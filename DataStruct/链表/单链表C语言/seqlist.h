#ifndef _SEQLIST_H
#define _SEQLIST_H
#include"ututli.h"

#define ElemType int
#define DEFAULT_SIZE 8		//初始化时数组的长度
#define LIST_INCREMENT 2	//每次增加的长度


typedef struct SeqList
{
	ElemType *base;
	size_t	 len;
	size_t	 capacity;
}SeqList;

void InitSeqList(SeqList *list);				//初始化函数
int isfull(SeqList *list);						//判断是否为空
void move(SeqList *list,int m,int n);					//将制定位置移动函数
void push_back(SeqList *list,ElemType x );		//后插函数
void push_front(SeqList *list,ElemType x);		//头插函数
void pop_back(SeqList *list);					//尾删函数
void pop_front(SeqList *list);					//头删函数
void insert_pos(SeqList *list,int i,ElemType e);//按位置插入
void insert_val(SeqList *list,ElemType e);		//按值插入
void delete_pos(SeqList *list,int i);			//按位置删除
void delete_val(SeqList *list,ElemType e);		//按值删除
int  find_val(SeqList *list,ElemType e);		//按值查找
int  length(SeqList *list);						//求顺序表的长度
int  isempty(SeqList *list);					//判断是否为空,0为假,1为真.
void clear(SeqList *list);						//清空顺序表
void resver(SeqList *list);						//转置顺序表
void show_list(SeqList *list);					//显示函数
void sort(SeqList *list);						//排序函数
void DestroySeqlist(SeqList *list);				//摧毁函数
bool ListInsert(SeqList *list,int i,ElemType e);//动态插入函数
//////////////////////////////
void InitSeqList(SeqList *list)
{
	list->base = ( ElemType*)malloc(sizeof(SeqList) * DEFAULT_SIZE);

	assert(list != NULL);
	list->len = 0;
	list->capacity = DEFAULT_SIZE;
}

void sort(SeqList *list)	//使用冒泡排序法
{
	if(list->len == 0 || list->len == 1)
		return;
	else
	{
		int i,j,t;
		for(i = 0; i <list->len-1; ++i )
			for(j = 0; j < list->len-1-i; ++j)
				if(list->base[j] > list->base[j+1])
				{
					t = list->base[j];
					list->base[j] = list->base[j+1];
					list->base[j+1] = t;
				}
	}
}

//判断是否满，如果为满的话，返回０，不满的话返回１.
int  isfull(SeqList *list)
{
	if(list->len == list->capacity)
		return 0;
	else
		return 1;
}

void move(SeqList *list,int m,int n)//m代表位置，n代表前移或者后移.
{									//为0代表前移,为１代表后移.
	int k;
	if(n == 1)
	{
		for(k = list->len-1; k >= m-1; --k)//将指定的位置向后移动
			list->base[k+1] = list->base[k];
	}
	else
	{
		for(k = m; k < list->len; ++k)
			list->base[k-1] = list->base[k];
	}
}

bool ListInsert(SeqList *list,int i,ElemType e)
{
	ElemType *newbase,*q,*p;
	if(i < 1 || i > list->len+1)	//插入的位置不合法
		return	false;
	if(list->len >= list->capacity)
	{
		if(!(newbase = (ElemType*)realloc(list->base,(list->capacity + LIST_INCREMENT) * sizeof(ElemType))))	
			exit(0);		//存储分配失败
		list->base = newbase;	//新地址
		list->capacity += LIST_INCREMENT;	//增加存储容量
	}
	q = list->base+i-1;			//q为插入位置
	move(list,i,1);				//插入位置的元素向后移动
	*q = e;			//插入
	++list->len;	//表长增加1
	return true;
}

void push_back(SeqList *list,ElemType x )
{
	if(isfull(list) == 0)
	{
		printf("顺序表已满，错误\n");
		return ;
	}
	else
		list->base[list->len++] = x;
}

void push_front(SeqList *list,ElemType x)
{
	if(isfull(list) == 0)
	{
		printf("顺序表已满，错误\n");
		return;
	}
	else
	{
		move(list,1,1);
		list->base[0] = x;
	}
	list->len++;
}

void pop_back(SeqList *list)
{
	if(list->len == 0)
		return;
	list->len--;
}

void pop_front(SeqList *list)
{
	if(list->len == 0)
		return;
	else if(list->len == 1)
		list->len--;
	else if(list->len <= list->capacity)
	{
		move(list,1,0);
		list->len--;
	}
}

void insert_pos(SeqList *list,int i,ElemType e)
{
	if(list->len == list->capacity)
		return;
	else if(i < 1 || i > list->len+1)
		return;
	else if(i <= list->len)
		move(list,i,1);
	list->base[i-1] = e;
	list->len++;
}

void insert_val(SeqList *list,ElemType e)
{
	if(isfull(list) == 0)
		return;
	else
		push_back(list,e);
}

void delete_pos(SeqList *list,int i)
{
	if(isfull(list) == 0)
		return;
	if(i < 1 || i > list->len)
		return;
	if(i < list->len)	//如果删除不是最后位置
		move(list,i,0);
	list->len--;
}

void delete_val(SeqList *list,ElemType e)
{
	int i;
	for(i = 0; i < list->len; ++i)
	{
		if(list->base[i] == e)
			break;
	}
	i++;
	if(i <= list->len)
		delete_pos(list,i);
	else
		printf("未找到要删除的值!");
}

int find_val(SeqList *list,ElemType e)	//返回0代表失败
{
	int i;
	if(list->len == 0)
		return 0;
	else
	{
		for(i = 0; i < list->len; ++i)
			if(list->base[i] == e)
				break;
	}
	i++;
	if(i <= list->len)
		return i;
	else
		return 0;
}

int length(SeqList *list)
{
	return list->len;
}

int isempty(SeqList *list)
{
	if(list->len == 0)
		return 1;
	else
		return 0;
}

void clear(SeqList *list)
{	//将List置为空表
	if(isempty(list) == 1)
		return ;
	else
		list->len = 0;
}

void resver(SeqList *list)
{
	int i,t;
	if(list->len == 0 || list->len == 1)
		return;
	else
		for(i = 0; i < list->len/2; ++i)
		{
			t = list->base[i];
			list->base[i] = list->base[list->len-1-i];
			list->base[list->len-1-i] = t;
		}
}

void show_list(SeqList *list)
{
	int i = 0;
	while(list->len > i )
	{
		printf("%d->",list->base[i]);
		i++;
	}
	printf("Over\n");
}
void DestroySeqlist(SeqList *list)
{	//初识条件:顺序线性表已经存在。操作结果，销毁顺序线性表.
	free(list->base);
	list->base = NULL;
	list->len = 0;
	list->capacity = 0;
}

#endif
