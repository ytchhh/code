#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#if 0
int main()
{
 char *a[2]={"one","two"};
 char **p;
 p = a;
 printf("%s\n",*(p++)+1);
 printf("%c\n",**p-1);
}
#endif
#if 0
float fun(float x,int y);
int main()
{
 float x;
 int y;
 printf("请输入两个数:\n");
 scanf("x=%f,y=%d",&x,&y);
 printf("%f\n",fun(x,y));
 return 0;
}
float fun(float x,int y)
{
 int i;
 float z = 1.0;
 for (i=1; i<= y; ++i)
  z = z*x;
 return z;
}
#endif
#if 0
#define SQR(X) X*X
int main()
{
 int a = 16,k = 2,m = 1;
 a/=SQR(k+m)/SQR(k+m);
 printf("%d\n",a);
 return 0;
}
#endif
#if 0 //编写函数，将两个递增有序的链表，合并成一个递增有序的表
typedef struct NODE
{
 int value;
 struct NODE *next;
}
Node;
Node* creat();
Node *fn(Node*head1,Node*head2,Node*head);
void print(Node*head);
int main()
{
 Node *head1=NULL,*head2=NULL,*head=NULL;
 head1 = creat();
 getchar();
 head2 = creat();
 
 head = fn(head1,head2,head);  
 print(head);
 return 0;
}
Node* creat()
{
 Node *head = NULL,*p1 = NULL,*p2 = NULL;
 p1 = (Node*)malloc(sizeof(Node));
 p1 -> next = NULL;
 while (1 == scanf("%d",&p1 ->value))
 {
 if (head == NULL)
   head = p1;
 else 
p2 -> next = p1;
p2 = p1;
p1 = (Node*)malloc(sizeof(Node));
p1 -> next = NULL;
 }
free(p1);
p1 = NULL;
return head;
}
Node *fn(Node*head1,Node*head2,Node*head)
{
 Node*p1=NULL,*p2=NULL,*p=NULL;
 
 p1 = head1;
 p2 = head2;
 if (p1 -> value < p2 -> value)
 { 
  head = p1;
  p1 = p1 -> next;
 }
 else 
 {
 head = p2;
 p2 = p2 -> next;
 }
p = head;
 while (p1 != NULL && p2 != NULL)
 {
  if (p1 -> value < p2 -> value)
  {
   p -> next = p1;
   p = p ->next;
   p1 = p1 -> next;
  }
  else
  {
  p -> next = p2;
  p = p -> next;
  p2 = p2 -> next;
  } 
 }
while (p1 != NULL)
{
  p -> next = p1;
  p1 = p1 -> next;
}
while (p2 != NULL)
{
  p -> next = p2;
  p2 = p2 ->next;
}
return head; 
}
void print(Node*head)
{
Node*p = NULL;
p = head;
for (; p -> next != NULL; p = p -> next)
printf("%d,",p -> value);
printf("%d\n",p -> value);
}
#endif

















