#ifndef _STL_UNINITIALIZED_H
#define _STL_UNINITIALIZED_H

template<class ForwardIterator, class Size, class T>
ForwardIterator __uninitialized_fill_n_aux(ForwardIterator first,
//当POD类型采取交由高阶函数解决											Size n,
											const T &x,
											_true_type)
{
	return fill_n(first, n, x);
}

template<class ForwardIterator, class Size, class T>
ForwardIterator __uninitialized_fill_n_aux(ForwardIterator first,
											Size n,
											const T &x,
//非POD类型时由construct来填充											_false_type)
{
	ForwardIterator cur = first;
	for(; n>0; --n, ++cur)
	{
		construct(&*cur, x);
	}
	return cur;
}


template<class ForwardIterator, class Size, class T, class T1>
ForwardIterator __uninitialized_fill_n(ForwardIterator first,
									   Size n,
									   const T &x,
									   T1*)
{
	typedef typename __type_traits<T1>::is_POD_type is_POD;
	return __uninitialized_fill_n_aux(first, n, x, is_POD());
}

template<class ForwardIterator, class Size, class T>
ForwardIterator uninitialized_fill_n(ForwardIterator first,//初始化的起始空间
									Size n,//初始化空间的大小
									const T &x)//表示初值
{
	return __uninitialized_fill_n(first, n, x, value_type(first));
}

#endif
