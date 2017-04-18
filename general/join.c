#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../general.h"
#include "../string.h"

#define MAX_SIZE 100000

// Join
#define P_JOIN(TYPE); \
char *join_pointer_##TYPE(TYPE *target) {\
    int num = length_pointer_##TYPE(target);\
    register int total_length = 0, item_length = 0;\
    char *tmp = calloc(MAX_SIZE, sizeof(char));\
	register int i;\
    for (i = 0; i < num; i++) {\
        item_length = length_##TYPE(target[i]);\
        memcpy(tmp + total_length, string_from_##TYPE(target[i]), item_length);\
        total_length += item_length;\
    }\
	char *result = calloc(total_length, sizeof(char));\
    memcpy(result, tmp, total_length);\
    free(tmp);\
	return result;\
}


// Join with delimiter
#define P_JOIN_DELIM(TYPE); \
char *join_delim_pointer_##TYPE(TYPE *target, const char *delim) {\
	int num = length_pointer_##TYPE(target);\
    register int item_length = 0, total_length = 0;\
    int delim_length = length_pointer_char(delim);\
    char *tmp = calloc(MAX_SIZE, sizeof(char));\
	register int i;\
    for (i = 0; i < num; i++) {\
        item_length = length_##TYPE(target[i]);\
        memcpy(tmp + total_length, string_from_##TYPE(target[i]), item_length);\
        total_length += item_length;\
        memcpy(tmp + total_length, delim, delim_length);\
        total_length += delim_length;\
    }\
	char *result = calloc(total_length, sizeof(char));\
    memcpy(result, tmp, total_length - delim_length);\
    free(tmp);\
	return result;\
}

char *join_pointer_pointer_char(char **target)
{
	register char **pointer;
	register int total_length = 0, item_length = 0;
	char *result_tmp = calloc(MAX_SIZE, sizeof(char));
	for (pointer = target; *pointer; ++pointer) {
		item_length = length_pointer_char(*pointer);
		memcpy(result_tmp + total_length, *pointer, item_length);
		total_length += item_length;
	}
	// Deallocate memory
	char *result = calloc(total_length + 1, sizeof(char));
	memcpy(result, result_tmp, total_length);
	// Saving memory
	free(result_tmp);
	return result;
}

char *join_delim_pointer_pointer_char(char **target, const char *delim)
{
	register char **pointer;
	register int total_length = 0, item_length = 0;
	int delim_length = length_pointer_constant_char(delim);
	char *result_tmp = calloc(MAX_SIZE, sizeof(char));
	for (pointer = target; *pointer; ++pointer) {
		item_length = length_pointer_char(*pointer);
		memcpy(result_tmp + total_length, *pointer, item_length);
		total_length += item_length;
		memcpy(result_tmp + total_length, delim, delim_length);
		total_length += delim_length;
	}
	// Deallocate memory
	char *result = calloc(total_length - delim_length + 1, sizeof(char));
	// Copy and remove remainder delimiter
	memcpy(result, result_tmp, total_length - delim_length);
	// Saving memory
	free(result_tmp);
	return result;
}

P_JOIN(short);
P_JOIN_DELIM(short);
P_JOIN(int);
P_JOIN_DELIM(int);
P_JOIN(long);
P_JOIN_DELIM(long);
P_JOIN(double);
P_JOIN_DELIM(double);
P_JOIN(float);
P_JOIN_DELIM(float);
