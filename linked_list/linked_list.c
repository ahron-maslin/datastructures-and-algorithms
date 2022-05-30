#include "linked_list.h"

static node_t *init_node(int data){
  node_t *list = malloc(sizeof(struct LINKED_LIST));
  list->data = data;
  list->next = NULL;

  return list;
}

void destroy(node_t *list){
  if (!list){
    return;
  }
  destroy(list->next);
  free(list);
  list = NULL;
}

void push(node_t **head, int data){
  node_t *new_head = init_node(data);
  if (*head == NULL){
    *head = new_head;
    return;
  }
  new_head->next = *head;
  *head = new_head;
}

void push_last(node_t **head, int data){
    node_t* next = init_node(data);
    if (*head == NULL){
      *head = next;
    } else {
      node_t *temp = *head;
      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = next;
    }
}

int peek_first(node_t *list) {
  return list->data;
}

int peek_last(node_t *list){
  node_t *trav = list;
  while (trav->next != NULL){
    trav = trav->next;
  }
  return trav->data;
}

int peek_at(node_t* list, int index) {
  node_t* temp = list;
  int data = -1;
  if (list == NULL) {
    fprintf(stderr, "Cannot peek, list is NULL! ");
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
  if (temp->next == NULL) {
    return -1;
  }
  data = temp->data;
  return data;
}

int remove_first(node_t **head){
  node_t *first_node = NULL;
  int data = -1;
  if ((*head)->next == NULL)
  {
    data = (*head)->data;
    free(head);
    return data;
  }
  first_node = *head;
  data = (*head)->data;
  *head = (*head)->next;
  free(first_node);
  return data;
}

int remove_last(node_t *list){
  if (list->next == NULL){
    int data = list->data;
    free(list);
    return data;
  }

  node_t* trav = list;
  while (trav->next->next != NULL){
    trav = trav->next;
  }
  int data = trav->next->data;
  free(trav->next);
  trav->next = NULL;
  return data;
}

int remove_at(node_t **list, int index){
  node_t *current = *list;
  node_t *temp = NULL;
  int data = -1;
  if (list == NULL)
  {
    fprintf(stderr, "List is empty, deletion is not possible");
    exit(EXIT_FAILURE);
  }
  if (index == 0){
    return remove_first(list);
  }

  for (int i = 0; i < index - 1; i++){
    if (current->next == NULL){
      return -1;
    }
    current = current->next;
  }

  if (current->next == NULL){
    return -1;
  }

  temp = current->next;
  data = temp->data;
  current->next = temp->next;
  free(temp);
  return data;
}

void remove_value(node_t **list, int data){
  node_t *temp = *list, *prev;
  if (temp != NULL && temp->data == data){
    *list = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->data != data){
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL){
    return;
  }

  prev->next = temp->next;
  free(temp);
}

bool contains(node_t *list, int data) {
  if (list == NULL) {
    return false;
  }
  node_t* temp = list;
  while (temp != NULL) {
    if (temp->data == data) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}
