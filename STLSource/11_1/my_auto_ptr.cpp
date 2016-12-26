#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

class String;
class String_rep
{
	friend class String;
private :
	mutable char *data; 				//mutable yibiande
	mutable int use_count_;

public :
	String_rep(const char *str = "") : use_count_(0)
	{
		data = new char[strlen(str) + 1];
		strcpy(data, str);
	}
	String_rep(const String_rep &rep)
	{
				
	}
	String_rep& operator=(const String_rep &rep);
	~String_rep()
	{
		delete []data;	
	}

public :
	void increment()
	{++ use_count_;}
	void decrement()
	{
		if(-- use_count_ == 0)	
			delete this;
	}
	int use_count() const
	{return use_count_;}
};

class String
{
private :
	String_rep *rep;
	
public :
	String(const char *str = "") : rep(new String_rep(str))
	{
		rep -> increment();	
	}
	
	String(const String& str)
	{
		rep = str.rep;
		rep -> increment();
	}

	String& operator=(const String& str)
	{
		if(this != &str)	
		{
			rep -> decrement();
			rep = str.rep;
			rep -> increment();
		}
	}
	~String()
	{
		rep -> decrement();	
	}

public :
	void to_upper()
	{
		if(rep -> use_count() > 1)	
		{
			String_rep *new_rep = new String_rep(rep -> data);	
			rep -> decrement();
			rep = new_rep;
			rep -> increment();
		}
		char *ch = rep -> data;
		while(*ch != '\0')
		{
			*ch += 32;
			++ ch;
		}
	}
};
int main()
{
	String s1("123");	
	String s2("345");

	s1 = s2;
	return 0;
}
