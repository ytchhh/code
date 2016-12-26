#pragma once

#include"../utili.h"

template<class Type>
class ListNode
{
public:
	ListNode():data(Type()),prev(NULL),next(NULL)
	{}
	ListNode(Type d, ListNode<Type>*p=NULL,ListNode<Type>*n=NULL)
		:data(d),prev(p),next(n)
	{}
	~ListNode()
	{}
private:
	Type data;
	ListNode<Type> *prev;
	ListNode<Type> *next;
};
template<class Type>
class List
{
public:
	List()
	{
		first = last = new ListNode<Type>;
		first->prev = NULL;
		last->next = NULL;
		size = 0;
	}
public:
	void push_back(const Type &x);
	void push_front(const Type &x);
	Status insert(ListNode<Type> *p, const Type &x);
	ListNode<Type>* find(const Type &key);
	void sort();
	void resver();
private:
	ListNode<Type> *first;
	ListNode<Type> *last;
	size_t          size;
};

