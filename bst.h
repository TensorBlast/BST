

struct treenode
{
	int key;
	node *left;
	node *right;
};

typedef struct treenode node;

void insert(node ** root, int key);
node * search(node * root, int key);
node * delete(node * root, int key);