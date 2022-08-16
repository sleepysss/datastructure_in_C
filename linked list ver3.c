#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List
{
	int num;
	struct List* next;
}ListNode;


ListNode *addNode(const int num,ListNode *head)
{
	ListNode *newnode_ptr = (ListNode*)malloc(sizeof(ListNode)), * nextofnewnode_ptr=head, * lastofnewnode_ptr=head;
	newnode_ptr->next = NULL;
	newnode_ptr->num = num;

	if (head==NULL || head->num > newnode_ptr->num ) //add at first or empty list
	{
		newnode_ptr->next = head;
		head = newnode_ptr;
	}
	else   //add at middle or last
	{
		while (nextofnewnode_ptr)   //find the place to add (the list is small to big)
		{
			if (newnode_ptr->num <= nextofnewnode_ptr->num)
				break;
			lastofnewnode_ptr = nextofnewnode_ptr;
			nextofnewnode_ptr = nextofnewnode_ptr->next;
		}
		//if the if condition does not fit , then nextofnewnode will be NULL and lastofnewnode will be the last node , this still work !
		newnode_ptr->next = nextofnewnode_ptr;
		lastofnewnode_ptr->next = newnode_ptr;
	}
	return head;
}

ListNode *deleteNode(const int num,ListNode *head)
{
	//using dummy node,then we dont need to handle boundary condition
	ListNode dummy;
	ListNode *finddeletenode_ptr=&dummy, *lastofdeletenode_ptr=&dummy;
	dummy.next = head;
	while (finddeletenode_ptr)
	{
		if (finddeletenode_ptr->num == num && finddeletenode_ptr!=&dummy)
		{
			lastofdeletenode_ptr->next = finddeletenode_ptr->next;
			free(finddeletenode_ptr);
			break;
		}
		lastofdeletenode_ptr = finddeletenode_ptr;
		finddeletenode_ptr = finddeletenode_ptr->next;
	}

	return dummy.next;
}

void traversal(const ListNode *head)
{
	while (head)
	{
		printf("%d ", head->num);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	ListNode *head=NULL;
	int choose,num;

	for (;;)
	{
		printf("one for add , two for delete , three for traverse\n");
		scanf("%d", &choose);
		switch (choose)
		{
			case 1:
				printf("add num?\n");
				scanf("%d", &num);
				head = addNode(num,head);
				break;
			case 2:
				printf("delete num?\n");
				scanf("%d", &num);
				head = deleteNode(num, head);
				break;
			case 3:
				traversal(head);
		}
	}
	system("pause");
	return 0;
}
