#include<stdio.h>
#if 0
int sum(int a[],int n);
int main()
{
 int a[100];
 int i,m;
 for (i=0; i<100; ++i)
 a[i]=i+1;
 m=sum(a,100);
 printf("%d\n",m);
 return 0;
}
int sum(int a[],int n)
{
 return ((n>1)?a[n-1]+sum(a,n-1):a[0]);
}
#endif
#if 1 //将二维数组中的 查找整数
void find(int a[][4],int n);
int main()
{
 int a[4][4]={{1,2,3,4},{2,3,4,5},{3,4,5,6},{4,5,6,7}};
 int n;
 printf("输入要查找的数:");
 scanf("%d",&n);
 find(a,n);
}
void find(int a[][4],int n)
{
 int i,m,j=0,l=3,k=4;
 for (i=0; i<4; ++i)
 {
  if (n>=a[i][0]&&n<=a[i][3])
	  k=i;break;
 }
 if (k==4)
  printf("查无此数\n");
 else 
 {  i=k;
  while(j<l)
  { m=(j+l)/2;
   if (n>a[k][m])
   j=m+1;
   else l=m-1;
  }
  m=(j+l)/2;
  if (n==a[k][m])
	  printf("有这个数\n");
  else 
	  printf("查无此数\n");
 }
}
#endif