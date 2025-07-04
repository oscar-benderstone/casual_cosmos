#ifndef APP_CORE
#define APP_CORE

#include <SDL3/SDL_render.h>

struct App_Core {
  SDL_Window *window;
  SDL_Renderer *renderer;
};

#endif
