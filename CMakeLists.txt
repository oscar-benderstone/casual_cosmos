# Adapted from:
# sdl3-sample
# https://github.com/Ravbug/sdl3-sample
cmake_minimum_required(VERSION 3.16)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(SetupPlatform)
include(GetSDL)

project(casual_cosmos C)

SETUP_PLATFORM()
GET_SDL()

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_sources(${EXECUTABLE_NAME}
  PRIVATE
    src/main.c
)

