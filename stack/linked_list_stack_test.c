#include <assert.h>
#include "linked_list_stack.h"

int main() {
  ll_stack_t* stack = NULL;

  assert(is_empty(stack));

  for (int i = 0; i < 11; i++) {
    push(&stack, i);
  }

  assert(!is_empty(stack));

  assert(pop(&stack) == 10);
  assert(peek(stack) == 9);
  assert(pop(&stack) == 9);

  assert(size(stack) == 9);


  destroy(stack);
  
  printf("All tests pass!\n");
  return 0;
}