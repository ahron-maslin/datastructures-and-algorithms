#include "queue.h"
#include <assert.h>

int main() {
  queue_t* queue = init_queue();
  for (int i = 0; i < 10000; i++) {
    enqueue(queue, i);
    assert(peek(queue) == 0);
  }

  assert(size(queue) == 10000);

  for(int i = 0; i < 10000; i++) {
    assert(dequeue(queue) == i);
  }

  
  assert(is_empty(queue));
  assert(size(queue) == 0);

  destroy(queue);
  printf("All tests pass!\n");
  return 0;
}