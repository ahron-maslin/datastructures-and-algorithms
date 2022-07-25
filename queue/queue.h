#ifndef QUEUE_H
#define QUEUE_H 

#ifndef DATATYPE
#define DATATYPE int
#endif

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


/*
Queue

Enqueue:     O(1)
Dequeue:     O(1)
Peeking:     O(1)
Contains:    O(n)
Removal:     O(n)
Is Empty:    O(1)
*/
typedef struct LL_NODE {
  DATATYPE data;
  struct LL_NODE* next;
} node_t;


typedef struct QUEUE {
  node_t* head;
  node_t* tail;
  int size;
  
} queue_t;

queue_t* init_queue();

void destroy(queue_t* queue);

bool is_empty(queue_t* queue);

int size(queue_t* queue);

void enqueue(queue_t* queue, DATATYPE data);
DATATYPE dequeue(queue_t* queue);

DATATYPE peek(queue_t* queue);

#endif