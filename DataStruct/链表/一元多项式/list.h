#ifndef _LIST_H
#define _LIST_H

#include"utili.h"

typedef struct		//多项式的项做为LikList的数据元素
{
	float coef;		//系数
	int   expn;		//指数
}term,ElemType;

typedef struct ListNode		//结点类型
{
	ElemType data;
	ListNode *next;
}*Link,*Position;

struct List
{
	struct ListNode *first;		//头结点
	struct ListNode *last;			//尾结点
	int		 len;			//数据元素的个数
};

///////////////////////////////////////////

void MakeNode(Link p,ElemType e);	//分配由p指向的值为e的结点,若分配失败,则退出
void InsertFirst(List *L,ListNode *h,ListNode *s);	//h指向一个结点,把h当做头结点，将s所指结点插在第一个结点之前
void InitList(List *L);			//构造一个空的线性链表
Position LocateElem(List *L,ElemType e,int (*compare)(ElemType,ElemType));
int cmp(term a,term b);				//依a的指数值<,=,>分别返回-1,0,1
bool ListEmpty(List *L);			//判空
ElemType GetCurElem(Link p);		//得到当前元素
void CreatPolyn(List *p,int m);		//输入m项的系数和指数,建立一元多项式的有序链表
void PrintPolyn(List *p);			//打印函数
bool DelFirst(List *L,Link h,Link q);		//
void FreeNode(Link *p);					//释放结点
void Append(List *L,Link s);			//
void AddPolyn(List *pa,List *pb);		//多项式加法
void Opposite(List *L);					//取反
void SubtractPolyn(List *pa,List *pb);		//减法








///////////////////////////////////////////
void MakeNode(Link p,ElemType e)
{
	p = (Link)malloc(sizeof(ListNode));
	if(!p)
		exit(1);
	p->data = e;
}
void InitList(List *L)
{
	Link p;
	p = (Link)malloc(sizeof(ListNode));
	if(p)
	{
		p->next = NULL;
		L->last = L->first = p;
		L->len = 0;
	}
	else
		exit(1);
}
void InsertFirst(List *L,ListNode *h,ListNode *s)
{
	s->next = h->next;
	h->next = s;
	if(h == L->last)		//h指向尾结点
		L->last = h->next;	//修改尾指针
	L->len++;
}
bool DelFirst(List *L,Link h,Link q)
{	//h指向L的一个结点,

	q = h->next;
	if(q)
	{
		h->next = q->next;
		if(!h->next)		//删除尾结点
			L->last = h;
		L->len--;
		return true;
	}
	else
		return false;
}
void FreeNode(Link p)
{
	free(p);
	p = NULL;
}
void Append(List *L,Link s)
{
	int i = 1;
	L->last->next = s;
	while(s->next)
	{
		s = s->next;
		++i;
	}
	L->last = s;
	L->len += i;
}
bool LocateElem(List *L,ElemType e,Position q,int (*compare)(ElemType,ElemType))
{//若升序链表L中存在与e满足判定函数compare()取值为0的元素,则q指示L中
 //第一个值为e的结点的位置,并返回true,否则q指示第一个与e满足判定函数
 ListNode *pp,*p = L->first;
 do
 {
	pp = p;
	p = p->next;
 }while(p && (compare(p->data,e) < 0));	//没到表尾且p->data < e.data
 if(!p || compare(p->data,e) > 0)
 {
	q = pp;
	return false;
 }
 else	//找到
 {
	q = p;
	return true;
 }
}
int cmp(term a,term b)
{
	if(a.expn == b.expn)
		return 0;
	else
		return (a.expn - b.expn)/abs(a.expn - b.expn);
}
bool ListEmpty(List *L)
{//若表为空，则返回true,否则返回false.
	if(L->len)
		return false;
	else
		return true;
}
ElemType GetCurElem(Link p)
{//已知p指向线性链表中的一个结点，返回p中所指数据元素的值
	return p->data;
}
void CreatPolyn(List *p,int m)
{
	Position q,s;
	term e;
	int i;
	
	InitList(p);
	printf("请依次输入%d个系数,指数:\n",m);
	for(i = 1; i <= m; ++i)
	{//依次输入m个非零项(可按任意顺序)
		scanf("%f,%d",&e.coef,&e.expn);
		if(!LocateElem(p,e,q,cmp))//当前链表不存在该指数项,cmp是实参
		{
			MakeNode(s,e);
			InsertFirst(p,q,s);			//生成结点并插入链表
		}
	}
}
void PrintPolyn(List *p)
{
	Link q;
	q = p->first->next;			//q指向第一个结点
	printf("系数　　指数\n");
	while(q)
	{
		printf("%f    %d\n",q->data.coef,q->data.expn);
		q = q->next;
	}
}
void AddPolyn(List *pa,List *pb)
{	//pa = pa + pb,并摧毁pb
	Position ha,hb,qa,qb;
	term a,b;
	ha = pa->first;
	hb = pb->first;		//ha和hb分别指向pa和pb的头

	qa = ha->next;
	qb = hb->next;		//qa和qb分别指向第一个结点
	
	while(!ListEmpty(pa) && !ListEmpty(pb) && qa)
	{//
		a = GetCurElem(qa);
		b = GetCurElem(qb);			//a和b为两表中当前比较元素
		switch(cmp(a,b))
		{
		case -1:
			ha = qa;
			qa = ha->next;
			break;
		case 0:
			qa->data.coef += qb->data.coef;		//两者的指数值相等,修改当前结点的系数值
			if(qa->data.coef == 0)
			{
				DelFirst(pa,ha,qa);
				FreeNode(qa);
			}
			else
				ha = qa;
			DelFirst(pb,hb,qb);
			FreeNode(qb);
			qb = hb->next;
			qa = ha->next;
			break;
		case 1:
			DelFirst(pb,hb,qb);
			InsertFirst(pa,ha,qb);
			ha = ha->next;
			qb = hb->next;
		}
	}
	if(!ListEmpty(pb))
	{
		pb->last = hb;
		Append(pa,qb);
	}
}

void Opposite(List *pa)
{
	Position p;
	p = pa->first;
	while(p->next)
	{
		p = p->next;
		p->data.coef *= -1;
	}
}

void SubtractPolyn(List *pa,List *pb)
{
	Opposite(pb);
	AddPolyn(pa,pb);
}


#endif
