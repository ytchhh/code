#include"list.h"

int main()
{
	List<int> mylist;
	int select = 1;
	ElemType Item;
	int postion;
	while(select)
	{
		cout<<"******************************************"<<endl;
		cout<<"[1]push_back       [2]push_front         *"<<endl;
		cout<<"[3]show_list       [0]quit_system        *"<<endl;
		cout<<"[4]pop_back        [5]pop_front          *"<<endl;
		cout<<"[6]insert_val      [7]delete_val         *"<<endl;
		cout<<"[8]find            [9]clear              *"<<endl;
		cout<<"[10]sort           [11]reverse           *"<<endl;
		cout<<"[12]ListEmpty      [13]ListLength        *"<<endl;
		cout<<"[14]GetElem        [15]LocateElem        *"<<endl;
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
		/*
		case 4:
			if(mylist.pop_back() == false)
				cout<<"删除失败!"<<endl;
			else
				cout<<"删除成功!"<<endl;
			break;
		*/
		case 5:
			if(mylist.pop_front() == false)
				cout<<"删除失败"<<endl;
			else
				cout<<"删除成功"<<endl;
			break;
		case 6:
			cout<<"请输入要插入的值:>";
			cin>>Item;
			mylist.insert(Item);
			break;
		case 7:
			cout<<"请输入要删除的值:"<<endl;
			cin>>Item;
			if(mylist.erase(Item) == false)
				cout<<"删除失败"<<endl;
			else
				cout<<"删除成功"<<endl;
			break;
		case 8:
			cout<<"请输入要查找的值:>";
			cin>>Item;
			if(NULL == mylist.find(Item))
				cout<<"查无此值!"<<endl;
			else
				cout<<"地址为:"<<mylist.find(Item)<<endl;
			break;
		case 9:
			mylist.clear();
			break;
		case 10:
			mylist.sort();
			break;
		case 11:
			mylist.reverse();
			break;
		/*
		case 12:
			if(mylist.ListEmpty() == true)
				cout<<"线性表为空"<<endl;
			else
				cout<<"线性表不为空"<<endl;
			break;
		case 13:
			cout<<"线性表的长度为:"<<mylist.ListLength()<<endl;
		case 14:
			cout<<"请输入要查找的位置:>";
			cin>>postion;
			if(mylist.GetElem(postion,Item) == false)
				cout<<"查无此值"<<endl;
			else
				cout<<"查到了"<<Item<<endl;
			break;
		case 15:
			cout<<"输入要查找的数:";
			cin>>Item;
		if(mylist.LocateElem(Item,compare) == 0)
				cout<<"没有找到满足的位置"<<endl;
			else 
				cout<<"找到了位置"<<endl;
		*/
		default:
			break;
		}
	#define _TIME_
	#define _DATE_

	}
	return 0;
}
