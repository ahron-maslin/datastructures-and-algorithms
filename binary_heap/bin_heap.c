#include "bin_heap.h"

static void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

static void heapify_max(int* array, int size, int root) {
  int largest = root;
  int left_child = 2 * root + 1;
  int right_child = 2 * root + 2;

  // If left child is larger than root
  if (left_child <= size && array[left_child] > array[largest]) {
    largest = left_child;
  }

  // If right child is larger than largest so far
  if (right_child <= size && array[right_child] > array[largest]) {
    largest = right_child;
  }

  // If largest is not root
  if (largest != root) {
    swap(&array[root], &array[largest]);
    heapify_max(array, size, largest);
  }
}


static void max_heap_fixup(heap_t* heap, int size) {
  int i = size - 1;
    while (i > 0 && heap->array[(i-1)/2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1)/2]);
        i = (i-1)/2;
    }
}

static void max_heap_fidown(heap_t* heap, int size) {
  while (2*size <= heap->size) {
  int j = 2*size;
  if (j < heap->size && heap->array[j+1] < heap->array[j])
  j++;
  if (heap->array[size] <= heap->array[j])
  break;
  swap(&heap->array[size], &heap->array[j]);
  size = j;
  }
}


void build_heap_max(heap_t* heap) {
  int last_non_leaf_node = (size(heap) / 2) - 1;
  // Perform reverse level order traversal
  // from last non-leaf node and heapify
  // each node
  for (int i = last_non_leaf_node; i >= 0; i--) {
    heapify_max(heap->array, size(heap), i);
  }
}


bool is_max_heap(int* arr, int n, int i) {
  for (int i = 0; i <= (n - 2) / 2; i++)
  {
    // If left child is greater, return false
    if (arr[2 * i + 1] > arr[i])
      return false;

    // If right child is greater, return false
    if (2 * i + 2 < n && arr[2 * i + 2] > arr[i])
      return false;
  }
  return true;
}


void heap_insert(heap_t* heap, int data) {
  insert(heap, data);
  max_heap_fixup(heap, size(heap));
}


int peek(heap_t* heap) {
  return heap->array[0];
}

int delete(heap_t* heap) {
  int data = heap->array[0];
  heap->array[0] = heap->array[--heap->size];
  //int data = remove_at(heap, 0);

  //build_heap_max(heap); // fixdown

  max_heap_fidown(heap, 0);
    return data;
}