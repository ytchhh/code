#if 0
#include<new>//为set_new-handler准备的头文件
#define __THROW_BAD_ALLOC throw bad_alloc
#elif !defined(__THROW_BAD_ALLOC)
#include<iostream>
#include<stdlib.h>
//#include<STDDEF.H>
using namespace std;
#define __THROW_BAD_ALLOC cerr<<"Out Of Memory."<<endl;exit(1);
#endif

//一级空间适配器
template<int inst>	//inst为处理多线程时所遇到的问题
class __malloc_alloc_template
{
private://因为以下的函数只是被类里面的公有函数调用,所以定义为私有的，静态的
	static void* oom_malloc(size_t n);
	static void* oom_realloc(void *p,size_t new_sz);
	static void(* __malloc_alloc_oom_handler)();//这是一个函数指针
public:
	static void* allocate(size_t n)
	{	//一级配置器的时候直接使用了malloc()
		void *result = malloc(n);
		//当以下无法满足需求的时候，改用oom_malloc();
		if(0 == result)
			result = oom_malloc(n);
		return result;
	}
	static void deallocate(void *p,size_t n)
	{
		free(p);
	}
	static void* reallocate(void *p,size_t old_sz,size_t new_sz)
	//改变申请空间大小时
	{
		void *result = realloc(p,new_sz);
		//以下无法满足需求时，改用oom_realloc()
		if(0 == result) result = oom_realloc(p,new_sz);
		return result;
	}
	static void(*set_malloc_handler(void(*f)()))()
	{	//仿真C++的set_new_handler().换句话说，你可以通过它
		//指定你自己的out_of_memory handler
		void(*old)() = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return old;
	}
};

template<int inst>	//将初值设置为0
void(*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;

template<int inst>
void* __malloc_alloc_template<inst>::oom_malloc(size_t n)
{
	void(*my_malloc_handler)();//定义一个函数指针
	void* result;
	for(; ; )//不断尝试释放，配置，再释放，再配置....
	{
		my_malloc_handler = __malloc_alloc_oom_handler;
		if(0 == my_malloc_handler)
		{
			__THROW_BAD_ALLOC;	//抛出异常
		}
		(*my_malloc_handler)();//调用处理进程，企图释放内存。
		result = malloc(n);//再次尝试配置内存
		if(result)
			return result;
	}
}

template<int inst>
void* __malloc_alloc_template<inst>::oom_realloc(void *p,size_t n)
{
	void (*my_malloc_handler)();
	void *result;
	for(; ; )
	{
		my_malloc_handler = __malloc_alloc_oom_handler;
		if(0 == my_malloc_handler)
		{
			__THROW_BAD_ALLOC;
		}
		(*my_malloc_handler)();
		result = realloc(p,n);
		if(result)
			return result;
	}
}

typedef __malloc_alloc_template<0> malloc_alloc;//将一级配置器取了别名


enum{__ALIGN = 8};//小型区块的上调边界
enum{__MAX_BYTES = 128};//小型区块的上限
enum{__NFREELISTS = __MAX_BYTES/__ALIGN};//free-list的个数

//二级配置器
template<bool threads,int inst>
class __default_alloc_template
{
public:	//n必须大于0
	static void * allocate(size_t n)
		{
			obj * volatile * my_free_list;
			obj * result;
			//如果申请的空间大于128就调用第一级配置器
			if (n > (size_t) __MAX_BYTES) 
			{
				return(malloc_alloc::allocate(n));
			}
			//寻找16个free_list中适当的一个
			my_free_list = free_list + FREELIST_INDEX(n);
			result = *my_free_list;
			if (result == 0) 
			{	//没找到可用的free_list，准备重新填充free_list.
				void *r = refill(ROUND_UP(n));
				return r;
			}
			//调整free_list。
			*my_free_list = result -> free_list_link;
			return (result);
		}
	static void deallocate(void *p, size_t n);
	static void * reallocate(void *p, size_t old_sz, size_t new_sz);
private:
	static size_t ROUND_UP(size_t bytes)
	{	//ROUND_UP函数将bytes上调至8的倍数
		return ((bytes + __ALIGN - 1) & ~(__ALIGN - 1));
	}	//位运算
	union obj
	{
		union obj* free_list_link;
		char client_data[1];
	};
private:
	static obj* volatile free_list[__NFREELISTS];//16个free_list的节点
//void(*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;

	static  size_t FREELIST_INDEX(size_t bytes) 
	{	//根据使用的区块大小，决定使用第n号free_list,n从0起算.
		 return (((bytes) + __ALIGN-1)/__ALIGN - 1);
	}
private:
	static void *refill(size_t n);
	static char *chunk_alloc(size_t,int &nobjs);
private:
	static char *start_free;
	static char *end_free;
	static size_t heap_size;
};

template<bool threads,int inst>
char* __default_alloc_template<threads,inst>::start_free = 0;

template<bool threads,int inst>
char* __default_alloc_template<threads,inst>::end_free = 0;

template<bool threads,int inst>
size_t __default_alloc_template<threads,inst>::heap_size = 0;

template<bool threads,int inst>
typename __default_alloc_template<threads,inst>::obj* volatile
__default_alloc_template<threads,inst>::free_list[__NFREELISTS] = 
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

template <bool threads, int inst>
char* __default_alloc_template<threads, inst>::chunk_alloc(size_t size, int& nobjs)
{
	char * result;
	size_t total_bytes = size * nobjs;
	size_t bytes_left = end_free - start_free;
	if (bytes_left >= total_bytes) 
	{
		result = start_free;
		start_free += total_bytes;
		return(result);
	} 
	else if (bytes_left >= size) 
	{
		nobjs = bytes_left/size;
		total_bytes = size * nobjs;
		result = start_free;
		start_free += total_bytes;
		return(result);
	} 
	else 
	{
		size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);
		if (bytes_left > 0) 
		{
			obj * volatile * my_free_list =
				free_list + FREELIST_INDEX(bytes_left);
			((obj *)start_free) -> free_list_link = *my_free_list;
			*my_free_list = (obj *)start_free;
		}
		start_free = (char *)malloc(bytes_to_get);
		if (0 == start_free) 
		{
			int i;
			obj * volatile * my_free_list, *p;
			for (i = size; i <= __MAX_BYTES; i += __ALIGN) 
			{
				my_free_list = free_list + FREELIST_INDEX(i);
				p = *my_free_list;
				if (0 != p) 
				{
					*my_free_list = p -> free_list_link;
					start_free = (char *)p;
					end_free = start_free + i;
					return(chunk_alloc(size, nobjs));
				}
			}
			end_free = 0;
			start_free = (char *)malloc_alloc::allocate(bytes_to_get);
		}
		heap_size += bytes_to_get;
		end_free = start_free + bytes_to_get;
		return(chunk_alloc(size, nobjs));
	}
}

template <bool threads, int inst>
void* __default_alloc_template<threads, inst>::refill(size_t n)
{
	int nobjs = 20;
	char * chunk = chunk_alloc(n, nobjs);
	obj * volatile * my_free_list;
	obj * result;
	obj * current_obj, * next_obj;
	int i;
	if (1 == nobjs) return(chunk);
	my_free_list = free_list + FREELIST_INDEX(n);
	result = (obj *)chunk;
	*my_free_list = next_obj = (obj *)(chunk + n);
	for (i = 1; ; i++) 
	{
		current_obj = next_obj;
		next_obj = (obj *)((char *)next_obj + n);
		if (nobjs - 1 == i) 
		{
			current_obj -> free_list_link = 0;
			break;
		} 
		else
		{
			current_obj -> free_list_link = next_obj;
		}
	}
	return(result);
}

#ifdef __USE_MALLOC	//如果没有定义__USE__ALLOC的话就使用一级空间配置器，否则使用二级空间配置器
typedef __malloc_alloc_template<0> malloc_alloc;
typedef malloc_alloc alloc;
#else
typedef __default_alloc_template<0,0> alloc;
#endif

template<class T,class Alloc>
class simple_alloc
{
public:
	static T* allocate(size_t n)
	{
		return 0 == n ? 0 : (T*)Alloc::allocate(n * sizeof(T));
	}
	static T* allocate()
	{
		return (T*)Alloc::allocate(sizeof(T));
	}
	static void deallocate(T *p,size_t n)
	{
		if(0 != n)
			Alloc::deallocate(p,n * sizeof(T));
	}
	static void deallocate(T *p)
	{
		Alloc::deallocate(p,sizeof(T));
	}
};
