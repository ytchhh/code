#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#if 0 //定义一个结构体变量(包括年月日)。计算该日在本年中是第几天，注意闰年问题。
typedef struct date
{
 int year;
 int months;
 int day;
}Date;
int main()
{
 Date number;
 int n=0,i;
 int a[2][13]={{0,31,29,31,30,31,30,31,31,30,31,30,31},
	          {0,31,29,31,30,31,30,31,31,30,31,30,31}};
 printf("请输入年月日\n");
 scanf("%d%d%d",&number.year,&number.months,&number.day);
 if (number.year%4 == 0 && number.year%100 != 0 || number.year%400 !=0)
	    {
			for (i=1; i<number.months; ++i)
				n=n+a[0][i];
	    }
	else 
		{
			for (i=1; i<number.months; ++i)
				n=n+a[1][i];
		}
	n=n+number.day;
 printf("该天是本年中的第%d天\n",n);
 return  0;
}
#endif
#if 0 //写一个函数days，实现第一题的计算，由主函数将年月日传递给days函数，计算后将日子数传回主函数输出
typedef struct date
{
 int year;
 int months;
 int day;
}Date;
int count(Date number);
int main()
{
 Date number;
 int n;
 printf("请输入年月日\n");
 scanf("%d%d%d",&number.year,&number.months,&number.day);
 n=count(number);
 printf("该天是本年中的第%d天\n",n);
 return  0;
}
int count(Date number)
{
	int a[2][13]={{0,31,29,31,30,31,30,31,31,30,31,30,31},
	              {0,31,29,31,30,31,30,31,31,30,31,30,31}};
    int n=0,i;
	if (number.year%4 == 0 && number.year%100 != 0 || number.year%400 !=0)
	    {
			for (i=1; i<number.months; ++i)
				n=n+a[0][i];
	    }
	else 
		{
			for (i=1; i<number.months; ++i)
				n=n+a[1][i];
		}
	n=n+number.day;
	return n;
}
#endif
#if 0 //编写一个函数print,打印一个学生的成绩数组，该数组中有5个学生的数据记录，每个记录包括num,name,score[3]
      //每个记录包括num,name,score[3],用主函数输入这些记录，用print函数输出这些记录。
typedef struct student
{
 int num;
 char name[20];
 int score[3];
}Stu;
void print(Stu a[]);
int main()
{
 int i;
 Stu a[5];
 for (i=0; i<5; ++i)
	 scanf("%d %s %d %d %d",&a[i].num,a[i].name,&a[i].score[0],&a[i].score[1],&a[i].score[2]);
 print(a);
 return 0;
}
void print(Stu a[])
{
 int i;
 for (i=0; i<5; ++i)
	 printf("%d %s %d %d %d\n",a[i].num,a[i].name,a[i].score[0],a[i].score[1],a[i].score[2]);
}
#endif
#if 0 //在第三题的基础上，编写一个函数input，用来输入5个学生的数据记录。
typedef struct student
{
 int num;
 char name[20];
 int score[3];
}Stu;
void input(Stu a[]);
void print(Stu a[]);
int main()
{
 Stu a[5];
 input(a);
 print(a);
 return 0;
}
void input(Stu a[])
{
 int i;
 for (i=0; i<5; ++i)
	 scanf("%d %s %d %d %d",&a[i].num,a[i].name,&a[i].score[0],&a[i].score[1],&a[i].score[2]);
}
void print(Stu a[])
{
 int i;
 for (i=0; i<5; ++i)
	 printf("%d %s %d %d %d\n",a[i].num,a[i].name,a[i].score[0],a[i].score[1],a[i].score[2]);
}
#endif
#if 0 //有10个学生，每个学生的数据包括学号，姓名，3门课程的成绩，从键盘输入10个学生数据，要求输出三门课程
      //的总平均成绩，以及最高分的同学的数据（包括学号，姓名，三门课程成绩，平均分数）
/*  成绩输入样本
1 wang 56 57 58
2 yang 76 79 99
3 liu  87 88 86
4 wu   55 56 57
5 sun  67 68 69
*/
typedef struct student
{
 int num;
 char name[20];
 int score[3];
}Stu;
void input(Stu a[]);
void print(Stu a[]);
int main()
{
 Stu a[5];
 printf("请输入学生数据:\n");
 input(a);
 print(a);
 return 0;
}
void input(Stu a[])
{
 int i;
 for (i=0; i<5; ++i)
	 scanf("%d %s %d %d %d",&a[i].num,a[i].name,&a[i].score[0],&a[i].score[1],&a[i].score[2]);
}
void print(Stu a[])
{
 int i,sum=0;
 int max=a[0].score[0];
 int n=0;
 for (i=0; i<5; ++i)
	 {
		 sum=sum+a[i].score[0]+a[i].score[1]+a[i].score[2];
	 }
 for (i=0; i<5; ++i)
	 {
		 if (max < a[i].score[0])
		 {
			 max = a[i].score[0];
			 n=i;
		 }
		  if (max < a[i].score[1])
		 {
			 max = a[i].score[1];
			 n=i;
		 }
		  if (max < a[i].score[2])
		 {
			 max = a[i].score[2];
			 n=i;
		 }
	 }
 printf("三门课程的总平均成绩为:%d\n",sum/15);
 printf("最高分为第%d位学生\n",n+1);
 printf("学号:%d,姓名:%s,成绩1:%d,成绩2:%d,成绩3:%d,平均成绩:%d\n",a[n].num,a[n].name,a[n].score[0],a[n].score[1],a[n].score[2],(a[n].score[0]+a[n].score[1]+a[n].score[2])/3);
}
#endif
#if 0  //13个人围成一圈，从第一个人开始顺序报号1，2，3.凡报到3者退出圈子。找出最后留在圈子中的人原来的序号。
       //要求用链表实现
typedef struct data
{
 int number;
 struct data *next;
}Data;
Data *creat();
Data* count(Data *head); 
void print(Data *head);
int main()
{
 Data *head = creat();
 print(count(head));
 return 0;
}
Data *creat()
{
 Data *head = NULL,*p1 = NULL,*p2 = NULL;
 p1 = (Data*)malloc(sizeof(Data));
 p1 ->next = NULL;
 while (1 == scanf("%d",&p1->number))
 {
  if (head == NULL)
	  head =p1;
  else 
	  p2->next = p1;
  p2 = p1;
  p1 = (Data*)malloc(sizeof(Data));
  p1->next = NULL;
 }
 free(p1);
 p1 = NULL;
 p2 ->next = head;
 return head;
}
Data* count(Data *head)
{
 Data *p1 = NULL,*p2=NULL,*p3=NULL;
 int k=1;
 p1 = p2 = head;
 while (p1->next != p1)
 {
  if (k == 3)  //如果 k == 3的话，
	  {
	   p3 = p1; //将p3指向p1
	   p1 = p1->next;//p1指向下一个
	   p2->next = p1;//再重新连接起来
	   free(p3);// 将要删除的释放掉
	   p3 = NULL;// 将p3指向为NULL
	   k = 0; //再将k重新置为0
	  }
  else 
  {
    p2 = p1; //如果不是的话，p2始终指向的是p1前面的一个数据
	p1 = p1->next;//p1再指向下一个
  }
  k++;  //每次k自加一次
 }
 p1->next = NULL; //最后跳出循环的时候将 p1->next指向为 NULL
 return (p1);
}
void print(Data *head)
{
 Data *p = NULL;
 p=head;
 printf("%d\n",p->number);
}
#endif
#if 0 //在第九章例9.9和例9.10的基础上，写一个函数del，用来删除动态链表中指定的结点
typedef struct data
{
 int number;
 struct data *next;
}Data;
Data* creat();
Data* del(Data *head,int n);
Data* find(Data *head,int n); 
void print(Data *head);
int main()
{
 int n;
 Data *head =creat();
 printf("输入要删除的数:n=");
 getchar();
 scanf("%d",&n);
 head=del(head,n);
 print(head);
 return 0;
}
Data *creat()
{
 Data *head = NULL,*p1 = NULL,*p2 = NULL;
 p1 = (Data*)malloc(sizeof(Data));
 p1 ->next = NULL;
 while (1 == scanf("%d",&p1->number))
 {
  if (head == NULL)
	  head =p1;
  else 
	  p2->next = p1;
  p2 = p1;
  p1 = (Data*)malloc(sizeof(Data));
  p1->next = NULL;
 }
 free(p1);
 p1 = NULL;
 return head;
}
Data* find(Data *head,int n)
{
 Data *p1 = NULL,*p2 = NULL;
 p1 = head;
 if (head->number==n)
	 return NULL;
 else 
	 {
		 while (p1->next != NULL)
			 {
				 if (p1->next->number == n)
					 p2 = p1 ; 
				 p1 = p1->next;
			 }
		 if (p2 != NULL)
			 return p2;
		 return NULL;
	 }
}
Data* del(Data *head,int n)
{
 Data *p1 = NULL,*p2 = NULL,*p3 = NULL;
 p1 = head;
 p2 = find(head,n);
 if (head->number == n )
	 {
		 head = head->next;
		 free(p1);
		 p1= NULL;
	 }
 else 
	 {
       if (p2 == NULL)
			  { 
				 printf("要删除的数据不在里面\n");
	             head = NULL;
			  }
	   else if (p2->next->number == n)
	   {
		   p3 = p2->next;
		   p2->next=p3->next;
		   free(p3);
		   p3 = NULL;
	   }
	 }
 return head;
}
void print(Data *head)
{
	Data *p = head;
	while(p != NULL)
	{
		printf("%d ",p->number);
		p = p->next;
	}
	printf("\n");
}
#endif
