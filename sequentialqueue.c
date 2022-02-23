#define _CRT_SECURE_NO_WARNINGS
#define MAX_QUEUE_SIZE 10
#include <stdio.h>
#include <stdlib.h>

void AddQ(int store[],int *end,int num)
{
	if ((*end) >= MAX_QUEUE_SIZE - 1)
		return;
	else
		store[++(*end)] = num;
}


void DeleteQ(int store[],int *front,int *end) // DeleteQ並沒有真正把Array的記憶體位置釋放，只是調整front，使得Queue「看起來」有刪除資料。
{
	if ((*front) == (*end))  //empty queue
		return;
	else
		(*front)++;
}


int main()
{
	//queue:is an ordered list in which insertions and deletions take place at different place
	int store[MAX_QUEUE_SIZE] = { 0 };
	int front=-1,end=-1; //front:first element index;end:last element index
	int choose, num;
	for (;;)
	{
		printf("1:Add,2:Delete");
		scanf("%d", &choose);
		if (choose == 1)
		{
			printf("num?\n");
			scanf("%d", &num);
			AddQ(store, &end, num);
		}
		else if (choose == 2)
		{
			DeleteQ(store, &front,&end);
		}	

		printf("%d %d\n", front, end);

	}
	system("pause");
	return 0;
}
