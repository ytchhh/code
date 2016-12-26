#include<iostream>
using namespace std;
#if 0
/*
在一个文件中定义一个全局变量n，主函数main(),在另外一个文件中定义函数fn1()，在main()中对n赋值，再调用fn1(),在fn1中也对n赋值，显示n最后的值。
*/
int n;
void fn1()
{
 n = 6;
}
int main()
{
 n =7;
 fn1();
 cout<<n<<endl;
 return 0;
}
#endif
#if 0
/*
定义类X,Y,Z,函数h(X),满足:类X有私有成员i，Y的成员函数g(X)是X的友元函数，实现对X的成员i加1,类Z是类X的友元类，其成员函数f(X)实现对X的成员i加5,函数h(X)是X的友元函数，实现对X的成员加10,在一个文件中定义和实现类，在另一个文件中实现main函数。
*/
class X;
class Y
{
public:
  void g(X &x); 
private:
  int y;
};

class Z
{
 public:
    void f(X &x); 
 private:
    int z;
};
class X
{
public:
   X(int j = 0):i(j){}
   friend void Y::g(X &x);
   friend class Z;
   friend void h(X &x);
   void print(){cout<<i<<endl;}
private:
   int i;
};
void Z::f(X &x)
{
 x.i+=5;
}
void h(X &x)
{
 x.i+=10;
}
void Y::g(X &x)
{
 x.i+=1;
}

int main()
{
 X x(10);
 x.print();
 Y y;
 y.g(x);
 x.print();
 Z z;
 z.f(x);
 x.print();
 h(x);
 x.print();
 return 0;
}
#endif
#if 0
/*
定义一个Boat与Car两个类，两者都有weight属性，定义二者的一个友元函数，getTotalWeight(),计算二者的重量和。
*/
class Car;
class Boat 
{
 public:
    Boat(int i = 0):weight(i){}
	friend void add(Boat &a,Car &b);
 private:
    int weight;
};
class Car
{
 public:
     Car(int i = 0):weight1(i){}
     friend void add(Boat &a,Car &b);
 private:
   int weight1;
};
void add(Boat &a,Car &b)
{
 cout<<a.weight+b.weight1<<endl;
}
int main()
{
 Boat a(5);
 Car b(7);
 add(a,b);
 return 0;
}
#endif

#if 0

class A
{
 public:
   A(int i = 0,int j = 0){cout<<"A"<<i<<j<<endl;} 
   ~A(){cout<<"!"<<endl;}
 private:
   
};
int main()
{
 //A a[5] = {A(1,2),A(3,4),A(4,5),A(5,6)};
 A *p = new A[5];
 delete []p;
 return 0;
}
#endif
#if 0
class A
{
 public:
    void print(){cout<<"print"<<m_i<<m_j<<endl;}
    static void test(int i){cout<<"test"<<i<<endl;}
	int m_i;
	static int m_j;
 private:
    
};
int A::m_j;
int main()
{
 /*
 int *p = NULL;
 A a;
 p = &a.m_i; //对于普通的数据成员需要有对象才能给指针赋值
 *p = 7;
 a.print();
 p = &A::m_j;//而静态的成员不同，在定义的时候就被初始化了，所以不需要明确对象
 *p = 9;
 a.print();
 */
 void (A::*p)();//先定义p是一个指向函数的指针
 p = &A::print; //将p指向其成员函数
 A a;
 (a.*p)();  //*p 就是 print

 void (*p1)(int);
 p1 = &A::test;
 p1(4);  //这儿采用 p1 或者 *p1 都是可行的
 return 0;
}
#endif
#if 0
#include<vector>//使用vector的头文件
#include<algorithm>//算法的头文件
#include<iterator> //迭代器
#include<functional>//可以调用各种实体库
int main()
{
 /*
 vector<int>a;
 copy(istream_iterator<int>(cin),istream_iterator<int>(),back_insert_iterator < vector<int> >(a));
 sort(a.begin(),a.end());
 copy(a.begin(),a.end(),ostream_iterator<int>(cout," "));
 cout<<endl;
 */
 int a[] = {5,4,3,1,2,6,7,8,9,0};
 int n = sizeof(a)/sizeof(a[0]);
 sort(a,a+n,greater<int>());//加入greater后就是进行逆序排列，不加的话默认为从小到大排序
 for (int i = 0;i < n; ++i)
     cout<<a[i]<<" ";
 cout<<endl;
 return 0;
} 
#endif
#if 0
#include<vector>
#include<algorithm>
#include<iterator>
#include<functional>
int main()
{ 
 int i;
 int data[10] = {1,2,3,4,5,6,7,8,9,88};
 vector<int> a;
 vector<int> b(10,8);
 vector<int> c(data,data+10);
 vector<int> d(c);
 copy(b.begin(),b.end(),ostream_iterator<int>(cout," "));//begin是刚开始的第一个地址,end是数组最后一个地址。
 a.assign(data+4,data+6);//assgin是将里面的值重新覆盖
 cout<<*c.begin()<<endl;
 
 copy(a.begin(),a.end(),ostream_iterator<int>(cout,","));
 cout<<endl;

 b.assign(5,0);
 copy(b.begin(),b.end(),ostream_iterator<int>(cout," "));
 cout<<endl;
 
 cout<<c.at(5)<<endl; //c[5] at如果越界的话，就会抛出一个异常
 
 c.clear();//将里面的元素清空
 if (c.empty())//查看C是否为空
	  cout<<"C is empty"<<endl;
 
 c.push_back(11);//相c里面压东西
 c.push_back(22);
 copy(c.begin(),c.end(),ostream_iterator<int>(cout," "));
 cout<<endl;

 cout<<c.size()<<endl;//c的大小
 c.pop_back();//向外面弹出
 cout<<c.size()<<endl;
 
 cout<<c.front()<<endl;//front和back就是当前的元素

 c.swap(d);//swap就是直接将两个进行交换
 copy(c.begin(),c.end(),ostream_iterator<int>(cout," "));
 cout<<endl;
 /*
 rbegin 和 rend 是和 begin,end相反的顺序,
 */
 return 0;
}
#endif
#if 0
#include<string>
int main()
{
 string a = "1234";
 string b("qwer");
 string c = a + b;
 cout<<c<<endl;
 cout<<c[4]<<endl;
 return 0;
}
#endif
#if 0
/*
声明一个有5个元素的int型数组,在程序中提示用户输入元素值，最后在屏幕上显示出来
*/
#include<iomanip>
int main()
{
 int a[5];
 int i;
 cout<<"input five numbers:"<<endl;
 for ( i = 0; i < 5; ++i)
     cin>>a[i];
 for (i = 0; i < 5; ++i)
     cout<<a[i]<<" ";
	 cout<<endl;
 return 0;
}
#endif
#if 0
/*
在程序中声明一个double类型变量的指针，分别显示指针占了多少字节，和指针所指向的变量占了多少字节。
*/

int main()
{ 
 double *p1 = NULL;
 cout<<sizeof(p1)<<","<<sizeof(p1)<<endl;
 return 0;
}
#endif
#if 0
/*
声明一个int型变量a，一个int型指针p，一个引用r,通过p把a的值该位10,通过r把a的值改为5.
*/
int main()
{
 int a = 5;
 int *p = &a;
 int &r = a;
 *p = 10;
 cout<<a<<endl;
 r = 5;
 cout<<a<<endl;
 return 0;
}
#endif
#if 0
int fn1()
{
 int *p = new int (5);
 return *p;
}
int main()
{
 int *p;
 int a = fn1();
 cout<<"the value of a is:"<<a;
 delete p;
 return 0;
}
#endif
#if 0
/*
声明一个参数为int型，返回值为long型的函数指针，声明类A的一个成员函数指针，其参数为int型，返回值为long型。
*/
class A
{
 public:
   long fn(int i = 0){return 10*i;} 
 private:
   
};
int main()
{
 long (A::*p)(int);
 p = & A::fn;
 A a;
 cout<<(a.*p)(4)<<endl;
 return 0;
}
#endif
#if 0
/*
实现一个名为SimpleCircle的简单圆类。其数据成员int*itsRadius为一个指向其半径值的指针，存放其半径值。设计对数据成员的各种操作，给出这个类的完整实现并测试这个类。
*/
const float PI = 3.1415; 
class SimCircle
{
 public:
   SimCircle(int i = 0)
   {
   *itsRadius = i;
   cout<<"!"<<endl;
   }
   float getPerimeter()//获得周长
   {
    return 2*PI*(*itsRadius);
   }
   float getArea() //获得面积
   {
    return PI*(*itsRadius)*(*itsRadius);
   }
   int getRadius()
   {
    return *itsRadius;
   }
   void setRadius(int Radius)
   {
    *itsRadius = Radius;
   }
 private:
   int *itsRadius;
};
int main()
{
 SimCircle a(10);
 cout<<a.getPerimeter()<<endl;
 cout<<a.getArea()<<endl;
 cout<<a.getRadius()<<endl;
 a.setRadius(5);
 cout<<a.getRadius()<<endl;
 return 0;
}
#endif
#if 0
/*
编写一个函数，统计一条英文句子中字母的个数，在主程序中实现输入输出
*/
int count(string a)
{
 int i,n = 0;
 for (i = 0; a[i] != '\0'; i++)
      if (a[i] >= 'a' && a[i] <= 'z'|| (a[i] >= 'A' && a[i] <= 'Z'))
           n++;
  return n; 
}
int main()
{
 string a;
 cout<<"请输入一个字符串:"<<endl;
 cin>>a;
 cout<<"字母的个数:"<<count(a)<<endl;
 return 0;
}
#endif
#if 0
/*
编写函数 void reverse(string &a),用递归算法使字符串s倒序
*/
void reverse(string &s)
{
 int i,n=0;
 char c;
 for (i = 0; s[i] != '\0'; ++i)
      n++;
 for (i = 0; i<n/2; ++i)
 {
 c = s[i];
 s[i] = s[n-i-1];
 s[n-i-1] = c;
 }
}
int main()
{
 string a = "abcdefghj";
 reverse(a);
 cout<<a<<endl;
}
#endif
#if 0
/*
设学生人数 N = 8,提示用户输入N个人的考试成绩，然后计算出N个人的考试成绩，然后计算出他们的平均成绩。并显示出来。
*/
int main()
{
 int a[8];
 cout<<"请输入8个人的考试成绩:"<<endl;
 int i;
 for (i = 0; i < 8; ++i)
     cin>>a[i];
 int sum = 0;
 for (i = 0; i < 8; ++i)
     sum+= a[i];
 cout<<"平均分:"<<sum/8<<endl;
 return 0;
}
#endif
#if 0
/* 基于char*设计一个字符串类MyString,并且具有构造函数，析构函数，复制函数，重载函数，重载运算符"+","=","+=","[]", 尽可能完善它，使之能满足各种需要。
*/
#include<string.h>
class Mystring
{
 public:
   Mystring(void);
   Mystring(char *s);
   ~Mystring();
   Mystring(const Mystring &p );
   const Mystring operator +(const Mystring &p);
   void print(){cout<<str<<endl;}
 private:
   char *str;
   int len;
};
Mystring::Mystring(void)
{
 str = new char;
 str[0] = '\0';
 len = 0;
}
Mystring::Mystring(char *s)//构造函数
{
 int size = strlen(s);
 str = new char[size+1];
 str[size] = '\0';
 strcpy(str,s);
 len = size;
 cout<<"构造"<<endl;
}
Mystring::Mystring(const Mystring &p)//拷贝构造函数
{
 len = p.len;
 str = new char[len+1];
 str[len] = '\0';
 strcpy(str,p.str);
 cout<<"拷贝"<<endl;
}
const Mystring Mystring::operator +(const Mystring &p)//运算符+
{
 int newlen = len + p.len;
 char *newstr = new char[newlen+1];
 newstr[newlen] = '\0';
 strcpy(newstr,str);
 strcpy(newstr+len,p.str);
 return Mystring(newstr);
}
Mystring::~Mystring()//析构函数
{
 delete str;
 cout<<"!"<<endl;
}
int main()
{
 Mystring a("1234"),b("5678");
 a.print();
 Mystring c(a);
 c.print();
 //Mystring d = operator +(a,b);
 //d.print();
 //cout<<Mystring(b)<<endl;
 //cout<<a+b<<endl;
 return 0;
}
#endif
#if 0
/*
编写一个3×3的矩阵转制的函数，在main()函数中输入数据
*/
void invert(int a[][3])
{
 int i,j,t;
 for (i = 0; i < 3; ++i)
      for (j = 0; j <= i; ++j)
      {
	   t = a[i][j];
	   a[i][j] = a[j][i];
	   a[j][i] = t;	  
	  }	
}
int main()
{
 int a[3][3];
 int i,j;
 for (i = 0; i < 3; ++i)
     for (j = 0; j <3; ++j)
         cin>>a[i][j];
  invert(a);
  for (i = 0; i < 3; ++i){
       for (j = 0; j < 3; ++j)
       cout<<a[i][j]<<" ";
       cout<<endl;
   }
 return 0;	
}

#endif
#if 0
/*
编写一个矩阵转制的函数，矩阵的行数和列数在程序中输入
*/
void invert(int *a,int c,int l)
{
 int i,j,t;
 for (i = 0; i < c; ++i)
     for (j = 0; j <= i; ++j)
         {
		  t = *(a+i*c+j);
		  *(a+i*c+j) = *(a+j*c+i);
		  *(a+j*c+i) = t;
		 }
}
int main()
{
 int c,l;
 cout<<"请输入行数:";
 cin>>c;
 cout<<endl<<"请输入列数:";
 cin>>l;
 cout<<endl;
 int a[c][l];
 int i,j;
 cout<<"请输入数据:"<<endl;
 for (i = 0; i < c; ++i)
     for (j = 0; j < l; ++j)
	     cin>>a[i][j];
 invert(&a[0][0],c,l);
 for (i = 0; i < c; ++i)
 {
     for (j = 0; j < l; ++j)
	     cout<<a[i][j];
		 cout<<endl;
 }
 return 0;
}
#endif
#if 0
/*
定义一个Employee类，其中包括表示姓名，地址，城市和邮编等属性，包括setName()和display()等函数。display()使用cout语句显示姓名，地址，城市和邮编等属性，函数setName()改变对象的姓名属性，实现并测试这个类。
*/
#include<string.h>
#include<string>
class Employee
{
 public:
    Employee(string n = "",string a = "",string c = "",string c1 = ""):name(n),address(a),city(c),code(c1){}
	void setname(string c);
	void display();
 private:
   string name;
   string address;
   string city;
   string code;
};
void Employee::setname(string c)
{
 name = c;
}
void Employee::display()
{
 cout<<name<<" "<<address<<" "<<city<<" "<<code<<endl;
}
int main()
{
 Employee a("yang","xian","city","23455");
 a.display();
 a.setname("wang");
 a.display();
 return 0;
}
#endif
#if 1
/*

*/
#endif























