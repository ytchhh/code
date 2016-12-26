#include<iostream>
using namespace std;
#if 0
/*
虚函数是动态绑定的基础，虚函数必须是非静态的成员函数。虚函数经过派生之后，在类族中就可以实现运行过程中的多态。
*/
/*
虚函数成员的声明语法是:
virtual 函数类型 函数名(形參表);
虚函数声明只能出现在类定义中的函数原型中，而不能在成员函数实现的时候。
 运行过程中的多态需要满足他个条件，
 第一是类之间满足赋值兼容规则，第二是要声明虚函数，第三是要由成员函数来调用或者是通过指针，引用来访问虚函数。
 虚函数一般补声明为内联函数，因为对虚函数的调用需要动态绑定，而对内联函数的处理是静态的，所以虚函数一般不能移内联函数处理。但将虚函数声明为内联函数也不会引起错误。
*/
class Base1
{
public:
   virtual void display() const;
};
void Base1::display() const
{
 cout<<"Base1::display()"<<endl;
}
class Base2:public Base1
{
 public:
	void display() const;
};
void Base2::display() const
{
 cout<<"Base2::display()"<<endl;
}
class Derived:public Base2
{
 public:
	void display() const;
};
void Derived::display() const
{
 cout<<"Derived::display()"<<endl;
}
void fun(Base1 *ptr) //参数为指向基类对象的指针
{
 ptr -> display();//对象指针 -> 成员名
}
int main()
{
 Base1 base1;
 Base2 base2;
 Derived derived;
 fun(&base1);
 fun(&base2);
 fun(&derived);
 return 0;
 return 0;
}
#endif
#if 0
/*
虚析构函数
虚析构函数的声明语法为:
virtual ~类名();
*/
//如果一个类的析构函数是虚函数，那么由它派生而来的所有子类的析构函数也是虚函数。析构函数设置为虚函数之后，在使用指针引用时可以动态绑定，实现运行时的多态，保证使用基类类型的指针就能调用适当的析构函数针对不同的对象进行清理工作。
class Base
{
public:
	virtual ~Base();
};
Base::~Base()
{
 cout<<"Base destructor"<<endl;
}
class Derived:public Base
{
 public:
	Derived();
	~Derived();
 private:
	int *p;
};
Derived::Derived()
{
 p = new int(0);
}
Derived::~Derived()
{
 cout<<"Derived destructor"<<endl;
 delete p;
}
void fun(Base *b)
{
 delete b;
}
int main()
{
 Base *b = new Derived();
 fun(b);

 return 0;
}
#endif
#if 0
/*
纯虚函数:
virtual 函数类型是函数名(参数表)=0;
与虚函数成员的原型在书写格式上的不同就在于后面加了"=0"。
声明为纯虚函数后，基类中就可以不再给出函数的染实现部分，纯虚函数的函数体由派生类给出.
基类中人然允许对纯虚函数给出实现，但即使给出实现，也必须由派生类覆盖，否则无法实例化。在基类中对纯虚函数定义的函数体的调用，必须通过"基类名::汉化素名(参数表)"的形式。如果将析构函数声明为纯虚函数，必须给出它的实现，因为派生类的析构函数体执行完后需要调用基类的纯虚函数.

*/

#endif
#if 0
class Base1 //基类Base1定义
{
 public:
	virtual void display() const = 0; //纯虚函数
};
class Base2:public Base1
{
 public:
	void display() const;
};
void Base2::display() const
{
 cout<<"Base2::display()"<<endl;
}
class Derived:public Base2
{
 public:
	void display() const;
};
void Derived::display() const
{
 cout<<"Derived::display()"<<endl;
}
void fun(Base1 *ptr)
{
 ptr -> display();
}
int main()
{
 Base2 base2;
 Derived derived;
 fun(&base2);
 fun(&derived);

 return 0;
}
#endif
#if 0
class D
{
	public:
		void print(){}
		int m_i;
};
class A:virtual public D
{
};
class B:virtual public D
{

};
class C:public A,public B
{

};
int main()
{
	int *p;
	cout<<sizeof(int)<<endl;
	cout<<sizeof(p)<<endl;
	cout<<sizeof(D)<<endl;//考虑对齐
	cout<<sizeof(B)<<endl;
	cout<<sizeof(C)<<endl;
	return 0;
}
#endif
#if 0
int  fn1(int n);
int  fn2(int n);
int main()
{

	reutrn 0;
}
int fn1(int n)
{
	return 0;
}
int (*p) fn2(int n)
{
	return n+
}
#endif
#if 0
class A
{
	public:
		A(){}
};
int main()
{
	A a;
	return 0;
}
#endif
/*
题目:求1+2+...+n,要求不能使用乘除法，for,while,if,else,switch,case等关键字及条件判断语句(A?B:C)
	这个问题本身没有太多的实际意义，但不少面试官认为这个可以考察应聘者发散思维能力的题目，而发散思维能够反映出应聘者知识面
的宽度，以及对编程相关技术理解的深度。
	通常求1+2+..+n除了用公式n(n+1)/2之外，无外乎循环和递归两种思想，由于已经明确限制for和while的使用，循环已经不能再用了。
递归函数也需要用if语句或者条件判断语句来判断是继续递归下去还是终止递归，但现在题目已经补允许使用这两种语句了。
*/
/*	
	解法一:利用构造函数求解
	我们仍然围绕循环做文章，循环只是让相同的代码重复执行n遍而已，我们完全可以不用for和while来达到这个效果。比如我们先定义
一个类型，接着创建n个该类型的实例，那么这个类型的构造函数将确定会被调用n次。我们可以将与累加相关的代码放到构造函数里面里。
*/
#if 0
int Sum_Solution1(int n);
class Temp
{
 public:
 	Temp() { ++N;Sum += N; }
	int GetSum() const { return Sum; }
 private:
 	static int N;
	static int Sum;
};
int Temp::N = 0;
int Temp::Sum = 0;
int main()
{
	cout<<"sum="<<Sum_Solution1(100)<<endl;
	return 0;
}
int Sum_Solution1(int n)
{
	Temp *a = new Temp[n];
	delete []a;
	a = NULL;
	return a->GetSum();
}
#endif
/*
	 解法二:利用虚函数求解
	 我们同样也可以围绕递归做文章。既然不能在一个函数中判断是不是应该终止递归，那么我们不妨定义两个函数，一个函数充当递归函数
的角色，另一个函数处理终止递归的情况，我们需要做的是在两个函数里二选一。从二选一我们很自然的想到布尔变量，比如值为true(1)的时候
调用第一个函数，值为false(0)的时候调用第二个函数。那现在的问题是如何把数值变量n转换为布尔值。如果对n连续做两次反运算，即!!n
,那么非零的n转换为true，0转换为false。
*/
#if 0
int Sum_Solution2(int n);
class A;
A *Array[2];
class A
{
 public:
 	virtual int Sum(int n)
	 	{
			 return 0;
		}
};
class B:public A
{
 public:
 	virtual int Sum(int n)
	 {
		 return Array[!!n]->Sum(n-1) + n;
	 }
};
int main()
{
	cout<<"SUM="<<Sum_Solution2(100)<<endl;
	return 0;
}
int Sum_Solution2(int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	int value = Array[1]->Sum(n);
	return value;
}
#endif
/*
	解法三:利用函数指针求解
	在纯C语言的编程环境中，我们不能使用虚函数，此时可以用函数指针来模拟，这样代码可能还更加直观一些。
*/
 #if 0
 #include<stdio.h>
 typedef int (*fun) (int);
 int Sum_Solution3_Teminator(int n)
 {
	 return 0;
 }
 int Sum_Solution3(int n)
 {
	 fun f[2] = {Sum_Solution3_Teminator,Sum_Solution3};
	 return n + f[!!n]( n - 1 );
 }
 int main()
 {
	 printf("sum=%d\n",Sum_Solution3(100));
	 return 0;
 }
#endif






