#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;
struct node {
	int data;
	Node* next;
};

void head_insert_node(Node** top, int data);
void tail_insert_recursive(Node** top, int data);
void tail_insert(Node** top, int data);
void list_destroy(Node** top);
void swap(Node* a, Node* b);
void count_up(int n);
void count_down(int n);

int main() {
	printf("Enter a list of numbers, will terminate when a negative is encountered\n");
	int i = 0;
	int x;
	while (i != -1) {
		scanf("%d", x);
		printf("");
	}
	return 0;
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

void tail_insert_recursive(Node** top, int data) {
	if (*top == NULL) {
		*top = (Node*)malloc(sizeof(Node));
		if (*top == NULL)
			exit(1);
		(*top)->data = data;
		(*top)->next = NULL;
	}
	else
		tail_insert_recursive(&(*top)->next, data);

}

void tail_insert(Node** top, int data) {
	Node* tmp;
	if (*top == NULL) {
		*top = (Node*)malloc(sizeof(Node));
		if (*top == NULL)
			exit(1);
		(*top)->data = data;
		(*top)->next = NULL;
	}
	else {
		tmp = *top;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (Node*)malloc(sizeof(Node));
		if (tmp->next != NULL) {
			(tmp->next)->data = data;
			(tmp->next)->next = NULL;
		}
	}
}

void list_destroy(Node** top) {
	Node* tmp;
	tmp = *top;
	while (tmp != NULL) {
		*top = tmp->next;
		free(tmp);
		tmp = *top;
	}
}

void count_up(int n) {
	if (n >= 0) {
		count_up(n - 1);
		printf("%d ", n);
	}
}
void count_down(int n) {
	if (n >= 0) {
		printf("%d ", n);
		count_down(n - 1);
	}
}

void swap(Node* a, Node* b) {
	Node tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertionSort(struct Node** top) {
	if (top == NULL) {
		printf("List empty!\n");
		return 0;
	}
	Node *sorted = NULL;
	Node *current = *top;
	while (current != NULL) {
		Node *next = current->next;
		current = next;
	}
	*top = sorted;
}