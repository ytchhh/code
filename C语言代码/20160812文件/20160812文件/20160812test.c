#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys\stat.h>
#if 0
void sort(char *a,int n);
int main()
{
 FILE *p1 = NULL,*p2 = NULL;
 int size=0,n;
 char a[20] = "";
 p1 = fopen("1.txt","r"); //表示打开名字为1.txt的文件，使用方式为读入 r为read的意思
 p2 = fopen("2.txt","wb");//表示为了输出数据，打开一个二进制文件。
 if (p1 == NULL)
	 printf("error\n");
 fseek(p1,0,2); //fseek 函数将指针进行移动，可以改变文件的位置
 size = ftell(p1);
 rewind(p1); //rewind 将指针指向文件开始的位置 或者用fseek(p1,0,0)也可以移动位置。
 n=fread(a,size,1,p1);//fread函数的返回值为成功的次数。
 printf("%d\n",n);   //fread是从p1指向的文件读入1个size字节的数据。
 puts(a);
 sort(a,size);
 puts(a);
 fwrite(a,size,1,p2);//fwrite是将从a所指向的地址读入1个size字节的数据存到p2中去
 fclose(p1);
 fclose(p2);//文件使用结束后都要使用fclose函数来关闭 让指针不指向文件的位置
}
void sort(char *a,int n)
{
	int i,j;
	char t;
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<n-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}
#endif
#if 0
/*
EOF 是文件结束的标志
*/
int main()
{
 FILE *p1 = NULL,*p2 = NULL;
 char a;
 int n,size = 0;
 p1 = fopen("1.txt","r");
 p2 = fopen("2.txt","wb"); //fgetc是每次向p1所指向的文件读入一个字符 
 while ( (a = fgetc(p1)) != EOF ) //fputc是将字符写到p2所指向的文件中
 {
  putchar(a);
  fputc(a,p2);
 }
 printf("\n");
 return 0;
}
#endif
#if 0
/*
-stat 原型就是 int _stat(const char *path,struct-stat *buffer)
*/
int main()
{
 FILE *p1 = NULL,*p2=NULL;
 //char a[20];
 struct _stat buf;  //使用时加上头文件
 int n,size = 0;
 int a,b;
 p1 = fopen("1.txt","r");
 p2 = fopen("2.txt","wb");
 _stat("1.txt",&buf);
 size = buf.st_size;
 //fgets(a,size+1,p1);//作用是将p1所指向的文件读入一个长度为size的字符串，并在后面加上一个'\0'字符
                    //然后将size+1个字符存放到字符数组a里面去。
 //fputs(a,p2);  // 将a所指向的字符串写到p2所指向的文件中去。
 fscanf(p1,"%2d%3d",&a,&b); //是将磁盘文件中的数据读取两个分别送给整型a和b。
 fprintf(p2,"a=%d,b=%d",a,b); //将int 型变量a和b分别输出到p2所指向的文件中去。
 fprintf(p2,"asdfasdfad");
 fclose(p1);
 fclose(p2);
 return 0;          //
}
#endif
#if 0
#include <malloc.h>
#include <string.h>
typedef struct data
{
	char a[3];
	char num[7];  //以二进制读取的时候没行要加两个才行 
}Data;            //以文本读取的时候只加一个
void sort(Data *p,int n);
int main()
{
 Data *p = NULL;
 FILE *p1 = fopen("1.txt","r");
 FILE *p2 = fopen("2.txt","w");
 int size = 0,n=0,i;
 struct _stat buf;
 _stat("1.txt",&buf);
 size =buf.st_size; //这个可以求总长度
 n = size / sizeof(Data); //求出多少行
 p = (Data *)malloc(n*sizeof(Data));//给p开辟内存空间
 for(i = 0;i<n;i++)
	{
		fread(&p[i],sizeof(Data),1,p1);
	}
 sort(p,n);
 for(i = 0;i<n;i++)
	{
		fwrite(&p[i],sizeof(Data),1,p2);
	}
 fclose(p1);
 fclose(p2);
 return 0;
}
void sort(Data *p,int n)
{
	int i,j;
	Data t;
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<n-i-1;j++)
		{
			if(strncmp(p[j].num,p[j+1].num,7) > 0) //因为这儿的数据都没有以'\0'结束，
			{                                      //所以比较的时候要用strncmp来进行比较。
				t = p[j];
				p[j] = p[j+1];
				p[j+1] = t;
			}
		}
	}
}

#endif
#if 0 //从键盘输入一个字符串，将其中的小写字母全部转换为大写字母，然后输出到一个磁盘文件“test”中保存
                                               //输入的字符串以'！'结束。
int main()
{
 FILE *p = NULL;
 char ch;
 if ((p = fopen("test.txt","wb")) == NULL)
 {
  printf("无法打开此文件\n");
  exit(0);
 }
 printf("请输入要存储的字符串(以！结束):");
 while ((ch = getchar()) != '!')
 {
	 if (ch >= 'a' && ch <= 'z')
      fputc(ch+'A'-'a',p);
	 else 
      fputc(ch,p);
 }
 fclose(p);
 return 0;
 return 0;
}

#endif
#if 0 //有两个磁盘文件A和B，各自存放一行字母，今要求把这两个文件中的信息合并(按字母顺序排列)
                                                  //输出到一个新的文件夹C中去
int main()
{
 FILE *p1 = NULL,*p2 = NULL,*p3 = NULL;
 char a[100],ch;
 int i=0,n,j;
 p1 = fopen("A.txt","r");
 p2 = fopen("B.txt","r");
 p3 = fopen("C.txt","wb");
 while ((ch = fgetc(p1)) != EOF)
 {
  a[i++] = ch;
 }
 i--;
 while ((ch = fgetc(p2)) != EOF)
 {
  a[i++] = ch;
 }
 a[i] = '\0';
 n = strlen(a);
 for (i=0; i<n-1; ++i)
	 for (j=0; j<n-1-i; ++j)
		 {
		  if (a[j]>a[j+1])
			  {
			   ch = a[j];
			   a[j] = a[j+1];
			   a[j+1] = ch;
			  }
		 }
 fputs(a,p3);
 fclose(p1);
 fclose(p2);
 fclose(p3);
 return 0;
}
#endif
#if 1 //有5个学生，每个学生有3门课程的成绩，从键盘输入学生数据(包括学号，姓名，三门课程成绩)
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
 fclose(p); //
 p1 = fopen("stud.txt","rb");
 //rewind(p);
 for (i=0; i<5; ++i)
 {
  n=fscanf(p1,"%s%s%d,%d,%d,%d",b[i].number,b[i].name,&b[i].score[0],&b[i].score[1],&b[i].score[2],&b[i].average);
  printf("%s,%s,%d,%d,%d,%d\n",b[i].number,b[i].name,b[i].score[0],b[i].score[1],b[i].score[2],b[i].average);
 }
 fclose(p);
 fclose(p1);
 return 0;
}
#endif
