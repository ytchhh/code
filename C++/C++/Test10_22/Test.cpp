#include<iostream>
#include<assert.h>
using namespace std;

#define PF(x)  printf(#x" square is %d\n",((x)*(x)));

void main()
{
	PF(2+3);
}

/*
#define ADD(a,b) ((a)+(b))
#define MUL(a,b) ((a)*(b))

void main()
{
	cout<<MUL(2+3,3+4)<<endl; //(2+3)*(3+4)
	cout<<ADD(1,2)*ADD(3,4)<<endl; //((1)+(2))*((3)+(4))
}


//Code

void  _my_assert(void *exp, void *file, unsigned int line)
{
	cout<<"Assert Fail:>"<<(char*)exp<<endl;
	cout<<"file name:>"<<(char*)file<<endl;
	cout<<"line:>"<<line<<endl;
	abort();
}

#define my_assert(exp) \
(void)((exp)||(_my_assert(#exp,__FILE__,__LINE__),0))

//ÐøÐÐ
void main()
{
	//cout<<__FILE__<<endl;
	//cout<<__LINE__<<endl;
	//cout<<__DATE__<<endl;
	//cout<<__TIME__<<endl;
	int a = 0;
	my_assert(a != 0);
	/////////////////////////////////
	cout<<"OK."<<endl;
}

/*
void main()
{
	int *p = (int*)malloc(sizeof(int) * 10);
	assert(p != NULL); //¶ÏÑÔ Ô¤ÑÔ
	cout<<"OK."<<endl;
}

/*

void main()
{
	int *p = (int*)malloc(sizeof(int) * 10);
	if(NULL == p)
	{
		cout<<"Out Of Memory."<<endl;
		exit(1);
	}
	cout<<"OK."<<endl;
}
*/