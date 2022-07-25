#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../queue/queue.h"


/*
 Binary Search Tree:

Operation 	Average		Worst
_____________________________________
Insert:		O(log(n))	  O(n)
Remove:		O(log(n))	  O(n)
Search:		O(log(n))	  O(n)

This is an implementation for a binary <i>search</i> tree,
not necessarily a binary tree
 */

typedef struct BINARY_TREE_NODE {
  int data;
  struct BINARY_TREE_NODE *left;
  struct BINARY_TREE_NODE *right;
} binary_tree_node_t;


binary_tree_node_t* new_node(int data);

void destroy_bst(binary_tree_node_t* bst);

void insert(binary_tree_node_t** nodeptr, int data);

void delete_node(binary_tree_node_t** node, int data);

bool search(binary_tree_node_t* root, int data);

void preorder_trav(binary_tree_node_t* root);
void inorder_trav(binary_tree_node_t* root);
void postorder_trav(binary_tree_node_t* root);

void bfs_trav(binary_tree_node_t* root);

void trav(binary_tree_node_t* bst, void (*fp)(binary_tree_node_t* bst));

#endif
