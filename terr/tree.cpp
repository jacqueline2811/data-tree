// BinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>

struct node
{
	int key_value;
	node *left;
	node *right;
	node* parent;
};

void insert(int key, node *&leaf, node *parent)
{
	if (leaf == NULL)
	{
		leaf = new node;
		leaf->key_value = key;
		leaf->left = NULL;
		leaf->right = NULL;
		leaf->parent = parent;
	}
	else
	{
		if (key < leaf->key_value)
		{
			insert(key, leaf->left, leaf);
		}
		else if (key >= leaf->key_value)
		{
			insert(key, leaf->right, leaf);
		}
	}
}


void destroy_tree(node *&leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

node *search(int key, node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key_value)
			return leaf;
		if (key < leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return NULL;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int height(node* leaf)
{
	if (leaf == NULL)
		return 0;
	else
	{
		int height_l = height(leaf->left);
		int height_r = height(leaf->right);
		return 1 + max(height_l, height_r);
	}
}

void print(node* leaf)
{
	if (leaf != NULL)
	{
		print(leaf->left);
		printf(" %d ", leaf->key_value);
		print(leaf->right);
	}
}



/*Function to print all nodes at a given level*/
void printGivenLevel(node* leaf, int level)
{
	if (leaf != NULL)
	{
		if (level == 1)
		{
			for (int i = 0; i < height(leaf); i++)
				printf("   ");
			printf("%d", leaf->key_value);
			for (int i = 0; i < height(leaf); i++)
				printf("   ");
		}
		else //if (level > 1)
		{
			printGivenLevel(leaf->left, level - 1);
			printGivenLevel(leaf->right, level - 1);
		}

	}
}

void printLevelorder(node* leaf)
{
	for (int i = 1; i < height(leaf) + 1; i++)
	{
		printGivenLevel(leaf, i);
		printf("\n");
	}

}



int main()
{
	node *root = NULL;
	insert(10, root, NULL);
	insert(6, root, NULL);
	insert(14, root, NULL);
	insert(5, root, NULL);
	insert(8, root, NULL);
	insert(11, root, NULL);
	insert(18, root, NULL);


	node* leaf1 = search(6, root);
	node* leaf2 = search(9, root);

	int h = height(root);

	print(root);
	printf("\n\n");
	printLevelorder(root);
	destroy_tree(root);
	getchar();

}
