#pragma once

#include"memory.h"
#include<assert.h>

template<class Type, class _A=my_allocator<Type> >
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
	//iterator it(_P);
	class iterator // : public const_iterator
	{
	public:
		iterator()
		{}
		iterator(_Nodeptr _P) : _Ptr(_P)
		{}
	public:
		reference operator*()const
		{return _Acc::_Value(_Ptr);}
		iterator& operator++()
		{
			_Ptr = _Acc::_Next(_Ptr);
			return *this;
		}
		iterator operator++(int)
		{
			iterator tmp = *this;
			++*this;
			return tmp;
		}
		iterator& operator--()
		{
			_Ptr = _Acc::_Prev(_Ptr);
			return *this;
		}
		iterator operator--(int)
		{
			iterator tmp = *this;
			--*this;
			return tmp;
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
	//const_iterator begin()const;
	//const_iterator end()const;
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
	void pop_back()
	{erase(--end());}
	void pop_front()
	{erase(begin());}
	reference back()
	{return *(--end());}
	reference back()const
	{return *(--end());}
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
		//_Acc::_Value(_S) = _X;
		allocator.construct(&_Acc::_Value(_S), _X);
		++_Size;
		return iterator(_S);
	}
	void insert(iterator _P, size_type _M, const Type &_X)
	{
		for(;_M>0; --_M)
			insert(_P,_X);
	}
	void insert(iterator _P, const Type *_F, const Type *_L)
	{
		for(;_F!=_L;++_F)
			insert(_P,*_F);
	}
	void insert(iterator _P, _It _F, _It _L)
	{
		for(;_F!=_L; ++_F)
			insert(_P,*_F);
	}
	//失效
	iterator erase(iterator _P)
	{
		_Nodeptr _S = (_P++)._Mynode();
		_Acc::_Next(_Acc::_Prev(_S)) = _Acc::_Next(_S);
		_Acc::_Prev(_Acc::_Next(_S)) = _Acc::_Prev(_S);
		allocator.destroy(&_Acc::_Value(_S));
		_Freenode(_S);
		//free(_S);
		--_Size;
		return _P;
	}
	iterator erase(iterator _F, iterator _L)
	{
		while(_F != _L)
		{
			erase(_F++);
		}
		return _F;
	}
	void clear()
	{
		erase(begin(), end());
	}

protected:
	_Nodeptr _Buynode(_Nodeptr _Narg=0, _Nodeptr _Parg=0)
	{
		//_Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));
		_Nodeptr _S = (_Nodeptr)allocator._Charalloc(sizeof(_Node));
		assert(_S != NULL);
		_Acc::_Next(_S) = _Narg!=0 ? _Narg : _S;
		_Acc::_Prev(_S) = _Parg!=0 ? _Parg : _S;
		return _S;
	}
	void _Freenode(_Nodeptr _S)
	{
		allocator.deallocate(_S, 1); 
	}
private:
	_Nodeptr  _Head;
	size_type _Size;
	_A        allocator;
};