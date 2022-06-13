#include "bin_heap.h"
#include <assert.h>
#include <time.h>


int main() {
  srand(time(NULL));
  heap_t* heap = array_init(100);

  assert(size(heap) == 0);

  for (int i = 0; i < 10; i++) {
    insert(heap, rand() % 1000);
  }

  build_heap_max(heap);
  assert(is_max_heap(heap->array, size(heap), 0));

  heap_insert(heap, 800);
  assert(is_max_heap(heap->array, size(heap), 0));

  delete(heap);
  assert(is_max_heap(heap->array, size(heap), 0));


  destroy(heap);



  // testing with heapify after init
  heap_t* heap2 = array_init(1);
  
  clock_t start2 = clock();
  
  for (int i = 0; i < 10000; i++) {
    insert(heap2, rand() % 100000);
  }
  build_heap_max(heap2);
  
  clock_t end2 = clock();
  
  assert(is_max_heap(heap2->array, size(heap2), 0));
  //printf("full time: %f\n", (double)(end2 - start2) / CLOCKS_PER_SEC);

  destroy(heap2);


  
  // testing with inserting with heapify using build heap max O(n)
  heap_t* heap3 = array_init(1);
  
  clock_t start3 = clock();
  
  for (int i = 0; i < 10000; i++) {
    heap_insert(heap3, rand() % 100000);
  }
  
  clock_t end3 = clock();
  
  assert(is_max_heap(heap3->array, size(heap3), 0));
  //printf("full time: %f\n", (double)(end3 - start3) / CLOCKS_PER_SEC);

  destroy(heap3);


  // testing with inserting with heapify using fixup / fixdown O(log n)
  heap_t* heap4 = array_init(1);
  
  clock_t start4 = clock();
  for (int i = 0; i < 10000; i++) {
    heap_insert(heap4, rand() % 100000);
  }
  clock_t end4 = clock();
  
  assert(is_max_heap(heap4->array, size(heap4), 0));
  //printf("full time: %f\n", (double)(end4 - start4) / CLOCKS_PER_SEC);

  destroy(heap4);

  
  // testing with deleting from heap
  heap_t* heap5 = array_init(1);
  
  clock_t start5 = clock();
  for (int i = 0; i < 10000; i++) {
    heap_insert(heap5, rand() % 100000);
  }
  clock_t end5 = clock();

  for (int i = 0; i < 10000; i++) {
    delete(heap5);
  }

  assert(is_max_heap(heap5->array, size(heap5), 0));
  //printf("full time: %f\n", (double)(end5 - start5) / CLOCKS_PER_SEC);

  destroy(heap4);


  
  printf("All tests pass!\n");
  return 0;
}