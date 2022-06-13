#ifndef _DYNAMIC_ARRAY_H
#define _DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define min(a,b) (((a)<(b))?(a):(b))

/*
Dynamic Array

Access:    O(1)
Search:    O(n)
Insertion: O(n)
Appending: O(1)
Deletion:  O(n)
*/

typedef struct DYNAMIC_ARRAY {
  int* array;
  int capacity;
  int size;
} dynamic_array_t;

dynamic_array_t* array_init(int capacity);
void destroy(dynamic_array_t *array);

int size(dynamic_array_t *array);
bool is_empty(dynamic_array_t *array);

int get(dynamic_array_t *array, int index);
void set(dynamic_array_t *array, int index, int data);

void insert(dynamic_array_t* array, int data);
void insert_at(dynamic_array_t *array, int index, int data);

int remove_at(dynamic_array_t *array, int index);
void remove_element(dynamic_array_t* array, int data);

int index_of(dynamic_array_t *array, int data);
bool contains(dynamic_array_t *array, int data);
#endif