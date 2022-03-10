#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//if collision->chaining

struct HashNode
{
	int key;
	char name[10];
	struct HashNode* next;
};

bool find(int key,struct HashNode **hashtable)
{
	int store = key % 55;
	struct HashNode *temp;
	if (!hashtable[store])
		return 0;
	else
	{
		temp = hashtable[store];
		while (temp)  //traverse
		{
			if (temp->key == key)
				return 1;
			temp = temp->next;
		}
		return 0; //not find
	}
}

void insertnode(int key,char name[],struct HashNode **hashtable) 
{
	if (find(key, hashtable)) //already exist
		return;

	struct HashNode* node = (struct HashNode*)malloc(sizeof(HashNode)), *temp;
	//initial
	node->key = key;
	strcpy(node->name,name);
	node->next = NULL;

	int store = key % 55;  //hash function
	if (!hashtable[store])
		hashtable[store] = node;
	else
	{
		temp = hashtable[store];
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

void deletenode(int key, struct HashNode** hashtable)
{
	if (!find(key, hashtable))  //does not exist
		return;
	else
	{
		int store= key % 55;
		struct HashNode* temp=hashtable[store],* pre=hashtable[store];
		while (temp)
		{
			if (temp->key == key)
			{
				if (hashtable[store] == temp) //first
				{
					hashtable[store] = temp->next;
					free(temp);
					return;
				}
				else
				{
					pre->next = temp->next;
					free(temp);
					return;
				}
			}
			pre = temp;
			temp = temp->next;
		}
	}
}

int main()
{
	//hash table
	//(1)能夠在O(1)完成查詢
	//(2)Hash Table希望能夠將存放資料的「Table」的大小(size)降到「真正會存放進Table的資料的數量」，也就是「有用到的Key的數量」,
	//要達到這個目標，必須引入Hash Function，將Key對應到符合Table大小m的範圍內，index=h(Key)，即可成為Hash Table的index,ex:h(Key)=Key mod m ,Key就存在index h(Key)中
	//(3)Collision就是兩筆資料存進同一個Table之slot的情形，這將會使得查詢資料失敗,解決的辦法有二
	//Chaining：使用Linked list把「Hashing到同一個slot」的資料串起來。
	//Open Addressing:使用Probing Method來尋找Table中「空的slot」存放資料。

	struct HashNode* hashtable[55];   //store first node's address
	for (int i = 0; i < 55; ++i)
		hashtable[i] = NULL;
	int store,key,temp,c;
	char name[10];
	for (;;)
	{
		printf("1 for insert,2 for delete,3 for find\n");
		scanf("%d", &store);
		if (store == 1)
		{
			while ((c = getchar()) != EOF && c != '\n'); //clean buffer
			printf("key?\n");
			scanf("%d", &key);
			while ((c = getchar()) != EOF && c != '\n');
			printf("name?\n");
			scanf("%s", name);
			insertnode(key,name,hashtable);
		}
		else if (store == 2)
		{
			printf("key?\n");
			scanf("%d", &key);
			deletenode(key,hashtable);
		}
		else if (store == 3)
		{
			printf("key?\n");
			scanf("%d", &key);
			temp=find(key, hashtable);
			if (temp)
				printf("find\n");
			else
				printf("not find\n");
		}
	}

	system("pause"); 
	return 0;
}
