#pragma 

#include<assert.h>
#include<stdlib.h>
template<class Type>

class list
{
	public:
		struct _Node;
		typedef struct _Node* _Nodepter;
		struct _Node
		{
			_Nodepter _Next;
			_Nodepter _Prev;
			Type _Value;
		};
		struct _Acc
		{
			typedef _Nodepter&  _Nodepref;
			typedef Type&    _Vref;
			static _Nodepref _Next(_Nodepter _P)
			{
				return ((_Nodepref)(*_P)._Next);
			}
			static _Nodepref _Prev(_Nodepter _P)
			{
				return ((_Nodepref)(*_P)._Prev);
			}
			static _Vref _Value(_Nodepter _P)
			{
				return ((_Vref)(*_P)._Value);
			}
		};
		typedef size_t   size_type;
		typedef Type   Value_type;
		typedef Type&  reference;
		typedef const Type&  const_reference;
		typedef Type*   pointer;
		typedef const Type*  const_pointer;
	public:
		class iterator
		{
		public:
			iterator(){}
			iterator(_Nodepter _P):_Ptr(_P){}
			iterator operator++()
			{
				++(*this)._Value;
				return this;
			}
			bool operator==(const iterator & it)
			{
				return (_Ptr==it._Ptr);
			}
			bool operator!=(const iterator it)
			{
				return !((*this)==it);
			}

			_Nodepter MyNode()
			{return _Ptr;}
		private:
			_Nodepter _Ptr;
		};
		typedef iterator It;

	protected:

		_Nodepter _Buynode(_Nodepter _Narg=0,_Nodepter _Parg=0)
		{
			_Nodepter _S=(_Nodepter)malloc(sizeof(_Node));
			assert(NULL != _S);
			_Acc::_Next(_S) = (_Narg!=0)?_Narg:_S;
			_Acc::_Prev(_S) = (_Parg!=0)?_Parg:_S;
			return _S;
		}
	public:
		
		list():_Head(_Buynode()),_Size(0){}
		iterator insert(iterator _P,const Type& _X=Type())
		{
			_Nodepter _S=_P.MyNode();
			_Acc::_Prev(_S) = _Buynode(_S,_Acc::_Prev(_S));
			_Acc::_Value(_S) = _X;
			_Acc::_Prev(_Acc::_Next(_S)) = _S;

		}
		iterator begin()
		{return iterator(_Acc::_Next(_Head));}
		iterator insert(iterator _P,size_t _M,const Type& _X=Type())
		{}
		iterator insert(iterator _P,const Type* _F,const Type* _L)
		{}
		iterator insert(iterator _P,const iterator _F,const iterator _L)
		{}
	private:
		_Nodepter _Head;
		size_type _Size;
};


			

		



