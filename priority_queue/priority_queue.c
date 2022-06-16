#include "priority_queue.h"


void enqueue(priority_queue_t* pqueue, int data) {
  heap_insert(pqueue, data);
}

int dequeue(priority_queue_t* pqueue) {
  return delete(pqueue);
}

void change_priority(priority_queue_t* pqueue, int index, int priority) {
  if (index >= size(pqueue) || priority <= 0 || priority == pqueue->array[index]) {
    return;
  }

  pqueue->array[index] = priority;
  build_heap_max(pqueue);
}