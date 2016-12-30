#if 0
/*
	输入格式
		输入包含一个非负整数a，表示要转换的数。0<=a<=2147483647
	输出格式
	　　输出这个整数的16进制表示
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	long int n;
	int i = 0,a[8] = {0},j = 0;
	string str;
	char b;
	cin>>n;

	if(n)
	{
	    while(n)
	    {
		    a[i++] = n%16;
		    n = n/16;
	    }

	    while(i)
	    {
		    --i;
		    switch(a[i])
		    {
			    case 10:b = 'A';break;
			    case 11:b = 'B';break;
			    case 12:b = 'C';break;
			    case 13:b = 'D';break;
			    case 14:b = 'E';break;
			    case 15:b = 'F';break;
		    }
		    if(a[i] >= 0 && a[i] <= 9)
		    {
			    b = a[i] + '0';
		    }
		    str[j++] = b;
	    }
	    for(i = 0; i < j; ++i)
		    cout<<str[i];
	    cout<<endl;
	}
	else
		cout<<n<<endl;
	return 0;
}
#endif

#if 0
/*
	 问题描述

	 给出一个包含n个整数的数列，问整数a在数列中的第一次出现是第几个。
	 输入格式

	 第一行包含一个整数n。

	 第二行包含n个非负整数，为给定的数列，数列中的每个数都不大于10000。

	 第三行包含一个整数a，为待查找的数。
	 输出格式
	 如果a在数列中出现了，输出它第一次出现的位置(位置从1开始编号)，否则输出-1。 
*/

#include<iostream>
using namespace std;

int main()
{
	int n,i,key;
	cin>>n;

	int a[n];
	for(i = 0; i < n; ++i)
		cin>>a[i];
	
	cin>>key;
	for(i = 0; i < n; ++i)
		if(a[i] == key)
			break;
	if(i != n)
		cout<<++i;
	else
		cout<<-1;
	cout<<endl;
	return 0;
}
#endif

#if 0
/*
	问题描述
	给出n个数，找出这n个数的最大值，最小值，和。
	输入格式
	第一行为整数n，表示数的个数。
	第二行有n个数，为给定的n个数，每个数的绝对值都小于10000。
	输出格式
	输出三行，每行一个整数。第一行表示这些数中的最大值，第二行表示这些数中的最小值，第三行表示这些数的和。
*/

#include<iostream>
using namespace std;

int main()
{
	int n,sum,min,max,i,j;
	cin>>n;

	int a[n];
	for(i = 0; i < n; ++i)
		cin>>a[i];
	sum = max = min = a[0];

	for(i = 1; i < n; ++i)
	{
		if(a[i] > max)
			max = a[i];
		else
			min = a[i];
		sum += a[i];
	}
	cout<<max<<endl;
	cout<<min<<endl;
	cout<<sum<<endl;
	return 0;
}
#endif

#if 0
/*
	问题描述

	利用字母可以组成一些美丽的图形，下面给出了一个例子：

	ABCDEFG

	BABCDEF

	CBABCDE

	DCBABCD

	EDCBABC

	这是一个5行7列的图形，请找出这个图形的规律，并输出一个n行m列的图形。
	输入格式
	输入一行，包含两个整数n和m，分别表示你要输出的图形的行数的列数。
	输出格式
	输出n行，每个m个字符，为你的图形。
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int m,n,i,j,k;
	char a;
	string str;
	
	cin>>n>>m;
	
	char arr[n][m];
	for(i = 0; i < n; ++i)
	{
		a = 'A';
		for(j = i; j < m; ++j)
			arr[i][j] = a++;
		a = 'A';
		for(k = i; k > 0; )
			arr[i][--k] = ++a;
	}
	for(i = 0; i < n; ++i)
	{	
		for(j = 0; j < m; ++j)		
			cout<<arr[i][j];
		cout<<endl;
	}	
	return 0;
}
#endif

#if 0
/*
	 问题描述

	 对于长度为5位的一个01串，每一位都可能是0或1，一共有32种可能。它们的前几个是：

	 00000

	 00001

	 00010

	 00011

	 00100

	 请按从小到大的顺序输出这32种01串。
	 输入格式
	 本试题没有输入。
	 输出格式
	 输出32行，按从小到大的顺序每行一个长度为5的01串。 
*/

#include<iostream>
using namespace std;

int main()
{
	for(int i = 0; i <= 31; ++i)
	{
		int a[5] = {0};
		int num = i;
		int z = 0;
		while(num != 0)
		{
			a[z] = num%2;
			++z;
			num/=2;
		}
		for(int j = 4; j >= 0; --j)
			cout<<a[j];
		cout<<endl;
	}
	return 0;
}
#endif

#if 0
/*
	 问题描述

	 给定一个年份，判断这一年是不是闰年。

	 当以下情况之一满足时，这一年是闰年：

	 1. 年份是4的倍数而不是100的倍数；

	 2. 年份是400的倍数。

	 其他的年份都不是闰年。
	 输入格式
	 输入包含一个整数y，表示当前的年份。
	 输出格式
	 输出一行，如果给定的年份是闰年，则输出yes，否则输出no。

	 说明：当试题指定你输出一个字符串作为结果（比如本题的yes或者no，你需要严格按照试题中给定的大小写，写错大小写将不得分。

*/

#include<iostream>
using namespace std;

int main()
{
	int year;
	cin>>year;

	if((year%4 == 0 && year%100 != 0) || year%400 == 0)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}

#endif

#if 0
/*
	 问题描述

	 给定一个序列，每次询问序列中第l个数到第r个数中第K大的数是哪个。
	 输入格式

	 第一行包含一个数n，表示序列长度。

	 第二行包含n个正整数，表示给定的序列。

	 第三个包含一个正整数m，表示询问个数。

	 接下来m行，每行三个数l,r,K，表示询问序列从左往右第l个数到第r个数中，从大往小第K大的数是哪个。序列元素从1开始标号。
	 输出格式
	 总共输出m行，每行一个数，表示询问的答案。 
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

int cmp(const void *a,const void *b)
{
	return *(int*)b - *(int*)a;
}
int main()
{
	int n;
	int m;
	cin>>n;

	int a[n],b[3];
	for(int i = 0; i < n; ++i)
		cin>>a[i];
	cin>>m;
	int c[m],l = 0;
	

	for(int i = 0; i < m; ++i)
	{
		cin>>b[0]>>b[1]>>b[2];
		int d[b[1]-b[0]+1];
		int k = 0;
		for(int j = b[0]-1; j < b[1]; ++j)
			d[k++] = a[j];
		qsort(d,b[1]-b[0]+1,sizeof(int),cmp);
		c[l++] = d[b[2]-1];
	}
	
	for(int i = 0; i < l; ++i)
		cout<<c[i]<<endl;
	return 0;
}
#endif

#if 1
/*
	问题描述

	已知一个正整数N，问从1~N中任选出三个数，他们的最小公倍数最大可以为多少。
	输入格式

	输入一个正整数N。
	输出格式
	输出一个整数，表示你找到的最小公倍数。
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	unsigned long long int ans;
	cin>>n;

	if(n <= 2)
		ans = n;
	else if(n%2)
		ans = n*(n-1)*(n-2);
	else
	{
		if(n%3)
			ans = n*(n-1)*(n-3);
		else
			ans = (n-1)*(n-2)*(n-3);
	}
	cout<<ans<<endl;
	return 0;
}
#endif
