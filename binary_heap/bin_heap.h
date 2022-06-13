#ifndef _BIN_HEAP_H
#define _BIN_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../array/dynamic_array.h"


/*
Binary Heap (max):

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

// shift up / shift down --> log n

typedef dynamic_array_t heap_t;

void build_heap_max(heap_t* heap);
bool is_max_heap(int* arr, int n, int i);

void heap_insert(heap_t* heap, int item);
void heap_insert_log(heap_t* heap, int item);
int peek(heap_t* heap);
int delete(heap_t* heap);

#endif