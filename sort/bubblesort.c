#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
	//bubble sort:讓數字大(小)的慢慢往右移動

	int store[SIZE] = { 3,5,1,-7,4,9,-6,8,10,4 },temp,flag=1;

	//small to big
  
	for (int i = 0; i < SIZE; ++i) //each round
	{
		for (int j = 0; j <SIZE-1-i; ++j)  //compare with neighbourhood 每一輪最大的會被移到最右邊
		{
			if (store[j] > store[j + 1])   //big to small: <
			{
				temp = store[j]; 
				store[j] = store[j + 1];
				store[j + 1] = temp;
			}
		}
	}
  
	for (int i = 0; i < SIZE; ++i)
		printf("%d ", store[i]);
	printf("\n");
  
  
	//improved ver.
	for (int i = 0; !flag && i < SIZE; ++i) //each round   flag:該輪下來flag沒被更動,代表sorting已經完成(全部人都是由小到大排好了),可以提早離開了
	{
		flag = 1; //每一輪都要初始化,不然的話只要第一輪有動過,後面就必然無法提早離開(因為flag會維持0)
		for (int j = 0; j < SIZE - 1 - i; ++j)  //compare with neighbourhood
		{
			if (store[j] > store[j + 1])   //big to small: <
			{
				temp = store[j];
				store[j] = store[j + 1];
				store[j + 1] = temp;
				flag = 0;
			}
		}
	}
  
	for (int i = 0; i < SIZE; ++i)
		printf("%d ", store[i]);
	printf("\n");

	system("pause");
	return 0;
}
