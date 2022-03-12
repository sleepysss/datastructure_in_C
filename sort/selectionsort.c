#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
	//selection sort:把整個array分為處理過和未處理裡過
	//首先在未排序序列中找到最小元素，存放到排序序列的起始位置，然後，再從剩餘未排序元素中繼續尋找最小元素，然後放到已排序序列的末尾,重複下去

	int store[SIZE] = { 3,5,1,-7,4,9,-6,8,10,4 },temp,smallest_index;

	for (int i = 0; i < SIZE-1; ++i)  //each round will find a samllest val and put it to the place it should be , 最後一個不用比
	{
		smallest_index = i; //default smallest val's place
		for (int j = i+1; j < SIZE; ++j) //從i+1開始因為i不可能讓if成立
			if (store[j] < store[smallest_index])
				smallest_index = j;
		if (smallest_index != i)
		{
			temp = store[smallest_index];
			store[smallest_index] = store[i];
			store[i] = temp;
		}
	}

	for (int i = 0; i < SIZE; ++i)
		printf("%d ", store[i]);

	system("pause");
	return 0;
}
