#include "doubly_linked_list.h"

static dnode_t *init_node(int data) {
  dnode_t* list = malloc(sizeof(struct DOUBLY_LINKED_LIST));
  list->data = data;
  list->next = NULL;
  list->prev = NULL;

  return list;
}

void destroy(dnode_t *list) {
  if (!list) {
    return;
  }
  // recursively free next pointer
  destroy(list->next);
  free(list);
  list = NULL;
}

void push(dnode_t **head, int data) {
  dnode_t* new_head = init_node(data);
  if (*head == NULL) {
    *head = new_head;
    return;
  }
  // pointer rearrangement
  new_head->prev = NULL;
  new_head->next = *head;
  (*head)->prev = new_head;
  *head = new_head;
}

void push_last(dnode_t **head, int data) {
  dnode_t* new_tail = init_node(data);
  if (*head == NULL) { // if nothing in list
    *head = new_tail;
    return;
  }
  dnode_t* temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_tail;
  new_tail->prev = temp;
  return;
}

int peek_first(dnode_t *list) {
  if (list == NULL) {
    fprintf(stderr, "Cannot peek first, list is NULL! ");
    exit(EXIT_FAILURE);
  }
  return list->data;
}

int peek_last(dnode_t *list) {
  if (list == NULL) {
    fprintf(stderr, "Cannot peek last, list is NULL! ");
    exit(EXIT_FAILURE);
  }
  dnode_t* temp = list;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  return temp->data;
}

int peek_at(dnode_t* list, int index) {
  dnode_t* temp = list;
  int data = -1;
  if (list == NULL) {
    fprintf(stderr, "List is empty, deletion is not possible");
    exit(EXIT_FAILURE);
  }
  if (index == 0) {
    return peek_first(list);
  }
  for (int i = 0; i < index; i++) {
    if (temp->next == NULL) {
      return -1;
    }
    temp = temp->next;
  }
  if (temp->next == NULL) { // if index is larger than ll
    return -1;
  }
  data = temp->data;
  return data;
}

int remove_first(dnode_t **head) {
  dnode_t* next_node = NULL;
  int data = -1;
  if ((*head) == NULL) {
    fprintf(stderr, "Cannot remove first, list is NULL! ");
    exit(EXIT_FAILURE);
  }
  
  if ((*head)->next == NULL) {  // if there is only one node
    data = (*head)->data;
    free(*head);
    return data;
  }
  next_node = *head;
  data = (*head)->data;
  *head = (*head)->next;
  (*head)->prev = NULL;
  free(next_node);
  return data;
}

int remove_last(dnode_t *list) {
  int data = -1;
  if (list == NULL) {
    fprintf(stderr, "Cannot remove last, list is NULL! ");
    exit(EXIT_FAILURE);
  }
  if (list->next == NULL) {
    data = list->data;
    free(list);
    return data;
  }
  dnode_t* temp = list;
  while (temp->next != NULL) {
    
  }
}

int remove_at(dnode_t **list, int index) {
  dnode_t* current = *list;
  dnode_t* temp = NULL;
  int data = -1;
  if (list == NULL) {
    fprintf(stderr, "List is empty, deletion is not possible");
    exit(EXIT_FAILURE);
  }
  if (index == 0) {
    return remove_first(list);
  }
  for (int i = 0; i < index - 1; i++) {
    if (current->next == NULL) {
      return -1;
    }
    current = current->next;
  }
  if (current->next == NULL) {
    return -1;
  }
  temp = current->next;
  data = temp->data;
  current->next = temp->next;
  temp->next->prev = current;
  free(temp);
  return data;
}

void remove_value(dnode_t **list, int data) {
  dnode_t* temp = *list, *current;
  if (temp != NULL && temp->data == data) {
    *list = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->data != data) {
    current = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    return;
  }

  current->next = temp->next;
  if (current->next == NULL) {
    return;
  }
    temp->next->prev = current;
  free(temp);
}

bool contains(dnode_t *list, int data) {
  if (list == NULL) {
    return false;
  }
  dnode_t* temp = list;
  while (temp != NULL){
    if (temp->data == data) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}