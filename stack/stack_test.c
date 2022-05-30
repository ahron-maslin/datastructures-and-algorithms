#include <assert.h>
#include "stack.h"

int main() {
  stack_t* stack = init_stack(20);

  assert(is_empty(stack));

  for (int i = 0; i < 11; i++) {
    push(stack, i);
  }

  assert(!is_empty(stack));

  assert(pop(stack) == 10);
  assert(peek(stack) == 9);
  assert(pop(stack) == 9);

  assert(size(stack) == 9);


  destroy(stack);
  
  printf("All tests pass!\n");
  return 0;
}