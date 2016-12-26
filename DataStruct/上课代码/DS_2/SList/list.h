#ifndef _LIST_H
#define _LIST_H

#include"../utili.h"
#define ElemType int

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
		last->next = NULL;
		size = 0;
	}
	List(const List<Type> &lt)
	{}
	List<Type>& operator=(const List<Type> &lt)
	{}
	~List()
	{
		clear();
		free(first);
		first = last = NULL;
		size = 0;
	}
public:
	void push_back(Type &x)
	{
		ListNode<Type>*s = new ListNode<Type>(x);
		assert(s != NULL);
		last->next = s;
		last = s;
		size++;
	}
	void push_front(Type &x)
	{
		ListNode<Type> *s = new ListNode<Type>(x);
		assert(s != NULL);
		s->next = first->next;
		first->next = s;
		if(size == 0)
			last = s;
		size++;
	}
	void pop_back()
	{
		if(size == 0)
			return;
		ListNode<Type> *p = first;
		while(p->next != last)
			p = p->next;
		p->next = NULL;
		free(last);
		last = p;
		size--;
	}
	void pop_front()
	{
		if(size == 0)
			return;
		ListNode<Type> *p = first->next;
		first->next = p->next;
		free(p);
		size--;
	}
	void show_list()const
	{
		ListNode<Type> *p = first->next;
		while(p != NULL)
		{
			cout<<p->data<<"-->";
			p = p->next;
		}
		cout<<"Over."<<endl;
	}
	ListNode<Type>* find(const Type &key)
	{
		ListNode<Type> *p = first->next;
		while(p!=NULL && p->data!=key)
			p = p->next;
		return p;
	}
	Status erase(const Type &key)
	{
		ListNode<Type> *p = find(key);
		if(p == NULL)
			return FALSE;
		ListNode<Type> *q = first;
		while(q->next != p)
			q = q->next;

		if(p == last)
			last = q;
		q->next = p->next;
		free(p);
		size--;
		return TRUE;
	}
	Status insert(ListNode<Type> *s)
	{
		ListNode<Type> *p = first;
		while(p->next!=NULL && p->next->data < s->data)
			p = p->next;
		if(p->next == NULL)
			last = s;
		s->next = p->next;
		p->next = s;
		return TRUE;
	}
	Status insert(const Type &x)
	{
		ListNode<Type> *p = first;
		while(p->next!=NULL && p->next->data < x)
			p = p->next;
		ListNode<Type> *s = new ListNode<Type>(x);
		if(s == NULL)
			return FALSE;
		if(p->next == NULL)
			last = s;
		s->next = p->next;
		p->next = s;
		size++;
		return TRUE;
	}
	void clear()
	{
		if(size == 0)
			return;
		ListNode<Type> *p = first->next;
		while(p != NULL)
		{
			first->next = p->next;
			free(p);
			p = first->next;
		}
		size = 0;
	}
	void sort()
	{
		ListNode<Type> *p = first->next;
		ListNode<Type> *t = p->next;
		last = p;
		last->next = NULL;

		while(t != NULL)
		{
			p = t;
			t = p->next;
			insert(p);
		}
	}
	void resver()
	{}
private:
	ListNode<Type> *first;
	ListNode<Type> *last;
	size_t          size;
};

#endif