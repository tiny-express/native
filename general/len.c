#pragma once
#include "../string.h"
#include "../general.h"

// Length of pointer
#define P_LEN(TYPE); \
inline int length_pointer_##TYPE(TYPE *target) {\
    if (target == NULL) return 0;\
	register TYPE*pointer;\
	for (pointer = target; *pointer; ++pointer);\
	return pointer - target;\
}

// length of pointer pointer
#define P_P_LEN(TYPE); \
inline int length_pointer_pointer_##TYPE(TYPE **target) {\
	register TYPE**pointer;\
	for (pointer = target; *pointer; ++pointer);\
	return pointer - target;\
}

// Length of number
#define NUM_LEN(TYPE); \
inline int length_##TYPE(TYPE target) {\
	char *result = string_from_##TYPE(target);\
	return length_pointer_char(result);\
}

P_LEN(char);
P_P_LEN(char);
NUM_LEN(short);
NUM_LEN(int);
NUM_LEN(long);
NUM_LEN(double);
NUM_LEN(float);
