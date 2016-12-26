//#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
using namespace std;

typedef struct Node
{
	int data;
	struct Node *next;
}NODE;
typedef struct HashTable
{
	NODE *value[10];
}HashTable;
HashTable *creat();
NODE *find(HashTable *p,int data);
bool insert (HashTable *p,int data);
bool Delete(HashTable *p,int data);
void show(HashTable *p);
int main()
{
	HashTable *p = creat();
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int n = sizeof(a)/sizeof(a[0]);
	int i;
	show(p);
	for (i = 0; i < n; ++i)
	{
		insert(p,a[i]);
	}
	show(p);	
	return 0;
}
HashTable *creat()
{
	HashTable *p = (HashTable*)malloc(sizeof(HashTable));
	memset(p,0,sizeof(HashTable));
	return p;
}
NODE *find(HashTable *p,int data)
{
	NODE *pNode;
	if (NULL == p)
		return NULL;
	if (NULL == (pNode = p -> value[data%10]))
		return NULL;
			while (pNode)
			{
				if (data == pNode -> data)
					return pNode;
				pNode = pNode -> next;
			}
	return NULL;
}
bool insert (HashTable *p,int data)
{
	NODE *p1;
	if (NULL == p)
		return false;
	if (NULL == p -> value[data%10])
	{
		p1 = (NODE*)malloc(sizeof(NODE));
		memset(p1,0,sizeof(NODE));
		p1 -> data = data;
		p -> value[data%10] = p1;
		return true;
	}
	if (NULL != find(p,data))
		return false;
	p1 = p -> value[data%10];
	while (NULL != p1 -> next)
		p1 = p1 -> next;
	p1 -> next = (NODE*)malloc(sizeof(NODE));
	memset(p1 -> next,0,sizeof(NODE));
	p1 -> next -> data = data;
	return true;
}
bool Delete(HashTable *p,int data)
{
	NODE *pHead,pNode;
	if (NULL == p || NULL == p -> value[data%10])
		return false;
	if (NULL == (pNode = find(p,data)))
		return false;
	if (pNode == p -> value[data%10])
	{
		p -> value[data%10] = pNode -> next
			goto find;
	}
	pHead = p -> value[data%10];
	while (pNode != pHead -> next)
		pHead = pHead -> next;
	pHead -> next = pNode -> next;
find:
	free(pNode);
	return true;
}
void show(HashTable *p)
{
	int i;
	NODE *p1;
	p1 = p -> value[i];
	for(i = 0; i < 10; ++i)
	{
		cout<<i<<":";
		while (p1 != NULL)
		{
			cout<<p1 -> data<<"->";
			p1 = p1 -> next;
		}
		cout<<"Nul"<<endl;
	}
}
























