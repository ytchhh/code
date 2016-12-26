#ifndef _LIST_H
#define _LIST_H
#include<iostream>
using namespace std;

typedef struct Data
{
	float coef;			//系数
	int expn;			//指数
}Elemtype;

class List;

class ListNode
{
friend class List;
public:
	ListNode():data(Elemtype()),next(NULL)
	{
	}
	ListNode(const Elemtype &e,ListNode *n = NULL):data(e),next(n)
	{
	}
	~ListNode()
	{
	}
	bool operator!=(Elemtype e)
	{
		return (this->data.coef != e.coef)&&(this->data.expn != e.expn);
	}
private:
	Elemtype data;
	ListNode *next;
};

class List
{
public:
	List()
	{
		first = last = new ListNode;
		size = 0;
	}
	~List()
	{
		
	}
public:
	void DestroyPolyn()
	{
		ListNode *p = first,*q;
		while(p->next)
		{
			q = p->next;
			p = q->next;
			delete q;
		}
		delete first;
		first = last = NULL;
		size = 0;
	}
	void Clear_Polyn()
	{
		ListNode *p = first->next,*q;
		while(p)
		{
			q = p;
			p = p->next;
			delete q;
		}
		last = first;
		size = 0;
	}
	
	void Merge(Elemtype &e)
	{
		ListNode *p = first->next,*q = first;
		while(p != NULL && p->data.expn != e.expn)
		{
			q = p;
			p = p->next;
		}
		if(p != NULL)
		{
			p->data.coef += e.coef;
			if(0 == p->data.coef)
				Delete_Node(p->data);
		}
	}

	bool Find_Expn(int expn)
	{
		ListNode *p = first->next;
		while(p != NULL && p->data.expn != expn)
			p = p->next;
		if(!p)
			return false;
		else
			return true;
	}
	void Insert_Expn(ListNode *p)
	{
		ListNode *q = first;
		while(q->next != NULL && q->next->data.expn < p->data.expn)
			q = q->next;
		p->next = q->next;
		q->next = p;
		if(size == 0)
			last = p;
		++size;
	}
	void CreatPolyn(int m)
	{
		Elemtype e;
		int i;
		ListNode *p = NULL;
		
		cout<<"请依次输入"<<m<<"个系数,指数:"<<endl;
		for(i = 0; i < m; ++i)
		{
			cin>>e.coef>>e.expn;
			if(!Find_Expn(e.expn))
			{
				p = new ListNode(e);
				Insert_Expn(p);
			}
		}
	}
	
	void PrintPolyn()
	{
		ListNode *p;
		p = first->next;
		cout<<"指数     系数"<<endl;
		while(p)
		{
			cout<<p->data.coef<<"        "<<p->data.expn<<endl;
			p = p->next;
		}
	}
	int cmp(Elemtype a,Elemtype b)
	{
		if(a.expn < b.expn)
			return -1;
		else if(a.expn == b.expn)
			return 0;
		else if(a.expn > b.expn)
			return 1;
	}
	bool Is_Full()
	{
		if(first->next == NULL)
			return true;
		else
			return false;
	}
	void Delete_Node(Elemtype &e)	 //删除结点
	{
		if(Is_Full())
			return;
		ListNode *q = first->next,*t = first;
		while(q != NULL && (*q) != e)
			{
				t = q;
				q = q->next;	
			}
		if(q == NULL)
			return;
		else
		t->next = q->next;
		delete q;
		q = NULL;
		--size;
	}
	void AddPolyn(List &L)
	{	//多项式加法, pa = pa + pb,并摧毁一元多项式
		ListNode *ha,*hb,*qa,*qb;
		
		Elemtype a,b;
		ha = first;
		hb = L.first;		//ha和hb分别指向头结点
		qa = ha->next;
		qb = hb->next;		//qa和qb分别指向第一个结点
		
		while(!Is_Full() && !L.Is_Full() && qa && qb)
		{
			a = qa->data;
			b = qb->data;	//a和b分别指向两个链表当前元素

			switch(cmp(a,b))
			{
				case -1://qa的指数<qb的指数
						ha = qa;			//ha向后移动
						qa = ha->next;		//qa向后移动
						break;
				case 0:
						qa->data.coef += qb->data.coef;//两者的指数相等,修改pa所指的系数
						if(0 == qa->data.coef)	//删除当前结点
							Delete_Node(qa->data);
						else
							ha = qa;
						L.Delete_Node(qb->data);
						qb = hb->next;
						qa = ha->next;
						break;

				case 1:			//多项式pa大于pb;
						ListNode *p = new ListNode(qb->data);
						L.Delete_Node(qb->data);
						Insert_Expn(p);
						ha = ha->next;
						qb = hb->next;
						break;
			}
		}
		if(!L.Is_Full())
		{
			while(qb != NULL)		//链接L中剩余结点
			{
				hb = qb;
				qb = qb->next;
				Insert_Expn(hb);
			}
		}
		L.DestroyPolyn();
	}
	void Opposite()			//一元多项式系数取反
	{
		ListNode *p;
		p = first;
		while(p->next)
		{
			p = p->next;
			p->data.coef *= -1;
		}
	}
	void SubtractPolyn(List &L)		//减法
	{
		L.Opposite();
		AddPolyn(L);
	}
	void MultiplyPolyn(List &L)		//乘法
	{
		List pc;
		ListNode *qa,*qb;
		Elemtype a,b,c;
		qa = first->next;
		while(qa)
		{
			a = qa->data;
			qb = L.first->next;
			while(qb)
			{
				b = qb->data;
				c.coef = a.coef * b.coef;
				c.expn = a.expn + b.expn;
					if(pc.Find_Expn(c.expn))	//如果已经存在该项指数
						pc.Merge(c);			//合并系数
					else
					{
						ListNode *p = new ListNode(c);	//不存在的话直接插入
						pc.Insert_Expn(p);
					}
				qb = qb->next;
			}
			qa = qa->next;
		}
		L.DestroyPolyn();	//摧毁L链表
		Clear_Polyn();		//将本身的链表清空
		first = pc.first;
		last = pc.last;
		size = pc.size;
	}
private:
	ListNode *first;	//头结点
	ListNode *last;		//尾结点
	size_t	 size;		//个数
};
#endif
