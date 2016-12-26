#include<iostream>
using namespace std;

#if 0
/*
    模板的效率并不是很高，因为其中产生了很多的函数。一直调用会会不停的压栈，出栈。
    由函数的返回值并不能推测其函数值
*/
template<class T>
T Max(T a,T b)
{
    return a > b ? a : b;
}
int main()
{
    cout<<Max(1,2)<<endl;
    cout<<Max('A','X')<<endl;
    cout<<Max(1.2,2.3)<<endl;//小数默认为双精度浮点类型
    cout<<Max(1.2f,2.3f)<<endl;//加f后为单精度浮点类型
    return 0;
}
#endif

#if 0
template<class T,class T1,class T2>
T Max(T1 a,T2 b)
{
    return a > b ? a : b;
}
int main()
{
    cout<<Max<int,int,double>(1,2.1)<<endl;
    return 0;
}
#endif

#if 0
class Test;
ostream& operator<<(ostream &out,const Test &t);
class Test
/*
    在一个类里面，默认存在的有6个函数,分别为:
    构造函数，拷贝函数，赋值函数，析构函数，取址重载运算符，常成员函数。
*/
{
    friend ostream& operator<<(ostream &out,const Test &t);
    public:
        Test(int d = 0):data(d){}
        Test& operator=(const Test &t){}
        ~Test(){}
        bool operator>(const Test &t)
        {return data > t.data;}
        bool operator<=(const Test &t)
        //{return data <= t.data;}虽然在写法上看起来相对简单，但是要尽量遵从后面的函数要利用前面所写的函数，能够避免错误的出现
        {return !(*this>t);}
    private:
        int data;
};
ostream& operator<<(ostream &out,const Test &t)
{
    out<<t.data;
    return out;//此时的返回值是为了后面的连续赋值。
}
template<class T>
T Max(T a,T b)
{
    return a > b ? a : b;
}
int main()
{
    Test t1(10);
    Test t2(20);
    cout<<Max(t1,t2)<<endl;
    return 0;
}
#endif

#if 0
class Test
//此为一个类里面默认存在的六个函数
{
    public:
        Test(int d = 0):data(d)
        //构造函数
        {
            cout<<"Create Test Object:"<<this<<endl;
        }
        Test(const Test &t)
        //拷贝构造函数
        {
            cout<<"Copy Create Test Object"<<this<<endl;
        }
        Test& operator=(const Test &t)
        //赋值函数
        {
            cout<<"Assgin:"<<this<<" = "<<endl;
            if(this != &t)
            //赋值的时候要看是否是给自己本身赋值,以后写的时候都要自己注意添加。
            {
                data = t.data;
            }
            return *this;
        }
        ~Test()
        //析构函数
        {
            cout<<"Free Test Object :"<<this<<endl;
        }
        Test* operator&()
        //取址运算符
        {
            return this;
        }
        const Test* operator&()const
        //常成员函数
        {
            return this;
        }
    private:
        int data;
};
int main()
{
    //const Test t1(100);
    //const Test *pt = &t1;
    Test t1(100);
    Test t2;
    Test t3;
    t3 = t2 = t1;
    return 0;
}
#endif

#if 0
struct Test
{
    int a;
    struct iterator
    {
        int c;
        struct tt
        {
            int x;
            int y;
        };
        int e;
    };
    double d;
};
int main()
{
    Test t;
    cout<<sizeof(Test)<<endl;//会有一个字节对齐的情况
    t.a = 10;
    t.d = 12.34;
    Test::iterator::tt it; //使用作用域分辨符可以灵活的调用各种类和对象
    it.x = 5;
    return 0;
}
#endif

#if 1
#include<assert.h>

int main()
{
    int *p = (int*)malloc(sizeof(int)*10);
    
    return 0;
}
#endif
