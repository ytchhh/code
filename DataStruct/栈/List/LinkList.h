#ifndef _LINKLIST_H
#define _LINKLIST_H

#include"until.h"

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	LNode *next;
};
typedef LNode* LinkList;

void InitList(LinkList &L);		//初始化链表
void DestroyList(LinkList &L);	//摧毁链表	
void ClearList(LinkList &L);	//清空链表
bool ListInsert(LinkList &L,int i,ElemType e);	//插入数据
void ShowList(LinkList &L);				//打印链表
////////////////////////////////
////////////////////////////////

void InitList(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if(!L)
		exit(1);
	L->next = NULL;
}

void DestroyList(LinkList &L)
{
	LinkList q;
	while(L)
	{
		q = L->next;
		free(L);
		L = q;
	}
}

void ClearList(LinkList &L)
{
	LinkList p,q;
	p = L->next;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}

bool ListInsert(LinkList &L,int i,ElemType e)
{
	int j = 0;
	LinkList p = L,s;
	while(p && j < i -1)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i-1)
		return false;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

void ShowList(LinkList &L)
{
	while(L)
	{
		cout<<L->data<<"->";
		L = L->next;
	}
	cout<<"Over!"<<endl;
}

#endif
