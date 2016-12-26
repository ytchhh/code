//scoped_ptr指针的简单实现
//scoped_ptr不能转让所有权 
#if 0
//how to use scoped_ptr 
#include <boost/smart_ptr.hpp> 
using namespace boost;
using namespace std;

struct posixFile
{
	posixFile(const char* fileName)
	{
		cout << "open file : " << fileName << endl;
	}

	~posixFile()
	{
		cout << "close file"	<< endl;
	}
};

int main()
{
	scoped_ptr<int> p(new int);
	if(p)
	{
		*p = 100;
		cout << *p << endl;
	}
	p.reset();
	assert(p == 0);
	if(!p)
	{
		cout << "p == NULL"	<< endl;

		//每种智能指针只能管理一种类型的的指针，操作时要注意智能指针所管 
		//的类型
		scoped_ptr<posixFile> pos(new posixFile("/home/lhg/1.txt"));
	}
	return 0;
}
#endif

#if 0
#include <iostream>
#include <boost/smart_ptr.hpp>
using namespace boost;
using namespace std;
//自动指针auto_ptr和scoped_ptr的区别
//示例
int main()
{
	auto_ptr<int> ap(new int(10));
	scoped_ptr<int> sp(ap); //这步是怎么实现的
	assert(ap.get() == 0);

	ap.reset(new int(20));
	cout << *ap << "," << *sp << endl;

	auto_ptr<int> ap2;
	ap2 = ap;
	assert(ap.get() == 0);
}
#endif

#if 1
//下来是源码剖析
//scoped_ptr
#include <iostream>
using namespace std;

template <class T>
class scoped_ptr
{
private :
	T* px;
	scoped_ptr(scoped_ptr<T> const&);
	scoped_ptr& operator=(const scoped_ptr<T> &);

public :
	scoped_ptr(T * p = 0) : px(p) {}
	~scoped_ptr()
	{
		delete px;	
	}
	T& operator*()
	{
		return *get();	
	}
	T* operator->() const
	{
		return get();	
	}
	T* get() const
	{
		return px;	
	}

	typedef scoped_ptr<T> this_type;
	void reset(T * p = 0)
	{
		this_type(p).swap(*this);
	}

	void swap(scoped_ptr<T>& b)
	{
		T * temp = b.px;
		b.px = px;
		px = temp;
	}
};

int main()
{
	int *p = new int(10);
	int *q = new int(100);
	scoped_ptr<int> sp(p);
	cout << *sp << endl;
	sp.reset(q);
	cout << *sp << endl;

	return 0;	
}

#endif
