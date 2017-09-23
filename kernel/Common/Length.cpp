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

#include "../String.hpp"
#include "../Common.hpp"
#include "../Type.hpp"

#define P_LEN(NAME, TYPE); \
int Kernel::lengthPointer##NAME(TYPE *target) {\
    if (target == NULL) return 0;\
        register TYPE*pointer;\
        for (pointer = target; *pointer; ++pointer);\
        return pointer - target;\
}

// length of pointer pointer
#define P_P_LEN(NAME, TYPE); \
int Kernel::lengthPointerPointer##NAME(TYPE **target) {\
        if (target == NULL) return 0;\
        register TYPE**pointer;\
        for (pointer = target; *pointer; ++pointer);\
        return pointer - target;\
}

// Length of number
#define NUM_LEN(NAME, TYPE); \
int Kernel::length##NAME(TYPE target) {\
        char *result = stringFrom##NAME(target);\
        int len = lengthPointerChar(result); \
        free(result); \
        return len; \
}

//#ifndef __linux__
P_LEN(Char, char);
//#endif
P_P_LEN(Char, char);
NUM_LEN(Short, short);
NUM_LEN(Int, int);
NUM_LEN(Long, long);
NUM_LEN(Double, double);
NUM_LEN(Float, float);

/**
 * Is string empty ?
 *
 * @param input
 * @return TRUE or FALSE
 */
int Kernel::isEmptyString(char *input) {
	if (lengthPointerChar(input) == 0) {
		return TRUE;
	}
	return FALSE;
}
