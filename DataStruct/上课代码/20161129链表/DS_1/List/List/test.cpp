#include "list.h"

int main()
{
	List<int> mylist;
	for(int i=1; i<=10; ++i)
	{
		mylist.push_back(i);
	}
	mylist.show_list();

	ListNode<int> *p = mylist.find(5);
	return 0;
}
