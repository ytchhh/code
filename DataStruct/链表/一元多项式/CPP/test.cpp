#include"list.h"

int main()
{
	List my_list1,my_list2;
	int m;
	cout<<"请输入第一个非零多项式的个数:>";
	cin>>m;
	my_list1.CreatPolyn(m);
	my_list1.PrintPolyn();
	
	cout<<"请输入第二个非零多项式的个数:>";
	cin>>m;
	my_list2.CreatPolyn(m);
	my_list2.PrintPolyn();
	
	//my_list1.AddPolyn(my_list2);
	//cout<<"相加后的结果为:"<<endl;
	//my_list1.PrintPolyn();

	//cout<<"相减后的结果为:"<<endl;
	//my_list1.SubtractPolyn(my_list2);
	//my_list1.PrintPolyn();
	
	//my_list1.MultiplyPolyn(my_list2);
	//cout<<"相乘后的结果为:"<<endl;
	//my_list1.PrintPolyn();

	return 0;
}
