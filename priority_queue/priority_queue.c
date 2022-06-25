#include "priority_queue.h"


void enqueue(priority_queue_t* pq, int data) {
  heap_insert(pq, data);
}

int dequeue(priority_queue_t* pq) {
  return poll(pq);
}

void change_priority(priority_queue_t* pq, int index, int priority) {
  if (index >= size(pq) || priority <= 0 || priority == pq->array[index]) {
    return;
  }

  pq->array[index] = priority;
  build_heap_max(pq);
}