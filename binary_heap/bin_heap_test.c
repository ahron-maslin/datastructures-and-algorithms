#include "bin_heap.h"
#include <assert.h>
#include <time.h>


int main() {
  srand(time(NULL));
  heap_t* heap = array_init(5);

  assert(size(heap) == 0);

  for (int i = 0; i < 100; i++) {
    insert(heap, rand() % 1000);
  }

  build_heap_max(heap);
  assert(isMaxHeap(heap->array, size(heap), 0));

  build_heap_min(heap);
  assert(isMinHeap(heap->array, size(heap), 0));

  heap_insert(&build_heap_min, heap, 50);
  assert(isMinHeap(heap->array, size(heap), 0));

  delete(&build_heap_max, heap);
  assert(isMaxHeap(heap->array, size(heap), 0));


  destroy(heap);
  printf("All tests pass!\n");
  return 0;
}