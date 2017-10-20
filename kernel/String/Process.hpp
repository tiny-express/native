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

#ifndef NATIVE_KERNEL_STRING_PROCESS_HPP
#define NATIVE_KERNEL_STRING_PROCESS_HPP

#include "../Common/Segment.hpp"

/**
 * String replace
 * Find a string in target and replace it by replaceWith
 *
 * @param target
 * @param findString
 * @param replaceWith
 * @return string
 */
inline char *stringReplace(char *target, const char *findString, const char *replaceWith) {
	if (target == nullptr || findString == nullptr || replaceWith == nullptr) {
		return stringCopy("");
	}
	char *result;
	int i, count = 0;
	int newLength = lengthPointerChar(replaceWith);
	int oldLength = lengthPointerChar(findString);
	
	for (i = 0; target[ i ] != '\0'; i++) {
		if (strstr(&target[ i ], findString) == &target[ i ]) {
			count++;
			i += oldLength - 1;
		}
	}
	result = (char *)allocateMemory((size_t) i + 1 + count * ( newLength - oldLength ));
	
	i = 0;
	while (*target) {
		if (strstr(target, findString) == target) {
			strcpy(&result[ i ], replaceWith);
			i += newLength;
			target += oldLength;
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
inline char **stringSplit(const char *target, const char *delimiter) {
	if (target == nullptr || delimiter == nullptr) {
		auto **result = (char **) calloc(1, sizeof(char *));
		return result;
	}
	auto **data = (char **) calloc(MAX_STRING_LENGTH, sizeof(char *));
	const int targetLength = lengthPointerChar(target);
	char const_target[targetLength + 1];
	strncpy(const_target, target, (size_t) targetLength);
	const_target[ targetLength ] = '\0';
	char *item = strtok(const_target, delimiter);
	register int count = 0;
	while (item != nullptr) {
		data[ count++ ] = stringCopy(item);
		item = strtok(nullptr, delimiter);
	}
	auto **result = (char **) calloc((size_t) count + 1, sizeof(char *));
	memcpy(result, data, count * sizeof(char *));
	result[ count ] = nullptr;
	free(data);
	return result;
}

/**
 * Free pointer pointer char
 *
 * @param charArray
 */
inline void freePointerPointerChar(char **charArray) {
	if (charArray == nullptr) {
		return;
	}
	int length = lengthPointerPointerChar(charArray);
	register int index;
	for (index = length - 1; index >= 0; index--) {
		free(charArray[ index ]);
	}
	free(charArray);
}

/**
 * String join
 *
 * @param target
 * @param delimiter
 * @return string
 */
inline char *stringJoin(char *target[], const char *delimiter) {
	if (target == nullptr || delimiter == nullptr) {
		return nullptr;
	}
	int num = lengthPointerPointerChar(target) - 1;
	int len = 0, wlen = 0;
	auto *tmp = (char*) calloc(MAX_STRING_LENGTH, sizeof(char));
#ifdef LINUX
	register
#endif
    int index;
	for (index = 0; index < num; index++) {
		// Copy memory segment
		wlen = lengthPointerChar(target[index]);
		memcpy(tmp + len, target[ index ], (size_t) wlen);
		len += wlen;
		// Copy memory segment
		wlen = lengthPointerChar(delimiter);
		memcpy(tmp + len, delimiter, (size_t) wlen);
		len += wlen;
	}
	// Copy memory segment
	wlen = lengthPointerChar(target[num]);
	memcpy(tmp + len, target[ num ], (size_t) wlen);
	len += wlen;
	len += 1;
	// Saving memory
	auto *result = (char *) calloc((size_t) len + 1, sizeof(char));
	memcpy(result, tmp, (size_t) len);
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
inline char *stringTrim(const char *target) {
	if (target == nullptr) {
		return nullptr;
	}
	int len, left, right;
	left = 0;
	right = lengthPointerChar(target) - 1;
	while (target[ left ] == ' ')
		left++;
	while (target[ right ] == ' ')
		right--;
	len = right - left + 1;
	auto *result = (char *)calloc((size_t) len + 1, sizeof(char));
	strncpy(result, &target[ left ], (size_t) len);
	return result;
}

/**
 * String start withs a prefix
 *
 * @param target
 * @param prefix
 * @return true | false
 */
inline boolean stringStartswith(const char *target, const char *prefix) {
	if (target == nullptr || prefix == nullptr) {
		return false;
	}
	int targetLength = lengthPointerChar(target);
	int prefix_length = lengthPointerChar(prefix);
	if (targetLength < prefix_length) {
		return false;
	}
	register int i;
	for (i = 0; i < prefix_length; i++) {
		if (prefix[ i ] != target[ i ]) {
			return false;
		}
	}
	return true;
}

/**
 * String end withs a suffix
 *
 * @param target
 * @param suffix
 * @return true | false
 */
inline boolean stringEndswith(const char *target, const char *suffix) {
	if (target == nullptr || suffix == nullptr) {
		return false;
	}
	int targetLength = lengthPointerChar(target);
	int suffix_length = lengthPointerChar(suffix);
	if (targetLength < suffix_length) {
		return false;
	}
	register int i;
	for (i = suffix_length - 1; i >= 0; i--) {
		if (suffix[ i ] != target[ targetLength - suffix_length + i ]) {
			return false;
		}
	}
	return true;
}

/**
 * String index
 *
 * @param target
 * @param subTarget
 * @param times
 * @return position
 */
inline int stringIndex(const char *target, const char *subTarget, int times) {
	if (isEmptyString((string) target) || isEmptyString((string) subTarget) || ( times <= 0 )) {
		return NOT_FOUND;
	}
	
	int targetLength = lengthPointerChar(target);
	int subTargetLength = lengthPointerChar(subTarget);
	
	if (targetLength == 0 || subTargetLength == 0 || targetLength < subTargetLength || ( times == 0 )) {
		return NOT_FOUND;
	}

#ifdef LINUX
	register
#endif
    int indexTarget, indexSubTarget, count_times = 0, position_result;
	for (indexTarget = 0; indexTarget <= ( targetLength - subTargetLength ); indexTarget++) {
		if (target[ indexTarget ] != subTarget[ 0 ]) {
			continue;
		}
		for (indexSubTarget = 1; indexSubTarget < subTargetLength; indexSubTarget++) {
			if (target[ indexTarget + indexSubTarget ] != subTarget[ indexSubTarget ]) {
				break;
			}
		}
		if (indexSubTarget == subTargetLength) {
			position_result = indexTarget;
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
inline char *stringRandom(char *target, int size) {
	if (isEmptyString(target)) {
		return nullptr;
	}
	int targetLength = lengthPointerChar(target);
	auto *result = (char *)calloc((size_t) size + 1, sizeof(char));
#ifdef LINUX
    register
#endif
	  int i;
	for (i = 0; i < size; i++) {
		result[ i ] = target[ rand() % targetLength ];
	}
	result[ size ] = '\0';
	return result;
}

/**
 * Append a character into a string
 *
 * @param target
 * @param subTarget
 * @return string
 */
inline char *stringAppend(char **target, char subTarget) {
	int length = asprintf(target, "%s%c", *target, subTarget);
	if (length <= 0) {
		return nullptr;
	}
	return *target;
}

/**
 * String concatenation
 *
 * @param target
 * @param subTarget
 * @return string
 */
inline char *stringConcat(char *target, char *subTarget) {
	if (isEmptyString(target)) {
		return stringCopy(subTarget);
	}
	if (isEmptyString(subTarget)) {
		return stringCopy(target);
	}
	int targetLength = lengthPointerChar(target);
	int subTargetLength = lengthPointerChar(subTarget);
	auto *result = (char *)calloc((size_t) targetLength + subTargetLength + 1, sizeof(char));
	memcpy(result, target, (size_t) targetLength);
	memcpy(result + targetLength, subTarget, (size_t) subTargetLength);
	result[ targetLength + subTargetLength ] = '\0';
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
inline char *stringFromTo(char *target, int from, int to) {
	return segmentPointerChar(target, from, to);
}

/**
 * Substring from a position to end of string
 *
 * @param target
 * @param from
 * @return
 */
inline char *stringFrom(char *target, int from) {
	return stringFromTo(target, from, lengthPointerChar(target));
}

/**
 * String from a position
 *
 * @param target
 * @param to
 * @return
 */
inline char *stringTo(char *target, int to) {
	return stringFromTo(target, 0, to);
}

/**
 * String upper
 *
 * @param target
 * @return string
 */
inline char *stringUpper(char *target) {
	if (isEmptyString(target)) {
		return nullptr;
	}
	char *result = stringCopy(target);
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
inline char *stringLower(char *target) {
	if (isEmptyString(target)) {
		return nullptr;
	}
	char *result = stringCopy(target);
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
inline char *stringTitle(char *target) {
	if (isEmptyString(target)) {
		return nullptr;
	}
	char *result = stringCopy(target);
	register char *index = result;
	if (lengthPointerChar(index) > 0 && 'a' <= *index && *index <= 'z') {
		*index -= 32;
	}
	char lastIndex = *index;
	index++;
	for (; *index; index++) {
		if (lastIndex == ' ' && 'a' <= *index && *index <= 'z') {
			*index -= 32;
		}
		lastIndex = *index;
	}
	return result;
}

/**
 * Standardized string
 *
 * @param target
 * @return string
 */
inline char *stringStandardized(char *target) {
	if (isEmptyString(target)) {
		return nullptr;
	}
	char **segments = stringSplit(target, (string) " ");
	char *result = stringJoin(segments, (string) " ");
	result[lengthPointerChar(result) ] = '\0';
	freePointerPointerChar(segments);
	return result;
}

/**
 * Check two string equals or not
 *
 * @param target1
 * @param target2
 * @return true | false
 */
inline boolean stringEquals(const char *target1, const char *target2) {
	if (( target1 == nullptr) && ( target2 == nullptr)) {
		return true;
	}
	if (( target1 == nullptr) || ( target2 == nullptr)) {
		return false;
	}
	return strcmp(target1, target2) == 0;
}

/**
 * Reverse a string
 *
 * @param target
 * @return string reversed
 */
inline char *stringReverse(char *target) {
	int targetLength = lengthPointerChar(target);
	auto *result = (char *) calloc((size_t) targetLength + 1, sizeof(char));
#ifdef LINUX
	register
#endif
	int index;
	for (index = 0; index < targetLength; index++) {
		result[ index ] = target[ targetLength - index - 1 ];
	}
	result[ targetLength ] = '\0';
	return result;
}

#endif//NATIVE_KERNEL_STRING_PROCESS_HPP