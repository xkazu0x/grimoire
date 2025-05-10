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

    s64 array[] {
        KB(1), MB(1), GB(1), TB(1),
        Thousand(1), Million(1), Billion(1),
    };

    s64 min_value = array[0];
    s64 max_value = array[0];
    
    for (int index = 0;
         index < ArrayCount(array);
         ++index) {
        min_value = Min(min_value, array[index]);
        max_value = Max(max_value, array[index]);
    }
    
    printf("min value: %lld\n", min_value);
    printf("max value: %lld\n", max_value);

    printf("vec2:\n");
    Vec2 vec2 = make_vec2(10, 20);
    printf(" x:%.02f,  y:%.02f\n", vec2.x, vec2.y);
    printf(" u:%.02f,  v:%.02f\n", vec2.u, vec2.v);
    printf("e0:%.02f, e1:%.02f\n", vec2.e[0], vec2.e[1]);
    
    printf("vec3:\n");
    Vec3 vec3 = make_vec3(10, 20, 30);
    printf(" x:%.02f,  y:%.02f,  z:%.02f\n", vec3.x, vec3.y, vec3.z);
    printf(" r:%.02f,  g:%.02f,  b:%.02f\n", vec3.r, vec3.g, vec3.b);
    printf("e0:%.02f, e1:%.02f, e2:%.02f\n", vec3.e[0], vec3.e[1], vec3.e[2]);
    
    printf("vec4:\n");
    Vec4 vec4 = make_vec4(10, 20, 30, 40);
    printf(" x:%.02f,  y:%.02f,  z:%.02f  w:%.02f\n", vec4.x, vec4.y, vec4.z, vec4.w);
    printf(" r:%.02f,  g:%.02f,  b:%.02f  a:%.02f\n", vec4.r, vec4.g, vec4.b, vec4.a);
    printf("e0:%.02f, e1:%.02f, e2:%.02f e3:%.02f\n", vec4.e[0], vec4.e[1], vec4.e[2], vec4.e[3]);
    
    return(0);
}
