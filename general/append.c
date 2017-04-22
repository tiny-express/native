#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../general.h"

inline char **append_pointer_char(char **target, char *append) {
	int len = length_pointer_pointer_char(target);
	char **pointer = calloc(len + 2, sizeof(char *));
	memcpy(pointer, target, len * sizeof(char *));
	*(pointer + len) = append;
	*(pointer + len + 1) = '\0';
	return pointer;
}