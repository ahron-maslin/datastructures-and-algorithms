#include "dynamic_array.h"
#include <assert.h>


int main(){
    /*
  - init_array.is_empty == true
  - adding {size/capacity}
  - getting values
  - getting values with wrong index
  - setting values
  - setting values with wrong index
  - inserting values
  - inserting values with wrong index
  - remove values
  - removing values with wrong index
  - index_of valid value
  - index_of invalid value
  - contains value / invalid value
  - removing - valid size
  - double capacity
  */

  dynamic_array_t* arr = array_init(9);

  assert(is_empty(arr));
  assert(arr->capacity == 9);

  for (int i = 1; i < 10; i++) {
    insert(arr, i);
  }

  assert(size(arr) == 9);
  assert(get(arr, 2) == 3);
  
  set(arr, 4, 55);
  
  assert(get(arr, 4) == 55);
  assert(remove_at(arr, 5) == 6);
  assert(size(arr) == 8);
  
  remove_element(arr, 8);
  
  assert(size(arr) == 7);
  assert(arr->capacity == 9);

  assert(index_of(arr, 4) == 3);
  assert(index_of(arr, -10) == -1);

  assert(contains(arr, 3));
  assert(!contains(arr, 300));

  insert(arr, 10);
  insert(arr, 11);
  insert(arr, 12);

  assert(arr->capacity == 18);
  assert(size(arr) == 10);

  destroy(arr);

  printf("All tests pass!\n");

  return 0;
}