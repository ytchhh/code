#ifndef _SEQLIST_H
#define _SEQLIST_H

#include"../utili.h"

#define ElemType int
#define DEFAULT_SIZE 8
#define INC_SIZE     5

typedef struct SeqList
{
	ElemType *base;
	size_t    caapcity;
	size_t    len;
}SeqList;

///////////////////////////////////////////////
void InitList(SeqList *lt);
///////////////////////////////////////////////
void InitList(SeqList *lt)
{
	lt->base = (ElemType*)malloc(sizeof(ElemType)*DEFAULT_SIZE);
	assert(lt->base != NULL);
	lt->caapcity = DEFAULT_SIZE;
	lt->len = 0;
}
void push_back(SeqList *lt, ElemType x)
{
	if(lt->len >= lt->caapcity)
	{
		cout<<"空间已满，不能插入."<<endl;
		return;
	}
	lt->base[lt->len++] = x;
}
void push_front(SeqList *lt, ElemType x)
{
}
void pop_back(SeqList *lt)
{
	if(lt->len == 0)
	{
		cout<<"表已空，不能删除."<<endl;
		return;
	}
	lt->len--;
}
void pop_front(SeqList *lt)
{
	//
}
void show_list(SeqList *lt)
{
	for(int i=0; i<lt->len; ++i)
	{
		cout<<lt->base[i]<<" ";
	}
	cout<<endl;
}

Status insert(SeqList *lt, int pos, ElemType x)
{

}

Status insert(SeqList *lt, ElemType x)
{
	return TRUE;
}

int find(SeqList *lt, ElemType key)
{
	for(int i=0; i<lt->len; ++i)
	{
		if(lt->base[i] == key)
			return i;
	}
	return -1;
}
Status erase(SeqList *lt, ElemType key)
{
	
}
void clear(SeqList *lt)
{
	lt->len = 0;
}
void resver(SeqList *lt)
{

}

void sort(SeqList *lt)
{

}
#endif