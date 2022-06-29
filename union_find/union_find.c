#include "union_find.h"

union_find_t* init_union(int size) {
  union_find_t* uf = (union_find_t*)malloc(sizeof(struct UNION_FIND));
  uf->size = size;
  uf->arr = malloc(sizeof(int) * uf->size);
  uf->sz_arr = malloc(sizeof(int) * uf->size);
  if (uf->arr == NULL || uf->sz_arr == NULL) {
    fprintf(stderr, "Cannot malloc union find!");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < uf->size; i++) {
    uf->arr[i] = i;
    uf->sz_arr[i] = 1;
  }
  return uf;
}


void destroy(union_find_t* uf) {
  free(uf->arr);
  free(uf->sz_arr);
  free(uf);
}


//returns the root of a set
int find(union_find_t* uf, int i) {
  while (uf->arr[i] != i) {
    //path compression
    uf->arr[i] = uf->arr[uf->arr[i]];
    i = uf->arr[i];
  }
  return i;
}

bool connected(union_find_t* uf, int p, int q) {
  return find(uf, p) == find(uf, q);
}

int componentSize(union_find_t* uf, int p) {
  return uf->sz_arr[find(uf, p)];
}

void unify(union_find_t* uf, int p, int q) {
  if (connected(uf, p, q)) {
    return;
  }
  int root1 = find(uf, p);
  int root2 = find(uf, q);

  if (uf->sz_arr[root1] < uf->sz_arr[root2]) {
    uf->sz_arr[root2] += uf->sz_arr[root1];
    uf->arr[root1] = root2;
    uf->sz_arr[root1] = 0;
  }
  else {
    uf->sz_arr[root1] += uf->sz_arr[root2];
    uf->arr[root2] = root1;
    uf->sz_arr[root2] = 0;
  }
}