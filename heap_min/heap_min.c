#include "heap_min.h"

static void swap(int* a, int* b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}


static void heapify_min(int* array, int size, int root) {
  int smallest = root;
  int left_child = 2 * root + 1;
  int right_child = 2 * root + 2;


  if (left_child < size && array[left_child] < array[smallest]) {
    smallest = left_child;
  }
  if (right_child < size && array[right_child] < array[smallest]) {
    smallest = right_child;
  }

  if (smallest != root) {
    swap(&array[root], &array[smallest]);
    heapify_min(array, size, smallest);
  }

}


static void minheap_fixup(min_heap_t* heap, int size) {
  int i = size - 1; // compensate for array starting at 0 instead of 1
  while (i > 0 && heap->array[i] < heap->array[(i - 1) / 2]) {
    swap(&heap->array[(i - 1) / 2], &heap->array[i]);
    i = (i-1)/ 2;
  }
}


static void minheap_fixdown(min_heap_t* heap, int index) {
  while (2 * index+1 < heap->size) {
    int j = 2 * index+1;
    if (j + 1 < heap->size && heap->array[j + 1] < heap->array[j]){
      j++;
    }
    if (heap->array[index] <= heap->array[j]){
      break;
    }

    swap(&heap->array[index], &heap->array[j]);
    index = j;
  }
}


void build_heap_min(min_heap_t* heap) {
  int last_non_leaf_node = (size(heap) / 2) - 1;
  // Perform reverse level order traversal
  // from last non-leaf node and heapify
  // each node
  for (int i = last_non_leaf_node; i >= 0; i--) {
    heapify_min(heap->array, size(heap), i);
  }
}


bool is_min_heap(int* arr, int n, int i) {
  for (int i = 0; i <= (n - 2) / 2; i++)
  {
    // If left child is greater, return false
    if (arr[2 * i + 1] < arr[i])
      return false;

    // If right child is greater, return false
    if (2 * i + 2 > n && arr[2 * i + 2] < arr[i])
      return false;
  }
  return true;
}


void heap_insert(min_heap_t* heap, int data) {
  insert(heap, data);
  minheap_fixup(heap, size(heap));
}


int peek(min_heap_t* heap) {
  return heap->array[0];
}


int poll(min_heap_t* heap) {
  int data = heap->array[0];
  heap->array[0] = heap->array[--heap->size];
  minheap_fixdown(heap, 0);
  return data;
}