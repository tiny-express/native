#ifndef BUILTIN_DATETIME_H
#define BUILTIN_DATETIME_H
#ifdef __linux__
#include <stdint.h>
#elif __APPLE__
#include <mach/mach_time.h>
#elif defined _WIN32 || defined __CYGWIN__
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
#endif

long now();
char *date(long timestamp, char *format);
uint64_t get_timestamp();
#endif
