#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

void AddQ(int store[], int *front, int *end, int num)
{
	if (((*end) + 1) % 5 == (*front))  //隊伍的最後一個的下一個為隊伍開頭的前一個(代表有一個空位)(因為要留一個空位)    留空位的原因為如果不留,front==back可能會全滿或沒半個,留的話全滿的條件會變左邊那個
		return;
	else
	{
		*end = ((*end) + 1) % 5;
		store[*end] = num;
	}
}

void DeleteQ(int store[], int *front, int *end, int num)
{
	if ((*front) == (*end)) //隊伍中沒任何東西
		return;
	else
		(*front) = ((*front) + 1) % 5;
}

int main()
{
	//circular queue 畫圖較好理解
	int store[5];
	//front:隊伍開頭的前一個的index back:隊伍的最後一個的index

	system("pause");
	return 0;
}
