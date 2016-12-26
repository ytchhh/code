#if 0
#include<iostream>
using namespace std;
class A
{
public:
	void getnum()
	{
		
	}
	int a;
};
int main()
{
   cout<<"welcome to C++!"<<endl;
   return 0;
   A a;
   

}
#endif
#if 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Node
{
	int id;
	int pri;
	int cputime;
	int alltime;
	struct Node *next; 
}node;
void priority(node **head);
void function(node **p);
void finish(node **head);
void print(node **head);
void jincheng(node **head);
node *create()
{
	node *head = NULL,*pnew =NULL,*ptail=NULL;
	pnew = (Node*)malloc(sizeof(Node));
	pnew->next = NULL;
	for(int i=0;i<5;i++)
	{
	printf("输入进程ID：");
	scanf("%d",&pnew->id);
	printf("输入进程优先数：");
	scanf("%d",&pnew->pri);
	printf("输入进程已占用时间片：");
	scanf("%d",&pnew->cputime);
	printf("输入进程还需占用时间片：");
	scanf("%d",&pnew->alltime);
		if(head == NULL)
			head = pnew;
		else
			ptail->next = pnew;
		ptail = pnew;
		pnew = (Node*)malloc(sizeof(Node));
		pnew->next =NULL;
	}
	free(pnew);
	pnew = NULL;
	return head;
}
int main()
{
	node *head=create();
	jincheng(&head);
}
void jincheng(node **head)
{
	priority(head);
	print(head);		
	finish(head);
}
void priority(node **head)
{
	node *p = *head;
	node *q = *head;
	while(q!=NULL)
	{
		if(q->alltime!=0)
		{
			if(p->pri<=q->pri)
				p=q;	
		}
		q=q->next;
	}
	function(&p);
}
void function(node **p)
{
	(*p) -> cputime += 1;
	(*p) -> alltime -= 1;
	(*p) -> pri -= 3;

}
void finish(node **head)
{
	node *p = *head;
	int i=0;
	while(p != NULL)
	{
		if(p->alltime == 0)
			i++;
		p = p->next;
	}
	if(i == 5)
		printf("进程结束\n");
	else
		jincheng(head);	
}
void print(node **head)
{
	node *p = *head;
	printf("进程ID  优先数  CPUTIME  ALLTIME\n");
	while(p!=NULL)
	{
		printf("   %d    ",p->id);
		printf("  %d     ",p->pri);
		printf("   %d    ",p->cputime);
		printf("   %d    ",p->alltime);
		p=p->next;
		printf("\n");
	}
}
#endif
