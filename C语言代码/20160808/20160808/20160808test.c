#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#if 0  //类堆排序也是属于选择排序中的一种，不过用创堆的方式的效率比较高。
void sort(int a[],int len);
void print(int a[],int len);
void creatheap(int a[],int root,int len);
int main()
{
 int a[]={0,49,38,65,97,76,13,27,49}; //使用类堆排序的时候，要将数组的下标进行改变，a[0]不存放元素
 int len=sizeof(a)/sizeof(a[0])-1;
 sort(a,len);
 print(a,len);
 return 0;
}
void print(int a[],int len)
{
 int i;
 for (i=1; i<=len; ++i)
	 printf("%d ",a[i]);
 printf("\n");
}
void sort(int a[],int len)
{
 int i;
 int t;
 for (i=len/2; i>=1; --i)  //创立初始堆，从长度的一半的位置开始创立，
	 creatheap(a,i,len);
 for (i=len; i>=1; --i)  //将堆顶的元素移到最后，并将无序的部分再次重新创立为堆
 {
  t=a[1];
  a[1]=a[i];
  a[i]=t;
  creatheap(a,1,i-1);
 }
}
void creatheap(int a[],int root,int len) //创堆 可以根据自己的需要创立大根堆或者小根堆
{
 int i=2*root;    //从根节点开始沿着关键字比较大的结点开始向下筛选。
 int t=a[root];   //先将父结点的值保存起来，方便之后的比较和赋值。
 int flag=0;      //用一个中间值来判断是否父结点大于子结点。
 while (i <= len && flag == 0)
 {
  if (i<len)  //如果i<len 说明有两个子结点
  {
   if (a[i]<a[i+1]) //找到子结点中两个比较大的 将i标记为比较大的.
	   i++;
  }
  if (t >= a[i])  //如果父结点大于子结点的话 就可以不用去交换 并且结束循环。
	  flag=1;      
  else
  {               //如果父结点小于子结点的话，要先将父结点的值和其交换 再将i的值扩大为两倍。
   a[i/2]=a[i];   //再次进入循环 ，判断 如果i是小于总的长度的话 说明其下面还是有子结点的 
   i=i*2;         //就要再次进入比较，如果i的长度大于总的长度的话，说明下面没有子结点了。
  }               //就可以退出循环
 }
 a[i/2]=t;   //退出循环后，要将最原始要交换的值放到相对应的位置。
}
#endif
#if 0 //要求逆序输出输入的字符串，并且不能使用第三方变量。
void fput(char *a);
int main()
{
	char a[]="abcdefgh";
	fput(a);
	putchar('\n');
	return 0;
}
void fput (char *a)
{
	
	if(*a == '\0')
		return ;
	else
	{
		fput(++a);
		putchar(*(--a));
	}
}

#endif
#if 0 //用递归算法判断数组a[N]是否为一个递增数组。
int fun(int a[],int n);
int main()
{
 int a[10]={1,2,3,4,5,6,7,8,9,0};
 int n;
 n=fun(a,10);
 if (n==1)
 printf("是递增数组\n");
 else
 printf("不是递增数列\n");
 return 0;
}
int fun(int a[],int n)
{
 if (n==1)
 return 1;
 else 
  {
   if (fun(a,n-1)==1&&a[n-1]<a[n])
       return 1;
    else return 0;
  } 
}
#endif
void update(char a[]);
#if 0 //请实现一个函数，把字符串中的每个空格替换成"%20"，
void update(char a[]);
int main()
{
 char a[100]={"we are happay"};
 update(a);
 return 0;
}
void update(char a[])
{
 int i,j,n=0;
 for (i=0; a[i]!='\0'; ++i)
	 if (a[i]==' ')
		 n++;

 for (j=strlen(a)+2*n; j >= 0; )
 {
  if (a[i]!=' ')
	  {
		  a[j--]=a[i];
		  i--;
	  }
  else 
	  {
	   a[j--]='0';
	   a[j--]='2';
	   a[j--]='%';
	   i--;
	  }
 }
puts(a);
}
#endif
#if 0 //求1+2+3+....+n 要求不能使用乘除法 for while if else switch case 等关键字及条件判断语句
int f1(int n);
int f2(int n);
int (*p[2]) (int)={f1,f2};
int main()
{
 int n;
 printf("请输入一个数:n=");
 scanf("%d",&n);
 f2(n);
 printf("和为:%d\n",f2(n));
 return 0;
}
int f1(int n)
{
 return 0;
}
int f2(int n)
{
 return n+p[!!n](n-1);
}
#endif
#if 0
/*结构体的出现，能够将不同类型数据组成的组合型的数据结构，结构体类型的一半形式为
 struct 结构体名 {成员列表}
 定义结构体的变量的三种方法：
 1.先声明结构体类型，再定义该类型的变量。
  struct student
{
	int number;
	char name[20];
	char sex;
}；       再在主函数中声明   struct student stu1; stu1就是一个结构体类型。
 2.在声明类型的同时定义变量。
 struct student
{
	int number;
	char name[20];
	char sex;
}a;
3.在声明类型的同时定义变量（结构体名可以省略）typedef 代替一个复杂的类型
 typedef struct data
{
	char b;
	int number;
	char c;
}DATA;    可以用DATA来定义。比如: DATA a a就是一个结构体类型了。
*/
//结构体变量的初始化和引用
struct student
{
	int number;
	char name[20];
	char sex;
};
typedef struct data
{
	char b;
	int number;
	char c;
}DATA;

int main()
{
 //int i;
 //typedef struct student STU;
 //struct student stu ={1,"list",'m'}; //可以在定义的时候初始化
 //printf("%d\n",sizeof(stu)); //计算机在开辟内存的时候，采用的是字节对齐。小的在两边的话，采取的是分别对齐，小的在一堆的话，对齐一个就行了。
 /* 引用结构体变量中成员的值的时候，引用方式为： 结构体变量名.成员名 
 注意：不能通过输出结构体变量名来达到输出结构体变量名所有成员的值。
 同种类型的结构体变量可以相互赋值。
 */
    struct student stu ={1,"lisi",'m'} ;
	struct student stu1;
	typedef struct student STU;
	int i;
	STU *p = &stu;
	STU a[5] = {{1,"111",'1'},{2,"222",'2'},{3,"333",'3'},
	{4,"444",'4'},{5,"555",'5'}};
//	DATA a;
//	printf("%d\n",sizeof(stu));
	printf("%d %s %c\n",stu.number,stu.name,stu.sex);
	stu.number = 5;
	strcpy(stu.name,"asd");//gets(stu.name);
	stu.sex = 'm';
	printf("%d %s %c\n",stu.number,stu.name,stu.sex);
	
	scanf("%d",&stu.number);
	getchar();
	gets(stu.name);
	scanf("%c",&stu.sex);
	printf("%d %s %c\n",stu.number,stu.name,stu.sex);
	
	stu1 = stu;
	printf("%d %s %c\n",stu1.number,stu1.name,stu1.sex);
	
	for(i = 0;i<5;i++)
		printf("%d %s %c\n",a[i].number,a[i].name,a[i].sex);
//	for(i = 0;i<5;i++)
//		scanf("%d %s %c",&a[i].number,a[i].name,&a[i].sex);
	printf("%d,%d\n",p->number,(*p).number);
	p = a;
}
#endif
/*
结构体数组 
定义：
1.
struct 结构体名
{成员列表} 数组名[数组长度]
2.
先声明一个结构体类型
结构体类型 数组名[数组长度}
赋值的话可以用循环对其赋值，也可以在定义的时候赋值。
结构体指针
定义：
1.先定义 struct student *pt 再将p指向一个结构体变量就可以了
引用：  (*p).成员名  p->成员名  这两种方法都是可以的。
指向结构体数组的指针
  (1)先声明一个结构体类型，并且定义结构体数组，同时初始化。
  (2)定义一个指向结构体类型的指针变量p；
  (3)让p指向结构体数组的首元素，依次输出
 */
#if 0
typedef struct student
{
 int number;
 int name[20];
}STU;
void sort(STU *a,int n);
void print(STU *a,int n);
void input(STU *a,int n);
int main()
{
 STU a[5];
 input(a,5);
 sort(a,5);
 print(a,5);
 return 0;
}
void input(STU *a,int n)
{
 int i;
 for (i=0; i<5; ++i)
	 scanf("%d %s",&a[i].number,a[i].name);
}
void sort(STU *a,int n)
{
 int i,j;
 STU t;
 for (i=0; i<n-1; ++i)
	 for (j=0; j<n-1-i; ++j)
		 if (a[j].number>a[j+1].number )
		 {
		  t=a[j];
		  a[j]=a[j+1];
		  a[j+1]=t;
		 }
}
void print(STU *a,int n)
{
 int i;
 for (i=0; i<5; ++i)
	 printf("%d %s\n",a[i].number,a[i].name);
}
#endif
#if 0 //静态链表 由于静态链表的使用不是特别的多，初略的看一下代码就行了。
typedef struct node
{
	int n;
	struct node *next;
}Node;
int main()
{
 void main()
{
	Node a,b,c,d;
	Node *head = NULL,*p = NULL;
	head = &a;
	a.n = 1;
	a.next = &b;
	b.n = 2;
	b.next = &c;
	c.n = 3;
	c.next = &d;
	d.n = 4;
	d.next = NULL;

	p = head;
	while(p!= NULL)
	{
		printf("%d ",p->n);
		p = p->next;
	}
}
}
#endif
#if 0 //动态链表的创立
typedef struct node
{
	int n;
	struct node *next;
}Node;
Node *creat();
void print(Node *head);
int main()
{
 Node *head = creat();
 print(head);
 return 0;
}
Node *creat()
{
 Node *head=NULL,*pnew=NULL,*ptail=NULL; //先定义三个指针，分别指向空
 pnew=(Node*)malloc(sizeof(Node));  //先给pnew开辟内存空间
 pnew->next = NULL;                 //将pnew->next 指向空
 while (1==scanf("%d",&pnew->n))    //当输入的数据一直满足条件时 ，一直执行循环
 {
  if (head == NULL)     // 第一次的时候将head 指向pnew
	  head = pnew;      //head 始终指向第一个的首地址
   else 
	  ptail->next = pnew; //始终将 ptail->next 指向pnew的位置
  ptail=pnew;      //将ptail指向pnew的位置
  pnew = (Node*)malloc(sizeof(Node)); //再次为pnew开辟内存空间
  pnew->next = NULL;  //将pnew->next 指向空
 }
 free(pnew);
 pnew = NULL;
 return head; //将首地址返回
}
void print(Node *head)
{
 Node *p=head;
 while (p != NULL)
 {
	 printf("%d ",p->n);
	 p = p->next;
 }
 printf("\n");
}
#endif