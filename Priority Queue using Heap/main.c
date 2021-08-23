#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main(int argc, char * argv[]) {
	PRIORITY_QUEUE hQueue;
	hQueue = NULL;
	hQueue = priority_queue_init_default();

	if (hQueue == NULL) {
		printf("Priority queue not made!\n");
		exit(1);
	}

	priority_queue_insert(hQueue, 21, 10);
	priority_queue_insert(hQueue, 35, 5);
	priority_queue_insert(hQueue, 38, 8);

	printf("%d\n", priority_queue_front(hQueue, NULL));
	priority_queue_service(hQueue);

	printf("%d\n", priority_queue_front(hQueue, NULL));
	priority_queue_service(hQueue);

	printf("%d\n", priority_queue_front(hQueue, NULL));
	priority_queue_service(hQueue);

	return 0;
}