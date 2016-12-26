#ifndef _LIST_H
#define _LIST_H

#include<iostream>
using namespace std;

template<class Type>
class List;

template<class Type>
class ListNode
{
	friend class List<Type>;
public:
	ListNode():data(Type()),next(NULL)
	{}
	ListNode(Type d, ListNode<Type> *n=NULL) 
		: data(d),next(n)
	{}
	~ListNode()
	{}
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
		size = 0;
	}
public:
	void push_back(const Type &x);
	void push_front(Type &x);
	void show_list();
	void pop_back();
	void pop_front();
	bool insert(const Type &x); // -->
	ListNode<Type>* find(const Type &key);
	bool erase(const Type &key);
	void sort();
	void resver();
private:
	ListNode<Type> *first;
	ListNode<Type> *last;
	size_t          size;
};

////////////////////////////////////////////////////
template<class Type>
void List<Type>::push_back(const Type &x)
{
	ListNode<Type> *s = new ListNode<Type>(x);
	last->next = s;
	last = s;
	size++;
}
template<class Type>
void List<Type>::show_list()
{
	ListNode<Type> *p = first->next;
	while(p != NULL)
	{
		cout<<p->data<<"-->";
		p = p->next;
	}
	cout<<"Over."<<endl;
}
template<class Type>
bool List<Type>::insert(const Type &x)
{
	if(size == 0)
	{
		push_back(x);
		return true;
	}
	ListNode<Type> *p = first;
	while(p->next!=NULL && p->next->data < x)
	{
		p = p->next;
	}
	if(p->next == NULL)
	{
		push_back(x);
		return true;
	}

	ListNode<Type> *s = new ListNode<Type>(x);
	if(s == NULL)
		return false;
	s->next = p->next;
	p->next = s;
	size++;
	return true;
}

template<class Type>
ListNode<Type>* List<Type>::find(const Type &key)
{
	ListNode<Type> *p = first->next;
	while(p!=NULL && p->data!=key)
		p = p->next;
	return p;
}
#endif
