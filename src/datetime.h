#ifndef BUILTIN_DATETIME_H
#define BUILTIN_DATETIME_H
#ifdef __linux__
#define uint64_t long 
#elif __APPLE__
#include <mach/mach_time.h>
#endif

long now();
char *date(long timestamp, char *format);
uint64_t get_timestamp();
#endif
