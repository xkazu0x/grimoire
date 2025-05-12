////////////////////////////////
// NOTE(xkazu0x): Memory allocation

internal void *
os_reserve(u64 size) {
    void *result = VirtualAlloc(0, size, MEM_RESERVE, PAGE_READWRITE);
    return(result);
}

internal b32
os_commit(void *ptr, u64 size) {
    b32 result = (VirtualAlloc(ptr, size, MEM_COMMIT, PAGE_READWRITE) != 0);
    return(result);
}

internal void
os_decommit(void *ptr, u64 size) {
    VirtualFree(ptr, size, MEM_DECOMMIT);
}

internal void
os_release(void *ptr, u64 size) {
    VirtualFree(ptr, 0, MEM_RELEASE);
}

////////////////////////////////
// NOTE(xkazu0x): Entry points

internal void
win32_entry_point_caller(int argc, char **argv) {
    entry_point(argc, argv);
}

#if BUILD_CONSOLE_INTERFACE
int
main(int argc, char **argv) {
    win32_entry_point_caller(argc, argv);
    return(0);
}
#else
// NOTE(xkazu0x): for __argc, __argv
#include <stdlib.h>

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    win32_entry_point_caller(__argc, __argv);
    return(0);
}
#endif
