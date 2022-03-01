#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List
{
	int num;
	struct List* next;
};

typedef struct List ListNode;

//can use dummy_head than in add and delete , we dont need to pay attention on head

void addNode(int num,ListNode **first) //change value store in pointer needs double pointer
{
	ListNode* find=*first;
	ListNode *ptr = (ListNode*)malloc(sizeof(ListNode));
	ptr->num = num;
	ptr->next = NULL;

	if (!(*first))
	{
		*first = ptr;
		return;
	}
	else
		while (find->next)
			find = find->next;
	find->next = ptr;
}

void deleteNode(int num,ListNode **first)
{
	if (!(*first))
		return;
	else
	{
		ListNode* find = *first;
		ListNode* find2= *first; //foregoing of find
		while (find)
		{
			if (find->num == num) //get the delete num
			{
				if (find == *first) //delete first
				{
					*first = find->next;
					return;
				}
				find2->next = find->next;
				return;
			}
			find2 = find;
			find = find->next;
		}
	}
}

void traversal(ListNode* first)
{
	while (first)
	{
		printf("%d ", first->num);
		first = first->next;
	}
}

void reverse(ListNode** first)
{
	ListNode* find1=*first, *find2=*first, * find3=NULL; //1:next node 2:current node 3:pre node
	if (!(*first)) 
		return;
	else
	{
		while (find1)
		{
			find2 = find1; //cant find2=find2->next because it will be in a circle
			find1 = find2->next; //find1 first get find2->next address,because later find2->next will replace 因為反轉操作而喪失連結的節點，需要儲存起來
			find2->next = find3;
			find3 = find2; //after link,find3 can move
		}
		*first = find3;
	}
}


int main()
{
	ListNode* first=NULL; //store first node address

	for (int i = 0; i < 5; ++i)
	{
		addNode(i, &first); //change value store in pointer needs double pointer
		traversal(first);
		printf("\n");
	}

	reverse(&first);
	traversal(first);
	printf("\n");

	for (int i = 0; i < 5; ++i)
	{
		deleteNode(i, &first);
		traversal(first);
		printf("\n");
	}

	system("pause");
	return 0;
}
