#pragma once
#include <stdlib.h>
#include "status.h"

typedef void* QUEUE;

QUEUE queue_init_default(void);

Status queue_enqueue(QUEUE *hQueue, int item);

Status queue_dequeue(QUEUE hQueue);

void queue_destroy(QUEUE* phQueue);

Boolean queue_empty(QUEUE hQueue);

int get_front(QUEUE* hQueue);