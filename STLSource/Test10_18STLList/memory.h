#pragma once

template<class _Ty> 
inline _Ty* _MyAllocate(_PDFT _N, _Ty*)
{
	if (_N < 0)
		_N = 0;
	return ((_Ty*)operator new((_SIZT)_N * sizeof (_Ty))); 
}

template<class _T1, class _T2> 
inline void _MyConstruct(_T1 *_P, const _T2& _V)
{
	new((void *)_P)_T1(_V); 
}

template<class _Ty> 
inline void _MyDestroy(_Ty *_P)
{
	//_DESTRUCTOR(_Ty, _P); 
	_P->~_Ty();
}

template<class _Ty>
class my_allocator
{
public:
	typedef _SIZT size_type;
	typedef _PDFT difference_type;
	typedef _Ty  *pointer;
	typedef const _Ty *const_pointer;
	typedef _Ty & reference;
	typedef const _Ty & const_reference;
	typedef _Ty value_type;
public:
	char* _Charalloc(size_type _N)
	{
		return (_MyAllocate((difference_type)_N,(char*)0)); 
	}
	void construct(pointer _P, const _Ty& _V)
	{
		_MyConstruct(_P, _V); 
	}
	void destroy(pointer _P)
	{
		_MyDestroy(_P); 
	}
	void deallocate(void *_P, size_type)
	{
		operator delete(_P);
	}

};
