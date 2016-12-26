#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;

typedef int Elemtype;

typedef struct ListNode
{
	Elemtype data;
	struct ListNode *next;
}ListNode;

typedef ListNode* Lt;

void InitList(ListNode **p)
{
	(*p) = NULL;
}

void CreatList_H(ListNode **p)
{
	ListNode *q;
	(*p) = (ListNode*)malloc(sizeof(ListNode));
	(*p)->data = 0;
	(*p)->next = NULL;
	int i;
	for(i = 1; i <= 5; ++i)
	{
		q = (ListNode*)malloc(sizeof(ListNode));
		q->data = i;
		q->next = (*p);
		(*p) = q;
	}
}

void CreatList_B(ListNode **p)
{
	ListNode *q,*head;
	(*p) = (ListNode*)malloc(sizeof(ListNode));
	(*p)->data = 0;
	(*p)->next = NULL;
	head = (*p);
	int i;
	for(i = 1; i <= 5; ++i)
	{
		q = (ListNode*)malloc(sizeof(ListNode));
		(*p)->next = q;
		q->data = i;
		q->next = NULL;
		(*p) = q;
	}
	(*p) = head;
}

void show_list(ListNode **p)
{
	while(*p != NULL)
	{
		cout<<(*p)->data<<"-->";
		(*p) = (*p)->next;
	}
	cout<<"Over"<<endl;
}
///////////////////////////


int main()
{
	ListNode* mylist;
	InitList(&mylist);
	CreatList_B(&mylist);
	show_list(&mylist);
	return 0;
}
