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
  if (left_child < size && array[left_child] > array[largest]) {
    largest = left_child;
  }

  // If right child is larger than largest so far
  if (right_child < size && array[right_child] > array[largest]) {
    largest = right_child;
  }

  // If largest is not root
  if (largest != root) {
    swap(&array[root], &array[largest]);
    heapify_max(array, size, largest);
  }

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


void build_heap_max(heap_t* heap) {
  int last_non_leaf_node = (size(heap) / 2) - 1;
  // Perform reverse level order traversal
  // from last non-leaf node and heapify
  // each node
  for (int i = last_non_leaf_node; i >= 0; i--) {
    heapify_max(heap->array, size(heap), i);
  }
}


void build_heap_min(heap_t* heap) {
  int last_non_leaf_node = (size(heap) / 2) - 1;
  // Perform reverse level order traversal
  // from last non-leaf node and heapify
  // each node
  for (int i = last_non_leaf_node; i >= 0; i--) {
    heapify_min(heap->array, size(heap), i);
  }
}


bool isMaxHeap(int* arr, int n, int i) {
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

bool isMinHeap(int* arr, int n, int i) {
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


void heap_insert(void(*fp)(heap_t*), heap_t* heap, int item) {
  insert(heap, item);
  fp(heap);
}

int peek(heap_t* heap) {
  return heap->array[0];
}

int delete(void(*fp)(heap_t*), heap_t* heap) {
  int data = remove_at(heap, 0);
  fp(heap);
  return data;
}