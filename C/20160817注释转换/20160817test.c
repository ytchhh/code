#if 1 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void fun1(char **p1,char **p2)
{
 *(*p2)++ = '*';
 
 while (**p1 != '\n'|| **p1 == EOF)
 { 
  if (**p1 == '/' && *((*p1)+1) == '/' )
  {
  *(*p2)++ = ' ';
  *(*p2)++ = ' ';
  (*p1)++;
  (*p1)++;
  }
  else if (**p1 == '/' && *((*p1)+1) == '*')
  {
  *(*p2)++ = ' ';
  *(*p2)++ = ' ';
  (*p1)++;
  (*p1)++;
  }
  else if (**p1 == '*' && *((*p1)+1) == '/')
   { 
   *(*p2)++ = ' ';
   *(*p2)++ = ' ';
   (*p1)++;
   (*p1)++;
  }
 else
 *(*p2)++ = *(*p1)++; 
}  
 *(*p2)++ = '*';
 *(*p2)++ = '/';
 *(*p2)++ = '\n';
if (**p1 == '\n')
 (*p1)++;
}
int main()
{
 char a[100] = "12314//ewiurw/*djf*/ish//ei\nuuuuusa//";
 char b[100] = {0};
 char *p1 = NULL,*p2 = NULL;
 p1 = a;
 p2 = b;
 fun1(&p1,&p2);
 puts(a);
 puts(b); 
 return 0;
}
#endif
#if 0
void  fun3(char **p1,char **p2);
void  space(char **p1,char **p2);
int main()
{
	char *p1= {"1234567//sed/*frt//gyh*/"};
	char b[100]={0},*p2;
        p2 = b;
	puts(p1);
	fun3(&p1,&p2);
	puts(b);

}
void space(char **p1,char **p2)
{
		if ((**p1) == '/')
			{
				if( *((*p1)+1) == '/')
					{
					*(*p2)++ = ' ';
					*(*p2)++ = ' ';
					}
				if( *((*p1)+1) == '*')
					{ 
					*(*p2)++ = ' ';
					*(*p2)++ = ' ';
					}	
			}	
}
void fun3(char **p1,char **p2)
{
	for(; **p1 != '*' || *((*p1)+1) != '/'; (*p1)++)
	{
		if(**p1 == '/')
		{
			space(p1,p2);
			(*p1)++;
		}
	    else
        {
			**p2 = **p1;  
			(*p2)++;
		}
	}
 (*p1)++;
 (*p1)++;
}
#endif


























