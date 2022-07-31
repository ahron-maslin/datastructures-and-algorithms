#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
Hash Table:

Operation 	Average		Worst
_____________________________________
Insertion:	O(1)  	  O(n)
Removal:		O(1)  	  O(n)
Search:		  O(1)  	  O(n)

this implementation uses seperate chaining
(others are open addressing...)
*/


typedef struct KEY_VALUE_NODE kv_node_t;
typedef struct HASH_TABLE hash_table_t;

hash_table_t* ht_init(int size);

void ht_destroy(hash_table_t* ht);

int ht_size(hash_table_t* ht);

void ht_insert(hash_table_t* ht, char* key, char* value);

void ht_remove(hash_table_t* ht, char* key);

bool ht_contains(hash_table_t* ht, char* key);

char* ht_get(hash_table_t* ht, char* key);

void ll_print_helper(hash_table_t* ht, unsigned int index);

#endif