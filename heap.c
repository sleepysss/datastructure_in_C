#include <stdio.h>
#include <stdlib.h>

//max heap

//正統的heap sort見 sort部分的heapsort.c

//reheap就是把heap中違規的那個傢伙(除了他以外,其他都正常),丟到他應該去的地方,來讓heap"恢復正常" (排除那一粒老鼠屎),過程有點像bubble sort的冒泡過程

void ReheapUp(int store[], int index)  //Reheap from down to up,after Reheap,array will be a heap
{
	if (!index) //does not have parent
		return;
	int value = store[index], parent = store[(index - 1) / 2], storevalue;
	if (value > parent) //does not fit Heap property
	{
		storevalue = value;
		store[index] = parent;
		store[(index - 1) / 2] = storevalue;
		ReheapUp(store, (index - 1) / 2);
	}
}

void ReheapDown(int nums[], int root, int last) //Reheap from up to down,after Reheap,array will be a heap
{
	//是要「由上而下」地，以Max Heap的規則(root的數值「大於」兩個child的數值)，調整矩陣
	int leftchild, rightchild, biggest_index = root;
	if ((2 * root + 1) <= last) //leftchild exist
	{
		leftchild = 2 * root + 1;
		biggest_index = nums[leftchild] > nums[biggest_index] ? leftchild : biggest_index;  //leftchild bigger than biggest or not
	}
	if ((2 * root + 2) <= last) //rightchild exist
	{
		rightchild = 2 * root + 2;
		biggest_index = nums[rightchild] > nums[biggest_index] ? rightchild : biggest_index;
	}
	if (root != biggest_index)  //exchange
	{
		int temp = nums[biggest_index];  //index(root)與index(largest)這兩個node互換位置，如此一來，當前的subtree必定能滿足Max Heap規則
		nums[biggest_index] = nums[root];
		nums[root] = temp;
		ReheapDown(nums, biggest_index, last); //檢查新的subtree是否符合Max Heap規則
	}
}

void push(int store[], int num, int *last) //add an element to heap
{
	store[++(*last)] = num; //add at last
	ReheapUp(store, *last);
}

void pop(int store[], int *last) //delete root from heap       last:heap last element index
{
	//將root與最後加入的node交換。
	//刪除被換到最下面的root node。
	//將被換到最上面的node與其小孩比較，依情況交換，直到滿足Heap Tree的特性。
	
	printf("%d ", store[0]);
	store[0] = store[(*last)--]; //最後一個node移到root
	ReheapDown(store, 0, *last); //解決老鼠屎(幫剛移上去的找新家)
}

void pop(int store[],int *last,int num) //delete arbitrary num from heap
{
    int index=-1; //delete num's index
    //find num
    for(int i=0;i<*last;++i)
    {
        if(store[i]==num)
        {
            index=i;
            break;
        }
    }
    
    if(index==-1)
        return;
    else
    {
        store[index]=store[*last]; //change
        (*last)--; //delete
        
        if(index>0&&store[index]>store[(index-1)/2]) //check greater than parent or not index>0:has parent
            ReheapUp(store,index);        
        else //check greater than son or not
            ReheapDown(store,index,last); 
    }
}

void sorting_big2small(int store[], int *last)
{
	for (int i = *last; i >= 0; --i)
	{
		pop(store, last);
	}
	printf("\n");
}

void BuildHeapFromArray(int store[], int last)
{
	//此方法為 Floyd建堆算法
	//只要對所有「具有child的node」檢查一次MaxHeapify()，便能夠把一個任意矩陣調整成Max Heap
	//為什麼只要對「具有child的node」調整呢？
	//因為Max Heap的規則是「比較root的數值與child的數值」，如果是沒有child的node(屬於leaf node)，就一定不會違反Max Heap的規則。
	for (int i = ((last - 1) / 2); i >= 0; --i)  //每個i當成root(當成一個subtree,並對他做ReheapDown),然後因為後面的index已滿足heap的特性,所以前面的index可以安心用ReheapDown,弄到最後面就能得到一個"正版"的heap
		ReheapDown(store, i, last);            //且leaf這個subtree一定會滿足heap的特性

	//another method:start from i=0 and use ReheapUp  可想成把值一直加到heap中(逐個元素插入,然後對每個元素進行reheapUP),最後得到"正版"的heap
}

int main()
{
	//heap:
	//(1)heap is complete or nearly complete binary tree , so it is usually implemented in an array structure
	//(2)parents always bigger:MAXheap(smaller:MINheap) than both child
	//(3)下標為i的節點的子節點是2i + 1與2i + 2；其父節點的下標是⌊floor((i − 1) ∕ 2)⌋

	int num[10] = { 9,10,5,1,5,70,6,45,2,0 };
	int last = 9;
	BuildHeapFromArray(num, last);
	sorting_big2small(num, &last);

	system("pause");
	return 0;
}
