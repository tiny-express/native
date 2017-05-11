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


#define typename(x) _Generic((x),                                                 \
                                                                                  \
        _Bool: "_Bool",                  unsigned char: "unsigned char",          \
         char: "char",                     signed char: "signed char",            \
    short int: "short int",         unsigned short int: "unsigned short int",     \
          int: "int",                     unsigned int: "unsigned int",           \
     long int: "long int",           unsigned long int: "unsigned long int",      \
long long int: "long long int", unsigned long long int: "unsigned long long int", \
        float: "float",                         double: "double",                 \
  long double: "long double",                    char*: "pointer to char",        \
       void *: "pointer to void",                int *: "pointer to int",         \
      default: "other")

char **append_pointer_char(char **target, char *append);

char *join_pointer_pointer_char(char **target);
char *join_delim_pointer_pointer_char(char **target, const char *delim);

int length_pointer_char(char *target);
int length_pointer_pointer_char(char **target);

int length_short(short target);
int length_int(int target);
int length_long(long target);
int length_double(double target);
int length_float(float target);

char *segment_pointer_char(char *target, int from, int to);
char **segment_pointer_pointer_char(char **target, int from, int to);
int linear_search(int array[], int lenght, int key);
int binary_search(int array[], int lenght, int key);

void distribution_counting_sort(int *array, int size);

void sort_int(int *array, int begin_array, int end_array);
//void sort_float(pointer_float array, int begin_array, int end_array);
//void sort_double(pointer_double array, int begin_array, int end_array);
//void sort_long(pointer_long array, int begin_array, int end_array);
//void sort_string(pointer_char array, int begin_array, int end_array);

int is_increase_int_array(int *array, int length);
int is_increase_float_array(float *array, int length);
int is_increase_double_array(double *array, int length);
int is_increase_long_array(long *array, int length);

int is_decrease_int_array(int *array, int length);
int is_decrease_float_array(float *array, int length);
int is_decrease_double_array(double *array, int length);
int is_decrease_long_array(long *array, int length);

//int compare_pointer_char(char *value1, char *value2);
int compare_int(int value1, int value2);
int compare_float(float value1, float value2);
int compare_double(double value1, double value2);
int compare_long(long value1, long value2);

#endif //NATIVE_GENERAL_H
