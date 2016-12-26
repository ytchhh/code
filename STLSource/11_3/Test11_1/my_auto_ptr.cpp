// 这一个测试
#include <iostream>

using namespace std;

template <class _Ty> 
class auto_ptr
{
private :	
	mutable bool _Owns;
	mutable _Ty  *_Ptr;

public :
	auto_ptr(_Ty *_P = 0) : _Owns(_P != 0), _Ptr(_P){}
	auto_ptr(const auto_ptr<_Ty>& _Y);
	auto_ptr<_Ty>& operator=(const auto_ptr<_Ty>& _Y);
	~auto_ptr();
	_Ty operator*() const;
	_Ty * operator->() const;
	_Ty * get() const;
	_Ty * release() const;
};

template <class _Ty>
_Ty* auto_ptr<_Ty> :: get() const
{return _Ptr;}
template <class _Ty>
_Ty auto_ptr<_Ty> :: operator*() const
{return *get();}
template <class _Ty>
_Ty* auto_ptr<_Ty> :: operator->() const
{return get();}
template <class _Ty>
auto_ptr<_Ty> :: ~auto_ptr()
{
	if(_Owns)
		delete _Ptr;
}
template <class _Ty>
_Ty* auto_ptr<_Ty> :: release() const
{
	_Owns = 0;
	_Ty * temp = _Ptr;
	_Ptr = NULL;	
	return temp;
}
template <class _Ty>
auto_ptr<_Ty> :: auto_ptr(const auto_ptr<_Ty>& _Y)
{
	_Ptr = _Y._Ptr;
	_Owns = 1;
	_Y.release();
}
template <class _Ty>
auto_ptr<_Ty>& auto_ptr<_Ty> :: operator=(const auto_ptr<_Ty>& _Y)
{
	if(this != &_Y)
	{
		if(_Ptr != _Y.get())	
		{
			if(_Owns)	
				delete _Ptr;
			_Owns = _Y._Owns;
		}
		else if(_Y._Owns)
			_Owns = true;
		_Ptr = _Y.release();
	}
	return (*this);
}

int main()
{
	int *p = new int(19);
	auto_ptr<int> ap(p);
	auto_ptr<int> ap2;
	cout << *ap << endl;
	ap2 = ap;
	if(ap2.get() == NULL)
		cout << "ap2 == NULL" << endl;
	else 
		cout << *ap2 << endl;
	return 0;
}
