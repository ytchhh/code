#include<iostream>
using namespace std;
/*
class A
{
public:
	A(int i = 0):a(i){}
	int print()
		{
			cout<<"a = "<<a<<endl;
		}
private:
	int a;
};
int main()
{
	A a;
	a.print();
	return 0;
}
*/

#if 0
#include<stdlib.h>
int main()
{
	int *p = (int*)malloc(sizeof(int) * 10);
	if(NULL == p)
		{
			cout<<"Out of Memory."<<endl;
			exit(1);
		}
	free(p);

	int *q = new int[10];
	delete []q;
	return 0;
}
#endif

#if 0
#include<string.h>
#include<assert.h>
#include<stdlib.h>
class String
{
	public:
		String()
		{
			data = NULL;
		}
		void InitObj(const char *str = "")
		{
			data = new char[strlen(str) + 1];
			strcpy(data,str);
		}
		void DestroyObj()
		{
			delete []data;
			data = NULL;
		}
		~String()
		{
			delete []data;
			data = NULL;
		}
	private:
		char* data;
};
int main()
{
	String *ps = (String*)malloc(sizeof(String));
	assert(ps != NULL);

	ps->InitObj("HelloLinux");

	ps->DestroyObj();
	free(ps);

	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int d = 0):data(d)
	{
		cout<<"Create Test Object."<,endl;
	}
	~Test()
	{
		cout<<"Free Test Objecct."<<endl;
	}
	void InitObject(int d)
	{
		data = d;
	}
	void DestroyObj(int d)
	{
		data = 0;
	}
private:
	int data;
};
int main()
{
	
	Test *pt = new Test;
	Test *pt = (Test*)::operator new(sizeof(Test));

	return 0;
}
#endif

#if 0
#include<stdlib.h>
void* operator new(size_t sz)//其值类型必须为无符号整型
{
	void *p = malloc(sz);
	return p;
}
void operator delete(void *p)
{
	free(p);
	p = NULL;
}
void* operator new(size_t sz,int *data,int pos)
{
	return &data[pos];
}

int main()
{
	int *p = (int*)malloc(sizeof(int) * 10);
	new(p) int(1);

	return 0;
}
#endif

#if 1
#include<string.h>
class String;
ostream& operator<<(ostream &out,const String &s);
class String
{
	friend ostream& operator<<(ostream &out,const String &s);
	public:
		String(const char *str = "")
		{
			data = new char[strlen(str) + 1];
			strcpy(data,str);
			//use_count++;
		}
		String(const String &s)
		{
			data = s.data;
			//use_count++;
		}
		String& operator=(const String &s)
		{
			if(this != &s)
			{
				delete []data;
				data = new char[strlen(s.data) + 1];
				strcpy(data,s.data);
			}
			return *this;
		}
		~String()
		{
			//if(--use_count == 0)
			//{
				delete []data;
				data = NULL;
			//}
		}
	private:
		char *data;
		//static int use_count;
};
//int String::use_count = 0;

ostream& operator<<(ostream &out,const String &s)
{
	out<<s.data;
	return out;
}
int main()
{
	String s1("Hello");
	String s2 = s1;
	cout<<s1<<endl;
	cout<<s2<<endl;
	return 0;
}
#endif

#if 0

int main()
{
	
	return 0;
}
#endif

