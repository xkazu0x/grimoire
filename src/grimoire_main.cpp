#include <stdio.h>

#define BUILD_CONSOLE_INTERFACE 1

#include "base.h"
#include "os.h"

#include "base.cpp"
#include "os.cpp"

/*
  TODO(xkazu0x):
  BASE
  - cross
  - matrices
  - arena (after os)
  - string (after arena)
  - log (after arena)

  OPERATING SYSTEM
  - thread context (after arena)
  - file handling (after string)
  - file paths (after string)
  - time
  - gfx

  RENDER
  - directx
  - opengl?
  - vulkan?
  - software?
*/

internal void
entry_point(int argc, char **argv) {
    printf("operating_system: %s\n", string_from_operating_system(operating_system_from_context()));
    printf("architecture: %s\n", string_from_architecture(architecture_from_context()));
    printf("compiler: %s\n", string_from_compiler(compiler_from_context()));
}
