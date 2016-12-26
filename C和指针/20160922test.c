#if 0
/*
   首先读取一串列标号，这些列标号成对出现，表示输入行的列范围。这串列标号以一个负值作为结束标志。剩余的输入行被程序读入并打印，然后输入行中被选中范围的字符串被提取出来并打印。注意，每行第一列的列标号为。
 */
/*
 **这个程序从标准输入中读取输入行并在标准输出中打印这些输入行
 **每个输入行的后面一行是该行内容的一部分
 **输入的第一行是一串列标号，串的最后以一个负数结尾
 **这些列标号成对出现，说明需要打印的输入行的列的范围
 **例如 0 3 10 12 -1表示第列到第位列，第10列到第页中列的内容将被打印
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20    //能处理的最大列号
#define MAX_INPUT 1000 //每个输入行的最大长度
int read_column_numbers(int columns[],int max);
void rearrange(char *output,char const *input,int n_columns,int const columns[]);
int main(void)
{
	int n_columns; //进行处理的列标号
	int columns[MAX_INPUT]; //需要处理的列数
	char input[MAX_INPUT];//容纳输入行的数组
	char output[MAX_INPUT];//容纳输出行的数组
	//读取该出纳列标号
	n_columns = read_column_numbers(columns,MAX_COLS);//读取该串列标号
	//读取，处理和打印剩余的输入行
	while ( gets(input) != NULL )
	{
		printf("Original input:%s\n",input);
		rearrange(output,input,n_columns,columns);
		printf("Rearranged line:%s\n",output);
	}
	return EXIT_SUCCESS;
}
int read_column_numbers(int columns[],int max)
{
	int num = 0;
	int ch;
	//读取列标号，如果所读取的数小于0则停止。
	while(num < max && scanf("%d",&columns[num]) == 1 && columns[num] >= 0)
		num += 1;
	//确认已经读取的标号为偶数个，因为它们是以成对的形式出现的。
	if ( num % 2 != 0)
	{
		puts("Last column number is not paired.");
		exit(EXIT_FAILURE);
	}
	//丢弃该行中包含最后一个数字的那部分内容
	while ( (ch = getchar()) != EOF && ch != '\n')
		;
	return num;
}
//处理输入行，将制定列的字符连接在一起，输出行以NUL结尾
void rearrange(char *output,char const *input,int n_columns,int const columns[])
{
	int col;		//columns数组的下表
	int output_col;	//输出列计数器
	int len;	//输入行的长度

	len = strlen(input);
	output_col = 0;
	//处理没对列符号
	for(col = 0; col < n_columns; col += 2)
	{
		int nchars = columns[col + 1] - columns[col] + 1;

		//如果输入行或输出行数组已满，就结束任务;
		if (columns[col] >= len || output_col == MAX_INPUT - 1)
			break;
		//如果输出行数据空间不够，只复制可以容纳的数据
		if (output_col + nchars > MAX_INPUT - 1)
			nchars = MAX_INPUT - output_col - 1;
		//复制相关的数据
		strncpy(output + output_col,input + columns[col],nchars);
		output_col += nchars;
	}
	output[output_col] = '\0';
}
#endif
#include <stdio.h>
#if 0
int main()
{
 //printf("Delete file (are you really sure??):");
 //printf("\\");
 //printf("//");
 int a = 4,*p = NULL;
 p = &a;
 printf("%d\n",sizeof(p));
 printf("%d\n",sizeof(int));
 printf("%d\n",sizeof(long int));
 printf("%d\n",sizeof(short int));
 return 0;
}
#endif
#if 0
int main()
{
	typedef char *ptr_to_char;
	ptr_to_char a;
	a = "qwerrt";
	printf(a);
	printf("%d\n",sizeof(a));
	return 0;
}
#endif
#if 0
int main()
{
	int a[5] = {1,2,3,4,5};
	printf("%d\n",a[0]);
	printf("%d\n",0[a]);
	return 0;
}
#endif
#if 0
int main()
{
 int a = 5,b = 6;
 //int const *p = &a;
 int *const p = &a;
 ++*p;
 //p = &b;
 printf("%d\n",*p);
 return 0;
}
#endif
#if 0
int func(void);
int main()
{
	int answer;
	printf("%f\n",(float)(25/10));
    answer = func() - func() * func();
	printf("answer = %d\n",answer);
    return 0;
}
int func(void)
{ 
 static int counter = 1;
 return ++counter;
}
#endif
#if 0
int main()
{
	int array[5] = {1,2,3,4,5};
	int ARRAY_SIZE = 5;
	int i;
	int non_zero = 0;
	for(i = 0; i < ARRAY_SIZE; ++i)
		{
			non_zero += array[i];
		}
	if( !non_zero )
			printf("Values are all zero\n");
	else
			printf("Values are nonzero values\n");
	return 0;
}
#endif
#if 0
int main()
{
	int a = 5;//不能将指针指向为一个野指针，这样会出现堆内存错误的提示，结果非常危险。
	int *p = NULL;
	p = &a;
    printf("%d\n",*p);
	return 0;
}
#endif
#if 0
int main()
{
	int a;
	*&a = 25;//将25赋给变量a
	//*(int *)100 = 25; //非法，因为其地址并没有内存来存取，内存错误。
	return 0;
}
#endif
#if 0
int my_strlen(char *string);
int main()
{
	char a[10] = "qwerty";
	printf("%d\n",my_strlen(a));
	return 0;
}
int my_strlen(char *string)
{
	int length = 0;
	while( *string++ != '\0')
			length++;
	return length;
}
#endif

#if 0
/*
厄密多项式 
*/
int Hermite(int n,int x);
int main()
{
	printf("结果是:%d\n",Hermite(2,2));	
	return 0;
}
int Hermite(int n,int x)
{
	if( n <= 0 )
		return 1;
	else if( n == 1 )
		return 2*x;
	else if( n >= 2)
		return (2*x*Hermite(n-1,x)-2*(n-1)*Hermite(n-2,x));
}
#endif

#if 0
/*
求最大公约数
*/
int gcd(int m,int n);
int main()
{
    printf("最大公约数:%d\n",gcd(5,4));
	return 0;
}
int gcd(int m,int n)
{
	int r;
	if(m%n == 0)
		return n;
	else if( (r = m%n) > 0)
		gcd(n,r);
}
#endif

/*将字符转化为数字*/
#if 0
int ascii_to_integer( char *string );
int main()
{
	char str[10] = "12345";
	printf("转化后为:%d\n",ascii_to_integer(str));
	return 0;
}
int ascii_to_integer( char *string )
{
	int value = 0;
	while( *string >= '0' && *string <= '9')
			{
				value *= 10;
				value += *string - '0';
				string++;
			}
	if( *string != '\0')
			return 0;
	return value;
}
#endif

/*返回输入参数中的最大值*/
#if 0
#define MAXLEN 100
int max_list(int array[MAXLEN]);
int main()
{
	int array[MAXLEN];
	printf("最大的参数为:%d\n",max_list(array));
	return 0;
}
int max_list(int array[])
{
	int num = 0,max = 0,temp;
	while( num < MAXLEN && scanf("%d",&array[num]) == 1 && array[num] >= 0 )
			{
				if( max < array[num] )
						max = array[num];
				num++;
			}
	return max;
}
#endif

/* 写一个简化的 printf函数*/
#if 1
#include<stdarg.h>
void print(char *p);
int main()
{

	return 0;
}
void print(char *p)
{
	int i;
	float f;
	char *fm,*s;
	va_list ap;
	va_start(ap,p);
	for(fm = p; *fm; ++fm)
		{
			if(*fm != '%')
				continue;
			switch(*++fm)
			{
				case 'd':i = va_arg(ap,int);
						print_integer(i);break;
				case 'f':f = va_arg(ap,float);
						print_float(f);
				case 's':for(s = va_arg(ap,char*); *s; ++s)
							putchar(*s);
					putchar('');
					break;
			}
		}
		va_end;
}
#endif