void insertionsort(int store[],int size)
{
	int key,j;
	for (int i = 1; i < size; ++i) //目前要處理的資料,i之前的是已經排序(處理)過的資料,現在要把第i個資料插入前面那一坨中
	{
		key = store[i];  //目前要插的值
		j = i - 1;  //已排序的序列中目前檢查的index
		while (j >= 0 && store[j] > key)  //由後向前看看新的要插在哪
		{
			store[j + 1] = store[j];  //往後移一格
			j--;
		}
		store[j + 1] = key; //把key插入她該在的地方
	}
}

// ex:
//  3 5 1 2 6 4       i=2  key=1
//  3 5 5 2 6 4	      i=2  key=1 j=1 符合條件
//  3 3 5 2 6 4       i=2  key=1 j=0 符合條件
//  跳出while because j為-1
//  1 3 5 2 6 4
// key 比store[j]大也是類似的概念

int main()
{
	//insertion sort:和打撲克牌時，從牌桌上逐一拿起撲克牌，在手上排序的過程相同。
	//The array is virtually split into a sorted and an unsorted part. 
	//Values from the unsorted part are picked and placed at the correct position in the sorted part.
  
  //small to big
  
	int store[SIZE] = { 3,5,1,-7,4,9,-6,8,10,4 },temp,smallest_index;
	insertionsort(store, SIZE);
	for (int i = 0; i < SIZE; ++i)
		printf("%d ", store[i]);

	system("pause");
	return 0;
}
