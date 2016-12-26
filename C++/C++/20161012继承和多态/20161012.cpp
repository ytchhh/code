#include<iostream>
using namespace std;
#if 0
class A
{
 public:
    A(){}
    int m_i;
 protected:
    int m_j;
 private:
    int m_k;
};
class B:public A
{
 public:
    void print()
    {
        m_i = 5;
        m_j = 6;
    //    m_k = 7;
    }
};
class C:public B
{

};
int main()
{
    B b;
    b.print();
    b.m_i = 6;
   // b.m_j = 6;
    //b.m_k = 7;
    return 0;
}
#endif
/*
            public      protected   private
public      public      protected   private
protected   protected   protected   不可访问
private     不可访问     不可访问
*/
#if 0
class A
{
 public:
    A(int i = 0){cout<<"A"<<endl;}
    void print(){cout<<"A:print"<<endl;}
};
class B:public A
{
 public:
    B(int i){cout<<"B"<<endl;}
    void print(){cout<<"B:print"<<endl;}
    void fn(){cout<<"fn"<<endl;}
};
//捆绑，联编
//早捆绑，静态联编
int main()
{
    B b(5);
   // a.print();
    b.print();
    return 0;
}
#endif
#if 0
/*
 基类指针可以指向子类对象，向下兼容，
 虚函数是可以被继承的，且无论虚基类个数，空间大小只占4个字节。
 但必须是继承关系，基类函数必须要带虚，必须是基类指针或者基类引用指向派生类。
 指针指向虚表的首地址
 eg:

    A:fn1()     B:fn1()
    A:fn2()     A:fn2()
    A:fn3()     B:fn3()
    A:fn4()     B:fn3()
在子类继承基类的虚函数时，会自动继承其虚函数。
*/
class A
{
 public:
    A(int n):flag(n){}
    virtual void fn1(){cout<<"A::fn1"<<endl;}
    virtual void fn2(){cout<<"A::fn2"<<endl;}
    virtual void fn3(){cout<<"A::fn3"<<endl;}
    virtual void fn4(){cout<<"A::fn4"<<endl;}
    void fn5(){cout<<"A::fn1"<<endl;}
    void fn6(){cout<<"A::fn2"<<endl;}
    int flag;
};
class B:public A
{
 public:
    B(int i):A(i){} 
    void fn1(){cout<<"B:fn1"<<endl;}
    virtual void fn3(){cout<<"B:fn3"<<endl;}
    virtual void fn4(){cout<<"B:fn4"<<endl;}
    virtual void fn7(){cout<<"A:fn3"<<endl;}
    void fn8(){cout<<"A::fn4"<<endl;}
};
/*
void test(A &p)
{
    p.fn1();
    p.fn2();
    p.fn3();
    p.fn4();
}
*/
void test(A &p)
{
    switch(p.flag)
    {
        case 0:((A&)p).fn1();break;
        case 1:((B&)p).fn1();break;
    }
}
int main()
{
    /*
    A a;
    B b;
    test(a);
    test(b);
    cout<<sizeof(A)<<endl;
    */
    A a(0);
    B b(1);
    test(a);
    test(b);
    return 0;
}
#endif
#if 0
class A
{
    public:
        A(){cout<<"A"<<endl;}
};
class B:public A
{
    public:
        B(){cout<<"B"<<endl;}
};
class C
{
    public:
        C(){cout<<"C"<<endl;}
};
class E:public C
{
    public:
        E(){cout<<"E"<<endl;}
};
class D:public A,virtual public B,public C
{
    public:
        D(){cout<<"D"<<endl;}
};
int main()
{
    D d;
    return 0;
}
#endif
#if 0
class D
{
    public:
        void print(){cout<<"D"<<endl;}
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
    C c;
    c.print();
    cout<<sizeof(B)<<endl;
    cout<<sizeof(C)<<endl;
    return 0;
}
#endif
/*
重载:
   成员函数被重载的特征:
   1.相同的范围(在同一个类中)
   2.函数名字相同
   3.参数不同
   4.virtual关键字可有可无
覆盖:
    1.不同的范围(分别位于派生类与基类)
    2.函数名字相同
    3.参数不同
    4.基类函数必须有virtual关键字
隐藏:
    1.如果派生类的函数与基类的函数同名，但是参数不同。此时，不论有无virtual关键字
，基类的函数将被隐藏。
    2.如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual关键字，、
此时，基类的函数被隐藏.(注意别与覆盖混淆)
*/
#if 0
class Shape
{
    public:
        Shape(){}
        virtual void c() = 0;
        virtual void s() = 0;
};
class Circle:public Shape
{
    public:
        void c(){cout<<"cc"<<endl;}
        void s(){cout<<"cs"<<endl;}
};
class Rectangle:public Shape
{
    public:
        void c(){cout<<"rc"<<endl;}
        void s(){cout<<"rs"<<endl;}
};
class Triangle:public Shape
{
    public:
        void c(){cout<<"rc"<<endl;}
        void s(){cout<<"ts"<<endl;}
};
int main()
{
    Shape *p[3];
    p[0] = new Circle;
    p[1] = new Rectangle;
    p[2] = new Triangle;
    for(int i = 0; i < 3; ++i)
        {
            p[i]->c();
            p[i]->s();
        }
    return 0;
}
#endif
/*
   关于构造函数的调用顺序:
1.调用基类构造函数，调用顺序按照它们被继承时声明的顺序(从左向右)。
2.对派生类新增的成员对象初始化，调用顺序按照它们在类中声明的顺序。
3.执行派生类的构造函数体中的内容。
  构造函数初始化列表中基类名，对象名之间的次序无关紧要，它们各自出现的顺序可以是任意的，无论它们的顺序怎样
安排，基类构造函数的调用和各个成员对象的初始化顺序都是确定的。
*/
/*
拷贝构造函数的调用顺序:
    要为派生类编写拷贝构造函数，一般需要为基类相应的拷贝构造函数传递参数。
    可以用派生类的对象去初始化基类的引用。
*/
/*
析构函数:
    在派生类的析构函数中，只要负责把派生类新增的非对象成员的清理工作做好就够了，系统会自己调用基类以及对象
成员的析构函数来对基类进行清理，
    它的执行顺序和构造函数的调用顺序刚好相反，首先执行派生类，再对基类。    
*/
/*
    使用虚基类和作用域分辨符可以解决在类的派生过程中二义性的问题。
    相比较而言，前者在派生类中拥有同名成员的多个副本，分别通过直接基类名来唯一标识，可以存放不同的数据，
进行不同的操作，后者只维护一份成员副本。相比之下，前者可以容纳更多的数据，而后者使用更为简洁，内存空间更为
节省。可以根据不同的需求来选用合适的方法。
*/
/*
    构造一个类的对象的一般顺序是:
(1)如果该类有直接或间接的虚基类，则先执行虚基类的构造函数。
(2)如果该类有其他基类，则按照它们在继承声明列表中出现的次序，分别执行它们的构造函数，但构造过程中，不再
    执行它们的虚基类的构造函数。
(3)按照在类定义中出现的次序，对派生类中新增的成员对象进行初始化。对于类类型的成员函数，如果出现在构造函
数初始化列表中，则以其中指定的参数执行构造函数，如未出现，则执行默认构造函数。对于基本数据类型的成员对
象，如果出现在构造函数的初始化列表中，则使用其中指定的值为其赋初值，否则什么也不做。
(4)执行构造函数的函数体
*/
/*
组合和继承其实反映了两种不同的对象关系。
    组合反映的是"有一个"的关系。如果类B中存在一个类A的内嵌对象，表示的是每一个B类型的对象都"有一个"A类型
的对象。A类型的对象与B类型的对象是部分与整体的关系。B类的对象虽然包括A类对象的全部内容，但本身并补包括A类
对象的接口。因为一般A类的对象会作为B类的私有成员存在，这样B类中内嵌的A类对象的对外接口会被B类隐藏起来，
这些接口只能被B类所用，而不会直接作为B类的对外接口。        
*/


