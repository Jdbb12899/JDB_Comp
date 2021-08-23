#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;
struct node {
	int data;
	Node* next;
};

void swap(Node* a, Node* b);
void sortedInsert(Node** top, Node* new_node);
void insertionSort(struct Node** top);
void head_insert_node(Node** top, int data);

int main() {
	Node* top = NULL;
	printf("Enter a list of numbers, will terminate when a negative is encountered\n");
	int i = 0;
	int x;
	while (i != -1) {
		scanf("%d", x);
		head_insert_node(Node** top, x);
		printf("%d\n", x);
		}
		//after each number is entered, sort and delete duplicates
	}
	return 0;
}

void swap(Node* a, Node* b) {
	Node tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertionSort(struct Node** top) { // and delete duplicates
	if (top == NULL) {
		printf("List empty!\n");
		return 0;
	}
	Node *sorted = NULL;
	Node *current = *top;
	while (current != NULL) {
		Node *next = current->next;
		sortedInsert(&sorted, current);
		current = next;
	}
	*top = sorted;
}

void sortedInsert(Node** top, Node* new_node) {
	struct Node* current;
	if (*top == NULL || (*top)->data >= new_node->data) {
		new_node->next = *head_ref;
		*top = new_node;
	}
	else {
		current = *top;
		while (current->next != NULL && current->next->data < new_node->data) {
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

void head_insert_node(Node** top, int data) {
	Node* tmp = NULL;
	tmp = (Node*)malloc(sizeof(Node));
	if (tmp == NULL) {
		printf("no memory allocated\n");
		exit(1);
	}
	tmp->data = data;
	tmp->next = *top;
	*top = tmp;
}