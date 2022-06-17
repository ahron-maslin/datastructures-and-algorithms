#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H
#include "../binary_heap/bin_heap.h"

/*
Priority Queue (max):

Construction:     O(n)
Polling:          O(log(n))
Peeking:          O(1)
Adding:           O(log(n))
Naive removing:   O(n)
Naive contains:   O(n)
*/


typedef dynamic_array_t priority_queue_t;

void enqueue(priority_queue_t* pq, int data);
int dequeue(priority_queue_t* pq);
void change_priority(priority_queue_t* pq, int index, int priority);

#endif