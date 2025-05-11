#include <stdio.h>
#include <malloc.h>

#include "base.h"
#include "base.cpp"

#include "os.h"
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
  - thread context
  - file handling
  - file paths
  - time
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

    u32 test_mem_count = 1024;
    u64 memory_size = test_mem_count*sizeof(s32);
    s32 *test_mem = (s32 *)os_reserve(memory_size);
    os_commit(test_mem, memory_size);
    for (s32 i = 0; i < test_mem_count; ++i) {
        test_mem[i] = i;
    }
    os_decommit(test_mem, memory_size);
    os_release(test_mem, memory_size);
    
    return(0);
}
