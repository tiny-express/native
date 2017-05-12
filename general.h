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

#ifndef NATIVE_GENERAL_H
#define NATIVE_GENERAL_H

#define _BOOL                   1
#define CHAR                    2
#define SHORT_INT               3
#define INT                     4
#define LONG_INT                5
#define LONG_LONG_INT           6
#define FLOAT                   7
#define LONG_DOUBLE             8
#define VOID_POINTER            9
#define UNSIGNED_CHAR           10
#define SIGNED_CHAR             11
#define UNSIGNED_SHORT_INT      12
#define UNSIGNED_INT            13
#define UNSIGNED_LONG_INT       14
#define UNSIGNED_LONG_LONG_INT  15
#define DOUBLE                  16
#define CHAR_POINTER            17
#define INT_POINTER             18
#define OTHER                   19

#define typename(x)  _Generic((x),                                            \
        _Bool: _BOOL,                  unsigned char: UNSIGNED_CHAR,          \
         char: CHAR,                     signed char: SIGNED_CHAR,            \
    short int: SHORT_INT,         unsigned short int: UNSIGNED_SHORT_INT,     \
          int: INT,                     unsigned int: UNSIGNED_INT,           \
     long int: LONG_INT,           unsigned long int: UNSIGNED_LONG_INT,      \
long long int: LONG_LONG_INT, unsigned long long int: UNSIGNED_LONG_LONG_INT, \
        float: FLOAT,                         double: DOUBLE,                 \
  long double: LONG_DOUBLE,                   char *: CHAR_POINTER,           \
       void *: VOID_POINTER,                   int *: INT_POINTER,            \
      default: OTHER)

char **append_pointer_char(char **target, char *append);

char *join_pointer_pointer_char(char **target);
char *join_delimiter_pointer_pointer_char(char **target, const char *delimiter);

int length_pointer_char(char *target);
int length_pointer_pointer_char(char **target);

int length_short(short target);
int length_int(int target);
int length_long(long target);
int length_double(double target);
int length_float(float target);

char *segment_pointer_char(char *target, int from, int to);
char **segment_pointer_pointer_char(char **target, int from, int to);
int linear_search(int array[], int length, int key);
int binary_search(int array[], int length, int key);

void distribution_counting_sort(int *array, int size);

void sort_int(int *array, int begin_array, int end_array);
void sort_long(long *array, int begin_array, int end_array);
void sort_short(short *array, int begin_array, int end_array);
void sort_float(float *array, int begin_array, int end_array);
//void sort_double(double array, int begin_array, int end_array);


int is_increase_int_array(int *array, int length);
int is_increase_float_array(float *array, int length);
int is_increase_double_array(double *array, int length);
int is_increase_long_array(long *array, int length);
int is_increase_short_array(short *array, int length);

int is_decrease_int_array(int *array, int length);
int is_decrease_float_array(float *array, int length);
int is_decrease_double_array(double *array, int length);
int is_decrease_long_array(long *array, int length);


#endif //NATIVE_GENERAL_H
