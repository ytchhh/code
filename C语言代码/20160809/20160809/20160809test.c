#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#if 0
typedef struct node
{
 int n;
 struct node *next;
}Node;
Node *creat();
void print(Node *head);
Node *sort(Node *head);  //排序
Node *swap(Node *head);  //逆序
int main()
{
 Node *head = creat();
 print(head);
 head=sort(head);
 print(head);
 head=swap(head);
 print(head);
 return 0;
}
Node *creat()
{
 Node *head=NULL,*p1=NULL,*p2=NULL;
 p1 = (Node*)malloc(sizeof(Node));
 p1->next = NULL;
 while (1 == scanf("%d",&p1->n))
 {
    if (head ==NULL)
		head = p1;
	else 
		p2->next = p1;
	p2 = p1;
	p1 = (Node*)malloc(sizeof(Node));
	p1->next = NULL;
 }
 free(p1);
 p1 = NULL;
 return head;
 }
void print(Node *head)
{
 Node *p = head;
 while (p !=NULL)
 {
	 printf("%d ",p->n);
	 p = p->next;
 }
 printf("\n");
}
Node *sort(Node *head)
{
 Node *newhead=NULL,*newtail=NULL,*p,*min,*minf;
 if (head == NULL || head->next == NULL)
	 return head;
 while (head != NULL)
 {
  p = min = head;
  for (; p->next!=NULL ; p = p->next )
  { 
     if (p->next ->n <min ->n) //第一步先遍历一次找到最小的，min始终指向最小的。
	 {                         //而minf始终指向min前面的那一个。
	  min = p->next ;
	  minf =p; 
	 }
  }
   //2
	 if (newhead==NULL)   //第一次的时候将 newhead 和 newtail都指向min;
		 {
		  newhead = newtail =min;
		 }
	 else    //下一次的时候 将newtail->next 里面存放 下一次遍历的最小值；
	 {       //再将newtail指向min
	   newtail->next = min;
	   newtail = min;
	 }
	 //3  删除
	 if (min ==head) //如果找到的最小值刚好是head的话，就将head指向head的下一个
		 head = head->next ;
	 else 
		 minf->next = min->next;  //否则的话 将minf里面的next指向min的下一个
  }
 if (newhead!=NULL)
	 newtail->next =NULL; //将最后一个里面的next指向为NULL
 return newhead;
 }
Node *swap(Node *head)
{
  Node *p=NULL,*pf=NULL,*pn=NULL;
  if (head ==NULL ||head->next ==NULL)
	  return head;
  pf = head;   //先将pf指向head
  p =pf->next ; //将p指向head的下一个，
  pf->next =NULL; //先将pf->next指向为0
  while (p ->next !=NULL)
  {
        pn = p->next; //先让pn指向p的下一个
		p->next = pf; //将p->next先指向pf
		pf = p;   //再将pf指向p
		p = pn;   //p再指向pn
  }
  p ->next =pf;
  head = p;
  return head;
}
#endif
#if 0
typedef struct node
{
 int n;
 struct node *next;
}Node;
void test(Node *head); //如何找到链表的中间位置，定义两个指针，都指向head,其中一个指针每次增加两次，另
int main()               //一个指针每次增加一次。当第一个指针走到结尾的时候，第二个指针就在中间
{
 Node *head;
 head=test(head);
 return 0;
}
void test(Node *head)
{
 Node *p1=NULL,*p2=NULL;
 p1 = p2 =NULL;
 while (p1 != NULL)
 {
  p1 = p1->next ;
  if (p1 != NULL)
  {
	  p1 = p1->next;
	  p2 = p2->next; 
  }
 }
}
#endif
#if 0
typedef struct data    //循环链表 ，最后一个结点里面不指向为0，指向head；
{
	int n;
	struct data *next;
}Node;
Node *create();
void print(Node *head);
int main()
{
 Node *head=create();
 print(head);
 return 0;
}
Node *create()
{
	Node *head=NULL,*p1=NULL,*p2=NULL;
	p1 = (Node*)malloc(sizeof(Node));
	p1->next = NULL;
	while(1 == scanf("%d",&p1->n))
	{
		if(head == NULL)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (Node*)malloc(sizeof(Node));
		p1->next = NULL;
	}
	free(p1);
	p1 = NULL;
	p2->next = head;
	return head;
}
void print(Node *head)
{
	Node *p = head;
	do         //循环链表在输出的时候，应该把判断条件改了。
	{
		printf("%d ",p->n);
		p = p->next;
	}while(p != head);
	printf("\n");
}
#endif
#if 0
typedef struct data
{
	int n;
	struct data *next;
	struct data *front;
}Node;
Node *create();
void print(Node *head);
int main()
{
 Node *head =create();
 print(head);
 return 0;
}
Node *create()
{
 Node *head=NULL,*p1=NULL,*p2=NULL;
 p1=(Node*)malloc(sizeof(Node));
 p1->front = NULL;
 p1->next  = NULL;
 while (1 == scanf("%d",&p1->n ))
 {
  if (head ==NULL)
     head =p1;
  else
  {
   p2->next =p1; //双指针就是在多了一个存放前面地址的指针。
   p1->front =p2;  //
  }
  p2 = p1;
  p1=(Node*)malloc(sizeof(Node));
  p1->front = NULL; //每次在定义新的指针的时候记得将指针指向为空就行了。
  p1->next  = NULL; //
 }
 free(p1);
 p1 = NULL;
 return head;
}
void print(Node *head)
{
 Node *p = head,*p1 = NULL;  //在输出双指针的时候，只要记得将两个指针的分别存放的地址是什么就可以弄清楚
	while(p != NULL)
	{
		p1= p;
		printf("%d ",p->n);
		p = p->next;
	}
	printf("\n");
	while(p1 != NULL)
	{
		printf("%d ",p1->n);
		p1 = p1->front;
	}
	printf("\n");
}
#endif
#if 0  //链表的插入
typedef struct data
{
	int n;
	struct data *next;
}Node;
Node *creat();
Node *find(Node *head,int key);     //找到关键字的位置
void insert(Node *head,int newdata,int key);  //插入
void print(Node *head);
int main()
{
 int key,newdata=9;
 Node *head;
 printf("输入要插在那个数的后面：key=");
 scanf("%d",&key);
 printf("input numbers:\n");
 head=creat();
 insert(head,9,key);
 print(head);
 return 0;
}
Node *creat()
{
 Node *head=NULL,*p1=NULL,*p2=NULL;
 p1 = (Node*)malloc(sizeof(Node));
 p1->next = NULL;
 while (1 == scanf("%d",&p1->n))
 {
    if (head ==NULL)
		head = p1;
	else 
		p2->next = p1;
	p2 = p1;
	p1 = (Node*)malloc(sizeof(Node));
	p1->next = NULL;
 }
 free(p1);
 p1 = NULL;
 return head;
 }
Node *find(Node *head,int key)  //找到关键字的位置
{
 Node *p1 =NULL,*p2 = NULL;
 p1 =head;
 for (;p1->next !=NULL; p1 =p1->next )
 {
	 if (p1->n ==key)
		 p2 = p1;
 }
 if (p2 !=NULL)
	 return p2;
 else 
	 return NULL;
}
void insert(Node *head,int newdata,int key)
{
 Node *newnode = NULL;  //新建一个结点
 Node *p1 =find(head,key); //p1是插入位置之前的结点指针
 newnode=(Node *)malloc(sizeof(Node)); //给结点开辟新的内存
 newnode->n =newdata;   //newdata是新结点的数据
  if (head ==NULL||p1==NULL)  //如果链表没有结点 或者找不到关键字的结点
  {
	  newnode->next=head; //就插入到表头位置   先连接起来
	  head =newnode;  // 再断开
  }
  else   
  {
	  newnode->next=p1->next;  //否则 就插入在p1的后面， 先连接
	  p1->next=newnode;  //再断开
  }
}
void print(Node *head)
{
	Node *p = head;
	while(p != NULL)
	{
		printf("%d ",p->n);
		p = p->next;
	}
	printf("\n");
}
#endif
#if 0
typedef struct data
{
	int n;
	struct data *next;
}Node;
Node *creat();
void print(Node *head);
Node* find(Node *head,int key);
void Delete(Node *head,int key);
int main()
{
 Node *head;
 int key=5;
 printf("input numbers:");
 head=creat();
 //printf("要删除的关键字:key=");
 //scanf("%d",&key);
 Delete(head,key);
 return 0;
}
Node *creat()
{
 Node *head=NULL,*p1=NULL,*p2=NULL;
 p1 = (Node*)malloc(sizeof(Node));
 p1->next = NULL;
 while (1 == scanf("%d",&p1->n))
 {
    if (head ==NULL)
		head = p1;
	else 
		p2->next = p1;
	p2 = p1;
	p1 = (Node*)malloc(sizeof(Node));
	p1->next = NULL;
 }
 free(p1);
 p1 = NULL;
 return head;
 }
Node* find(Node *head,int key)
{
 Node *p1=head,*p2=NULL,*p3=NULL;
 if (head->n ==key)
	 return p2;
 else
 {
	 for (; p1->next !=NULL;p3=p1, p1 =p1->next )
	 {   
	  if (p1->n == key)
		  p2 =p3;
	 }
	 if (p2 !=NULL)
		 return p2;
	 else 
		 return NULL;
 }
}
void Delete(Node *head,int key)
{
 Node *p=NULL,*p1=find(head,key);

 if (head!=NULL)
 {
    if (head->n ==key)
		{
	     p=head;
		 head=head->next;
		 free(p);
		 print(head);
		}
	else 
		{
	     while (p1!=NULL)
		 {
			 if (p1->next->n==key)
			 {
				 p=p1->next;
				 p1->next=p->next;
				 free(p);
				 print(head);
				 p1 =NULL;
			 }
		 }
		}
 }
 else 
 printf("没找到关键字或者链表为空\n");
}
void print(Node *head)
{
	Node *p = head;
	while(p != NULL)
	{
		printf("%d ",p->n);
		p = p->next;
	}
	printf("\n");
}
#endif
#if 0  //判断一个单链表是否成环
typedef struct data
{
	int n;
	struct data *next;
}Node;
Node *creat();
b
int main()
{
 Node *head=NULL;
 head=creat();
 judge(head);
}
Node *creat()
{
  Node *head=NULL,*p1=NULL,*p2=NULL;
 p1 = (Node*)malloc(sizeof(Node));
 p1->next = NULL;
 while (1 == scanf("%d",&p1->n))
 {
    if (head ==NULL)
		head = p1;
	else 
		p2->next = p1;
	p2 = p1;
	p1 = (Node*)malloc(sizeof(Node));
	p1->next = NULL;
 }
 free(p1);
 p1 = NULL;
 p2->next=head->next;
 return head;
}
#endif