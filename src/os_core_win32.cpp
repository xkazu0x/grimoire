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
    // NOTE(xkazu0x): size not used, parameters must be zero if MEM_RELEASE
    VirtualFree(ptr, 0, MEM_RELEASE);
}
