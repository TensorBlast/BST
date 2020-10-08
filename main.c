#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

int main()
{
	node *root = NULL;

	insert(&root, 5);
	insert(&root, 3);
	insert(&root, 4);
	insert(&root, 7);

	inorder(root);

	node * res = search(root,4);

	printf("%s%d\n", "Found node: ",res->key);

	delete(root, 7);

	return 0;
}