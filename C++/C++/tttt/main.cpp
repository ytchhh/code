#include<iostream>
#include"list.h"
using namespace std;

int main()
{
	list<int> a;
	list<int>::iterator p;
	p = a.begin();
		
	a.insert(p,22);
	return 0;	
}

