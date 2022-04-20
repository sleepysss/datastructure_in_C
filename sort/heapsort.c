#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

//maxheap: result will be small to big

void reheapDown(int store[],int root,int last)
{
	int biggestindex = root;
	if (2 * root + 1 <= last && store[2 * root + 1] > store[biggestindex])
		biggestindex = 2 * root + 1;
	if (2 * root + 2 <= last && store[2 * root + 2] > store[biggestindex])
		biggestindex = 2 * root + 2;
	if (biggestindex != root)
	{
		int temp = store[root];
		store[root] = store[biggestindex];
		store[biggestindex] = temp;
		reheapDown(store, biggestindex, last);
	}
}

void BuildHeapFromArray(int store[],int last)
{
	for (int i = (last - 1) / 2; i >= 0; --i)
		reheapDown(store, i, last);
}

void heapsort(int store[],int last)
{
	BuildHeapFromArray(store,last);

	for (int i = last; i > 0; --i)
	{
		int temp = store[0];       //(1)把最大的移到最後面(由後往前一路加回來(靠last)) (2)整個array分為sort完和沒sort完
		store[0] = store[last];
		store[last] = temp;
		last--;
		reheapDown(store, 0, last);
	}
}

int main()
{	
	//heap滿足:(1)任意節點小於（或大於）它的所有後裔 (2)堆積總是一棵完全樹。即除了最底層，其他層的節點都被元素填滿，且最底層儘可能地從左到右填入。
	
	int store[SIZE] = { 3,5,1,-7,4,-666,-6,8,999,4 };
	heapsort(store,SIZE-1);
	for (int i = 0; i < SIZE; ++i)
		printf("%d ", store[i]);

	system("pause");
	return 0;
}
