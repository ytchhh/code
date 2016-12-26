#include <stdio.h>

int find(int arr[][4]);
void run(int arr[][4], int id);
int finish(int arr[][4]);

int main()
{
	int arr[5][4] = {{0,9, 0, 3}, {1, 38, 0, 3}, {2, 30, 0, 6}, {3, 29, 0, 3}, {4, 0, 0, 4}};	
	while(!finish(arr))
		run(arr, find(arr));
	return 0;
}
int find(int arr[][4])
{
	int i;
	int id = -1;
	for(i = 0; i < 5; i ++)
	{
		if(arr[i][3] > 0)
		{
			if(id == -1)
				id = i;
			else 
				id = arr[id][1] > arr[i][1] ? id : i;
		}
	}
	return id;
}

void run(int arr[][4], int id)
{
	int i;
	printf("dangqian : %d\n", id);
	printf("jixu");
	for(i = 0; i < 5; ++i)
	{
		if(i != id && arr[i][3] > 0)
			printf("%d  ", i);
	}
	printf("\n");
	arr[id][1] -= 3;
	arr[id][3] -= 1;
}

int finish(int arr[][4])
{
	int i;
	for(i = 0; i < 5; ++i)
	{
		if(arr[i][3] > 0)
			return 0;
	}
	return 1;
}
