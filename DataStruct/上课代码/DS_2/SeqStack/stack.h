#ifndef _STACK_H
#define _STACK_H

#include"../utili.h"

template<class Type>
class Stack
{
public:
	Stack(size_t sz = STACK_DEFAULT_SIZE)
	{
		capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
		base = new Type[capacity];
		top = 0;
	}
	~Stack()
	{
		delete []base;
		base = NULL;
		capacity = top = 0;
	}
public:
	bool isfull()const
	{return top >= capacity;}
	bool isempty()const
	{return top == 0;}
public:
	void push(const Type &x)
	{
		if(!isfull())
		{
			base[top++] = x;
		}
	}
	void pop()
	{
		if(!isempty())
		{
			top--;
		}
	}
	Type gettop()const
	{
		if(!isempty())
		{
			//return base[--top]; //
			return base[top-1]; //
		}
	}
	void show_stack()const
	{
		for(int i=top-1; i>=0; --i)
		{
			cout<<base[i]<<endl;
		}
	}
	void clear_stack()
	{top = 0;}
	//void destroy_stack();
	size_t length()const
	{return top;}
private:
	enum{STACK_DEFAULT_SIZE = 8};
	Type *base;
	size_t capacity;
	size_t top; // 0
};

#endif