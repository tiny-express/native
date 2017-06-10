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
#include "../string.h"
#include "../common.h"

inline char *segment_pointer_char(char *target_param, int from, int to) {
        if (target_param == NULL) {
                return strdup("");
        }
        int length_target = length_pointer_char(target_param);
        if (from > to || from < 0 || from > length_target || to < 0) {
                return strdup("");
        }
        char *target = strdup(target_param);
        int length= to - from + 1;
        if (to >= length_target) {
                length = length_target - from + 1;
        }
	char *pointer = calloc(length + 2, sizeof(char));
        memcpy(pointer, &target[from], length);
        pointer[length] = '\0';
        return pointer;
}

inline char **segment_pointer_pointer_char(char **target, int from, int to) {
    int length_target = length_pointer_pointer_char(target);
        if (from > to || from < 0 || from > length_target || to < 0 || to > length_target) {
                return NULL;
        }
        char **pointer = calloc((to - from + 2), sizeof(char*));
        memcpy(pointer, &target[from], (to - from + 1) * sizeof(char*));
        return pointer;
}