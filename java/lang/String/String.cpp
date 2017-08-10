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


using namespace Java::Lang;

String::String() {
	this->original = strdup("\0");
	this->size = 0;
}

String::String(char target) {
	this->original = strdup((string) &target);
	this->size = 0;
}

String::String(const_string target) {
	this->original = strdup(target);
	this->size = length_pointer_char((string) target);
}

String::String(string target) {
	this->original = strdup(target);
	this->size = length_pointer_char(target);
}

String::String(Array<char> &charArray) {
	free(original);
	this->original = String::fromCharArray(charArray).toString();
	this->size = charArray.length;
}

String::String(Array<byte> &byteArray) {
	Array<char> chars;
	for (byte byte : byteArray) {
		chars.push((char) byte);
	}
	this->original = strdup(String::fromCharArray(chars).toString());
	this->size = chars.length;
}

String::String(const String &target) {
	this->original = strdup(target.original);
	this->size = target.size;
}

String::String(const std::string &target) {
	this->original = (string) strdup(target.c_str());
	this->size = (int) target.size();
}

String::String(const StringBuilder &stringBuilder) {
    this->original = strdup(stringBuilder.toString());
    this->size = stringBuilder.length();
}

String::String(const StringBuffer &stringBuffer) {
    /*this->original = strdup(stringBuffer.getValue());
    this->size = stringBuffer.length();*/
}

String::~String() {
	free(original);
}

int String::getSize() const {
	return this->size;
}

String String::clone() {
	string pointerHolder = strdup(this->original);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

char String::charAt(int index) const{
	if(index < 0 || index > this->size - 1) {
		throw StringIndexOutOfBoundsException("String index out of range");
	}
	return (this->original[index]);
}

int String::compareTo(const String &anotherString) const {
	string anotherStringValue = anotherString.toString();
	if (string_equals(this->original, anotherStringValue)) {
		return 0;
	}
	return 0;
}

int String::compareToIgnoreCase(String targetString) const {
	// TODO
	return 0;
}

String String::concat(String str) {
	string stringConcat = string_concat(this->original, str.original);
	String result(stringConcat);
	free(stringConcat);
	return result;
}

boolean String::contains(const CharSequence &charSequence) {
	return ( string_index(this->original, charSequence.toString(), 1) != NOT_FOUND );
}

Array<byte> String::getBytes() const {
	Array<byte> bytes;
	String originalString = this->original;
	for (char character : originalString.toCharArray()) {
		bytes.push((byte) character);
	}
	return bytes;
}

String String::getStringFromIndex(int index) {
	if (index < 0 || index > this->size - 1) {
		throw StringIndexOutOfBoundsException("String index out of range");
	}
	return &(this->original[index]);
}

boolean String::endsWith(const String &suffixString) const {
	return ( string_endswith(this->original, suffixString.original));
}

String String::fromCharArray(Array<char> &charArray) {
	string str = (string) calloc((size_t) charArray.length + 1, sizeof(char));
#ifdef __linux__
	register
#endif
	int index = 0;

	for (char character : charArray) {
		str[ index++ ] = character;
	}
	str[index] = '\0';
	String result = str;
	free(str);
	return result;
}

int String::indexOf(int character) const {
	string pointerHolder = string_from_char((char) character);
	int result = string_index(this->original, pointerHolder, 1);
	free(pointerHolder);
	return result;
}

int String::indexOf(int character, int fromIndex) const {
	if (fromIndex > this->size) {
		return -1;
	}

#ifdef __linux__
	register
#endif
	int index = 0;

	for (index = fromIndex; index < this->size; index++) {
		if (this->original[ index ] == (char) character) {
			return index;
		}
	}
	return -1;
}

int String::indexOf(String subString) const {
	return string_index(this->original, subString.original, 1);
}

int String::indexOf(String subString, int fromIndex) const {
    // TODO
	return 0;
}

boolean String::isEmpty() const {
	return (boolean) is_empty(this->original);
}

int String::lastIndexOf(int character) {
#ifdef __linux__
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
#ifdef __linux__
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
	string reversedString = string_reverse(subString.toString());
	string currentReversedString = string_reverse(this->toString());
	int result = string_index(currentReversedString, reversedString, 1);
	free(reversedString);
	free(currentReversedString);
	if (result == NOT_FOUND) {
		return result;
	}
	//Re-calculate first character of subString
	result = this->size - ( result + subString.size );
	return result;
}

int String::lastIndexOf(String subString, int fromIndex) const {
	string subStringFromIndex = &( this->original )[ fromIndex ]; // get subString start fromIndex
	string reversedString = string_reverse(subString.toString());
	string currentReversedString = string_reverse(subStringFromIndex);
	int result = string_index(currentReversedString, reversedString, 1);
	free(reversedString);
	free(currentReversedString);
	if (result == NOT_FOUND) {
		return result;
	}
	// Re-calculate first character of str
	result = this->size - ( result + subString.size );
	return result;

}

int String::length() const {
	return this->size;
}

boolean String::matches(String regex) const {
	int result = string_matches(this->original, regex.toString());
	return result == TRUE;
}

String String::replace(char oldChar, char newChar) const {
	string oldString = string_from_char(oldChar);
	string newString = string_from_char(newChar);
	string pointerHolder = string_replace(this->original, oldString, newString);
	String result = pointerHolder;
	free(pointerHolder);
	free(oldString);
	free(newString);
	return result;
}

String String::replaceAll(String regex, String replacement) const {
	// TODO fix this later
	return "";
}

Array<String> String::split(String regex) const {
	string *splitStrings = string_split(this->original, regex.toString());
	Array<String> strings;

#ifdef __linux__
	register
#endif
	int index = 0;

	int splitStringsLength = length_pointer_pointer_char(splitStrings);
	for (index = 0; index < splitStringsLength; index++) {
		strings.push(splitStrings[ index ]);
	}

	free_pointer_pointer_char(splitStrings);
	return strings;
}

boolean String::startsWith(String prefix) const {
	return string_startswith(this->original, prefix.original);
}

boolean String::startsWith(String prefix, int thisOffset) const {
	if (this->original == NULL || prefix.original == NULL || thisOffset < 0) {
		return FALSE;
	}
	int originalLength = length_pointer_char(this->original);
	int prefixLength = length_pointer_char(prefix.original);
	if (originalLength < prefixLength || thisOffset > ( originalLength - prefixLength )) {
		return FALSE;
	}
#ifdef __linux__
	register
#endif
	int firstIndex = 0;

#ifdef __linux__
	register
#endif
	int secondIndex = thisOffset;
	for (; firstIndex < prefixLength; firstIndex++) {
		if (prefix.original[ firstIndex ] != this->original[ secondIndex ]) {
			return FALSE;
		}
		secondIndex++;
	}
	return TRUE;
}

Array<char> String::toCharArray() const {
	Array<char> chars;

#ifdef __linux__
	register
#endif
	int index = 0;

	while (this->original[ index ] != '\0') {
		chars.push(this->original[ index++ ]);
	}
	return chars;
}

string String::toString() const {
	return this->original;
}

String String::toLowerCase() const {
	string holdPointer = string_lower(this->original);
	String result = holdPointer;
	free(holdPointer);
	return result;
}

String String::toUpperCase() {
	string holdPointer = string_upper(this->original);
	String result = holdPointer;
	free(holdPointer);
	return result;
}

String String::trim() {
	string holdPointer = string_trim(this->original);
	String result = holdPointer;
	free(holdPointer);
	return result;
}

/**
 * String value of boolean
 *
 * @param target
 * @return String
 */
String String::valueOf(boolean target) {
	if (target) {
		return (string) "true";
	}
	return (string) "false";
}

String String::valueOf(char charValue) {
	string pointerHolder = string_from_char(charValue);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

String String::valueOf(string stringValue) {
	if (is_empty(stringValue)) {
		return (string) "";
	}
	return stringValue;
}

String String::valueOf(short shortValue) {
	string pointerHolder = string_from_short(shortValue);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

String String::valueOf(int intValue) {
	string pointerHolder = string_from_int(intValue);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

String String::valueOf(long longValue) {
	string pointerHolder = string_from_long(longValue);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

String String::valueOf(float floatValue) {
	string pointerHolder = string_from_float(floatValue);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

String String::valueOf(double doubleValue) {
	string pointerHolder = string_from_double(doubleValue);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

String String::subString(int beginIndex) {
   return this->subString(beginIndex, this->size - 1);
}

String String::subString(int beginIndex, int endIndex) {
	string holder = string_from_to(this->original, beginIndex, endIndex);
	String result = holder;
	free(holder);
	return result;
}

String String::operator+(const string &target) {
	string pointerHolder = string_concat(this->original, target);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

String String::operator+(const String &target) {
	string pointerHolder = string_concat(this->original, target.original);
	String result = pointerHolder;
	free(pointerHolder);
	return result;
}

String &String::operator+=(const String &target) {
	string result = string_concat(this->original, target.original);
	*this = result;
	free(result);
	return *this;
}

String &String::operator+=(const char &target) {
	string pointerHolder = this->original;
	string_append(&this->original, target);
	free(pointerHolder);
	return *this;
}

String &String::operator+=(const_string target) {
	String appendString = target;
	*this += appendString;
	return *this;
}

boolean String::operator==(const String &target) const {
	if (string_equals(this->original, target.toString())) {
		return true;
	}
	return false;
}

String &String::operator=(const String &target) {
	if (this->original != NULL) {
		free(this->original);
	}
	this->original = strdup(target.original);
	this->size = target.size;
	return *this;
}

boolean String::operator!=(const String &target) const {
	return !this->operator==(target);
}

boolean String::operator<(const String &target) const {
	if (strcmp(this->original, target.toString()) < 0) {
		return true;
	}

	return false;
}

boolean String::operator>(const String &target) const {
	if (strcmp(this->original, target.toString()) > 0) {
		return true;
	}

	return false;
}

boolean String::operator<=(const String &target) const {
	if (strcmp(this->original, target.toString()) > 0) {
		return false;
	}

	return true;
}

boolean String::operator>=(const String &target) const {
	if (strcmp(this->original, target.toString()) < 0) {
		return false;
	}
	return true;
}

/**
 * Format string (base - currying function)
 * @param format
 * @return String
 */
String String::format(const String &format) {
	std::string result;
	std::string inputString(format.toString());
	std::smatch matchResult;
	std::regex reg("%(\\d+\\$)?([-#+0,(\\<]*)?(\\d+)?(\\.\\d+)?([tT])?([a-zA-Z%])");

	while(true) {
		if(std::regex_search(inputString, matchResult, reg)) {
			result += matchResult.prefix();
			if('%' == matchResult[0].str().back()) {
				result += matchResult[0].str().back();
				inputString = matchResult.suffix().str();
				continue;
			} else {
				throw "missing arguments";
			}
		} else {
			result += inputString;
			break;
		}
	}

	return String(result.c_str());
}

std::string String::print(const std::string &format, short value) {
    std::string result;
    char buffer[256] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value);
    if(length > 0)
        result = std::string(buffer);
    return result;
}

std::string String::print(const std::string &format, int value) {
    std::string result;
    char buffer[256] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value);
    if(length > 0)
        result = std::string(buffer);
    return result;
}

std::string String::print(const std::string &format, long value) {
    std::string result;
    char buffer[256] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value);
    if(length > 0)
        result = std::string(buffer);
    return result;
}

std::string String::print(const std::string &format, unsigned short value) {
    std::string result;
    char buffer[256] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value);
    if(length > 0)
        result = std::string(buffer);
    return result;
}

std::string String::print(const std::string &format, unsigned int value) {
    std::string result;
    char buffer[256] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value);
    if(length > 0)
        result = std::string(buffer);
    return result;
}

std::string String::print(const std::string &format, unsigned long value) {
    std::string result;
    char buffer[256] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value);
    if(length > 0)
        result = std::string(buffer);
    return result;
}

std::string String::print(const std::string &format, double value) {
    std::string result;
    char buffer[256] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value);
    if(length > 0)
        result = std::string(buffer);
    return result;
}

std::string String::print(const std::string &format, float value) {
    std::string result;
    char buffer[256] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value);
    if(length > 0)
        result = std::string(buffer);
    return result;
}

std::string String::print(const std::string &format, char *value) {
    std::string result;
    char buffer[256] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value);
    if(length > 0)
        result = std::string(buffer);
    return result;
}

std::string String::print(const std::string &format, Short value) {
	std::string result;
	char buffer[256] = {0};
	const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value.shortValue());
	if(length > 0)
		result = std::string(buffer);
	return result;
}

std::string String::print(const std::string &format, Integer value) {
	std::string result;
	char buffer[256] = {0};
	const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value.intValue());
	if(length > 0)
		result = std::string(buffer);
	return result;
}

std::string String::print(const std::string &format, Long value) {
	std::string result;
	char buffer[256] = {0};
	const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value.longValue());
	if(length > 0)
		result = std::string(buffer);
	return result;
}

std::string String::print(const std::string &format, Float value) {
	std::string result;
	char buffer[256] = {0};
	const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value.floatValue());
	if(length > 0)
		result = std::string(buffer);
	return result;
}

std::string String::print(const std::string &format, Double value) {
    std::string result;
    char buffer[256] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value.doubleValue());
    if(length > 0)
        result = std::string(buffer);
    return result;
}

std::string String::print(const std::string &format, String value) {
    std::string result;
    char buffer[256] = {0};
    const int length = snprintf(buffer, sizeof(buffer), format.c_str(), value.toString());
    if(length > 0)
        result = std::string(buffer);
    return result;
}



