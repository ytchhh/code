#include<iostream>
using namespace std;
#if 0
template<class T>
T abs(T x)
{
    return x>0?x:-x;
}
int main()
{
    int n = -5;
    double d = -5.5;
    cout<<abs(n)<<endl;
    cout<<abs(d)<<endl; 
    return 0;
}
#endif
#if 0
#include<string.h>
template<class T>
int cmp(T &a,T &b)
{
    return a>b?1:0;
}
template<> int cmp<char *>(char * &a,char * &b)
{
    return strcmp(a,b);
}

template<class T>
void my_swap(T &a,T &b)
{
    T t = a;
    a = b;
    b = t;
}
template<> void my_swap<char *>(char * &a,char * &b)
{
    char t[20];
    strcpy(t,a);
    strcpy(a,b);
    strcpy(b,t);

}

template<class T>
void sort(T *a,int n)
{
    T t;
    int i,j;
    for(i = 0; i < n; ++i)
        {
            for(j = 0; j < n-1-i; ++j)
                {
                    if( cmp(a[j],a[j+1]) > 0)
                        {
                            my_swap(a[j],a[j+1]);
                        }
                }
        }
}

template<class T>
void print(T *a,int n)
{
    int i;
    for(i = 0; i < n; ++i)
        cout<<a[i]<<" ";
        cout<<endl;
}

int main()
{
    //int a[] = {5,4,3,2,1};
    //int n = sizeof(a)/sizeof(a[0]);
    char b[5][20] = {"111","000","888","666","444"};
    char *a[5];
    for(int i = 0; i < 5; ++i)
        a[i] = b[i];
    sort(a,5);
    print(a,5);
    return 0;
}
#endif
#if 0
class List
{
    public:
        List(){m_pHead  = m_pTail = NULL;}
        void insertHead(int value);
        void insertTail(int value);
        void DeleteHead();
        void DeleteTail();
        void print();
        bool IsEmpty();
        void Clear();
        int size();
        ~List(){}
        
    private:
        typedef struct node
        {
            int value;
            struct node *next;
        }Node;
        Node *m_pHead;
        Node *m_pTail;
};
void List::insertHead(int value)
{
    Node *p = NULL;
    p = new Node;
    p->value = value;
    p->next =NULL;
    if(m_pHead == NULL)
        {
            m_pHead = p;
            m_pTail = p;
        }
    else
        {
            p->next = m_pHead;
            m_pHead = p;   
        }

}
void List::insertTail(int value)
{
    Node *p = NULL;
    p = new Node;
    p->value = value;
    p->next = NULL;
    if( m_pTail == NULL )
        {   
            m_pTail = p;
            m_pHead = p;
        }
    else
        {
            m_pTail->next = p;
            m_pTail = p;   
        }
}
void List::DeleteHead()
{
    Node *p = NULL;
    if( m_pHead == NULL )
        return ;
    else
        {
            p = m_pHead->next;
            delete m_pHead;
            m_pHead = p;
        }
}
void List::DeleteTail()
{
    Node *p = NULL;
    
    if( m_pTail == NULL )
        {
            return ;           
        }
    else
        {
            if( m_pHead == m_pTail )
                {
                    delete m_pTail;
                }
            else
                {
                    for( p = m_pHead; p->next != m_pTail; p = p->next )
                            ;
                    delete m_pTail;
                    m_pTail = p;
                    m_pTail->next = NULL;
                }
        }
}
bool List::IsEmpty()
{
    if( m_pHead == NULL )
            return true;
    else
            return false;
}
void List::Clear()
{
    Node *p = NULL,*p1 = NULL;
   if( m_pHead == NULL )
        return ;
   else
   {
        for( p = m_pHead; p != NULL; p = p1 )
            {
                p1 = p->next;
                
                p = NULL;
            }     
   }
}
void List::print()
{
    Node *p = NULL;
    for(p = m_pHead; p != NULL; p = p->next)
        cout<<p->value<<" ";
    cout<<endl;
}
int main()
{
    List li;
    li.insertHead(1);
    li.insertTail(2);
    //li.print();
    li.insertTail(3);
    li.print();
    //li.DeleteHead();
    //li.DeleteTail();
    li.Clear();
    li.print();
    return 0;
}

#endif

/*
    C++的最重要特性就是代码重用，为了实现代码重用，代码必须具有通用性。通用代码应不受数据类型的影响，并且可以自动适应数据类型
的变化。这种程序设计类型称为参数话程序设计。模板是C++支持参数化程序设计的工具，通过它可以实现参数化多态性。
    所谓参数化多态性，就是将程序所处理的对象的类型参数化，使得一段程序可以用于处理多种不同类型的对象。
*/
/*
    函数模板的定义形式为
    template<模板参数表>
    类型名 函数名(参数表)
    {
        函数体的定义
    }
    模板参数表由逗号分隔的模板参数构成，可以包括以下内容
    (1)class(或typedef)标识符，指明可以接受一个类型参数。这些类型参数代表的是类型，可以是内部类型或自定义类型。
    (2)"类型说明符"标识符，指明可以接受一个由"类型说明符"所规定类型的常量作为参数。
    (3)template<参数表>class 标识符，指明可以接受一个类模板名作为参数
       函数参数可以用来指定函数模板本身的形參类型，返回值类型，以及声明函数中的局部变量。函数模板中函数体的定义方式与定义
    普通函数类似。
*/

#if 0
template<class T>
T abs(T x)
{
    return x > 0 ? x : -x;
}
int main()
{
    int n = -5;
    double d = -5.5;
    cout<<abs(n)<<endl;
    cout<<abs(d)<<endl;
    return 0;
}
#endif

#if 0
template<class T>
void outputArray(const T* array,int count)
{
    for(int i = 0; i < count; ++i)
        {
            cout<<array[i]<<" ";
        }
    cout<<endl;
}
int main()
{
    const int A_COUNT = 8,B_COUNT = 8,C_COUNT = 20;
    int a[A_COUNT] = {1,2,3,4,5,6,7,8};
    double b[B_COUNT] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8};
    char c[C_COUNT] = "Welcome to see you!";
    cout<<"a array contains:"<<endl;
    outputArray(a,A_COUNT);
    cout<<"b array contains:"<<endl;
    outputArray(b,B_COUNT);
    cout<<"c array contains:"<<endl;
    outputArray(c,C_COUNT);
    return 0;
}
#endif
/*
    1.虽然函数模板本身在编译时不会生成任何目标代码，只有由模板生成的实例会生成目标代码。
    2.被多个源文件引用的函数模板，应当连同函数体一同放在头文件中，而不能像普通函数那样只能将声明放在头文件中。
    3.函数指针也只能指向模板的实例，而不能指向模板本身。
*/

/*
    类模板
        使用类模板使用户可以为类定义一种模式，使得类中的某些数据成员，某些成员函数的参数，返回值或局部变量能取任意类型。
    类是对一组对象的公共性质的抽象，而类模板则是对不同类的公共性质的抽象，因此类模板是属于更高层次的抽象。由于类模板需要
    一种或多种更高层次的抽象。由于类模板需要一种或多种类型参数，所以类模板也常称为参数化表。
*/
/*
类模板的声明语法形式为:
    template<模板参数表>
    class 类名
    {
        类成员声明
    }
    如果需要在类模板以外定义其成员函数，咋要采用以下的形式:
    template<模板参数表>
    类型名 类名<模板参数标识符列表>::函数名(参数表)
    注意:一个类模板声明本身并不是一个类，它说明了类的一个家族。只有当被其他代码引用时，模板才根据引用的需要生成具体的类。
    使用一个模板类来建立对象时，应按照如下形式声明:
    模板名<模板参数表>对象名1,...，对象名n;

*/
#if 0
#include<cstdlib>
struct Student  //结构体Student
{
    int id;     //学号
    float gpa;  //平均分
};
template<class T>
class Store
{
    private:
        T item;
        bool haveValue;
    public:
        Store();
        T &getElem();
        void putElem(const T &x);
};
template<class T> //提取默认构造函数的实现
Store<T>::Store():haveValue(false) {}

template<class T>
T &Store<T>::getElem()
{
    if(!haveValue)
        {
            cout<<"No item present!"<<endl;
            exit(1);
        }
    return item;
}

template<class T>
void Store<T>::putElem(const T &x)
{
    haveValue = true;//将haveValue置为true，表示item中已存入数值
    item = x;
}

int main()
{
    Store<int>s1,s2;  //定义两个Store<int>类对象，其中数据成员item为int类型
    s1.putElem(3);    //向对象中存入数据。
    s2.putElem(-7);
    cout<<s1.getElem()<<" "<<s2.getElem()<<endl;
    
    Student g = {1000,23};
    Store<Student>s3;
    s3.putElem(g);
    cout<<"The student id is"<<s3.getElem().id<<endl;

    Store<double>d;
    cout<<"Retrieving object d...";
    cout<<d.getElem()<<endl;

    return 0;
}
#endif

/*
    对可直接访问的线性群体，我们可以直接访问群体中任何一个元素，而不必首先访问该元素之前的元素。
    对顺序访问的线性群体，只能按元素的排列顺序从头开始依次访问各个元素。
    有两种特殊的线性群体---栈和队列
    编译系统在处理表达式时，需要确定运算次序。为此，需要建立两个栈:操作数栈(ODS)和操作符栈(OPS),然后自作至右扫描表达式。
用压栈和出栈的方式来处理这些数据。
    栈为先进后出。
    和栈一样，队列也是一种特殊的线性群体。对于队列我们并不陌生，队列是只能向一端添加元素，从另一端删除元素的线性群体，可以
添加元素的一端称为队尾，可以删除元素的一端称为对头。对头位置的标记称为对头指针，对队尾位置的标记称为队尾指针。向队尾添加元
素称为"入队"，删除对头元素称为"出队"。
    队列是先进先出。
*/
/*
    直接访问群体--数组类
    例子:动态数组类模板Array
*/

#if 0
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
int main()
{
    Array<int>a(10);
    Array<int>b(a);
    return 0;
}
#endif
/*
    在原例中，对对象a中数组元素首地址简单赋值给了对象b的指针成员，数组元素并没有真的被复制，对象b根本没有构造自己的数组。
 结果造成对象a和b共同使用同一段内存空间存放数组元素，这样不仅会造成混乱，更严重的是执行析构函数时，会出现严重的错误。
*/

#if 0
void read(int *p,int n)
{
    for(int i = 0; i < n; ++i)
        cin>>p[i];
}
int main()
{
    int a[10];
    read(a,10);
    return 0;
}
#endif

#if 0
#include"Array.h"
void read(int *p,int n)
{
    for(int i = 0; i < n; ++i)
        cin>>p[i];
}
int main()
{
    Array<int>a(10);
    read(a,10);
    return 0;
}
#endif

#if 0
#include<iomanip>
#include"Array.h"
int main()
{
    Array<int>a(10);
    int count = 0;
    int n;
    cout<<"Enter a value >= 2 as limit for prime numbers:";
    cin>>n;
    for(int i = 2; i <= n; ++i)
        {
            bool isPrime = true;
            for(int j = 0; j < count; ++j)
                if(i%a[j] == 0) //若i被a[j]整除，说明i不是质数
                    {
                        isPrime = false;
                        break;
                    }
                if(isPrime)//把i写入质数表中
                        //如果质数表满了，将其空间加倍。
                    {
                        if( count == a.getSize() )
                            a.resize(count*2);
                        a[count++] = i;
                    }
        }
        for(int i = 0; i < count; ++i)
            cout<<setw(8)<<a[i];
        cout<<endl;
    return 0;
}
#endif
/*
    链表类尚未实现，后续记得实现
*/
#if 0
template<class T>
class Node
{
    private:
        Node<T> *next;  //指向后继结点的指针
    public:
        T data;         //数据域
    
    Node(const T &data,Node<T> *next = 0);  //构造函数
    void insertAfter(Node<T> *p);           //在本结点之后插入一个同类结点
    Node<T> *deleteAfter();                 //删除本结点的后继结点，并返回其地址
    Node<T> *nextNode();                    //获取后继结点的地址
    const Node<T> *nextNode() const;           //获取后继结点的地址
};

//返回后继结点的指针
template<class T>
Node<T> *Node<T>::nextNode()
{
    return next;
}

//返回后继结点的指针
template<class T>
const Node<T>* Node<T>::nextNode() const
{
    return next;
}

//在当前结点之后插入一个结点p
template<class T>
void Node<T>::insertAfter(Node<T>*p)
{
    p -> next = next;   //p结点指针域指向当前结点的后继结点
    next = p;           //当前结点的指针域指向p
}

//删除当前结点的后继结点，并返回其地址
template<class T>
Node<T>* Node<T>::deleteAfter()
{
    Node<T>* tempPtr = next;        //将欲删除的结点地址存储到tempPtr中
    if(next == 0)                   //如果当前结点没有后继结点，则返回空指针
        return 0;
    next = tempPtr->next;           //使当前结点的指针域指向tempPtr的后继结点
    return tempPtr;                 //返回被删除的结点的地址
} 
#endif

/*
    栈类:栈也是一种线性群体，因此栈可以用数组或链表来储存，但是对栈中元素的访问是受限的，压入和弹出栈的操作
都只能在栈顶进行，因此不宜直接用数组类和链表类来解决栈的问题，而是需要专门设计栈类。
    要完整地保存栈的信息，栈类的数据成员至少应该包括栈元素和栈顶指针。由于栈元素既可以用数组也可以用链表来存放，栈类的结构
也就有了两种:基于数组和基于链表。用数组来存储栈元素时，不仅可以使用C++语言提供的静态数组，也可以使用vector或介绍的动态数组类
    栈的基本状态有:一般状态，栈空，栈满。当栈中没有元素时称为栈空;当战中元素个数达到上限时，称为栈满;栈中有元素，但未达到栈满
状态时，即处于一般状态。
*/
