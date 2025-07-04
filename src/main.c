// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#include "app.h"
#include "core.h"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>

// Key structure that holds
// constructors and destructors.
// Can be used in a struct;
// see more in main
struct Manager {
  bool (*new)(struct App *app);
  void (*del)(struct App *app);
};

// Thin wrappers around constructors
// and destructors. Explained more in main.
// TODO: figure out if there is a nice way to include
// these in core.h.
// Main problem: circular reference!
// TODO: maybe add enum App_Status to new instead of using bool?
bool app_new_core(struct App *app) { return new_core(&app->core); };
void app_del_core(struct App *app) { del_core(&app->core); };

int main(int argc, char *argv[]) {
  static enum App_Status app_status = APP_CONTINUE;
  static struct App app = {0};

  // We declaratively list constructors/destructors,
  // and can manage them in one place!
  // In some compilers (i.e., clang), this can be inlined (at -O2)!
  // TODO: discuss limitations and workarounds
  static struct Manager managers[] = {
      {.new = app_new_core, .del = app_del_core}};

  for (int i = 0; i < sizeof(managers) / sizeof(managers[0]); i++) {
    if (!(app_status = managers[i].new(&app))) {
      SDL_LogError(SDL_LOG_CATEGORY_ERROR, "error while initing SDL: %s",
                   SDL_GetError());
      break;
    };
  }

  if (app_status) {
    SDL_Log("Hello, Casual Cosmos!");
  }

  for (int i = sizeof(managers) / sizeof(managers[0]) - 1; i >= 0; i--) {
    managers[i].del(&app);
  }

  return app_status;
}
