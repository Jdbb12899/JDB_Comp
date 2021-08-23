#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

struct node {
	int priority;
	int number;
};
typedef struct node Node;

struct priority_queue{
	int size;
	int capacity;
	Node* data;
	int front;
	int back;
};
typedef struct priority_queue Priority_queue;

PRIORITY_QUEUE priority_queue_init_default(void) { //queue init
	Priority_queue* pPriority_queue;
	pPriority_queue = (Priority_queue*)malloc(sizeof(Priority_queue));
	if (pPriority_queue != NULL) {
		pPriority_queue->size = 0;
		pPriority_queue->capacity = 1;
		pPriority_queue->data = (Node*)malloc(sizeof(Node) * pPriority_queue->capacity);
		pPriority_queue->front = 0;
		pPriority_queue->back = 0;
	}
	return pPriority_queue;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item) {
	Priority_queue* pPriority_queue = (Priority_queue*)hQueue;
	Node* tmp;
	Node swap;
	int i;
	int parent;
	if (pPriority_queue->size >= pPriority_queue->capacity) { //first half is enqueue function
		tmp = (Node*)malloc(sizeof(Node) * pPriority_queue->capacity * 2);
		if (tmp == NULL) {
			return FAILURE;
		}
		for (i = 0; i < pPriority_queue->size; ++i) {
			tmp[i] = pPriority_queue->data[i];
		}
		free(pPriority_queue->data);
		pPriority_queue->data = tmp;
		pPriority_queue->capacity *= 2;
		pPriority_queue->front = 0;
		pPriority_queue->back = pPriority_queue->size;
	}
	i = pPriority_queue->size;
	(pPriority_queue->data[i]).priority = priority_level;
	(pPriority_queue->data[i]).number = data_item;
	parent = (i - 1) / 2;
	while (i >= 1 && ((pPriority_queue->data[i]).priority > (pPriority_queue->data[parent]).priority)) {
		swap = pPriority_queue->data[parent];  //swap (in fix up implementation in class, a swap function was used and function was recursive
		pPriority_queue->data[parent] = pPriority_queue->data[i]; //swap
		pPriority_queue->data[i] = swap; //swap
		i = parent;
		parent = (i - 1) / 2; //i for implementaion
	}
	pPriority_queue->front = 0;
	pPriority_queue->size++; //increment size
	pPriority_queue->back = pPriority_queue->size - 1;
	return SUCCESS;
}

//  2 * i + 1
// (i - 1) / 2

Status priority_queue_service(PRIORITY_QUEUE hQueue) {
	Priority_queue* pPriority_queue = (Priority_queue*)hQueue;
	Node* tmp = (Node*)malloc(sizeof(Node));
	Node* swap = (Node*)malloc(sizeof(Node)); 
	int i = 0;
	int alternate = 1;
	int left_index;
	int right_index;
	left_index = 2 * i + 1;
	right_index = 2 * i + 1;
	if (priority_queue_is_empty(pPriority_queue) == TRUE) { //return failure if priority queue is empty
		return FAILURE;
		exit(1);
	} //return success if highest priority item removed
	*swap = pPriority_queue->data[0]; //swap
	pPriority_queue->data[0] = pPriority_queue->data[pPriority_queue->back];
	pPriority_queue->data[pPriority_queue->back] = *swap;
	pPriority_queue->size--;
	while (left_index < pPriority_queue->size && alternate != 0) { //until left index is same as size
		alternate = 0; //two cases
		if ((pPriority_queue->data[right_index]).priority > (pPriority_queue->data[left_index]).priority && right_index < pPriority_queue->size) {
			if ((pPriority_queue->data[i]).priority < (pPriority_queue->data[right_index]).priority) { //right index case
				*tmp = pPriority_queue->data[i];
				pPriority_queue->data[i] = pPriority_queue->data[right_index];
				pPriority_queue->data[right_index] = *tmp;
				i = right_index;

				left_index = 2 * i + 1;
				right_index = 2 * i + 2;

				alternate = 1;
			}
		}
		else {
			if ((pPriority_queue->data[i]).priority < (pPriority_queue->data[left_index]).priority) { //switch off, left index case
				*tmp = pPriority_queue->data[i];
				pPriority_queue->data[i] = pPriority_queue->data[left_index];
				pPriority_queue->data[left_index] = *tmp;
				i = left_index;

				left_index = 2 * i + 1;
				right_index = 2 * i + 2;

				alternate = 1; //binary 0,1
			}
		}
	}
	pPriority_queue->back = pPriority_queue->size - 1;
	return SUCCESS;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus) {
	Priority_queue* pPriority_queue = (Priority_queue*)hQueue;
	if (priority_queue_is_empty(pPriority_queue) == TRUE) { //check empty
		if (pStatus != NULL) {
			*pStatus = FAILURE;
		}
		exit(1);
	}
	else if (pStatus != NULL) {
		*pStatus = SUCCESS;
	}
	return (pPriority_queue->data[pPriority_queue->front]).number; //return front
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue) { //empty function
	Priority_queue* pPriority_queue = (Priority_queue*)hQueue;
	return (Boolean)(pPriority_queue->size == 0);
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue) { //destroy
	Priority_queue* pPriority_queue = (Priority_queue*)*phQueue;
	free(pPriority_queue->data);
	free(*phQueue);
	*phQueue = NULL;
}