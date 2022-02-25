#include <stdio.h>
#include <stdlib.h>

//max heap

//reheap就是把heap中違規的那個傢伙(除了他以外,其他都正常),丟到他應該去的地方,來讓heap"恢復正常" (排除那一粒老鼠屎),過程有點像bubble sort的冒泡過程

void ReheapUp(int store[],int index)  //Reheap from down to up,after Reheap,array will be a heap
{
	if (!index) //does not have parent
		return;
	int value=store[index],parent=store[(index-1)/2],storevalue;
	if (value > parent) //does not fit Heap property
	{
		storevalue = value;
		store[index] = parent;
		store[(index - 1) / 2] = storevalue;
		ReheapUp(store,(index-1)/2);
	}
}

void ReheapDown(int store[],int index,int last) //Reheap from up to down,after Reheap,array will be a heap
{
	int leftson =store[2 * index + 1], rightson = store[2 * index + 2],biggest=store[index],biggest_index=index,storevalue,flag=0;
	if (leftson > biggest&&last>=(2*index+1))
	{
		biggest = leftson;
		biggest_index = 2 * index + 1;
		flag = 1;
	}
	if (rightson > biggest&&last >= (2 * index + 2))
	{
		biggest = rightson;
		biggest_index = 2 * index + 2;
		flag = 1;
	}
	//exchange root with biggest if biggest isnt root
	if (flag)
	{
		storevalue = store[index];
		store[index] = biggest;
		store[biggest_index] = storevalue;
		ReheapDown(store, biggest_index,last);
	}
}

void push(int store[],int num,int last) //add an element to heap
{
	store[++last] = num; //add at last
	ReheapUp(store, last);
}

void pop(int store[],int last) //delete root from heap       last:heap last element index
{
	printf("%d ", store[0]);
	store[0] = store[last--]; //最後一個取代被pop出去的那個
	ReheapDown(store,0,last); //解決老鼠屎
}

void sorting_big2small(int store[],int last)
{
	for (int i = last; i >=0; --i)
	{
		pop(store,i);
	}
	printf("\n");
}

void BuildHeapFromArray(int store[],int last)
{
	for (int i =( (last - 1) / 2); i >= 0; --i)  //每個i當成root(當成一個subtree,並對他做ReheapDown),然後因為後面的index已滿足heap的特性,所以前面的index可以安心用ReheapDown,弄到最後面就能得到一個"正版"的heap
		ReheapDown(store,i,last);            //且leaf這個subtree一定會滿足heap的特性

	//another method:start from i=0 and use ReheapUp  可想成把值一直加到heap中,最後得到"正版"的heap
}

int main()
{
	//heap:
	//(1)heap is complete or nearly complete binary tree , so it is usually implemented in an array structure
	//(2)parents always bigger:MAXheap(smaller:MINheap) than both son
	
	int num[10] = { 9,10,5,1,5,70,6,45,2,0 };
	BuildHeapFromArray(num, 9);
	sorting_big2small(num,9);

	system("pause");
	return 0;
}
