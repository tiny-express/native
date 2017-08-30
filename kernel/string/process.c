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
#include "../type.h"
#include "../string.h"
#include "../common.h"

/**
 * String replace
 * Find a string in target and replace it by replace_with
 *
 * @param target
 * @param find_string
 * @param replace_with
 * @return string
 */
inline char *string_replace(char *target, char *find_string, char *replace_with) {
	if (target == NULL || find_string == NULL || replace_with == NULL) {
		return strdup("");
	}
	char *result;
	int i, count = 0;
	int new_len = length_pointer_char(replace_with);
	int old_len = length_pointer_char(find_string);
	
	for (i = 0; target[ i ] != '\0'; i++) {
		if (strstr(&target[ i ], find_string) == &target[ i ]) {
			count++;
			i += old_len - 1;
		}
	}
	result = malloc(i + 1 + count * ( new_len - old_len ));
	
	i = 0;
	while (*target) {
		if (strstr(target, find_string) == target) {
			strcpy(&result[ i ], replace_with);
			i += new_len;
			target += old_len;
		} else {
			result[ i++ ] = *target++;
		}
	}
	result[ i ] = '\0';
	
	return result;
}

/**
 * String split
 *
 * @param target
 * @param delimiter
 * @return array char pointer
 */
inline char **string_split(char *target, char *delimiter) {
	if (target == NULL || delimiter == NULL) {
		char **result = calloc(1, sizeof(char *));
		return result;
	}
	char **data = calloc(MAX_STRING_LENGTH, sizeof(char *));
	const int target_length = length_pointer_char(target);
	char const_target[target_length + 1];
	strncpy(const_target, target, (size_t) target_length);
	const_target[ target_length ] = '\0';
	char *item = strtok(const_target, delimiter);
	register int count = 0;
	while (item != NULL) {
		data[ count++ ] = strdup(item);
		item = strtok(NULL, delimiter);
	}
	char **result = calloc((size_t) count + 1, sizeof(char *));
	memcpy(result, data, count * sizeof(char *));
	result[ count ] = '\0';
	free(data);
	return result;
}

/**
 * Free pointer pointer char
 *
 * @param char_array
 */
void free_pointer_pointer_char(char **char_array) {
	if (char_array == NULL) {
		return;
	}
	int length = length_pointer_pointer_char(char_array);
	register int index;
	for (index = length - 1; index >= 0; index--) {
		free(char_array[ index ]);
	}
	free(char_array);
}

/**
 * String join
 *
 * @param target
 * @param delimiter
 * @return string
 */
inline char *string_join(char *target[], char *delimiter) {
	if (target == NULL || delimiter == NULL) {
		return NULL;
	}
	int num = length_pointer_pointer_char(target) - 1;
	int len = 0, wlen = 0;
	char *tmp = calloc(MAX_STRING_LENGTH, sizeof(char));
	register int index;
	for (index = 0; index < num; index++) {
		// Copy memory segment
		wlen = length_pointer_char(target[ index ]);
		memcpy(tmp + len, target[ index ], wlen);
		len += wlen;
		// Copy memory segment
		wlen = length_pointer_char(delimiter);
		memcpy(tmp + len, delimiter, wlen);
		len += wlen;
	}
	// Copy memory segment
	wlen = length_pointer_char(target[ num ]);
	memcpy(tmp + len, target[ num ], wlen);
	len += wlen;
	len += 1;
	// Saving memory
	char *result = calloc(len + 1, sizeof(char));
	memcpy(result, tmp, len);
	// Deallocate memory
	free(tmp);
	return result;
}

/**
 * String trim
 *
 * @param target
 * @return string
 */
inline char *string_trim(char *target) {
	if (target == NULL) {
		return NULL;
	}
	int len, left, right;
	left = 0;
	right = length_pointer_char(target) - 1;
	while (target[ left ] == ' ')
		left++;
	while (target[ right ] == ' ')
		right--;
	len = right - left + 1;
	char *result = calloc(len + 1, sizeof(char));
	strncpy(result, &target[ left ], len);
	return result;
}

/**
 * String start withs a prefix
 *
 * @param target
 * @param prefix
 * @return TRUE | FALSE
 */
inline int string_startswith(char *target, char *prefix) {
	if (target == NULL || prefix == NULL) {
		return FALSE;
	}
	int target_length = length_pointer_char(target);
	int prefix_length = length_pointer_char(prefix);
	if (target_length < prefix_length) {
		return FALSE;
	}
	register int i;
	for (i = 0; i < prefix_length; i++) {
		if (prefix[ i ] != target[ i ]) {
			return FALSE;
		}
	}
	return TRUE;
}

/**
 * String end withs a suffix
 *
 * @param target
 * @param suffix
 * @return TRUE | FALSE
 */
inline int string_endswith(char *target, char *suffix) {
	if (target == NULL || suffix == NULL) {
		return FALSE;
	}
	int target_length = length_pointer_char(target);
	int suffix_length = length_pointer_char(suffix);
	if (target_length < suffix_length) {
		return FALSE;
	}
	register int i;
	for (i = suffix_length - 1; i >= 0; i--) {
		if (suffix[ i ] != target[ target_length - suffix_length + i ]) {
			return FALSE;
		}
	}
	return TRUE;
}

/**
 * String index
 *
 * @param target
 * @param subtarget
 * @param times
 * @return position
 */
inline int string_index(char *target, char *subtarget, int times) {
	if (is_empty(target) || is_empty(subtarget) || ( times <= 0 )) {
		return NOT_FOUND;
	}
	
	int target_length = length_pointer_char(target);
	int subtarget_length = length_pointer_char(subtarget);
	
	if (target_length == 0 || subtarget_length == 0 || target_length < subtarget_length || ( times == 0 )) {
		return NOT_FOUND;
	}
	
	register int index_target, index_subtarget, count_times = 0, position_result;
	for (index_target = 0; index_target <= ( target_length - subtarget_length ); index_target++) {
		if (target[ index_target ] != subtarget[ 0 ]) {
			continue;
		}
		for (index_subtarget = 1; index_subtarget < subtarget_length; index_subtarget++) {
			if (target[ index_target + index_subtarget ] != subtarget[ index_subtarget ]) {
				break;
			}
		}
		if (index_subtarget == subtarget_length) {
			position_result = index_target;
			count_times++;
			if (count_times == times) {
				return position_result;
			}
		}
	}
	return NOT_FOUND;
}

/**
 * String random
 *
 * @param target
 * @param size
 * @return random string
 */
inline char *string_random(char *target, int size) {
	if (is_empty(target)) {
		return NULL;
	}
	int target_length = length_pointer_char(target);
	char *result = calloc(size + 1, sizeof(char));
	register int i;
	for (i = 0; i < size; i++) {
		result[ i ] = target[ rand() % target_length ];
	}
	result[ size ] = '\0';
	return result;
}

/**
 * Append a character into a string
 *
 * @param target
 * @param subtarget
 * @return string
 */
inline char *string_append(char **target, char subtarget) {
	asprintf(target, "%s%c", *target, subtarget);
	return *target;
}

/**
 * String concatenation
 *
 * @param target
 * @param subtarget
 * @return string
 */
inline char *string_concat(char *target, char *subtarget) {
	if (is_empty(target)) {
		return strdup(subtarget);
	}
	if (is_empty(subtarget)) {
		return strdup(target);
	}
	int target_length = length_pointer_char(target);
	int subtarget_length = length_pointer_char(subtarget);
	char *result = calloc(target_length + subtarget_length + 1, sizeof(char));
	memcpy(result, target, target_length);
	memcpy(result + target_length, subtarget, subtarget_length);
	result[ target_length + subtarget_length ] = '\0';
	return result;
}

/**
 * String from to
 *
 * @param target
 * @param from
 * @param to
 * @return string
 */
inline char *string_from_to(char *target, int from, int to) {
	return segment_pointer_char(target, from, to);
}

/**
 * Substring from a position to end of string
 *
 * @param target
 * @param from
 * @return
 */
inline char *string_from(char *target, int from) {
	return string_from_to(target, from, length_pointer_char(target));
}

/**
 * String from a position
 *
 * @param target
 * @param to
 * @return
 */
inline char *string_to(char *target, int to) {
	return string_from_to(target, 0, to);
}

/**
 * String copy
 *
 * @param target
 * @return string
 */
char *string_copy(char *target) {
	if (is_empty(target)) {
		return strdup("");
	}
	int length = length_pointer_char(target);
	char *result = (char *) calloc(length + 1, sizeof(char));
	memcpy(result, target, length);
	result[ length ] = '\0';
	return result;
}

/**
 * String upper
 *
 * @param target
 * @return string
 */
char *string_upper(char *target) {
	if (is_empty(target)) {
		return NULL;
	}
	char *result = string_copy(target);
	register char *index = result;
	for (; *index; index++) {
		if (( 'a' <= *index ) && ( *index <= 'z' )) {
			*index = *index - 32;
		}
	}
	return result;
}

/**
 * String lower
 *
 * @param target
 * @return string
 */
char *string_lower(char *target) {
	if (is_empty(target)) {
		return NULL;
	}
	char *result = string_copy(target);
	register char *index = result;
	for (; *index; index++) {
		if (( 'A' <= *index ) && ( *index <= 'Z' )) {
			*index = *index + 32;
		}
	}
	return result;
}

/**
 * String title
 *
 * @param target
 * @return string
 */
char *string_title(char *target) {
	if (is_empty(target)) {
		return NULL;
	}
	char *result = string_copy(target);
	register char *index = result;
	if (length_pointer_char(index) > 0 && 'a' <= *index && *index <= 'z') {
		*index = *index - 32;
	}
	char last_index = *index;
	index++;
	for (; *index; index++) {
		if (last_index == ' ' && 'a' <= *index && *index <= 'z') {
			*index = *index - 32;
		}
		last_index = *index;
	}
	return result;
}

/**
 * Standardized string
 *
 * @param target
 * @return string
 */
char *string_standardized(char *target) {
	if (is_empty(target)) {
		return NULL;
	}
	char **segments = string_split(target, " ");
	char *result = string_join(segments, " ");
	result[ length_pointer_char(result) ] = '\0';
	free_pointer_pointer_char(segments);
	return result;
}

/**
 * Check two string equals or not
 *
 * @param target1
 * @param target2
 * @return TRUE | FALSE
 */
int string_equals(char *target1, char *target2) {
	if (( target1 == NULL) && ( target2 == NULL)) {
		return TRUE;
	}
	if (( target1 == NULL) || ( target2 == NULL)) {
		return FALSE;
	}
	if (strcmp(target1, target2) == 0) {
		return TRUE;
	}
	return FALSE;
}

/**
 * Reverse a string
 *
 * @param target
 * @return string reversed
 */
char *string_reverse(char *target) {
	int target_length = length_pointer_char(target);
	char *result = (char *) calloc(target_length + 1, sizeof(char));
#ifdef __linux__
	register
#endif
	int index;
	for (index = 0; index < target_length; index++) {
		result[ index ] = target[ target_length - index - 1 ];
	}
	result[ target_length ] = '\0';
	return result;
}

/**
 * Match a regex in target
 *
 * @param target
 * @param regex
 * @return TRUE | FALSE
 */
int string_matches(char *target, char *regex) {
//	if (is_empty(target)) {
//		return FALSE;
//	}
//
//	regex_t exp;
//	int convert = regcomp(&exp, regex, REG_EXTENDED);
//	if (convert != 0) {
//        regfree(&exp);
//		return FALSE;
//	}
//	if (regexec(&exp, target, 0, NULL, 0) == 0) {
//		regfree(&exp);
//		return TRUE;
//	}
//    regfree(&exp);
	return FALSE;
}