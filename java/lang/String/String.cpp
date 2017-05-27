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

#include "String.hpp"

using namespace Java::Lang;

String::String() {
	this->original = string_copy((string) "\0");
	this->length();
}

String::String(const_string target) {
	this->original = string_copy((string) target);
	this->length();
}

String::String(string target) {
	this->original = string_copy(target);
	this->length();
}

String::String(Array<byte> &bytes) {
	ArrayList<char> listCharacters;
	for (byte byte : bytes) {
		listCharacters.add((char&) byte);
	}
	Array<char> chars = listCharacters.toArray(chars);
	this->original = String::fromCharArray(chars).toString();
	this->size = chars.length;
}

String::String(const String &target) {
	this->original = string_copy(target.original);
	this->length();
}

String::~String() {
}

/**
 * String character at index
 *
 * @param index
 * @return String
 */
char String::charAt(int index) {
	if (( index < 0 ) || ( index >= this->size )) {
		return '\0';
	}
	return this->original[ index ];
}

/**
 * String compare to another string
 *
 * @param anotherString
 * @return int
 */
int String::compareTo(String anotherString) {
	// string anotherStringValue = anotherString.toString();
	// if (string_equals(this->original, anotherStringValue) {
	//     return 0;
	// }
	return 0;
}

/**
 * String compare with another string but ignore case
 *
 * @param str
 * @return int
 */
int String::compareToIgnoreCase(String str) {
	// TODO
	return 0;
}

/**
 * String concatenation
 *
 * @param str
 * @return String
 */
String String::concat(String str) {
	return string_concat(this->original, str.original);
}

/**
 * Find substring inside
 *
 * @param str
 * @return String
 */
boolean String::contains(CharSequence &str) {
	return ( string_index(this->original, str.toString(), 1) != NOT_FOUND );
}

/**
 * Get byte array from String
 *
 * @return Array<byte>
 */
Array<byte> String::getBytes() const {
	ArrayList<byte> byteArrayList;
	String originalString = this->original;
	for (char character : originalString.toCharArray()) {
		byteArrayList.add(0, (byte&) character);
	}
	Array<byte> bytes;
	return byteArrayList.toArray(bytes);
}

/**
 * String endswith a suffix
 * @param suffix
 * @return
 */
boolean String::endsWith(String suffix) {
	return string_endswith(this->original, suffix.original);
}

/**
 * String from character array
 *
 * @param chars
 * @return String
 */
String String::fromCharArray(Array<char> &chars) {
	string str = (string) malloc(( chars.length + 1 ) * sizeof(char));
	register int index = 0;
	for (char character : chars) {
		str[ index++ ] = character;
	}
	str[ index ] = '\0';
	return str;
}

/**
 * String index of character
 *
 * @param ch
 * @return int
 */
int String::indexOf(int ch) const {
	return string_index(this->original, string_from_char((char) ch), 1);
}

/**
 * String index of
 *
 * @param ch
 * @param fromIndex
 * @return int
 */
int String::indexOf(int ch, int fromIndex) const {
	if (fromIndex > this->size) {
		return -1;
	}
	register int index;
	for (index = fromIndex; index < this->size; index++) {
		if (this->original[ index ] == (char) ch) {
			return index;
		}
	}
	return -1;
}

/**
 * String index of a String
 *
 * @param str
 * @return int
 */
int String::indexOf(String str) const {
	return string_index(this->original, str.original, 1);
}

/**
 * String index of a string from index position
 *
 * @param str
 * @param fromIndex
 * @return int
 */
int String::indexOf(String str, int fromIndex) const {
	return 0;
}

/**
 * String is empty or not
 *
 * @return boolean
 */
boolean String::isEmpty() const {
	if (length_pointer_char(this->original) == 0) {
		return true;
	}
	return false;
}

/**
 * String last index of character
 *
 * @param ch
 * @return int
 */
int String::lastIndexOf(int ch) {
	register int index;
	for (index = this->size - 1; index >= 0; index--) {
		if (this->charAt(index) == (char) ch) {
			return index;
		}
	}
	return -1;
}

/**
 * String last index of character
 *
 * @param ch
 * @param fromIndex
 * @return int
 */
int String::lastIndexOf(int ch, int fromIndex) {
	register int index;
	for (index = fromIndex - 1; index >= 0; index--) {
		if (this->charAt(index) == (char) ch) {
			return index;
		}
	}
	return -1;
}

/**
 * Last index of String inside this
 *
 * @param str
 * @return int
 */
int String::lastIndexOf(String str) const {
	string strReversed = string_reverse(str.toString());
	string currentStrReversed = string_reverse(this->toString());
	
	int result = string_index(currentStrReversed, strReversed, 1);
	
	free(strReversed);
	free(currentStrReversed);
	
	if (result == NOT_FOUND) {
		return result;
	}
	
	//Re-calculate first character of str
	result = this->size - ( result + str.size );
	return result;
}

/**
 * Last index of String start fromIndex inside this
 *
 * @param str
 * @param fromIndex
 * @return int
 */
int String::lastIndexOf(String str, int fromIndex) const {
	string subString = &( this->original )[ fromIndex ]; // get subString start fromIndex
	
	string strReversed = string_reverse(str.toString());
	string currentStrReversed = string_reverse(subString);
	
	int result = string_index(currentStrReversed, strReversed, 1);
	
	free(strReversed);
	free(currentStrReversed);
	
	if (result == NOT_FOUND) {
		return result;
	}
	
	//Re-calculate first character of str
	result = this->size - ( result + str.size );
	return result;
	
}

/**
 * String length
 *
 * @return int
 */
int String::length() {
	this->size = length_pointer_char(this->original);
	return this->size;
}

/**
 * String matches
 * @params regex pattern
 * @return TRUE | FALSE
 */
boolean String::matches(String regex) const {
	int result = string_matches(this->original, regex.toString());
	return ( result == TRUE ? true : false );
}

/**
 * String replace
 *
 * @param oldChar
 * @param newChar
 * @return String
 */
String String::replace(char oldChar, char newChar) const {
	return string_replace(this->original, string_from_char(oldChar), string_from_char(newChar));
}

/**
 * String replace all matches by replacement
 *
 * @param regex
 * @param replacement
 * @return String
 */
String String::replaceAll(String regex, String replacement) const {
	return string_replace(this->original, regex.original, replacement.original);
}

/**
 * Split string by regex
 *
 * @param regex
 * @return Array<String>
 */
Array<String> String::split(String regex) const {
	char **splitStrings = string_split(this->original, regex.toString());
	ArrayList<String> stringArrayList;
	register int index;
	int splitStringsLength = length_pointer_pointer_char(splitStrings);
	for (index = 0; index < splitStringsLength; index++) {
		stringArrayList.add((String&) splitStrings[ index ]);
	}
	Array<String> strings = stringArrayList.toArray(strings);
	return strings;
}

/**
 * String starts with a prefix
 *
 * @param prefix
 * @return boolean
 */
boolean String::startsWith(String prefix) const {
	return string_startswith(this->original, prefix.original);
}

/**
 * String starts with a prefix
 *
 * @param prefix
 * @param from t
 * @return boolean
 */
boolean String::startsWith(String prefix, int toffset) const {
	if (this->original == NULL || prefix.original == NULL || toffset < 0) {
		return FALSE;
	}
	int original_length = length_pointer_char(this->original);
	int prefix_length = length_pointer_char(prefix.original);
	if (original_length < prefix_length || toffset > ( original_length - prefix_length )) {
		return FALSE;
	}
	register int i = 0;
	register int j = toffset;
	for (i; i < prefix_length; i++) {
		if (prefix.original[ i ] != this->original[ j ]) {
			return FALSE;
		}
		j++;
	}
	return TRUE;
}
/**
 * String to char array
 *
 * @return Array<char>
 */
Array<char> String::toCharArray() const {
	ArrayList<char> charArrayList;
	register int index = 0;
	while (this->original[ index ] != '\0') {
		charArrayList.add(this->original[ index++ ]);
	}
	Array<char> chars = charArrayList.toArray(chars);
	return chars;
}

/**
 * String to char string (char pointer)
 *
 * @return string
 */
string String::toString() const {
	return this->original;
}

/**
 * String to lowercase
 *
 * @return String
 */
String String::toLowerCase() const {
	return string_lower(this->original);
}

/**
 * String to uppercase
 *
 * @return String
 */
String String::toUpperCase() {
	return string_upper(this->original);
}

/**
 * String trim space
 *
 * @return String
 */
String String::trim() {
	return string_trim(this->original);
}

/**
 * String value of boolean
 *
 * @param target
 * @return String
 */
String String::valueOf(boolean target) {
	if (target) {
		return (string) "1";
	}
	return (string) "0";
}

/**
 * String value of character
 *
 * @param target
 * @return String
 */
String String::valueOf(char target) {
	return string_from_char(target);
}

/**
 * String value of string
 *
 * @param target
 * @return String
 */
String String::valueOf(string target) {
	if (is_empty(target)) {
		return (string) "";
	}
	return target;
}

/**
 * String value of short
 *
 * @param target
 * @return String
 */
String String::valueOf(short target) {
	return string_from_short(target);
}

/**
 * String value of integer
 *
 * @param target
 * @return String
 */
String String::valueOf(int target) {
	return string_from_int(target);
}

/**
 * String value of long
 *
 * @param target
 * @return String
 */
String String::valueOf(long target) {
	return string_from_long(target);
}

/**
 * String value of float
 *
 * @param target
 * @return String
 */
String String::valueOf(float target) {
	return string_from_float(target);
}

/**
 * String value of double
 *
 * @param target
 * @return String
 */
String String::valueOf(double target) {
	return string_from_double(target);
}

String String::operator+(const String &target2) {
	String result = string_concat(this->original, target2.original);
	return result;
}

void String::operator+=(const String &target2) {
	*this = string_concat(this->original, target2.original);
}

boolean String::operator==(const String &target2) const {
	if (string_equals(this->original, target2.toString())) {
		return true;
	}
	return false;
}

String String::operator=(const String &target) {
	this->original = string_copy(target.original);
	this->length();
	return *this;
}

boolean String::operator!=(const String &target2) {
	return !this->operator==(target2);
}

boolean String::operator<(const String &target2) const {
	if (strcmp(this->original, target2.toString()) < 0) {
		return true;
	}
	
	return false;
}
