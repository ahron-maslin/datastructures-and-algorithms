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

typedef struct LINKED_LIST_STACK {
  int data;
  struct LINKED_LIST_STACK* next;
} ll_stack_t;

ll_stack_t* init_ll_stack(int data);

void destroy(ll_stack_t* stack);

void push(ll_stack_t** stack, int item);

int pop(ll_stack_t** stack);

int peek(ll_stack_t* stack);

bool is_empty(ll_stack_t* stack);

int size(ll_stack_t* stack);

#endif