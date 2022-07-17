#include "binary_search_tree.h"

static binary_tree_node_t* find_min(binary_tree_node_t* root) {
  binary_tree_node_t* temp = root;
  while (temp && temp->left != NULL) {
    temp = temp->left;
  }
  return temp;
}


static binary_tree_node_t* remove_node(binary_tree_node_t* node, int data) {
  binary_tree_node_t* temp = NULL;

  if (node == NULL) {
    return node;
  }

  // dig until we find the node we want to remove
  if (node->data > data) {
    node->left = remove_node(node->left, data);
  }
  else if (node->data < data) {
    node->right = remove_node(node->right, data);
  }
  else { // we found the node to remove
    if (node->left == NULL) {
      temp = node->right;
      free(node);
      return temp;
    }
    else if (node->right == NULL) {
      temp = node->left;
      free(node);
      return temp;
    } // if two children exist
    temp = find_min(node->right);
    node->data = temp->data;
    node->right = remove_node(node->right, temp->data);
  }
  return node;
}



binary_tree_node_t* new_node(int data) {
  binary_tree_node_t* root = malloc(sizeof(struct BINARY_TREE_NODE));
  root->data = data;
  root->left = NULL;
  root->right = NULL;
  return root;
}


void destroy_bst(binary_tree_node_t* root) {
  // recursively free() nodes
  // using postorder transversal (DFS)
  if (root != NULL) {
    destroy_bst(root->left);
    destroy_bst(root->right);
    free(root);
    root->left == NULL;
    root->right == NULL;
  }
}


void insert(binary_tree_node_t** nodeptr, int data) {
  binary_tree_node_t* node = *nodeptr;
  if (!search(node, data)) {

    if (node == NULL) {
      // if leaf node
      (*nodeptr) = new_node(data);
      return;
    }
    // else, recursively find proper leaf node per BST rules
    if (data < node->data) {
      return insert(&(node->left), data);
    }
    else {
      return insert(&(node->right), data);
    }
  }
}


bool search(binary_tree_node_t* root, int data) {
  binary_tree_node_t* current = root; // trav node
  if (current == NULL) { // if we've reached node, than data is not in the tree
    return false;
  }
  if (current->data > data) {
    return search(current->left, data);
  }
  else if (current->data < data) {
    return search(current->right, data);
  }
  else {
    return true;
  }
}

void delete_node(binary_tree_node_t** tree, int data) {
  // wrapper for remove_node 
  // calling it with a double pointer
  // prevents the option from fixing up parent 
  // by freeing child pointers
  *tree = remove_node(*tree, data);
  return;
}

void trav(binary_tree_node_t* bst, void (*fp)(binary_tree_node_t*)) {
  return fp(bst);
}


void preorder_trav(binary_tree_node_t* root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder_trav(root->left);
    preorder_trav(root->right);
  }
}

void inorder_trav(binary_tree_node_t* root) {
  if (root != NULL) {
    inorder_trav(root->left);
    printf("%d ", root->data);
    inorder_trav(root->right);
  }
}


void postorder_trav(binary_tree_node_t* root) {
  if (root != NULL) {
    postorder_trav(root->left);
    postorder_trav(root->right);
    printf("%d ", root->data);
  }
}

void bfs_trav(binary_tree_node_t* root) {
  queue_t* queue = init_queue();
  binary_tree_node_t* temp = root;
  
  enqueue(queue, root);
  while (!is_empty(queue)) {
    temp = dequeue(queue);
    printf("%d ", temp->data);
    if (temp->left) {
      enqueue(queue, temp->left);
    }
    if (temp->right) {
      enqueue(queue, temp->right);
    }
  }
  destroy(queue);
  return;
}