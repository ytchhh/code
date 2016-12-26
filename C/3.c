#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NUM 100
void zcd();
void input();
void sort();
void search();
void print();
void print1();
void print2();
void modify();
struct student
{  int term;
      int num;
      int classes;
      char name[10];
      int score[4];
      int sum;
      float average;
}stu[NUM];
void main()
{
	zcd();
}
//主函数界面//


void zcd()
{
int n=0;
	char m;
	system("cls");   //清屏//
	   printf("按任意键进入主菜单\n ");   //按任意键进入主菜单//
       printf("--------------------------------------------------------------------------\n");
       printf("\t\t\t\t\t西安石油大学欢迎你\n");
       printf("\n\t\t\t--------- 欢迎使用学生管理系统\n\n\t\t\t\t\t-----------\n");
 printf("--------------------------------------------------------------------------\n");
       printf("\t\t\t1. 输入学生成绩记录 Input the record\n");   //输入学生成绩记录//
       printf("\t\t\t2. 排序 Sort to make new a file\n");   //排序//
	   printf("\t\t\t3. 按班级显示成绩单 Print the record\n");   //显示//
       printf("\t\t\t4. 查询个人成绩 Search record on name\n");   //查询//
       printf("\t\t\t5. 修改成绩 Modify a record\n");   //修改//
       printf("\t\t\t6. 退出 Quit\n");   //退出//
       printf("--------------------------------------------------------------------------\n");
       printf("\n\t\t\t输入你的选择Enter your choice(1~7):");
       fflush(stdin);
	   m=getchar();
	do
	{
		switch(m)
		{
		   case '1':input();zcd();break;
           case '2':sort();system("pause");zcd();break;
		   case '3':print();system("pause");break;
           case '4':search();zcd();break;
           case '5':modify();system("pause");zcd();break;
           case '6':exit(0); //如菜单返回值为7则程序结束//
		   default:printf("指令错误，程序结束"); getchar();zcd();
		}
	} while(1);

}


void input()
{
   system("cls");
    int i;
	char a;
	for(i=0;i<NUM;i++)
	{  printf(" \n请输入学生的学期：");
	  scanf("%d",&stu[i].term);

printf(" \n请输入学生的学号：");
	  fflush(stdin);
	  scanf("%d",&stu[i].num);

	  printf(" \n请输入学生的班级：");
	  scanf("%d",&stu[i].classes);

	  printf("\n请输入学生的姓名：");
	  scanf("%s", stu[i].name) ;

	  printf("\n请输入学生的高数成绩：");
	  scanf("%d",&stu[i].score[0]);
	  printf("\n请输入学生的物理成绩：");
	  scanf("%d", &stu[i].score[1]);
	  stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2]+stu[i].score[3];  //计算总分和平均分//
      stu[i].average=(double)stu[i].sum/4.0;

	   printf("是否要继续添加(按N&n退出)");
	  fflush(stdin);
	  a=getchar();
	  if(a=='n'||a=='N')
		 break;
	}
}


void sort()
{
    int i,j=0;
	float temp;
    for(i=0;i<NUM;i++)
    {
	   stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2]+stu[i].score[3];
       stu[i].average=(float)stu[i].sum/4.0;
    }
	for(i=0;i<NUM-1;i++)
	{
		for(j=i+1;j<NUM;j++)
		{
			if(stu[i].sum<stu[j].sum)
			{
				temp=stu[i].sum;
                stu[i].sum=stu[j].sum;
                stu[j].sum=temp;
			}
		}
 	}
   printf("学号\t姓名\t班级 高数 物理 总分 平均分\n");
   for(i=0;i<NUM;i++)
      printf("%d\t%s\t%d%5d%5d%5d%8.2f\n",stu[i].num,stu[i].name,stu[i].classes,
		     stu[i].score[0],stu[i].score[1],stu[i].sum,stu[i].average);   //输出学生信息//
	system("pause");system("cls");print();
}


void search()
{
   system("cls");   //清屏//
   int number=0,i;
   printf("\t\t\t 请输入要查找学生的学号:");
   scanf("%d",&number);
   printf("学号\t姓名\t班级 高数 物理 总分 平均分\n");
	  	for(i=0;i<NUM;i++)

	  if(number==stu[i].num) break;   //查找判断//
	   if(i<NUM)
	{printf("%d\t%s\t%d%5d%5d%5d%8.2f\n",stu[i].num,stu[i].name,stu[i].classes,
stu[i].score[0],stu[i].score[1],stu[i].sum,stu[i].average);   //输出学生信息//
	   }
	 else
			printf("未找到该学生的信息\n");
	system("pause");


}
void print()
{
    system("cls");
	char a;
    printf("1、按学期输出\n");
	printf("2、按班级输出\n");
	printf("3、返回\n");
	fflush(stdin);
	a=getchar();
	switch(a)
	{
	case '1':print1();
	case '2':print2();
	case '3':zcd();
	default:print();
	}
}
void print1()   //按学期查询//
{
	int i,m;
	printf("请输入查询的学期：\n");
	scanf("%d",&m);
	printf("学号\t姓名\t班级  高数 物理 总分 平均分\n");
	for(i=0;i<NUM;i++)
	{
	  if(m==stu[i].term)
      printf("%d\t%s\t%d%5d%5d%5d%8.2f\n",stu[i].num,stu[i].name,stu[i].classes,
		     stu[i].score[0],stu[i].score[1],stu[i].sum,stu[i].average);   //出学生信息//
	}
	system("pause");system("cls");print();
}


void print2()  //按班级查询//
{
	int i,j,k;
	printf("请输入查询的班级：\n");
	scanf("%d",&k);
    printf("学号\t姓名\t班级 高数 物理 总分 平均分\n");
	for(i=0;i<NUM;i++)
	{
	  if(k==stu[i].classes)
	  {
		  stu[i].sum=stu[i].score[0]+stu[i].score[1];
          stu[i].average=stu[i].sum/2.0;
          printf("%d\t%s\t%d%5d%5d%5d%8.2f\n",stu[i].num,stu[i].name,stu[i].classes,
		  stu[i].score[0],stu[i].score[1],stu[i].sum,stu[i].average);   //输出学生信息//
	  }
	}
	printf("输出不及格学生名单及成绩：\n");
	printf("学号\t姓名\t班级 高数 物理\n");
	for(i=0;i<NUM;i++)
	{for(j=0;j<2;j++)
	  {
		  if(stu[i].score[j]<60&&k==stu[i].classes)   //输出不及格学生名单及成绩//
          printf("%d\t%s\t%d%5d%5d\n",stu[i].num,stu[i].name,stu[i].classes,
		     stu[i].score[0],stu[i].score[1]);
		  break;
	  }
	}
	system("pause");system("cls");print();
}
void modify()
{
system("cls");
   int number,i;
   printf("\t\t\t请输入要修改信息的学生学号:");
   scanf("\t\t\t%d",&number);
   for(i=0;i<NUM;i++)
        if(number=stu[i].num)  break;   //查找判断//
	   if(i<NUM)   //查找判断//

	   {
          printf("请输入修改后的学生的信息：");

printf(" \n请输入学生的学期：");
	      scanf("%d",&stu[i].term);

	      printf(" \n请输入学生的学号：");
	      fflush(stdin);
	      scanf("%d",&stu[i].num);

	      printf(" \n请输入学生的班级：");
	      scanf("%d",&stu[i].classes);

	      printf("\n请输入学生的姓名：");
	      scanf("%s", stu[i].name) ;

	      printf("\n请输入学生的高数成绩：");
	      scanf("%d",&stu[i].score[0]);

	      printf("\n请输入学生的物理成绩：");
	      scanf("%d", &stu[i].score[2]);

	   }
   else
			printf("未找到该学生的信息\n");

	system("paues");system("cls");zcd();
}
