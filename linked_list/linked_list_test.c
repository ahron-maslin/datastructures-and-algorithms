#include <assert.h>
#include "linked_list.h"


bool int_cmp(void* data1, void* data2) {
  return data1 == data2;
}

int main() {
  int numbers[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
  
  node_t* head = NULL;
  push(&head, &numbers[2]);
  push_last(&head, &numbers[3]);
  push_last(&head, &numbers[4]);

  assert(node_data(head) == &numbers[2]);
  assert(node_data(get_next_node(head)) == &numbers[3]);

  push(&head, &numbers[1]);

  assert(node_data(head) == &numbers[1]);
  assert(peek_first(head) == &numbers[1]);
  assert(peek_last(head) == &numbers[4]);
  assert(remove_first(&head) == &numbers[1]);

  push(&head, &numbers[1]);

  assert(remove_at(&head, 2) == &numbers[3]);

  push_last(&head, &numbers[5]);
  push_last(&head, &numbers[6]);
  push_last(&head, &numbers[6]);
  remove_value(&head, &numbers[5], int_cmp);


  assert(contains(head, &numbers[6], int_cmp));
  assert(!contains(head, &numbers[400], int_cmp));

#ifdef DEBUG

  node_t *trav = head;
  while (trav){
    printf("%d\n", *(int*)node_data(trav));
    trav = get_next_node(trav);
}
#endif
  
  destroy(head, NULL);

  printf("All tests pass!\n");

  return 0;
}