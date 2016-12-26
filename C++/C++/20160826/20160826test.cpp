#include<iostream>
using namespace std;
#if 0
#include<cmath>
/*
个人银行账户管理程序
*/
class SavingsAccount //´存储账户类
{
 public:
    SavingsAccount(int date,int id,double rate);//构造函数
	int getId(){return id;}
	double getBalance(){return balance;}
	double getRate(){return rate;}
	void deposit(int date,double amount);//存入现金
	void withdraw(int date,double amount);//取出现金
	void settle(int date); //结算利息，每年1月一日调用依次该函数
	void show(); //显示账户信息
 private:
    int id;  //帐号
	double balance; //余额
    double rate;   //存款的年利率
	int lastDate; //上次变更余额的时期
	double accumulation; //余额按日累计之加
	  //记录一笔账，date为日期，amount为金额，desc为说明
	void record(int date,double amount);
	  //获得到制定日期为止的存款金额按日累计值
	double accumulate(int date) const
	{
	    return accumulation+balance*(date-lastDate);
	}
};
SavingsAccount::SavingsAccount(int date,int id,double rate):id(id),balance(0),rate(rate),lastDate(date),accumulation(accumulation)//构造函数
{
 cout<<date<<"\t#"<<id<<"is created"<<endl;
}
void SavingsAccount::record(int date,double amount)
{
accumulation = accumulate(date);
lastDate = date;
amount = floor(amount * 100 +0.5)/100;//保留小数点后两位
balance+=amount;
cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}
void SavingsAccount::deposit(int date,double amount)
{
 record(date,amount);
}
void SavingsAccount::withdraw(int date,double amount)
{
 if (amount > getBalance())
     cout<<"error:not enough money"<<endl;
 else
    record(date,-amount);
}
void SavingsAccount::settle(int date)//计算年利息
{
 double interest = accumulate(date)*rate/365;
    if (interest != 0)
       record(date,interest);
    accumulation = 0;
}
void SavingsAccount::show()
{
 cout<<"#"<<id<<"\tBalance:"<<balance;
}
int main()
{
 SavingsAccount sa0(1,21325302,0.015);//建立几个账户
 SavingsAccount sa1(1,58320212,0.015);
 sa0.deposit(5,5000);
 sa1.deposit(25,10000);
 sa0.deposit(45,5500);
 sa1.withdraw(60,4000);//几笔帐目
 sa0.settle(90);//开户后90天到了银行的计息日，结算所有账户的年息
 sa1.settle(90);
 sa0.show();cout<<endl;//输出每个账户的信息
 sa1.show();cout<<endl;
 return 0;
}
#endif
#if 0
/*
枚举类型
  将变量的值一一列举出来，便构成了一个枚举类型。
定义：
   enum 枚举类型名 {变量值列表}
eg:
  enum weekday {sun,mon,wen,thu,fri,sat};
枚举类型说明:
  1.对枚举元素按常量处理，不能对他们赋值。
       eg:  sun = 0;
  2.枚举元素具有默认值，他们依次为：0,1,2,..
    sun = 0,mon = 1;
  3.也可以在声明时另行定义枚举元素的值，
    enum wekkday{sun = 7,mon = 1,tue,wed,thu,fri,sat};
	定义sun为7,mon为1,以后顺序加1,sat为6
  4.枚举值可以进行关系运算
  5.整数值不能直接赋给枚举变量，如需要将整数赋值给枚举变量，应进行强制类型转换
*/
/*
设某次体育比赛的结果只有4种可能，胜(WIN),负(LOSE),平局(TIE),比赛取消(CANCEL),编写程序输出这过程
*/
#include<iostream>
using namespace std;
enum GameResult{WIN,LOSE,TIE,CANCEL};
int main()
{
 enum GameResult result;
 enum GameResult omit = CANCEL;
   for (int count = WIN; count <= CANCEL; count++)
       {
	    result = GameResult(count);
		if (result == omit)
		   cout<<"The game was cancelled"<<endl;
		else
          {
		  cout<<"The game was played";
		     if (result == WIN)
			   {
			    cout<<"and we win"<<endl;
			   }
			 if (result == LOSE)
			   {
			    cout<<"and we lost"<<endl;
			   }
		  }
	   }
 return 0;
}
#endif
#if 0
/*
位域:
 数据类型说明符  成员名 ：位数;
 位域是 一种允许将类中的多个数据成员打包，从而使不同成员可以共享的字节机制.
 程序员可以通过冒号（：）后的位数来指定一个位域所占用的二进制位数，使用位域，应该注意：
 c++标准规定了使用这种机制来允许编译器将不同的的位域“打包”，但这种打包的具体方式，C++标准并没有规定，因此不同的编译器会有不同的处理方法，不同编译器下，包含位域的类所占用的空间也会有所不同。
 只有bool，char，int,enum，的成员才能够定义为位域。
 位域虽然节省了内存空间，但由于打包和解压的过程中需要耗费额外的操作，所以运行时间很有可能会增加。
*/
/*
设计一个结构体存储学生的成绩信息，需要包括学号，年纪和成绩三项，学号的范围是 0～99999999,年纪分为freshman,sophomore,junior,senior四种，成绩包括A,B,C,D四个等级
分析：学号包括27个二进制位，年级和成绩各个含有2个二进制位
*/
enum Level {Freshman,Sophomore,Junior,Senior};
enum Grade {A,B,C,D};
class student
{
 public:
    student(unsigned number,Level level,Grade grade):number(number),level(level),grade(grade){}
	void show();
 private:
    unsigned number: 27;
    Level level: 2;
	Grade grade: 2;
};
void student::show()
{
 cout<<"Number:\t"<<number<<endl;
 cout<<"Level:\t";
 switch(level)
       {
	    case Freshman:cout<<"freshman"<<endl;break;
		case Sophomore:cout<<"sophomore"<<endl;break;
		case Junior:cout<<"junior"<<endl;break;
		case Senior:cout<<"senior"<<endl;break;
	   }
 cout<<endl;
 cout<<"Grade:\t";
 switch (grade)
      {
	   case A:cout<<"A"<<endl;break;
	   case B:cout<<"B"<<endl;break;
	   case C:cout<<"C"<<endl;break;
	   case D:cout<<"D"<<endl;break;
	  }
 cout<<endl;

}
int main()
{
 student s(20160128,Freshman,C);
 cout<<"Size of student:"<<sizeof(student)<<endl;
 s.show();

 return 0;
}
#endif
#if 0
#include<iomanip>
/*
  输入一个年份，判断是否闰年。
int main()
{
 int year;
 bool isleapyear;
 cout<<"Enter the year:";
 cin>>year;
 isleapyear = ()
 return 0;
}
*/
#endif
#if 1
/*
编写一个名为CPU的类，描述一个CPU的以下信息：时钟频率，最大不会超过3000hz;字长，可以是32位或64位;核数，可以是单核，双核，或四核;是否支持超线程，各项信息要求用位域来表示。通过输出sizeof(CPU)来观察该类所占的字节数。
*/

enum NuclearNumber {one,two,four};
enum Length {a,b};
enum Thread{c,d};
class CPU
{
 public:
    CPU(int hz,NuclearNumber A,Length length,Thread thread):hz(hz),A(A),length(length),thread(thread)
	{
	 cout<<"!"<<endl;
	}
	void show();
 private:
    int hz :12;
    NuclearNumber A :2;
	Length length :1;
	Thread thread :1;
};
void CPU::show()
{
 cout<<"时钟频率:"<<hz<<endl;
 cout<<"核数:";
 switch(A)
 {
  case one :cout<<"one";break;
  case two :cout<<"two";break;
  case four :cout<<"four";break;
 }
cout<<endl;
cout<<"字长:";
switch(length)
{
 case a :cout<<"32";break;
 case b :cout<<"64";break;
}
cout<<endl;
cout<<"超线程：";
switch(thread)
{
 case c :cout<<"true";break;
 case d :cout<<"false";break;
}
cout<<endl;
}
int main()
{
 CPU s(244,one,a,c);
 cout<<"Size of CPU is :"<<sizeof(CPU)<<endl;
 s.show();
 return 0;
}
#endif
