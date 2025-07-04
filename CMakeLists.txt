# Adapted from:
# sdl3-sample
# https://github.com/Ravbug/sdl3-sample
cmake_minimum_required(VERSION 3.16)

project(casual_cosmos C)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(SetupPlatform)
include(GetSDL)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_sources(${EXECUTABLE_NAME}
  PRIVATE
    src/scene.c
    src/core.c
    src/run.c
    src/main.c
)

