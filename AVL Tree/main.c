#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;
struct node {
	int data;
	Node* left;
	Node* right;
	int balance_factor;
};

int insert_report_taller(Node** pRoot, int value);
void traversal_inorder(Node* root);
Node* check_balance(Node** pRoot);
Node* rotate_left_right(Node** pRoot);

int main(int argc, char* argv[]) {
	Node* root = NULL;
	int taller;
	insert_report_taller(&root, 42);
	insert_report_taller(&root, 21);
	taller = insert_report_taller(&root, 33);
	traversal_inorder(root);
	printf("-------------\n");
	if (taller)
		check_balance(&root);
	traversal_inorder(root);
	return 0;
}

int insert_report_taller(Node** pRoot, int value) {
	//if pRoot = NULL
	//create new node -> root
	//if not NULL, insert node on left or right
	int old_balance_factor;
	if (*pRoot == NULL) {
		*pRoot = (Node*)malloc(sizeof(Node));
		if (*pRoot == NULL) {
			printf("error\n");
			exit(1);
		}
		(*pRoot)->data = value;
		(*pRoot)->left = NULL;
		(*pRoot)->right = NULL;
		(*pRoot)->balance_factor = 0;
	}
	else {
		old_balance_factor = (*pRoot)->balance_factor;
		if (value < (*pRoot)->data) {
			//if tree is taller
			if (insert_report_taller(&(*pRoot)->left, value)) {
				(*pRoot)->balance_factor++;
				if ((*pRoot)->balance_factor > old_balance_factor) {
					return 1;
				}
				else 
					return 0;
			}
			else
				return 0;
		}
		}
	return 1;
}
void traversal_inorder(Node* root) {
	if (root != NULL) {
		traversal_inorder(root->left);
		printf("value = %d\tbalance_factor = %d\n", root->data, root->balance_factor);
		traversal_inorder(root->right);
	}
}
Node* check_balance(Node** pRoot) {
	if ((*pRoot)->balance_factor == 2) {  //paretn is left heavy
		if (((*pRoot)->left)->balance_factor == 1) {
		}
		else
			rotate_left_right(&(*pRoot));
	}
	return NULL;
}
Node* rotate_left_right(Node** pRoot) {
	Node* tmp_root = *pRoot;
	Node* tmp_left = (*pRoot)->left;
	Node* tmp_right = ((*pRoot)->left)->right;
	// rotate child left
	tmp_root->left = tmp_right;
	tmp_left->right = NULL;
	tmp_right->left = tmp_left;
	tmp_left->balance_factor++;
	//rotate parent right
	*pRoot = tmp_right;
	(tmp_right->right)->left == NULL;
	(tmp_right->right)->balance_factor = 0;
	return NULL;
}