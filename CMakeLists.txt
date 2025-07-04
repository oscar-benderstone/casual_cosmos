# Adapted from:
# sdl3-sample
# https://github.com/Ravbug/sdl3-sample
cmake_minimum_required(VERSION 3.16)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(casual_cosmos C)

include(SetupPlatform)

SETUP_PLATFORM()

target_sources(${EXECUTABLE_NAME}
PRIVATE
  src/main.c
)

option(SDL_VENDORED "Use vendored SDL" OFF)
# option(SDL_IMAGE_VENDORED "Use vendored SDL_image" OFF)
# option(SDL_TTF_VENDORED "Use vendored SDL_ttf" OFF)

include(FetchContent)

# Adapted from:
# https://github.com/libsdl-org/SDL_helloworld
if(SDL_VENDORED)
  FetchContent_Declare(
    SDL3
    GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
    GIT_TAG "main"
    EXCLUDE_FROM_ALL
  )
  FetchContent_MakeAvailable(SDL3)
else()
  # find_package looks for already-installed system packages.
  # Configure with `-DCMAKE_PREFIX_PATH="/path/to/package1;/path/to/package2"`
  # to add search paths.
  find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
target_include_directories(${PROJECT_NAME} PRIVATE include)
