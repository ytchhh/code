#ifndef _LIST_H
#define _LIST_H

#include"../utili.h"

#define ElemType int

typedef struct ListNode
{
	ElemType data;
	struct ListNode *next;
}ListNode;

typedef struct List
{
	ListNode *first;
	ListNode *last;
	size_t    size;
}List;

////////////////////////////////////////////
void InitList(List *lt)
{
	ListNode *s = (ListNode *)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->next = NULL;
	lt->first = lt->last = s;
	lt->size = 0;
}
void push_back(List *lt, ElemType x)
{
	ListNode *s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	lt->last->next = s;
	lt->last = s;
	lt->size++;

}
void push_front(List *lt, ElemType x)
{
	ListNode *s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->data = x;
	s->next = lt->first->next;
	lt->first->next = s;
	if(lt->size == 0)
		lt->last = s;
	lt->size++;
}
void show_list(List *lt)
{
	ListNode *p = lt->first->next;
	while(p != NULL)
	{
		cout<<p->data<<"-->";
		p = p->next;
	}
	cout<<"Over."<<endl;
}
#endif