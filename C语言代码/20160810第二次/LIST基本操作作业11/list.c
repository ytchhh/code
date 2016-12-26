#include <stdio.h>
#include <malloc.h>
#include "list.h"
//建立链表
Node *create()
{
	Node *head=NULL,*p1=NULL,*p2=NULL;
	p1 = (Node*)malloc(sizeof(Node));
	p1->pNext = NULL;
	while(1 == scanf("%d",&p1->Value))
	{
		if(head == NULL)
			head = p1;
		else
			p2->pNext = p1;
		p2 = p1;
		p1 = (Node*)malloc(sizeof(Node));
		p1->pNext = NULL;
	}
	free(p1);
	p1 = NULL;
	return head;
}
void InsertHead(pNode*pHead,int value)
{
	pNode pNewNode=NULL;
	pNewNode = (pNode)malloc(sizeof(Node));
	pNewNode->Value = value;

	pNewNode->pNext = (*pHead);
	*pHead = pNewNode;
}
//输出链表
void ShowList(pNode pHead)
{
	pNode p =pHead;
	while (p!=NULL)
	{
		printf("%4d",p->Value);
		p = p->pNext;
	}
	putchar(10);
}
void InsertTail(pNode* pHead,int value)
{
	pNode pNewNode=NULL;
	pNewNode = (pNode)malloc(sizeof(Node));
	pNewNode->Value = value;
	pNewNode->pNext = NULL;
	if ((*pHead) ==NULL)
	{
		*pHead = pNewNode;
	}
	else
	{
		pNode p = (*pHead);
		while (p->pNext!=NULL)
		{
			p = p->pNext;
		}
		p->pNext = pNewNode;

	}
}
//删除链表
void DeleteHead(pNode *pHead)
{
	pNode p = (*pHead);
	if ((*pHead)==NULL||(*pHead)->pNext==NULL)
	{
		*pHead = NULL;
	}
	else
	{
		(*pHead) = (*pHead)->pNext;
	}
	free(p);
	p = NULL;
}
void DeleteTail(pNode *pHead)
{
	pNode q = (*pHead);

	if ((*pHead)==NULL||(*pHead)->pNext==NULL)
	{
		*pHead = NULL;
	}
	else
	{
		pNode p=NULL;
		while (q->pNext != NULL)
		{
			p = q;
			q = q->pNext;
		}
		p->pNext = NULL;
	}	
	free(q);
	q = NULL;
}
void Clear(pNode* pHead)
{
 pNode p = NULL,p1 = NULL;
 p= p1 = (*pHead);
 while ( (p->pNext) !=NULL)
 {
	 p = p->pNext;
	 p1 = p;
	 free(p1);
 }
 free(p);
 p = NULL;
}
//链表插入
//有序链表的插入
void InsertByVaule(pNode *pHead,int value)
{
 pNode p1 = NULL,p2 = NULL;
 pNode p3 = (pNode)malloc(sizeof(Node));
 p3->Value = value;
 p1 = (*pHead);
 for (; p1->pNext != NULL; p1 = p1->pNext)
	 {
		 if (p1->Value > value)
			 {
				 p3->pNext = p1;
				 p2 = p3;
				 (*pHead) = p3;
			 }
		 if (p1->pNext->Value > value)
			 {
				 p2 = p1->pNext;
				 p1->pNext = p3;
				 p3->pNext = p2;
				 break;
			 }
	 }
 if (p2 == NULL)
 {
	 p1->pNext = p3;
	 p3->pNext = NULL;
 }
}
void InsertByIndex(pNode *pHead,int index,int value)
{
 pNode p1 = NULL,p2 = NULL,p3 = NULL;
 int n=1;
 p3 = (pNode)malloc(sizeof(Node));
 p3->Value = value;
 for (p1 = (*pHead); p1->pNext !=NULL; p2 = p1,p1 = p1->pNext)
	 {
	  if (n == index)
		  {
			  p2->pNext = p3;
			  p3->pNext = p1;
			  break;
		  }
	  n++;
	 }
}
int FindByValue(pNode pHead,int value)
{
 int n = 1;
 pNode p1 = NULL;
 for (p1 = pHead; p1->pNext != NULL; p1 = p1->pNext, n++)
	 {
		 if (p1->Value == value)
		     {
			  break;
			 }
	 }
 return n;
}
int FindByIndex(pNode pHead,int index)
{
 pNode p1 = NULL;
 int n=1;
 for (p1 = pHead; p1 != NULL; p1 = p1->pNext)
	 {
	   if (n == index)
		   {
			break;
		   }
	   n++;
	 }
 return (p1->Value);
}

void ListSort(pNode* pHead)
{
 pNode p1 =NULL, p2 = NULL;
 int t,i,n=0;
 for (p1 = (*pHead); p1->pNext != NULL; p1 = p1->pNext)
	  n++;
 n++;
 for (p1 = (*pHead); p1->pNext != NULL; p1 = p1->pNext)
	 { 
		 for (p2 = (*pHead),i=0; i<n-1; n-- )
			 {
				 if (p2->Value > p2->pNext->Value)
					 { 
						 t= p2->Value;
						 p2->Value = p2->pNext->Value;
						  p2->pNext->Value = t;
					 }
			 }
	 }
}


