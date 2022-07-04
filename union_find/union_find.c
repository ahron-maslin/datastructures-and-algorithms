#include "union_find.h"

union_find_t* init_union(int size) {
  union_find_t* uf = (union_find_t*)malloc(sizeof(struct UNION_FIND));
  uf->size = size;
  uf->arr = malloc(sizeof(int) * uf->size);
  if (uf->arr == NULL) {
    fprintf(stderr, "Cannot malloc union find!");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < uf->size; i++) {
    uf->arr[i] = -1;
  }
  return uf;
}


void destroy(union_find_t* uf) {
  free(uf->arr);
  free(uf);
}


//returns the root of a set
int find(union_find_t* uf, int i) {
  if (uf->arr[i] < 0) {
    return i;
  }
  else {
    uf->arr[i] = find(uf, uf->arr[i]);
    return uf->arr[i];
  }
}

bool connected(union_find_t* uf, int p, int q) {
  return find(uf, p) == find(uf, q);
}

int componentSize(union_find_t* uf, int p) {
  return (uf->arr[find(uf, p)])*-1;
}

void unify(union_find_t* uf, int p, int q) {
  if (connected(uf, p, q)) {
    return;
  }
  int root1 = find(uf, p);
  int root2 = find(uf, q);

  if (uf->arr[root2] < uf->arr[root1]) {
    uf->arr[root2] += uf->arr[root1];
    uf->arr[root1] = root2;
  }
  else {
    uf->arr[root1] += uf->arr[root2];
    uf->arr[root2] = root1;
  }
}