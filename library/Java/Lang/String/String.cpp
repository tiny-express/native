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

#include <algorithm>
#include <cstring>
#include <locale.h>
#include "String.hpp"
#include "../StringIndexOutOfBoundsException/StringIndexOutOfBoundsException.hpp"
#include "../StringBuilder/StringBuilder.hpp"
#include "../StringBuffer/StringBuffer.hpp"
#include "../IllegalArgumentException/IllegalArgumentException.hpp"

using namespace Java::Lang;

std::string wideStringToMultiByteString(const std::wstring& input) {
    char* buffer = new char[DEFAULT_BUFFER_LENGTH]();
    size_t len = wcstombs(buffer, input.c_str(), DEFAULT_BUFFER_LENGTH);
    std::string result;

    if (len != static_cast<std::size_t>(-1)) {
        if (len > DEFAULT_BUFFER_LENGTH) {
            delete[] buffer;
            ++len;
            buffer = new char[len]();
            len = wcstombs(buffer, input.c_str(), len);
        }
        result = std::string(buffer, buffer + len);
    }

    delete[] buffer;
    return result;
}

std::wstring multiByteStringToWideString(const std::string& input) {
    wchar_t* buffer = new wchar_t[DEFAULT_BUFFER_LENGTH]();
    std::size_t len = mbstowcs(buffer, input.c_str(), DEFAULT_BUFFER_LENGTH);
    std::wstring result;

    if (len != static_cast<std::size_t>(-1)) {
        if (len > DEFAULT_BUFFER_LENGTH) {
            delete[] buffer;
            ++len;
            buffer = new wchar_t[len]();
            len = mbstowcs(buffer, input.c_str(), len);
        }

        result = std::wstring(buffer, buffer + len);
    }

    delete[] buffer;
    return result;
}

std::string toUpper(const std::string& input) {
    setlocale(LC_CTYPE, "en_US.UTF-8");
    std::wstring wideString = multiByteStringToWideString(input);
    auto& f = std::use_facet<std::ctype<wchar_t>>(std::locale());
    std::transform(wideString.begin(), wideString.end(), wideString.begin(), towupper);
    return wideStringToMultiByteString(wideString);
}

std::string toLower(const std::string& input) {
    setlocale(LC_CTYPE, "en_US.UTF-8");
    std::wstring wideString = multiByteStringToWideString(input);
    auto& f = std::use_facet<std::ctype<wchar_t>>(std::locale());
    std::transform(wideString.begin(), wideString.end(), wideString.begin(), towlower);
    return wideStringToMultiByteString(wideString);
}

String::String() {
}

String::String(string original, int length) {
    this->original = std::string(original, original +  (size_t) length);
}

String::String(Array<char> charArray) {
    this->original.clear();
    this->original.shrink_to_fit();
    int i;
    for (i = 0; i<charArray.length; i++) {
        this->original += charArray[i];
    }
}

String::String(Array<byte> byteArray) {
    this->original.clear();
    this->original.shrink_to_fit();
    int i;
    for (i = 0; i < byteArray.length; i++) {
        this->original += byteArray[i];
    }
}

String::String(const String &target) {
    this->original = target.original;
    this->hash = target.hash;
}

String::String(const StringBuilder &stringBuilder) {
    this->original = std::string(stringBuilder.toString().toCharPointer());
}

String::String(const StringBuffer &stringBuffer) {
    this->original = std::string(stringBuffer.getValue().toCharPointer());
}

String::String(Array<char> array, int offset, int length) {
    if (offset < 0) {
        throw StringIndexOutOfBoundsException(offset);
    }
    if (length < 0) {
        throw StringIndexOutOfBoundsException(length);
    }
    if (offset > array.length - length) {
        throw StringIndexOutOfBoundsException(offset + length);
    }

    this->original.clear();
    this->original.shrink_to_fit();
    int i;
    for (i = offset; i < offset + length; ++i) {
        this->original.push_back(array[i]);
    }
}

String::String(Array<byte> array, int offset, int length) {
    if (offset < 0) {
        throw StringIndexOutOfBoundsException(offset);
    }
    if (length < 0) {
        throw StringIndexOutOfBoundsException(length);
    }
    if (offset > array.length - length) {
        throw StringIndexOutOfBoundsException(offset + length);
    }

    this->original.clear();
    this->original.shrink_to_fit();
    int i;
    for (i = offset; i < offset + length; i++) {
        this->original.push_back((char)array[i]);
    }
}

String::~String() {

}

int String::getSize() const {
    return this->original.size();
}

String String::clone() {
    return this->original;
}

char String::charAt(int index) const {
    if (index < 0 || index > this->original.size() - 1) {
        throw StringIndexOutOfBoundsException("String index out of range");
    }
    return (this->original[index]);
}

int String::compareTo(const String &anotherString) const {
    return strcmp(this->original.c_str(), anotherString.original.c_str());
}

int String::compareToIgnoreCase(const String &anotherString) const {
    return strcasecmp(this->original.c_str(), anotherString.original.c_str());
}

String String::concat(String target) {
    this->original += target.original;
    return *this;
}

boolean String::contains(const CharSequence &charSequence) {
    std::size_t found = this->original.find(charSequence.toString().toCharPointer());
    if (found != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

Array<byte> String::getBytes() const {
    Array<byte> bytes;
    for (int i = 0; i < this->original.size(); ++i) {
        bytes.push((byte)this->original.c_str()[i]);
    }
    return bytes;
}

String String::getStringFromIndex(int index) const {
    if (index < 0 || index > this->original.size() - 1) {
        throw StringIndexOutOfBoundsException(index);
    }
    return this->original.substr(index);
}

boolean String::endsWith(const String &suffixString) const {
    int suffixLength = suffixString.toString().length();
    int targetLength = this->original.size();
    if (targetLength < suffixLength) {
        return false;
    }
    int i;
    for (i = suffixLength - 1; i >= 0; i--) {
        if (suffixString[i] != this->original[targetLength - suffixLength + i]) {
            return false;
        }
    }
    return true;
}

String String::fromCharArray(Array<char> &charArray) {
    return String(charArray);
}

int String::indexOf(int character) const {
    string pointerHolder;
    char target = (char)character;
    if (target == '\0') {
        pointerHolder= strdup("");
    } else {
        auto *result = (char *) calloc(2, sizeof(char));
        result[0] = target;
        result[1] = '\0';
        pointerHolder=result;

    }
    std::size_t found = this->original.find(pointerHolder);
    free(pointerHolder);
    if (found != std::string::npos) {
        return found;
    } else {
        return NOT_FOUND;
    }
}

int String::indexOf(int character, int fromIndex) const {
    if (fromIndex > (int)this->original.size()) {
        return -1;
    }
    if (fromIndex < 0) {
        return this->indexOf(character);
    }

    int index = 0;
    for (index = fromIndex; index < this->original.size(); index++) {
        if (this->original[index] == (char) character) {
            return index;
        }
    }
    return -1;
}

int String::indexOf(String subString) const {
    std::size_t found = this->original.find(subString.original);
    if (found != std::string::npos) {
        return found;
    } else {
        return NOT_FOUND;
    }
}

int String::indexOf(String subString, int fromIndex) const {
    if (fromIndex < 0) {
        return this->indexOf(subString);
    }
    if (fromIndex > (this->original.size() - 1)||(this->original.size()) < (subString.original.size())){
        return -1;
    }
    std::string stringFromIndex=(this)->original.substr(fromIndex);
    std::size_t found = stringFromIndex.find(subString.original);
    if (found != std::string::npos) {
        return (found + fromIndex);
    } else {
        return -1;
    }
}

boolean String::isEmpty() const {
    return (boolean)this->original.empty();
}

int String::lastIndexOf(int character) {
    int index = 0;
    for (index = (int)this->original.size() - 1; index >= 0; index--) {
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
    if (fromIndex > this->original.size() - 1) {
        return this->lastIndexOf(character);
    }

    int index = 0;
    for (index = fromIndex - 1; index >= 0; index--) {
        if (this->charAt(index) == (char) character) {
            return index;
        }
    }
    return -1;
}

int String::lastIndexOf(String subString) const {
    String reversedString = subString;
    std::reverse(reversedString.original.begin(), reversedString.original.end());
    std::string currentReversedString = this->original;
    std::reverse(currentReversedString.begin(), currentReversedString.end());
    std::size_t found = currentReversedString.find(reversedString.original);
    if (found == std::string::npos) {
        return NOT_FOUND;
    }
    return((int)this->original.size()-(int)(found+subString.original.size()));
}

int String::lastIndexOf(String subString, int fromIndex) const {

    if (fromIndex < 0) {
        return -1;
    }
    if (fromIndex > this->original.size() - 1) {
        return this->lastIndexOf(subString);
    }
    std::string thisStringReversed = this->original;
    std::reverse(thisStringReversed.begin(), thisStringReversed.end());
    int indexToCreatSubString = this->original.size() - fromIndex - subString.length();
    if (indexToCreatSubString > this->original.size()) {
        return -1;
    }
    std::string subStringFromIndex = thisStringReversed.substr(indexToCreatSubString);
    std::string reversedString = subString.toCharPointer();
    std::reverse(reversedString.begin(), reversedString.end());
    int result = subStringFromIndex.find(reversedString);
    if (result == NOT_FOUND) {
        return result;
    }

    // Re-calculate first character of str
    result = fromIndex - result;
    return result;
}

String String::replace(char oldChar, char newChar) const {
    std::string copyString = (std::string)this->original;
    for (int index = 0; index < this->original.size(); index++)
        if(this->original[index] == oldChar) {
            copyString[index] = newChar;
        }
    return copyString;
}

String String::replaceAll(String regex, String replacement) const {
    // TODO (anhnt) fix this later, temporary use replace, need Pattern
    return replace(regex, replacement);
}

Array<String> String::split(String regex) const {
    // TODO (anhnt) fix this later, temporary use replace, need Pattern
    string *splitStrings = stringSplit(this->original.c_str(), regex.toCharPointer());
    Array<String> strings;

    int index = 0, splitStringsLength = lengthPointerPointerChar(splitStrings);
    for (index = 0; index < splitStringsLength; index++) {
        strings.push(splitStrings[index]);
    }

    freePointerPointerChar(splitStrings);
    return strings;
}

boolean String::startsWith(String prefix) const {
    if (this->original.c_str() == nullptr || prefix.original.c_str() == nullptr) {
        return false;
    }
    int lengthOriginal = this->original.size();
    int lengthPrefix = prefix.original.size();
    if (lengthOriginal < lengthPrefix){
        return false;
    }
    for (int index=0; index<lengthPrefix; index++)
    if (this->original[index] != prefix.original[index]){
        return false;
    }
    return true;
}

boolean String::startsWith(String prefix, int thisOffset) const {
    if (thisOffset < 0) {
        return false;
    }
    int originalLength = this->original.size();
    int prefixLength = prefix.original.size();
    if (originalLength < prefixLength || thisOffset > (originalLength - prefixLength)) {
        return false;
    }

    int firstIndex = 0, secondIndex = thisOffset;
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
    for(char c : this->original) {
        chars.push(c);
    }
    return chars;
}

string String::toCharPointer() const {
    return (char*)this->original.c_str();
}

String String::toString() const {
    return *this;
}

String String::toLowerCase() {
    return toLower(this->original);
}

String String::toUpperCase() {
    return toUpper(this->original);
}

String String::trim() {
    size_t first = this->original.find_first_not_of(' ');
    if (std::string::npos == first) {
        this->original = "";
        return *this;
    }
    size_t last = this->original.find_last_not_of(' ');
    this->original = this->original.substr(first, (last - first + 1));
    return *this;
}

String String::valueOf(boolean target) {
    if (target) {
        return (string) "true";
    }
    return (string) "false";
}

String String::valueOf(char charValue) {
    string pointerHolder;
    if (charValue == '\0') {
        pointerHolder= stringCopy("");
    } else {
        auto *result = (char *) calloc(2, sizeof(char));
        result[0] = charValue;
        result[1] = '\0';
        pointerHolder = result;
    }
    String output = pointerHolder;
    free(pointerHolder);
    return output;
}

String String::valueOf(string stringValue) {
    if (stringValue == nullptr) {
        return (string) "";
    }
    return stringValue;
}

String String::valueOf(short shortValue) {
    String result = std::to_string(shortValue);
    return result;
}

String String::valueOf(int intValue) {
    String result = std::to_string(intValue);
    return result;
}

String String::valueOf(long longValue) {
    String result = std::to_string(longValue);
    return result;
}

String String::valueOf(float floatValue) {
    std::ostringstream strCout;
    strCout << floatValue;
    std::string result = strCout.str();
    return result;
}

String String::valueOf(double doubleValue) {
    int precision = 15;
    string pointerHolder = (string) calloc(1079, sizeof(char));
    if (doubleValue == 0.0f && doubleValue < 0) {
        sprintf(pointerHolder, "-%.*f", precision, doubleValue);
    } else {
        sprintf(pointerHolder, "%.*f", precision, doubleValue);
    }
    String result = pointerHolder;
    free(pointerHolder);
    return result;
}

String String::subString(int beginIndex) const {
    return this->subString(beginIndex, (int)this->original.size());
}

String String::subString(int beginIndex, int endIndex) const {
    string holder = stringFromTo((char*)this->original.c_str(), beginIndex, endIndex - 1);
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
    return strcmp(this->original.c_str(), charSequence.toString().toCharPointer()) == 0;
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
    if (hashCode == 0 && this->original.size() > 0) {
        for (int i = 0; i < this->original.size(); i++) {
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

    if (sourceEnd > this->length()) {
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
    string pointerHolder = stringReplace(
            (char*)this->original.c_str(),
            target.toString().toCharPointer(),
            replacement.toString().toCharPointer()
    );
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
    int indexOfRegexBelowLimit = stringIndex(this->original.c_str(), regex.toCharPointer(), limit - 1);
    int remainStringLength = indexOfRegexBelowLimit + regex.length();
    String remainString = this->getStringFromIndex(remainStringLength);
    Array<String> stringArrayLimit;
    int index;
    for (index = 0; index < limit - 1; index++) {
        stringArrayLimit.push(stringArrayNoLimit[index]);
    }
    stringArrayLimit.push(remainString);
    return stringArrayLimit;
}

String String::print(const String &format, bool value) {
    if (format.original == "%b") {
        return (value ? "true" : "false");
    }
    if (format.original == "%B") {
        return (value ? "TRUE" : "FALSE");
    }
    return "";
}

String String::print(const String &format, short value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, int value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, long value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, unsigned short value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, unsigned int value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, unsigned long value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, double value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, float value) {
    String result;
    char buffer[DEFAULT_BUFFER_LENGTH] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.toCharPointer(), value);
    if (length > 0) {
        result = String(buffer, length);
    }
    return result;
}

String String::print(const String &format, char* value) {
    String result;
    auto buffer = (string)calloc(DEFAULT_BUFFER_LENGTH, sizeof(char));
    int length = snprintf(buffer, DEFAULT_BUFFER_LENGTH, format.toCharPointer(), value);

    if (length > DEFAULT_BUFFER_LENGTH) {
        free(buffer);
        buffer = (string) calloc(++length, sizeof(char));
        length = snprintf(buffer, (size_t)length, format.toCharPointer(), value);
    }

    if (length > 0) {
        result = String(buffer, length);
    }

    free(buffer);
    return result;
}

String String::print(const String &format, const char* value) {
    String result;
    auto buffer = (string)calloc(DEFAULT_BUFFER_LENGTH, sizeof(char));
    int length = snprintf(buffer, DEFAULT_BUFFER_LENGTH, format.toCharPointer(), value);

    if (length > DEFAULT_BUFFER_LENGTH) {
        free(buffer);
        buffer = (string) calloc(++length, sizeof(char));
        length = snprintf(buffer, (size_t)length, format.toCharPointer(), value);
    }

    if (length > 0) {
        result = String(buffer, length);
    }

    free(buffer);
    return result;
}

String String::print(const String &format, Boolean value) {
    return print(format, value.booleanValue());
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
            ".[[:digit:]]+)?(l){0,2}([diuoxXfFeEgGaAcspnbB%])";
    String result;
    string inputStringPtr = format.toCharPointer();
    int inputStringLength = format.getSize();
    int inputStringOffset = 0;
    int errorCode = 0;
    regex_t regex;

    errorCode = regcomp(&regex, pattern.toCharPointer(), REG_EXTENDED);
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