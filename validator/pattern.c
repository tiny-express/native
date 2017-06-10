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

#include <regex.h>
#include "../validator.h"
#include "../common.h"
#include "../type.h"

#define IS(TYPE, PATTERN);\
inline int is_##TYPE(char* input) {\
    if (is_empty(input)) {\
        return FALSE;\
    }\
    regex_t exp;\
    int convert = regcomp(&exp, PATTERN, REG_EXTENDED);\
    if (convert != 0) {\
        return FALSE;\
    }\
    if (regexec(&exp, input, 0, NULL, 0) == 0) {\
        return TRUE;\
        regfree(&exp);\
    }\
    regfree(&exp);\
    return FALSE;\
}
IS(url, URL_PATTERN);IS(phone_number, PHONE_PATTERN);IS(email, EMAIL_PATTERN);

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