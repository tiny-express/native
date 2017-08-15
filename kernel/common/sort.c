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

#include "../common.h"
#include "../type.h"
#include <string.h>

#define SWAP(value1, value2, TYPE) { TYPE temp = value1; value1 = value2; value2 = temp; }

/**
 * Quick Sort
 * Complexity O(M*log(N))
 *
 * @param array
 * @param length
 * @param key
 * @return result
 */
#define QUICK_SORT(TYPE)                                                           \
inline void sort_##TYPE(TYPE *array, int left_position, int right_position) {      \
    int left = left_position;                                                      \
    int right = right_position;                                                    \
    TYPE pivot = array[(left + right) / 2];                                        \
    while (left <= right) {                                                        \
        while (array[left] < pivot)  left++;                                       \
        while (array[right] > pivot) right--;                                      \
        if (left <= right) {                                                       \
            SWAP(array[left], array[right], TYPE);                                 \
            left++;                                                                \
            right--;                                                               \
        }                                                                          \
    }                                                                              \
    if (left_position < right) sort_##TYPE(array, left_position, right);           \
    if (left < right_position) sort_##TYPE(array, left, right_position);           \
}

void sort_string(char *array[], int left_position, int right_position) {
	int left = left_position;
	int right = right_position;
	char *pivot = array[ ( left + right ) / 2 ];
	
	while (left <= right) {
		while (strcmp(array[ left ], pivot) < 0)
			left++;
		while (strcmp(array[ right ], pivot) > 0)
			right--;
		if (left <= right) {
			char *temp = array[ left ];
			array[ left ] = array[ right ];
			array[ right ] = temp;
			left++;
			right--;
		}
	}
	if (left_position < right) {
		sort_string(array, left_position, right);
	}
	if (left < right_position) {
		sort_string(array, left, right_position);
	}
	
}

/**
 * Is increase string array
 *
 * @param array
 * @param size
 * @return TRUE | FALSE
 */
inline int is_increase_string_array(char **array, int size) {
	register int index = 0;
	for (index = 0; index < size - 1; index++) {
		if (strcmp(array[ index ], array[ index + 1 ]) > 0) {
			return FALSE;
		}
	}
	return TRUE;
}

/**
 * Is increase generic type array
 *
 * @param array
 * @param size
 * @return TRUE | FALSE
 */
#define INCREASE(TYPE)                                      \
int is_increase_##TYPE##_array(TYPE *array, int length) {   \
    register int index = 0;                                 \
    for (index = 0; index < length - 1; index++) {          \
        if (array[index] > array[index + 1])                \
            return FALSE;                                   \
    }                                                       \
    return TRUE;                                            \
}

#define DECREASE(TYPE)                                      \
int is_decrease_##TYPE##_array(TYPE *array, int length) {   \
    register int index = 0;                                 \
    for (index = 0; index < length - 1; index++) {          \
        if (array[index] < array[index + 1])                \
        return FALSE;                                       \
    }                                                       \
    return TRUE;                                            \
}

INCREASE(short);
INCREASE(int);
//INCREASE(long);
//INCREASE(float);
//INCREASE(double);
//
//DECREASE(short);
//DECREASE(int);
//DECREASE(long);
//DECREASE(float);
//DECREASE(double);
//
//QUICK_SORT(short);
QUICK_SORT(int);
//QUICK_SORT(long);
