#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


void error()
{
	fprintf(stderr, "%s\n", "Error assigning memory to node");
	exit(1);
}

void insert(node **root, int key)
{
	node *t1, *t2;

	if (*root == NULL) {
		printf("Root is null\n");
		*root = (node *)malloc(sizeof(node));
		if (*root==NULL) {
			fprintf(stderr, "%s\n", "Cannot allocate memory for node in Insert");
			exit(1);
		}
		(*root)->key = key;
		(*root)->left = (*root)->right = NULL;
	}
	else {
		printf("Root contains data. Inserting new node.\n");
		t1 = *root;

		while (t1 != NULL) {
			t2 = t1;

			if (key < t1->key)
				t1 = t1->left;
			else
				t1 = t1->right;
		}

		if(key < t2->key) {
			t2->left = (node *) malloc(sizeof(node));
			t2 = t2->left;
			if (t2==NULL)
				error();
			t2 -> key = key;
		}
		else {
			t2->right = (node *) malloc(sizeof(node));
			t2 = t2->right;
			if (t2==NULL)
				error();
			t2->key = key;
		}
	}

	
}

void inorder(node * root)
{
	if (root!=NULL) {
		inorder(root->left);
		printf("%d ->", root->key);
		inorder(root->right);
	}
}

node * search(node *root, int key)
{
	node * t = root;

	while (t!=NULL)
	{
		if (key == t->key)
			return t;
		else if (key < t->key)
			t = t->left;
		else
			t = t->right;
	}
	return NULL;
}

node * getparent(node * root, int key)
{
	node * t = root, *parent = NULL;

	while (t!=NULL)
	{	
		if (key == t->key)
			return parent;
		else if (key < t->key)
			t = t->left;
		else
			t = t->right;
		parent = t;
	}
	return NULL;
}

node * delete(node *root, int key)
{
	node * todelete = search(root,key), parent = getparent(root, key);
	if (todelete==NULL) {
		fprintf(stderr, "%s\n", "Key not found");
		exit(2);
	}

}