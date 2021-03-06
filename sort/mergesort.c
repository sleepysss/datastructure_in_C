#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void merge(int nums[], int front_index, int end_index, int mid_index)  //merge two subarray into one (two subarray are both sorted because of recursive structure)
{
	int i, j;
	int* left_subarray = (int *)malloc(sizeof(int)*(mid_index-front_index+1));  //front~mid 
	int* right_subarray = (int*)malloc(sizeof(int)*(end_index - mid_index));  //mid+1~end 
	int left_subarray_index = 0, right_sub_array_index = 0;  //看看接下來要比較的是sub array的哪一格

	for (i = 0, j = front_index; i < (mid_index - front_index + 1); ++i, ++j) 
		left_subarray[i] = nums[j];  //assignment(把front~mid的value丟給left_subarray)

	for (i = 0, j = mid_index + 1; i < end_index - mid_index; ++i, ++j) 
		right_subarray[i] = nums[j];

	i = front_index; //藉由比較兩個sub array來插回原本的array中
	while (left_subarray_index < (mid_index - front_index + 1) && right_sub_array_index < (end_index - mid_index)) //兩個sub array還沒traverse完
		nums[i++] = (left_subarray[left_subarray_index] < right_subarray[right_sub_array_index]) ? left_subarray[left_subarray_index++] : right_subarray[right_sub_array_index++];
	while (left_subarray_index < (mid_index - front_index + 1))  //means:right_sub_array traverse finish
		nums[i++] = left_subarray[left_subarray_index++];
	while (right_sub_array_index < (end_index - mid_index)) //means:left_sub_array traverse finish
		nums[i++] = right_subarray[right_sub_array_index++];

	free(left_subarray);
	free(right_subarray);
}

void mergesort(int nums[], int front_index, int end_index)
{
	if (end_index > front_index)
	{
		int mid_index = (end_index + front_index) / 2;
		mergesort(nums, front_index, mid_index);                //divide (front~mid),會將nums中front_index~mid_index排好
		mergesort(nums, mid_index + 1, end_index);				      //divide (mid+1~end),會將nums中mid+1~end排好
		merge(nums, front_index, end_index, mid_index);			    //conquer(合體:將兩個subarray做比較,並合併出排序後的array)          
	}
}

int main()
{
	//merge sort:將問題拆解為子問題,並逐一處理子問題後,將子問題的結果合併,來解決原來的問題

	int store[SIZE] = { 3,5,999,-7,4,9,-6,888,10,-400 };
	mergesort(store,0,9); //呼叫這個代表會將nums[]0~9由小到大排好

	for (int i = 0; i < SIZE; ++i)
		printf("%d ", store[i]);
	printf("\n");

	system("pause");
	return 0;
}
