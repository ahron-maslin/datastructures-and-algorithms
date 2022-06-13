#include "dynamic_array.h"

static void double_capacity(dynamic_array_t* array){
  int new_cap = array->capacity * 2;
  int *new_items = (int *)malloc(sizeof(int) * new_cap);

  for (int i = 0; i < array->size; i++){
    new_items[i] = array->array[i];
  }

  free(array->array);
  array->array = new_items;
  array->capacity = new_cap;
}

static void half_capacity(dynamic_array_t* array){
  int new_cap = array->capacity / 2;
  int *new_items = (int *)malloc(sizeof(int) * new_cap);

  for (int i = 0; i < min(array->size, new_cap); i++){
    new_items[i] = array->array[i];
  }

  free(array->array);
  array->array = new_items;
  array->capacity = new_cap;
  array->size = min(array->size, new_cap);
}

dynamic_array_t* array_init(int capacity) {
  if (capacity <= 0) {
    fprintf(stderr, "Array cannot have a capacity less than zero!");
    exit(EXIT_FAILURE);
  }
  dynamic_array_t *array = (dynamic_array_t*)malloc(sizeof(struct DYNAMIC_ARRAY));
  if (array == NULL){
    fprintf(stderr, "Not enough memory!");
    exit(EXIT_FAILURE);
  }
  array->size = 0;
  array->capacity = capacity;
  array->array = (int*)malloc(sizeof(int) * array->capacity);

  return array;
}

int size(dynamic_array_t *array){
  return array->size;
}

bool is_empty(dynamic_array_t *array){
  return array->size == 0;
}

int get(dynamic_array_t *array, int index){
  if (index >= array->size || index < 0){
    fprintf(stderr, "Out of index!");
    exit(EXIT_FAILURE);
  }
  return array->array[index]; 
}

void set(dynamic_array_t *array, int index, int data){
  if (index >= array->size || index < 0){
    fprintf(stderr, "Out of index!");
    exit(EXIT_FAILURE);
  }
  array->array[index] = data; 
}

void destroy(dynamic_array_t *array){
  free(array->array);
  free(array);
}

void insert(dynamic_array_t* array, int data){
  if (array->size >= array->capacity){
    double_capacity(array);
  }
  array->array[array->size++] = data;
}

void insert_at(dynamic_array_t *array, int index, int data){
  if (index >= array->size || index < 0){
    fprintf(stderr, "Out of index!");
    exit(EXIT_FAILURE);
  }

  if (array->size >= array->capacity){
    double_capacity(array);
  }

  for (int i = array->size; i > index; i--){
    array->array[i] = array->array[i - 1];
  }
  array->array[index] = data;
  array->size++;
}

int remove_at(dynamic_array_t* array, int index){
  if (index >= array->size || index < 0){
    return -1;
  }
  int data = array->array[index];
  for (int i = index; i < array->size - 1; i++){
    array->array[i] = array->array[i + 1];
  }
  array->size--;

  if (array->size * 4 < array->capacity) {
    half_capacity(array);
  }
  return data;
}

void remove_element(dynamic_array_t* array, int data){
  int index = index_of(array, data);
  if (index >= array->size || index < 0)
  {
    return;
  }
  for (int i = index; i < array->size - 1; i++){
    array->array[i] = array->array[i + 1];
  }
  array->size--;
  if (array->size * 4 < array->capacity) {
    half_capacity(array);
  }
}

int index_of(dynamic_array_t *array, int data){
  for (int i = 0; i < array->size; i++){
    if (array->array[i] == data){
      return i;
    }
  }
  return -1;
}

bool contains(dynamic_array_t *array, int data){
  return index_of(array, data) != -1;
}