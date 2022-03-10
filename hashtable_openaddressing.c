#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//if collision->open addressing(linear probing)

struct HashNode
{
	int key;
	char name[10];
	struct HashNode* next;
};

bool find(int key, struct HashNode** hashtable)
{
	for (int i = 0; i < 20; ++i) 
	{
		if (!hashtable[(key % 20 + i) % 20]) //因為填入時一定會照probing的順序,所以只要一個是空,必定代表沒有
			return false;
		if (hashtable[(key % 20 + i) % 20]->key == key) //要確認的原因為可能是別人佔那個位置
			return true;
	}
	return false;
}

void insertnode(int key, char name[], struct HashNode** hashtable)
{
	if (find(key, hashtable)) //already exist
		return;
	struct HashNode* node = (struct HashNode*)malloc(sizeof(HashNode)), * temp;
	//initial
	node->key = key;
	strcpy(node->name, name);
	node->next = NULL;

	for (int i = 0; i < 20; ++i) //iterative 一輪必定能找到空的(或者也可以用load factor來控制table的大小)  第1個slot滿了，就找第2個slot；若第2個slot滿了，就找第3個slot，依此類推
	{
		if (!hashtable[(key % 20 + i) % 20])     //h(k,i)=(h'(k)+i) mod m  ex:k=7 m=8 ，h'(7)=7 (h'(k)=k mod m)，Probing Sequence為{7,0,1,2,3,4,5,6}
		{
			hashtable[(key % 20 + i) % 20] = node;
			return;
		}	
	}
}

int main()
{
	//Probing就是「尋找下一格空的slot」，如果沒找到，就要繼續「往下找」，因此，Probing的精髓就是要製造出「往下找的順序」，
	//這個順序盡可能越不規則越好，如此可確保Hash Function不會一直找到同一個slot
	
	struct HashNode* hashtable[20];   //store first node's address
	for (int i = 0; i < 20; ++i)
		hashtable[i] = NULL;
	int c, key,store;
	bool temp;
	char name[10];
	for (;;)
	{
		printf("1 for insert,3 for find\n");
		scanf("%d", &store);
		if (store == 1)
		{
			while ((c = getchar()) != EOF && c != '\n'); //clean buffer
			printf("key?\n");
			scanf("%d", &key);
			while ((c = getchar()) != EOF && c != '\n');
			printf("name?\n");
			scanf("%s", name);
			insertnode(key, name, hashtable);
		}
		else if (store == 3)
		{
			printf("key?\n");
			scanf("%d", &key);
			temp = find(key, hashtable);
			if (temp)
				printf("find\n");
			else
				printf("not find\n");
		}
	}

	system("pause"); 
	return 0;
}
