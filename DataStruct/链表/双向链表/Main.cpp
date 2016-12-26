#include"list.h"

int main()
{
	List<int> mylist;
	int select = 1;
	ElemType Item;
	int postion,value;
	while(select)
	{
		cout<<"******************************************"<<endl;
		cout<<"[1]push_back       [2]push_front         *"<<endl;
		cout<<"[3]show_list       [0]quit_system        *"<<endl;
		cout<<"[4]pop_back        [5]pop_front          *"<<endl;
		cout<<"[6]insert_val      [7]delete_val         *"<<endl;
		cout<<"[8]find            [9]clear              *"<<endl;
		cout<<"[10]sort           [11]reverse           *"<<endl;
		cout<<"[12]Is_Full        [13]"<<endl;
		cout<<"******************************************"<<endl;
		cout<<"input select:->";
		cin>>select;
		switch(select)
		{
		case 1:
			cout<<"input data(-1 Over):>";
			while(cin>>Item,Item != -1)
				mylist.push_back(Item);
			break;	
		case 2:
			cout<<"input data(-1 Over):>";
			while(cin>>Item,Item != -1)
				mylist.push_front(Item);
			break;
		case 3:
			mylist.show_list();
			break;
		case 4:
			mylist.pop_back();
			break;
		case 5:
			mylist.pop_front();
			break;
		case 6:
			cout<<"输入要插入位置的值和插入的元素:>";
			cin>>Item>>value;
			mylist.insert(mylist.find(Item),value);
			break;
		case 7:
			cout<<"请输入要删除的值:";
			cin>>Item;
			if(false == mylist.delete_val(Item))
				cout<<"删除失败"<<endl;
			else
				cout<<"删除成功"<<endl;
			break;
		case 8:
			cout<<"请输入要查找的值:"<<endl;
			cin>>Item;
			if(mylist.find(Item) == NULL)
				cout<<"没有找到"<<endl;
			else
				cout<<"找到"<<endl;
		case 9:
			mylist.clear();
			break;
		case 10:
			mylist.sort();
			break;
		case 11:
			mylist.reverse();
			break;
		case 12:
			if(mylist.Is_Full() == true)
				cout<<"空"<<endl;
			else
				cout<<"不空"<<endl;
		default:
			break;
		}
	}
	return 0;
}
