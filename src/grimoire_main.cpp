#include <stdio.h>

#include "base.h"
#include "base.cpp"

int main(void) {
    printf("operating system: ");
    Operating_System os = operating_system_from_context();
    switch (os) {
        case OperatingSystem_Windows: {
            printf("windows\n");
        } break;
        case OperatingSystem_Linux: {
            printf("linux\n");
        } break;
        case OperatingSystem_Mac: {
            printf("mac\n");
        } break;
        default: {
            printf("null\n");
        } break;
    }

    printf("architecture: ");
    Architecture arch = architecture_from_context();
    switch (os) {
        case Architecture_x64: {
            printf("x64\n");
        } break;
        case Architecture_x86: {
            printf("x86\n");
        } break;
        case Architecture_arm64: {
            printf("arm64\n");
        } break;
        case Architecture_arm32: {
            printf("arm32\n");
        } break;
        default: {
            printf("null\n");
        } break;
    }
    
    printf("compiler: ");
    Compiler compiler = compiler_from_context();
    switch (compiler) {
        case Compiler_msvc: {
            printf("msvc\n");
        } break;
        case Compiler_gcc: {
            printf("gcc\n");
        } break;
        case Compiler_clang: {
            printf("clang\n");
        } break;
        default: {
            printf("null\n");
        } break;
    }
    
    return(0);
}
