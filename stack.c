#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 10
#include <stdio.h>
#include <stdlib.h>

void push(int num,int store[],int* top)
{
	if ((*top) >= MAX_STACK_SIZE-1) //full
		return;
	else
		store[++(*top)] = num;
}

void pop(int store[],int *top)
{
	if ((*top) == -1)
		return;
	else
		(*top)--;
}

int main()
{
	//stack:last in first out data structure in which all insertions and deletions are restricted to one end,called top 
	int store[MAX_STACK_SIZE] = {0};
	int top = -1;
	int choose,num;

	for (;;)
	{
		printf("1:push,2:pop");
		scanf("%d", &choose);
		if (choose == 1)
		{
			printf("num?\n");
			scanf("%d", &num);
			push(num, store, &top);
		}
		else if(choose==2)
		{
			pop(store, &top);
		}

		if(top!=-1)
			printf("top element:%d\n", store[top]);

	}

	system("pause");
	return 0;
}
