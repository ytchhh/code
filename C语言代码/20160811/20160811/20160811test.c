#if 1 
//copyright@ 泡泡鱼   2. //July、2010.06.02。   
//@lingyun310：先对元素数组原地建最小堆，O(n)。然后提取K次，但是每次提取时，   
//换到顶部的元素只需要下移顶多k次就足够了，下移次数逐次减少。此种方法的复杂度为O(n+k^2）。   
#include <stdio.h>   
#include <stdlib.h>   
#define MAXLEN 1000   
#define K 10         
void HeapAdjust(int array[], int i, int Length) //创堆   
{   
 int child,temp;   

 for(temp = array[i]; 2*i+1 < Length; i = child)   
	{   
		child = 2*i+1;   
		if(child < Length-1 && array[child+1] < array[child])   
		child++;   
		if (temp > array[child])   
		array[i] = array[child];   
		else   
		break;   
		array[child] = temp;   
	}   
}       
	void Swap(int* a,int* b)   
	{   
	//*a=*a^*b;   
	//*b=*a^*b;   
	//*a=*a^*b;   
	int t;
	t = *a;
	*a = *b;
	*b = t;
	}   
    
	int GetMin(int array[], int Length,int k)   
	{   
	int min=array[0]; // 小顶堆中第一个元素是最小的，先保存起来   
	int child,temp;   //
	int i=0,j=k-1;    //i = 0,
	Swap(&array[0],&array[Length-1]); //把第一个元素和最后面的元素相交换，    
	for (temp=array[0]; j>0 && 2*i+1<Length; --j,i=child)//   
	{  //先将较大的元素保存，找到他的位置后再放入     //j是需要下移的次数 
	child = 2*i+1; //1   
	if(child < Length-1 && array[child+1] < array[child])   
    child++;     //找到两个儿子当中较小的那个
	if (temp > array[child])   //如果第一个元素比他（儿子）大的话
	array[i] = array[child];   //就将第一个元素赋值为他的儿子中较小的那个
	else   
	break;   //如果子节点比父结点的值大的话，就跳出循环 因为本身就满足小顶堆的性质
	array[child] = temp;   
	}   
        
	return min;   
	}   
   
	void Kmin(int array[] , int Length , int k)   
	{   
		int i=Length/2;
		int j=Length;
	for(; i>=0; --i)    
	//初始建堆，时间复杂度为O(n)   
	HeapAdjust(array,i,Length);   
     for (i=0; i<100;++i)
		 printf("%d ",a[i]);
     printf("\n");
	//int j=Length;   
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
	int i=MAXLEN;
	for(; i>0; --i)   
	array[MAXLEN-i] = i;   
        
	Kmin(array,MAXLEN,K);   
	return 0;   
	}   
#endif
#if 0
#include<stdio.h>
#define MAXLEN 100   
#define K 10 
void Kmin(int a[],int length,int k);
void creatheap(int a[],int root,int len);
int main()
{
 int a[MAXLEN];
 int i= MAXLEN;
 for(; i>0; --i)
	 a[i-1] = MAXLEN-i;
 a[0]=0;
 Kmin(a,MAXLEN,K); 
 return 0;
}
void Kmin(int a[],int length,int k)
{
 int i=length/2;
		int j=length;
		int t;
	for(; i>=1; --i)       //初始建堆，时间复杂度为O(n)   
	creatheap(a,i,MAXLEN); 
	for (i=1; i<MAXLEN; ++i)
		printf("%d ",a[i]);
	printf("\n");
	for(i=k; i>0; --i,--j) //k次循环，每次循环的复杂度最多为k次交换，复杂度为o(k^2)   
	{     
	 t=a[1];
     a[1]=a[j];
     a[j]=t;
	 printf("%d,", t);
	 creatheap(a,i,j);
	}   
}
void creatheap(int a[],int root,int len) //创堆 可以根据自己的需要创立大根堆或者小根堆
{
 int i=2*root;    //从根节点开始沿着关键字比较大的结点开始向下筛选。
 int t=a[root];   //先将父结点的值保存起来，方便之后的比较和赋值。
 int flag=0;      //用一个中间值来判断是否父结点大于子结点。
 while (i <= len && flag == 0)
 {
  if (i<len)  //如果i<len 说明有两个子结点
  {
   if (a[i]>a[i+1]) //找到子结点中两个比较大的 将i标记为比较大的.
	   i++;
  }
  if (t <= a[i])  //如果父结点大于子结点的话 就可以不用去交换 并且结束循环。
	  flag=1;      
  else
  {               //如果父结点小于子结点的话，要先将父结点的值和其交换 再将i的值扩大为两倍。
   a[i/2]=a[i];   //再次进入循环 ，判断 如果i是小于总的长度的话 说明其下面还是有子结点的 
   i=i*2;         //就要再次进入比较，如果i的长度大于总的长度的话，说明下面没有子结点了。
  }               //就可以退出循环
 }
 a[i/2]=t;   //退出循环后，要将最原始要交换的值放到相对应的位置。
}
#endif

