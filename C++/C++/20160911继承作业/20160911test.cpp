#include<iostream>
using namespace std;
#if 0
/*
   定义一个基类Shape,在此基础上派生出Rectangle和Circle,二者都有getArea()函数计算对象的面积。使用Rectangle类创建一个派生类Square.
 */
#define pi 3.14
#include<cmath>
#include<stdlib.h>
class shape
{
	public:
		virtual float area() = 0;
};
class circle:public shape
{
	public:
		circle(float r1)
		{
			r = r1;
		}
		float area()
		{
			return (float)pi*r*r;
		}
	private:
		float r;
};
class retangle:public shape
{
	private:
		float width,height;
	public:
		retangle(float w1,float h1)
		{
			width = w1;
			height = h1;
		}
		float area()
		{
			return width*height;
		}
};
class square:public retangle
{
	public:
		square(float len):retangle(len,len){}
		~square(){}
		float area(float len)
		{
			return len*len;
		}
};
float total(shape *s[],int n)
{
	float sum = 0.0;
	for (int i = 0; i < n; ++i)
		sum+=s[i]->area();
	return sum;
}
int main()
{
	shape *s[2];
	s[0] = new circle(1);
	cout<<s[0]->area()<<endl;
	s[1] = new retangle(2,4);
	cout<<s[1]->area()<<endl;
	s[2] = new square(3);
	cout<<s[2]->area()<<endl;
	cout<<total(s,3)<<endl;
	for (int i = 0; i < 3; ++i)
		delete []s[i];
	system("pause");

	return 0;
}
#endif
#if 0
/*
定义一个哺乳动物类Mammal,再由此派生出狗类Dog,定义一个Dog类的对象，观察基类与派生类的构造函数和析构函数的调用顺序。
*/
class Mammal
{
 public:
	Mammal(){cout<<"Constructor1"<<endl;}
    ~Mammal(){cout<<"destructor1"<<endl;}
 private:
	
};
class Dog:public Mammal
{
 public:
	Dog(int age = 0,int weight = 0):age(age),weight(weight){cout<<"Constructor2"<<endl;}	
	~Dog(){cout<<"destructor2"<<endl;}
 private:
	int age,weight;
};
int main()
{
 Dog A(5,8);
 return 0;
}
#endif
#if 0
/*
定义一个基类及其派生类，在构造函数中输出提示信息，构造派生类的对象，观察构造函数的执行情况。
*/
class 
#endif
#if 0
/*
定义一个Document类，有数据成员name,从Document派生出Book类，增加数据成员pageCount.
*/
class Document
{
 public:
	 void initDocument(string a = "")
	 {
	 name = a;
	 cout<<"1"<<endl;
	 }
	 ~Document(){cout<<"!1"<<endl;}
	 string getname() const {return name;}
 private:
	string name;
};
class Book:public Document
{
 public:
	void initBook(string a,int b = 0)
	{
	initDocument(a);
	pageCount = b;
	cout<<"2"<<endl;
	}
	int getCount() const {return pageCount;}
	~Book(){cout<<"!2"<<endl;}
 private:
	int pageCount;
};
int main()
{
 Book a;
 a.initBook("string",5);
 cout<<a.getCount()<<endl;
 cout<<a.getname()<<endl;
 return 0;
}
#endif
#if 0
/*
定义一个基类Base，有两个公有成员函数fn1(),fn2()，私有派生出Derived类，如何通过Derived类的对象调用基类的函数fn1()。
*/
class Base
{
 public:
	void fn1(){cout<<"1"<<endl;}
	void fn2(){cout<<"2"<<endl;}
 private:
};
class Derived:private Base
{
 public:
	void fn1(){Base::fn1();}
	void fn2(){Base::fn2();}
 private:
};
int main()
{
 Derived a;
 a.fn1();
 a.fn2();
 
 return 0;
}
#endif
#if 0
/*
定义一个Object类，有数据成员weight及相应的操作函数，由此派生出Box类，增加数据成员height和width及相应的操作函数，声明一个Box对象，观察构造函数与析构函数的调用顺序。
*/
class Object
{
 public:
	Object(int weight = 0):weight(weight){cout<<"1"<<endl;}
	~Object(){cout<<"!1"<<endl;}
 private:
	int weight;
};
class Box:public Object
{
 public:
	Box(int height = 0,int width = 0):height(height),width(width){cout<<"2"<<endl;}
	~Box(){cout<<"!2"<<endl;}
 private:
	int height,width;
};
int main()
{
 Box a(3,4);
 return 0;
}
#endif
#if 0
/*
定义一个基类BaseClass，从它派生出类DerivedClass.BaseClass有成员函数fn1(),fn2(),DerivedClass也有成员函数fn1(),fn2().在主函数中声明你该一个DerivedClass的对象，分别用DerivedClass的对象以及BaseClass和DerivedClass的指针来调用fn1(),fn2(),观察运行结果。
*/
class BaseClass
{
 public:
	void fn1(){cout<<"1"<<endl;}
	void fn2(){cout<<"2"<<endl;}
 private:
	
};
class DerivedClass:public BaseClass
{
 public:
	void fn1(){cout<<"3"<<endl;}
	void fn2(){cout<<"4"<<endl;}
 private:
	
};
int main()
{
 DerivedClass a;
 BaseClass *p;
 DerivedClass *q;
 a.fn1();
 a.fn2();
 p -> fn1();
 p -> fn2();
 q -> fn1();
 q -> fn2();
 return 0;
}

#endif
#if 0
/*
7.15下面的程序能得到预期的结果吗？如何避免类似问题的发生？

*/
struct Base1{int x;};
struct Base2{float y;};
struct Derived:Base1,Base2{};
int main()
{
 Derived *pd = new Derived;
 pd -> x = 1;
 pd -> y = 2.0f;
 void *pv = pd;
 Base2 *pd = static_cast<Base*>(pv);
 cout<<pd -> y <<""<<pb -> y<<endl;
 delete pb;

 return 0;
}
#endif
















