    #include<iostream>
    //copyright@ 泡泡鱼   2. //July、2010.06.02。   
	//@lingyun310：先对元素数组原地建最小堆，O(n)。然后提取K次，但是每次提取时，   
	//换到顶部的元素只需要下移顶多k次就足够了，下移次数逐次减少。此种方法的复杂度为O（n+k^2）。   
	#include <stdio.h>   
	#include <stdlib.h>   
	#define MAXLEN 100   
	#define K 10   
    
	//   
	void HeapAdjust(int array[], int i, int Length)   
	{   
	int child,temp;   

	for(temp=array[i];2*i+1<Length;i=child)   
	{   
	child = 2*i+1;   
	if(child<Length-1 && array[child+1]<array[child])   
	child++;   
	if (temp>array[child])   
		array[i]=array[child];   
	else   
	break;   
	array[child]=temp;   
	}   
	}   
    
	void Swap(int* a,int* b)   
	{   
	*a=*a^*b;   
	*b=*a^*b;   
	*a=*a^*b;   
	}   
    
	int GetMin(int array[], int Length,int k)   
	{   
	int min=array[0];   
	Swap(&array[0],&array[Length-1]);   
        
	int child,temp;   
	int i=0,j=k-1;   
	for (temp=array[0]; j>0 && 2*i+1<Length; --j,i=child)   
	{   
	child = 2*i+1;   
	if(child<Length-1 && array[child+1]<array[child])   
	child++;   
	if (temp>array[child])   
	array[i]=array[child];   
	else   
	break;   
	array[child]=temp;   
	}   
      
	return min;   
	}   
    
	void Kmin(int array[] , int Length , int k)   
	{   
		int i;
	for(i=Length/2-1;i>=0;--i)    
	//初始建堆，时间复杂度为O(n)   
	HeapAdjust(array,i,Length);
	for (i=0; i<100; ++i)
		printf("%d ",array[i]);
	printf("\n");
	int j=Length;   
	for(i=k;i>0;--i,--j)    
	//k次循环，每次循环的复杂度最多为k次交换，复杂度为o(k^2)   
	{   
		int min=GetMin(array,j,i);   
	printf("%d,", min);   
	}   
	}   
    
	int main()   
	{   
	int array[MAXLEN];   
	for(int i=MAXLEN;i>0;--i)   
	array[MAXLEN-i] = i;   
	Kmin(array,MAXLEN,K);   
	return 0;   
	}   
