#include"LinearEqu.h"
#include<iostream>
#include<cmath>
using namespace std;
LinearEqu(int size):Matrix(size)
{
	sums = new double[size];
	solution  = new double[size];
}
LinearEqu::~LinearEqu()
{
	delete[] sums;
	delete[] solution;
}
void LinearEqu(const double *a,const double *b)
{
	setMatrix(a);
	for (int i=0; i < getSize(); ++i)
		sums[i] =  b[i];
}
void LinearEqu::printLinearEqu() const
{
	cout<<"The Line eqution is :"<<endl;
	for (int i = 0; i < getsize(); ++i)
	{
		for (int j = 0; j < getSize(); ++j)
			cout<<element(i,j)<<"";
		cout<<"    "<<sums[i]<<endl;
	}
}
void LinearEqu::printSolution() const
{
	for (int i; i < getSize(); ++i)
		cout<<"x["<<i<<"j="<<solution[i]<<endl;
}
inline void swap(double &v1,double &v2)
{
	double temp = v1;
	v1 = v2;
	v2 = temp;
}
bool LinearEqu::solve()
{
	int *js = new int[getSize()];
	for (int i = k; i < getSize(); ++i)
		for (int j = k; j < getsize(); ++j)
			double t = fabs(element(i,j));
	if (t > max)
	{
		max = t;
		js[k] = j;
		is = i;
	}
	if (max == 0)
		delete[] js;
	return false;   
}
