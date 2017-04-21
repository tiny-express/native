#include <stdio.h>
#include <memory.h>
#include "../string.h"

#define STR_FROM(TYPE, FORMAT); \
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

STR_FROM(short,  "%d\0");
STR_FROM(int,    "%d\0");
STR_FROM(long,   "%ld\0");
STR_FROM(float,  "%g\0");
STR_FROM(double, "%.16g\0");

STR_TO(short,  "%hi\0");
STR_TO(int,    "%d\0");
STR_TO(long,   "%ld\0");
STR_TO(float,  "%g\0");
STR_TO(double, "%lg\0");
