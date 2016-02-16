#include "comm.h"

typedef enum {
  AppKeyJSReady = 0,
} AppKey;

static CommJSReadyCallback *s_callback;

static void inbox_recieved_handler(DictionaryIterator *iter, void *context) {
  Tuple *js_ready_t = dict_find(iter, AppKeyJSReady);
  if(js_ready_t) {
    s_callback();
  }
}

void comm_init(CommJSReadyCallback *callback) {
  s_callback = callback;
  app_message_register_inbox_received(inbox_recieved_handler);

  const int inbox_size = 64;
  const int outbox_size = 64;
  app_message_open(inbox_size, outbox_size);
}

void comm_deinit() { 
  // Nothing yet
}
