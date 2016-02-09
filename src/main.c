#include <pebble.h>

#include "modules/comm.h"
#include "modules/data.h"
#include "windows/main_window.h"

static void init() {
  comm_init();

  const int array_size = 16;
  data_init(array_size);

  main_window_push();
}

static void deinit() {
  data_deinit();
}

int main() {
  init();
  app_event_loop();
  deinit();
}
