cmake_minimum_required(VERSION 3.11)
project(casual_cosmos C)

include(FetchContent)

# TODO: add vendored libraries,
# preferably *without* submodules!
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

# TODO: add cross-platform support. See:
# https://github.com/Ravbug/sdl3-sample
add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
