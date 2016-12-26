#include<iostream>
#include<list>
#include<vector>
#include<deque>
#include<string>
#include<stack>
#include<queue>
#include<bitset>
#include<map>
#include<set>
using namespace std;

void main()
{
	map<int,int> mp;
	set<int> se;
 	string s;
	bitset<100> bt;
	stack<int> st;
	queue<int> qe;
	deque<int> dq;
	vector<int> v;
	list<int> mylist;
}

/*
class Test
{
public:
	Test(int d = 0)
	{}
};

void main()
{
	Test t;
	t = Test(10);
}

/*
struct Test
{
	int a; // 4+4
	struct iterator
	{
		int c;
		struct tt
		{
			int x;
			int y;
		};
		int e;
	};
	double d;
};

void main()
{
	Test t;
	t.a = 10;
	t.d = 12.34;
	
	Test::iterator::tt it;
	it.
}

/*
void main()
{
	int a = int();
	double d = double();
	char ch = char();
}

/*
class Test
{
public:
	Test(int d = 0) : data(d)
	{
		cout<<"Create Test Object : "<<this<<endl;
	}
	Test(const Test &t)
	{
		cout<<"Copy Create Test Object : "<<this<<endl;
		data = t.data;
	}
	Test& operator=(const Test &t)
	{
		cout<<"Assign:"<<this<<" = "<<&t<<endl;
		if(this != &t)
		{
			data = t.data;
		}
		return *this;
	}
	~Test()
	{
		cout<<"Free Test Object :"<<this<<endl;
	}
public:
	Test* operator&()
	{
		return this;
	}
	const Test* operator&()const
	{
		return this;
	}
private:
	int data;
};

void main()
{
	const Test t1(100);
	const Test *pt = &t1;
}

/*
void main()
{
	Test t1(100);
	Test t2;
	Test t3;
	//t3.operator=();
	t2 = t1;
}

/*
class Test;
ostream& operator<<(ostream &out, const Test &t);
class Test
{
	friend ostream& operator<<(ostream &out, const Test &t);
public:
	Test(int d = 0) : data(d)
	{}
	Test& operator=(const Test &t)
	{}
	~Test()
	{}
public:
	//t1 > t2; //
	bool operator>(const Test &t)
	{return data > t.data;} 
	//t1 <= t2;
	//t1.operator<=(t2);
	bool operator<=(const Test &t)
	{return !(*this>t);}
private:
	int data;
};
template<class Type>
Type Max(Type a, Type b)
{
	return a > b ? a : b;
}
ostream& operator<<(ostream &out, const Test &t)
{
	out<<t.data;
	//return out;
}

void main()
{
	Test t1(10); //data=10
	Test t2(20); //data=20
	cout<<Max(t1,t2)<<endl;
}

/*
template<class Type, class Type1, class Type2>
Type Max(Type1 a, Type2 b)
{
	return a > b ? a : b;
}

void main()
{
	cout<<Max<int,int,double>(1,2.1)<<endl;
}

/*
void main()
{
	cout<<Max(1,2)<<endl;
	cout<<Max('A','X')<<endl;
	cout<<Max(1.2,2.3)<<endl;
	cout<<Max(1.2f,2.3f)<<endl;
}

/*
void main()
{
	map<int,int> mp;
	set<int> se;
 	string s;
	bitset<100> bt;
	stack<int> st;
	queue<int> qe;
	deque<int> dq;
	vector<int> v;
	list<int> mylist;
}
*/