#pragma once 

template<class T>
class scoped_ptr
{
public:
	explicit scoped_ptr(T *p = 0):px(p)//显式构造函数
	{
	}
	~scoped_ptr()				//析构函数
	{
		if(px)
			delete px;
	}
	void reset(T *p = 0)		//重置智能指针
	{
		BOOST_ASSERT(p == 0 || p != px);
		this_type(p).swap(*this);
	}

	T &  operator*() const		//操作符重载
	{
		return *px;
	}
	T *  operator->() const	//操作符重载
	{
		return px;
	}
	T *  get()	const			//获得原始指针
	{
		return px;
	}

	explicit	operator bool() const		//显式bool值转型
	{
	
	}
	void		swap(scoped_ptr &b)	//交换指针
	{
		T* tmp = b.px;
		b.px = px;
		px = tmp;
	}
private:
	T *px;		//原始指针
	scoped_ptr(scoped_ptr const &);
	scoped_ptr& operator=(scoped_ptr const &);

	void operator==(scoped_ptr const&) const;
	void operator!=(scoped_ptr const&) const;
};
/*
	将拷贝和赋值函数都定义为私有的不允许拷贝和赋值，拒绝了指针所有权的转让，智能在函数内部自己使用。从而保证了指针的绝对安全。
*/
