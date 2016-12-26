#include"list.h"

void main()
{
	List<int> mylist;
	int select = 1;
	int pos;
	ElemType Item;
	ListNode<ElemType> *p = NULL;
	while(select)
	{
		cout<<"**************************************"<<endl;
		cout<<"[1]push_back       [2]push_front     *"<<endl;
		cout<<"[3]show_list       [0]quit_system    *"<<endl;
		cout<<"[4]pop_back        [5]pop_front      *"<<endl;
		cout<<"[6]insert_val      [*7]insert_pos    *"<<endl;
		cout<<"[8]delete_val      [*9]delete_pos    *"<<endl;
		cout<<"[10]find           [11]clear         *"<<endl;
		cout<<"[12]sort           [13]resver        *"<<endl;
		cout<<"**************************************"<<endl;
		cout<<"input select:>";
		cin>>select;
		switch(select)
		{
		case 1:
			cout<<"input data(-1 over):>";
			while(cin>>Item, Item!=-1)
			{
				mylist.push_back(Item);
			}
			break;
		case 2:
			cout<<"input data(-1 over):>";
			while(cin>>Item, Item!=-1)
			{
				//mylist.push_front(Item);
			}
			break;
		case 3:
			mylist.show_list();
			break;
			
		case 4:
			//mylist.pop_back();
			break;
		case 6:
			cout<<"input data:>";
			cin>>Item;
			//mylist.insert(Item);
			break;
		case 7:
			cout<<"input insert pos:>";
			cin>>pos;
			cout<<"input data:>";
			cin>>Item;
			//insert(&mylist, pos, Item);
			break;
		case 8:
			cout<<"input delete key:>";
			cin>>Item;
			//mylist.erase(Item);
			break;
		case 10:
			cout<<"input find key:>";
			cin>>Item;
			//p = mylist.find(Item); //i  -1
			break;
		case 11:
			//mylist.clear();
			break;
		case 12:
			//mylist.sort();
			break;
		case 13:
			mylist.resver();
			break;
		default:
			break;
			
		}
		system("pause");
		system("cls");
	}

}