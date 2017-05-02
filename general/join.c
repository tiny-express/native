#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../general.h"

#define MAX_SIZE 100000

inline char *join_pointer_pointer_char(char **target)
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

inline char *join_delim_pointer_pointer_char(char **target, const char *delim)
{
	register char **pointer;
	register int total_length = 0, item_length = 0;
	int delim_length = length_pointer_char((char*) delim);
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
