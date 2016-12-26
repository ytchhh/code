#include<iostream>sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
using namespace std;
/*
 this指针：非静态成员函数里面有个this指针，在用本类地向调用此成员函数的时候
将本对象的地址隐含的传递给了此this指针，因此在成员函数中对数据成员进行操作，
因此在成员函数中对数据成员进行操作，相当于对当前的数据成员进行操作。
例如：this->m_i
*/
#if 0
class A
{
 public:
 void init(int i = 0){this->m_i = i;}
 void print(){cout<<m_i<<endl;}
 private:
  int m_i;
};
int main()
{
 A a,b;
 a.init(5);
 a.print();
 b.init(7);
 b.print();
 return 0;
}
#endif
/*
  构造函数的作用就是在对象被创建时利用特定的值构造对象，将对象初始化位一个特定的状态。
  函数名和类名相同，可以有参数。
  函数没有返回类型(什么都不用写)
在类对象定义的时候自动被调用。
默认构造函数：如果一个类没有提供的构造函数，则本类有个默认的构造函数，
默认的构造函数无參，作用为：为本类的数据成员分配空间。
构造函数可以进行重载。
*/ 
#if 0
class A
{
  public: 
    A(int i = 0){m_i = i;cout<<"A"<<endl;}
  void print(){cout<<m_i<<endl;}
  private:
  int m_i;
};
int main()
{
 class A a(5);
 //class A a = 5; //这种写法虽然正确，但是不建议这样写。
 a.print();       //如果 A的前面有explicit 上面这种写法就是错误的
 return 0;
}
#endif
#if 0
class A
{
 public:
    A(int i = 0, int j = 0)
     {
      m_i = i;
      m_j = j;
     }
    void print(){cout<<m_i<<":"<<m_j<<endl;}
 private:
    int m_i,m_j; 
};
int main()
{
 A a(5),b(5,6);
 a.print();
 b.print();
 return 0;
}
#endif
/*
在有些情况下，如果类的成员函数需要在定义的时候就要赋值
就需要使用到冒号语法
*/
#if 0
class B
{
 public:
   B(int i = 0)
    {
     m_i = i;
     cout<<"B"<<m_i<<endl;
    }
private:
   int m_i;
};
class A
{
 public:               //相当于 int a = 6;
     A(int j = 0):b(j) //冒号语法 在定义的时候，调用构造函数，并把值赋进去
       {
        // b = j; //先遇到b的时候先调用构造函数，把j赋给给的时候也要调用
        cout<<"A"<<j<<endl; //因为j是整型，要将其转换为类类型
       }
private:
  B b;
};
int main()
{
 A a(5); //在调用的时候是先
 return 0;
}
#endif
#if 0
class A
{
 public:
  A(int i = 0,int j = 0):m_j(j),m_i(m_j)
     {                  //在冒号语法中，是根据成员的声明顺序开始初始化的
      //m_j = j;        //和写的顺序无关
      //m_i = m_j;
      cout<<m_i<<","<<m_j<<endl;
     }
 private:
 int m_i,m_j; 
};
int main()
{
 class A a(5,8);
 return 0;
}
#endif
#if 0
/*
引用;是一个实体的别名
1.引用必须在声明时初始化
2.引用不能为空
3.一旦声明一个引用，就不能修改，除非实体消失。
引用和指针的区别？
引用：
一个变量的别名，为什么引入别名呢？原因是我们想定义一个变量，它共享另一个变量
的内存空间。变量是一个内存空间的名字，如果我们给这个内存空间起另外一个名字，那就是我们能够共享这个内存，引用（别名）的由来。
指针：
指向另一个内存空间的变量，我们可以通过它来索引另一个内存空间的内容，它本身也有自己的内存空间。
区别：
引用访问一个变量是直接访问，而指针是间接访问
  引用是一个变量的别名，本身补单独分配自己的内存空间，而指针有自己的内存空间引用在开始的时候就绑定到了一个内存空间（开始必须赋初值），所以它只能是这段内存空间的名字，而不能改成其他的，当然可以改变这个内存空间的值。而指针在任何时候都可以改变自己的指向。
一旦和对象绑定，引用无法和其指示物分开，引用本身不是一个对象（它是没有标识的，当试图获得引用的地址时，你将得到它的指示物的地址。记住：引用就是它的指示物）
*/
void swap(int &a,int &b)
{
 int t = a;
 a = b;
 b = t;
}
int main()
{
 int a = 6;
 int b = 7;
 swap(a,b);
 cout<<a<<","<<b<<endl;
}

#endif
#if 0
class A
{
public:
    A(int i = 0):b(i)
    {
     cout<<b<<endl;
    }
private:
    int &b; //因为是引用，必须要在定义的时候初始化，所以只能使用冒号语法
 // const int b; //在C++中，为变量。 
};
int main()
{
 A a(5);
 return 0;
}
#endif
#if 0
/*
 析构函数：
函数名和类名相同，无參（不能重载），没有返回类型
一个类有且仅有一个析构函数
如果当前类里面没有指针作为数据成员，析构函数都可以不用程序员自己定义
*/
class A
{
 public:
     A(){cout<<"A"<<endl;}
    ~A(){cout<<"~A"<<endl;}
};
void test()
{
  A b;
}
int main()
{
 A a; //定义a的时候先调用构造函数。
 test();//先调用构造，函数结束的时候，再调用析构函数。
 cout<<"main end"<<endl;
 //主函数快要结束的时候，再调用析构函数将a释放掉。
 return 0;
}
#endif
#if 0
int main()
{
 
 returnn 0;
}
#endif
#include<stdlib.h>
#include<string.h>
#if 0
class STR
{
public:
   STR(char *str = "");
   ~STR();
   void print(){cout<<m_str<<endl;}
private:
   char *m_str;
};
STR::STR(char *str)
{
 m_str = (char*)malloc(strlen(str)+1);
 strcpy(m_str,str);
}
STR::~STR()
{
 if (m_str != NULL)
    {
     free(m_str);
     m_str = NULL;
    }
}
int main()
{
 STR a("12345");
 a.print();
 return 0;
}
#endif
#if 0
class STR
{
public:
    STR(char *str = "");
    void print(){cout<<m_str<<endl;}
private:
   char m_str[20];
};
STR::STR(char *str)
{
 int n = sizeof(m_str);
 strncpy(m_str,str,n-1);
 m_str[n-1] = '\0';
}
int main()
{
 STR a("1234567890123456789012345");
 a.print();
 return 0;
}
#endif
#if 0
class clock
{
 public:
     //  A(){} /*编译系统默认生成的构造函数 */
 clock(int newh, int newm, int news)
 {
 hour = newh;
 minute = newm;
 second = news;
 }
 void show()
 {
 cout<<hour<<":"<<minute<<":"<<second<<endl;
 } 
 private:
 int hour,minute,second;
}; 
int main()
{
 class clock a(0,0,0),b(1,2,3);
 a.show();
 b.show();
 return 0;
}
#endif
#if 1
#include<iomanip>
int main()
{
 cout<<setw(5)<<setprecision(3)<<3.1415<<endl;
 return 0;
}
#endif
