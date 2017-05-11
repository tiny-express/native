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

#include "../general.h"
#include "../type.h"
#include <stdlib.h>
#include <string.h>

/**
 * Distribution Counting Sort
 * Complexity O(M) with M is max value of array
 *
 * @param array
 * @param size
 */
void distribution_counting_sort(int *array, int size) {

    register int current;
    int max_value = 0;
    for (current = 0; current < size; ++current) {
        if (array[current] > max_value)
            max_value = array[current];
    }

    int * counting_array = calloc(max_value, sizeof(int));

    for(current = 0; current < size; current ++){
        counting_array[array[current]]++;
    }

    int num = 0;
    current = 0;

    while(current <= size) {
        while(counting_array[num] > 0) {
            array[current] = num;
            counting_array[num]--;
            current++;
            if(current > size){ break; }
        }
        num++;
    }
}

/**
 * Quick Sort
 * Complexity O(M*log(N))
 *
 * @param array
 * @param length
 * @param key
 * @return result
 */
#define QUICK_SORT(TYPE, TYPE_COMPARE)                                             \
inline void sort_##TYPE(TYPE *array, int left_position, int right_position) {       \
    int left = left_position;                                                      \
    int right = right_position;                                                    \
    TYPE pivot = array[(left + right) / 2];                                        \
    while (left <= right) {                                                        \
        while (compare_##TYPE_COMPARE(array[left], pivot) < 0)  left++;            \
        while (compare_##TYPE_COMPARE(array[right], pivot) > 0) right--;           \
        if (left <= right) {                                                       \
            TYPE tmp = array[left];                                                \
            array[right] = array[left];                                            \
            array[left] = tmp;                                                     \
            left++;                                                                \
            right--;                                                               \
        }                                                                          \
    }                                                                              \
    if (left_position < right) sort_##TYPE(array, left_position, right);           \
    if (left < right_position) sort_##TYPE(array, left, right_position);           \
}

#define COMPARE(TYPE)                                                   \
inline int compare_##TYPE(TYPE value1, TYPE value2) {                   \
	if (typename(value1) == "pointer to char") {                        \
		return (strcmp(value1, value2));	                            \
	}                                                                   \
                                                                        \
	return ((value1) - (value2));                                       \
}

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

INCREASE(int);
INCREASE(float);
INCREASE(double);
INCREASE(long);

DECREASE(int);
DECREASE(float);
DECREASE(double);
DECREASE(long);


QUICK_SORT(int, int);

//QUICK_SORT(pointer_float, float);
//QUICK_SORT(pointer_long, long);
//QUICK_SORT(pointer_double, double);
//QUICK_SORT(pointer_char, pointer_char);


COMPARE(int);

//COMPARE(int);
//COMPARE(float);
//COMPARE(long);
//COMPARE(double);



