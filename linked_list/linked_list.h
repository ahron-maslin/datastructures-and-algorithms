#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
Singly Linked List

Search:           O(n)
Insert at head:   O(1)
Insert at tail:   O(1)
Remove at head:   O(1)
Remove at tail:   O(n)
Remove in middle: O(n)
*/

typedef struct LINKED_LIST
{
  int data;
  struct LINKED_LIST *next;
} node_t;

void destroy(node_t *list);

void push(node_t **head, int data);
void push_last(node_t **head, int data);

int peek_first(node_t *list);
int peek_last(node_t *list);
int peek_at(node_t* list, int index);

int remove_first(node_t **head);
int remove_last(node_t *list);

int remove_at(node_t **list, int index);
void remove_value(node_t **list, int data);

bool contains(node_t *list, int data);
#endif