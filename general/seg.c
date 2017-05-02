#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../general.h"

#define P_SEG(TYPE);\
inline TYPE *segment_pointer_##TYPE(TYPE *target, int from, int to) {\
	if (target == NULL){\
		return "";\
	}\
	int len_target = length_pointer_##TYPE(target);\
	if (from > to || from < 0 || from > len_target || to < 0) {\
		return "";\
	}\
	int len = to - from + 1;\
	if (to >= len_target) {\
		len = len_target - from + 1;\
	}\
	TYPE *pointer = calloc(len, sizeof(TYPE));\
	memcpy(pointer, &target[from], len);\
	return pointer;\
}

#define P_C_SEG(TYPE);\
inline TYPE *segment_pointer_constant_##TYPE(const TYPE *target, int from, int to) {\
	if (target == NULL){\
		return "";\
	}\
	int len_target = length_pointer_##TYPE(target);\
	if (from > to || from < 0 || from > len_target || to < 0) {\
		return "";\
	}\
	int len = to - from + 1;\
	if (to >= len_target) {\
		len = len_target - from + 1;\
	}\
	TYPE *pointer = calloc(len, sizeof(TYPE));\
	memcpy(pointer, &target[from], len);\
	return pointer;\
}

#define P_P_SEG(TYPE);\
inline TYPE **segment_pointer_pointer_##TYPE(TYPE **target, int from, int to) {\
    int len_target = length_pointer_pointer_##TYPE(target);\
	if (from > to || from < 0 || from > len_target || to < 0 || to > len_target) {\
		return "";\
	}\
	TYPE **pointer = calloc((to - from + 2), sizeof(TYPE*));\
	memcpy(pointer, &target[from], (to - from + 1) * sizeof(TYPE*));\
	return pointer;\
}

P_SEG(char);
P_C_SEG(char);
P_P_SEG(char);