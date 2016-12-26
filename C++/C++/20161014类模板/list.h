#pragma once
#include<stdlib.h>
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
	//ÝÍÈ¡¼¼Êõ
	typedef size_t        size_type;
	typedef Type          value_type;
	typedef Type&         reference;
	typedef const Type&   const_reference;
	typedef Type*         pointer;
	typedef const Type*   const_pointer;
public:
	list():_Head(_Buynode()),_Size(0)
	{}
public:
	void push_back(const Type &x)
	{
		_Nodeptr _S = _Buynode(_Head,_Acc::_Prev(_Head));
		assert(_S != NULL);
		_Acc::_Value(_S) = x;
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Acc::_Prev(_Head) = _S;
		_Size++;
	}
/*
	void push_back(const Type &x)
	{
		_Nodeptr _S = _Buynode(_Head,_Head->_Prev);
		assert(_S != NULL);
		_S->_Value = x;
		_S->_Prev->_Next = _S;
		_Head->_Prev = _S;
		_Size++;
	}
	
	void push_back(const Type &x)
	{
		_Nodeptr _S = _Buynode();
		assert(_S != NULL);
		_S->_Value = x;

		_S->_Next = _Head;
		_S->_Prev = _Head->_Prev;
		_S->_Prev->_Next = _S;
		_Head->_Prev = _S;
		_Size++;
	}
	*/
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
