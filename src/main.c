// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#include "app.h"
#include <SDL3/SDL_init.h>

int main(int argc, char *argv[]) {
  static enum App_Status app_status = APP_CONTINUE;
  static struct App app = {0};

  if (!(SDL_Init(SDL_INIT_VIDEO))) {
    app_status = APP_FAILURE;
  }

  if (app_status) {
    app_status = APP_SUCCESS;
  }

  SDL_Quit();

  return app_status;
}
