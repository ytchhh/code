#include<iostream>
#include<memory>
using namespace std;

void main()
{
	int *p = new int(10);
	int *q = new int(20);
	auto_ptr<int> pa(p);
	auto_ptr<int> pa1(q);
}

/*
template<class _Ty>
class auto_ptr
{
public:
	auto_ptr(_Ty *_Ptr = 0):_Myptr(_Ptr)
	{}
	auto_ptr(auto_ptr<_Ty>& _Right) 
		: _Myptr(_Right.release())
		{}
	auto_ptr<_Ty>& operator=(auto_ptr<_Ty>& _Right)
	{	
		reset(_Right.release());
		return (*this);
	}
	~auto_ptr()
	{
		if (_Myptr != 0)
			delete _Myptr;
	}
public:
	_Ty& operator*() const
	{
		return (*get());
	}
	_Ty *operator->() const 
	{
		return (get());
	}
	_Ty *get() const
	{
		return (_Myptr);
	}
	_Ty *release()
	{	
		_Ty *_Tmp = _Myptr;
		_Myptr = 0;
		return (_Tmp);
	}
	void reset(_Ty* _Ptr = 0)
	{
		if (_Ptr != _Myptr && _Myptr != 0)
			delete _Myptr;
		_Myptr = _Ptr;
	}
private:
	_Ty *_Myptr;
};

void main()
{
	int *p = new int(10);
	int *q = new int(20);
	auto_ptr<int> pa(p);
	auto_ptr<int> pa1(q);

	pa1 = pa;

}
*/

