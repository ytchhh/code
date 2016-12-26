#pragma once
#include"mylist.h"

template<class Item>
struct ListIter
{
	Item *ptr;
	
	ListIter(Item *p = 0):ptr(p){}

	//不必实现copy ctor,因为编译器已经有默认的
	//不必实现operator=,因为编译器已经有默认的

	Item& operator*() const {return *ptr;}
	Item* operator->() const {return ptr;}

	//以下两个operator遵循标准做法，
	//前加加

	ListIter operator++()
	{
		ptr = ptr->next();
		return *this;
	}
	ListIter operator++(int)
	{
		ListIter tmp = *this;
		++*this;
		return tmp;
	}
	bool operator==(const ListIter& i) const
	{
		return ptr == i.ptr;
	}
	bool operator!=(const ListIter& i) const
	{
		return !(*this == i);
	}
};

