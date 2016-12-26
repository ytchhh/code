template<class T>
class auto_ptr
{
public:
	explicit auto_ptr(T *p = 0):pointer(p){}
	template<class U>
	auto_ptr(auto_ptr<U>& rhs):pointee(rhs.release()) {}
	~auto_ptr(){delete pointee;}
	
	template<class U>
	auto_ptr<T>& operator=(auto_tpr<U>& rhs)
	{
		if(this != &rhs)
			reset(rhs.release());
		return *this;
	}
	T& operator*() const {return *pointee;}
	T* operator->() const {return pointee;}
	T* get() const {return pointer;}
private:
	T *pointer;
};
