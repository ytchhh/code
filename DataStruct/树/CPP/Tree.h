#ifndef _TREE_H
#define _TREE_H

#include"utili.h"

#define Type char


struct TreeNode			//树的结点
{
	Type ch;			//树的元素
	TreeNode *left;		//左子结点
	TreeNode *right;	//右子结点
};

class Tree
{
public:
	Tree(TreeNode *r = NULL):root(r){}
	Tree(int node_num);
	~Tree();

	void AddNode(int i,int j);
	void PreOrder();		//前序遍历
	void print();			//打印
private:
	void print(TreeNode *node,int num);
	void addBrotherNode(TreeNode *bro,TreeNode *node);
	void PreOrder(TreeNode *root);		//前序遍历
	
	TreeNode *root;
};
void Tree::print()
{
	print(root,0);
}

void PrintSpace(int num)
{
	int i = 0;
	for(i = 0; i < num-3; ++i)
		cout<<" ";
	
	for(; i < num-2; ++i)
		cout<<"|";

	for(; i < num; ++i)
		cout<<"_";
}

void Tree::print(TreeNode *node,int num)
{
	if(node != NULL)
	{	
		PrintSpace(num);
		cout<<node->ch<<endl;
		print(node->left,num+4);
		print(node->right,num);
	}
}

//前序遍历
void Tree::PreOrder()
{
	cout<<"前序遍历:";
	PreOrder(root);
	cout<<endl;
}

void Tree::PreOrder(TreeNode *root)
{
	if(root != NULL)
	{
		cout<<root->ch<<" ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

Tree::Tree(int node_num)
{
	root = new TreeNode[node_num];

	char ch = 'A';

	for(int i = 0; i < node_num; ++i)
	{
		root[i].ch = ch + i;
		root[i].left = NULL;
		root[i].right = NULL;
	}
}

//释放所有结点的内存空间
Tree::~Tree()
{
	if(root != NULL)
		delete []root;
}

//addNode将父子结点组对
//如果父节点的firstChild==NULL, 则firstChild = node;
//如果父节点的firstChild != NULL, 则
void Tree::AddNode(int i, int j)
{
    TreeNode* parent = &root[i];
	TreeNode* node = &root[j];

	if(parent->left == NULL)
		parent->left = node;
	else
		addBrotherNode(parent->left, node);
}

//将节点插入到兄弟节点
void Tree::addBrotherNode(TreeNode* bro, TreeNode* node)
{
	if(bro->right == NULL)
		bro->right = node;
	else
		addBrotherNode(bro->right, node);
}
#endif
