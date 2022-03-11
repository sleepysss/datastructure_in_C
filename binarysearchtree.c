#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}NODE;

NODE* Q[100];  //queue
int front = -1, back = -1;  //front:隊伍開頭的前一個的index back:隊伍的最後一個的index

void addQ(NODE * ptr)
{
	Q[++back] = ptr;
}

void deleteQ()
{
	front++;
}


int search(NODE* root,int num)
{
	if (!root)
		return 0;
	else if (root->data == num)
	{
		return 1;
	}
	else if (root->data > num)
	{
		return search(root->left, num); //just like ask left subtree is num at there,and left subtree will tell you
	}
	else if (root->data < num)
	{
		return search(root->right, num);
	}
}

NODE *insertnode(NODE* root, int num)
{
	if (!root)
	{
		NODE* ptr = (NODE*)malloc(sizeof(NODE));
		ptr->data = num;
		ptr->left = NULL;
		ptr->right = NULL;
		return ptr;
	}
	else
	{
		if (root->data > num)
			root->left=insertnode(root->left, num);
		else
			root->right=insertnode(root->right, num);
	}
	return root; //after link,we shall return root back
}

//another version of insert node (by double pointer,so dont need to return address back)
void insertnode(NODE **root, int num)
{
	if (!(*root))
	{
		NODE* ptr = (NODE*)malloc(sizeof(NODE));
		ptr->data = num;
		ptr->left = NULL;
		ptr->right = NULL;
	}
	else
	{
		if ((*root)->data > num)
			insertnode(&((*root)->left));
		else
			insertnode(&((*root)->right));
	}
}

int findsmallest_rightsubtree_data(NODE *ptr)
{
	if (ptr->left)
		return findsmallest_rightsubtree_data(ptr->left);
	else
	{
		return ptr->data;

	}
		
}

NODE* deletenode(NODE* root, int num)  //delete the number and return back new root
{
	if (!root)
		return root;
	else if (root->data == num) //find
	{
		if ((!root->left) || (!root->right)) //no child or one child
		{
			NODE* ptr1 = root->left, *ptr2=root->right;
			free(root);
			return ptr1 ? ptr1 : ptr2; //return back new root(String it up directly)
		}
		else //two child method:find successor(替身)
		{
			int x = findsmallest_rightsubtree_data(root->right); //get successor val
			root->right=deletenode(root->right, x); //cant root because it will be a cycle    delete successor
			root->data = x; //put successor val to root
		}
	}
	else if (root->data > num)
	{
		root->left=deletenode(root->left, num); //return back new root->left
	}
	else if (root->data < num)
	{
		root->right = deletenode(root->right, num);
	}
	return root;
}

void traverse_BFS(NODE* root)
{
	if (root)
	{
		addQ(root);
		while (front != back) //Queue not empty
		{
			printf("%d ", Q[front + 1]->data);
			if(Q[front+1]->left)
				addQ(Q[front + 1]->left);
			if(Q[front + 1]->right)
				addQ(Q[front + 1]->right);
			deleteQ();
		}
	}
	printf("\n");
}

void traverse_DFS_Inorder(NODE* root)  //left mid right
{
	if (!root)
		return;
	else
	{
		traverse_DFS_Inorder(root->left);
		printf("%d ", root->data);
		traverse_DFS_Inorder(root->right);
	}
	return;
}

int main()
{
	//  bst:     k
	//         /  \
	//	ALL<k  ALL>k

	int choose,num;
	NODE* root = NULL;

	for (;;)
	{
		printf("1for add 2for delete 3for find");
		scanf("%d", &choose);
		if (choose == 1)
		{
			scanf("%d", &num);
			root=insertnode(root,num);
		}
		if (choose == 2)
		{
			scanf("%d", &num);
			root=deletenode(root,num);
		}
		traverse_BFS(root);
	}

	system("pause");
	return 0;
}
