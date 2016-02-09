#include "main_window.h"

#define TIMER_INTERVAL 1000

static Window *s_window;

static void timer_handler(void *context) {
  if(comm_is_js_ready()) {
    // JS is ready!
    window_set_background_color(s_window, PBL_IF_COLOR_ELSE(GColorGreen, GColorWhite));
  } else {
    // Try again later
    app_timer_register(TIMER_INTERVAL, timer_handler, NULL);
  }
}

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

  // Wait for JS to be ready
  app_timer_register(TIMER_INTERVAL, timer_handler, NULL);
}
