#include <stdio.h>
#include <stdlib.h>
#include "../string.h"
#include "../general.h"

#define MAX_SIZE 1000000
#define TRUE 1
#define FALSE 0

// Find and replace
inline char *string_replace(char *target, char* find, char* replace_with) {
	char *result;
	register int i, count = 0;
	int oldlen = length_pointer_char(find);
	int newlen = length_pointer_char(replace_with);
	for (i = 0; target[i] != '\0'; i++) {
		if (strstr(&target[i], find) == &target[i]) {
			count++;
			i += oldlen - 1;
		}
	}
	result = (char*) malloc(i + count * (newlen - oldlen));
	if (result == NULL) {
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (*target)
	{
		if (strstr(target, find) == target)
		{
			strcpy(&result[i], replace_with);
			i += newlen;
			target += oldlen;
		} else result[i++] = *target++;
	}
	result[i] = '\0';
	return result;
}

// Split string to one dimession array by delimiter
inline char **string_split(char *target, const char *delim_) {
	char* delim = (char*) delim_;
	int len_target = length_pointer_char(target);
	int len_delim = length_pointer_char(delim);
	int distance = len_target - len_delim + 1;
	int len_item = 0;
	char *segment = calloc(len_delim, sizeof(char));
	char **data = malloc(MAX_SIZE * sizeof(char*));
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
	int num = length_pointer_pointer_char(target) - 1;
	int len = 0, wlen = 0;
	char *tmp = calloc(MAX_SIZE, sizeof(char));
	register int i;
	for (i=0; i<num; i++) {
		// Copy memory segment
		wlen = length_pointer_char(target[i]);
		memcpy(tmp + len, target[i], wlen);
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
    int target_length = length_pointer_char(target);
    int subtarget_length = length_pointer_char(subtarget);
    if (target_length < subtarget_length || (times == 0)) {
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
	int length = length_pointer_char(target);
	char *result = malloc((length + 1) * sizeof(char));
	memcpy(result, target, length);
	result[length] = '\0';
	return result;
}

char *string_upper(char *target) {
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
	char *result = string_copy(target);
	register char *index = result;
	if (length_pointer_char(index) > 0 && 'a' <= *index && *index <= 'z')  {
		*index = *index - 32;
	}
	char lastIndex = *index;
	index++;
	for (; *index; index++) {
		if (lastIndex == ' ' && 'a' <= *index && *index <= 'z') {
			*index = *index - 32;
		}
		lastIndex = *index;
	}
	return result;
}


