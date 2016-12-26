#include<iostream>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define PF(x) printf(#x" square is %d\n",((x)*(x)));
    //#x代表的是取当前的值
//在使用宏定义的时候，要进来将其中的的每个参数用括号括起来

#if 0
int main()
{
    int *p = (int*)malloc(sizeof(int)*10);
    assert(p != NULL);//assert的意思是断言，预测。
    cout<<"OK."<<endl;
    return 0;
}
#endif

#if 0
int main()
{
    int *p; 
    //= (int*)malloc(sizeof(int) * 10);
    if(NULL == p)
        {
            cout<<"Out of Memory."<<endl;
            exit(1);
        }
    cout<<"OK."<<endl;
    return 0;
}
#endif

#if 0
void _my_assert(void *exp,void *file,unsigned int line)
{
    cout<<"Assert Fail:>"<<(char*)exp<<endl;
    cout<<"file name:>"<<(char*)file<<endl;
    cout<<"line:>"<<line<<endl;
    abort();
}

#define my_assert(exp)\
(void)((exp) || (_my_assert(#exp,__FILE__,__LINE__),0))
//\为续行符

int main()
{
    cout<<__FILE__<<endl;
    cout<<__LINE__<<endl;
    cout<<__DATE__<<endl;
    cout<<__TIME__<<endl;
    int a = 0;
    my_assert(a != 0);
    cout<<"OK."<<endl;
    return 0;
}
#endif

#if 0
#define ADD(a,b) ((a) + (b))
#define MUL(a,b) ((a) * (b))
int main()
{
    cout<<MUL(2+3,3+4)<<endl;//(2+3)*(3+4)
    cout<<ADD(1,2)*ADD(3,4)<<endl;//((1) + (2))*((3) + (4))
    return 0;
}
#endif
/*
int main()
{
    PF(2+3);
    return 0;
}
*/