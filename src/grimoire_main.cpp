#include <stdio.h>
#include <malloc.h>

#include "base.h"
#include "base.cpp"

/*
  TODO(xkazu0x):
  BASE
  - cross
  - matrices
  - arena (after os)
  - string (after arena)
  - log (after arena)

  OPERATING SYSTEM
  - memory operations
  - file handling
  - gfx

  RENDER
  - directx
  - opengl?
  - vulkan?
  - software?
*/

int
main(void) {
    printf("operating system: %s\n", string_from_operating_system(operating_system_from_context()));
    printf("architecture: %s\n", string_from_architecture(architecture_from_context()));
    printf("compiler: %s\n", string_from_compiler(compiler_from_context()));

    return(0);
}
