#if 0
#include<iostream>
#include<fstream>
#include<string>
int main()
{
	ofstream outfile("out_file");
	ifstream infile("in_file");
	if (! infile)
	{
		cerr<<"error:unable to open input file!\n";
	          return -1;
	}
	if (! outfile)
	{
		cerr<<"error:unble to open output file\n";
		return -2;
	}
	string word;
	while ( infile >> word)
		outfile << word << " ";
	return 0;
}
#endif
#include<iostream>
using namespace std;
#if 0
class Complex
{
	public:
		Complex(double r = 0.0,double i = 0.0):real(r),imag(i){}
		void display() const;
	private:
		double real;
		double imag;
};
void Complex::display()const
{
	cout<<"real:"<<real<<" "<<"imag:"<<imag<<endl;
}
int main()
{
	Complex a(10,20),b(5,8);
	a.display();
	return 0;
}
#endif
#if 0
/*
运算符重载已有的运算符赋予多重含义，使同一个运算符作用于不同类型的数据时导致不同的行为。
运算符重载的实质是函数重载
C++中的运算符除了少数几个之外，全部可以重载，而且只能重载C++中已经有的运算符。
重载之后运算符的优先级和结合性都不会改变。
运算符重载是针对新类型数据的实际需要，对原有的运算符进行适当的改造。
语法模式
  返回类型 operator运算符（参数列表）
  {
   函数体
  }
*/
class Complex
{
	public:
		Complex(double r = 0,double i = 0):real(r),imag(i){}
		Complex operator+(const Complex &p) const;
		Complex operator-(const Complex &p) const;
		void display() const;
	private:
		double real,imag;
};
Complex Complex::operator+(const Complex &p) const
{
	return Complex(real+p.real,imag+p.imag);
}
Complex Complex::operator-(const Complex &p) const
{
	return Complex(real-p.real,imag-p.imag);
}
void Complex::display()const
{
	cout<<"("<<real<<","<<imag<<")"<<endl;
}
int main()
{
	Complex c(5,4),c1(2,10),c2;
	cout<<"c=";c.display();
	cout<<"c1=";c1.display();
	c2 = c-c1;
	cout<<"c2 = c-c1=";c2.display();
	c2 = c = c1;
	cout<<"c2 = c + c1=";c2.display();
	return 0;
}
#endif
#if 0
class Clock
{
	public:
		Clock(int hour = 0,int minute = 0,int second = 0);
		void showTime() const;
		Clock operator++();
		Clock operator++(int);
	private:
		int hour,minute,second;
};
Clock::Clock(int hour, int minute,int second)
{
	if (0<=hour && hour<24 && 0<=minute && minute<60 && 0<= second && second<60)
	{
		this -> hour = hour;
		this -> minute = minute;
		this -> second = second;
	}
	else
		cout<<"Time error!"<<endl;
}
void Clock::showTime() const
{
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}
Clock Clock::operator++()
{
	second++;
	if (second >= 60)
	{
		second -= 60;
		minute++;
		if (minute >= 60)
		{
			minute -= 60;
			hour = (hour+1)%24;
		}
	}
	return *this;
}
Clock Clock::operator++(int)
{
	Clock old = *this;
	++(*this);
	return old;   //调用前置++运算符
}
int main()
{
	Clock myClock(23,59,59);
	cout<<"First time output";
	myClock.showTime();
	cout<<"Show myClock++";
	(myClock++).showTime();
	cout<<"Show ++myClock";
	(++myClock).showTime();
	return 0;
}
#endif
#if 0
class Complex
{
	public:
		Complex(double r = 0.0,double i = 0.0):real(r),imag(i){}
		friend Complex operator+(const Complex &c1,const Complex &c2);
		friend Complex operator-(const Complex &c1,const Complex &c2);
		friend ostream& operator<<(ostream &out,const Complex &c2);
	private:
		double real,imag;
};
Complex operator+(const Complex &c1,const Complex &c2)
{
	return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
Complex operator-(const Complex &c1,const Complex &c2)
{
	return Complex(c1.real-c2.real,c1.imag-c2.imag);
}
ostream& operator<<(ostream &out,const Complex &c)
{
	cout<<"("<<c.real<<","<<c.imag<<")";
	return out;
}
int main()
{
	Complex c1(5,4),c2(2,10),c3;
	cout<<"c1 = "<<c1<<endl;
	cout<<"c2 = "<<c2<<endl;
	c3 = c1 - c2;
	cout<<"c3 = c1 + c2 = "<<c3<<endl;
	return 0;
}

#endif
#if 1
/*

*/
#endif













