#include<stdio.h>
#include<string.h>
#if 0
int main()
{
 int *p;
 char *q;
 printf("%d,%d\n",sizeof(p),sizeof(q));
 return 0;
}
#endif
#if 0
int main()
{
 int a=6;
 int b=8;
 int *p=&a;
 int *q=&b;
 printf("%d %d %d %d %d %d",*&a,*&p,&*p,p,&a,a);
 return 0;
}
#endif
#if 0
int main()
{
 int a=6;
 int b=8;
 int *p=&a;
 int *q=&b;
 int *t=NULL;
 int temp;
 /*
 t=p;
 p=q;
 q=t;
 */
 temp = *p;
 *p = *q;
 *q = temp;
 printf("%d,%d\n",a,b);
 printf("%d,%d\n",*p,*q);
 return 0;
}
#endif
#if 0
 void swap(int *a,int *b)
{
	int t ; 
	t = *a;
	*a = *b;
	*b = t;
}
int main()
{
	int a = 6,b = 8;//9
	swap(&a,&b);
	printf("%d,%d\n",a,b);
	return 0;
}
#endif
#if 0
int main()
{
 int a=0x11223344;
 short b=a;
 char c=a;
 printf("%x %x %x",a,b,c);
 return 0;
}
#endif
#if 0
int main()
{
 int *p=(int*)0x2000;
 int *q=(int*)0x2014;
 printf("%x\n",(char*)p+5);
 printf("%x\n",(double*)p+5);
 printf("%x\n",(short*)p+5);
 printf("%x\n",(long*)p+5);
 printf("%d\n",p-q);
 return 0;
}
#endif
#if 0
int main()
{
 int main()
{
	int *p = NULL;
	int a[N] = {1,2,3,4,5,6,7,8,9,0};
	//int b[3][4];
	int i = 0;
	//int *const a;
//	sizeof(a)
	p = &a[0];//a,&a[0] p = a
//	printf("%d\n",*p);
	for(i = 0;i<N;i++) //魔数
		printf("%d ",a[i]);
	printf("\n");
	for(i = 0;i<N;i++) //魔数
		printf("%d ",*(a+i));
	printf("\n");
	for(p= a,i = 0;i<N;i++) //魔数
		printf("%d ",p[i]);
	printf("\n");
	for(i = 0;i<N;i++) //魔数
		printf("%d ",*(p+i));
	printf("\n");

	for(p=a;p<a+N;p++) //for(p = a;p <p+N;p++);
		printf("%d ",*p);
	printf("\n");
	return 0;
}
 return 0;
}
#endif
#if 0
// 0000 0001 0000 0001 0000 0001 0000 0001
int main()
{
 char a[]={1,1,1,1,1};
 int *p=(int*)a;
 //char b='1';
 //char c=1;注意两者的区别。
 printf("%d\n",*p);
 return 0;
}
#endif
#if 0
int main()
{
	int a[5] = {1,3,5,7,9};
	int *p = (int*)(&a+1);
	printf("%d\n",*(p-1));
	return 0;
}
#endif
#if 0
int main()
{
	int a[] = {1,3,2,6,5,4,0,9,8,7};
	int n = sizeof(a)/sizeof(a[0]);
	int *p = a,*q = a + n-1;
	int t;
	//p[i],p[n-i-1]
	while(p < q)
	{
		t = *p;
		*p = *q;
		*q = t;
		++p;
		--q;
	}
	for(p = a;p<a+n;p++)
		printf("%d ",*p);
	return 0;
}
#endif
#if 0
int main()
{
	int a[] = {3,2,1,4,5,0,9,8,7,6};
	int n = sizeof(a)/sizeof(a[0]);
	int *p = a,*q = a,*m = a + n,t;
	for(p = a;p<a+n;p++)
	{
		for(q = a;q < m-1;q++)
		{
			if(*q > *(q+1))
			{
				t = *q;
				*q = *(q+1);
				*(q+1) = t;
			}
		}
		--m;
	}
	for(p = a;p < a + n;p++)
		printf("%d ",*p);
	printf("\n");
	return 0;
}
#endif
#if 1
int main()
{
	int a = 6;
	int *const p1 = &a;
	int const *p2= &a;
	const int *p3 = &a;
	const int *const p4 = &a;

	return 0;
}
#endif
