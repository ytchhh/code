#if 0
int lerang (int n,int x);
int main()
{
 int n,x;
 int m;
 scanf("%d%d",&n,&x);
 m=lerang (n,x);
 printf("%d\n",m);
 return 0;
}
int lerang (int n,int x)
{
 if (n=0)
   return 1;
 else if(n=1) 
   return x;
 else if (n>=1)
   return ((2*n-1)*x-lerang(n-1,x)-(n-1)*lerang(n-2,x))/n;
}
#endif