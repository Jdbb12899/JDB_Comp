#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "Ferry.h"

enum bank_side { LEFT, RIGHT };

int main(int argc, char* argv[]) {
	enum bank_side side;
	side = LEFT;
	int scenarios;//how many scenarios
	int ferrylength;//ferry length
	int numberofcars;//number of cars on case
	char bank[30];//what bank left/right
	int carlength;//car length
	int trips = 0; //output value for how many ferry trips
	int totallength;//car1 + car2+carn....
	int currentside = 1;
	int i;
	int j;
	int k = 0;
	//left = 1
	//right = 2
	
	QUEUE right = queue_init_default();
	QUEUE left = queue_init_default();
	QUEUE total_trips = queue_init_default();
	QUEUE current_queue = left;
	//enter number of cases
	//enter length of ferry, space, how many cars queued
	//each car length on left/right bank
	//printf("How many scenarios will there be?\n");
	scanf_s("%d", &scenarios);
	for (j = 0; j < scenarios; j++) {
		current_queue = left;
		side = LEFT;
		trips = 0;
		//printf("How long is the ferry(meters) and how many cars?\n");
		scanf_s("%d %d", &ferrylength, &numberofcars);
		ferrylength = ferrylength * 100; //ferry length to cm
		for (i = 0; i < numberofcars; i++) {
			//printf("what is the car length(cm) and bank?\n");
			scanf_s(" %d %s", &carlength, bank, sizeof(bank));
			if (bank[0] == 'l') {
				queue_enqueue(left, carlength);
			}
			if (bank[0] == 'r') {
				queue_enqueue(right, carlength);
			}
		}
		//start on left bank
		while (queue_empty(left) == FALSE || queue_empty(right) == FALSE) {
			while (queue_empty(left) == FALSE || queue_empty(right) == FALSE) {
				totallength = get_front(current_queue);
				queue_dequeue(current_queue);
				while (queue_empty(current_queue) == FALSE && totallength + get_front(current_queue) < ferrylength) {
					totallength = totallength + get_front(current_queue);
					queue_dequeue(current_queue);
				}
				totallength = 0;
				trips++;
				if (side == LEFT) {
					side = RIGHT;
					current_queue = right;
				}
				else if (side == RIGHT) {
					side = LEFT;
					current_queue = left;
				}
			}
		}
		queue_enqueue(total_trips, trips);
	}
	for (j = 0; j < scenarios; j++) {
		printf("%d\n", get_front(total_trips));
		queue_dequeue(total_trips);
	}
	return 0;
}