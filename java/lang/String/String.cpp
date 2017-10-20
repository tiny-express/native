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

#include "String.hpp"
#include "../StringIndexOutOfBoundsException/StringIndexOutOfBoundsException.hpp"
#include "../StringBuilder/StringBuilder.hpp"
#include "../StringBuffer/StringBuffer.hpp"
#include "../IllegalArgumentException/IllegalArgumentException.hpp"

using namespace Java::Lang;

String::String() {
    this->original = (string) allocateMemory(DEFAULT_CAPACITY * sizeof(char));
    this->original[0] = '\0';
    this->size = 0;
    this->capacity = DEFAULT_CAPACITY;
}

String::String(string original, int length) {
    this->original = strndup(original, (size_t) length);
    this->size = length;
    this->capacity = this->size == 0 ? -1 : this->size;
}

String::String(Array<char> &charArray) {
    this->original = charArray.toString();
    this->size = charArray.length;
    this->capacity = this->size == 0 ? -1 : this->size;
}

String::String(Array<byte> &byteArray) {
    Array<char> chars;
    for (byte byte : byteArray) {
        chars.push((char) byte);
    }
    this->original = stringCopy(String::fromCharArray(chars).toString());
    this->size = chars.length;
    this->capacity = this->size == 0 ? -1 : this->size;
}

String::String(const String &target) {
    this->original = stringCopy(target.original);
    this->size = target.size;
    this->capacity = this->size == 0 ? -1 : this->size;
    this->hash = target.hash;
}

String::String(const StringBuilder &stringBuilder) {
    this->original = stringCopy(stringBuilder.toString());
    this->size = stringBuilder.length();
    this->capacity = this->size == 0 ? -1 : this->size;
}

String::String(const StringBuffer &stringBuffer) {
    this->original = stringCopy(stringBuffer.getValue());
    this->size = stringBuffer.length();
    this->capacity = this->size == 0 ? -1 : this->size;
}

String::String(Array<char> &array, int offset, int length) {
    STRING_CONSTRUCTOR_ARRAY
}

String::String(Array<byte> &array, int offset, int length) {
    STRING_CONSTRUCTOR_ARRAY
}

String::~String() {
    free(original);
}

int String::getSize() const {
    return this->size;
}

String String::clone() {
    string pointerHolder = stringCopy(this->original);
    String result = pointerHolder;
    free(pointerHolder);
    return result;
}

char String::charAt(int index) const {
    if (index < 0 || index > this->size - 1) {
        throw StringIndexOutOfBoundsException("String index out of range");
    }
    return (this->original[index]);
}

int String::compareTo(const String &anotherString) const {
    return strcmp(this->original, anotherString.original);
}

int String::compareToIgnoreCase(const String &anotherString) const {
    return strcasecmp(this->original, anotherString.original);
}

String String::concat(String target) {
    string targetValue = target.original;
    long targetLength = target.size;
    long newLength = this->size + target.size;
    STRING_OPERATOR_PLUS
    return *this;
}

boolean String::contains(const CharSequence &charSequence) {
    return (stringIndex(this->original, charSequence.toString(), 1) != NOT_FOUND);
}

Array<byte> String::getBytes() const {
    Array<byte> bytes;
    String originalString = this->original;
    for (char character : originalString.toCharArray()) {
        bytes.push((byte) character);
    }
    return bytes;
}

String String::getStringFromIndex(int index) const {
    if (index < 0 || index > this->size - 1) {
        throw StringIndexOutOfBoundsException(index);
    }
    return &(this->original[index]);
}

boolean String::endsWith(const String &suffixString) const {
    return (bool) stringEndswith(this->original, suffixString.original);
}

String String::fromCharArray(Array<char> &charArray) {
    string str = (string) allocateMemory((charArray.length + 1) * sizeof(char));
#ifdef LINUX
    register
#endif
    int index = 0;
    for (char character : charArray) {
        str[index++] = character;
    }
    str[index] = '\0';
    String result = str;
    free(str);
    return result;
}

int String::indexOf(int character) const {
    string pointerHolder = stringFromChar((char) character);
    int result = stringIndex(this->original, pointerHolder, 1);
    free(pointerHolder);
    return result;
}

int String::indexOf(int character, int fromIndex) const {
    if (fromIndex > this->size) {
        return -1;
    }
    if (fromIndex < 0) {
        return this->indexOf(character);
    }

#ifdef LINUX
    register
#endif
    int index = 0;

    for (index = fromIndex; index < this->size; index++) {
        if (this->original[index] == (char) character) {
            return index;
        }
    }
    return -1;
}

int String::indexOf(String subString) const {
    return stringIndex(this->original, subString.original, 1);
}

int String::indexOf(String subString, int fromIndex) const {
    if (fromIndex < 0) {
        return this->indexOf(subString);
    }
    if (fromIndex > this->size - 1) {
        return -1;
    }
    string stringFromIndex = stringFrom(this->original, fromIndex);
    int result = stringIndex(stringFromIndex, subString.original, 1);
    free(stringFromIndex);
    if (result == -1) {
        return result;
    }
    result = fromIndex + result;
    return result;
}

boolean String::isEmpty() const {
    return (boolean) isEmptyString(this->original);
}

int String::lastIndexOf(int character) {
#ifdef LINUX
    register
#endif
    int index = 0;

    for (index = this->size - 1; index >= 0; index--) {
        if (this->charAt(index) == (char) character) {
            return index;
        }
    }
    return -1;
}

int String::lastIndexOf(int character, int fromIndex) {
    if (fromIndex < 0) {
        return -1;
    }
    if (fromIndex > this->size - 1) {
        return this->lastIndexOf(character);
    }
#ifdef LINUX
    register
#endif
    int index = 0;

    for (index = fromIndex - 1; index >= 0; index--) {
        if (this->charAt(index) == (char) character) {
            return index;
        }
    }
    return -1;
}

int String::lastIndexOf(String subString) const {
    string reversedString = stringReverse(subString.toString());
    string currentReversedString = stringReverse(this->toString());
    int result = stringIndex(currentReversedString, reversedString, 1);
    free(reversedString);
    free(currentReversedString);
    if (result == NOT_FOUND) {
        return result;
    }
    // Re-calculate first character of subString
    result = this->size - (result + subString.size);
    return result;
}

int String::lastIndexOf(String subString, int fromIndex) const {
    if (fromIndex < 0) {
        return -1;
    }
    if (fromIndex > this->size - 1) {
        return this->lastIndexOf(subString);
    }
    string thisStringReversed = stringReverse(this->original);
    string subStringFromIndex = &(thisStringReversed)[this->size - fromIndex - subString.size];
    string reversedString = stringReverse(subString.toString());
    // string currentReversedString = stringReverse(subStringFromIndex);
    int result = stringIndex(subStringFromIndex, reversedString, 1);
    free(reversedString);
    free(thisStringReversed);
    if (result == NOT_FOUND) {
        return result;
    }
    // Re-calculate first character of str
    result = fromIndex - result;
    return result;
}


// boolean String::matches(String regex) const {
// 	int result = stringMatches(this->original, regex.toString());
// 	return result == true;
// }

String String::replace(char oldChar, char newChar) const {
    string oldString = stringFromChar(oldChar);
    string newString = stringFromChar(newChar);
    string pointerHolder = stringReplace(this->original, oldString, newString);
    String result = pointerHolder;
    free(pointerHolder);
    free(oldString);
    free(newString);
    return result;
}

String String::replaceAll(String regex, String replacement) const {
    // TODO (anhnt) fix this later, temporary use replace, need Pattern
    return replace(regex, replacement);
}

Array<String> String::split(String regex) const {
    // TODO (anhnt) fix this later, temporary use replace, need Pattern
    string *splitStrings = stringSplit(this->original, regex.toString());
    Array<String> strings;

#ifdef LINUX
    register
#endif
    int index = 0;

    int splitStringsLength = lengthPointerPointerChar(splitStrings);
    for (index = 0; index < splitStringsLength; index++) {
        strings.push(splitStrings[index]);
    }

    freePointerPointerChar(splitStrings);
    return strings;
}

boolean String::startsWith(String prefix) const {
    return (bool) stringStartswith(this->original, prefix.original);
}

boolean String::startsWith(String prefix, int thisOffset) const {
    if (this->original == nullptr ||
        prefix.original == nullptr || thisOffset < 0) {
        return false;
    }
    int originalLength = lengthPointerChar(this->original);
    int prefixLength = lengthPointerChar(prefix.original);
    if (originalLength < prefixLength ||
        thisOffset > (originalLength - prefixLength)) {
        return false;
    }
#ifdef LINUX
    register
#endif
    int firstIndex = 0;

#ifdef LINUX
    register
#endif
    int secondIndex = thisOffset;
    for (; firstIndex < prefixLength; firstIndex++) {
        if (prefix.original[firstIndex] != this->original[secondIndex]) {
            return false;
        }
        secondIndex++;
    }
    return true;
}

Array<char> String::toCharArray() const {
    Array<char> chars;

#ifdef LINUX
    register
#endif
    int index = 0;

    while (this->original[index] != '\0') {
        chars.push(this->original[index++]);
    }
    return chars;
}

string String::toString() const {
    return this->original;
}

String String::toLowerCase() const {
    string holdPointer = stringLower(this->original);
    String result = holdPointer;
    free(holdPointer);
    return result;
}

String String::toUpperCase() {
    string holdPointer = stringUpper(this->original);
    String result = holdPointer;
    free(holdPointer);
    return result;
}

String String::trim() {
    string holdPointer = stringTrim(this->original);
    String result = holdPointer;
    free(holdPointer);
    return result;
}

String String::valueOf(boolean target) {
    if (target) {
        return (string) "true";
    }
    return (string) "false";
}

String String::valueOf(char charValue) {
    string pointerHolder = stringFromChar(charValue);
    String result = pointerHolder;
    free(pointerHolder);
    return result;
}

String String::valueOf(string stringValue) {
    if (isEmptyString(stringValue) != 0) {
        return (string) "";
    }
    return stringValue;
}

String String::valueOf(short shortValue) {
    string pointerHolder = stringFromShort(shortValue);
    String result = pointerHolder;
    free(pointerHolder);
    return result;
}

String String::valueOf(int intValue) {
    string pointerHolder = stringFromInt(intValue);
    String result = pointerHolder;
    free(pointerHolder);
    return result;
}

String String::valueOf(long longValue) {
    string pointerHolder = stringFromLong(longValue);
    String result = pointerHolder;
    free(pointerHolder);
    return result;
}

String String::valueOf(float floatValue) {
    string pointerHolder = stringFromFloat(floatValue);
    String result = pointerHolder;
    free(pointerHolder);
    return result;
}

String String::valueOf(double doubleValue) {
    string pointerHolder = stringFromDouble(doubleValue);
    String result = pointerHolder;
    free(pointerHolder);
    return result;
}

String String::subString(int beginIndex) const {
    return this->subString(beginIndex, this->size);
}

String String::subString(int beginIndex, int endIndex) const {
    string holder = stringFromTo(this->original, beginIndex, endIndex - 1);
    String result = holder;
    free(holder);
    return result;
}

boolean String::contentEquals(const CharSequence &charSequence) {
    // TODO (anhnt) instanceof return false
/*    if (instanceof<StringBuffer>(&charSequence)) {
        std::mutex mutex;
        std::lock_guard<std::mutex> guard(mutex);
        return strcmp(this->original, charSequence.toString()) == 0;
    }*/
    return strcmp(this->original, charSequence.toString()) == 0;
}

String String::copyValueOf(Array<char> &charArray) {
    return String(charArray);
}

String String::copyValueOf(Array<char> &charArray, int offset, int count) {
    return String(charArray, offset, count);
}

boolean String::equalsIgnoreCase(String anotherString) {
    return this->compareToIgnoreCase(anotherString) == 0;
}

long String::hashCode() const {
    int hashCode = this->hash;
    if (hashCode == 0 && this->size > 0) {
        for (int i = 0; i < this->size; i++) {
            hashCode = 31 * hashCode + this->original[i];
        }
        this->hash = hashCode;
    }
    return hashCode;
}

boolean String::regionMatches(int thisOffset,
                              String otherString, int otherOffset, int len) {

    return this->regionMatches(false, thisOffset, otherString, otherOffset, len);
}

boolean String::regionMatches(boolean ignoreCase, int thisOffset,
                              String otherString, int otherOffset, int len) {

    String thisString = this->subString(thisOffset, thisOffset + len);
    otherString = otherString.subString(otherOffset, otherOffset + len);
    if (ignoreCase) {
        return thisString.compareToIgnoreCase(otherString) == 0;
    }
    return thisString.compareTo(otherString) == 0;
}

void String::getChars(int sourceBegin, int sourceEnd,
                      Array<char> &destination, int destinationBegin) {
    if (sourceBegin < 0) {
        throw StringIndexOutOfBoundsException(sourceBegin);
    }

    if (sourceBegin > sourceEnd) {
        throw StringIndexOutOfBoundsException(sourceEnd - sourceBegin);
    }

    if (sourceEnd > this->size) {
        throw StringIndexOutOfBoundsException(sourceEnd);
    }

    if (destinationBegin < 0) {
        throw StringIndexOutOfBoundsException(destinationBegin);
    }

    if (destinationBegin + (sourceEnd - sourceBegin) > destination.length) {
        throw StringIndexOutOfBoundsException(destinationBegin
                                              + (sourceEnd - sourceBegin));
    }

    int index;
    int len = sourceEnd - sourceBegin;
    for (index = 0; index < destinationBegin + len; index++) {
        if (index >= destinationBegin && index < destinationBegin + len) {
            destination[index] = this->charAt(sourceBegin);
            sourceBegin++;
        } else {
            destination[index] = destination[index];
        }
    }
}

String String::replace(CharSequence &target, CharSequence &replacement) const {
    string oldString = target.toString();
    string newString = replacement.toString();
    string pointerHolder = stringReplace(this->original, oldString, newString);
    String result = pointerHolder;
    free(pointerHolder);
    return result;
}

String String::replaceFirst(String regex, String replacement) const {
    // TODO (anhnt) fix this later, temporary, need Pattern
    int stringWithFirstRegexLength = this->indexOf(regex) + regex.length();
    String stringWithFirstRegex = this->subString(0, stringWithFirstRegexLength);
    String remainString = this->getStringFromIndex(stringWithFirstRegexLength);
    stringWithFirstRegex = stringWithFirstRegex.replace(regex, replacement);
    return stringWithFirstRegex + remainString;
}

Array<String> String::split(String regex, int limit) const {
    // TODO (anhnt) fix this later, temporary, need Pattern
    Array<String> stringArrayNoLimit = this->split(regex);
    if (limit == 1) {
        return Array<String>{*this};
    }
    if (limit > stringArrayNoLimit.length || limit <= 0) {
        return stringArrayNoLimit;
    }
    int indexOfRegexBelowLimit = stringIndex(this->original, regex.toString(), limit - 1);
    int remainStringLength = indexOfRegexBelowLimit + regex.length();
    String remainString = this->getStringFromIndex(remainStringLength);
    Array<String> stringArrayLimit;
#ifdef LINUX
    register
#endif
    int index;
    for (index = 0; index < limit - 1; index++) {
        stringArrayLimit.push(stringArrayNoLimit[index]);
    }
    stringArrayLimit.push(remainString);
    return stringArrayLimit;
}

String String::print(const String &format, short value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toString(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, int value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toString(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, long value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toString(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, unsigned short value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toString(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, unsigned int value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toString(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, unsigned long value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toString(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, double value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toString(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, float value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toString(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, string value) {
    String result;
    char *buffer = (char *) calloc(DEFAULT_BUFFER_LENGTH, sizeof(char));
    int length = snprintf(buffer, DEFAULT_BUFFER_LENGTH, format.toString(), value);

    if (length > DEFAULT_BUFFER_LENGTH) {
        free(buffer);
        buffer = (char *) calloc(++length, sizeof(char));
        length = snprintf(buffer, (size_t) length, format.toString(), value);
    }

    if (length > 0) {
        result = String(buffer, length);
    }

    free(buffer);
    return result;
}

String String::print(const String &format, Short value) {
    return String::print(format, value.shortValue());
}

String String::print(const String &format, Integer value) {
    return String::print(format, value.intValue());
}

String String::print(const String &format, Long value) {
    return String::print(format, value.longValue());
}

String String::print(const String &format, Float value) {
    return String::print(format, value.floatValue());
}

String String::print(const String &format, Double value) {
    return String::print(format, value.doubleValue());
}

String String::print(const String &format, String value) {
    return String::print(format, value.toString());
}

String String::format(const String &format) {
    const String pattern = "%([[:digit:]]+)?([-#+0 ]*)?([[:digit:]]+)?(\\" \
            ".[[:digit:]]+)?(l){0,2}([diuoxXfFeEgGaAcspn%])";
    String result;
    string inputStringPtr = format.toString();
    int inputStringLength = format.getSize();
    int inputStringOffset = 0;
    int errorCode = 0;
    regex_t regex;

    errorCode = regcomp(&regex, pattern.toString(), REG_EXTENDED);
    while (errorCode == 0 && inputStringOffset < format.getSize()) {
        regmatch_t matchedResult[16] = {0}; // max 16 groups
        errorCode = regexec(&regex, inputStringPtr, 16, matchedResult, 0);
        if (errorCode != 0) {
            result += String(inputStringPtr, inputStringLength);
            break;
        }

        int unmatchedStringLength = matchedResult[0].rm_so;
        int matchedStringLength = matchedResult[0].rm_eo - matchedResult[0].rm_so;

        if (unmatchedStringLength > 0) {
            result += String(inputStringPtr, unmatchedStringLength);
        }

        if (matchedStringLength > 0) {
            String matchedString(inputStringPtr + unmatchedStringLength, matchedStringLength);
            if (matchedString.charAt(matchedString.getSize() - 1) != '%') {
                regfree(&regex);
                throw IllegalArgumentException("Missing arguments.");
            } else {
                result += "%";
            }
        }

        inputStringPtr += matchedResult[0].rm_eo;
        inputStringOffset += matchedResult[0].rm_eo;
        inputStringLength -= matchedResult[0].rm_eo;
    }

    regfree(&regex);
    return result;
}

String String::valueOf(const_string constStringValue) {
    if (isEmptyString(constStringValue) != 0) {
        return (string) "";
    }
    return constStringValue;
}

String String::valueOf(String stringValue) {
    return stringValue;
}

