#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H
#include "../binary_heap/bin_heap.h"

typedef dynamic_array_t priority_queue_t;

void pqueue_insert(void(*funcp)(priority_queue_t*), priority_queue_t* pqueue, int item);


#endif