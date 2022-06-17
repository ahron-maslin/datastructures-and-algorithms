#include "priority_queue.h"
#include <assert.h>
#include <time.h>


int main() {
  srand(time(NULL));

  priority_queue_t* pq = array_init(1);

  assert(size(pq) == 0);

  for (int i = 0; i < 10000; i++) {
    enqueue(pq, rand() % 100000);
  }

  for (int i = 0; i < 100; i++) {
    change_priority(pq, rand() % 9999, rand() % 100000);
  }

  assert(is_max_heap(pq->array, size(pq), 0));

  assert(dequeue(pq) >= dequeue(pq));

  destroy(pq);

  printf("All tests pass!\n");
  return 0;
}