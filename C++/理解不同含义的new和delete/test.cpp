/*
    人们好像喜欢故意使C++语言的术语难以理解，比如new操作符(new operator)和操作new操作(operator)
例如:
string *ps = new string("Memory Management");
    这时候你所使用的new是new操作符。这个操作符就像sizeof一样是语言内置的，你不能改变他的含义，它的功能
总是一样的。它要完成的功能分成两个部分。第一部分是分配足够的内存以便容纳所需类型的对象。第二部分是它
调用构造函数初始化内存中的对象。new操作符总是做这两件事，你不能以任何方式改变它的行为。
    你所能改变的是如何为对象分配内存。new操作符调用一个函数来完成必需的内存分配，你能够重写或重载这个
函数来改变它的行为。new操作符为分配内存所调用的函数的名字是 operator new。
    函数operator new 通常这样声明:
    void* operator new(size_t size);
    返回值类型是void*,因为这个函数返回一个未经处理的指针，未初始化的内存，参数size_t确定分配多少内存，
你能增加额外的参数重载函数operator new,但是第一个参数类型必须是size_t.()
    你一般不会直接调用operaator new,但是一旦这么做，你可以像调用其他函数一样调用它。
void *rawMemory = operator new(sizeof(string));
    操作符operator new 将返回一个指针，指向一块足够容纳一个string类型对象的内存。
    就像malloc一样，operator new 的职责职责只是分配内存。他对构造函数一无所知，operator new所了解的
是内存分配。把operator new 返回的未经处理的指针传递给一个对象是new操作符的工作。当你的编译器遇见这样的
语句:
    string *ps = new string("Memory Management");
    它生成的代码或多或少与下面的代码相似：
void *memory =                  //得到未经处理的内存
    operator new(sizeof(string));//为String对象
call string::string("memory Management")//初始化
on *memory;                             //内存中

string *ps = static_cast<string*>(memory);      //新的对象
    注意第二步包含了构造函数的调用，你做为一个程序员被禁止这样去做。你的编译器没有这个约束，它可以做它想做
因此如果你想建立一个堆对象就必须用new操作符，不能直接调用构造函数来初始化对象。

    placement new
    有时你确实想直接调用构造函数，在一个已存在的对象上调用构造函数是没有意义的，因为构造函数用来初始化对象，而一个
对象仅仅能在给它初值时被初始化一次。但是有时一些已经被分配但是尚未处理的内存，你需要在这些内存中构造一个对象。
你可以使用一个特殊的operator new,它被称为placement new。
    class Widget
    {
    public:
        Widget(int WidgetSize);
    };
    Widget *constructWidgeInBuffer(void *buffer,int WidgetSize)
    {
        return new(buffer)Widget(WidgetSize);
    }
这个函数返回一个指针，指向一个Widget对象，对象在传递给函数的buffer里分配。当程序使用共享内存
或memory-mapped时这个函数可能有用，因为在这样程序里对象必须被放置在一个确定地址上，或一块被
例程分配的内存中。
    在constructWidgeInBuffer里面，返回的表达式为:
    new(buffer)Widget(WidgetSize)
这个看上去有些陌生，但是它是new操作符的一个用法，需要使用一个额外的变量(buffer),当new操作符隐含
调用operator new函数时，把这个变量传递给它，被调用的operator new除了持有强制的参数size_t外，
还必须接受void*指针参数，指向构造对象占用的内存空间，这个operator new 就是placement new ,它
看上去像这样:
    void* operator new(size_t,void* location)
    {
        return location;
    }
这可能比你期望的要简单，但是这就是placement new需要做的事，毕竟operator new的目的是为对象分配
内存然后返回指向该内存的指针。在使用placement new的情况下，调用者已经获得了指向内存的指针，因为
调用者知道对象应该放在哪里。placement new必须做的是就是返回传递给它的指针，placement new是标准
C++库的一部分，为了使用placement new,你必须使用语句#include<new>
    从placement new看，new操作符和operator new的关系，你想在堆上建立一个对象，应该用new操作符，
它既分配内存又为对象调用析构函数，如果你仅仅想分配内存，就应该调用operator new函数，它不会调用构造函数
如果你想定制自己在堆对象被建立时的内存分配过程，你应该写你自己的operator new函数。然后使用new操作符，
new操作符会调用你定制的operator new.如果你想在一块已经获得指针的内存里建立一个对象，应该用placement new.

*/