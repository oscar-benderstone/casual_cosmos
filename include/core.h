// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef APP_CORE
#define APP_CORE

#include <SDL3/SDL_render.h>

// Thin wrapper around key
// SDL objects.
// Used on entry (enter and exit),
// as well as general video tasks
struct App_Core {
  SDL_Window *window;
  SDL_Renderer *renderer;
};

// Constructor/Destructor for app.core
bool new_core(struct App_Core *core);
void del_core(struct App_Core *core);

#endif
