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

#ifndef JAVA_LANG_STRING_STRING_HPP
#define JAVA_LANG_STRING_STRING_HPP

#include "../../../kernel/String.hpp"
#include "../../../kernel/Common.hpp"

#include <typeinfo>
#include <regex>
#include <string>

#include "../Object/Object.hpp"
#include "../CharSequence/CharSequence.hpp"
#include "../../io/Serializable/Serializable.hpp"
#include "../../lang/Comparable/Comparable.hpp"
#include <regex.h>

using namespace Java::IO;

namespace Java {
    namespace Lang {

#define DEFAULT_CAPACITY 16
#define DEFAULT_BUFFER_LENGTH 128

#define STRING_CONSTRUCTOR  \
        this->original = stringCopy(target);\
        this->capacity = this->size == 0 ? -1 : this->size;

#define STRING_CONSTRUCTOR_ARRAY \
    if (offset < 0) {\
        throw StringIndexOutOfBoundsException(offset);\
    }\
    if (length < 0) {\
        throw StringIndexOutOfBoundsException(length);\
    }\
    if (offset > array.length - length) {\
        throw StringIndexOutOfBoundsException(offset + length);\
    }\
    this->original = (string) allocateMemory((length + 1) * sizeof(char));\
    int index;\
    for (index = 0; index < length; offset++, index++) {\
        this->original [index] = array.get(offset);\
    }\
    this->original [length] = '\0';\
    this->size = length;\
    this->capacity = this->size == 0 ? -1 : this->size;

#define STRING_OPERATOR_PLUS  \
        if (newLength >= this->capacity) {\
            this->capacity = newLength << 1;\
            this->original = (string) allocateMemory(this->original, this->capacity);\
        }\
        memcpy(&this->original[this->size], targetValue, targetLength);\
        this->original[newLength] = '\0';\
        this->size = newLength;

        class StringBuilder;

        class StringBuffer;

        class Short;

        class Integer;

        class Long;

        class Float;

        class Double;

        class String :
                public Object,
                public virtual Serializable,
                public virtual Comparable<String>,
                public virtual CharSequence {
        private:
            string original;
            long size;
            long capacity;
            mutable int hash = 0;

        public:
            /**
             * Initializes a newly created String object
             * so that it represents an empty character sequence.
             */
            String();

            /**
             * Initializes a newly created String object
             * so that it represents the same sequence of characters as the argument.
             *
             * @param target
             */
            String(const String &target);

            /**
             * Constructs a new String by decoding the specified array of bytes.
             *
             * @param byteArray
             */
            String(Array<byte> &byteArray);

            /**
             * Allocates a new String that contains the sequence
             * of characters currently contained in the StringBuilder.
             *
             * @param stringBuilder
             */
            String(const StringBuilder &stringBuilder);

            /**
             * Allocates a new String so that it represents the sequence
             * of characters currently contained in the character array argument.
             *
             * @param charArray
             */
            String(Array<char> &charArray);

            /**
             * Allocates a new String that contains the sequence
             * of characters currently contained in the StringBuffer.
             *
             * @param stringBuffer
             */
            String(const StringBuffer &stringBuffer);

            /**
             * Constructs a new String by decoding the specified array of bytes
             * using the specified charset.
             *
             * @param byteArray
             * @param charsetName
             */
            // TODO (anhnt) need CharSet
            // String(Array<byte> byteArray, String charsetName);

            /**
             * Constructs a new String by decoding the specified array of bytes
             * using the specified charset.
             *
             * @param byteArray
             * @param charset
             */
            // TODO (anhnt) need CharSet
            // String(Array<byte> byteArray, Charset charset)

            /**
             * Allocates a new String that contains characters
             * from a subarray of the character array argument.
             *
             * @param charArray
             * @param offset
             * @param count
             * @throw IndexOutOfBoundsException If the offset and count arguments index
             * characters outside the bounds of the value array
             */
            String(Array<char> &charArray, int offset, int count);

            /**
             * Allocates a new String that contains characters
             * from a subarray of the Unicode code point array argument.
             *
             * @param codePoints
             * @param offset
             * @param count
             * @throw IllegalArgumentException If any invalid Unicode
             * code point is found in codePoints
             * @throw IndexOutOfBoundsException If the offset and count
             * arguments index characters outside the bounds of the codePoints array
             */
            // TODO (anhnt) need CharSet
            // String(Array<int> codePoints, int offset, int count);

            /**
             * Constructs a new String by decoding the specified
             * subarray of bytes using the platform's default charset.
             *
             * @param byteArray
             * @param offset
             * @param length
             * @throwIndexOutOfBoundsException If the offset and the length arguments index
             * characters outside the bounds of the bytes array
             */
            String(Array<byte> &byteArray, int offset, int length);

            /**
             * Constructs a new String by decoding the specified
             * subarray of bytes using the specified charset
             *
             * @param byteArray
             * @param offset
             * @param length
             * @param charset
             * @throw IndexOutOfBoundsException If the offset and length arguments index
             * characters outside the bounds of the bytes array
             */
            // TODO (anhnt) need CharSet
            // String(Array<byte> &byteArray, int offset, int length, Charset charset);

            /**
             * Constructs a new String by decoding the specified
             * subarray of bytes using the specified charset.
             *
             * @param bytes
             * @param offset
             * @param length
             * @param charsetName
             * @throw java.io.UnsupportedEncodingException If the named charset is not supported
             * @throw IndexOutOfBoundsException If the offset and length arguments index
             * characters outside the bounds of the bytes array
             */
            // TODO (anhnt) need CharSet
            // String(Array<byte> &byteArray, int offset, int length, String charsetName);

            /**
             * Construct a new String from specific string
             *
             * @param original
             */
            inline String(string target) {
                this->size = lengthPointerChar(target);
                STRING_CONSTRUCTOR
            }

            /**
             * Construct a new String from specific const_string
             *
             * @param target
             */
            inline String(const_string target) {
                this->size = lengthPointerChar(target);
                STRING_CONSTRUCTOR
            }

            /**
             * Construct a new String from specific std::string
             *
             * @param target
             */
            inline String(const std::string &targetString) {
                string target = (string) targetString.c_str();
                this->size = targetString.length();
                STRING_CONSTRUCTOR
            }

            /**
             * Construct a new String from char array with specific length
             *
             * @param original
             * @param length
             */
            String(string target, int length);

            /**
             * Destructor
             */
            ~String();

        public:
            /**
            * Set and get value of element in char type
            * at the specified position in this String
            *
            * @param index
            * @return char
            */
            inline char &operator[](const int index) {
                return this->original[index];
            }

            /**
             * Return size of String
             *
             * @return int
             */
            int getSize() const;

            /**
             * String character at index
             *
             * @param index
             * @return String
             */
            char charAt(int index) const override;

            /**
             * Returns the character (Unicode code point) at the specified index.
             *
             * @param index
             * @return int
             */
            // TODO (anhnt) need Character
            // int codePointAt(int index);

            /**
             * Returns the character (Unicode code point) before the specified index.
             *
             * @param index
             * @return int
             */
            // TODO (anhnt) need Character
            // int codePointBefore(int index);

            /**
             * Returns the number of Unicode code points
             * in the specified text range of this String.
             *
             * @param beginIndex
             * @param endIndex
             * @return int
             */
            // TODO (anhnt) need Character
            // int codePointCount(int beginIndex, int endIndex);

            /**
             * Clone to new object
             *
             * @return String
             */
            String clone();

            /**
             * String compare to another string
             *
             * @param anotherString
             * @return 0 if the argument String is equal to this string;
             * a value less than 0 if this String is lexicographically
             * less than the String argument;
             * and a value greater than 0 if this String is lexicographically
             * greater than the String argument.
             */
            int compareTo(const String &anotherString) const override;

            /**
             * String compare with another String but ignore case
             *
             * @param targetString
             * @return 0 if the argument String is equal to this string
             * ignoring case considerations.
             * a value less than 0 if this String is lexicographically
             * less than the String argument ignoring case considerations.
             * and a value greater than 0 if this String is lexicographically
             * greater than the String argument ignoring case considerations..
             */
            int compareToIgnoreCase(const String &targetString) const;


            /**
             * String concatenation
             *
             * @param target
             * @return String
             */
            String concat(String target);

            /**
             * Find substring inside this String
             *
             * @param charSequence
             * @return String
             */
            boolean contains(const CharSequence &charSequence);

            /**
             * Compares this String to the specified CharSequence.
             * The result is true if and only if this String represents
             * the same sequence of char values as the specified sequence.
             *
             * @param charSequence
             * @return boolean
             */
            boolean contentEquals(const CharSequence &charSequence);

            /**
             * Returns the String representation of the char array argument.
             * The contents of the character array are copied;
             * subsequent modification of the character array does not affect the returned string.
             *
             * @param charArray
             * @return a String that contains the characters of the charArray.
             */
            static String copyValueOf(Array<char> &charArray);

            /**
             * Returns the String representation of a specific subarray of the char array argument.
             *
             * @param charArray
             * @param offset
             * @param count
             * @throw IndexOutOfBoundsException if offset is negative, or count is negative,
             * or offset+count is larger than data.length.
             * @return a String that contains the characters of the
             * specified subarray of charArray.
             */
            static String copyValueOf(Array<char> &charArray, int offset, int count);

            /**
             * String endswith a suffix
             *
             * @param suffixString
             * @return true if the character sequence represented by the argument
             * is a suffix of the character sequence represented by this String;
             * False otherwise
             */
            boolean endsWith(const String &suffixString) const;

            /**
             * Compares this String to the specified object.
             *
             * @param T
             * @param anObject
             * @return true if the given object represents a String equivalent
             * to this string, false otherwise
             */
            template<class T>
            boolean equals(T anObject) const {
                if (Object::equals(anObject)) {
                    return true;
                }
                if (instanceof<String>(anObject)) {
                    return (boolean) stringEquals(original, anObject.toString());
                }
                return false;
            }

            /**
             * Compares this String to another String, ignoring case considerations.
             *
             * @param anotherString
             * @return true if the given object represents a String equivalent
             * to this string, false otherwise, ignoring case considerations
             */
            boolean equalsIgnoreCase(String anotherString);

            /**
             * String from character array
             *
             * @param charArray
             * @return String
             */
            static String fromCharArray(Array<char> &charArray);

            /**
             * Get byte array from this String
             *
             * @return Array<byte>
             */
            Array<byte> getBytes() const;

            /**
             * Encodes this String into a sequence of bytes using the named charset,
             * storing the result into a new byte array.
             *
             * @param charSetName
             * @return
             */
            // Array<byte> getBytes(String charSetName) const;

            /**
             * Encodes this String into a sequence of bytes using the charset,
             * storing the result into a new byte array.
             *
             * @param charSet
             * @return
             */
            // Array<byte> getBytes(CharSet charSet) const;

            /**
             * Copies characters from this String into the destination character array.
             *
             * @param sourceBegin
             * @param sourceEnd
             * @param destination
             * @param destinationBegin
             * @throw StringIndexOutOfBoundsException If :
             * sourceBegin is negative.
             * sourceBegin is greater than srcEnd
             * sourceEnd is greater than the length of this string
             * destinationBegin is negative
             * destinationBegin + (srcEnd - srcBegin) is larger than destination.length
             */
            void getChars(int sourceBegin, int sourceEnd,
                          Array<char> &destination, int destinationBegin);

            /**
             * Get char to String
             * This function use for class UUID and Long
             *
             * @param index
             * @return String
             */
            String getStringFromIndex(int index) const;

            /**
             * Returns a hash code for this string.
             *
             * @return int
             */
            long hashCode() const override;

            /**
             * Returns the index within this String
             * of the first occurrence of the specified character.
             *
             * @param character
             * @return index of the first occurrence of character,
             * or -1 if there is no such occurrence.
             */
            int indexOf(int character) const;

            /**
             * Returns the index within this String
             * of the first occurrence of the specified String.
             *
             * @param subString
             * @return index of the first occurrence of the specified substring,
             * or -1 if there is no such occurrence.
             */
            int indexOf(String subString) const;

            /**
             * Returns the index within this String
             * of the first occurrence of the specified character,
             * starting the search at the specified index.
             *
             * @param character
             * @param fromIndex
             * @return index of the first occurrence of the specified character,
             * or -1 if there is no such occurrence.
             */
            int indexOf(int character, int fromIndex) const;

            /**
             * Returns the index within this string
             * of the first occurrence of the specified String.
             * starting the search at the specified index.
             *
             * @param subString
             * @param fromIndex
             * @return index of the first occurrence of the specified substring,
             * start from fromIndex or -1 if there is no such occurrence.
             */
            int indexOf(String subString, int fromIndex) const;

            /**
             * Determine if this String is empty
             *
             * @return true if, and only if, length() is 0.
             */
            boolean isEmpty() const;

            /**
             * Returns a new String composed of copies of the CharSequence elements
             * joined together
             *
             * @param delimiter
             * @param elements
             * @return a new String that is composed of the elements
             */
            template<typename ... Args>
            static String join(CharSequence &delimiter, Args &&... elements) {
                String result;
                std::initializer_list<CharSequence *> paramList = {&elements...};
                for (const CharSequence *arg : paramList) {
                    result += arg->toString();
                    result += delimiter.toString();
                }
                result = result.subString(0, result.size - delimiter.length());
                return result;
            }

            /**
             * Returns the index within this string of the last occurrence
             * of the specified character
             *
             * @param character
             * @return index of the last occurrence of the specified character,
             * or -1 if the character does not occur.
             */
            int lastIndexOf(int character);

            /**
             * Returns the index within this string of the last occurrence
             * of the specified character,
             * searching backward starting at the specified index.
             *
             * @param character
             * @param fromIndex
             * @return index of the last occurrence of the specified character,
             * or -1 if the character does not occur.
             */
            int lastIndexOf(int character, int fromIndex);

            /**
             * Returns the index within this string of the last occurrence
             * of the specified substring
             *
             * @param subString
             * @return index of the last occurrence of the specified substring,
             * or -1 if the substring does not occur.
             */
            int lastIndexOf(String subString) const;

            /**
             * Returns the index within this string of the last occurrence
             * of the specified substring,
             * searching backward starting at the specified index.
             *
             * @param subString
             * @param fromIndex
             * @return index of the last occurrence of the specified substring,
             * or -1 if the substring does not occur.
             */
            int lastIndexOf(String subString, int fromIndex) const;

            /**
             * Returns the length of this string
             *
             * @return int
             */
            inline int length() const override {
                return this->size;
            }

            /**
             * Tells whether or not this string matches the given regular expression.
             *
             * @param regex
             * @throw java.util.regex.PatternSyntaxException
             * if the regular expression's syntax is invalid
             * @return true if, and only if, this string matches
             * the given regular expression
             */
            // TODO (anhnt) need Pattern
            // boolean matches(String regex) const;

            /**
             * Returns the index within this String that is offset
             * from the given index by codePointOffset code points
             *
             * @param index
             * @param codePointOffset
             * @throw IndexOutOfBoundsException if index is negative or larger then
             * the length of this String,
             * or if codePointOffset is positive and the substring starting with index
             * has fewer than codePointOffset code points,
             * or if codePointOffset is negative and the substring before index has fewer than
             * the absolute value of codePointOffset code points.
             * @return the index within this String
             */
            // TODO (anhnt) need Character
            // int offsetByCodePoints(int index, int codePointOffset);

            /**
             * Tests if two string regions are equal.
             *
             * @param thisOffset
             * @param otherString
             * @param otherOffset
             * @param len
             * @return true if the specified subregion of this String exactly
             * matches the specified subregion of the String argument; false otherwise.
             */
            boolean regionMatches(int thisOffset,
                                  String otherString, int otherOffset, int len);

            /**
             * Tests if two string regions are equal.
             *
             * @param ignoreCase
             * @param thisOffset
             * @param otherString
             * @param otherOffset
             * @param len
             * @return true if the specified subregion of this String matches the specified
             * subregion of the String argument; false otherwise.
             * Whether the matching is exact or case insensitive depends on the ignoreCase argument.
             */
            boolean regionMatches(boolean ignoreCase, int thisOffset,
                                  String otherString, int otherOffset, int len);

            /**
             * Returns a string resulting from replacing all occurrences
             * of oldChar in this String with newChar.
             *
             * @param oldChar
             * @param newChar
             * @return a string derived from this String by replacing
             * every occurrence of oldChar with newChar.
             */
            String replace(char oldChar, char newChar) const;

            /**
             * Replaces each substring of this string that matches the literal
             * target sequence with the specified literal replacement sequence.
             * The replacement proceeds from the beginning of the string to the end.
             *
             * @param target
             * @param replacement
             * @return The resulting String
             */
            String replace(CharSequence &target, CharSequence &replacement) const;

            /**
             * Replaces each substring of this string that matches
             * the given regular expression with the given replacement.
             *
             * @param regex
             * @param replacement
             * @throw java.util.regex.PatternSyntaxException
             * if the regular expression's syntax is invalid
             * @return The resulting String
             */
            String replaceAll(String regex, String replacement) const;

            /**
             * Replaces the first substring of this string that matches
             * the given regular expression with the given replacement.
             *
             * @param regex
             * @param replacement
             * @throw java.util.regex.PatternSyntaxException
             * if the regular expression's syntax is invalid
             * @return The resulting String
             */
            String replaceFirst(String regex, String replacement) const;

            /**
             * Splits this String around matches of the given regular expression.
             *
             * @param regex
             * @throw java.util.regex.PatternSyntaxException
             * if the regular expression's syntax is invalid
             * @return the array of Strings computed by splitting this String
             * around matches of the given regular expression
             */
            Array<String> split(String regex) const;

            /**
             * Splits this string around matches of the given regular expression.
             *
             * @param regex
             * @param limit
             * @throw java.util.regex.PatternSyntaxException
             * if the regular expression's syntax is invalid
             * @return array of Strings computed by splitting this String
             * around matches of the given regular expression
             */
            Array<String> split(String regex, int limit) const;

            /**
             * Tests if this string starts with the specified prefix.
             *
             * @param prefix
             * @return true if the character sequence represented by the argument is a prefix
             * of the character sequence represented by this string; false otherwise.
             */
            boolean startsWith(String prefix) const;

            /**
             * Tests if the substring of this string beginning
             * at the specified index starts with the specified prefix.
             *
             * @param prefix
             * @param thisOffset
             * @return true if the character sequence represented by the argument is a prefix
             * of the substring of this object starting at index thisOffset; false otherwise.
             * The result is false if thisOffset is negative or greater than the length
             * of this String object;
             */
            boolean startsWith(String prefix, int thisOffset) const;

            /**
             * Returns a character sequence that is a subsequence of this sequence.
             *
             * @param beginIndex
             * @param endIndex
             * @throw IndexOutOfBoundsException if beginIndex or endIndex is negative,
             * if endIndex is greater than length(), or if beginIndex is greater than endIndex
             * @return the specified subsequence.
             */
            // CharSequence subSequence(int beginIndex, int endIndex);

            /**
             * Returns a String that is a substring of this String.
             * The substring begins with the character at the specified
             * index and extends to the end of this string.
             *
             * @param beginIndex
             * @throw IndexOutOfBoundsException if beginIndex is negative
             * or larger than the length of this String object.
             * @return the specified substring as a String.
             */
            String subString(int beginIndex) const;

            /**
             * Returns a string that is a substring of this string.
             * The substring begins at the specified beginIndex
             * and extends to the character at index endIndex - 1
             *
             * @param beginIndex
             * @param endIndex
             * @throw IndexOutOfBoundsException if the beginIndex is negative,
             * or endIndex is larger than the length of this String object,
             * or beginIndex is larger than endIndex.
             * @return the specified substring as a String.
             */
            String subString(int beginIndex, int endIndex) const;

            /**
             * Converts this string to a new character array.
             *
             * @return a newly allocated character array contain
             */
            Array<char> toCharArray() const;

            /**
             * Converts all of the characters in this String to lower case
             * using the rules of the default locale.
             *
             * @return the String, converted to lowercase.
             */
            String toLowerCase() const;

            /**
             * Converts all of the characters in this String to lower case using the rules of the given Locale.
             *
             * @param locale
             * @return the String, converted to lowercase.
             */
            // TODO (anhnt) need Locale
            // String toLowerCase(Locale locale);

            /**
             * Converts all of the characters in this String to upper case
             * using the rules of the default locale.
             *
             * @return the String, converted to uppercase.
             */
            String toUpperCase();

            /**
            * Converts all of the characters in this String to upper case
            * using the rules of the given locale.
            *
            * @param locale
            * @return the String, converted to uppercase.
            */
            // TODO need Locale
            // String toUpperCase(Locale locale);

            /**
             * Returns a String whose value is this string, with any leading
             *
             * and trailing whitespace removed.
             *
             * @return a String with leading and trailing whitespace removed.
             */
            String trim();

            /**
             * Return a String a string contain value of this String
             *
             * @return a String contain value of this String
             */
            string toString() const override;

            /**
             * Returns the String representation of the boolean argument.
             *
             * @param boolValue
             * @return if the argument is true, a String equal to "true" is returned;
             * otherwise, a String equal to "false" is returned.
             */
            static String valueOf(boolean boolValue);

            /**
             * Returns the String representation of the char argument.
             *
             * @param charValue
             * @return a String of length 1 containing charValue.
             */
            static String valueOf(char charValue);

            /**
             * Returns the String representation of the string argument.
             *
             * @param stringValue
             * @return a String containing stringValue.
             */
            static String valueOf(string stringValue);

            /**
             * Returns the String representation of the String argument.
             *
             * @param stringValue
             * @return a String containing stringValue.
             */
            static String valueOf(String stringValue);

            /**
             * Returns the String representation of the const string argument.
             *
             * @param stringValue
             * @return a String containing stringValue.
             */
            static String valueOf(const_string constStringValue);

            /**
             * Returns the String representation of the short argument.
             *
             * @param shortValue
             * @return a String representation of the short argument.
             */
            static String valueOf(short shortValue);

            /**
             * Returns the String representation of the int argument.
             *
             * @param intValue
             * @return a String representation of the int argument.
             */
            static String valueOf(int intValue);

            /**
             * Returns the String representation of the long argument.
             *
             * @param longValue
             * @return a String representation of the long argument.
             */
            static String valueOf(long longValue);

            /**
             * Returns the String representation of the float argument.
             *
             * @param floatValue
             * @return a String representation of the float argument.
             */
            static String valueOf(float floatValue);

            /**
             * Returns the String representation of the double argument.
             *
             * @param doubleValue
             * @return a String representation of the double argument.
             */
            static String valueOf(double doubleValue);

        public:
            /**
             * Add two String
             *
             * @param target
             * @return a String contain value of this String and target String
             */
            inline String operator+(const string &target) {
                auto targetValue = (string) target;
                long targetLength = lengthPointerChar((string) target);
                long newLength = this->size + targetLength;
                STRING_OPERATOR_PLUS
                return this->original;
            }

            /**
             * Add two String
             *
             * @param target
             * @return a String contain value of this String and target String
             */
            inline String operator+(const String &target) {
                string targetValue = target.original;
                long targetLength = target.size;
                long newLength = this->size + target.size;
                STRING_OPERATOR_PLUS
                return this->original;
            }

            /**
             * Add this String with string
             *
             * @param target
             * @return a String contain value of this String and target string
             */
            inline String &operator+=(const String &target) {
                string targetValue = target.original;
                long targetLength = target.size;
                long newLength = this->size + target.size;
                STRING_OPERATOR_PLUS
                return *this;
            }

            /**
             * Add two String
             *
             * @param target
             * @return a String contain value of this String and target String
             */
            inline String &operator+=(const_string target) {
                auto targetValue = target;
                long targetLength = lengthPointerChar(target);
                long newLength = this->size + targetLength;
                STRING_OPERATOR_PLUS
                return *this;
            }

            /**
            * Add target char to this String and assign value to this String
            *
            * @param target
            * @return a reference to this String
            */
            inline String &operator+=(const char &target) {
                string pointerHolder = this->original;
                stringAppend(&this->original, target);
                this->size++;
                this->capacity = this->size;
                free(pointerHolder);
                return *this;
            }

            /**
             * Determine if two String is equal
             *
             * @param target
             * @return true if this String is equal to target; false otherwise
             */
            inline boolean operator==(const String &target) const {
                return stringEquals(this->original, target.toString()) != 0;
            }

            /**
            * Assign value from target to this String
            *
            * @param target
            * @return a reference to this String
            */
            inline String &operator=(const String &target) {
                if (this->original != nullptr) {
                    free(this->original);
                }
                this->original = stringCopy(target.original);
                this->size = target.size;
                this->capacity = target.capacity;
                return *this;
            }

            /**
            * Determine if two String is not equal
            *
            * @param target
            * @return true if this String is different from target; false otherwise
            */
            inline boolean operator!=(const String &target) const {
                return !this->operator==(target);
            }

            /**
            * Determine if this String is smaller than another String
            *
            * @param target
            * @return true if this String is smaller than target; false otherwise
            */
            inline boolean operator<(const String &target) const {
                return strcmp(this->original, target.toString()) < 0;
            }

            /**
             * Determine if this String is greater than another String
             *
             * @param target
             * @return true if this String is greater than target; false otherwise
             */
            inline boolean operator>(const String &target) const {
                return strcmp(this->original, target.toString()) > 0;
            }

            /**
            * Determine if this String is smaller than or equal to another String
            *
            * @param target
            * @return true if this String is smaller than or equal to target; false otherwise
            */
            inline boolean operator<=(const String &target) const {
                return strcmp(this->original, target.toString()) <= 0;
            }

            /**
             * Determine if this String is greater than or equal to another String
             *
             * @param target
             * @return true if this String is greater than or equal to target; false otherwise
             */
            inline boolean operator>=(const String &target) const {
                return strcmp(this->original, target.toString()) >= 0;
            }

        public:
            /**
             * Format string
             *
             * @param format
             * @throw IllegalArgumentException - if not enough arguments
             */
            template<typename T, typename... Args>
            static String format(const String &format, T value, Args... args) {
                const String pattern = "%([[:digit:]]+)?([-#+0 ]*)?" \
                        "([[:digit:]]+)?(\\.[[:digit:]]+)?(l){0,2}([diuoxXfFeEgGaAcspn%])";
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
                        result += printObject(matchedString, value);

                        if (matchedString.charAt(matchedString.getSize() - 1) != '%') {
                            String remainString(inputStringPtr + matchedResult[0].rm_eo,
                                                inputStringLength - matchedResult[0].rm_eo);
                            try {
                                result += String::format(remainString, args...);
                            } catch (...) {
                                regfree(&regex);
                                throw;
                            }
                            break;
                        }
                    }

                    inputStringPtr += matchedResult[0].rm_eo;
                    inputStringOffset += matchedResult[0].rm_eo;
                    inputStringLength -= matchedResult[0].rm_eo;
                }

                regfree(&regex);
                return result;
            }

            /**
             * Format string
             *
             * @param format
             * @throw IllegalArgumentException - if not enough arguments
             */
            static String format(const String &format);

        public:

            /**
             * Output string value as stream
             *
             * @param os
             * @param target
             * @return
             */
            inline friend std::ostream &operator<<(std::ostream &os, const String &target) {
                os << target.original;
                return os;
            }

            /**
             * Add const_string and String
             *
             * @param target1
             * @param target2
             * @return a String contain value of target1 and target2
             */
            inline friend String operator+(String const &target1, String const &target2) {
                String result = target1;
                result += target2;
                return result;
            }

        private:
            template<typename T>
            static String printObject(const String &format, T value) {
                String result;
                char lastChar = '\0';

                if (format.getSize() > 0) {
                    lastChar = format.charAt(format.getSize() - 1);
                }

                switch (lastChar) {
                    case '%':
                        result += lastChar;
                        break;
                    default:
                        result = print(format, value);
                        break;
                }
                return result;
            }

            static String print(const String &format, short value);

            static String print(const String &format, int value);

            static String print(const String &format, long value);

            static String print(const String &format, unsigned short value);

            static String print(const String &format, unsigned int value);

            static String print(const String &format, unsigned long value);

            static String print(const String &format, double value);

            static String print(const String &format, float value);

            static String print(const String &format, char *value);

            static String print(const String &format, Short value);

            static String print(const String &format, Integer value);

            static String print(const String &format, Long value);

            static String print(const String &format, Float value);

            static String print(const String &format, Double value);

            static String print(const String &format, String value);
        };
    } // namespace Lang
} // namespace Java

#endif  // JAVA_LANG_STRING_STRING_HPP