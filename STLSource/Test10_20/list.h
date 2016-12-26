#pragma once

#include<assert.h>

template<class Type>
class list
{
public:
	struct _Node;
	typedef struct _Node* _Nodeptr;
	struct _Node
	{
		_Nodeptr _Next;
		_Nodeptr _Prev;
		Type     _Value;
	};
	struct _Acc
	{
		typedef struct _Node*& _Nodepref;
		typedef Type&          _Vref;
		static _Nodepref _Next(_Nodeptr _P)
		{return((_Nodepref)(*_P)._Next);}
		static _Nodepref _Prev(_Nodeptr _P)
		{return((_Nodepref)(*_P)._Prev);}
		static _Vref _Value(_Nodeptr _P)
		{return ((_Vref)(*_P)._Value);}
	};
	//萃取技术
	typedef size_t        size_type;
	typedef Type          value_type;
	typedef Type&         reference;
	typedef const Type&   const_reference;
	typedef Type*         pointer;
	typedef const Type*   const_pointer;
public:
	class iterator
	{
	public:
		iterator()
		{}
		iterator(_Nodeptr _P) : _Ptr(_P)
		{}
	public:
		reference operator*()const
		{return _Acc::_Value(_Ptr);}
		iterator operator++()
		{
			_Ptr = _Acc::_Next(_Ptr);
			return *this;
		}
		bool operator==(const iterator &it)
		{return _Ptr==it._Ptr;}
		bool operator!=(const iterator &it)
		{return !(*this==it);}
		_Nodeptr _Mynode()const
		{return _Ptr;}
	protected:
		_Nodeptr _Ptr;
	};

	typedef iterator _It;
public:
	list():_Head(_Buynode()),_Size(0)
	{}
public:
	iterator begin()
	{
		return iterator(_Acc::_Next(_Head));
	}
	iterator end()
	{
		return iterator(_Head);
	}
public:
	/*
	void push_back(const Type &x)
	{
		_Nodeptr _S = _Buynode(_Head,_Acc::_Prev(_Head));
		assert(_S != NULL);
		_Acc::_Value(_S) = x;
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Acc::_Prev(_Head) = _S;
		_Size++;
	}
	*/
	void push_back(const Type &x)
	{insert(end(),x);}
	void push_front(const Type &x)
	{insert(begin(),x);}
	size_type size()const
	{return _Size;}
public:
	//迭代
	iterator insert(iterator _P, const Type &_X=Type())
	{
		_Nodeptr _S = _P._Mynode();
		_Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
		_S = _Acc::_Prev(_S);
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Acc::_Value(_S) = _X;
		++_Size;
		return iterator(_S);
	}
	void insert(iterator _P, size_type _M, const Type &_X);
	void insert(iterator _P, const Type *_F, const Type *_L);
	void insert(iterator _P, _It _F, _It _L);
	iterator earse(iterator _P);
protected:
	_Nodeptr _Buynode(_Nodeptr _Narg=0, _Nodeptr _Parg=0)
	{
		_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
		assert(_S != NULL);
		_Acc::_Next(_S) = _Narg!=0 ? _Narg : _S;
		_Acc::_Prev(_S) = _Parg!=0 ? _Parg : _S;
		return _S;
	}
private:
	_Nodeptr  _Head;
	size_type _Size;
};