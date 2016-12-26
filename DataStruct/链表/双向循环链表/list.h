#ifndef _LIST_H
#define _LIST_H

#include"utili.h"

typedef int ElemType;

template<class Type>
class List;

template<class Type>
class ListNode
{
	friend class List<Type>;
public:
	ListNode():prev(NULL),next(NULL),data(Type())
	{}
	ListNode(Type d,ListNode<Type> *p = NULL,ListNode<Type> *n = NULL):data(d),prev(p),next(n)
	{}
private:
	ListNode<Type> *prev;
	ListNode<Type> *next;
	Type		data;
};

template<class Type>
class List
{
public:
	List()
	{
		first = last = new ListNode<Type>;
		size = 0;
		first->prev = last;
		last->next = first;
	}
	~List()
	{
		
	}
public:
	bool Is_Empty()				//判断是否为空
	{
		if(first->next == first)
			return true;
		else
			return false;
	}
	void push_back(const ElemType &e)			//后插
	{
		ListNode<Type> *p = new ListNode<Type>(e);
		
		p->prev = last;
		p->next = first;
		last->next = p;
		first->prev = p;

		last = p;
		++size;
	}
	void show_list()				//打印函数
	{
		ListNode<Type> *p = first->next;
		while(p != first)
		{
			cout<<p->data<<"-->";
			p = p->next;
		}
		cout<<"Over!"<<endl;
	}
	void push_front(const ElemType &e)		//头插函数
	{
		ListNode<Type> *p = new ListNode<Type>(e);
		p->next = first->next;
		first->next->prev = p;
		first->next = p;
		p->prev = first;
		if(0 == size)
			last = p;
		++size;
	}
	ListNode<Type>* find(const ElemType &e)			//查找函数
	{
		ListNode<Type> *p = first->next;
		while(p != NULL && p->data != e)
		{
			p = p->next;
		}
		return p;
	}
	void pop_back()						//尾删
	{
		if(Is_Empty() == true)
			return;
		else
		{
			ListNode<Type> *p = last->prev;
			p->next = first;
			first->prev = p;
			delete last;
			last = p;
			--size;
		}
	}
	void pop_front()				//头删函数
	{
		if(Is_Empty() == true)
			return;
		else
		{
			ListNode<Type> *q,*p = first;
			q = p->next;
			p->next = q->next;
			q->next->prev = p;
			if(size == 1)
				last = first;
			--size;
		}
	}
	bool insert_val(const Type &x)		//按值插入
	{
		ListNode<Type> *q,*p = new ListNode<Type>(x);
		q = first->next;
		while(q != first && q->data > x)
			q = q->next;
		
		p->prev = q;
		p->next = q->next;
		q->next->prev = p;
		q->next = p;
		++size;

		return true;
	}
	bool delete_val(const Type &x)		//按值删除
	{
		if(Is_Empty() == true)
			return true;
		ListNode<Type> *t,*p = first->next;
		while(p->data != x && p != first)
			p = p->next;
		if(p == first)
			return false;
		else
		{
			if(p == last)
				pop_back();
			else if(p == first->next)
				pop_front();
			else
			{
				t = p->prev;
				t->next = p->next;
				p->next->prev = t;
				delete p;
				--size;
			}
			return true;
		}
	}
	void clear()					//清空函数
	{
		ListNode<Type> *p = first->next,*q;
		while(p != first)
		{
			q =  p->next;
			delete p;
			p = q;
		}
		first->next = first;
		first->prev = first;
		last = first;
		size = 0;
	}
	void insert(ListNode<Type> *p)
	{
		ListNode<Type> *t = first;
		while(t->next != first && t->next->data < p->data)
			t = t->next;
		if(t->next == first)
			last = p;
		else
			t->next->prev = p;
		p->next = t->next;
		t->next = p;
		p->prev = t;
	}
	void sort()				//排序函数
	{
		ListNode<Type> *p = first->next,*q = p->next;
		p->next = first;
		last = p;

		while(q != first)
		{
			p = q;
			q = p->next;
			insert(p);
		}
	}
	void reverse()				//转置函数
	{
		ListNode<Type> *p = first->next,*q = p->next;
		p->next = first;
		last = p;

		while(q != first)
		{
			p = q;
			q = p->next;
			push_front(p->data);
			delete p;
		}
	}
private:
	ListNode<Type> *first;
	ListNode<Type> *last;
	size_t		   size;
};

#endif
