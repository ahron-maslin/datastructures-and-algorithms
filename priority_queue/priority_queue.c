#include "priority_queue.h"


void enqueue(priority_queue_t* pqueue, int data) {
  heap_insert(pqueue, data);
}

int dequeue(priority_queue_t* pqueue) {
  return delete(pqueue);
}