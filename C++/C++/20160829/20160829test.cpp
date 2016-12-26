#include<iostream>
using namespace std;
/*
为什么要使用静态成员变量，如果使用全局变量的话，太危险，容易出错。
*/
#if 0
int count;
class student
{
	public:
		student():m_count(0){m_count++;count++;}
		void print(){cout<<m_count<<","<<count<<endl;}
	private:
		int m_count;
};
int main()
{
	student a,b,c,d,e;
	a.print();
	b.print();
	return 0;
}
#endif
#if 0
/*
静态成员变量:所有成员可以调用，并且受保护。类本身不占空间。
*/
class student
{
public:
   student(){m_count++;}
   void print(){cout<<m_count<<endl;}
private:
   static int m_count;
};
 int student::m_count;
int main()
{
 student a,b,c,d,e;
 a.print();
 b.print();
 c.print();
 d.print();
 e.print();
}
#endif
/*
a.h a.cpp test.cpp
    静态成员的初始化一般放在a.cpp当中
*/
#if 0
class A
{
public:
   A(){m_i++;cout<<m_i<<endl;}
   void print(){cout<<m_i<<endl;}
   static void test(A &a)
      {
	   m_i = 6;
	   a.m_j = 9;
	  }//静态成员函数中不能直接访问非静态成员
//静态成员函数没有this指针，不能直接访问非静态成员，非静态成员函数里面可以访问静态成员或非静态成员。
private:
   static int m_i;
   int m_j;
};
int A::m_i;
int main()
{
 A a,b,c,d;
 a.print();
 a.test(b);
 b.print();
 return 0;
};
#endif
#if 0

class B;
class A
{
 public:
     A(int i = 0):m_i(i){}
	 friend void fn(A &a,B &b);
 private:
     int m_i;
};
class B
{
 public:
    B(int j = 0):m_j(j){}
	friend void fn(A &a,B &b);
 private:
    int m_j;
};
void fn(A &a,B &b)
{
  cout<<a.m_i+b.m_j<<endl;
}
int main()
{
 A a(5);
 B b(7);
 fn(a,b);
}
#endif
/*
友元不是类的成员函数(只是朋友)，不能在类里面定义
友元关系是单向的
友元关系不能继承
*/
#if 0
class B;
class A
{
 public:
    A(int i = 0):m_i(i){}
	void fn(B &b);
 private:
    int m_i;
};
class B
{
 public:
    B(int j = 0):m_j(j){}
	friend void A::fn(B &b);
 private:
    int m_j;
};
void A::fn(B &b)
{
 cout<<m_i + b.m_j<<endl;
}
int main()
{
 A a(4);
 B b(3);
 a.fn(b);
 return 0;
}
#endif
//常成员函数（不能修改本类数据成员的值）
#if 0
class A
{
 public:
   A():j(5){}
   void set()const{i = 5;}
   int get()const{return i;}
 private:
   mutable int i;
   const int j;
};
int main()
{
 A a;
 a.set();
 cout<<a.get()<<endl;
 return 0;
}
#endif
#if 0
int i;
namespace Ns
{
 int j;
}
int main()
{
 i = 5;
 Ns::j = 6;
 {
  using namespace Ns;
  int i;
  i = 7;
  cout<<"i ="<<i<<endl;
  cout<<"j ="<<j<<endl;
 }
 cout<<"i ="<<i<<endl;
 return 0;
}
#endif
#if 0
int i = 1;//i是全局变量
void other()
{//a,b为静态局部变量，具有全局寿命，局部可见，只是第一次进入函数时初始化
 static int a = 2;
 static int b;
 int c = 10;//c是局部变量，具有动态生存期，每次进入函数时，都初始化
 a+=2;
 i+=32;
 c+=5;
 cout<<"---OTHER---"<<endl;
 cout<<" i: "<<i<<"a: "<<a<<"b: "<<b<<"c: "<<c<<endl;
 b = a;
}
int main()
{//a为静态局部变量，具有全局寿命，局部可见
 static int a;
 int b = -10;//b,c为局部变量，具有动态生存期
 int c = 0;
 cout<<"---MAIN---"<<endl;
 cout<<" i: "<<i<<"a: "<<a<<"b: "<<b<<"c: "<<c<<endl;
 c+=8;
 other();
 cout<<"---MAIN---"<<endl;
 cout<<" i: "<<i<<"a: "<<a<<"b: "<<b<<"c: "<<c<<endl;
 i+=10;
 other();
 return 0;
}
#endif
#if 0
class point
{
 public:
    point(int x = 0,int y = 0):x(x),y(y) {count++;}
	point(point &p)
	     {
		  x = p.x;
		  y = p.y;
		  count++;
		 }
	~point(){count--;}
	int getx(){return x;}
	int gety(){return y;}
	void showCount()
	{
	 cout<<"object count = "<<count<<endl;
	}
 private:
    int x,y;
    static int count;//用count来记录对象的个数
};
int point::count = 0;
int main()
{
 point a(4,5);
 cout<<"point A:"<<a.getx()<<","<<a.gety()<<endl;
 a.showCount();
 point b(a);
 cout<<"point B:"<<b.getx()<<","<<b.gety()<<endl;
 return 0;
}
#endif
#if 0
#include<cmath>
class point
{
public:
   point(int x = 0,int y = 0):x(x),y(y){}
   int getx(){return x;}
   int gety(){return y;}
   friend float dist(point &p1,point &p2);
private:
   int x,y;
};
float dist(point &p1,point &p2)
{
 double x = p1.x - p2.x;
 double y = p1.y - p2.y;
 return static_cast<float>(sqrt(x*x+y*y));
}
int main()
{ 
 point p1(1,1),p2(4,5);
 cout<<"the distance is:";
 cout<<dist(p1,p2)<<endl;
 return 0;
}
#endif
#if 0
/*
 使用const关键字修饰的函数为常成员函数，常成员函数声明的格式如下，
 类型说明符 函数名（参数表） const
 const是函数类型的一个组成部分，因此在函数的定义部分也要带const关键字
 如果将一个对象说明为常对象，则通过该常对象只能调用它的常成员函数，而不能调用其他成员函数
 无论是否通过常对象调用常成员函数，在常成员函数调用期间，目的对象都被视为常对象，因此常成员函数不能更新目的对象的数据成员，也不能针对目的对象调用该类中没有用const修饰的成员函数。
  const关键字可以用于对重载函数的区分。
  如果仅仅以const关键字为区分对成员函数重载，那么通过非const的对象调用该函数，两个重载的函数都可以与之相匹配，这时编译器会选择不带const关键字的函数
*/
class R
{
public:
 R(int r1,int r2):r1(r1),r2(r2){}
 void print();
 void print()const; //常成员函数
private:
  int r1,r2;
};
void R::print()
{
 cout<<r1<<":"<<r2<<endl;
}
void R::print() const
{
 cout<<r1<<":"<<r2<<endl;
}
int main()
{
 R a(5,4);
 a.print();
 const R b(20,52);
 b.print();
 return 0;
}
#endif
#if 0
/*
常数据成员只能通过初始化列表
常引用
  const 类型说明符 & 引用名;

*/
#endif
#if 0
/*
定义一个Cat类，拥有静态数据成员numOfCats，记录Cat的个体数目，静态成员函数getNumOfCats(),读取numOfCats.设计测试这个类，体会静态数据成员和静态成员函数的用法
*/
class Cats
{
 public:
   Cats(){}
   static int getNumOfCats()
      {
	   return numOfCats;
	  }
 private:
   static int numOfCats;   
};
int Cats::numOfCats = 16;
int main()
{
 Cats A ;
 cout<<A.getNumOfCats()<<endl;
 return 0;
}
#endif
#if 1

#endif



















