#ifndef HEAP_MIN_H
#define HEAP_MIN_H

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

// shift up / shift down --> log n

typedef dynamic_array_t min_heap_t;

void build_heap_min(min_heap_t* heap);
bool is_min_heap(int* arr, int n, int i);

void heap_insert(min_heap_t* heap, int data);
int peek(min_heap_t* heap);
int poll(min_heap_t* heap);

#endif