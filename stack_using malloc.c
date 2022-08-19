#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int capacity = 5;
int TOP=-1;

bool isEmpty()
{
	return (TOP == -1) ? 1 : 0;
}

int *push(int store[],int data)
{
	if (TOP == capacity - 1)
	{
		capacity *= 2;
		store = (int *)realloc(store, sizeof(int) * capacity);
	}

	store[++TOP] = data;

	return store;
}

void pop(int store[])
{
	if (!isEmpty())
		TOP--;
	return;
}

int getSize()
{
	return TOP + 1;
}

void top(int store[])
{
	if (TOP != -1)
		printf("%d",store[TOP]);
}

int main()
{
	int* store;
	int choose, num;

	store = (int*)malloc(sizeof(int) * capacity);

	for (;;)
	{
		printf("1:push,2:pop,3:top,4:size,5:exit\n");
		scanf("%d", &choose);
		if (choose == 1)
		{
			printf("num?\n");
			scanf("%d", &num);
			store=push(store, num);
		}
		else if (choose == 2)
		{
			pop(store);
		}
		else if (choose == 3)
		{
			top(store);
		}
		else if (choose == 4)
		{
			printf("%d\n", getSize());
		}
		else if (choose == 5)
			break;

	}
	free(store);

	system("pause");
	return 0;
}
