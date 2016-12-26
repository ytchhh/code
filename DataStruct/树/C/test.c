#include"Tree.h"


int main()
{
	Tree t;
	Node *p = NULL,*q = NULL;
	InitTree(&t);
	t.root = Create(&t);
	PreOrder(t.root);
	printf("\n");
	
	InOrder(t.root);
	printf("\n");
	
	PostOrder(t.root);
	printf("\n");
	
	printf("count = %d\n",Count_Tree(t.root));
	printf("height = %d\n",Height(t.root));
	
	if((q = Search(t.root,'b')) != NULL)
		printf("find:%c\n",q->ch);
	else
		printf("not find\n");
	q = Parent(t.root,q);
	printf("%c\n",q->ch);
	return 0;
}
