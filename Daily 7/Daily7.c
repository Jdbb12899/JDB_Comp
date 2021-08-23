/**********************************************************************
Program: <Daily 7>
Author: <Jacob Blumsack>
Date: <10/07/19>
Time spent: <2.5 hrs>
Purpose: real use case for stack implementation
***********************************************************************/

#include<stdio.h> 
#include<stdlib.h> 

struct node {
	int data;
	struct Node* next;
};

typedef struct node Node;
int stack_pop(Node** TOP);
void stack_push(Node** TOP, int item);

int Match(char i, char j) { //check for matching pairs
	if (i == '(' && j == ')') {
		return 1;
	}
	else if (i == '[' && j == ']') {
		return 1;
	}
	else if (i == '{' && j == '}') {
		return 1;
	}
	return 0;
}

int Symmetrical(char arr[]) { //check for symmetrical
	int i = 0;
	Node *stack = NULL;

	while (arr[i]) {
		if (arr[i] == '{' || arr[i] == '(' || arr[i] == '[') {
			stack_push(&stack, arr[i]);
		}
		if (arr[i] == '}' || arr[i] == ')' || arr[i] == ']') {
			if (stack == NULL) {
				return 0;
			}
			else if (!Match(stack_pop(&stack), arr[i])) {
				return 0;
			}
		}
		i++;
	}

	if (stack == NULL) {
		return 1;
	}
	else
		return 0;
}

int main(int argc, char * argv[]) { //main
	char arr[100] = "([()[]()])}";
	if (Symmetrical(arr)) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}

int stack_pop(Node** TOP) { //pop
	char i;
	Node *top;

	if (*TOP == NULL) {
		printf("Error\n");
		getchar();
		exit(0);
	}
	else {
		top = *TOP;
		i = top->data;
		*TOP = top->next;
		free(top);
		return i;
	}
}

void stack_push(Node** TOP, int item) { //push
	Node* pNode = (Node*)malloc(sizeof(Node));
	if (pNode == NULL) {
		printf("Error");
		getchar();
		exit(0);
	}
	pNode->data = item;
	pNode->next = (*TOP);
	(*TOP) = pNode;
}