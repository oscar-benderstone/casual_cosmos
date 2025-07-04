// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "core.h"
#include "config.h"
#include <SDL3/SDL_init.h>

static inline bool init_core(const struct App_Core *core) {
  return (SDL_Init(app_sdl_init_flags));
}

static inline void quit_core(const struct App_Core *core) { SDL_Quit(); }

static inline bool new_window(struct App_Core *core) {
  return (core->window = SDL_CreateWindow(app_title, app_window_width,
                                          app_window_height, app_window_flags));
}

static inline void del_window(struct App_Core *core) {
  SDL_DestroyWindow(core->window);
}

static inline bool new_renderer(struct App_Core *core) {
  return (core->window = SDL_CreateWindow(app_title, app_window_width,
                                          app_window_height, app_window_flags));
}

static void del_renderer(struct App_Core *core) {
  SDL_DestroyWindow(core->window);
}

// TODO: use manager iteration idiom here
bool new_core(struct App_Core *core) {
  if (!(init_core(core))) {
    return false;
  };
  if (!new_window(core)) {
    return false;
  };
  return new_renderer(core);
}

void del_core(struct App_Core *core) {
  del_renderer(core);
  del_window(core);
  quit_core(core);
}
