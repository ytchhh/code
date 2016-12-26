#include<iostream>
using namespace std;
#if 10
/*
   1.拷贝构造函数:
   用一个已有对象初始化（构造）一个本类新对象
   3中情况调用拷贝构造
   1.用一个已有对象构造一个新对象
   2.函数传參
   3.返回值为类对象
   */
class A
{
	public:
		A(int i = 0):m_i(i){cout<<"!!"<<endl;}
		A(A t)  //这样的值传递是错误的
		{       //编译器并不能通过，会陷入无限递归中去
			m_i = t.m_i;
			cout<<"AA"<<endl;
		}
		~A(){}
	private:
		int m_i;
};
int main()
{
	A a(5);
	A b(a);
	return 0;
}
#endif
#if 0
class A //用指针传递也是可行的，但是容易混淆
{       //最后选择了引用
	public:
		A(int i = 0):m_i(i){cout<<"!"<<endl;}
		A(A *t)
		{
			m_i = t->m_i;cout<<"AA"<<endl;
		}
		~A(){}
		void print()
		{
			cout<<m_i<<endl;
		}
	private:
		int m_i;
};
int main()
{
	A a(5);
	A b(&a);
	return 0;
}
#endif
#if 0
class A
{
	public:
		A(int i = 0):m_i(i){cout<<"!"<<endl;}
		A(const A &g) //在这儿要加上const
		{
			m_i = g.m_i;
			cout<<"A(&)"<<endl;
		}
		void print(){cout<<m_i<<endl;}
		//	~A(){}
	private:
		int m_i;
};
A test(A &t)
{
	cout<<"test"<<endl;
	t.print();
	A c(7);
	return c;//返回值为类类型
}      //由于编译器自动做了优化
//所以结果不显示调用了两次析构函数
//C会先给一个临时变量，临时变量再给s
int main()
{
	A a(5);
	a.print();
	A b(5);
	b.print();
	A s = test(a);//本类对象值传递
	s.print();
	return 0;
}
#endif
#if 0
/*
   使用的 new 和 delete 的用法，比malloc 和 free要方便很多，只要是指针型，就必须要有相应的delete
   */
class A
{
	public:
		A(int i = 0){cout<<"!"<<i<<endl;}
		~A(){cout<<"~A"<<endl;}
		void print(){cout<<m_i<<endl;}
	private:
		int m_i;
};
int main()
{
	//  A *P = (A*)malloc(sizeof(A));
	//  p -> print();//如果用C语言的方法的话给指针开辟空间太过于麻烦了。
	A *p = new A;
	//  A *q = new A[5];
	// char *q = new char[100];
	// delete []p;
	p->print();
	delete p;
	return 0;
}
#endif
#if 0
#include<string.h>
class STR
{
	public:
		STR(char *str = "")
		{
			m_str = new char[strlen(str)+1];
			strcpy(m_str,str);
		}
		STR(STR &s)
		{
			m_str = new char[strlen(s.m_str+1)];
			strcpy(m_str,s.m_str);
		}
		~STR()
		{
			delete[]m_str;
			m_str = NULL;
		}
		void print()
		{
			cout<<m_str<<endl;
		}
	private:
		char *m_str;
};
int main()
{
	STR a("123456");
	STR b(a);
	a.print();
	b.print();
	return 0;
}
#endif
#if 0
/*
   定义一个datatype类，能处理包含字符型，整型，浮点型，3种类型的数据，写出其构造函数。
   */
class Datatype
{
	public:
		Datatype(char c)
		{
			this->c = c;
			cout<<"1"<<endl;
		}
		Datatype(int i)
		{
			this->i = i;
			cout<<"2"<<endl;
		}
		Datatype(float f)
		{
			this->f = f;
			cout<<"3"<<endl;
		}
	private:
		int i;
		char c;
		float f;
};
int main()
{
	Datatype A('c');
	return 0;
}
#endif
#if 0
/*
   14.定义一个Tree类，有数据成员ages，成员函数grow（int year）和对ages加上years，age()显示tree对象的ages的值。
   */
class Tree
{
	public:
		Tree(int i = 0)
		{
			ages = i;
		}
		void grow(int year)
		{
			ages = year + ages;
		}
		void age()
		{
			cout<<ages<<endl;
		}
	private:
		int ages;
};
int main()
{
	Tree a(5);
	a.grow(5);
	a.age();
	return 0;
}
#endif
#if  0
/*
   13.定义一个Circle类，有数据成员radius，成员函数 getArea(),计算圆的面积，构造一个Circle的对象进行测试
   */
#define Pi 3.141596
class Circle
{
	public:
		Circle(float i =0){radius = i;}
		float getArea()
		{
			float area = Pi*radius*radius;
			return area;
		}

	private:
		float radius;
};
int main()
{
	Circle a(10);
	cout<<"圆的面积是:"<<endl;
	cout<<a.getArea()<<endl;
	return 0;
}
#endif
#if 1
class CPU
{
	public: //描述一个CPU的类，描述一个CPU的以下信息，时钟频率，最大不会超过3000Mhz,

	private:
		int hz,length;
		int nuclear;
};0
#endif
#if 0
class Complex
{
	public:
		Complex(float r1,float i1);
		Complex(float r1);
		void add(Complex &c);
		void show();
	private:
		float r;
		float i;
};
Complex::Complex(float r1,float i1)
{
	r = r1;
	i = i1;
}
void Complex::add(Complex &c)
{
	r+=c.r;
	i+=c.i;
}
void Complex::show()
{
	cout<<r<<(i>0?'+':'-')<<i<<'i'<<endl;
}
Complex::Complex(float r1)
{
	r = r1;
	i = 0;
}
int main()
{
	Complex c1(3,5);
	c1.show();
	Complex c2 = 4.5;
	c2.show();
	c1.add(c2);
	c1.show();
	return 0;
}
#endif
#if 1
/*
   类的组合，线段类(line)类。
   我们使用一个类来描述线段，使用4.3节中point类的对象来表示端点。这个问题可以用类的组合来解决，使line类包括point类的两个对象p1和p2，作为其数据成员，line类具有计算线段长度的功能，在构造函数中实现
   */
#include<cmath>
class point //point类
{
	public:
		point(int xx = 0,int yy = 0)//构造函数
		{
			x = xx;
			y = yy;
		}
		point(const point &p)//拷贝构造函数
		{
			x = p.x;
			y = p.y;
			cout<<"copy"<<endl;
		}
		int getx(){return x;}
		int gety(){return y;}
	private:
		int x,y;
};
class line
{
	public:
		line(point p1,point p2);
		line(const line &p);
		float getlen(){return len;}
	private:
		point p1,p2;
		float len;
};
line::line(point p1,point p2)
{
	cout<<"construct"<<endl;
	float x = static_cast<float>(p1.getx()-p2.getx());float y =static_cast<float>(p1.gety()-p2.gety());
	len = sqrt(x*x+y*y);
}
line::line(const line &p):p1(p.p1),p2(p.p2)
{
	cout<<"copy2"<<endl;
	len = p.len;
}
int main()
{
	point p1(1,1),p2(4,5);
	line line1(p1,p2);
	line line2(line1);
	cout<<"the length of the line1 is:";
	cout<<line1.getlen()<<endl;
	cout<<"the length of the line2 is:";
	cout<<line2.getlen()<<endl;
	return 0;
}
#endif










































