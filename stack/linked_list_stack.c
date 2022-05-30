#include "linked_list_stack.h"

int nodes_count = 0;

ll_stack_t* init_ll_stack(int data) {
  ll_stack_t* stack = malloc(sizeof(struct LINKED_LIST_STACK));
  stack->data = data;
  stack->next = NULL;

  return stack;
}

void destroy(ll_stack_t* stack) {
  if (!stack) {
    return;
  }
  destroy(stack->next);
  free(stack);
  stack = NULL;
  nodes_count = 0;
}

void push(ll_stack_t** stack, int item) {
  ll_stack_t* new_head = init_ll_stack(item);
  if (*stack == NULL) {
    *stack = new_head;
    nodes_count++;
    return;
  }
  new_head->next = *stack;
  *stack = new_head;

  nodes_count++;
}

int pop(ll_stack_t** stack) {
  ll_stack_t* first_node = NULL;
  if (stack == NULL) {
    fprintf(stderr, "Stack is NULL!");
    exit(EXIT_FAILURE);
  }
  int data = peek(*stack);

  first_node = *stack; // points to first node so it can be freed
  *stack = (*stack)->next;
  nodes_count--;
  free(first_node);
  return data;
}

int peek(ll_stack_t* stack) {
  if (!is_empty(stack)) {
    return stack->data;
  }
  else {
    fprintf(stderr, "The stack is empty");
        exit(EXIT_FAILURE);
  }
}

bool is_empty(ll_stack_t* stack){
  return stack == NULL;
}

int size(ll_stack_t* stack) {
  return nodes_count;
}