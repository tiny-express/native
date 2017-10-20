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

#ifndef NATIVE_COMMON_SEGMENT_HPP
#define NATIVE_COMMON_SEGMENT_HPP

#include "../Builtin.hpp"

inline char *segmentPointerChar(char *targetParam, int from, int to) {
	if (targetParam == nullptr) {
		return stringCopy("");
	}
	int lengthTarget = lengthPointerChar(targetParam);
	if (from > to || from < 0 || from > lengthTarget || to < 0) {
		return stringCopy("");
	}
	char *target = stringCopy(targetParam);
	int length = to - from + 1;
	if (to >= lengthTarget) {
		length = lengthTarget - from + 1;
	}
	auto *pointer = (char *) calloc(length + 1, sizeof(char));
	memcpy(pointer, &target[ from ], length);
	free(target);
	pointer[ length ] = '\0';
	return pointer;
}

inline char **segmentPointerPointerChar(char **target, int from, int to) {
	int lengthTarget = lengthPointerPointerChar(target);
	if (from > to || from < 0 || from > lengthTarget || to < 0 || to > lengthTarget) {
		return nullptr;
	}
	auto **pointer = (char **) calloc(( to - from + 2 ), sizeof(char *));
	memcpy(pointer, &target[ from ], ( to - from + 1 ) * sizeof(char *));
	return pointer;
}

#endif