#ifndef _STACK_H
#define _STACK_H

#include"utili.h"

#define STACK_INCREMENT 2


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
	void push(const Type &x);		
	bool pop();					
   	void show_stack();	
	Type GetTop();
	void clear_stack();
	bool Is_Full();
	bool Is_Empty();
private: 
	enum{STACK_DEFAULT_SIZE = 8};
	Type *base;
	size_t	capacity;
	size_t	top;
};
////////

template<class Type>
void Stack<Type>::push(const Type &x)
{
	if(Is_Full() == true)
	{
		base = (Type*)realloc(base,(capacity+STACK_INCREMENT) * sizeof(Type));
		if(!base)
			exit(1);		//存储分配失败
		capacity += STACK_INCREMENT;
	}
	base[top++] = x;
}

template<class Type>
void Stack<Type>::show_stack()
{
	int i = top;
	while(i > 0)
	{
		cout<<base[i-1]<<endl;
		--i;
	}
}

template<class Type>
bool Stack<Type>::pop()
{
	if(Is_Empty() == true)
		return false;
	top--;
	return true;
}

template<class Type>
Type Stack<Type>::GetTop()
{
	if(this->Is_Full() == true)
		return 0;
	return base[top-1];
}

template<class Type>
void Stack<Type>::clear_stack()
{
	top = 0;
}

template<class Type>
bool Stack<Type>::Is_Empty()
{
	if(top == 0)
		return true;
	else
		return false;
}

template<class Type>
bool Stack<Type>::Is_Full()
{
	if(top == capacity + 1)
		return true;
	else
		return false;
}

//////////////////////////////


#endif
