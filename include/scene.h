// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef APP_SCENE
#define APP_SCENE

#include "app.h"

enum App_Scene { APP_LOADING, APP_MAIN_MENU, APP_SETTINGS, APP_LEVEL };

struct Scene {
  enum App_Scene (*input)(struct App *app, enum App_Scene current_scene);
  void (*update)(struct App *app);
  void (*view)(struct App *app);
};

#endif
