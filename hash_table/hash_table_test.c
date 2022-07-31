#include "hash_table.h"
#include <assert.h>
#include <time.h>


#define HTSIZE 15

 char* keylist[] = {
    "tree",
    "lol",
    "pop",
    "green",
    "fred",
    "lukewarm",
    "llike"
  };

  char* valuelist[] = {
    "val1",
    "val2",
    "cal3",
    "asdg",
    "fredasdg",
    "asdgasdr",
    "werywer"
  };



int main() {

  hash_table_t* ht = ht_init(HTSIZE);

  assert(ht_size(ht) == HTSIZE);

  for (int i = 0; i < 7; i++) {
    ht_insert(ht, keylist[i], valuelist[i]);
  }
  ht_insert(ht, "test", "valuetest");
  ht_insert(ht, "test", "valuetest");

  ht_insert(ht, "yeet", "popopop");

  assert(ht_contains(ht, "yeet"));

  ht_remove(ht, "yeet");
  
  assert(!ht_contains(ht, "yeet"));

  ht_insert(ht, "asdf", "yellow");

  assert(strcmp(ht_get(ht, "asdf"), "yellow") == 0);

  #ifdef DEBUG
  for (int i = 0; i < ht_size(ht); i++) {
      printf("HT at index %3d >>> ", i);
      ll_print_helper(ht, i);
      printf("\n");
  }
 #endif

  ht_destroy(ht);
  printf("All tests pass!\n");
  return 0;
}