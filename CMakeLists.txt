# Adapted from:
# sdl3-sample
# https://github.com/Ravbug/sdl3-sample
cmake_minimum_required(VERSION 3.16)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(SetupPlatform)

project(casual_cosmos C)

SETUP_PLATFORM()

target_sources(${EXECUTABLE_NAME}
PRIVATE
  src/main.c
)

option(SDLVENDORED "Use vendored SDL" OFF)
# Defined internally to cmake files
# of each respective lib
set(SDLIMAGE_VENDORED OFF)
set(SDLMIXER_VENDORED ON)
set(SDLTTF_VENDORED OFF)

include(FetchContent)
set(FETCHCONTENT_BASE_DIR "${CMAKE_SOURCE_DIR}/vendored")
set(FETCHCONTENT_QUIET FALSE)

# Adapted from:
# https://github.com/libsdl-org/SDL_helloworld
if(SDLVENDORED)
  FetchContent_Declare(
    SDL3
    GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
    GIT_TAG "main"
    EXCLUDE_FROM_ALL
    SOURCE_DIR "vendored"
  )
  FetchContent_MakeAvailable(SDL3)
else()
  # find_package looks for already-installed system packages.
  # Configure with `-DCMAKE_PREFIX_PATH="/path/to/package1;/path/to/package2"`
  # to add search paths.
  find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
endif()

if(SDLIMAGE_VENDORED)
  FetchContent_Declare(
    SDL3_image
    GIT_REPOSITORY "https://github.com/libsdl-org/SDL_image.git"
    GIT_TAG "main"
    EXCLUDE_FROM_ALL
  )
  FetchContent_MakeAvailable(SDL3_image)
else()
  # find_package looks for already-installed system packages.
  # Configure with `-DCMAKE_PREFIX_PATH="/path/to/package1;/path/to/package2"`
  # to add search paths.
  find_package(SDL3_image REQUIRED)
endif()

if(SDLMIXER_VENDORED)
  FetchContent_Declare(
    SDL3_mixer
    GIT_REPOSITORY "https://github.com/libsdl-org/SDL_mixer.git"
    GIT_TAG "main"
    EXCLUDE_FROM_ALL
  )
  FetchContent_MakeAvailable(SDL3_mixer)
else()
  # find_package looks for already-installed system packages.
  # Configure with `-DCMAKE_PREFIX_PATH="/path/to/package1;/path/to/package2"`
  # to add search paths.
  find_package(SDL3_mixer REQUIRED)
endif()

if(SDLTTF_VENDORED)
  FetchContent_Declare(
    SDL3_ttf
    GIT_REPOSITORY "https://github.com/libsdl-org/SDL_ttf.git"
    GIT_TAG "main"
    EXCLUDE_FROM_ALL
  )
  FetchContent_MakeAvailable(SDL3_ttf)
else()
  # find_package looks for already-installed system packages.
  # Configure with `-DCMAKE_PREFIX_PATH="/path/to/package1;/path/to/package2"`
  # to add search paths.
  find_package(SDL3_ttf REQUIRED)
endif()

target_link_libraries(${PROJECT_NAME}
  PRIVATE
  SDL3_image::SDL3_image
  SDL3_mixer::SDL3_mixer
  SDL3_ttf::SDL3_ttf
  # SDL3 MUST be last item
  # in list of SDL libraries
  SDL3::SDL3
)
target_include_directories(${PROJECT_NAME} PRIVATE include)
