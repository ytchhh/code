#include<iostream>
#include<vld.h>
#include<assert.h>
#include<list>
using namespace std;

class String;

class String_rep
{
	friend class String;
public:
	String_rep(const char *str = "") : use_count_(0)
	{
		data = new char[strlen(str)+1];
		strcpy(data, str);
	}
	String_rep(const String_rep &rep);
	String_rep& operator=(const String_rep &rep);
	~String_rep()
	{
		delete []data;
	}
public:
	void increment()
	{++use_count_;}
	void decrement()
	{
		if(--use_count_ == 0)
			delete this;
	}
	int use_count()const
	{return use_count_;}
private:
	char *data;
	int use_count_;
};

class String
{
public:
	String(const char *str = ""):rep(new String_rep(str))
	{
		rep->increment();
	}
	String(const String &s)
	{
		rep = s.rep;
		rep->increment();
	}
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			rep->decrement(); //delete
			rep = s.rep;      //
			rep->increment(); //
		}
		return *this;
	}
	~String()
	{
		rep->decrement();
	}
public:
	void to_upper()
	{
		if(rep->use_count() > 1)
		{
			String_rep *new_rep = new String_rep(rep->data);
			rep->decrement();
			rep = new_rep;
			rep->increment();
		}
		char *ch = rep->data;
		while(*ch != '\0')
		{
			*ch -= 32;
			++ch;
		}
	}
private:
	String_rep *rep;
};
////////////////////////////////////////////////////

void main()
{
	String s1("hello");
	String s2("abc");
	s2 = s1; 

	s1.to_upper();

}

/*
class String_rep
{
public:
	String_rep(const char *str = "") : use_count_(0)
	{
		data = new char[strlen(str)+1];
		strcpy(data, str);
	}
	String_rep(const String_rep &rep);
	String_rep& operator=(const String_rep &rep);
	~String_rep()
	{
		delete []data;
	}
public:
	void increment()
	{++use_count_;}
	void decrement()
	{--use_count_;}
	int use_count()const
	{return use_count_;}
private:
	char *data;
	int use_count_;
};

class String
{
public:
	String(const char *str = ""):rep(new String_rep(str))
	{
		rep->increment();
	}
	String(const String &s)
	{}
	String& operator=(const String &s)
	{}
	~String()
	{
		rep->decrement();
		if(rep->use_count() == 0)
			delete rep;
	}
private:
	String_rep *rep;
};
////////////////////////////////////////////////////

void main()
{
	String s1("Hello");
	//String s2 = s1; //
}

/*
class String;
ostream& operator<<(ostream &out, const String &s);

class String
{
	friend ostream& operator<<(ostream &out, const String &s);
public:
	String(const char *str = "")
	{
		data = new char[strlen(str)+1];
		strcpy(data, str);
		use_count++;
	}
	String(const String &s)
	{
		data = s.data;
		use_count++;
	}
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			delete []data;
			data = new char[strlen(s.data)+1];
			strcpy(data, s.data);
		}
		return *this;
	}
	~String()
	{
		if(--use_count == 0)
		{
			delete []data;
			data = NULL;
		}
	}
private:
	char *data;
	static int  use_count;
};

int String::use_count = 0;

ostream& operator<<(ostream &out, const String &s)
{
	out<<s.data;
	return out;
}

void main()
{
	String s1("Hello");
	String s2 = s1;
	cout<<s1<<endl;
	cout<<s2<<endl;

	String s3("abc");
}

/*
void main()
{
	int *p = new int(10);
}


class String
{};

void main()
{
	list<String> mylist;

}


/*
void* operator new(size_t sz, int *data, int pos)
{
	return &data[pos];
}

void main()
{
	int *p = (int*)malloc(sizeof(int)*10);
	new(p) int(1); // placement new // ¶¨Î»
}

/*
void* operator new(size_t sz)
{
	void *p = malloc(sz);
	return p;
}

void operator delete(void *p)
{
	free(p);
	p = NULL;
}

class Test
{
public:
	Test(int d = 0) : data(d)
	{
		cout<<"Create Test Object."<<endl;
	}
	~Test()
	{
		cout<<"Free Test Object."<<endl;
	}
public:
	void InitObj(int d)
	{
		data = d;
	}
	void DestroyObj()
	{
		data = 0;
	}
private:
	int data;
};

//new operator
//operator new   malloc

void main()
{
	//Test *pt = new Test; //1 2
	//delete pt;           //1 2

	Test *pt = (Test*)::operator new(sizeof(Test));
}

/*
class String
{
public:
	String()
	{
		data = NULL;
	}
	void InitObj(const char *str = "")
	{
		data = new char[strlen(str)+1];
		strcpy(data, str);
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
	char *data;
};



/*
void main()
{
	//Test *pt = (Test *)malloc(sizeof(Test));
	String *ps = (String *)malloc(sizeof(String));
	assert(ps != NULL);

	ps->InitObj("HelloLinux");

	ps->DestroyObj();
	free(ps);
}

/*
void main()
{
	int *p = (int*)malloc(sizeof(int) * 10);
	if(NULL == p)
	{
		cout<<"Out Of Memory."<<endl;
		exit(1);
	}
	free(p);

	int *q = new int[10]; //new int(10)
	delete []q;
}
*/