#include "queue.h"

static node_t* init_node(int data) {
  node_t* node = malloc(sizeof(struct LL_NODE));
  node->data = data;
  node->next = NULL;

  return node;
}

queue_t* init_queue() {
  queue_t* queue = malloc(sizeof(struct QUEUE));
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;

  return queue;
}

void destroy(queue_t* queue) {
  while (queue->head != NULL) {
    node_t* temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
  }
  queue->tail = NULL;
  queue->size = 0;
  free(queue);
}

bool is_empty(queue_t* queue) {
  return size(queue) == 0;
}

int size(queue_t* queue) {
  return queue->size;
}

void enqueue(queue_t* queue, int data) {
  node_t* node = init_node(data);

  if (queue->head == NULL) {
    queue->head = queue->tail = node;
  }
  else { 
    queue->tail->next = node;
    queue->tail = node;
  }
  queue->size++;
}

int dequeue(queue_t* queue) {
  if (queue->head == NULL) {
    fprintf(stderr, "Cannot dequeue - queue is NULL\n");
    exit(EXIT_FAILURE); 
  }
  node_t* node = queue->head;

  if (queue->head == queue->tail) {
    queue->tail = NULL;
    queue->head = NULL;
  }
  else {
    queue->head = queue->head->next;
  }
  
  queue->size--;
  int data = node->data;
  free(node);
  return data;
}

int peek(queue_t* queue) {
  if (queue->head == NULL) {
    fprintf(stderr, "Cannot peek - queue is NULL\n");
    exit(EXIT_FAILURE);
  }
  return queue->head->data;
}
