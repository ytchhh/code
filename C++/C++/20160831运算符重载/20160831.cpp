#include<iostream>
using namespace std;
#if 0
/*
运算符重载是为了让类类型的对象可以直接像基本数据类型一样进行普通运算符运算 
*/
class A;
int add1(A &a,A &b);
class A
{
 public:
    A(int i = 0):m_i(i){}
	int add(A &b)
	   {
	     return m_i+b.m_i;//想要实现两个类类型的对象进行相加，这时第一种方法
	   }
	friend int add1(A &a,A &b);
	void print(){cout<<m_i<<endl;}   
    int get()const{return m_i;}//第二种方法是弄返回值类型的函数
 private:
    int m_i;
};
int add1(A &a,A &b)
{
 cout<<a.m_i+b.m_i<<endl;
}
int main()
{
  A a(3),b(5);
  A c;
  c = a.add(b);
  c.print();
  A d;
  d = a.get()+b.get();
  d.print();
  add1(a,b);
  return 0;
}
#endif
#if 0
/*
如果是在赋值表达式右边的话，就是作为返回值类型。
如果是在赋值表达式左边的话，就是作为引用返回。
*/
class A
{
 public:
 A(int i = 0):m_i(i){}
 void print()
 {
  cout<<m_i<<endl;
 }
 A operator+(A &b)
 {
  cout<<"+"<<endl;
  return m_i+b.m_i;
 }
 private:
   int m_i;
};
int main()
{
 A a(3),b(5);
 A c;
 c = a + b;
 c.print();
 return 0;
}
#endif
#if 0
/*
值返回，引用返回
*/
int main()
{
 int a = 5,b = 3,c = 0;
 c = a + b;
 (c = a) = b;
 ++b = a;
 
 return 0;
}
#endif
#if 1
/*

*/
class A
{
 public:
    A(int i = 0):m_i(i){cout<<"A"<<endl;}
	void print(){cout<<m_i<<endl;}
	A(A &b)
	{
	  cout<<"copy"<<endl;
	  m_i = b.m_i;
	}

	/*
	A operator+(A &b)
	{
	  return m_i + b.m_i;
	}

	A &operator=(A &b)
	{
	  cout<<"="<<endl;
	  m_i = b.m_i;
	  return *this;
	}
	A operator++(int)//自加运算符的时候，在后加加里面的形參列表加入int关键字来和前加加区别
	{
	  int t = m_i;
	  m_i = m_i + 1;
	  return t;
	}
	A operator++()
	{
	 ++m_i;
	 return *this;
	}
	A &operator+(A &b)
	{
	 m_i = m_i + b.m_i;
	 return *this;
	}
    */
 private:
    int m_i;
};
int main()
{
 class A a(4),b(8);
 //class A c = a + b;
 //c.print();
 
 return 0;
}
#endif






















