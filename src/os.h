#ifndef OS_H
#define OS_H

#include "os_core.h"

#if OS_WINDOWS
# include "os_core_win32.h"
#else
# error "OS core layer not implemented for the current operating system."
#endif

#endif // OS_H
