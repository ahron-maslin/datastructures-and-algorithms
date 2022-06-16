#include "priority_queue.h"
#include <assert.h>
#include <time.h>


int main() {
  srand(time(NULL));

  priority_queue_t* pqueue = array_init(1);

  assert(size(pqueue) == 0);

  for (int i = 0; i < 10000; i++) {
    enqueue(pqueue, rand() % 100000);
  }

  for (int i = 0; i < 100; i++) {
    change_priority(pqueue, rand() % 9999, rand() % 100000);
  }

  assert(is_max_heap(pqueue->array, size(pqueue), 0));

  assert(dequeue(pqueue) >= dequeue(pqueue));

  destroy(pqueue);

  printf("All tests pass!\n");
  return 0;
}