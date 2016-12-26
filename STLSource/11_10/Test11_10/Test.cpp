#include<iostream>
#include<new.h>
using namespace std;

int out_of_memory(size_t n)
{
	cout<<"Out Of Memory!"<<endl;
	//exit(1);
	return -1;
}

void main()
{
	_set_new_handler(out_of_memory);
	int *p = new int[10479149179]; //回调方式  operator new
	//int *p = new int[10];
	if(p == NULL)
	{
		cout<<"Out Of Memery."<<endl;
		exit(1);
	}
	cout<<"OK."<<endl;
}

/*
template<class Type , int inst>
class Stack
{
public:
	Stack(int sz = inst)
	{
		capacity = sz > DEFAULT_SIZE ? sz : DEFAULT_SIZE;
		base = new Type[capacity];
		top = 0;
	}
private:
	enum{DEFAULT_SIZE=8};
	Type *base;
	int capacity;
	int top;
};

void main()
{
	Stack<int,10> st;
}
*/