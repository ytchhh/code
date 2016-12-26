#include"LinkList.h"
#include<iostream>
using namespace std;

int main()
{
	LinkList list;
	InitList(list);
	ListInsert(list,1,1);
	ShowList(list);
	DestroyList(list);
}
