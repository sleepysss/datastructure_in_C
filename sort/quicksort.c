#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// ex for Partition
// 8 3 5 i=-1 j=0 last=2 pivot=5
// 3 8 5 i=0 j=1 last=2 pivot=5
// end for
// 3 5 8 i=1

//in place ver.


//為了達成上述條件，Quicksort 有許多不同的分割序列實作方案（partition scheme），其中以 Lomuto partition 最易理解，常被做為教材。
//1.以序列最後一個元素當做 pivot。
//2.利用兩個指標 i j，其中 j 從頭疊代整個序列
// 若有序列第 j 個元素小於 pivot，則與第 i 個元素置換。
// 第 i 個元素已落在小於 pivot 的範圍，將 i 指標往後移一個，處理下個元素。
//3.疊代完成後，小於 pivot 的元素全都置換至序列前端，此時將 pivot 與第 i 個元素置換，pivot 會剛好在最終正確位置上（符合不等式）。
//4.另外一種方法為Hoare partition scheme

int Partition(int store[],int first, int last)
{
	int pivot = store[last];
	int i = first - 1,temp;  //i:小於pivot的數所形成的數列的最後位置

	for (int j = first; j < last; ++j) //traverse each element
	{
		if (pivot > store[j])    //過程類似找到小於pivot的數,就把他插到小於pivot的數所形成的數列的尾端
		{
			i++;
			temp = store[i];
			store[i] = store[j];
			store[j] = temp;
		}
	}
	//做完上述步驟,整個數列會變成 <pivot >=pivot pivot  這時要將pivot插到中間來完成 <pivot pivot >=pivot
	i++;    
	temp = store[i];
	store[i] = pivot;
	store[last] = temp;

	return i; //pivot's index
}

void quicksort(int store[],int first,int last)
{
	if(first < last)  //因為這個條件,所以剩一個或沒有的會被自動擋掉
	{
		int pivot = Partition(store,first,last); //比pivot大於等於的都在pivot右邊,比pivot小的都在左邊,pivot固定住了
		quicksort(store, first, pivot - 1); //左排
		quicksort(store, pivot + 1, last); //右排
	}
}

int main()
{
	//quick sort:在數列中挑一個數pivot,然後調整數列,使得pivot右邊的數都比pivot大,pivot左邊的數都比pivot小,
	//接著把pivot左邊的數列當成新的數列,右邊的數列當成新的數列,重複前面的步驟,直到無法分出新數列為止

	int store[SIZE] = { 3,5,1,-7,4,9,-6,8,10,4 };
	quicksort(store, 0, SIZE - 1);
	for (int i = 0; i < SIZE; ++i)
		printf("%d ", store[i]);
	printf("\n");

	system("pause");
	return 0;
}
