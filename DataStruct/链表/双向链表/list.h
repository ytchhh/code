#include"utili.h"

template<class Type>
class List;

template<class Type>
class ListNode
{
friend class List<Type>;
public:
	ListNode():data(Type()),prev(NULL),next(NULL)
	{}
	ListNode(const Type d,ListNode<Type> *p = NULL,ListNode<Type> *n = NULL):data(d),prev(p),next(n)
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
		size = 0;
		first->prev = NULL;
		last->next = NULL;
	}
	~List()
	{
		clear();
		delete first;
		first = last = NULL;
	}
public:
	bool Is_Full()			//判断是否为空
	{
		if(first->next == NULL)
			return true;
		else
			return false;
	}
	void push_back(const ElemType &e)			//后插函数
	{
		ListNode<Type> *p = new ListNode<Type>(e);
		last->next = p;
		p->prev = last;
		last = p;
		++size;
	}
	void show_list()				//显示函数
	{
		ListNode<Type> *p = first->next;
		while(p != NULL)
		{
			cout<<p->data<<"-->";
			p = p->next;
		}
		cout<<"Over!"<<endl;
	}
	void push_front(const ElemType &e)			//前插函数
	{
		ListNode<Type> *p = new ListNode<Type>(e);
		p->next = first->next;
		first->next = p;
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
	void pop_back()					//尾删函数
	{
		if(Is_Full() == true)
			return;
		else
		{
			ListNode<Type> *p = last->prev;
			p->next = NULL;
			delete last;
			last = p;
			--size;
		}
	}
	void pop_front()				//头删函数
	{
		if(Is_Full() == true)
			return;
		else
		{
			ListNode<Type> *p = first->next,*q;
			q = p->next;
			if(q == NULL)
			{
				last = first;
				first->next = q;
			}
			else
			{
				first->next = q;
				q->prev = first;
			}
		--size;
		}
	}
	bool insert(ListNode<Type> *p,const Type &x)			//给定位置,插入值.
	{
		 ListNode<Type> *q = first->next;
		 ListNode<Type> *t = new ListNode<Type>(x);
		 while(q != p && q != NULL)
		 {
			q = q->next;
		 }
		 if(q != NULL)
		 {
			if(q == last)
				push_back(x);
			else
			{
				p->next->prev = t;
				t->next = p->next;
				p->next = t;
				t->prev = p;
				++size;
			}
			return true;
		 }
		 else
			return false;
	} 
	bool delete_val(const Type &x)				//按值删除函数
	{
		if(Is_Full() == true)
			return true;
		ListNode<Type> *p = first->next;
		while(p->data != x && p != NULL)
		{
			p = p->next;
		}
		if(p == NULL)
			return false;
		else
		{
			if(p == first->next)
				pop_front();
			else if(p == last)
				pop_back();
			else
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
				--size;
			}
			return true;
		}
	}
	void clear()		//清空函数
	{
		ListNode<Type> *p = first->next,*q;
		while(p != NULL)
		{
			q = p->next;
			delete p;
			p = q;
		}
		first->next = NULL;
		last = first;
		size = 0;
	}
	void insert(ListNode<Type> *p)		//插入结点,按结点的值插入,从小到大.
	{
			ListNode<Type> *t = first;
			while(t->next != NULL && t->next->data < p->data)
				t = t->next;
			if(t->next == NULL)
				last = p;
			else
				t->next->prev = p;
			p->next = t->next;
			t-next = p;
			p->prev = t;
	}
	void sort()							//排序函数
	{
		ListNode<Type> *p = first->next,*q = p->next;
		p->next = NULL;
		last = p;
		
		while(q != NULL)
		{
			p = q;
			q = p->next;
			insert(p);
		}
	}
	void reverse()						//转置函数
	{
		ListNode<Type> *p = first->next,*q = p->next;
		last = p;
		p->next = NULL;

		while(q != NULL)
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
