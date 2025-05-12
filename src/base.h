#ifndef BASE_H
#define BASE_H

////////////////////////////////
// NOTE(xkazu0x): Clang OS/Arch cracking

#if defined(__clang__)
# define COMPILER_CLANG 1

# if defined(_WIN32)
#  define OS_WINDOWS 1
# elif defined(__gnu_linux__) || defined(__linux__)
#  define OS_LINUX 1
# elif defined(__APPLE__) && defined(__MACH__)
#  define OS_MAC 1
# else
#  error Compiler/OS is not supported.
# endif

# if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64)
#  define ARCH_X64 1
# elif defined(i386) || defined(__i386) || defined(__i386__)
#  define ARCH_X86 1
# elif defined(__aarch64__)
#  define ARCH_ARM64 1
# elif defined(__arm__)
#  define ARCH_ARM32 1
# else
#  error Architecture is not supported.
# endif

////////////////////////////////
// NOTE(xkazu0x): MSVC OS/Arch cracking

#elif defined(_MSC_VER)
# define COMPILER_MSVC 1

# if defined(_WIN32)
#  define OS_WINDOWS 1
# else
#  error Compiler/OS is not supported.
# endif

# if defined(_M_AMD64)
#  define ARCH_X64 1
# elif defined(_M_IX86)
#  define ARCH_X86 1
# elif defined(_M_ARM64)
#  define ARCH_ARM64 1
# elif defined(_M_ARM)
#  define ARCH_ARM32 1
# else
#  error Architecture not supported.
# endif

////////////////////////////////
// NOTE(xkazu0x): GCC OS/Arch cracking

#elif defined(__GNUC__)
# define COMPILER_GCC 1

# if defined(_WIN32)
#  define OS_WINDOWS 1
# elif defined(__gnu_linux__)
#  define OS_LINUX 1
# elif defined(__APPLE__) && defined(__MACH__)
#  define OS_MAC 1
# else
#  error Compiler/OS is not supported.
# endif

# if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64)
#  define ARCH_X64 1
# elif defined(i386) || defined(__i386) || defined(__i386__)
#  define ARCH_X86 1
# elif defined(__aarch64__)
#  define ARCH_ARM64 1
# elif defined(__arm__)
#  define ARCH_ARM32 1
# else
#  error Architecture is not supported.
# endif

#else
# error Compiler is not supported.
#endif

////////////////////////////////
// NOTE(xkazu0x): Arch cracking

#if defined(ARCH_X64)
# define ARCH_64BIT 1
#elif defined(ARCH_X86)
# define ARCH_32BIT 1
#endif

#if ARCH_ARM32 || ARCH_ARM64 || ARCH_X64 || ARCH_X86
# define ARCH_LITTLE_ENDIAN 1
#else
# error Endianness of this architecture not understood by context cracker.
#endif

////////////////////////////////
// NOTE(xkazu0x): Build option cracking

#if !defined(BUILD_DEBUG)
# define BUILD_DEBUG 1
#endif

#if !defined(BUILD_CONSOLE_INTERFACE)
# define BUILD_CONSOLE_INTERFACE 0
#endif

////////////////////////////////
// NOTE(xkazu0x): Zero all undefined options

#if !defined(ARCH_32BIT)
# define ARCH_32BIT 0
#endif
#if !defined(ARCH_64BIT)
# define ARCH_64BIT 0
#endif
#if !defined(ARCH_X64)
# define ARCH_X64 0
#endif
#if !defined(ARCH_X86)
# define ARCH_X86 0
#endif
#if !defined(ARCH_ARM64)
# define ARCH_ARM64 0
#endif
#if !defined(ARCH_ARM32)
# define ARCH_ARM32 0
#endif
#if !defined(COMPILER_MSVC)
# define COMPILER_MSVC 0
#endif
#if !defined(COMPILER_GCC)
# define COMPILER_GCC 0
#endif
#if !defined(COMPILER_CLANG)
# define COMPILER_CLANG 0
#endif
#if !defined(OS_WINDOWS)
# define OS_WINDOWS 0
#endif
#if !defined(OS_LINUX)
# define OS_LINUX 0
#endif
#if !defined(OS_MAC)
# define OS_MAC 0
#endif

////////////////////////////////
// NOTE(xkazu0x): Unsupported errors

#if ARCH_X86
# error You tried to build in x86 (32 bit) mode, but currently, only building in x64 (64 bit) mode is supported.
#endif
#if !ARCH_X64
# error You tried to build with an unsupported architecture. Currently, only building in x64 mode is supported.
#endif

////////////////////////////////
// NOTE(xkazu0x): Helper macros

#define internal static
#define global   static
#define local    static

#if COMPILER_MSVC
# define Trap() __debugbreak()
#elif COMPILER_CLANG || COMPILER_GCC
# define Trap() __builtin_trap()
#else
# error Unknown trap intrinsic for this compiler.
#endif

#define AssertAlways(x) do {if (!(x)) {Trap();}} while(0)
#if BUILD_DEBUG
# define Assert(x) AssertAlways(x)
#else
# define Assert(x) (void)(x)
#endif
#define InvalidPath        Assert(!"Invalid Path!")
#define NotImplemented     Assert(!"Not Implemented!")

#define KB(x) (((u64)(x)) << 10)
#define MB(x) (((u64)(x)) << 20)
#define GB(x) (((u64)(x)) << 30)
#define TB(x) (((u64)(x)) << 40)
#define Thousand(x) ((x)*1000)
#define Million(x)  ((x)*1000000)
#define Billion(x)  ((x)*1000000000)

#define Min(a, b) ((a)<(b)?(a):(b))
#define Max(a, b) ((a)>(b)?(a):(b))

#define ArrayCount(x) (sizeof(x)/sizeof((x)[0]))

////////////////////////////////
// NOTE(xkazu0x): Base types

#include <stdint.h>
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t   s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;
typedef s8       b8;
typedef s16      b16;
typedef s32      b32;
typedef s64      b64;
typedef float    f32;
typedef double   f64;

////////////////////////////////
// NOTE(xkazu0x): Constants

global s8  s8_min  = (s8) 0x80;
global s16 s16_min = (s16)0x8000;
global s32 s32_min = (s32)0x80000000;
global s64 s64_min = (s64)0x8000000000000000llu;

global s8  s8_max  = (s8) 0x7F;
global s16 s16_max = (s16)0x7FFF;
global s32 s32_max = (s32)0x7FFFFFFF;
global s64 s64_max = (s64)0x7FFFFFFFFFFFFFFFllu;

global u8  u8_max  = 0xFF;
global u16 u16_max = 0xFFFF;
global u32 u32_max = 0xFFFFFFFF;
global u64 u64_max = 0xFFFFFFFFFFFFFFFFllu;

#include <float.h>
global f32 f32_max = FLT_MAX;
global f32 f32_min = -FLT_MAX;

global f32 pi32 = 3.14159265359f;
global f64 pi64 = 3.14159265359;

////////////////////////////////
// NOTE(xkazu0x): Context enums

enum Operating_System {
    OperatingSystem_Null,
    OperatingSystem_Windows,
    OperatingSystem_Linux,
    OperatingSystem_Mac,
    OperatingSystem_Count,
};

enum Architecture {
    Architecture_Null,
    Architecture_x64,
    Architecture_x86,
    Architecture_arm64,
    Architecture_arm32,
    Architecture_Count,
};

enum Compiler {
    Compiler_Null,
    Compiler_msvc,
    Compiler_gcc,
    Compiler_clang,
    Compiler_Count,
};

////////////////////////////////
// NOTE(xkazu0x): Context functions

internal Operating_System operating_system_from_context(void);
internal Architecture architecture_from_context(void);
internal Compiler compiler_from_context(void);

internal char *string_from_operating_system(Operating_System os);
internal char *string_from_architecture(Architecture arch);
internal char *string_from_compiler(Compiler compiler);

////////////////////////////////
// NOTE(xkazu0x): Math functions

#define square(x) ((x)*(x))

#include <math.h>
#define sqrt_f32(x) sqrtf(x)
#define cbrt_f32(x) cbrtf(x)
#define ceil_f32(x) ceilf(x)
#define floor_f32(x) floorf(x)
#define round_f32(x) roundf(x)
#define abs_f32(x) fabsf(x)
#define sin_f32(x) sinf(x)
#define cos_f32(x) cosf(x)
#define tan_f32(x) tanf(x)

////////////////////////////////
// NOTE(xkazu0x): Vector types

union Vec2 {
    struct {
        f32 x, y;
    };
    struct {
        f32 u, v;
    };
    
    f32 e[2];
};

union Vec3 {
    struct {
        f32 x, y, z;
    };
    struct {
        f32 r, g, b;
    };
    
    struct {
        Vec2 xy;
        f32 _z0;
    };
    struct {
        Vec2 rg;
        f32 _b0;
    };
    
    f32 e[3];
};

union Vec4 {
    struct {
        f32 x, y, z, w;
    };
    struct {
        f32 r, g, b, a;
    };
    
    struct {
        Vec2 xy;
        Vec2 zw;
    };
    struct {
        Vec2 rg;
        Vec2 ba;
    };

    struct {
        Vec2 xyz;
        f32 _w0;
    };
    struct {
        Vec2 rgb;
        f32 _a0;
    };
    
    f32 e[4];
};

////////////////////////////////
// NOTE(xkazu0x): Vector functions

internal Vec2 make_vec2(f32 x);
internal Vec3 make_vec3(f32 x);
internal Vec4 make_vec4(f32 x);

internal Vec2 make_vec2(f32 x, f32 y);
internal Vec3 make_vec3(f32 x, f32 y, f32 z);
internal Vec4 make_vec4(f32 x, f32 y, f32 z, f32 w);

internal Vec3 make_vec3(Vec2 xy, f32 z);
internal Vec4 make_vec4(Vec2 xy, f32 z, f32 w);
internal Vec4 make_vec4(Vec3 xyz, f32 w);

internal Vec2 operator+(Vec2 a, Vec2 b);
internal Vec3 operator+(Vec3 a, Vec3 b);
internal Vec4 operator+(Vec4 a, Vec4 b);

internal Vec2 &operator+=(Vec2 &a, Vec2 b);
internal Vec3 &operator+=(Vec3 &a, Vec3 b);
internal Vec4 &operator+=(Vec4 &a, Vec4 b);

internal Vec2 operator-(Vec2 v);
internal Vec3 operator-(Vec3 v);
internal Vec4 operator-(Vec4 v);

internal Vec2 operator-(Vec2 a, Vec2 b);
internal Vec3 operator-(Vec3 a, Vec3 b);
internal Vec4 operator-(Vec4 a, Vec4 b);

internal Vec2 &operator-=(Vec2 &a, Vec2 b);
internal Vec3 &operator-=(Vec3 &a, Vec3 b);
internal Vec4 &operator-=(Vec4 &a, Vec4 b);

internal Vec2 operator*(f32 s, Vec2 v);
internal Vec3 operator*(f32 s, Vec3 v);
internal Vec4 operator*(f32 s, Vec4 v);

internal Vec2 operator*(Vec2 v, f32 s);
internal Vec3 operator*(Vec3 v, f32 s);
internal Vec4 operator*(Vec4 v, f32 s);

internal Vec2 &operator*=(Vec2 &v, f32 s);
internal Vec3 &operator*=(Vec3 &v, f32 s);
internal Vec4 &operator*=(Vec4 &v, f32 s);

internal Vec2 operator/(Vec2 a, Vec2 b);
internal Vec3 operator/(Vec3 a, Vec3 b);
internal Vec4 operator/(Vec4 a, Vec4 b);

internal b32 operator==(Vec2 a, Vec2 b);
internal b32 operator==(Vec3 a, Vec3 b);
internal b32 operator==(Vec4 a, Vec4 b);

internal b32 operator!=(Vec2 a, Vec2 b);
internal b32 operator!=(Vec3 a, Vec3 b);
internal b32 operator!=(Vec4 a, Vec4 b);

internal Vec2 hadamard(Vec2 a, Vec2 b);
internal Vec3 hadamard(Vec3 a, Vec3 b);
internal Vec4 hadamard(Vec4 a, Vec4 b);

internal f32 dot(Vec2 a, Vec2 b);
internal f32 dot(Vec3 a, Vec3 b);
internal f32 dot(Vec4 a, Vec4 b);

internal f32 length_squared(Vec2 v);
internal f32 length_squared(Vec3 v);
internal f32 length_squared(Vec4 v);

internal f32 length(Vec2 v);
internal f32 length(Vec3 v);
internal f32 length(Vec4 v);

internal Vec2 normalize(Vec2 v);
internal Vec3 normalize(Vec3 v);
internal Vec4 normalize(Vec4 v);

#endif // BASE_H
