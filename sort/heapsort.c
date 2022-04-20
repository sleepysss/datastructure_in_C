#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

//maxheap: result will be small to big

void reheapDown(int store[],int root,int last) //last:last index
{	
	//找root,left_child,right_child三者中最大的且子節點要在有效範圍內
	int biggestindex = root;
	if (2 * root + 1 <= last && store[2 * root + 1] > store[biggestindex])
		biggestindex = 2 * root + 1;
	if (2 * root + 2 <= last && store[2 * root + 2] > store[biggestindex])
		biggestindex = 2 * root + 2;
	//若有調整,則檢查新的subtree是否符合
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
	//對所有「具有child的node」檢查一次，便能夠把一個任意矩陣調整成Max Heap
	for (int i = (last - 1) / 2; i >= 0; --i)
		reheapDown(store, i, last);
}

void heapsort(int store[],int last)
{
	BuildHeapFromArray(store,last);

	for (int i = last; i > 0; --i)
	{
		int temp = store[0];         //把最前面的(最大)移到最後面,最後面的移到最前面
		store[0] = store[last];  
		store[last] = temp;
		last--;                      //把array分為sort完和沒sort完兩部分
		reheapDown(store, 0, last);  //調整最前面的到適當位置(可以這樣的原因為其他都是符合heap特性的)
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
