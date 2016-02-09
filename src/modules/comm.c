#include "comm.h"

typedef enum {
  AppKeyJSReady = 0,
} AppKey;

static bool s_js_ready;

static void inbox_recieved_handler(DictionaryIterator *iter, void *context) {
  Tuple *js_ready_t = dict_find(iter, AppKeyJSReady);
  if(js_ready_t) {
    // JS is ready!
    s_js_ready = true;
  }
}

void comm_init() {
  app_message_register_inbox_received(inbox_recieved_handler);

  const int inbox_size = 64;
  const int outbox_size = 64;
  app_message_open(inbox_size, outbox_size);
}

bool comm_is_js_ready() {
  return s_js_ready;
}
