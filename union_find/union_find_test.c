#include "union_find.h"
#include <assert.h>
#include <time.h>


int main() {
  union_find_t* uf = init_union(11);

  assert(componentSize(uf, 7) == 1);
 
  unify(uf, 1, 0);
  unify(uf, 1, 2);
  unify(uf, 3, 4);
  unify(uf, 5, 6);
  unify(uf, 7, 8);
  unify(uf, 9, 10);

  assert(find(uf, 2) == 1);
  assert(find(uf, 4) == 3);
  assert(find(uf, 6) == 5);
  assert(find(uf, 8) == 7);
  assert(find(uf, 10) == 9);

  assert(componentSize(uf, 8) == 2);
  assert(componentSize(uf, 7) == 2);

  assert(connected(uf, 2, 1));
  assert(!connected(uf, 3, 1));

  unify(uf, 3, 10);

  assert(find(uf, 10) == 3);
  assert(componentSize(uf, 10) == 4);
  assert(connected(uf, 9, 4));

  unify(uf, 8, 2);

  destroy(uf);


  printf("All tests pass!\n");
  return 0;
}