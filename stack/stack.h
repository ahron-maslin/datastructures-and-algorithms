#ifndef _STACK_H
#define _STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
Stack

Pushing:     O(1)
Popping:     O(1)
Peeking:     O(1)
Searching:   O(1)
Size:        O(1)
*/

typedef struct STACK {
  int size;
  int top;
  int* items;
} stack_t;

stack_t* init_stack(int size);

void destroy(stack_t* stack);

void push(stack_t* stack, int item);

int pop(stack_t* stack);

int peek(stack_t* stack);

bool is_empty(stack_t* stack);

int size(stack_t* stack);

#endif