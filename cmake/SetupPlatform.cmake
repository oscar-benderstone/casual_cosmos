# Add platform specific settings.
# Need to use a macro to access
# global variables in dependencies
# and cmake
macro(SETUP_PLATFORM)
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
endmacro()
