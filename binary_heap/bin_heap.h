#ifndef _BIN_HEAP_H
#define _BIN_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../array/dynamic_array.h"


/*
Binary Heap (min):

- parent(i) = [i/2]
- left − child(i) = 2i
- right − child(i) = 2i + 1

Construction:     O(n)        <-- same as heapify
Polling:          O(log(n))
Peeking:          O(1)
Adding:           O(log(n))
Naive removing:   O(n)
Naive contains:   O(n)
*/

typedef dynamic_array_t heap_t;

void build_heap_max(heap_t* heap);
void build_heap_min(heap_t* heap);
bool isMaxHeap(int* arr, int n, int i);
bool isMinHeap(int* arr, int n, int i);

void heap_insert(void(*funcp)(heap_t*), heap_t* heap, int item);
int peek(heap_t* heap);
int delete(void(*funcp)(heap_t*), heap_t* heap);


#endif