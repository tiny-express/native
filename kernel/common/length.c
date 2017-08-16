/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "../string.h"
#include "../common.h"
#include "../type.h"

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
        if (target == NULL) return 0;\
        register TYPE**pointer;\
        for (pointer = target; *pointer; ++pointer);\
        return pointer - target;\
}

// Length of number
#define NUM_LEN(TYPE); \
inline int length_##TYPE(TYPE target) {\
        char *result = string_from_##TYPE(target);\
        int len = length_pointer_char(result); \
        free(result); \
        return len; \
}

//#ifndef __linux__
P_LEN(char);
//#endif
P_P_LEN(char);NUM_LEN(short);NUM_LEN(int);NUM_LEN(long);NUM_LEN(double);NUM_LEN(float);

/**
 * Is string empty ?
 *
 * @param input
 * @return TRUE or FALSE
 */
int is_empty(char *input) {
	if (length_pointer_char(input) == 0) {
		return TRUE;
	}
	return FALSE;
}
