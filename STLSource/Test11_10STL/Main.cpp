#include<iostream.h>
#include<vld.h>
#include"vector"
//#include"stl_alloc.h"

void main()
{
	vector<int> v(10,1);
}

/*
void main()
{
	int *p = (int*)__default_alloc_template<0,0>::allocate(sizeof(int));
	//int *p1 = (int*)__default_alloc_template<0,0>::allocate(sizeof(int));
	int *p2 = (int*)__default_alloc_template<0,0>::allocate(sizeof(int)*32);
	int *p3 = (int*)__default_alloc_template<0,0>::allocate(sizeof(int)*10);
	//int *p4 = (int*)__default_alloc_template<0,0>::allocate(sizeof(int)*6);
}

/*
void out_of_memory()
{
	cout<<"My Out Of Memory."<<endl;
	//exit(1);
}
void main()
{
	__malloc_alloc_template<0>::set_malloc_handler(out_of_memory);
	int *p = (int*)__malloc_alloc_template<0>::allocate(sizeof(int)*10);
	__malloc_alloc_template<0>::deallocate(p,sizeof(int)*10);
}
*/