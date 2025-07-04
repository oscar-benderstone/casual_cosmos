// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#include "run.h"
#include <SDL3/SDL_events.h>

bool app_run(struct App *app) {
  static bool running = true;
  SDL_Event event;

  // TODO: replace with scenes
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        running = false;
      }
    }

    SDL_SetRenderDrawColor(app->core.renderer, 18, 7, 52, 255);
    SDL_RenderClear(app->core.renderer);
    SDL_RenderPresent(app->core.renderer);
  }

  return APP_SUCCESS;
}
