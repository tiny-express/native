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

#ifndef NATIVE_STRING_H
#define NATIVE_STRING_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

char *string_from_char(char target);
char *string_from_short(short target);
char *string_from_int(int target);
char *string_from_long(long target);
char *string_from_double(double target);
char *string_from_float(float target);

char string_to_char(char *target);
short string_to_short(char *target);
int string_to_int(char *target);
long string_to_long(char *target);
double string_to_double(char *target);
float string_to_float(char *target);

char *string_replace(char *target, char *find, char *replace_with);
char **string_split(char *target, char *delimiter);
char *string_join(char **target, char *delimiter);
int string_index(char *target, char *subtarget, int times);
char *string_trim(char *target);
int string_startswith(char *target, char *prefix);
int string_endswith(char *target, char *suffix);
char *string_random(char *target, int size);
char *string_append(char **target, char subtarget);
char *string_concat(char *target, char *subtarget);
int string_equals(char *target1, char *target2);
char *string_concat_asm(char *target, char *subtarget);
char *string_reverse(char *target);
int string_matches(char *target, char *regex);

char *string_from_to(char *target, int from, int to);
char *string_from(char *target, int from);
char *string_to(char *target, int to);
char *string_copy(char *target);
char *string_upper(char *target);
char *string_lower(char *target);
char *string_title(char *target);
char *string_standardized(char *target);
int string_to_boolean(char *target);
char *string_from_boolean(int target);
char *url_encode(char *target);
char *url_decode(char *target);

char *find_param(char *name, char *params);
char *find_param_from_url(char *name, char *url);

void free_pointer_pointer_char(char **char_array);

#define CHAR_LIST "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
#define NUMBER_LIST "0123456789"

#endif

