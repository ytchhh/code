#include<iostream>
using namespace std;
#if 0
class A
{
 public:
    A(int i = 0):m_i(i){cout<<"A"<<endl;}
	void print(){cout<<m_i<<endl;}
	A(A &b)
	{
	   cout<<"copy"<<endl;
	   m_i = b.m_i;
	}
	A operator+(A &b)
	{
	 return m_i + b.m_i;
	}
 private:
    int m_i;
};
int main()
{
 A a(3),b(4);
 a.print();
 b.print();
 return 0;
}
#endif
#if 0
class A;
A operator+(A &a,A &b);
ostream& operator<<(ostream &out,A &a);
class A
{
 public:
    A(int i = 0):m_i(i){cout<<"A"<<endl;}
	void print(){cout<<m_i<<endl;}
    /*
	A operator+(A &b)
	{
	 cout<<"+"<<endl;
	 return m_i+b.m_i;
	}
	A &operator=(A &b)
	{
	  cout<<"="<<endl;
	  m_i = b.m_i;
	  return *this;
	}
	*/
	A operator++(int)//后加形參列表里放一个int
	{
	  int t = m_i;
	  m_i = m_i +1;
	  return t;
	}
	A &operator++()
	{
	  ++m_i;
	  return *this;
	}
	friend A operator +(A &a,A &b);
	friend ostream& operator<<(ostream &out,A &a);
 private:
   int m_i;
};
A operator+(A &a,A &b)
{
 return a.m_i+b.m_i;
}
ostream& operator<<(ostream &out,A &a)
{
out<<a.m_i;
return out;
}
int main()
{
 A a(3);
 a.print();
 A b(5);
 /*
 A c = a + b;
 c.print();
 */
 (a++).print();
 a.print();
 (++b).print();
 b.print();
 cout<<a<<endl;
 return 0;
}
#endif
#if 0
#include<string.h>
class STR
{
 public:
   STR(char *str = "");
   //STR(STR &str);
   ~STR();
   STR& operator=(STR &str);
   void print(){cout<<m_str<<endl;}
   STR operator+(STR &b);
   char &operator[](int index);
   const char &operator[](int index)const;
   friend ostream& operator<<(ostream &out,STR &a);
 operator char*()
 {
   return m_str;
 }
 private:
   char *m_str;
};
STR::STR(char *str)
{
 m_str = new char[strlen(str)+1];//先开辟空间
 strcpy(m_str,str);
}
STR::~STR()
{
 delete[]m_str;
 m_str = NULL;
}
/*STR::STR(STR &str)
{
 m_str = new char[strlen(str.m_str) + 1];//先开辟空间
 strcpy(m_str,str.m_str);
}
*/
STR STR::operator+(STR &b)
{
 char *p = new char[strlen(m_str)+strlen(b.m_str)+1];
 strcpy(p,m_str);//在构造的时候先用指针，不用类.
 strcat(p,b.m_str);
 STR t(p);
 delete[]p;
 p = NULL;
 return t;
}
STR& STR::operator=(STR &str)
{
 if (&str == this)
     return *this;
 delete[]m_str;//直接将原有的内存空间释放，从新开辟内存空间。
 m_str = new char[strlen(str.m_str)+1];
 strcpy(m_str,str.m_str);
 return *this;
}
char& STR::operator[](int index)
{
 return m_str[index];
}
const char& STR::operator[](int index)const
{
 return m_str[index];
}
ostream& operator<<(ostream &out,STR &a)
{
 out<<a.m_str;
 return out;
}
int main()
{
 STR a("123");
 STR b("456");
 //STR c("qwe");
 const STR d("asdfg");
 STR c = a + b;//123456
 c.print();
 cout<<a[1]<<endl;
 a[1] = 'p';
 cout<<d[4]<<endl;
 cout<<a<<endl;
 cout<<(char*)a<<endl;

 return 0;
}
#endif
#if 1
#include<string.h>
class STR
{
 public:
    STR(char *str = "");
	~STR();
	STR& operator=(STR &str);
	void print(){cout<<m_str<<endl;}
	STR operator+(STR &b);

 private:
    char *m_str;
};
STR::STR(char *str)
{
 m_str = new char[strlen(str)+1];
 strcpy(m_str,str);
}
STR::~STR()
{
 delete[]m_str;
 m_str = NULL;
}
STR STR::operator+(STR &b)
{
 char *p = new char[strlen(m_str)+strlen(b.m_str)+1];
 strcpy(p,m_str);//在构造的时候先用指针，不用类.
 strcat(p,b.m_str);
 STR t(p);
 delete[]p;
 p = NULL;
 return t;
}
STR& STR::operator=(STR &str)
{
 if (&str == this)
     return *this;
 delete[]m_str;
 m_str = new char[strlen(str.m_str)+1];
 strcpy(m_str,str.m_str);
 return *this;
}
int main()
{
 STR a("123");
 STR b("456");
 //STR c("qwe");
 STR c = a + b;
 c.print();
 return 0;
}
#endif

































