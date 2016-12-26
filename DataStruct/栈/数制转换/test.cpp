#include<iostream>
#include<stack>
using namespace std;


void Conversion();		//十进制转化为八进制
int main()
{
	
	return 0;
}

void Conversion()
{
	stack<int> s;
	int n;
	cin>>n;
	while(n)
	{
		s.push(n%8);
		n = n/8;
	}
	while(!s.empty())
	{
		s.pop();
	}
}
