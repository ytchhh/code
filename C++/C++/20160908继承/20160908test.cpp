#include<iostream>
using namespace std;
#if 1
/*
派生类的扎定义方法为:
  class 派生类名站:继承方式 基类名1,继承方式 基类名2~~~,继承方式 基类名n
  {
   派生类成员声明;
  };
*/
/*
class Derived:public Base1,private Base2
{
 public:
    Derived();
	~Derived();
};
*/
/*
一个派生类，可以同时有多个基类，这种情况称为多继承。
一个派生类只有一个直接基类的情况，称为单继承。
在类族中，直接参与派生出某类的基类称为直接基类
基类的基类甚至更高层的基类称为间接基类。
继承方式规定了如何访问从基类继承的成员
如果不显式的给出继承方式，系统默认为私有继承。
派生类成员是指从基类继承来的所有成员之外，新增加的数据和函数成员。
*/
#endif
#if 0
/*
从之前的普通账户过渡来的信用账户。
*/
class Account
{
 private:
    std::string id;
	double balance;
	static double total;
 protected:
    Account(const Date &date,const std::string &id);
	void record(const Date &date,double amount,const std::string &desc);
	void error(const std::string 8msg) const;
 public:
    const std::string &getId() const{return id;}
	double getBalance() const {return balance;}
	static double getTotal(){return total;}
	void show() const;
};
class CreditAccount:public Account
{
 private:
    Accumulator acc;  //辅助计算利息的累加器
	double credit;//信用额度
	double rate;  //欠款的日利率
	double fee;   //信用卡年费
	double getDebt() const;
 public;
    CreditAccount(const Date &date,const std::string &id,double credit,double rate,double fee);
	double getCredit() const;
	double getRate() const;
	double getFee() const;
	double getAvailableCredit();
	void deposit(const Date &date,double amount,const std::string &des);
	void withdraw(const Date &date,double amount,const std::string &des);
	void settle(const Date &date);
	void show() const;
};
/*
在C++的类继承中，上面的派生类CreditAccount继承了基类Account中除构造和析构函数之外的所有非静态成员,id,balance,record函数，error函数，getId函数，getBanlance函数，show函数。经过派生过程这些成员便存在于派生类之中。
隐藏：如果派生类声明了一个和某某类成员同名的新成员(如果是成员函数，则参数表也要相同，参数不同的情况属于重载)，派生类的新成员就隐藏了外层同名成员
*/
#endif
#if 0
/*
当类的继承方式为公有继承时，基类的公有成员和保护成员的访问属性在派生类中不变，而基类的私有成员不可直接访问。
*/
//Point类公有继承
#include<cmath>
#include"Rectangle.h"
int main()
{
 Rectangle rect;
 rect.initRectangle(2,3,20,10);
 rect.move(3,2);
 cout<<"The data of rect(x,y,w,h):"<<endl;
 cout<<rect.getX()<<","
 <<rect.getY()<<","
 <<rect.getW()<<","
 <<rect.getH()<<endl;
 return 0;
}
#endif
#if 0
/*
当类的继承方式为私有继承时，基类的公有成员和保护成员都以私有成员身份出现在派生类中，而基类的私有成员在派生类中不可直接访问
也就是说基类的公有成员和保护成员被继承后作为派生类的私有成员，派生类的其他成员可以直接访问它们，但是在类族外部通过派生类的对象无法直接访问它们，
*/
#include"Rectangle.h"
using namespace std;
int main()
{
	Retangle rect;
	rect.initRectangle(2,3,20,10);
	rect.move(3,2);
	cout<<"The data of rect(x,y,w,h):"<<endl;
	cout<<rect.getX()<<","
		<<rect.getY()<<","
		<<rect.getW()<<","
		<<rect.getH()<<endl;
	return 0;
}
/*
在私有继承情况下，为了保证基类的一部分外部接口特征能够在派生类中占也存在，就必须在派生类中重新声明同名的成员。
利用派生类对基类成员的访问能力，把基类的原有成员函数的功能照搬过来。
这种在派生类中重新声明的成员函数具有比基类同名成员函数更小的作用域，，因此在调用时，根据同名隐藏的原则，自然会使用派生类的函数。
*/
#endif
#if 0
/*
保护继承：
  保护继承中，基类的公有成员和保护成员都以保护成员的身份出现在派生类中，而基类的私有成员不可直接访问。这样，派生类的其他成员就可以直接访问从基类继承来的公有和保护成员，但在类外部通过派生类的对象无法直接访问它们，无论是派生类的成员还是派生类的对象都无法直接访问基类的私有成员。
*/
/*
class A
{
 protected:
	int x;
};
int main()
{
 A a;
 a.x = 5; //无法直接访问保护成员，其和私有成员一样
 return 0;
}
*/
class A
{
 public:
    void print(){cout<<x<<endl;}
 protected:
	int x;
};
class B:public A
{
 public:
   void function();
   void print(){cout<<x<<endl;}
};
void B::function()
{
 x = 5;
}
int main()
{
 B b;
 A a;
 b.function();
 b.print();
 a.print();
 return 0;
}
#endif
#if 0
/*
类型兼容规则
   类型兼容规则是指需要基类对象的任何地方,都可以使用公有派生类的对象来替代。通过公有继承，派生类得到了基类除构造函数，析构函数之外的所有成员。这样，公有派生类实际就具备了基类的所有功能，凡是基类能解决的问题，公有派生类都可以解决。类型兼容规则中所指的替代包括以下的情况。
   1.派生类的对象可以隐含转换为基类对象
   2.派生类的对象可以初始化基类的引用
   3.派生类的指针可以隐含转换为基类的指针。
在替代之后，派生类对象就可以作为基类的对象使用，但只能使用从基类继承的成员。
*/
/*
class B{}
class D:public B{}
B b1,*pb1;
D d1;
这个时候：
  1.派生类对象可以隐含转换为基类对象，即用派生类对象中从基类继承来的成员，逐个赋值给基类对象的成员。
   b1 = d1;
  2.派生类的对象也可以初始化基类对象的引用。
   B &rb = d1;
  3.派生类对象的地址也可以隐含转换为指向基类的指针
   pb1 = &d1;
*/
#endif
#if 0
class Base1
{
 public:
    void display() const {cout<<"Base1::display()"<<endl;}
};
class Base2:public Base1
{
 public:
    void display() const {cout<<"Base2::display()"<<endl;}
};
class Derived:public Base2
{
 void display() const {cout<<"Derived::display()"<<endl;}
};
void fun(Base1 *ptr)
{
 ptr -> display();
}
int main()
{
 Base1 base1;  //声明Base1类对象。
 Base2 base2;  //声明Base2类对象。
 Derived derived;//声明Derived类对象。
 fun(&base1);    //用Base1对象的指针。
 fun(&base2);    //用Base2对象的指针调用fun函数。
 fun(&derived);  //用Derived对象的指针调用fun函数。
 return 0;
}
/*
在程序中,声明了一个形參为基类Base1类型的普通函数fun，根据类型兼容规则，可以将公有派生类对象的地址赋值给基类类型的指针，这样，使用fun函数就可以统一对这个类族中的对象进行操作。程序运行过程中，分别把基类对象，派生类Base2的对象和派生类Derived的对象赋值给基类类型指针P,但是，通过指针p，只能使用继承下来的基类成员。也就是说，尽管指针指向派生类Derived的对象，fun函数运行时通过这个指针只能访问到Derived类从基类Base1继承过来的成员函数display，而不是Derived类自己的同名成员函数display，而不是类自己的同名成员函数。
*/
#endif
#if 0
/*
基类的构造函数和析构函数不能被继承，在派生类中，如果对派生类新增的成员进行初始化，就必须为派生类添加新的构造函数。但是派生类的构造函数只负责对派生类新增的成员进行初始化，对所有从基类继承下来的成员，其初始化工作还是由基类的构造函数完成。同样，对派生类对象扫尾，清理工作也需要加入新的析构函数。
*/
//在构造派生类的对象时，就要对基类的成员对象和新增成员对象进行初始化
/*
派生类名::派生类名(参数表):基类名站(基类1 初始化参数表)，...基类名n(基类n初始化参数表)，成员对象名站(成员对象1初始化 参数表)，...，成员对象名m(成员对象m初始化参数表)
{
 派生类构造函数的其他初始化操作;
}
*/
#include<iostream>
using namespace std;
class Base1
{
 public:
   Base1(int i){cout<<"Constructing Base1"<<i<<endl;}
};
class Base2
{
 public:
   Base2(int j){cout<<"Contructing Base2"<<j<<endl;}
};
class Base3
{
 public:
   Base3(){cout<<"Constructing Base3*"<<endl;}
};
class Derived:public Base2,public Base1,public  Base3
{  //派生新类Derived，注意基类名的顺序
 public:
	Derived(int a,int b,int c,int d):Base1(a),member2(d),member1(c),Base2(b)
	{}
	//注意基类名的个数与顺序，注意成员名的个数与顺序
 private:
	Base1 member1;
	Base2 member2;
	Base3 member3;
};
int main()
{ 
 Derived obj(1,2,3,4);
 return 0;
}
#endif
/*
基类构造函数的调用顺序是按照派生类定义时的顺序，因此应该是先Base2,再Base1,最后Base3，而内嵌对象的构造函数调用顺序应该是按照成员在类中声明的顺序，应该是先Base1,再Base2，最后base3。程序运行的结果也是这样。
*/
#if 0
class Base1
{
 public:
    Base1(int i){cout<<"Constructing Base1"<<i<<endl;}
	~Base1(){cout<<"Destructing Base1"<<endl;}
};
class Base2
{
 public:
	Base2(int j){cout<<"Constructing Base2"<<j<<endl;}
	~Base2(){cout<<"Destructing Base2"<<endl;}
};
class Base3
{
 public:
	Base3(){cout<<"Constructing Base3*"<<endl;}
	~Base3(){cout<<"Destructing Base3"<<endl;}
};
class Derived:public Base2,public Base1,public Base3
{   //在派生新类的时候，要注意基类名的顺序。
 public:
	Derived(int a,int b,int c,int d):Base1(a),member2(d),member1(c),Base2(b){}
 private:
	Base1 member1;
	Base2 member2;
	Base3 member3;
};
int main()
{
 Derived obj(1,2,3,4);
 return 0;
}
/*
析构函数的顺序刚好和构造函数的顺序相反，先执行派生类，在执行基类。
*/
#endif
#if 0
/*
对于在不同的作用域声明的标识符，可见性原则是：如果存在来嗯个或多个具有包含关系的作用域，外层声明了一个标识符，而内层没有再次声明同名标识符，那么外层标识符在内存中仍然可见。如果内层声明了同名标识符，则外层标识符在内层不可见，这时称内层标识符隐藏了外层同名标识符，这种现象称为隐藏规则。
在类的派生层次结构中，基类的成员和派生类新增的成员都具有类作用域。二者的作用范围不同，是相互包含的两个层，派生类在内层。这时，如果派生类声明了一个和某个基类成员同名的新成员，派生的新成员就隐藏了外层同名成员，直接使用成员名就只能访问到派生类的成员。如果派生类中声明了与基类成员函数同名的新函数，即使函数的参数不同，从基类继承的同名函数的所有重载形式也都会被隐藏。
*/
class Base1
{
 public:
	int var;
	void fun(){cout<<"Member of Base1"<<endl;}
};
class Base2
{
 public:
	int var;
	void fun(){cout<<"Mneber of Base2"<<endl;}
};
class Derived:public Base1,public Base2
{
 public:
	int var;
	void fun(){cout<<"Member of Derived"<<endl;}
};
int main()
{
 Derived d;
 Derived *p = &d;
 d.var = 1;//对象名，成员名标识
 d.fun();  //访问Derived类成员之

 d.Base1::var = 2;//作用域分辨符标识
 d.Base1::fun();//访问Base1基类成员

 p -> Base2::var = 3;//作用域分辨符标识
 p -> Base2::fun(); //访问Base2基类成员

 return 0;
}
#endif
/*
 如果希望d.var和d.fun()的用法补产生二义性，可以使用using关键字加以澄清。
 例如:
 class Derived:public Base1,public Base2
 {
  public:
	using Base1::var;
	using base1::fun;
 };
 这样d.var和d.fun()都可以明确表示对Base1中相关人员的引用了。using的一般功能是将一个作用域中的名字引入到另一个作用域中，它还有一个非常有用的方法：将usnig用于基类中的函数名，这样派生类中如果定义同名但参数不同的函数，基类的函数不会被隐藏，两个重载的函数会并存在派生类的作用域中。
 eg:
  class Derived:public Base1
  {
   using Base1::fun;
   void fun(int i){}
  };
  这时，使用Derived2的对象，既可以直接调用无參数的fun函数，又可以直接调用带int型参数的fun函数。
*/

#if 0
/*
如果某个派生类的部分或全部基类是从另一个共同的基类派生而来，在这些直接基类中，从上一级基类继承来的成员就拥有相同的名称，因此派生类中就会产生同名现象，对这种类型的同名成员也要是哦嗯作用域分辨符来唯一标识，而且必须用直接基类来进行限定。
*/
class Base0
{
 public:
	int var0;
	void fun0(){cout<<"Member of Base0"<<endl;}
};
class Base1:public Base0
{
 public:
	int var1;
};
class Base2:public Base0
{
 public:
	int var2;
};
class Derived:public Base1,public Base2
{
 public:
	int var;
	void fun(){cout<<"Menber of Derived"<<endl;}
};
int main()
{
 Derived d;
 d.Base1::var0 = 2;
 d.Base1::fun0();
 d.Base2::var0 = 3;
 d.Base2::fun0();
 return 0;
}
#endif
#if 0
/*
虚基类:
	将共同基类设置为虚基类，这时从不同的路径继承过来的同名数据成员在内存中就只有一个副本，同一个函数名也只有一个站映射。这样就解决了同名成员的唯一标识问题。
语法形式为：
class 派生类名:virtual 继承方式 基类名

*/
class Base0
{
 public:
	int var0;
	void fun0(){cout<<"Menber of Base0"<<endl;}
};
class Base1:virtual public Base0
{
 public:
	int var1;
};
class Base2:virtual public Base0
{
 public:
	int var2;
};
class Derived:public Base1,public Base2
{
 public:
	int var;
	void fun(){cout<<"Member of derived"<<endl;}
};
int main()
{ 
 Derived d;
 d.var0 = 2;
 d.fun0();
 return 0;
}
#endif
#if 1
/*
虚基类及其派生类构造函数
*/
class Base0
{
 public:
	Base0(int var):var0(var){}
	int var0;
	void fun0(){cout<<"Member of Base0"<<endl;}
};
class Base1:virtual public Base0
{
 public:
	Base1(int var):Base0(var){}
	int var1;
};
class Base2:virtual public Base0
{
 public:
	Base2(int var): Base0(var){}
	int var2;
};
class Derived:public Base1,public Base2
{
 public:
	Derived(int var): Base0(var),Base1(var),Base2(var){}
	int var;
	void fun(){cout<<"Member of Derived"<<endl;}
};
int main()
{
 Derived d(1);
 d.var = 2;
 d.fun();

 return 0;
}
#endif








