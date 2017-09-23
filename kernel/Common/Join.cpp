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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Type.hpp"
#include "../Common.hpp"

/**
 * Join pointer pointer char
 * Concatenating all elements in target array into single string
 *
 * @param target
 * @return char pointer
 */
char *Kernel::joinPointerPointerChar(char **target) {
	register char **pointer;
	register int total_length = 0, item_length = 0;
	char *result_tmp = (char *)calloc(MAX_STRING_LENGTH, sizeof(char));
	for (pointer = target; *pointer; ++pointer) {
		item_length = lengthPointerChar(*pointer);
		memcpy(result_tmp + total_length, *pointer, item_length);
		total_length += item_length;
	}
	// Allocate enough memory for result
	char *result = (char *)calloc(total_length + 1, sizeof(char));
	memcpy(result, result_tmp, total_length);
	// Free memory for temporary variable
	free(result_tmp);
	return result;
}

/**
 * Join delimiter pointer pointer char
 * Concatenating all elements in target array into single string with delimiter
 *
 * @param target
 * @return char pointer
 */
char *Kernel::joinDelimiterPointerPointerChar(char **target, const char *delimiter) {
	register char **pointer;
	register int total_length = 0, item_length = 0;
	int delimiter_length = lengthPointerChar((char *) delimiter);
	char *result_tmp = (char *)calloc(MAX_STRING_LENGTH, sizeof(char));
	for (pointer = target; *pointer; ++pointer) {
		item_length = lengthPointerChar(*pointer);
		memcpy(result_tmp + total_length, *pointer, item_length);
		total_length += item_length;
		memcpy(result_tmp + total_length, delimiter, delimiter_length);
		total_length += delimiter_length;
	}
	// Allocate enough memory for result
	char *result = (char *)calloc(total_length - delimiter_length + 1, sizeof(char));
	// Copy and remove remainder delimiter
	memcpy(result, result_tmp, total_length - delimiter_length);
	// Free memory for temporary variable
	free(result_tmp);
	return result;
}
