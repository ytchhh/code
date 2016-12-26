#include<iostream>
//#include<memory>
#include<vld.h>
using namespace std;

class Test
{
public:
	void fun()const
	{
		cout<<"This is Test::fun()"<<endl;
	}
};

template<class _Ty>
class auto_ptr
{
public:
	auto_ptr(_Ty *_P=0) : _Owns(_P!=0), _Ptr(_P)
	{}
	//auto_ptr(const auto_ptr<_Ty> &_Y):_Owns(_Y._Owns),_Ptr(_Y.release())
	auto_ptr(auto_ptr<_Ty> &_Y):_Owns(_Y._Owns),_Ptr(_Y.release())
	{}
	auto_ptr<_Ty>& operator=(const auto_ptr<_Ty> &_Y)
	{
		if(this != &_Y)
		{
			//
		}
		return *this;
	}
	~auto_ptr()
	{
		if(_Owns)
			delete _Ptr;
	}
public:
	_Ty& operator*()const
	{return (*get());}
	_Ty* operator->()const
	{return get();}
	_Ty* get()const
	{return _Ptr;}
	_Ty* release()
	{
		_Owns = false;
		return _Ptr;
	}
private:
	bool _Owns;
	_Ty  *_Ptr;
};

void main()
{
	int *p = new int(10);
	auto_ptr<int> pa(p); //pa.reset(p1);
	auto_ptr<int> pa1(pa);
	cout<<*pa<<endl;
	//a1 = pa;
}

/*
void main()
{
	int *p = new int(10);
	auto_ptr<int> pa(p);
	cout<<*pa<<endl;

	Test *pt = new Test;
	auto_ptr<Test> pa1(pt);
	pa1->fun();
}
	

/*
class Test
{
public:
	void fun()const
	{
		cout<<"This is Test::fun()"<<endl;
	}
};

void main()
{
	int *p = new int(10); //new int[10]; *p
	auto_ptr<int> pa(p);
	cout<<*pa<<endl;

	Test *pt = new Test;
	auto_ptr<Test> pa1(pt);
	pa1->fun();
}

/*


void fun()
{
	int *p = new int;
	return p;
}

void main()
{
	int *p = fun();
	delete p;
}

/*
//智能  指针
//代理
void main()
{
	int *p = new int(10); //new int[10]; *p
	auto_ptr<int> pa(p);
	cout<<*pa<<endl;

	Test *pt = new Test;
	auto_ptr<Test> pa1(pt);
	pa1->fun();
}
*/