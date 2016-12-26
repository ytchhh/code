#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#if 0
int main()
{
 unsigned char a[255],i;
 for (i=0;i<=255;++i)
	 a[i]=i;
 return 0;
}
#endif
#if 0
int main()
{
 char a[1000];   //
 int i;
 for (i=0; i<1000; ++i)
 {
     a[i] = -1-i;
 }
 printf("%d\n",strlen(a));
 return 0;
}
#endif
#if 0
#define N 100
void invert(int *p,int n);
int main()
{
 int *p=NULL,a[N],n,i;
 printf("请输入数的个数:n=");
 scanf("%d",&n);
 for (i=0;i<n;++i)
   scanf("%d",&a[i]);
 p=a;
 invert(p,n);
 return 0;
}
void invert(int *p,int n)
{
 int i;
 i=n-1;
 for (i; i>=0; --i)
	 printf("%d ",p[i]);
 printf("\n");
}
#endif
#if 0
void count(char *p,int *q);
int main()
{
 char a[20];
 char *p=NULL;
 int b[10];
 int *q=NULL;
 q=b;
 p=a;
 gets(a);
 count(p,q);
 return 0;
}
void count(char *p,int *q)
{
 int i,n=0;
 int *t=q;
 for (;*p!='\0';++p)
 {
  if (*p >='0'&&*p <='9')
  {
   *q=*p-'0';
  p++;
  while (*p >='0'&&*p <='9')
	  *q=(*q)*10+((*p++)-'0');
  n++;
  q++;
  }
 }
q=t;
 for (i=0; i<n; ++i)
	 printf("%d ",q[i]);
 printf("一共有%d个整数\n",n);
}
#endif
#if 0
int mystrcmp(char *p1,char *p2);
int main()
{
 char a[20],b[20];
 char *p1=NULL,*p2=NULL;
 gets(a);
 gets(b);
 p1=a;
 p2=b;
 printf("%d\n",mystrcmp(p1,p2));
 return 0;
}
int mystrcmp(char *p1,char *p2)
{
 while (*p1==*p2)
 {
  if (*p1=='\0')
	  return 0;
  p1++;
  p2++;
 }
 return (*p1-*p2);
}
#endif
#if 0
int main()
{
 char *a[12]={"Janurary","February","March","April","May","June","July","August","Setember",
               "October","November","December"};
 int m;
 printf("请输入月份：m=");
 scanf("%d",&m);
 printf("%s\n",a[m-1]);
 return 0;
}
#endif
#if 0
void sort(char **p);
int main()
{
 char *a[5]={"dcfde","esrty","cxzas","bvcx","asdfg"};
 char **p;
 int i;
 p=a;
 sort(p);
 for (i=0; i<5; ++i)
	 puts(p[i]);
 return 0;
}
void sort(char **p)
{
 int i,j;
 for (i=0; i<5-1; ++i)
 {
	 char *t;
  for (j=0; j<5-1-i; ++j)
	  if (strcmp(p[j],p[j+1])>0)
	  {
	   t=p[j];
	   p[j]=p[j+1];
	   p[j+1]=t;
	  }
 }
}
#endif
#if 0
void sort(int **p);
int main()
{
 int a[10]={1,2,3,4,5,6,7,8,9,0};
 
 int **p,i;
 
 p=(int**)malloc(40); //先开辟内存空间存放地址才行
 *p=a;
 //p=&(*p);
 for (i=0; i<10; ++i)
    printf("%d ",*(*p+i));//
 printf("\n");
 sort(p);
 for (i=0; i<10; ++i)
	 printf("%d ",(*p)[i]);//
 printf("\n");
 return 0;
}
void sort(int **p)
{
 int i,j,t;
 for (i=0; i<10-1; ++i)
 {
  for (j=0; j<10-1-i; ++j)
	  if (p[j]>p[j+1])
	  {
	   t=(*p)[j];
	   (*p)[j]=(*p)[j+1];
	   (*p)[j+1]=t;
	  }
 }
}
#endif
#if 0
char* mystr(char *p1,char *p2);
int main()
{
 char a[20],b[20];
 char *p1=NULL,*p2=NULL;
 p1=a;
 p2=b;
 gets(b);
 mystr(p1,p2);
 puts(p1);
 return 0;
}
char* mystr(char *p1,char *p2)
{
 char *t;
 t=p1;
 while(*p2!='\0')
  *p1++=*p2++;
 *p1='\0';
 return p1;
}
#endif
#if 1
int main()
{
 
 return 0;
}
#endif