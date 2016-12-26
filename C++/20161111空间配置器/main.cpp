#include<iostream>
#include<stdlib.h>

//#include"stl_alloc.h"
#include"vector"
using namespace std;

/*				//用来测试一级空间配置器的
void out_of_memory()
{
	cout<<"My Out Of Memory."<<endl;
	exit(1);
}
int main()
{
	__malloc_alloc_template<0>::set_malloc_handler(out_of_memory);
	int *p = (int*)__malloc_alloc_template<0>::allocate(sizeof(int) * 1232412231231);
	__malloc_alloc_template<0>::deallocate(p,sizeof(int) * 10);
	return 0;
}
*/

/*
int main()
{
	int *p = (int*)__default_alloc_template<0,0>::allocate(sizeof(int));
	int *p1 = (int*)__default_alloc_template<0,0>::allocate(sizeof(int));
	int *p2 = (int*)__default_alloc_template<0,0>::allocate(sizeof(int) * 4);
	return 0;
}
*/

int main()
{
	vector<int> V(10,1);
	return 0;
}
