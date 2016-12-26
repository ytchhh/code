#include <stdio.h>
#include <malloc.h>
#include "List.h"
int main(void)
{
	Node *head =create();
	ShowList(head);
	ListSort(&head);
//	InsertByVaule(&head,6); // 有序链表插入一个值
//	ShowList(head);     //插入后再输出新的链表
//	InsertByIndex(&head,4,6); //给出位置插入一个值
//	ShowList(head);   //插入后再输出新的
//	printf("在第%d个位置\n",FindByValue(head,5));  //给出值找出位置
	printf("第四个的值为%d\n",FindByIndex(head,4)); //给出位置找到值
	return 0;
}
