#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#if 0
void invert(int *p[4][4],char c); //对数组进行翻转
void print(int a[][4]);
int main()
{
 int a[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
 char c;
 int i,j;
 int *p[4][4];
 print(a);
 printf("input a charcater:");
 c = getchar();
 for (i = 0; i<4; ++i)
    for (j = 0; j<4; ++j)
 p[i][j] = &a[i][j];
 invert(p,c);
 for (i = 0; i<4; ++i)
{
 for(j = 0; j<4; ++j)
 printf("%-3d",*p[i][j]);
 printf("\n");
}
print(a);
 return 0;
}
void invert(int *p[4][4],char c)
{
 int i,j,*t;
 int *q[4][4];
 if (c == 'w')
 ;
 if (c == 's')
   {
   for (i = 0; i < 3; ++i)
      {
       for (j = 0; j < 3-i; ++j)
           {
            t = p[i][j];
            p[i][j] = p[3-i][3-j];
            p[3-i][3-j] = t;             
           }
      }
   t = p[0][3]; p[0][3] = p[3][0]; p[3][0] = t;
   t = p[1][2]; p[1][2] = p[2][1]; p[2][1] = t;
   }
 if (c == 'a')
     {
     for (i = 0; i < 4; ++i)
       {
         q[0][i] = p[3-i][0];
         q[1][i] = p[3-i][1];
         q[2][i] = p[3-i][2];
         q[3][i] = p[3-i][3];
       }
     for (i=0; i < 4; ++i)
         for (j=0; j<4;++j)
            p[i][j] = q[i][j];
     }
  if (c == 'd')
    {
    for (i = 0; i < 4; ++i)
        {
        q[0][i] = p[i][3];
        q[1][i] = p[i][2];
        q[2][i] = p[i][1];
        q[3][i] = p[i][0];
        }
    for (i = 0; i<4; ++i)
        for (j = 0; j<4; ++j)
      p[i][j] = q[i][j];
    }
}
void print(int a[][4])
{
 int i,j;
for (i = 0; i<4; ++i)
{
   for (j = 0; j<4; ++j)
printf("%-3d",a[i][j]);
printf("\n");
}
}
#endif
#if 0
void randominsert(int a[][4]);
void print(int a[][4]);
int main()
{
 int a[4][4] = {0};
 print(a);
 printf("\n"); 
 randominsert(a);
 print(a);
}
void randominsert(int a[][4])
{
 int number,n,*p;
 p = &a[0][0];
 srand((unsigned)time(NULL));
 number = (rand()%2+1)*2;
 n = rand()%16;
 while ( *(p+n) != 0)
  n =rand()%16;
 *(p+n) = number;
}
void print(int a[][4])
{
 int i,j;
for (i = 0; i<4; ++i)
{
   for (j = 0; j<4; ++j)
printf("%-3d",a[i][j]);
printf("\n");
}
}
#endif
#if 1
void moveup(int a[][4]);
void print(int a[][4]);
int main()
{
 int a[4][4] = {{2,2,2,2},{0,0,0,0},{2,2,2,2},{0}};
 print(a);
 printf("\n");
 moveup(a);
 print(a);
 return 0;
}
void moveup(int a[][4])
{
 int i,j,k;
 int n,tf;
 for (k = 0; k<4; ++k)
 {
  n=4;
  while (n--)
  for (i =0; i<3; ++i)
  {
   
  }
 } 
  
 
  
 
 
 
  


 
 



void print(int a[][4])
{
 int i,j;
for (i = 0; i<4; ++i)
{
   for (j = 0; j<4; ++j)
printf("%-3d",a[i][j]);
printf("\n");
}
}

#endif
