#include<iostream>
#include"list.h"
using namespace std;

void main()
{
	list<int> mylist;
	mylist.push_front(1);
	mylist.pop_back();
}

/*
void main()
{
	list<int> mylist;
	mylist.push_front(1);
	mylist.push_front(2);
	mylist.push_front(3);
	mylist.push_front(4);
	mylist.push_front(5);

	list<int>::iterator t;
	list<int>::iterator p = mylist.begin();
	++p;
	++p;
	t = mylist.insert(p);
	cout<<"*t="<<*t<<endl;

	//vector<int>::iterator it;
	list<int>::iterator it;
	it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<"-->";
		++it;
	}
	cout<<"Over."<<endl;

	cout<<"Size = "<<mylist.size()<<endl;

}
*/