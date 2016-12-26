#include<iostream>
//#include<memory>
#include<boost/smart_ptr.hpp>
#include<vld.h>
using namespace std;
using namespace boost;

class Test
{
public:
	void fun()
	{
		cout<<"This is Test::fun()."<<endl;
	}
};


void main()
{
	int *p = new int(10);
	shared_ptr<int> sp(p);
	cout<<*sp<<endl;

	shared_ptr<int> sp1 = sp;
	cout<<*sp1<<endl;

	shared_ptr<int> sp2;
	sp2 = sp1;
	cout<<*sp2<<endl;
}
/*
void main()
{
	int *p = new int(10);
	shared_ptr<int> sp(p);
	cout<<*sp<<endl;

	Test *pt = new Test;
	shared_ptr<Test> sp1(pt);
	sp1->fun();
}

/*
void main()
{
	int *p = new int[10];
	scoped_array<int> sa(p);
	
	for(int i=1; i<=10; ++i)
	{
		sa[i-1] = i;
	}
	for(i=0; i<10; ++i)
	{
		cout<<sa[i]<<" ";
	}
	cout<<endl;
}


/*
template<class T> 
class scoped_ptr
{
	scoped_ptr(const scoped_ptr<T> &);
	scoped_ptr<T>& operator=(const scoped_ptr<T> &);
public:
	scoped_ptr( T * p = 0 ): px( p )
    {}
	~scoped_ptr() // never throws
    {
		delete px; //delete []px;
    }
	T & operator*() const 
    {
        return *px;
    }
    T * operator->() const 
    {
        return px;
    }
    T * get() const 
    {
        return px;
    }

	typedef scoped_ptr<T> this_type;
	void reset(T * p = 0) 
    {
        this_type(p).swap(*this);
    }
	void swap(scoped_ptr & b) //靠靠靠縮coped_ptr<T> &
    {
        T * tmp = b.px;
        b.px = px;
        px = tmp;
    }
private:
	T * px;
};
void main()
{
	int *p = new int[10]
	int *q = new int(100);
	scoped_ptr<int> sp(p);
	cout<<*sp<<endl;
	sp.reset(q);
	cout<<*sp<<endl;
	//cout<<*sp<<endl;
}

/*
class String
{
public:
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			delete []data;
			data = new char[strlen(s.data)+1];
			strcpy(data, s.data);
		}
		return *this;
	}
private:
	char *data;
};

/*
void main()
{
	
	while(1)
	{
		int *p = new int(10);
	}
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

template<class _Ty>
class auto_ptr
{
public:
	auto_ptr(_Ty *_P=0) : _Owns(_P!=0), _Ptr(_P)
	{}
	auto_ptr(const auto_ptr<_Ty> &_Y):_Owns(_Y._Owns),_Ptr(_Y.release())
	//auto_ptr(auto_ptr<_Ty> &_Y):_Owns(_Y._Owns),_Ptr(_Y.release())
	{}
	//pa1 = pa; //pa1.operator=(pa);
	auto_ptr<_Ty>& operator=(const auto_ptr<_Ty> &_Y)
	{
		if (this != &_Y)
		{
			if (_Ptr != _Y.get())
			{
				if (_Owns)
					delete _Ptr;
				_Owns = _Y._Owns; 
			}
			else if (_Y._Owns)
				_Owns = true;
			_Ptr = _Y.release(); 
		}
		return (*this);
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
	//_Ty* release(const auto_ptr<_Ty> * const this)
	_Ty* release()const
	{
		((auto_ptr<_Ty>*const)this)->_Owns = false;
		//_Owns = false;

		//_Ty *_P = _Ptr;
		//((auto_ptr<_Ty>*const)this)->_Ptr = NULL;
		return _Ptr;
	}
private:
	//mutable bool _Owns;
	bool _Owns;
	_Ty  *_Ptr;
};

void main()
{
	int *p = new int[10];
	auto_ptr<int> pa(p); //pa[0]
}

/*
void main()
{
	int *p = new int(10);
	auto_ptr<int> pa(p); //pa.reset(p1);
	auto_ptr<int> pa1;
	pa1 = pa;
	cout<<*pa1<<endl;
	//a1 = pa;
}


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
