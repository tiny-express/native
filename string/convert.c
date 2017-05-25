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
#include "../common.h"
#include "../type.h"
#include "../string.h"
#include "../validator.h"

/**
 * Convert generic types to string
 *
 * @param target
 * @return string
 */
#define STR_FROM(TYPE, FORMAT); \
inline char* string_from_##TYPE(TYPE target) {\
	char *convert;\
	asprintf(&convert, FORMAT, target);\
	return convert;\
}

/**
 * Convert string to generic types
 *
 * @param target
 * @return generic values
 */
#define STR_TO(TYPE, FORMAT);\
inline TYPE string_to_##TYPE(char *target) {\
    if (target == NULL || strcmp(target, "\0") == 0) return 0;\
	TYPE result;\
    sscanf(target, FORMAT, &result);\
    return result;\
}

STR_FROM(short,  "%d");
STR_FROM(int,    "%d");
STR_FROM(long,   "%ld");
STR_FROM(float,  "%g");
STR_FROM(double, "%.16g");

STR_TO(short,  "%hi");
STR_TO(float,  "%g");
STR_TO(double, "%lg");

/**
 * String from char
 *
 * @param target
 * @return string
 */
char *string_from_char(char target) {
    if (target == '\0') {
        return (char*) "";
    }
    char *result = malloc(2 * sizeof(char));
    result[0] = target;
    result[1] = '\0';
    return result;
}

/**
 * String to char
 *
 * @param target
 * @return string
 */
char string_to_char(char* target) {
	if (is_empty(target)) {
		return '\0';
	}
	return target[0];
}

/**
 * String to int
 *
 * @param target
 * @return string
 */
int string_to_int(char* target) {
	if (target == NULL) {
		return 0;
	}
	return atoi(target);
}

/**
 * String to long
 *
 * @param target
 * @return string
 */
long string_to_long(char* target) {
	if (target == NULL) {
		return 0;
	}
	return atol(target);
}

/**
 * String to boolean
 *
 * @param target
 * @return TRUE | FALSE
 */
int string_to_boolean(char* target) {
	if (length_pointer_char(target) == 0) {
		return FALSE;
	}
	char *boolean_value = string_lower(target);
	if (string_equals(boolean_value, "true")) {
		return TRUE;
	}
    if (string_to_int(boolean_value) == TRUE) {
        return TRUE;
    }
	return FALSE;
}
