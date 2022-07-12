#include "binary_search_tree.h"
#include <assert.h>


int main(int argc, char argv[]) {

  binary_tree_node_t* bst = NULL;
  insert(&bst, 50);
  insert(&bst, 25);
  insert(&bst, 100);
  insert(&bst, 20);
  insert(&bst, 30);
  insert(&bst, 75);
  insert(&bst, 125);

  assert(search(bst, 25));

  delete_node(&bst, 125);
  delete_node(&bst, 50);
  delete_node(&bst, 25);

  trav(bst, bfs_trav);
  trav(bst, inorder_trav);
  trav(bst, preorder_trav);
  trav(bst, postorder_trav);

  destroy_bst(bst);

  printf("All tests pass!\n");
  return 0;
}