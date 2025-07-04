#ifndef APP
#define APP

#include "core.h"

enum App_Status { APP_SUCCESS = 0, APP_FAILURE = 1, APP_CONTINUE };

// Separate out App into separate stages,
// making management modular, easier,
// and less error-prone
struct App {
  struct App_Core core;
};

#endif
