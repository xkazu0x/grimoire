#ifndef OS_CORE_H
#define OS_CORE_H

////////////////////////////////
// NOTE(xkazu0x): Memory allocation

internal void *os_reserve(u64 size);
internal b32 os_commit(void *ptr, u64 size);
internal void os_decommit(void *ptr, u64 size);
internal void os_release(void *ptr, u64 size);

#endif // OS_CORE_H
