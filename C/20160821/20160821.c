#include<stdio.h>
#include <stdlib.h>
#if 0
int main()
{
printf("Hello Wolrd\n");

return 0;
}
#endif
#if 0 //有5个学生，每个学生有3门课程的成绩，从键盘输入学生数据(包括学号，姓名，三门课程成绩)
                                  //计算出平均成绩，将原有数据和计算出的平均分数存放在磁盘文件stud中
typedef struct student
{
	char number[10];
	char name[10];
	int score[3];
	int average;
}Stu;
/*
1 wang 98 97 96
2 yang 88 87 86
3 liu  78 77 76
4 sun  68 67 66
5 li   58 57 56
*/
int main()
{
 Stu a[5],b[5];
 FILE *p = NULL;
 FILE *p1 = NULL;
 int i,n,sum=0;
 p = fopen("stud.txt","wb");
 for (i=0; i<5; ++i)
	 scanf("%s%s%d%d%d",a[i].number,a[i].name,&a[i].score[0],&a[i].score[1],&a[i].score[2]);
 for (i=0; i<5; ++i)
 {
  sum = 0;
  sum = a[i].score[0]+a[i].score[1]+a[i].score[2];
  a[i].average = sum/3;
 }
 for (i=0; i<5; ++i)
	{
     fprintf(p,"%s %s %d,%d,%d,%d\r\n",a[i].number,a[i].name,a[i].score[0],a[i].score[1],a[i].score[2],a[i].average);
	}
 fclose(p);
 p = NULL;
 p1 = fopen("stud.txt","rb");
 //rewind(p);
 for (i=0; i<5; ++i)
 {
  n=fscanf(p1,"%s%s%d,%d,%d,%d",b[i].number,b[i].name,&b[i].score[0],&b[i].score[1],&b[i].score[2],&b[i].average);
  printf("%s,%s,%d,%d,%d,%d\n",b[i].number,b[i].name,b[i].score[0],b[i].score[1],b[i].score[2],b[i].average);
 }
 //fclose(p);
 fclose(p1);
 p1 = NULL;
 return 0;
}
#endif
#if 0 //将上一个题目的学生数据按照平均分呢进行排序，存放在磁盘文件 stud_sort中
typedef struct student
{
	char number[10];
	char name[10];
	int score[3];
	int average;
}Stu;
int main()
{
 FILE *p1 = NULL,*p2 = NULL;
 Stu b[5],t;
 int i,j;

 p1 = fopen("stud.txt","rb");
 for (i = 0; i<5; ++i)
 fscanf(p1,"%s%s%d,%d,%d,%d",b[i].number,b[i].name,&b[i].score[0],&b[i].score[1],&b[i].score[2],&b[i].average);
 for (i= 0; i<5-1; ++i)
     for (j = 0; j<5-1-i; ++j)
       if (b[j].average > b[j+1].average)
       {
        t = b[j];
        b[j] = b[j+1];
        b[j+1] = t;
       }
 fclose(p1);
 p1 = NULL;
 p2 = fopen("stu-sort.txt","wb");
 for (i = 0; i<5; ++i)
   fprintf(p2,"%s %s %d,%d,%d,%d\r\n",b[i].number,b[i].name,b[i].score[0],b[i].score[1],b[i].score[2],b[i].average);
printf("排序成功\n");
 fclose(p2);
 p2 = NULL;
 return 0;
}
#endif
#if 0 //将上个题目中的学生数据进行插入排序，输入一个学生的三门数据，计算平均分后，插入。插入后建立一个新文件
typedef struct student
{
	char number[10];
	char name[10];
	int score[3];
	int average;
}Stu;
int main()
{
 FILE *p1 = NULL,*p2 = NULL;
 int i,j;
 Stu b,a[6],t;
 scanf("%s%s%d%d%d",b.number,b.name,&b.score[0],&b.score[1],&b.score[2]);
 b.average = (b.score[0]+b.score[1]+b.score[2])/3;
 p1 = fopen("stu-sort.txt","rb");
 for (i = 0; i<5; ++i)
 fscanf(p1,"%s%s%d,%d,%d,%d",a[i].number,a[i].name,&a[i].score[0],&a[i].score[1],&a[i].score[2],&a[i].average);
 a[i] = b;
 for (i = 0; i<6-1; ++i)
     for (j = 0; j< 6-1-i; ++j)
     if (a[j].average > a[j+1].average)
     {
      t  = a[j];
      a[j] = a[j+1];
      a[j+1] =t;
     }
  fclose(p1);
  p1 = NULL;
  p2 = fopen("stud-sort1.txt","wb");
  for (i = 0; i<6; ++i)
  fprintf(p2,"%s %s %d,%d,%d,%d\r\n",a[i].number,a[i].name,a[i].score[0],a[i].score[1],a[i].score[2],a[i].average);
 printf("插入成功\n");
 fclose(p2);
 p2 = NULL;
 return 0;
}
#endif
#if 0 //将上一题的结果存入原有的"stu-sort"文件而不另建立新文件
int main()
{

}
#endif
#if 0 //有一个磁盘文件"employee",内存放职工的数据。每个职工的数据包括职工姓名，职工好，性别，
      //年龄，住址，工资，健康状况，文化程度。今要求将职工名，工资的信息单独列出来，另建一个简明的
      //职工工资文件
typedef struct data
{
 char name[10];
 char number[10];
 char sex;
 int age;
 char address[20];
 int salary;
 char condition[10];
 char education[10];
}Data;
int main()
{
 FILE *p1 = NULL,*p2 = NULL;
 int i;
 p1 = fopen("employee.txt","rb");
 p2 = fopen("employee1.txt","wb");
 Data a[3];
 for (i = 0; i < 3; ++i)
 fscanf(p1,"%s%s %c %d%s%d%s%s",a[i].name,a[i].number,&a[i].sex,&a[i].age,a[i].address,&a[i].salary,a[i].condition,a[i].education);
 fclose(p1);
 p1 = NULL;
 for (i = 0; i < 3; ++i)
 fprintf(p2,"%s %d\r\n",a[i].name,a[i].salary);
 fclose(p2);
 p2 = NULL;
 return 0;
}
#endif
#if 0//将上题的 职工工资文件 中删去一个职工的数据，再存回原文件
typedef struct data
{
 char name[10];
 char number[10];
 char sex;
 int age;
 char address[20];
 int salary;
 char condition[10];
 char education[10];
}Data;
int main()
{
 FILE *p1 = NULL;
 int i;
 Data a[3];
 p1 = fopen("employee1.txt","rb+");
 for (i = 0; i < 3; ++i)
 fscanf(p1,"%s%d",a[i].name,&a[i].salary);
 rewind(p1);
 for (i = 0; i < 3; i=i+2)
 fprintf(p1,"%s %d\r\n",a[i].name,a[i].salary);
 fclose(p1);
 p1 = NULL;
}
#endif
#if 1 //从键盘输入若干行字符，输入后把他们存储到一个磁盘文件中，再从该文件读入这些数据，将其中
      //小写字母转换成大写字母后在显示屏输出
int main()
{
 char a[4][20];
 int i;
 FILE *p1 = NULL,*p2 = NULL;
 for (i = 0; i < 4; ++i)
      scanf("%s",a[i]);
 p1 = fopen("2.txt","wb");
 for (i = 0; i < 10; ++i)
 fprintf(p1,"%s\r\n",a[i]);

 fclose(p1);
 p1 = NULL;
}
#endif
