#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char name[20];
	int price;
	struct node* link;
}NODE;


void add(NODE **head,char name[],int price)
{
	NODE* ptr = (NODE*)malloc(sizeof(NODE));
	NODE* find1, *find2;  //find1:current  find2:pre

	ptr->price = price;
	ptr->link = NULL;
	strcpy(ptr->name,name);

	if (!(*head)) //nothing in the list
	{
		*head = ptr;
		return;
	}
	else
	{
		if ((*head)->price > ptr->price)  //add at first
		{
			ptr->link = *head;
			*head = ptr;
		}
		else //add at middle & end
		{
			find1 = *head;
			find2 = *head;
			while (find1)
			{
				if (find1->price > ptr->price)  //find the place to add
					break;
				find2 = find1;
				find1 = find1->link;
			}
			find2->link = ptr;
			ptr->link = find1;
		}
	}
}

void del(char name[], NODE** head)
{
	NODE* find1=*head, *find2, *store;

	if (!(*head)) //nothing in the list
		return;
	else
	{
		if (!(strcmp(name, (*head)->name)))  //del first
		{
			store = *head;
			*head = (*head)->link;
			free(store);
			return;
		}
		else  //del middle & end
		{
			find1 = *head;
			find2 = *head;
			while (find1)
			{
				if (!(strcmp(name, find1->name)))
				{
					store = find1;
					find2->link = find1->link;
					free(store);
					return;
				}	
				find2 = find1;
				find1 = find1->link;
			}
		}
	}
}

void print_list(NODE* head)
{
	NODE* find = head;
	while (find)
	{
		printf("%s %d\n", find->name, find->price);
		find = find->link;
	}
}

void destroy(NODE** head)
{
	while (*head)
	{
		del((*head)->name,head);
	}
}

int main()
{
	//element in this linked list will be sorted from small to big

	int choose,c;
	char name[20];
	int price;
	NODE* head = NULL;

	for (;;)
	{
		printf("1:print list 2:delete element 3:add element 4:exit\n");
		scanf("%d", &choose);
		if (choose == 1)
		{
			print_list(head);
		}
		else if (choose == 2)
		{
			printf("name?\n");
			while ((c = getchar()) != EOF && c != '\n');  //clear buffer:不停地使用getchar()獲取緩衝中字元，直到獲取的c是“\n”或檔案結尾符EOF為止
			scanf("%s",name);
			del(name,&head);
		}
		else if (choose == 3)
		{
			while ((c = getchar()) != EOF && c != '\n');
			printf("name?\n");
			scanf("%s", name);
			printf("price?\n");
			scanf("%d", &price);
			add(&head,name,price);
		}
		else if (choose == 4)
		{
			destroy(&head);
			break;
		}
	}

	system("pause");
	return 0;
}
