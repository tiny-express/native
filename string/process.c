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
#include "../type.h"
#include "../string.h"
#include "../general.h"

/**
 * String replace
 * Find a string in target and replace it by replace_with
 *
 * @param target
 * @param find_string
 * @param replace_with
 * @return string
 */
inline char *string_replace(char *target, char* find_string, char* replace_with) {
    if (target == NULL || find_string == NULL || replace_with == NULL) {
        return NULL;
    }
	int old_length = length_pointer_char(find_string);
	int new_length = length_pointer_char(replace_with);
	register int i, count = 0;
	for (i = 0; target[i] != '\0'; i++) {
		if (strstr(&target[i], find_string) == &target[i]) {
			count++;
			i += old_length - 1;
		}
	}
	char *result = (char*) malloc(i + count * (new_length - old_length));
	if (result == NULL) {
		return NULL;
	}
	i = 0;
	while (*target) {
		if (strstr(target, find_string) == target) {
			strcpy(&result[i], replace_with);
			i += new_length;
			target += old_length;
		} else {
			result[i++] = *target++;
		}
	}
	result[i] = '\0';
	return result;
}

// Split string to one dimession array by delimiter
inline char **string_split(char *target, const char *delim_) {
    if (target == NULL || delim_ == NULL) {
        return NULL;
    }
	char* delim = (char*) delim_;
	int len_target = length_pointer_char(target);
	int len_delim = length_pointer_char(delim);
	int distance = len_target - len_delim + 1;
	int len_item = 0;
	char *segment = calloc(len_delim, sizeof(char));
	char **data = malloc(MAX_STRING_LENGTH * sizeof(char*));
	register int count = 0, from = 0, to = 0;
	// Compare delimiter per target segment
	while (to <= distance) {
		memcpy(segment, &target[to], len_delim);
		if (strcmp(segment, delim) == 0) {
			if (to - from > 0) {
				len_item = to - from;
				char *item = malloc((len_item + 1) * sizeof(char));
				memcpy(item, &target[from], len_item);
				item[len_item] = '\0';
				// Append element to result
				data[count++] = item;
				from = to + len_delim;
			} else from += len_delim;
			to = from;
			continue;
		}
		++to;
	}
	if (to - from > 0) {
		len_item = to - from;
		char *item = malloc((len_item + 1) * sizeof(char));
		memcpy(item, &target[from], len_item + 1);
		item[len_item] = '\0';
		// Append element to result
		data[count++] = item;
	}
	// Saving memory
	char **result = malloc((count + 1) * sizeof(char*));
    memcpy(result, data, count * sizeof(char*));
	// End array
	result[count] = '\0';
	// Deallocate memory
	free(segment);
	free(data);
	return result;
}

// Join string with delimiter
inline char *string_join(char *target[], const char *delim) {
    if (target == NULL || delim == NULL) {
        return NULL;
    }
	int num = length_pointer_pointer_char(target) - 1;
	int len = 0, wlen = 0;
	char *tmp = calloc(MAX_STRING_LENGTH, sizeof(char));
	register int index;
	for (index = 0; index < num; index++) {
		// Copy memory segment
		wlen = length_pointer_char(target[index]);
		memcpy(tmp + len, target[index], wlen);
		len += wlen;
		// Copy memory segment
		wlen = length_pointer_char(delim);
		memcpy(tmp + len, delim, wlen);
		len += wlen;
	}
	// Copy memory segment
	wlen = length_pointer_char(target[num]);
	memcpy(tmp + len, target[num], wlen);
	len += wlen;
	len += 1;
	// Saving memory
	char *result = calloc(len, sizeof(char));
	memcpy(result, tmp, len);
	// Deallocate memory
	free(tmp);
	return result;
}

// Trim all space left and right
inline char *string_trim(char *target) {
    if (target == NULL) {
        return NULL;
    }
	int len, left, right;
	left = 0;
	right = length_pointer_char(target) - 1;
	while (target[left] == ' ') left++;
	while (target[right] == ' ') right--;
	len = right - left + 1;
	char *result = calloc(len, sizeof(char));
	memcpy(result, &target[left], len);
	return result;
}

inline int string_startswith(char *target, const char *prefix) {
    if (target == NULL || prefix == NULL) {
        return 0;
    }
    int target_length = length_pointer_char(target);
    int prefix_length = length_pointer_char(prefix);
    if (target_length < prefix_length) {
		return 0;
	}
    register int i;
    for (i = 0; i < prefix_length; i++) {
        if (prefix[i] != target[i]) {
            return 0;
        }
    }
    return 1;
}

inline int string_endswith(char *target, const char *suffix) {
    if (target == NULL || suffix == NULL) {
        return 0;
    }
    int target_length = length_pointer_char(target);
    int suffix_length = length_pointer_char(suffix);
    if (target_length < suffix_length) {
		return 0;
	}
    register int i;
    for (i = suffix_length - 1; i >= 0; i--) {
        if (suffix[i] != target[target_length - suffix_length + i]) {
            return 0;
        }
    }
    return 1;
}

inline int string_index(char *target, char *subtarget, int times) {
    if (target == NULL || subtarget == NULL) {
        return -1;
    }

    int target_length = length_pointer_char(target);
    int subtarget_length = length_pointer_char(subtarget);

    if ( target_length == 0 || subtarget_length == 0 || target_length < subtarget_length || (times == 0)) {
		// Can not found subtarget in target
		return -1;
	}

    register int index_target, index_subtarget, count_times = 0, pos_result;
    for (index_target = 0; index_target <= (target_length - subtarget_length); index_target++) {
        if (target[index_target] != subtarget[0]) {
            continue;
        }
        for (index_subtarget = 1; index_subtarget < subtarget_length; index_subtarget++) {
            if (target[index_target + index_subtarget] != subtarget[index_subtarget]) {
                break;
            }
        }
        if (index_subtarget == subtarget_length) {
            pos_result = index_target;
            count_times++;
            if(count_times == times) {
                return pos_result;
            }
        }
    }
    return -1;
}

inline char *string_random(char *target, int size) {
    if (target == NULL) {
        return NULL;
    }
	int target_length = length_pointer_char(target);
	char *result = malloc((size + 1) * sizeof(char));
	register int i;
	for (i = 0; i < size; i++) {
		result[i] = target[rand() % target_length];
	}
    result[size] = '\0';
	return result;
}

inline char *string_concat(char *target, char *subtarget) {
    if (target == NULL || subtarget == NULL) {
        return NULL;
    }
	int target_length = length_pointer_char(target);
	int subtarget_length = length_pointer_char(subtarget);
	char *result = malloc((target_length + subtarget_length + 1) * sizeof(char));
	memcpy(result, target, target_length);
	memcpy(result + target_length, subtarget, subtarget_length);
    result[target_length + subtarget_length] = '\0';
	return result;
}

inline char *string_from_to(char *target, int from, int to) {
	return segment_pointer_char(target, from, to);
}

inline char *string_from(char *target, int from) {
	return string_from_to(target, from, length_pointer_char(target));
}

inline char *string_to(char *target, int to) {
	return string_from_to(target, 0, to);
}

char *string_copy(char *target) {
    if (target == NULL) {
        return NULL;
    }
	int length = length_pointer_char(target);
	char *result = malloc((length + 1) * sizeof(char));
	memcpy(result, target, length);
	result[length] = '\0';
	return result;
}

char *string_upper(char *target) {
    if (target == NULL) {
        return NULL;
    }
	char *result = string_copy(target);
	register char *index = result;
	for (; *index; index++) {
		if (('a' <= *index) && (*index <= 'z')) {
			*index = *index - 32;
		}
	}
	return result;
}

char *string_lower(char *target) {
    if (target == NULL) {
        return NULL;
    }
	char *result = string_copy(target);
	register char *index = result;
	for (; *index; index++) {
		if (('A' <= *index) && (*index <= 'Z')) {
			*index = *index + 32;
		}
	}
	return result;
}

char *string_title(char *target) {
    if (target == NULL) {
        return NULL;
    }
	char *result = string_copy(target);
	register char *index = result;
	if (length_pointer_char(index) > 0 && 'a' <= *index && *index <= 'z')  {
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


char *string_standardized(char *target) {
	if (target == NULL) {
        return NULL;
    }
    
	char **target_splitted = string_split(target," ");
	char *result = string_join(target_splitted," ");
	result[strlen(result) - 1] = '\0';
	return result;
}

