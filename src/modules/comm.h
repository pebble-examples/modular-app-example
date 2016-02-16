#pragma once

#include <pebble.h>

typedef void(CommJSReadyCallback)(void);

void comm_init();

void comm_deinit();
