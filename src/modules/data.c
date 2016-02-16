#include "data.h"

static int* s_array;

void data_init(int array_length) {
  if(!s_array) {
    s_array = (int*)malloc(array_length * sizeof(int));
  }
}

void data_deinit() {
  if(s_array) {
    free(s_array);
    s_array = NULL;
  }
}

void data_set_array_value(int index, int new_value) {
  s_array[index] = new_value;
}

int data_get_array_value(int index) {
  return s_array[index];
}
