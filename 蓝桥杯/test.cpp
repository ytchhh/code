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

#if 1
/*
	
*/
#include<iostream>
using namespace std;

int main()
{
	
	return 0;
}
#endif


