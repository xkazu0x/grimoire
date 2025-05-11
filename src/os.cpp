#if OS_WINDOWS
# include "os_core_win32.cpp"
#else
# error "OS core layer not implemented for the current operating system."
#endif
