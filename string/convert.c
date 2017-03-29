#include <stdio.h>
#include "../string.h"

#define CONVERT_STR(TYPE, FORMAT); \
char* string_from_##TYPE(TYPE target) {\
	char *convert;\
	asprintf(&convert, FORMAT, target);\
	return convert;\
}

#define STR_TO(TYPE, FORMAT);\
TYPE string_to_##TYPE(char *target) {\
    if (target == NULL || strcmp(target, "\0") == 0) return 0;\
	TYPE result;\
    sscanf(target, FORMAT, &result);\
    return result;\
}


CONVERT_STR(short,  "%d\0");
CONVERT_STR(int,    "%d\0");
CONVERT_STR(long,   "%ld\0");
CONVERT_STR(float,  "%g\0");
CONVERT_STR(double, "%lg\0");

STR_TO(short,  "%hi\0");
STR_TO(int,    "%d\0");
STR_TO(long,   "%ld\0");
STR_TO(float,  "%g\0");
STR_TO(double, "%lg\0");
