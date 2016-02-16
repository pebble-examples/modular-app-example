#include "main_window.h"

static Window *s_window;

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
}

static void window_unload(Window *window) {
  window_destroy(s_window);
}

void main_window_push() {
  if(!s_window) {
    s_window = window_create();
    window_set_background_color(s_window, PBL_IF_COLOR_ELSE(GColorRed, GColorBlack));
    window_set_window_handlers(s_window, (WindowHandlers) {
      .load = window_load,
      .unload = window_unload,
    });
  }
  window_stack_push(s_window, true);
}

void main_window_set_background_color(GColor new_color) {
  window_set_background_color(s_window, new_color);
}
