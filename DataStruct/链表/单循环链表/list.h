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
	ListNode():data(Type()),next(NULL)
	{}
	ListNode(const Type d,ListNode<Type> *n = NULL):data(d),next(n)
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
		last->next = first;
		size = 0;
	}
	~List()
	{
		
	}
public:
	void push_back(const Type &x)			//后插函数
	{
		ListNode<Type> *s = new ListNode<Type>(x);
		last->next = s;
		s->next = first;

		last = s;
		++size;
	}
	void push_front(const Type &x)			//前插函数
	{
		ListNode<Type> *s = new ListNode<Type>(x);
		s->next = first->next;
		first->next = s;
		if(size == 0)
			last = s;
		++size;
	}
	void show_list()						//打印函数
	{
		ListNode<Type> *s = first->next;
		while(s != first)
		{
			cout<<s->data<<"-->";
			s = s->next;
		}
		cout<<"Over!"<<endl;
	}
	bool Is_Empty()							//判空
	{
		if(first->next == first)
			return true;
		else
			return false;
	}
	
	bool pop_bacK()							//尾删函数
	{
		if(Is_Empty() == true)
			return false;
		ListNode<Type> *p = first;
		while(p->next != last)
			p = p->next;
		p->next = first;
		delete last;
		last = p;
		--size;
		return true;
	}
	bool pop_front()						//头删函数
	{
		if(Is_Empty() == true)
			return false;
		ListNode<Type> *p = first->next;
		first->next = p->next;
		delete p;
		if(p == last)
			last = first;
		--size;
		return true;
	}
	bool insert(const Type &x)				//按值插入
	{
		ListNode<Type> *p = first;
		while(p->next != first && p->next->data <x)
			p = p->next;
		ListNode<Type> *s = new ListNode<Type>(x);
		if(s == NULL)
			return false;
		if(p->next == first)
			last = s;
		s->next = p->next;
		p->next = s;
		++size;
		return true;
	}
	ListNode<Type>* find(const Type &key)	//查找函数
	{
		ListNode<Type> *p = first->next;
		while(p != first && p->data != key)
			p = p->next;
		if(p == first)
			return NULL;
		else
			return p;
	}
	bool erase(const Type &key)				//删除值函数
	{
		if(Is_Empty())
			return false;
		ListNode<Type> *p = first;
		while(p->next != first && p->next->data != key)
			p = p->next;
		ListNode<Type> *q = p->next;
		p->next = p->next->next;
		delete q;
		q = NULL;
		--size;
		return true;
	}
	bool insert(ListNode<Type> *s)			//按结点插入
	{
		ListNode<Type> *p = first;
		while(p->next != first && p->next->data < s->data)
			p = p->next;
		if(p->next == first)
			last = s;
		s->next = p->next;
		p->next = s;
		return true;
	}
	/*
	bool insert(const Type &x)				//按值插入
	{
		ListNode<Type> *p = first;
		while(p->next != first && p->next->data <x)
			p = p->next;
		ListNode<Type> *s = new ListNode<Type>(x);
		if(p->next == first)
			last = s;
		s->next = p->next;
		p->next = s;
		++size;
		return true;
	}
	*/
	void sort()							//排序函数
	{
		if(Is_Empty())
			return;
		ListNode<Type> *p = first->next,*t = p->next;
		last = p;
		last->next = first;

		while(t != first)
		{
			p = t;
			t = p->next;
			insert(p);
		}
	}
	void clear()							//清空函数
	{
		if(size == 0)
			return;
		ListNode<Type> *p = first->next;
		while(p != first)
		{
			first->next = p->next;
			delete p;
			p = first->next;
		}
		first->next = first;
		last = first;
		size = 0;
	}
	void reverse()						//转置函数
	{
		if(Is_Empty())
			return;
		ListNode<Type> *p = first->next,*t = p->next;
		last = p;
		last->next = first;

		while(t != first)
		{
			p = t;
			t = p->next;
			push_front(p->data);
			delete p;
		}
	}
private:
	ListNode<Type> *first;
	ListNode<Type> *last;
	size_t			size;
};
#endif
