#include <assert.h>
#include "linked_list.h"

int main(){
  node_t* head = NULL;
  push(&head, 2);
  push_last(&head, 3);
  push_last(&head, 4);

  assert(head->data == 2);
  assert(head->next->data == 3);

  push(&head, 1);

  assert(head->data == 1);
  assert(peek_first(head) == 1);
  assert(peek_last(head) == 4);
  assert(remove_first(&head) == 1);

  push(&head, 1);

  assert(remove_at(&head, 2) == 3);

  push_last(&head, 5);
  push_last(&head, 6);
  remove_value(&head, 5);


  assert(contains(head, 6));
  assert(!contains(head, 400));

  /*

  node_t *trav = head;
  while (trav != NULL){
    printf("%d\n", trav->data);
    trav = trav->next;
  }
*/
  destroy(head);

  printf("All tests pass!\n");

  return 0;
}