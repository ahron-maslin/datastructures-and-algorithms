#ifndef _UNION_FIND_H
#define _UNION_FIND_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Union Find

Construction:       O(n)
Union:              α(n)
Find:               α(n)
Get Component Size: α(n)
Check if connected: α(n)
Count Components:   O(1)

α(n) - Amortized constant time (worst case is very rare)
*/

typedef struct UNION_FIND {
  int* arr;
  int size;
} union_find_t;

union_find_t* init_union(int size);

void destroy(union_find_t* uf);

// Find which component/set 'p' belongs to, takes amortized constant time.
int find(union_find_t* uf, int p);

// Return whether or not the elements 'p' and
// 'q' are in the same components/set.
bool connected(union_find_t* uf, int p, int q);

// Return the size of the components/set 'p' belongs to
int componentSize(union_find_t* uf, int p);

//unify two elements in a set
void unify(union_find_t* uf, int p, int q);


#endif