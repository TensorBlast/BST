

struct treenode
{
	int key;
	struct treenode *left;
	struct treenode *right;
};

typedef struct treenode node;

node * getparent(node * root, int key);
void insert(node **root, int key);
node * search(node *root, int key);
node * delete(node *root, int key);
void inorder(node * root);
void preorder(node * root);