#include<iostream>
//#include<list>
#include"list.h"
using namespace std;
int main()
{
    /*
    list<int> mylist;
    mylist.push_front(1);
    mylist.push_front(2);
    mylist.push_front(3);
    mylist.push_front(4);
    mylist.push_front(5);

    list<int>::iterator t;
    list<int>::iterator p = mylist.begin();
    ++p;
    t = mylist.insert(p);
    cout<<"*t = "<<*t<<endl;

    list<int>::iterator it;
    it = mylist.begin();
    while(it != mylist.end())
        {
            cout<<*it<<"-->";
            ++it;
        }
    cout<<"Over."<<endl;
    
    cout<<"Size = "<<mylist.size()<<endl;
    
    */
	/*
    list<int> mylist;
    mylist.push_front(1);
    mylist.push_front(2);
    mylist.push_front(3);
    mylist.push_front(4);

    list<int>::iterator t;
    list<int>::iterator p = mylist.begin();
    ++p;
    ++p;
    //mylist.insert(p,3,5);
    
    int a[5] = {1,2,3,4,5};
    mylist.insert(p,a,a+2);
	*/
    /*
    list<int>::iterator m;
    list<int>::iterator n;
    list<int> mylist1;
    mylist.push_front(5);
    mylist.push_front(6);
    mylist.push_front(7);
    mylist.push_front(8);
    m = n = mylist1.begin();
    ++n;
    ++n;
    ++n;
    mylist.insert3(p,m,n);
    */

    /*
    list<int>::iterator it;
    it = mylist.begin();
    while(it != mylist.end())
        {
            cout<<*it<<"-->";
            ++it;
        }
    cout<<"Over."<<endl;
    mylist.earse(p);
    */
    /*
    list<int>::iterator it;
    it = mylist.begin();
    
    while(it != mylist.end())
        {
            cout<<*it<<"-->";
            ++it;
        }
    cout<<"Over."<<endl;
    
    mylist.clear();
    it = mylist.begin();
    
    while(it != mylist.end())
        {
            cout<<*it<<"-->";
            ++it;
        }
    cout<<"Over."<<endl;
    */
    
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);
	list<int>::iterator p;
	p = mylist.begin();
	++p;
	++p;
	list<int> mylist1;
	mylist1.push_back(5);
	mylist1.push_back(6);
	mylist1.push_back(7);
	mylist1.push_back(8);
	mylist.splice(p,mylist1);
	list<int>::iterator it;
	it = mylist.begin();
	while(it != mylist.end())
		{
			cout<<*it<<"-->";
			++it;
		}
	cout<<endl;

    cout<<__DATE__<<endl;
    cout<<__TIME__<<endl;
    return 0;
}
