#if 0
#include<iostream>
#include"scoped_ptr.h"
using namespace std;

int main()
{
	scoped_ptr<string> sp(new string("text"));
	cout<<*sp<<endl;
	cout<<sp->size()<<endl;
	return 0;
}
#endif

#include<iostream>
#include<boost/smart_ptr.hpp>
using namespace std;
using namespace boost;

struct postix_file
{
postix_file(const char* file_name)
{
	cout<<"open file:"<<file_name<<endl;
}
~postix_file()
{
	cout<<"close file"<<endl;
}
};

int main()
{
	scoped_ptr<postix_file> fp(new postix_file("1.txt"));

	scoped_ptr<int> p(new int);

	if(p)
	{
		*p = 100;
		cout<<*p<<endl;
	}

	p.reset();

	assert(p == 0);

	if(!p)
	{
		cout<<"scoped_ptr == nullptr"<<endl;
	}
	return 0;
}
