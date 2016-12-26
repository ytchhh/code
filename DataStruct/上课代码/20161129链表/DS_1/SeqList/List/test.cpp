#include"list.h"

void main()
{
	List mylist;
	InitList(&mylist);
	int select = 1;
	int pos;
	ElemType Item;
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
				push_back(&mylist, Item);
			}
			break;
		case 2:
			cout<<"input data(-1 over):>";
			while(cin>>Item, Item!=-1)
			{
				push_front(&mylist, Item);
			}
			break;
		case 3:
			show_list(&mylist);
			break;
			
		case 4:
			//pop_back(&mylist);
			break;
		case 6:
			cout<<"input data:>";
			cin>>Item;
			//insert(&mylist,Item);
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
			//erase(&mylist, Item);
			break;
		case 10:
			cout<<"input find key:>";
			cin>>Item;
			//pos = find(&mylist, Item); //i  -1
			//cout<<"pos = "<<pos<<endl;
			break;
		case 12:
			//sort(&mylist);
			break;
		case 13:
			//resver(&mylist);
			break;
		default:
			break;
			
		}
		system("pause");
		system("cls");
	}
}