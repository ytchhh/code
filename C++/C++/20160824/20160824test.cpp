#include<iostream>
using namespace std;
/*
4.定义一个Dog类，包含了age，weight等属性，以及对这些属性操作的方法。实现并测试这个类。
*/
#if 0
class Dog
{
public:
  Dog(int nage = 0,int nweight = 0){age = nage;weight = nweight;}
  void print(){cout<<age<<","<<weight<<endl;}
private:
  int age,weight;
};
int main()
{
 Dog A(3,4);
 A.print();
 return 0;
}
#endif
#if 0
/*
5.设计并且测试一个名为Rectangle 的矩形类，其属性为矩形的左下角与右上角两个点的坐标，根据坐标能计算矩形的面积。
*/
class Rectangle
{
public:
   Rectangle(int a=0,int b=0,int c=0,int d=0)
   {
   s = (c-a)*(d-b);}
   void print(){cout<<s<<endl;}
private:
   int a,b,c,d;
   int s;
};
int main()
{
 class Rectangle A(1,2,3,4);
 A.print();
 return 0;
}
#endif
#if 1
/*
10
设计一个用于人事管理的人员类，由于考虑到通用性，只抽象出所有类成员都具有的属性，编号，性别，出生日期，身份证号码，其中出生日期声明为一个日期类内嵌子对象，用成员函数实现对人员信息的录入和显示。要求包括构造函数和析构函数，复制构造函数，内联成员函数，带默认形參值的成员函数，类的组合。
*/
#include<string.h>
class Date     //出生类
{
 public:
    Date(int myear = 0,int mmonths=0,int mday=0)
	{
	 cout<<"constructor"<<endl;
	 year = myear;
	 months = mmonths;
	 day = mday;
	}
	Date(Date &p);   //复制构造函数
	void show()
	{
	 cout<<"出生日期:"<<year<<","<<months<<","<<day<<endl;
	}
	~Date()
	{
	 cout<<"delete1"<<endl;
	}
 private:
    int year;
	int months;
	int day;
};
Date::Date(Date &p)
{
 year = p.year;
 months = p.months;
 day = p.day;
 cout<<"constructor1"<<endl;
}
class person //人员类
{
 public:
    person(int n,char s,int y,int m,int d,string i):number(n),sex(s),t(y,m,d),id(i)    //构造函数
	{
	 cout<<"construct"<<endl;
	}
	person(person &p);  //复制构造函数
	void print()
	{
	 cout<<"编号:"<<number<<"性别:"<<sex<<endl;
	 t.show(); 
	 cout<<"身份证:"<<id<<endl;
	}
	~person()
	{
	 cout<<"delete2"<<endl;
	}
 private:
    int number;
	char sex;
	Date t;
    string id;
};

person::person(person &p)//:number(p.number),sex(p.sex),t(p.t),id(p.id) //复制构造函数定义
{
 
 number = p.number; //如果使用赋值表达式的话，就是调用构造函数
 sex = p.sex;       //使用冒号表达式就是调用复制构造函数
 t = p.t;
 id = p.id;
 cout<<"copy constructor"<<endl;
}
int main()
{
 class person A(1,'m',7,20,34,"513701");
 A.print();
 class person B(A);
 B.print();
 return 0;
}
#endif
#if 1
/*
 
*/
#endif
#if 0
/*
定义一个矩形类，有长宽两个属性，由成员函数计算矩形的面积。
*/
class rectangle
{
 public:
    void count(int length=0,int width=0);
	void print(){cout<<area<<endl;}
 private:
    int length,width,area;
};
void rectangle::count(int length,int width)
{
 area = length*width;
}
int main()
{
 class rectangle A;
 A.count(4,5);
 A.print();
 return 0;
}
#endif
#if 0
/*
定义一个datatype类型，能处理字符型，整型，浮点型3种类型的数据，给出其构造函数
*/
class Datatype
{
public:
   
private:
   char c;
   int b;
   float d;
};
#endif
#if 0
/*
在类的操作的时候，应该多操作。
*/
class clock
{
 public:
    void settime(int mhour,int mminute,int msecond);
    void showtime(){cout<<hour<<":"<<minute<<":"<<second<<endl;}
 private:
    int hour,minute,second;
};
void clock::settime(int mhour,int mminute,int msecond)
{
 hour = mhour;
 minute = mminute;
 second = msecond;
}
int main()
{
 class clock A;
 A.settime(5,6,7);
 A.showtime();
 return 0;
}
#endif
#if  0// 计算游泳池问题
#define PI 3.141593
class Circle
{
 public:
    Circle(float r);
	float circumference();
	float area();
 private:
    float radius;
};
Circle::Circle(float r)
{
 radius = r;
}
float Circle::circumference()
{
 return 2*PI*radius;
}
float Circle::area()
{
 return PI*radius*radius;
}
int main()
 {
 float radius;
 cout<<"enter the radius of the pool:";
 cin>>radius;
 class Circle A(radius);
 float fenceCost = A.circumference()*35;
 cout<<"FenceCost is ￥"<<fenceCost<<endl;
 float concreteCost = A.area()*20;
 cout<<"ConcreteCost is ￥"<<concreteCost<<endl;
 return 0;
 }
#endif
#if 0
/*
使用类的组合，线段类。
我们使用一个类来描述线段，使用4.3节中的Point类的对象表示端点。这个问题可以用类的组合来解决，使Line类包括Point类的连个对象p1和p2，作为其数据成员。Line类具有计算线段长度的功能，在构造函数中实现。
*/
class Point
{
 public:
    Point(int xx = 0,int yy = 0)
	{
	 x = xx;
	 y = yy;
	}
 Point(Point &p);
 int getX(){return x;}
 int getY(){return y;}
private;
    int x,y;
};
 Point::Point(Point &p)
{
 x = p.x;
 y = p.y;
}

int main()
{
 
 return 0;
}
#endif
#if 0
//输入输出流控制
int main()
{
int a,b;
cin>>a>>b;
cout<<a<<b<<endl;
return 0;
}
#endif
#if 0
int main()
{
 
 return 0;
}
#endif






























