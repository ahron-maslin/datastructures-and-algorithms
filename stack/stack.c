#include "stack.h"

stack_t* init_stack(int size) {
  stack_t* stack = malloc(sizeof(struct STACK));
  stack->size = size;
  stack->top = -1;
  stack->items = malloc(sizeof(int) * size);

  return stack;
}

void destroy(stack_t* stack) {
  free(stack->items);
  free(stack);
}

void push(stack_t* stack, int item) {
  if (stack->top == stack->size - 1) {
    fprintf(stderr, "Overflow detected!\n");
    exit(EXIT_FAILURE);
  }
  
  stack->items[++stack->top] = item;
}

int pop(stack_t* stack) {
  if (is_empty(stack)) {
    fprintf(stderr, "Underflow detected!\n");
    exit(EXIT_FAILURE);
  }
  
  return stack->items[stack->top--];
}

int peek(stack_t* stack) {
  return stack->items[stack->top];
}

bool is_empty(stack_t* stack) {
  return stack->top == -1;
}

int size(stack_t* stack) {
  return stack->top + 1;
}
