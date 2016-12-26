#pragma once //它的作用是防止头文件被再次与编译
#include<stdlib.h>
#include<assert.h>
#include"memory.h"

template<class T,class _A = my_allocator<T> >
class list
{
public:
    struct _Node;
    typedef struct _Node* _Nodeptr;
    struct _Node
    {
        _Nodeptr _Next;
        _Nodeptr _Prev;
        T        _Value;
    };
    struct _Acc
    {
        typedef struct _Node*& _Nodepref;
        typedef T&             _Vref;
        static  _Nodepref _Next(_Nodeptr _P)
        {return ((_Nodepref)(*_P)._Next);}
        static  _Nodepref _Prev(_Nodeptr _P)
        {return ((_Nodepref)(*_P)._Prev);}
        static  _Vref _Value(_Nodeptr _P)
        {return ((_Vref)(*_P)._Value);}
    };
    //萃取技术
    typedef list<T> _Myt;
    typedef size_t      size_type;
    typedef T           value_type;
    typedef T&          reference;
    typedef const T&    const_reference;
    typedef T&          pointer;
    typedef const T&    const_pointer;
public:

    list():_Head(_Buynode()),_Size(0)
    //list的构造函数
    {}
    class const_iterator
    {
        public:
            const_iterator(){}
            const_iterator(_Nodeptr _P):_Ptr(_P){}
            const_iterator(const_iterator &_X):_Ptr(_X._Ptr){}
            const_reference operator*()const
            {return _Acc::_Value(_Ptr);}
            //const_reference operator->()const
            //{return (&**this);}
            const_iterator& operator++()
            {
                _Ptr = _Acc::_Next(_Ptr);
                return *this;
            }
            const_iterator operator++(int)
            {
                const_iterator _Tmp = _Ptr;
                ++*this;
                return _Tmp;
            }
            const_iterator operator--()
            {
                _Ptr = _Acc::_Prev(_Ptr);
                return *this;
            }
            const_iterator operator--(int)
            {
                const_iterator _Tmp = *this;
                --*this;
                return _Tmp;
            }
            bool operator==(const const_iterator& _X) const
            {return _Ptr == _X._Ptr;}
            bool operator!=(const const_iterator& _X) const
            {return !(_Ptr == _X._Ptr);}
            _Nodeptr _Mynode() const
            {return _Ptr;}
        protected:
            _Nodeptr _Ptr;
    };
    class iterator//:public const_iterator
    {
        public:
            iterator(){}//普通构造函数
            iterator(_Nodeptr _P):_Ptr(_P){}//参数构造函数
            reference operator*()const
            {return (_Acc::_Value(_Ptr));} //取值运算符重载
            //reference operator->()const
            //{return (&**this);} //先对对象进行取*将值引用
            iterator& operator++()//前加加
            {
                _Ptr = _Acc::_Next(_Ptr);
                return (*this);
            }
            iterator operator++(int)//后加加
            {
                iterator _Tmp = *this;
                ++*this;
                return (_Tmp);
            }
            iterator operator--()//前减减
            {
                _Ptr = _Acc::_Prev(_Ptr);
                return (*this);
            }
            iterator operator--(int)//后减减
            {
                iterator _Tmp = *this;
                --*this;
                return _Tmp;
            }
            bool operator==(const iterator& _X) const//比较是否相等
            {return (_Ptr == _X._Ptr);}
            bool operator!=(const iterator& _X) const
            {return (!(*this == _X));}
            _Nodeptr _Mynode()const
            {return _Ptr;}
        private:
            _Nodeptr _Ptr;
    };
    typedef iterator _It;
    
    /*
    void push_back(const T &x)
    {
        _Nodeptr _S = _Buynode(_Head,_Acc::_Prev(_Head));
        assert(_S != NULL);
        _Acc::_Value(_S) = x;
        _Acc::_Next(_Acc::_Prev(_S)) = _S;
        _Acc::_Prev(_Head) = _S;
    }
    */
    /* //这种方法相比较于第一种方法已经有了提升
    void push_back(const T &x)
    {
        _Nodeptr _S = _Buynode(_Head,_Head->_Prev);//在创建结点的时候将当前结点的后继和前趋分别连接起来
        assert(_S != NULL);//断言 语言 条件为真继续执行，为假程序崩溃。
        _S->_Value = x;
        _S->_Prev->_Next = _S;
        _Head->_Prev = _S;
        _Size++;
    }
    */
    //这样的插入结点方法并没有完全的利用到_Buynode函数
    /*
    void push_back(const T &x)
    {
        _Nodeptr _S = _Buynode();//利用_Buynode函数创建一个结点
        assert(_S != NULL);  //判断是否为空
        _S->_Value = x;      //赋值

        _S->_Next = _Head;  //后继指向头指针
        _S->_Prev = _Head->_Prev; //前趋指向当前的最后一个结点
        _S->_Prev->_Next = _S;   //当前的最后一个结点的后继指向现在这个结点
        _Size++;    //结点个数进行自加
    }
    */
    size_type size()
    {
        return _Size;
    }
    bool empty() const
    {
        return (size() == 0);
    }
    iterator begin()
    {return (iterator(_Acc::_Next(_Head)));}
    const_iterator begin() const
    {return const_iterator(_Acc::_Next(_Head));}
    iterator end()
    {return (iterator(_Head));}
    const_iterator end() const
    {return const_iterator(_Head);}
    size_type size() const
    {return (_Size);}
    
    iterator insert(iterator _P,const T& _X = T())
    {
        _Nodeptr _S = _P._Mynode();
        _Acc::_Prev(_S) = _Buynode(_S,_Acc::_Prev(_S));
        _S = _Acc::_Prev(_S);
        _Acc::_Next(_Acc::_Prev(_S)) = _S;
        _Acc::_Value(_S) = _X;
        ++_Size;
        return iterator(_S);
    }
    reference front()
    {return *begin();}
    const_reference front() const
    {return *begin();}
    reference back()
    {return *(--end());}
    const_reference back() const
    {return *(--end());}
    void push_back(const T &x)//在尾部插入
    {insert(end(),x);}
    void push_front(const T &x)
    {insert(begin(),x);}
    void pop_back()
    {earse(--end());}
    void pop_front()
    {earse(begin());}

    void insert(iterator _P, size_type _M, const T &_X)
	{
        for(; 0 < _M; --_M)
            insert(_P,_X);
    }

    void insert(iterator _P, const T *_F, const T *_L)
	{
        for( ; _F != _L; ++_F )
            insert(_P,*_F);
    }
    void insert(iterator _P, _It _F, _It _L)
    {
        for(; _F != _L; ++_F)
            insert(_P,*_F);
    }

    iterator erase(iterator _P)
    {
        _Nodeptr _S = (_P++)._Mynode();
        _Acc::_Next(_Acc::_Prev(_S)) = _Acc::_Next(_S);
        _Acc::_Prev(_Acc::_Next(_S)) = _Acc::_Prev(_S);
        --_Size;
        free(_S);
        
        return _P;
    }
    iterator erase(iterator _F,iterator _L)
    {
        while(_F != _L)
            erase(_F++);
        return _F;
    }
    void clear()
    {
        erase(begin(),end());
    }
	
	/*
    void splice(iterator _P,_Myt _X)//将_X接合于_P的位置之前，_X必须不同于*this
    {
        if(!_X.empty())
            {
                splice(_P,_X,_X.begin(),_X.end());
                _Size += _X._Size;
                _X._Size  = 0;
            }
    }
    void splice(iterator _P,_Myt& _X,iterator _F)//将_F所指的元素接合于_P所指位置之前，_P和_F可指向同一个list
    {
        iterator _L = _F;
        if(_P != _F && _P != ++_L)
            {
                splice(_P,_X,_F,_L);
                ++_Size;
                --_X._Size;
            }
    }
    //将_F和_L内所有元素接合于_P所指位置之前，
    //_P和 _F,_L可指向同一个list
    //但_P不能位于_F和_L之间
    void splice(iterator _P,_Myt& _X,iterator _F,iterator _L)
    {
        if(_F != _L)
            {
                if(&_X != this)
                    {
                        size_type _N = 0;
                        _Distance(_F,_L,_N);
                        _Size += _N;
                        _X._Size -= _N;
                    }
                splice(_P,_X,_F,_L);
            }
    }
	*/

protected:
    _Nodeptr _Buynode(_Nodeptr _Narg = 0,_Nodeptr _Prev = 0)
    //_Buynode函数是创建一个结点，可以将结点的前趋和后继分别连接起来。
    {
        _Nodeptr _S = (_Nodeptr)malloc(sizeof(_Node));//分配空间
        assert(_S != NULL);  //检查是否指向为空
        _Acc::_Next(_S) = _Narg != 0 ? _Narg : _S;//连接后继结点
        _Acc::_Prev(_S) = _Prev != 0 ? _Prev : _S;//连接前趋结点
        return _S;  //将当前结点的地址返回
    }
private:
	_A			allocator;//声明一个空间配置器
    _Nodeptr    _Head; // 头指针
    size_type   _Size; // 结点的个数
};
