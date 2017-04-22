#include <time.h>
#include <stdlib.h>
#include "../datetime.h"
#include "../_string.h"

long now() {
    return time(NULL);
}

char *date(long timestamp, char *format) {
    char *date_format = string_replace(format, "D", "%d");
    date_format = string_replace(date_format, "d", "%d");
    date_format = string_replace(date_format, "M", "%m");
    date_format = string_replace(date_format, "m", "%m");
    date_format = string_replace(date_format, "Y", "%Y");
    date_format = string_replace(date_format, "y", "%Y");

    char *result = malloc(11 * sizeof(char));
    strftime(result, 11, date_format, gmtime(&timestamp));

    return result;
}


uint64_t get_timestamp() {
    #ifdef __APPLE__
        double timebase = 0.0;
        mach_timebase_info_data_t tb = { 0 };
        mach_timebase_info(&tb);
        timebase = tb.numer;
        timebase = timebase / tb.denom;
        uint64_t current = mach_absolute_time() * timebase;
        return current;
    #endif
    #ifdef __linux__
	    struct timespec tsp;
	    clock_gettime(0, &tsp);
	    return tsp.tv_sec * 1000000000 + tsp.tv_nsec;
    #endif
}