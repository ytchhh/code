#ifndef _TREE_H
#define _TREE_H

#include"utili.h"

typedef struct node
{
	char ch;
	struct node *left;
	struct node *right;
}Node;

typedef struct tree
{
	Node *root;
	char flag;
}Tree;

void InitTree(Tree *t)	//初始化树函数
{
	t->root = NULL;
	t->flag = '*';
}

Node *Create(Tree *t)	//构造一个树
{
	char ch;
	ch = getchar();
	if(ch == '*')
		return NULL;
	else
	{
		Node *newnode = (Node*)malloc(sizeof(Node));
		newnode->ch = ch;				//前序
		newnode->left = Create(t);
		newnode->right = Create(t);
		return newnode;
	}
}
void PreOrder(Node *root)		//前序遍历
{								//根左右
	if(root != NULL)
	{
		printf("%c ",root->ch);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
void InOrder(Node *root)		//中序遍历
								//左根右
{
	if(root != NULL)
	{
		InOrder(root->left);
		printf("%c ",root->ch);
		InOrder(root->right);
	}
}
void PostOrder(Node *root)		//后序遍历
{								//左右根
	if(root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%c ",root->ch);
	}
}
int Count_Tree(Node *root)		//树的结点的个数
{	/*
	static int i = 0;
	if(root	!= NULL)
	{
		Count_Tree(root->left);
		Count_Tree(root->right);
		++i;
	}
	return i;
	*/
	
	if(root == NULL)
			return 0;
	else
		return Count_Tree(root->left)+Count_Tree(root->right)+1;

}
int Height(Node *root)		//层数
{
	if(root == NULL)
		return 0;
	else
	{
		int h1 = Height(root->left);
		int h2 = Height(root->right);
		return h1 > h2 ? (h1+1) : (h2+1);
	}
}
Node* Search(Node *root,char k)		//查找
{
	Node *q = NULL;
	if(root == NULL)
		return NULL;
	if(root->ch == k)
		return root;
	q = Search(root->left,k);
	if(q != NULL)
		return q;
	else
		q = Search(root->right,k);
}
Node* Parent(Node *root,Node *p)
{
	Node *q = NULL;
	if(root == NULL)
		return NULL;
	if(root->left == p || root->right == p)
		return root;
	q = Parent(root->left,p);
	if(q != NULL)
		return q;
	return Parent(root->right,p);
}
#endif
