#include "linked_list.h"

typedef struct LINKED_LIST
{
  void* data;
  struct LINKED_LIST *next;
} node_t;

static node_t *init_node(void* data) {
  node_t *list = malloc(sizeof(struct LINKED_LIST));
  list->next = NULL;
  list->data = data;

  return list;
}

void destroy(node_t *node, void(*data_destroy_fp)()) {
  if (!node) {
    return;
  }
  if (data_destroy_fp) {
    data_destroy_fp(node->data);
  }
  destroy(node->next, data_destroy_fp);
  free(node);
  node = NULL;
}

void push(node_t **head, void* data) {
  node_t *new_head = init_node(data);
  if (*head == NULL) {
    *head = new_head;
    return;
  }
  new_head->next = *head;
  *head = new_head;
}

void push_last(node_t **head, void* data) {
  node_t* next = init_node(data);
  if (*head == NULL) {
    *head = next;
  }
  else {
    node_t *temp = *head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = next;
  }
}

void* peek_first(node_t *list) {
  return list->data;
}

void* peek_last(node_t *list) {
  node_t *trav = list;
  while (trav->next != NULL) {
    trav = trav->next;
  }
  return trav->data;
}

void* peek_at(node_t* list, int index) {
  node_t* temp = list;
  void* data;
  if (list == NULL) {
    fprintf(stderr, "Cannot peek, list is NULL! ");
    exit(EXIT_FAILURE);
  }
  if (index == 0) {
    return peek_first(list);
  }
  for (int i = 0; i < index; i++) {
    if (temp->next == NULL) {
      return NULL;
    }
    temp = temp->next;
  }
  if (temp->next == NULL) {
    return NULL;
  }
  data = temp->data;
  return data;
}

void* remove_first(node_t **head) {
  node_t *first_node = NULL;
  void* data;
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

void* remove_last(node_t *list) {
  if (list->next == NULL) {
    void* data = list->data;
    free(list);
    return data;
  }

  node_t* trav = list;
  while (trav->next->next != NULL) {
    trav = trav->next;
  }
  void* data = trav->next->data;
  free(trav->next);
  trav->next = NULL;
  return data;
}

void* remove_at(node_t **list, int index) {
  node_t *current = *list;
  node_t *temp = NULL;
  void* data;
  if (list == NULL)
  {
    fprintf(stderr, "List is empty, deletion is not possible");
    exit(EXIT_FAILURE);
  }
  if (index == 0) {
    return remove_first(list);
  }

  for (int i = 0; i < index - 1; i++) {
    if (current->next == NULL) {
      return NULL;
    }
    current = current->next;
  }

  if (current->next == NULL) {
    return NULL;
  }

  temp = current->next;
  data = temp->data;
  current->next = temp->next;
  free(temp);
  return data;
}

void remove_value(node_t **list, void* data2, bool(*cmp)(void* data1, void* data2)) {
  node_t *temp = *list, *prev;
  if (temp != NULL && cmp(temp->data, data2)) {
    *list = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && !cmp(temp->data, data2)) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL) {
    return;
  }

  prev->next = temp->next;
  free(temp);
}

bool contains(node_t *list, void* data2, bool (*comparator)(void* data1, void* data2)) {
  if (list == NULL) {
    return false;
  }
  node_t* temp = list;
  while (temp != NULL) {
    // we need to compare the structs that the data pointer points to
    // not the data pointer itself
    if (comparator(temp->data, data2)) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

int get_index(node_t* node, void* data) {
  node_t* trav = node;
  unsigned int i = 0;
  while (trav) {
    if (trav->data == data) {
      return i;
    }
    i++;
  }
}

node_t* get_next_node(node_t* list) {
  return list->next;
}


void* node_data(node_t* node) {
  return node->data;
}