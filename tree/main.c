#include <stdio.h>
//forward declaration

struct node;
typedef struct node Node;
struct node {
	int data;
	Node* left;
	Node* right;
};

void tree_insert(Node** pRoot, int item);
void preorder_traversal(Node* pRoot);
void destroy_tree(Node** pRoot);

int main(int argc, char* argv[]) {
	Node* root = NULL;
	tree_insert(&root, 5);
	tree_insert(&root, 15);
	tree_insert(&root, 1);
	tree_insert(&root, 25);
	tree_insert(&root, 17);
	tree_insert(&root, 3);
	tree_insert(&root, 9);
	tree_insert(&root, 8);
	preorder_traversal(&root);
	destroy_tree(&root);
	return 0;
}

void tree_insert(Node** pRoot, int item) {
	if (*pRoot == NULL) {
		*pRoot = (Node*)malloc(sizeof(Node));
		if (*pRoot == NULL)
			exit(1);
		(*pRoot)->data = item;
		(*pRoot)->left = NULL;
		(*pRoot)->right = NULL;
	}
	else {
		if (item < (*pRoot)->data)
			tree_insert(&(*pRoot)->left, item);
		else
			tree_insert(&(*pRoot)->right, item);
	}
}
void preorder_traversal(Node* pRoot) {
	if (pRoot != NULL) {
		printf("%d\n", pRoot->data);
		preorder_traversal(pRoot->left);
		preorder_traversal(pRoot->right);
	}
}
void destroy_tree(Node** pRoot) {
	if (*pRoot != NULL) {
		destroy_tree(&(*pRoot)->left);
		destroy_tree(&(*pRoot)->right);
		free(*pRoot);
	}
	*pRoot = NULL;
}