#ifndef _LIST_H
#define _LIST_H
//#pragma once
typedef struct NODE
{
	int			Value;
	struct NODE *pNext;
}Node,*pNode;
Node *create();
void InsertHead(pNode*pHead,int value);
void InsertTail(pNode* pHead,int value);

void ShowList(pNode pHead);

void DeleteHead(pNode *pHead);
void DeleteTail(pNode *pHead);
void Clear(pNode* pHead);

void InsertByVaule(pNode *pHead,int value);
void InsertByIndex(pNode *pHead,int index,int value);

int FindByValue(pNode pHead,int value);
int FindByIndex(pNode pHead,int index);

void ListSort(pNode* pHead);
#endif