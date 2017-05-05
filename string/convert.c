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
#include <memory.h>
#include "../string.h"

#define STR_FROM(TYPE, FORMAT); \
inline char* string_from_##TYPE(TYPE target) {\
	char *convert;\
	asprintf(&convert, FORMAT, target);\
	return convert;\
}

#define STR_TO(TYPE, FORMAT);\
inline TYPE string_to_##TYPE(char *target) {\
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
//STR_TO(int,    "%d\0");
STR_TO(long,   "%ld\0");
STR_TO(float,  "%g\0");
STR_TO(double, "%lg\0");

int string_to_int(char* target) {
	if (target == NULL) {
		return 0;
	}
	return atoi(target);
}
