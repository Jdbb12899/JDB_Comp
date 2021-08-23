///**********************************************************************
//Program: <Program 2 Ferry Loading>
//Author: <Jacob Blumsack>
//Date: <10/15/19>
//Time spent: <2 hours>
//Purpose: Practice with queue and linked list implementation with real world application
//***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Ferry.h"

typedef struct node Node;
struct node;
struct node {
	int data;
	Node* next;
};

struct queue {
	Node* front;
	Node* back;
};
typedef struct queue Queue;

QUEUE queue_init_default() {
	Queue* pQueue = NULL;
	pQueue = (Queue*)malloc(sizeof(Queue));
	if (pQueue != NULL) {
		pQueue->front = NULL;
		pQueue->back = NULL;
	}
	return pQueue;
}

Status queue_enqueue(QUEUE *hQueue, int item) {
	Queue* pQueue = (Queue*)hQueue;
	Node* tmp;
	if (pQueue->front == NULL) {
		pQueue->front = (Node*)malloc(sizeof(Node));
		if (pQueue->front == NULL)
			exit(1);
		pQueue->front->data = item;
		pQueue->front->next = NULL;
	}
	else {
		tmp = pQueue->front;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (Node*)malloc(sizeof(Node));
		if (tmp->next != NULL) {
			(tmp->next)->data = item;
			(tmp->next)->next = NULL;
		}
	}
	return SUCCESS;
}

Status queue_dequeue(QUEUE hQueue) {
	Queue* pQueue = (Queue*)hQueue;
	Node* tmp = pQueue->front;
	if (pQueue->front != NULL) {
		pQueue->front = pQueue->front->next;
		return SUCCESS;
	}
	return FAILURE;
}

void queue_destroy(QUEUE* phQueue) {
	Queue* pQueue = (QUEUE)*phQueue;
	Node* tmp;
	tmp = pQueue->front;
	while (tmp != NULL) {
		pQueue->front = tmp->next;
		free(tmp);
		tmp = pQueue->front;
	}
}

Boolean queue_empty(QUEUE hQueue) {
	Queue* pQueue = (Queue*)hQueue;
	return (Boolean)(pQueue->front == NULL);
}

int get_front(QUEUE* hQueue) {
	Queue* pQueue = (Queue*)hQueue;
	if (pQueue->front == NULL) {
		//printf("This queue is empty");
		return 0;
	}
	return pQueue->front->data;
}