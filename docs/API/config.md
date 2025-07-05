# Config

These are the base settings
for the app.

**TODO**: maybe we can create
a simple script to convert
the corresponding TOML into
the C header?

``` {.c file=include/config.h}
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef APP_CONFIG
#define APP_CONFIG

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>

static const char app_title[] = "Casual Cosmos";
// TODO: determine this per platform
static const int app_window_width = 500;
static const int app_window_height = 500;
static const SDL_InitFlags app_sdl_init_flags = SDL_INIT_VIDEO;
static const SDL_WindowFlags app_window_flags = 0;
static const int test = 0;

#endif

```
