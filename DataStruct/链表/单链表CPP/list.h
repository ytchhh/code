#ifndef _LIST_H
#define _LIST_H



#include<iostream>
using namespace std;
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
	ListNode<Type>*& Get_Next()
	{
		return next;
	}
	Type& Get_Data() 
	{
		return data;
	}
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
	~List()
	{}
public:
	void push_back(const Type &x);
	void push_front(const Type &x);
	void show_list();
	bool pop_back();
	bool pop_front();
	bool insert(const Type &x);
	ListNode<Type>* find(const Type &key);
	bool erase(const Type &key);
	void sort();
	void reverse();
	void clear();
	bool ListEmpty();			//判断线性表是否为空
	int  ListLength();			//求线性表的的长度
	bool GetElem(int i,ElemType &e);		//找到第i个元素
	int  LocateElem(ElemType e,int(*compare)(ElemType,ElemType));					//初始条件:compare()是数据元素判定函数(满足为1,否则为0)
		//操作结果:返回List中第1个与e满足关系compare()的数据元素的位序
private:
	ListNode<Type> *first;
	ListNode<Type> *last;
	size_t		    size;
};

/////////////////////////////////
template<class Type>
void List<Type>::push_back(const Type &x)
{
	ListNode<Type> *s = new ListNode<Type>(x);
	last->next = s;

	last = s;
	size++;
}

template<class Type>
void List<Type>::push_front(const Type &x)
{
	ListNode<Type> *s = new ListNode<Type>(x);
	s->next = first->next;
	first->next = s;
	if(size == 0)
		last = s;
	size++;
}

template<class Type>
void List<Type>::show_list()
{
	ListNode<Type> *s = first->next;
	while(s != NULL)
	{
		cout<<s->data<<"-->";
		s = s->next;
	}
	cout<<"Over!"<<endl;
}

template<class Type>
bool List<Type>::insert(const Type &x)
{
	if(size == 0)		//如果为空链表的话，调用函数。
	{
		push_back(x);
		return true;
	}
	ListNode<Type> *p = first;
	while(p->next != NULL && p->next->data < x)	//循环跳出的条件是两个，可以来判断是否找到合适的位置，从而减少代码的冗余度.
	{
		p = p->next;
	}
	if(p->next == NULL)		//此时插入的是最后一个位置
	{
		push_back(x);
		return true;
	}
	
	ListNode<Type> *s = new ListNode<Type>(x);
	if(s == NULL)
		return false;
	s->next = p->next;
	p->next = s;
	++size;
}

template<class Type>
bool List<Type>::pop_back()
{
	if(first->next == NULL)
		return false;
	else
	{
		ListNode<Type> *p = first;
		while(p->next != last)
			p = p->next;
		last = p;
		last->next = NULL;
		--size;
		return true;
	}
}

template<class Type>
bool List<Type>::pop_front()
{
	if(first->next == NULL)
		return false;
	else
	{
		ListNode<Type> *p = first->next;
		if(p == NULL)
			first->next = NULL;
		else
		{
			p = p->next;
			first->next = p;
		}
		--size;
		return true;
	}
}

template<class Type>
bool List<Type>::erase(const Type &key)
{
	if(first->next == NULL)
		return false;
	else
	{
		if(find(key) == NULL)
			return false;
		else
		{
			ListNode<Type> *q,*p = find(key);
			if(p == last)
				pop_back();
			else
			{
				q = first;
				while(q->next != p)
					q = q->next;
				q->next = p->next;
			}
			--size;
			return true;
		}
	}
}

template<class Type>
void List<Type>::clear()
{
	ListNode<Type> *p,*q;
	p = first->next;	//指向第一个结点
	while(p)			//没到表尾
	{
		q = p->next;
		delete p;
		p = q;
	}
	first->next = NULL;	//	头结点的指针域为空
}

template<class Type>
void List<Type>::sort()
{
	if(first == last || first->next->next == NULL)
		return;
	else
	{
		int i,j,t,n = 0;
		ListNode<Type> *p = first->next,*q;
		while(p != NULL)
		{
			++n;
			p = p->next;
		}
		for(i = 0; i < n-1; ++i)
		{
			p = first->next;
			q = p->next;
			for(j = 0; j < n-1-i; ++j)
			{
				if(p->data > q->data)
				{
					t = p->data;
					p->data = q->data;
					q->data = t;
					p = p->next;
					q = q->next;
				}
			}
		}
	}
}

template<class Type>
bool List<Type>::ListEmpty()
{		//初始条件:线性表已经存在
	if(first->next)		//非空
		return false;
	else
		return true;
}

template<class Type>
int List<Type>::ListLength()
{		//	初始条件:线性表L已经存在,返回其中的个数
	int i = 0;
	ListNode<Type> *p = first->next;
	while(p)		//没到表尾
	{
		++i;
		p = p->next;
	}
	return i;
}

template<class Type>
bool List<Type>::GetElem(int i,ElemType &e)
{		//当第i个元素存在的时候赋给e,不存在时返回false。
	int j = 1;		//j为计数器
	ListNode<Type> *p = first->next;
	while(p && j < i)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i)		//第i个元素不存在
		return false;
	e = p->data;		//取第i个元素
	return true;

}

template<class Type>
int List<Type>::LocateElem(ElemType e,int(*compare)(ElemType,ElemType))
{
	int i = 0;
	ListNode<Type> *p = first->next;
	while(p)
	{
		++i;
		if(compare(p->data,e))		//找到这样的数据元素
			return i;
		p = p->next;
	}
	return 0;
}

template<class Type>
void List<Type>::reverse()			//链表转置函数
{
	ListNode<Type> *p = first->next,*pleft = NULL,*pright = NULL;
	while(p != NULL)
	{
		pright = p->next;
		p->next = pleft;
		pleft = p;
		p = pright;
	}
	first = pleft;
}

template<class Type>
ListNode<Type>* List<Type>::find(const Type &key)
{
	ListNode<Type> *p = first->next;
	while(p != NULL && p->data != key)
		p = p->next;
	return p;
}

#endif
