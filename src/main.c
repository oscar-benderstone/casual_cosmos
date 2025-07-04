#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_oldnames.h>

enum App_Status { APP_SUCCESS = 0, APP_FAILURE = 1, APP_CONTINUE };

int main(int argc, char *argv[]) {
  static enum App_Status app_status = APP_CONTINUE;

  if (!(SDL_Init(SDL_INIT_VIDEO))) {
    app_status = APP_FAILURE;
  }

  SDL_Log("Hello, Casual Cosmos!");

  if (app_status) {
    app_status = APP_SUCCESS;
  }

  SDL_Quit();

  return app_status;
}
