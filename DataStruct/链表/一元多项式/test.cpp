#include"list.h"

int main()
{
	struct List *p,*q;
	p = (List*)malloc(sizeof(List));
	q = (List*)malloc(sizeof(List));
	int m;
	printf("请输入第1个一元多项式的非零项的个数:");
	scanf("%d",&m);
	CreatPolyn(p,m);

	printf("请输入第2个一元多项式的非零项的个数:");
	scanf("%d",&m);
	CreatPolyn(q,m);
	
	PrintPolyn(p);
	PrintPolyn(q);

	return 0;
}
