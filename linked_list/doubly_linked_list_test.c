#include <assert.h>
#include "doubly_linked_list.h"

int main() {
  // init list
  dnode_t* head = NULL;
  for (int i = 10; i > 0; i--) {
    push(&head, i);
  }

  push_last(&head, 42);
  
  assert(peek_first(head) == 1);
  assert(peek_last(head) == 42);

  assert(remove_first(&head) == 1);
  assert(remove_at(&head, 1) == 3);

  push_last(&head, 55);
  remove_value(&head, 5);
  
  assert(peek_last(head) == 55);
  assert(contains(head, 55));
  assert(!contains(head, 5445));


  // display list 
  /*
  dnode_t* temp = head;
  while (head != NULL) {
    printf("--->%d", head->data);
    temp = head;
    head = head->next;
  }
  printf("\n");
  while (temp != NULL) {
    printf("--->%d", temp->data);
    temp = temp->prev;
  }
*/
  
  destroy(head);
  printf("All tests pass!\n");
  return 0;
}