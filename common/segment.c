/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../common.h"

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
	int len_target = length_pointer_##TYPE((TYPE*) target);\
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
		return NULL;\
	}\
	TYPE **pointer = calloc((to - from + 2), sizeof(TYPE*));\
	memcpy(pointer, &target[from], (to - from + 1) * sizeof(TYPE*));\
	return pointer;\
}

P_SEG(char);
P_C_SEG(char);
P_P_SEG(char);