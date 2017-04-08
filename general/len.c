#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "../string.h"

// Length of pointer
#define P_LEN(TYPE); \
int length_pointer_##TYPE(TYPE *target) {\
	register TYPE*pointer;\
	for (pointer = target; *pointer; ++pointer);\
	return pointer - target;\
}

// Length of constant pointer
#define P_C_LEN(TYPE); \
int length_pointer_constant_##TYPE(const TYPE *target_const) {\
	TYPE* target = (TYPE*) target_const;\
	register TYPE*pointer;\
	for (pointer = target; *pointer; ++pointer);\
	return pointer - target;\
}

// length of pointer pointer
#define P_P_LEN(TYPE); \
int length_pointer_pointer_##TYPE(TYPE **target) {\
	register TYPE**pointer;\
	for (pointer = target; *pointer; ++pointer);\
	return pointer - target;\
}

// Length of number
#define NUM_LEN(TYPE); \
int length_##TYPE(TYPE target) {\
	char *result = string_from_##TYPE(target);\
	return length_pointer_char(result);\
}

P_LEN(char);
P_C_LEN(char);
P_P_LEN(char);
NUM_LEN(short);
P_LEN(short);
NUM_LEN(int);
P_LEN(int);
NUM_LEN(long);
P_LEN(long);
NUM_LEN(double);
P_LEN(double);
NUM_LEN(float);
P_LEN(float);