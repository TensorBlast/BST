#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

int main()
{
	node *root = NULL;

	insert(&root, 60);
	insert(&root, 30);
	insert(&root, 20);
	insert(&root, 25);
	insert(&root, 10);
	insert(&root, 40);
	insert(&root, 70);

	inorder(root);

	delete(root, 30);

	printf("\n");

	inorder(root);

	return 0;
}