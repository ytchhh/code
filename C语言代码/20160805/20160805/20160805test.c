#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#if 0
int fun(char *sl,char *s2)
{ int i=0;
while(sl[i]==s2[i]&&s2[i]!='\0') i++;
return(sl[i]=='\0'&&s2[i]=='\0');
}

int main()
{
 char a[20],b[20];
 char *s1=NULL,*s2=NULL;
 int n;
 gets(a);
 gets(b);
 s1=a;
 s2=b;
 n=fun(s1,s2);
 printf("%d\n",n);
 return 0;
}
#endif
#if 0//1，1直接插入排序
void insertSort(int a[]);
int main()
{
 int a[]={49,38,65,97,76,13,27};
 int i;
 for (i=0; i<7; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 insertSort(a);
 for (i=0; i<7; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 return 0;
}
void insertSort(int a[])
{
 int i,j,t;
 for (i=1; i<7; ++i)// 初始的时候认为a[0]是有序的，其余为无序子序列。
 {
  for (j=i; j>0; --j)//从后面依次取元素往有序的序列里面插入数据，
   if (a[j]<a[j-1])  //用遍历的方法找到应该插入的位置，每次都交换数据
   {
    t=a[j];
	a[j]=a[j-1];
	a[j-1]=t;
   }
 }
}
#endif
#if 0 //1.2直接插入排序（加入哨兵）
void insertSort(int a[]);
int main()
{
 int a[]={0,49,38,65,97,76,13,27};
 int i;
 for (i=1; i<8; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 insertSort(a);
 for (i=1; i<8; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 return 0;
}
void insertSort(int a[])
{
 int i,j,k;
 for (i=2; i<8; ++i) //初始时认为a[1]是有序序列，其余为无序序列。
   if (a[i]<a[i-1]) //如果插入数据小于最后一个关键字，则
	  {
	   a[0]=a[i];  //先将插入的关键字复制为哨兵
	   a[i]=a[i-1]; //将有序的序列最后一个数据后移一位
	  for (j=i-2; j>0&&a[0]<a[j]; --j)//一边比较一边后移
		  a[j+1]=a[j]; //将有序序列中大于哨兵的的部分整体后移一位
	  a[j+1]=a[0];  //找到合适的位置，插入哨兵
      }
}
#endif
#if 0
void BinsertSort(int a[]);
int main()
{
 int a[]={0,49,38,65,97,76,13,27};
 int i;
 for (i=1; i<8; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 BinsertSort(a);
 for (i=1; i<8; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 return 0;
}
void BinsertSort(int a[]) //折半查找也是在加入哨兵的基础上对有序数列进行这般法查找
{
 int low,high,m,i,j;
 for (i=2; i<8; ++i) //初始时认为a[1]是有序序列，其余为无序序列。
 {
  a[0]=a[i];     //先将插入的关键字复制为哨兵
  low=1;high=i-1; 
  while (low <= high) //用折半查找的方法来确定插入数据在有序序列中应该插入的位置
  {
   m=(low+high)/2;
   if (a[0]<a[m])
	   high=m-1;
   else
	   low=m+1;
  }
  for (j=i-1; j>= high+1; --j)  //将有序序列中大于插入数据的都后移一位
	  a[j+1]=a[j];
  a[j+1]=a[0]; //将插入的数据放入合适的位置
 }
}
#endif
#if 0 //归并排序
void remsort(int a[],int b[],int left,int right);
void merge(int a[],int b[],int left,int mid,int right);
int main()
{ 
 int a[]={49,38,65,97,76,13,27,49};
 int b[20];
 int left,right,i;
 left=0;
 right=6;
 for (i=0; i<7; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 remsort(a,b,left,right);
 for (i=0; i<7; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 return 0;
}
void remsort(int a[],int b[],int left,int right)
{
 int mid=(left+right)/2; //将原记录序列平分成两部分，
 if (left>=right)  //当只有一个数据的时候，本身就是有序的，作为递归终止的条件
	 return ;
 remsort(a,b,left,mid); //递归的将左边的部分进行排序，
 remsort(a,b,mid+1,right); //递归的将右边的序列进行排序，
 merge(a,b,left,mid,right); //将两个有序的序列合并成一个新的序列a
}
void merge(int a[],int b[],int left,int mid,int right)
{
 int i;
 int s1,s2,k;
 for (i=left; i <= right; ++i) //将a里面的数据先保存到b里面去。
	 b[i]=a[i];
 s1=left; //用s1来记录首个元素
 s2=mid+1;//用s2来记录第二部分首个元素
 k=left; //用k来初始化位置
 while (s1<=mid&& s2<= right) //用while循环将两个部分进行合并 并排序
 {
  if (b[s1]<=b[s2])
	  a[k++]=b[s1++];
  else 
	  a[k++]=b[s2++];
 }
 while (s1<=mid)    //如果有剩余元素没有排进去的，用while 循环依次赋值进去
	 a[k++]=b[s1++];
 while (s2<=right)
	 a[k++]=b[s2++];
}
#endif
#if 0//快速排序是对冒泡法的改进
int quicksort(int a[],int left,int right);
void Qsort(int a[],int left,int right);
int main()
{
 int a[]={49,38,65,97,76,13,27,49};
 int left,right,i;
 left=0;
 right=6;
 for (i=0; i<7; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 Qsort(a,left,right);
 for (i=0; i<7; ++i)
	 printf("%d ",a[i]);
 printf("\n");
 return 0;
}
void Qsort(int a[],int left,int right)
{
	int p; //用以标志枢轴的位置
 if (left <right)
 {
  p=quicksort(a,left,right); //确定列表L中枢轴的最终位置
  Qsort(a,left,p-1); //对枢轴左部的子列表进一步划分
  Qsort(a,p+1,right); //对枢轴右部的子列表进一步划分
 }
}
int quicksort(int a[],int left,int right)
{
 int k;
 k=a[left]; //用k来保存每次的关键字,为了减少交换的次数，将关键字先保存，等循环结束，也就是确定
            //最终位置的时候，再将其移过去。
 while (left<right) //当left=right的时候，就确定了枢轴的最终位置，
 {
  while (left <right&&a[right]>=k) //向左移动right，越过不小于枢轴的记录，到达第一个小于枢轴的记录，
	  right--;    //
   a[left]=a[right];  //将小于枢轴的记录与枢轴“想交换”
   while (left <right&&a[left]<=k) //向右移动left，越过小于枢轴的记录，到达第一个不比枢轴小的记录，
	   left++;   //将不小于枢轴的记录与与枢轴交换
   a[right]=a[left]; 
 }
 a[left]=k; //确定了枢轴最终位置，可以将其移过来
 return left; //返回枢轴最终位置
}
#endif
#if 0  //类堆排序也是属于选择排序中的一种，不过用创堆的方式的效率比较高。
void sort(int a[],int len);
void print(int a[],int len);
void creatheap(int a[],int root,int len);
int main()
{
 int a[]={0,49,38,65,97,76,13,27,49}; //使用类堆排序的时候，要将数组的下标进行改变，a[0]不存放元素
 int len=sizeof(a)/sizeof(a[0])-1;
 sort(a,len);
 print(a,len);
 return 0;
}
void print(int a[],int len)
{
 int i;
 for (i=1; i<=len; ++i)
	 printf("%d ",a[i]);
 printf("\n");
}
void sort(int a[],int len)
{
 int i;
 int t;
 for (i=len/2; i>=1; --i)  //创立初始堆，从长度的一半的位置开始创立，
	 creatheap(a,i,len);
 for (i=len; i>=1; --i)  //将堆顶的元素移到最后，并将无序的部分再次重新创立为堆
 {
  t=a[1];
  a[1]=a[i];
  a[i]=t;
  creatheap(a,1,i-1);
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
   if (a[i]<a[i+1]) //找到子结点中两个比较大的 将i标记为比较大的.
	   i++;
  }
  if (t >= a[i])  //如果父结点大于子结点的话 就可以不用去交换 并且结束循环。
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
