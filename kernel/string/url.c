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

#include <ctype.h>
#include <stdlib.h>
#include "../string.h"
#include "../common.h"

char from_hex(char ch) {
	return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}

char to_hex(char code) {
	static char hex[] = "0123456789abcdef";
	return hex[ code & 15 ];
}

char *url_encode(char *target) {
	char *target_index = target;
	char *result = calloc(length_pointer_char(target) * 3 + 1, sizeof(char));
	char *result_index = result;
	while (*target_index) {
		if (isalnum(*target_index) || *target_index == '-' || *target_index == '_' || *target_index == '.' || *target_index == '~') {
			*result_index++ = *target_index;
		} else if (*target_index == ' ') {
			*result_index++ = '+';
		} else {
			*result_index++ = '%', *result_index++ = to_hex(*target_index >> 4), *result_index++ = to_hex(*target_index & 15);
		}
		target_index++;
	}
	*result_index = '\0';
	return result;
}

char *url_decode(char *target) {
	char *target_index = target;
	char *result = calloc(length_pointer_char(target) + 1, sizeof(char));
	char *result_index = result;
	while (*target_index) {
		if (*target_index == '%') {
			if (target_index[ 1 ] && target_index[ 2 ]) {
				*result_index++ = from_hex(target_index[ 1 ]) << 4 | from_hex(target_index[ 2 ]);
				target_index += 2;
			}
		} else if (*target_index == '+') {
			*result_index++ = ' ';
		} else {
			*result_index++ = *target_index;
		}
		target_index++;
	}
	*result_index = '\0';
	return result;
}

char *find_param(char *name, char *params) {
	if (strcmp(params, "") == 0) {
		return strdup("");
	}
	
	char **query_pairs = string_split(params, "&");
	int length_pairs = length_pointer_pointer_char(query_pairs);

#ifdef __linux__
	register
#endif
	int i;
	for (i = 0; i < length_pairs; i++) {
		char **pair = string_split(query_pairs[ i ], "=");
		if (length_pointer_pointer_char(pair) == 2) {
			if (strcmp(pair[ 0 ], name) == 0) {
				char *result = strdup(pair[ 1 ]);
				free_pointer_pointer_char(pair);
				free_pointer_pointer_char(query_pairs);
				return result;
			}
		}
		free_pointer_pointer_char(pair);
	}
	
	free_pointer_pointer_char(query_pairs);
	return strdup("");
}

char *find_param_from_url(char *name, char *url) {
	char **url_components = string_split(url, "?");
	
	if (length_pointer_pointer_char(url_components) < 2) {
		free_pointer_pointer_char(url_components);
		return strdup("");
	}
	
	char *query_url = url_components[ 1 ];
	char **query_pairs = string_split(query_url, "&");
	int length_pairs = length_pointer_pointer_char(query_pairs);

#ifdef __linux__
	register
#endif
	int i;
	for (i = 0; i < length_pairs; i++) {
		char **pair = string_split(query_pairs[ i ], "=");
		if (length_pointer_pointer_char(pair) == 2) {
			if (strcmp(pair[ 0 ], name) == 0) {
				char *result = strdup(pair[ 1 ]);
				free_pointer_pointer_char(url_components);
				free_pointer_pointer_char(query_pairs);
				free_pointer_pointer_char(pair);
				
				return result;
			}
		}
		free_pointer_pointer_char(pair);
	}
	
	free_pointer_pointer_char(url_components);
	free_pointer_pointer_char(query_pairs);
	
	return strdup("");
}
