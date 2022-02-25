#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
	int height;
	int bf;
}NODE;

int node_height(NODE *node)
{
	if (!node)
		return -1;
	else
	{
		int left_height = node_height(node->left);
		int right_height = node_height(node->right);
		return (left_height > right_height) ? left_height + 1 : right_height + 1;
	}
}

int calculate_balance_factor(NODE *node)
{
	return node_height(node->left)-node_height(node->right); //cant  (node->left->height) - (node->right->height)  because NULL does not have member(height)
}

NODE *leftrotate(NODE *root)
{
	NODE *store=root->right;
	root->right = root->right->left;
	store->left = root;
	//update height ,   height only depends on child,parents wont affect height
	root->height=node_height(root); 
	store->height=node_height(store);
	root->bf = calculate_balance_factor(root);
	store->bf = calculate_balance_factor(store);
	return store;
}

NODE *rightrotate(NODE *root)
{
	NODE *store = root->left;
	root->left = root->left->right;
	store->right = root;

	root->height=node_height(root);
	store->height=node_height(store);
	root->bf = calculate_balance_factor(root);
	store->bf = calculate_balance_factor(store);
	return store;
}

NODE *insertnode(NODE* root, int num)
{
	if (!root)
	{
		NODE* ptr = (NODE*)malloc(sizeof(NODE));
		ptr->data = num;
		ptr->left = NULL;
		ptr->right = NULL;
		ptr->height = 0;
		ptr->bf = 0;
		return ptr;
	}
	else
	{
		if (root->data > num)
			root->left = insertnode(root->left, num);
		else
			root->right = insertnode(root->right, num);
	}

	//the node on the path will update height and bf

	root->height = node_height(root);  //update height
	root->bf = calculate_balance_factor(root);
	if ((root->bf) > 1)  //left too heavy , not balance
	{
		//see is LL or LR
		if (root->left->bf == 1)
		{
			//LL
			root = rightrotate(root);
		}
		else
		{
			//LR
			root->left = leftrotate(root->left);
			root = rightrotate(root);
		}
	}
	else if ((root->bf < -1)) //right too heavy , not balance
	{
		//see is RR or RL
		if (root->right->bf == 1)
		{
			//RL
			root->right = rightrotate(root->right);
			root = leftrotate(root);
		}
		else
		{
			//RR
			root = leftrotate(root);
		}
	}

	return root; //after link,we shall return root back
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

NODE* deletenode(NODE* root, int num)  //ddelete the number and return back new root
{
	if (!root)
		return root;
	else if (root->data == num) //find
	{
		if ((!root->left) || (!root->right)) //no child or one child
		{
			NODE* ptr1 = root->left, *ptr2 = root->right;
			free(root);
			return ptr1 ? ptr1 : ptr2;
		}
		else //two child
		{
			int x = findsmallest_rightsubtree_data(root->right);
			root->right = deletenode(root->right, x); //cant root because it will be a cycle
			root->data = x;
		}
	}
	else if (root->data > num)
	{
		root->left = deletenode(root->left, num); //return back new root->left
	}
	else if (root->data < num)
	{
		root->right = deletenode(root->right, num);
	}
	
	root->height = node_height(root);  //update height
	root->bf = calculate_balance_factor(root);
	if ((root->bf) > 1)  //left too heavy , not balance
	{
		//see is LL or LR
		if (root->left->bf == 1)
		{
			//LL
			root = rightrotate(root);
		}
		else
		{
			//LR
			root->left = leftrotate(root->left);
			root = rightrotate(root);
		}
	}
	else if ((root->bf < -1)) //right too heavy , not balance
	{
		//see is RR or RL
		if (root->right->bf == 1)
		{
			//RL
			root->right = rightrotate(root->right);
			root = leftrotate(root);
		}
		else
		{
			//RR
			root = leftrotate(root);
		}
	}

	return root; //after link,we shall return root back
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
	//AVL tree : balanced BST


	int choose, num;
	NODE* root = NULL;

	for (;;)
	{
		printf("1for add 2for delete 3for find");
		scanf("%d", &choose);
		if (choose == 1)
		{
			scanf("%d", &num);
			root = insertnode(root, num);
		}
		if (choose == 2)
		{
			scanf("%d", &num);
			root = deletenode(root, num);
		}
		traverse_DFS_Inorder(root);
		printf("\n");

	}

	system("pause");
	return 0;
}
