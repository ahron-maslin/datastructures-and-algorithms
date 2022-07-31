#include <string.h>
#include "hash_table.h"
#include "../linked_list/linked_list.h"



typedef struct KEY_VALUE_NODE {
  char* key;
  char* value;
  int hash;
} kv_node_t;

typedef struct HASH_TABLE {
  node_t** arr;
  int size;
  int count;
} hash_table_t;


// helper function to print out ll contents 
void ll_print_helper(hash_table_t* ht, unsigned int index) {
  node_t* trav = ht->arr[index];
  while (trav != NULL)
  {
    kv_node_t* node = node_data(trav);
    printf("[%s : %s] ", node->key, node->value);
    trav = get_next_node(trav);
  }
  return;
}


static bool key_cmp(void* data1, void* data2) {
  return strcmp(((kv_node_t*)data1)->key, data2) == 0;
}


static int hashify(hash_table_t* ht, char* key) {
  int index = 0;
  for (int i = 0; key[i]; i++) {
    index = index + key[i];
  }
  return index % ht->size;
}


static kv_node_t* kv_init(char* key, char* value) {
  kv_node_t* node = malloc(sizeof(struct KEY_VALUE_NODE));
  node->key = malloc(strlen(key) + 1);
  node->value = malloc(strlen(value) + 1);
  strcpy(node->key, key);
  strcpy(node->value, value);
  return node;
}


hash_table_t* ht_init(int size) {
  hash_table_t* ht = malloc(sizeof(struct HASH_TABLE));
  ht->arr = malloc(sizeof(node_t*) * size);
  for (int i = 0; i < size; i++) { // is this needed?
    ht->arr[i] = NULL;
  }
  ht->size = size;
  ht->count = 0;
  return ht;
}

void kv_node_destroy(kv_node_t* node) {
  free(node->key);
  free(node->value);
  free(node);
  return;
}

// if count is double size, rehash everything (easier with open addressing)

void ht_destroy(hash_table_t* ht) {
  for (int i = 0; i < ht->size; i++) {
    if (ht->arr[i] != NULL) {
      destroy(ht->arr[i], &kv_node_destroy);
    }
  }
  free(ht->arr);
  free(ht);
}


int ht_size(hash_table_t* ht) {
  return ht->size;
}


void ht_insert(hash_table_t* ht, char* key, char* value) {
  if (!ht_contains(ht, key)) {
    kv_node_t* node = kv_init(key, value);
    int index = hashify(ht, key);
    node->hash = index;
    push_last(&ht->arr[index], node);
    ht->count++;
  }
}


void ht_remove(hash_table_t* ht, char* key) {
  int index = hashify(ht, key);
  if (ht->arr[index] != NULL) {
    remove_value(&ht->arr[index], key, key_cmp);
    ht->count--;
  }
}


bool ht_contains(hash_table_t* ht, char* key) {
  int index = hashify(ht, key);
  return contains(ht->arr[index], key, key_cmp);
}


char* ht_get(hash_table_t* ht, char* key) {
  if (ht_contains(ht, key)) {
    node_t* node = ht->arr[hashify(ht, key)];
    kv_node_t* kv_node = node_data(node);
    if (strcmp(kv_node->key, key) == 0) {
      return kv_node->value;
    }
    else { // if the first entry of the ll does not contain our key
      node = get_next_node(node);
      while (node) {
        kv_node = node_data(node);
        if (strcmp(kv_node->key, key) == 0) {
          return kv_node->value;
        }
        node = get_next_node(node);
      }
      return "no...";
    }
  }
  else {
    return "key does not exist!";
  }

}
