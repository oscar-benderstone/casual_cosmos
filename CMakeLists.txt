# Adapted from:
# sdl3-sample
# https://github.com/Ravbug/sdl3-sample
cmake_minimum_required(VERSION 3.16)

include(FetchContent)

# set the output directory for built objects.
# This makes sure that the dynamic
# library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# prevent installing to system directories.
set(_CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}" CACHE INTERNAL "")

project(casual_cosmos C)
set(EXECUTABLE_NAME ${PROJECT_NAME})

if((APPLE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin") OR EMSCRIPTEN)
  # Disable shared builds on platforms
  # where it does not make sense to use them
  set(_BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
  set(SDL_SHARED OFF)
else()
  set(SDL_SHARED ON)
endif()

if(MSVC)
  if(NOT CMAKE_GENERATOR STREQUAL "Ninja")
    # parallelize each target,
    # unless Ninja is the generator
    add_definitions(/MP)
  endif()
endif()

# Create an executable or a shared library
# based on the platform and add our sources to it
if(ANDROID)
  # The SDL java code is hardcoded to load
  # libmain.so on android, so we need to change EXECUTABLE_NAME
  set(EXECUTABLE_NAME main)
  add_library(${EXECUTABLE_NAME} SHARED)
else()
  add_executable(${EXECUTABLE_NAME})
endif()

target_sources(${EXECUTABLE_NAME}
PRIVATE
  src/main.c
)

# on Web targets, we need CMake to generate a HTML webpage.
if(EMSCRIPTEN)
  set(_CMAKE_EXECUTABLE_SUFFIX ".html" CACHE INTERNAL "")
endif()

# SDL_Image bug: https://github.com/libsdl-org/SDL_image/issues/506
if(APPLE AND NOT BUILD_SHARED_LIBS)
  find_library(IO_LIB ImageIO REQUIRED)
  find_library(CS_LIB CoreServices REQUIRED)
  find_library(CT_LIB CoreText REQUIRED)
  find_library(CG_LIB CoreGraphics REQUIRED)
  find_library(CF_LIB CoreFoundation REQUIRED)
  target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${CF_LIB} ${CT_LIB} ${IO_LIB} ${CS_LIB} ${CG_LIB})
endif()


# TODO: add vendored libraries,
# preferably *without* submodules!
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
