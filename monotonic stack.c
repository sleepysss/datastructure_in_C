#include <stdio.h>
#include <stdlib.h>

int main()
{

	//monotonic stack:stack內元素都保持單調性
	//用途:finding next/previous greater/smaller element in a list of elements(4種case)
	//for greater:monotonically increasing stack
	//for smaller:monotonically decreasing stack
	//for next:backwardly iterate
	//for previous:forwardly iterate

	int store[5] = { 2,1,2,4,3 };
	int ans[5];
	int Stack[10];
	int top = -1;

	//find previous(left) & smaller

	for (int i = 0; i < 5; ++i)  //forwardly iterate(因為要先把魔王們建立起來,後來加入的才能和左邊比較)
	{
		while (top != -1 && store[i] <= Stack[top])  //因為是要找小的,所以stack從top到bottom為decrease(要插的那個數挑戰贏小魔王(比小魔王小)才能去挑戰中魔王的概念)
			top--;
		ans[i] = (top == -1) ? -1 : Stack[top];
		Stack[++top] = store[i];
		//整個stack就如同一個從i往左的排序,i先插到stack,接著i-1,.....比前面大的進不去,比前面小的依序變成中魔王,大魔王,大大魔王
	}

	for (int i = 0; i < 5; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	top = -1;

	//find next(right) & bigger

	for (int i = 4; i >= 0; --i)
	{
		while (top != -1 && store[i] >= Stack[top]) //依序單挑魔王
			top--;
		ans[i] = (top == -1) ? -1 : Stack[top];
		Stack[++top] = store[i];
	}

	for (int i = 0; i < 5; ++i)
		printf("%d ", ans[i]);


	system("pause");
	return 0;
}
