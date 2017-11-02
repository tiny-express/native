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

String::String(string original, long int length) {
    this->original = strndup(original, (size_t) length);
    this->size = length;
    this->capacity = this->size == 0 ? -1 : this->size;
}

String::String(Array<char> &charArray) {
    this->original = (string) malloc(charArray.length + 1);
#ifdef LINUX
    register
#endif
    long int i;
    for (i = 0; i < charArray.length; i++) {
        this->original[i] = charArray[i];
    }
    this->original[charArray.length] = '\0';
    this->size = charArray.length;
    this->capacity = this->size == 0 ? -1 : this->size;
}

String::String(Array<byte> &byteArray) {
    Array<char> chars;
    for (byte byte : byteArray) {
        chars.push((char) byte);
    }
    this->original = stringCopy(String::fromCharArray(chars).toCharPointer());
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
    this->original = stringCopy(stringBuilder.toString().toCharPointer());
    this->size = stringBuilder.length();
    this->capacity = this->size == 0 ? -1 : this->size;
}

String::String(const StringBuffer &stringBuffer) {
    this->original = stringCopy(stringBuffer.getValue().toCharPointer());
    this->size = stringBuffer.length();
    this->capacity = this->size == 0 ? -1 : this->size;
}

String::String(Array<char> &array, long int offset, long int length) {
    STRING_CONSTRUCTOR_ARRAY
}

String::String(Array<byte> &array, long int offset, long int length) {
    STRING_CONSTRUCTOR_ARRAY
}

String::~String() {
    free(original);
}

long int String::getSize() const {
    return this->size;
}

String String::clone() {
    string resultHolder = stringCopy(this->original);
    String result = resultHolder;
    free(resultHolder);
    return result;
}

char String::charAt(long int index) const {
    if (index < 0 || index > this->size - 1) {
        throw StringIndexOutOfBoundsException("String index out of range");
    }
    return (this->original[index]);
}

long int String::compareTo(const String &anotherString) const {
    return strcmp(this->original, anotherString.original);
}

long int String::compareToIgnoreCase(const String &anotherString) const {
    return strcasecmp(this->original, anotherString.original);
}

String String::concat(String target) {
    string targetValue = target.original;
    long long targetLength = target.size;
    long long newLength = this->size + target.size;
    STRING_OPERATOR_PLUS
    return *this;
}

boolean String::contains(const CharSequence &charSequence) {
    return (stringIndex(this->original, charSequence.toString().toCharPointer(), 1) != NOT_FOUND);
}

Array<byte> String::getBytes() const {
    Array<byte> bytes;
    String originalString = this->original;
    for (char character : originalString.toCharArray()) {
        bytes.push((byte) character);
    }
    return bytes;
}

String String::getStringFromIndex(long int index) const {
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
    long int index = 0;
    for (char character : charArray) {
        str[index++] = character;
    }
    str[index] = '\0';
    String result = str;
    free(str);
    return result;
}

long int String::indexOf(long int character) const {
    string resultHolder = stringFromChar((char) character);
    long int result = stringIndex(this->original, resultHolder, 1);
    free(resultHolder);
    return result;
}

long int String::indexOf(long int character, long int fromIndex) const {
    if (fromIndex > this->size) {
        return -1;
    }
    if (fromIndex < 0) {
        return this->indexOf(character);
    }

#ifdef LINUX
    register
#endif
    long int index = 0;

    for (index = fromIndex; index < this->size; index++) {
        if (this->original[index] == (char) character) {
            return index;
        }
    }
    return -1;
}

long int String::indexOf(String subString) const {
    return stringIndex(this->original, subString.original, 1);
}

long int String::indexOf(String subString, long int fromIndex) const {
    if (fromIndex < 0) {
        return this->indexOf(subString);
    }
    if (fromIndex > this->size - 1) {
        return -1;
    }
    string stringFromIndex = stringFrom(this->original, fromIndex);
    long int result = stringIndex(stringFromIndex, subString.original, 1);
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

long int String::lastIndexOf(long int character) {
#ifdef LINUX
    register
#endif
    long int index = 0;

    for (index = this->size - 1; index >= 0; index--) {
        if (this->charAt(index) == (char) character) {
            return index;
        }
    }
    return -1;
}

long int String::lastIndexOf(long int character, long int fromIndex) {
    if (fromIndex < 0) {
        return -1;
    }
    if (fromIndex > this->size - 1) {
        return this->lastIndexOf(character);
    }
#ifdef LINUX
    register
#endif
    long int index = 0;

    for (index = fromIndex - 1; index >= 0; index--) {
        if (this->charAt(index) == (char) character) {
            return index;
        }
    }
    return -1;
}

long int String::lastIndexOf(String subString) const {
    string reversedString = stringReverse(subString.toCharPointer());
    string currentReversedString = stringReverse(this->toCharPointer());
    long int result = stringIndex(currentReversedString, reversedString, 1);
    free(reversedString);
    free(currentReversedString);
    if (result == NOT_FOUND) {
        return result;
    }
    // Re-calculate first character of subString
    result = this->size - (result + subString.size);
    return result;
}

long int String::lastIndexOf(String subString, long int fromIndex) const {
    if (fromIndex < 0) {
        return -1;
    }
    if (fromIndex > this->size - 1) {
        return this->lastIndexOf(subString);
    }
    string thisStringReversed = stringReverse(this->original);
    string subStringFromIndex = &(thisStringReversed)[this->size - fromIndex - subString.size];
    string reversedString = stringReverse(subString.toCharPointer());
    // string currentReversedString = stringReverse(subStringFromIndex);
    long int result = stringIndex(subStringFromIndex, reversedString, 1);
    free(reversedString);
    free(thisStringReversed);
    if (result == NOT_FOUND) {
        return result;
    }
    // Re-calculate first character of str
    result = fromIndex - result;
    return result;
}

String String::replace(char oldChar, char newChar) const {
    string oldString = stringFromChar(oldChar);
    string newString = stringFromChar(newChar);
    string resultHolder = stringReplace(this->original, oldString, newString);
    String result = resultHolder;
    free(resultHolder);
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
    string *splitStrings = stringSplit(this->original, regex.toCharPointer());
    Array<String> strings;

#ifdef LINUX
    register
#endif
    long int index = 0;

    long int splitStringsLength = lengthPointerPointerChar(splitStrings);
    for (index = 0; index < splitStringsLength; index++) {
        strings.push(splitStrings[index]);
    }

    freePointerPointerChar(splitStrings);
    return strings;
}

boolean String::startsWith(String prefix) const {
    return (bool) stringStartswith(this->original, prefix.original);
}

boolean String::startsWith(String prefix, long int thisOffset) const {
    if (this->original == nullptr ||
        prefix.original == nullptr || thisOffset < 0) {
        return false;
    }
    long int originalLength = lengthPointerChar(this->original);
    long int prefixLength = lengthPointerChar(prefix.original);
    if (originalLength < prefixLength ||
        thisOffset > (originalLength - prefixLength)) {
        return false;
    }
#ifdef LINUX
    register
#endif
    long int secondIndex = thisOffset, firstIndex = 0;
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
    long int index = 0;

    while (this->original[index] != '\0') {
        chars.push(this->original[index++]);
    }
    return chars;
}

string String::toCharPointer() const {
    return this->original;
}

String String::toString() const {
    return *this;
}

String String::toLowerCase() const {
    string resultHolder = stringLower(this->original);
    String result = resultHolder;
    free(resultHolder);
    return result;
}

String String::toUpperCase() {
    string resultHolder = stringUpper(this->original);
    String result = resultHolder;
    free(resultHolder);
    return result;
}

String String::trim() {
    string resultHolder = stringTrim(this->original);
    String result = resultHolder;
    free(resultHolder);
    return result;
}

String String::valueOf(boolean target) {
    if (target) {
        return (string) "true";
    }
    return (string) "false";
}

String String::valueOf(char charValue) {
    string resultHolder = stringFromChar(charValue);
    String result = resultHolder;
    free(resultHolder);
    return result;
}

String String::valueOf(string stringValue) {
    if (isEmptyString(stringValue) != 0) {
        return (string) "";
    }
    return stringValue;
}

String String::valueOf(int shortValue) {
    string resultHolder = stringFromShort(shortValue);
    String result = resultHolder;
    free(resultHolder);
    return result;
}

String String::valueOf(long int intValue) {
    string resultHolder = stringFromInt(intValue);
    String result = resultHolder;
    free(resultHolder);
    return result;
}

String String::valueOf(long long longValue) {
    string resultHolder = stringFromLong(longValue);
    String result = resultHolder;
    free(resultHolder);
    return result;
}

String String::valueOf(float floatValue) {
    string resultHolder = stringFromFloat(floatValue);
    String result = resultHolder;
    free(resultHolder);
    return result;
}

String String::valueOf(double doubleValue) {
    string resultHolder = stringFromDouble(doubleValue);
    // Copy to result and free result holder
    String result = resultHolder;
    free(resultHolder);
    return result;
}

String String::subString(long int beginIndex) const {
    return this->subString(beginIndex, this->size);
}

String String::subString(long int beginIndex, long int endIndex) const {
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
    return strcmp(this->original, charSequence.toString().toCharPointer()) == 0;
}

String String::copyValueOf(Array<char> &charArray) {
    return String(charArray);
}

String String::copyValueOf(Array<char> &charArray, long int offset, long int count) {
    return String(charArray, offset, count);
}

boolean String::equalsIgnoreCase(String anotherString) {
    return this->compareToIgnoreCase(anotherString) == 0;
}

long long String::hashCode() const {
    long int hashCode = this->hash;
    if (hashCode == 0 && this->size > 0) {
        for (long int i = 0; i < this->size; i++) {
            hashCode = 31 * hashCode + this->original[i];
        }
        this->hash = hashCode;
    }
    return hashCode;
}

boolean String::regionMatches(long int thisOffset,
                              String otherString, long int otherOffset, long int len) {

    return this->regionMatches(false, thisOffset, otherString, otherOffset, len);
}

boolean String::regionMatches(boolean ignoreCase, long int thisOffset,
                              String otherString, long int otherOffset, long int len) {

    String thisString = this->subString(thisOffset, thisOffset + len);
    otherString = otherString.subString(otherOffset, otherOffset + len);
    if (ignoreCase) {
        return thisString.compareToIgnoreCase(otherString) == 0;
    }
    return thisString.compareTo(otherString) == 0;
}

void String::getChars(long int sourceBegin, long int sourceEnd,
                      Array<char> &destination, long int destinationBegin) {
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

    long int index;
    long int len = sourceEnd - sourceBegin;
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
    string resultHolder = stringReplace(
            this->original,
            target.toString().toCharPointer(),
            replacement.toString().toCharPointer()
    );
    String result = resultHolder;
    free(resultHolder);
    return result;
}

String String::replaceFirst(String regex, String replacement) const {
    // TODO (anhnt) fix this later, temporary, need Pattern
    long int stringWithFirstRegexLength = this->indexOf(regex) + regex.length();
    String stringWithFirstRegex = this->subString(0, stringWithFirstRegexLength);
    String remainString = this->getStringFromIndex(stringWithFirstRegexLength);
    stringWithFirstRegex = stringWithFirstRegex.replace(regex, replacement);
    return stringWithFirstRegex + remainString;
}

Array<String> String::split(String regex, long int limit) const {
    // TODO (anhnt) fix this later, temporary, need Pattern
    Array<String> stringArrayNoLimit = this->split(regex);
    if (limit == 1) {
        return Array<String>{*this};
    }
    if (limit > stringArrayNoLimit.length || limit <= 0) {
        return stringArrayNoLimit;
    }
    long int indexOfRegexBelowLimit = stringIndex(this->original, regex.toCharPointer(), limit - 1);
    long int remainStringLength = indexOfRegexBelowLimit + regex.length();
    String remainString = this->getStringFromIndex(remainStringLength);
    Array<String> stringArrayLimit;
#ifdef LINUX
    register
#endif
    long int index;
    for (index = 0; index < limit - 1; index++) {
        stringArrayLimit.push(stringArrayNoLimit[index]);
    }
    stringArrayLimit.push(remainString);
    return stringArrayLimit;
}

String String::print(const String &format, int value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const long int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, long int value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const long int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, long long value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const long int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, unsigned int value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const long int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, unsigned long int value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const long int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, unsigned long long value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const long int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, double value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const long int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, float value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const long int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, string value) {
    String result;
    auto buffer = (string) calloc(DEFAULT_BUFFER_LENGTH, sizeof(char));
    long int length = snprintf(buffer, DEFAULT_BUFFER_LENGTH, format.toCharPointer(), value);

    if (length > DEFAULT_BUFFER_LENGTH) {
        free(buffer);
        buffer = (string) calloc(++length, sizeof(char));
        length = snprintf(buffer, (size_t) length, format.toCharPointer(), value);
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
    return String::print(format, value.toCharPointer());
}

String String::format(const String &format) {
    const String pattern = "%([[:digit:]]+)?([-#+0 ]*)?([[:digit:]]+)?(\\" \
            ".[[:digit:]]+)?(l){0,2}([diuoxXfFeEgGaAcspn%])";
    String result;
    string inputStringPtr = format.toCharPointer();
    long int inputStringLength = format.getSize();
    long int inputStringOffset = 0;
    long int errorCode = 0;
    regex_t regex;

    errorCode = regcomp(&regex, pattern.toCharPointer(), REG_EXTENDED);
    while (errorCode == 0 && inputStringOffset < format.getSize()) {
        regmatch_t matchedResult[16] = {0}; // max 16 groups
        errorCode = regexec(&regex, inputStringPtr, 16, matchedResult, 0);
        if (errorCode != 0) {
            result += String(inputStringPtr, inputStringLength);
            break;
        }

        long int unmatchedStringLength = matchedResult[0].rm_so;
        long int matchedStringLength = matchedResult[0].rm_eo - matchedResult[0].rm_so;

        if (unmatchedStringLength > 0) {
            result += String(inputStringPtr, unmatchedStringLength);
        }

        if (matchedStringLength > 0) {
            String matchedString(inputStringPtr + unmatchedStringLength, matchedStringLength);
            if (matchedString.charAt(matchedString.getSize() - 1) != '%') {
                regfree(&regex);
                throw InterruptedException("Missing arguments.");
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

