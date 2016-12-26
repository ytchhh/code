#ifndef ARRAY_H
#define ARRAY_H

#include<cassert>
template<class T>
class Array
{
    private:
        T *list;
        int size;
    public:
        Array(int sz = 50);    //构造函数
        Array(const Array<T> &a);//复制构造函数
        ~Array();
        Array<T>& operator = (const Array<T> &rhs); //重载"="使数组对象可以整体赋值
        T &operator [] (int i);     //重载"[]",使Array对象可以起到C++普通数组的作用
        const T &operator [] (int i) const;//"[]"运算符针对const的重载
        operator T*();  //重载到T *类型的转换，使Array对象可以起到C++普通数组的作用
        operator const T*() const;      //到T*类型转换操作符针对const的重载
        int getSize() const;        //到数组的大小
        void resize(int sz);        //修改数组的大小
};
//构造函数
template<class T>
Array<T>::Array(int sz)
{
    assert(sz >= 0);    //sz为数组大小(元素个数)，应当非负
    size = sz;          //将元素个数赋值给变量size;
    list = new T[size]; //动态分配size个T类型的元素空间。
}

//析构函数
template<class T>
Array<T>::~Array()
{
    delete []list;
}

//复制构造函数
template<class T>
Array<T>::Array(const Array<T>&a)
{
    size = a.size;   //对对象a取得数组大小，并赋值给当前对象的成员
    list = new T[size]; //动态分配size个T类型的元素空间
    for(int i = 0; i < size; ++i) //从对象a复制数组元素到本对象
        {
            list[i] = a.list[i];
        }
}

//重载"="运算符，将对象rhs赋值给本对象，实现对象之间的整体赋值
template<class T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
    if(&rhs != this)//如果本对象中数组大小与rhs不同，则删除数组原有内容，然后重新分配
        {
            if(size != rhs.size)
                {
                    delete [] list;     //删除数组原有内存
                    size = rhs.size;    //设置本对象的数组大小
                    list = new T[size];
                }
                //从对象rhs复制数组元素到本对象
            for(int i = 0; i < size; ++i)
                    list[i] = rhs.list[i];
        }
    return *this;
}

//重载下标运算符，实现与普通数组一样通过下标访问元素，并且具有越界检查功能
template<class T>
T &Array<T>::operator[] (int n) 
{
    assert( n >= 0 && n < size); //检查下标是否越界
    return list[n];                 //返回下标为n的数组元素
}

template<class T>
const T &Array<T>::operator [] (int n) const 
{
    assert(n >= 0 && n < size);     //检查下标是否越界
    return list[n];         //返回下标为n的数组元素
}

//重载指针转换运算符，将Array类的对象名转换为T类型的指针
//指向当前对象中的私有数组
//因而可以像使用普通数组首地址一样使用Array类的对象名
template<class T>
Array<T>::operator T* ()
{
    return list;    //返回当前对象中私有数组的首地址
}

template<class T>
Array<T>::operator const T* () const
{
    return list;
}

template<class T>//取当前数组的大小
int Array<T>::getSize() const
{
    return size;
}

template<class T>
void Array<T>::resize(int sz)
{
    assert(sz >= 0);
    if(sz == size)
        return ;
    T *newList = new T [sz];
    int n = (sz < size) ? sz:size;
    for(int i = 0; i < n; ++i)
        {
            newList[i] = list[i];
            delete[] list;
            list = newList;
            size = sz;
        } 
}
#endif
