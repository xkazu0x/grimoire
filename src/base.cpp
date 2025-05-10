////////////////////////////////
// NOTE(xkazu0x): Context functions

internal Operating_System
operating_system_from_context(void) {
    Operating_System result = OperatingSystem_Null;
#if OS_WINDOWS
    result = OperatingSystem_Windows;
#elif OS_LINUX
    result = OperatingSystem_Linux;
#elif OS_MAC
    result = OperatingSystem_Mac;
#endif
    return(result);
}

internal Architecture
architecture_from_context(void) {
    Architecture result = Architecture_Null;
#if ARCH_X64
    result = Architecture_x64;
#elif ARCH_X86
    result = Architecture_x86;
#elif ARCH_ARM64
    result = Architecture_arm64;
#elif ARCH_ARM32
    result = Architecture_arm32;
#endif
    return(result);
}

internal Compiler
compiler_from_context(void) {
    Compiler result = Compiler_Null;
#if COMPILER_MSVC
    result = Compiler_msvc;
#elif COMPILER_GCC
    result = Compiler_gcc;
#elif COMPILER_CLANG
    result = Compiler_clang;
#endif
    return(result);
}

////////////////////////////////
// NOTE(xkazu0x): Vector functions

internal Vec2
make_vec2(f32 x) {
    Vec2 result = {x, x};
    return(result);
}

internal Vec3
make_vec3(f32 x) {
    Vec3 result = {x, x, x};
    return(result);
}

internal Vec4
make_vec4(f32 x)  {
    Vec4 result = {x, x, x, x};
    return(result);
}

internal Vec2
make_vec2(f32 x, f32 y) {
    Vec2 result = {x, y};
    return(result);
}

internal Vec3
make_vec3(f32 x, f32 y, f32 z) {
    Vec3 result = {x, y, z};
    return(result);
}

internal Vec4
make_vec4(f32 x, f32 y, f32 z, f32 w) {
    Vec4 result = {x, y, z, w};
    return(result);
}

internal Vec3
make_vec3(Vec2 xy, f32 z) {
    Vec3 result = {xy.x, xy.y, z};
    return(result);
}

internal Vec4
make_vec4(Vec2 xy, f32 z, f32 w) {
    Vec4 result = {xy.x, xy.y, z, w};
    return(result);
}

internal Vec4
make_vec4(Vec3 xyz, f32 w) {
    Vec4 result = {xyz.x, xyz.y, xyz.z, w};
    return(result);
}

internal Vec2
operator+(Vec2 a, Vec2 b) {
    Vec2 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return(result);
}

internal Vec3
operator+(Vec3 a, Vec3 b) {
    Vec3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return(result);
}

internal Vec4
operator+(Vec4 a, Vec4 b) {
    Vec4 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    result.w = a.w + b.w;
    return(result);
}

internal Vec2 &
operator+=(Vec2 &a, Vec2 b) {
    a = a + b;
    return(a);
}

internal Vec3 &
operator+=(Vec3 &a, Vec3 b) {
    a = a + b;
    return(a);
}

internal Vec4 &
operator+=(Vec4 &a, Vec4 b) {
    a = a + b;
    return(a);
}

internal Vec2
operator-(Vec2 v) {
    Vec2 result;
    result.x = -v.x;
    result.y = -v.y;
    return(result);
}

internal Vec3
operator-(Vec3 v) {
    Vec3 result;
    result.x = -v.x;
    result.y = -v.y;
    result.z = -v.z;
    return(result);
}

internal Vec4
operator-(Vec4 v) {
    Vec4 result;
    result.x = -v.x;
    result.y = -v.y;
    result.z = -v.z;
    result.w = -v.w;
    return(result);
}

internal Vec2
operator-(Vec2 a, Vec2 b) {
    Vec2 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return(result);
}

internal Vec3
operator-(Vec3 a, Vec3 b) {
    Vec3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return(result);
}

internal Vec4
operator-(Vec4 a, Vec4 b) {
    Vec4 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    result.w = a.w - b.w;
    return(result);
}

internal Vec2 &
operator-=(Vec2 &a, Vec2 b) {
    a = a - b;
    return(a);
}

internal Vec3 &
operator-=(Vec3 &a, Vec3 b) {
    a = a - b;
    return(a);
}

internal Vec4 &
operator-=(Vec4 &a, Vec4 b) {
    a = a - b;
    return(a);
}

internal Vec2
operator*(f32 s, Vec2 v) {
    Vec2 result;
    result.x = s*v.x;
    result.y = s*v.y;
    return(result);
}

internal Vec3
operator*(f32 s, Vec3 v) {
    Vec3 result;
    result.x = s*v.x;
    result.y = s*v.y;
    result.z = s*v.z;
    return(result);
}

internal Vec4
operator*(f32 s, Vec4 v) {
    Vec4 result;
    result.x = s*v.x;
    result.y = s*v.y;
    result.z = s*v.z;
    result.w = s*v.w;
    return(result);
}

internal Vec2
operator*(Vec2 v, f32 s) {
    Vec2 result;
    result.x = v.x*s;
    result.y = v.y*s;
    return(result);
}

internal Vec3
operator*(Vec3 v, f32 s) {
    Vec3 result;
    result.x = v.x*s;
    result.y = v.y*s;
    result.z = v.z*s;
    return(result);
}

internal Vec4
operator*(Vec4 v, f32 s) {
    Vec4 result;
    result.x = v.x*s;
    result.y = v.y*s;
    result.z = v.z*s;
    result.w = v.w*s;
    return(result);
}

internal Vec2 &
operator*=(Vec2 &v, f32 s) {
    v = v*s;
    return(v);
}

internal Vec3 &
operator*=(Vec3 &v, f32 s) {
    v = v*s;
    return(v);
}

internal Vec4 &
operator*=(Vec4 &v, f32 s) {
    v = v*s;
    return(v);
}

internal b32
operator==(Vec2 a, Vec2 b) {
    b32 result = ((a.x == b.x) &&
                  (a.y == b.y));
    return(result);
}

internal b32
operator==(Vec3 a, Vec3 b) {
    b32 result = ((a.x == b.x) &&
                  (a.y == b.y) &&
                  (a.z == b.z));
    return(result);
}

internal b32
operator==(Vec4 a, Vec4 b) {
    b32 result = ((a.x == b.x) &&
                  (a.y == b.y) &&
                  (a.z == b.z) &&
                  (a.w == b.w));
    return(result);
}

internal b32
operator!=(Vec2 a, Vec2 b) {
    b32 result = ((a.x != b.x) &&
                  (a.y != b.y));
    return(result);
}

internal b32
operator!=(Vec3 a, Vec3 b) {
    b32 result = ((a.x != b.x) &&
                  (a.y != b.y) &&
                  (a.z != b.z));
    return(result);
}

internal b32
operator!=(Vec4 a, Vec4 b) {
    b32 result = ((a.x != b.x) &&
                  (a.y != b.y) &&
                  (a.z != b.z) &&
                  (a.w != b.w));
    return(result);
}

internal Vec2
hadamard(Vec2 a, Vec2 b) {
    Vec2 result;
    result.x = a.x*b.x;
    result.y = a.y*b.y;
    return(result);
}

internal Vec3
hadamard(Vec3 a, Vec3 b) {
    Vec3 result;
    result.x = a.x*b.x;
    result.y = a.y*b.y;
    result.z = a.z*b.z;
    return(result);
}

internal Vec4
hadamard(Vec4 a, Vec4 b) {
    Vec4 result;
    result.x = a.x*b.x;
    result.y = a.y*b.y;
    result.z = a.z*b.z;
    result.w = a.w*b.w;
    return(result);
}

internal f32
dot(Vec2 a, Vec2 b) {
    f32 result = a.x*b.x + a.y*b.y;
    return(result);
}

internal f32
dot(Vec3 a, Vec3 b) {
    f32 result = a.x*b.x + a.y*b.y + a.z*b.z;
    return(result);
}

internal f32
dot(Vec4 a, Vec4 b) {
    f32 result = a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
    return(result);
}

internal f32
length_squared(Vec2 v) {
    f32 result = dot(v, v);
    return(result);
}

internal f32
length_squared(Vec3 v) {
    f32 result = dot(v, v);
    return(result);
}

internal f32
length_squared(Vec4 v) {
    f32 result = dot(v, v);
    return(result);
}

internal f32
length(Vec2 v) {
    f32 result = sqrt_f32(length_squared(v));
    return(result);
}

internal f32
length(Vec3 v) {
    f32 result = sqrt_f32(length_squared(v));
    return(result);
}

internal f32
length(Vec4 v) {
    f32 result = sqrt_f32(length_squared(v));
    return(result);
}
