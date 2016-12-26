#include<stdio.h>
#include"seqlist.h"

int main()
{
	SeqList mylist;
	InitSeqList(&mylist);
	ElemType Item,p,v;
	int select = 1;
	while(select)
	{
		printf("***************************************\n");
		printf("[1]push_back      [2]push_front       *\n");
		printf("[3]show_list      [0]quit_system      *\n");
		printf("[4]pop_back       [5]pop_front        *\n");
		printf("[6]insert_pos     [7]insert_val       *\n");
		printf("[8]delete_pos     [9]delete_val       *\n");
		printf("[10]find_val      [11]length	      *\n");
		printf("[12]isfull        [13]isempty         *\n");
		printf("[14]clear         [15]resever	      *\n");
		printf("[16]sort          [17]ListInsert      *\n");
		printf("***************************************\n");
		printf("please input select:>");
		scanf("%d",&select);
		switch(select)
		{
			case 1:
				   printf("请输入要插入的值(以-1结束):");
				   while(scanf("%d",&Item),Item != -1)
						push_back(&mylist,Item);
					break;
			case 2:
				  printf("请输入要插入的值(以-1结束):");
				  while(scanf("%d",&Item),Item != -1)
						push_front(&mylist,Item);
					break;
			case 3:
				    show_list(&mylist);
					break;
			case 4:
					pop_back(&mylist);
					break;
			case 5:
					pop_front(&mylist);
					break;
			case 6:
					printf("请输入要插入的位置和值(用空格隔开):");
					scanf("%d%d",&p,&v);
					insert_pos(&mylist,p,v);
					break;
			case 7:
					printf("请输入要插入的值:");
					scanf("%d",&v);
					insert_val(&mylist,v);
					break;
			case 8:
					printf("请输入要删除的位置:");
					scanf("%d",&v);
					delete_pos(&mylist,v);
					break;
			case 9:
					printf("请输入要删除的值:");
					scanf("%d",&v);
					delete_val(&mylist,v);
					break;
			case 10:
					printf("请输入要查找的值:");
					scanf("%d",&v);
					if(0 == find_val(&mylist,v))
						printf("要查找的值不存在\n");
					else
						printf("第%d个元素是要查找的值\n",find_val(&mylist,v));
					break;
			case 11:
					printf("此顺序表的长度是:%d\n",length(&mylist));
					break;
			case 12:
					if(0 == isfull(&mylist))
						printf("此顺序表满\n");
					else
						printf("此顺序表未满\n");
					break;
			case 13:
					if(0 == isempty(&mylist))
						printf("此顺序表不空\n");
					else
						printf("此顺序表空\n");
					break;
			case 14:
					clear(&mylist);
					break;
			case 15:
					resver(&mylist);
					break;
			case 16:
					sort(&mylist);
					break;
			case 17:
					printf("请输入要插入的位置和值:");
					scanf("%d%d",&p,&v);
					ListInsert(&mylist,p,v);
			default:
					break;
		}

	}
	DestroySeqlist(&mylist);
	return 0;
}
