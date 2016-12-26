#include"Tree.h"

int main()
{
	Tree tree(16);//分配十六个节点

	tree.AddNode(0, 1);
	tree.AddNode(0, 2);
	tree.AddNode(0, 3);
	tree.AddNode(0, 4);
	tree.AddNode(0, 5);
	tree.AddNode(0, 6);
	tree.AddNode(3, 7);
	tree.AddNode(4, 8);
	tree.AddNode(4, 9);
	tree.AddNode(5, 10);
	tree.AddNode(5, 11);
	tree.AddNode(5, 12);
	tree.AddNode(6, 13);
	tree.AddNode(9, 14);
	tree.AddNode(9, 15);

	cout << "Tree1: " << endl;
	tree.PreOrder();
	tree.print();    

	return 0;	
}
