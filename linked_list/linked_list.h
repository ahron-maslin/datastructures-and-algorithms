#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
Singly Linked List

Search:           O(n)
Insert at head:   O(1)
Insert at tail:   O(1)
Remove at head:   O(1)
Remove at tail:   O(n)
Remove in middle: O(n)
*/

typedef struct LINKED_LIST node_t;


void destroy(node_t *node, void (*data_destroy_fp)());

void push(node_t **head, void* data);
void push_last(node_t **head, void* data);

void* peek_first(node_t *list);
void* peek_last(node_t *list);
void* peek_at(node_t* list, int index);

void* remove_first(node_t **head);
void* remove_last(node_t *list);

void* remove_at(node_t **list, int index);
void remove_value(node_t **list, void* data2, bool(*cmp)(void* data1, void* data2));

bool contains(node_t *list, void* data2, bool (*comparator)(void* data1, void* data2));

node_t* get_next_node(node_t* list);

void* node_data(node_t* node);  
#endif