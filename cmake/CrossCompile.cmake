include(ExternalProject)

# TODO: add support for using WINE. (Likely cross platform?)
set(ACCEPT_MVSC_LICENSE
  "Accept the terms for the MVSC CRT.
  You will need to confirm it again manually."
  ON
)

# TODO: configure this in cli
set(CROSS_COMPILE_WINDOWS
  "Choose to cross-compile a Windows executable on Linux"
  OFF
)

if(LINUX AND CROSS_COMPILE_WINDOWS AND ACCEPT_MVSC_LICENSE)
  # ExternalProject_Add(WINDOWS_CRT
  #   SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendored"
  #   CONFIGURE_COMMAND ""
  #   BUILD_COMMAND "cargo install xwin"
  #   GIT_REPOSITORY
  # )
endif()
