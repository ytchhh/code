#include<iostream>
using namespace std;//namespace是名空间，为了解决词语匮乏的情况
#if 0
struct data //在C++中，结构体可以为空，并且占一个字节
{

};
int main()
{
  cout<<sizeof(data)<<endl;//cout是输出运算符，也是一种对象，endl是结束并且换行的标志

  return 0;
}
#endif
#if 0 //类：将不同类型的数据以及与这些数据相关的操作封装在一起构成一个集合，它是抽象的。
      //在内存里面不占空间。
// public,protected,private
class A
{
 int a;
 static int b;
 void print(){}  //普通的函数是不占空间的
 virtual void test1(){}  //所有的虚函数只占4个字节，因为其形成的是虚指针
 virtual void put(){}  //
};
int main()
{
  cout<<sizeof(A)<<endl;
  return 0;
}
#endif
#if 0
/*
函数重载：(给同一个名字赋予不同的含义)
1.函数名必须相同（同一个类）；
2.函数参数列表不同（参数个数，参数类型，参数顺序）;
3.和函数返回类型无关;
4.常成员函数可以构成重载（函数后面带有const）
*/
/*
 带有默认值的函数：
 1.默认值建议只在声明时，定义时不重新定义
 2.如果一个参数带默认值，其后的参数必须带默认值。
*/
/*
内联函数：
代码比较短小，函数功能比较简单，就可以作为内联函数来编译
inline : 程序员写inline只是个建议，编译器会根据实际情况来判断是否执行
*/
class clock
{
public:
  void set(int h = 0,int m = 0,int s = 0);
  void show()
  {
    cout<<m_hour<<":"<<m_minute<<":"<<m_second<<endl;
  }
private:
  int m_hour;
  int m_minute;
  int m_second;
};
int main()
{
class clock c,d,e,f;
c.set();
c.show();
d.set(1);
d.show();
e.set(1,2);
e.show();
f.set(1,2,3);
f.show();
}
void clock::set(int h,int m,int s)
{
 m_hour = h;
 m_minute  = m;
 m_second = s;
}
#endif
#if  0
class clock
{
 public:
void set();
void set(int h);
void set(int h,int m);
void set(int h,int m,int s);
void set()const;
void show()
{
 cout<<hour<<":"<<minute<<":"<<second<<endl;
}
private:
  int hour;
  int minute;
  int second;
};
void clock::set()
{
 hour = 5;
 minute =6;
 second = 7;
}
void clock::set(int h)
{
 hour = h;
 minute = 6;
 second = 7;
}
void clock::set(int h,int m)
{
 hour = h;
 minute = m;
 second = 7;
}
void clock::set(int h,int m,int s)
{
 hour = h;
 minute = m;
 second = s;
}
int main()
{
 class clock c,d,e,f;
 c.set();
 c.show();
 d.set(1);
 d.show();
 e.set(1,2);
 e.show();
 f.set(1,2,3);
 f.show();
}
#endif
#if 0
class clock
{
public:
  void set(int h = 0, int m = 0, int s = 0);
  void show();
private:
  int hour;
  int minute;
  int second;
};
void clock::set(int h,int m,int s)
{
 hour = h;
 minute = m;
 second = s;
}
int main()
{
  class clock d;
  d.set();
  d.show();
 return 0;
}
void clock::show()
  {
    cout<<hour<<":"<<minute<<":"<<second<<":"<<endl;
  }
#endif
#if 1
int main()
{
cout<<"hello!"<<endl;
cout<<"wecome to c++!"<<endl;
return 0;  
}
#endif
