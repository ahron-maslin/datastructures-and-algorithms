#ifndef _DOUBLY_LINKED_LIST_H
#define _DOUBLY_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
Doubly Linked List

Search:           O(n)
Insert at head:   O(1)
Insert at tail:   O(1)
Remove at head:   O(1)
Remove at tail:   O(1)
Remove in middle: O(n)
*/

typedef struct DOUBLY_LINKED_LIST
{
  int data;
  struct DOUBLY_LINKED_LIST *next;
  struct DOUBLY_LINKED_LIST *prev;
} dnode_t;

void destroy(dnode_t *list);

void push(dnode_t **head, int data);
void push_last(dnode_t **head, int data);

int peek_first(dnode_t *list);
int peek_last(dnode_t *list);
int peek_at(dnode_t* list, int index);

int remove_first(dnode_t **head);
int remove_last(dnode_t *list);

int remove_at(dnode_t **list, int index);
void remove_value(dnode_t **list, int data);

bool contains(dnode_t *list, int data);

#endif