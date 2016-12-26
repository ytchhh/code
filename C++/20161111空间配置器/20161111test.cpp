#include<iostream>
#include<new>
#include<stdlib.h>
using namespace std;

#if 0
int main()
{
	int *p = new int[107311741824];
	if(NULL == p)
	{
		cout<<"Out Of Memory."<<endl;
		exit(1);
	}
	cout<<"OK."<<endl;
	return 0;
}
/*
如果这样申请的话就会出现如下的错误:
	file:///tmp/mozilla_ytc0/stardict-langdao-ce-gb-2.4.2 file:///tmp/mozilla_ytc0/stardict-oald-cn-2.4.2 
	看报错信息应该是alloc函数申请不到空闲空间了。可能内存不够这个工程使用。换个大内存的环境试试。或者看看工程里用到alloc的地方看看是不是内存溢出了
*/
#endif

#if 0
void out_of_memory(void )
{
	//int *q = new int[10000000000000];
	cout<<"Out Of Memory!"<<endl;
	//abort();//终止当前进程，返回一个错误代码
	exit(1);//如果不使用exit(1)的话，就会出现一直调用死循环的问题。
}
int main()
{
	std::set_new_handler(out_of_memory);		//在vc6.0当中应该使用_set_new_handler,并加上头文件new.h,在以后的版本就不必在使用了。
	int *p = new int[10479149179];
	if(NULL == p)							//当new无法为p开辟那么多空间的话，函数out_of_memory就会被调用，于是程序就会一直输出，因为加入了exit(1),所以会夭折。当operator new无法满足内存申请时，它会不断调用new_handler函数，直到找到足够的内存。
	{
		cout<<"Out Of Memory."<<endl;
		exit(1);
	}
	cout<<"OK."<<endl;
	return 0;
}
#endif
/*
	当operator new无法满足某一内存分配需求的时候，它会抛出异常。以前它会返回一个NULL指针，某些旧式编译器也还会那么做。现在也可以取得旧行为。
	当operator new抛出异常来反映一个未获满足的内存需求之前，它会调用一个客户制定的错误处理函数，一个所谓的new_handler.为了指定这个"用于处理内存不足"的函数，客户必须调用set_new_handler,那是声明<new>的一个标准程序库函数：
	namespace std
	{
		typedef void (*new_handler)();	//这是一个函数指针
		new_handler set_new_handler(new_handler p) throw();
	}
	正如，new_handler是个typedef,定义出一个指针指向函数，该函数没有参数也不返回任何东西。set_new_handler则是"获得一个new_handler并返回一个new_handler"的函数。set_new_handler声明式尾端的"thorw()"是一份异常明细，表示该函数不抛出任何异常--虽然事实更有趣些。
	set_new_handler的参数是个指针，指向operator new无法分配内存时该被调用的函数。其返回值也是个指针，指向set_new_handler被调用前正在执行的那个new_handler函数。
	当operator new无法满足内存申请时，它会不断调用new_handler函数，直到找到足够内存，为了设计一个好的new_handler函数必须做以下事情:
	1.让更多内存可被使用。这便造成operator new内的下一次内存分配动作可能成功。实现此策略的一个做法是，程序一开始就分配一大块内存，而后当new_handler第一次被调用，将它们释放给程序使用。
	2.安装另一个new_handler，如果目前这个new_handler无法取得更多可用内存，或许它知道另外哪个new_handler由此能力，果真如此，目前这个new_handler就可以安装另外那个new_handler以替换自己(只要调用set_new_handler),下次当operator new调用new_handler,调用的将是最新安装的那个。
	3.卸除new_handler,也就是将NULL指针传给set_new_handler,一旦没有安装任何new_handler,operator new会在内存分配不成功时抛出异常。
	4.抛出bad_alloc的异常，这样的异常不会被operator new捕捉，因此会被传播到内存索求处。
	5.不返回，通常调用abort或exit.
*/

template<class Type,int inst>
class Stack
{
public:
	Stack(int sz = inst)
	{
		capacity = sz > DFFAULT_SIZE ? sz : DFFAULT_SIZE;//最低开辟的是8个字节
		base = new Type[capacity];
		top = 0;
	}
private:
	enum{DFFAULT_SIZE = 8};
	Type *base;		//指针来控制元素的指向
	int capacity;	//容量
	int top;		//栈顶的元素
};

int main()
{
	Stack<int,10> st;
	return 0;
}
