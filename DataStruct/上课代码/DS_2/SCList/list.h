#ifndef _LIST_H
#define _LIST_H
#include"../utili.h"
template<class Type>
class List;

template<class Type>
class ListNode
{
	friend class List<Type>;
public:
	ListNode():data(Type()),next(NULL)
	{}
	ListNode(Type d, ListNode<Type>*n=NULL)
		:data(d),next(n)
	{}
	~ListNode()
	{}
public:
	Type& GetData()
	{return data;}
	const Type& GetData()const
	{return data;}
	ListNode<Type>* GetNext()const
	{return next;}
	void SetData(Type &d)
	{data = d;}
private:
	Type data;
	ListNode<Type> *next;
};

template<class Type>
class List
{
public:
	List()
	{
		first = last = new ListNode<Type>;
		last->next = first;
		size = 0;
	}
private:
	ListNode<Type> *first;
	ListNode<Type> *last;
	size_t          size;
};
#endif