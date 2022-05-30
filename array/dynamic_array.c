#include "dynamic_array.h"

static void double_capacity(dynamic_array_t* array){
  int new_cap = array->capacity * 2;
  int *new_items = (int *)malloc(sizeof(int) * new_cap);

  for (int i = 0; i < array->size; i++){
    new_items[i] = array->items[i];
  }

  free(array->items);
  array->items = new_items;
  array->capacity = new_cap;
}

static void half_capacity(dynamic_array_t* array){
  int new_cap = array->capacity / 2;
  int *new_items = (int *)malloc(sizeof(int) * new_cap);

  for (int i = 0; i < min(array->size, new_cap); i++){
    new_items[i] = array->items[i];
  }

  free(array->items);
  array->items = new_items;
  array->capacity = new_cap;
  array->size = min(array->size, new_cap);
}

dynamic_array_t* array_init(int capacity){
  dynamic_array_t *array = (dynamic_array_t*) malloc(sizeof(struct DYNAMIC_ARRAY));
  if (array == NULL){
    fprintf(stderr, "Not enough memory!");
    exit(EXIT_FAILURE);
  }
  array->size = 0;
  array->capacity = capacity;
  array->items = (int*)malloc(sizeof(int) * array->capacity);

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
  return array->items[index]; 
}

void set(dynamic_array_t *array, int index, int item){
  if (index >= array->size || index < 0){
    fprintf(stderr, "Out of index!");
    exit(EXIT_FAILURE);
  }
  array->items[index] = item; 
}

void destroy(dynamic_array_t *array){
  free(array->items);
  free(array);
}

void add(dynamic_array_t* array, int item){
  if (array->size >= array->capacity){
    double_capacity(array);
  }
  array->items[array->size++] = item;
}

void insert_at(dynamic_array_t *array, int index, int item){
  if (index >= array->size || index < 0){
    fprintf(stderr, "Out of index!");
    exit(EXIT_FAILURE);
  }

  if (array->size >= array->capacity){
    double_capacity(array);
  }

  for (int i = array->size; i > index; i--){
    array->items[i] = array->items[i - 1];
  }
  array->items[index] = item;
  array->size++;
}

int remove_at(dynamic_array_t* array, int index){
  if (index >= array->size || index < 0){
    return -1;
  }
  int data = array->items[index];
  for (int i = index; i < array->size - 1; i++){
    array->items[i] = array->items[i + 1];
  }
  array->size--;

  if (array->size * 4 < array->capacity) {
    half_capacity(array);
  }
  return data;
}

void remove_element(dynamic_array_t* array, int item){
  int index = index_of(array, item);
  if (index >= array->size || index < 0)
  {
    return;
  }
  for (int i = index; i < array->size - 1; i++){
    array->items[i] = array->items[i + 1];
  }
  array->size--;
  if (array->size * 4 < array->capacity) {
    half_capacity(array);
  }
}

int index_of(dynamic_array_t *array, int item){
  for (int i = 0; i < array->size; i++){
    if (array->items[i] == item){
      return i;
    }
  }
  return -1;
}

bool contains(dynamic_array_t *array, int item){
  return index_of(array, item) != -1;
}