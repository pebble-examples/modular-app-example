#pragma once          // Prevent errors from being included multiple times
  
#include <pebble.h>   // Pebble SDK symbols

void data_init(int array_length);

void data_deinit();

void data_set_array_value(int index, int new_value);

int data_get_array_value(int index);
