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

void preorder(node * root)
{
	if (root!=NULL) {
		printf("%d-> ",root->key );
		preorder(root->left);
		preorder(root->right);
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
		else if (key < t->key) {
			parent = t;
			t = t->left;
		}
		else {
			parent = t;
			t = t->right;
		}
		
	}
	return NULL;
}

static void transplant(node * root, node * u, node * v)
{
	node *uparent = getparent(root, u->key);
	node * vparent = getparent(root, v->key);

	if (uparent == NULL)
		root = v;
	else if (u == uparent->left)
		uparent->left = v;
	else uparent->right = v;

	if (v!=NULL)
		vparent = uparent;
}

static node * getminvalue(node * root)
{
	while (root ->left!=NULL)
		root = root->left;

	return root;
}

node * delete(node *root, int key)
{
	node * todelete = search(root,key), *parent = getparent(root, key), *y;
	if (todelete==NULL) {
		fprintf(stderr, "%s\n", "Key not found");
		exit(2);
	}


	if (todelete->left == NULL && todelete->right==NULL) { //Deleting node with no children
		if (parent) {
			if (todelete == parent->left)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		free(todelete);
		return root;
	}
	else if (todelete->left && !todelete->right) {
		if (parent) {
			if (todelete == parent->left)
				parent->left = todelete->left;
			else
				parent->right = todelete->left;
		}
		else if (root==todelete) {
			root = root -> left;
		}
		free(todelete);
		return root;
	}
	else if (todelete->right && !todelete->left) {
		if(parent) {
			if (todelete == parent->left)
				parent->left = todelete->right;
			else
				parent->right = todelete->right;
		}
		else if(root==todelete) {
			root = root->right;
		}
		free(todelete);
		return root;
	}
	else {
	// {	printf("%s\n", "Here");
	// 	node * yparent = NULL;
	// 	y= todelete->right;
	// 	while (y->left!=NULL)
	// 	{
	// 		y = y->left;
	// 	}
	// 	yparent = getparent(root, y->key);
	// 	printf("yparent - %d\n", yparent->key);
	// 	if(yparent != todelete) {
	// 		yparent->right = y->right;
	// 		y->right = todelete->right;
	// 		node *yrightparent = getparent(root, y->right->key);
	// 		yrightparent = y;
	// 	}
	// 	parent->right = y;
	// 	y->left = todelete->left;
	// 	node * yleftparent = getparent(root, y->left->key);
	// 	yleftparent = y;
	// 	free(todelete);
	// 	return root;
		y = todelete->right;
		while(y->left!=NULL)
		{
			y = y->left;
		}
		node *yparent = getparent(root, y->key);
		if (yparent != todelete)
		{	
			transplant(root, y, y->right);
			y->right = todelete->right;
			node * yrightparent = getparent(root, y->right->key);
			yrightparent = y;
		}
		transplant(root, todelete, y);
		y->left = todelete->left;
		node *yleftparent = getparent(root, y->left->key);
		yleftparent = y;
		if (root == todelete)
			root = y;
		free(todelete);


		return root;

	}


}