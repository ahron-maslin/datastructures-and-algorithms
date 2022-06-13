#include "priority_queue.h"
#include <assert.h>
#include <time.h>


int main() {
  srand(time(NULL));

  priority_queue_t* pqueue = array_init(5);

  assert(size(pqueue) == 0);

  for (int i = 0; i < 20; i++) {
    pqueue_insert(&build_heap_max, pqueue, rand() % 1000);
  }

  assert(isMaxHeap(pqueue->array, size(pqueue), 0));

  for (int i = 0, n = 2; i < 20; i++) {
    printf("%d ", get(pqueue, i));
  }


  printf("All tests pass!\n");
  return 0;
}