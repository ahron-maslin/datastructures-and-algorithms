#include "priority_queue.h"

void pqueue_insert(void(*funcp)(priority_queue_t*), priority_queue_t* pqueue, int item) {
  heap_insert(*funcp, pqueue, item);
}