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

#ifndef JAVA_LANG_STRING_STRING_HPP_
#define JAVA_LANG_STRING_STRING_HPP_

#include <typeinfo>
#include <regex>
#include <string>

#include "../Object/Object.hpp"
#include "../CharSequence/CharSequence.hpp"
#include "../../io/Serializable/Serializable.hpp"
#include "../../lang/Comparable/Comparable.hpp"
#include "../../lang/Number/Number.hpp"
//#include "../StringBuilder/StringBuilder.hpp"
//#include "../StringBuffer/StringBuffer.hpp"

using namespace Java::IO;

namespace Java {
	namespace Lang {

		class String :
				public Object,
				public virtual Serializable,
				public virtual Comparable<String>,
				public virtual CharSequence {
		private:
			string original;
			int size = 0;

        private:
            int hash = 0;
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
             * Allocates a new string that contains the sequence
             * of characters currently contained in the string builder.
             *
             * @param stringBuffer
             */
            //String(const StringBuilder &stringBuffer);

            /**
             * Allocates a new String so that it represents the sequence
             * of characters currently contained in the character array argument.
             *
             * @param charArray
             */
            String(Array<char> &charArray);

            /**
             * Allocates a new string that contains the sequence
             * of characters currently contained in the string buffer.
             *
             * @param stringBuffer
             */
            // String(const StringBuffer &stringBuffer);

            /**
             * Constructs a new String by decoding the specified array of bytes
             * using the specified charset.
             *
             * @param byteArray
             * @param charsetName
             */
            // String(Array<byte> byteArray, String charsetName);

            /**
             * Constructs a new String by decoding the specified array of bytes
             * using the specified charset.
             *
             * @param byteArray
             * @param charset
             */
            // String(Array<byte> byteArray, Charset charset)

            /**
             * Allocates a new String so that it represents the sequence
             * of characters currently contained in the character array argument.
             *
             * @param charArray
             * @param share
             */
            //String(Array<char> &charArray, boolean share);

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
            //String(Array<char> &charArray, int offset, int count);

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
            //String(Array<int> codePoints, int offset, int count);

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
            //String(Array<byte> &byteArray, int offset, int length);

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
            //String(Array<byte> &byteArray, int offset, int length, String charsetName);

            /**
             * Construct a new String from target char
             *
             * @param target
             */
            String(char target);

            /**
             * Construct a new String from specific const_string
             *
             * @param original
             */
			String(const_string original);

            /**
             * Construct a new String from specific string
             *
             * @param original
             */
			String(string original);

            /**
             * Construct a new String from specific std::string
             *
             * @param target
             */
			String(const std::string &target);

            /**
             * Destructor
             */
			~String();

        private:
            /**
             * Bounds check the byte array and requested offset & length values
             * @param byteArray
             * @param offset
             * @param length
             */
            //static void checkBounds(Array<byte> &byteArray, int offset, int length);

		public:
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
			char charAt(int index) const;

            /**
             * Returns the character (Unicode code point) at the specified index.
             *
             * @param index
             * @return int
             */
			int codePointAt(int index);

            /**
             * Returns the character (Unicode code point) before the specified index.
             *
             * @param index
             * @return int
             */
			int codePointBefore(int index);

            /**
             * Returns the number of Unicode code points
             * in the specified text range of this String.
             *
             * @param beginIndex
             * @param endIndex
             * @return int
             */
			int codePointCount(int beginIndex, int endIndex);

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
             * @return 0 if the argument string is equal to this string;
             * a value less than 0 if this string is lexicographically
             * less than the string argument;
             * and a value greater than 0 if this string is lexicographically
             * greater than the string argument.
             */
			virtual int compareTo(const String &anotherString) const override;

            /**
             * String compare with another string but ignore case
             *
             * @param targetString
             * @return 0 if the argument string is equal to this string
             * ignoring case considerations.
             * a value less than 0 if this string is lexicographically
             * less than the string argument ignoring case considerations.
             * and a value greater than 0 if this string is lexicographically
             * greater than the string argument ignoring case considerations..
             */
			int compareToIgnoreCase(String targetString) const;


            /**
             * String concatenation
             *
             * @param str
             * @return String
             */
			String concat(String str);


            /**
             * Find substring inside this String
             *
             * @param charSequence
             * @return String
             */
			boolean contains(const CharSequence &charSequence);

            /**
             * Compares this string to the specified CharSequence.
             * The result is true if and only if this String represents
             * the same sequence of char values as the specified sequence.
             *
             * @param charSequence
             * @return boolean
             */
			//boolean contentEquals(const CharSequence &charSequence);

            /**
             * Compares this string to the specified CharSequence.
             * The result is true if and only if this String represents
             * the same sequence of char values as the specified sequence.
             *
             * @param stringBuffer
             * @return boolean
             */
            //boolean contentEquals(const StringBuffer &stringBuffer);

            /**
             * Returns the string representation of the char array argument.
             * The contents of the character array are copied;
             * subsequent modification of the character array does not affect the returned string.
             *
             * @param charArray
             * @return a String that contains the characters of the charArray.
             */
			//static String copyValueOf(const Array<char> &charArray);

            /**
             * Returns the string representation of a specific subarray of the char array argument.
             *
             * @param charArray
             * @param offset
             * @param count
             * @throw IndexOutOfBoundsException if offset is negative, or count is negative,
             * or offset+count is larger than data.length.
             * @return a String that contains the characters of the
             * specified subarray of charArray.
             */
			//static String copyValueOf(const Array<char> &charArray, int offset, int count);

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
             * Compares this string to the specified object.
             *
             * @tparam T
             * @param anObject
             * @return true if the given object represents a String equivalent
             * to this string, false otherwise
             */
			template <class T>
			boolean equals(T anObject) const {
				if (Object::equals(anObject)) {
					return true;
				}
				if (instanceof<String>(anObject)) {
					return (boolean) string_equals(original, anObject.toString());
				}
				return true;
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
            //Array<byte> getBytes(String charSetName) const;

            /**
             * Encodes this String into a sequence of bytes using the charset,
             * storing the result into a new byte array.
             *
             * @param charSet
             * @return
             */
            // Array<byte> getBytes(CharSet charSet) const;

            /**
             * Copies characters from this string into the destination character array.
             *
             * @param sourceBegin
             * @param sourceEnd
             * @param destination
             * @param destinationBegin
             * @throw IndexOutOfBoundsException If :
             * srcBegin is negative.
             * srcBegin is greater than srcEnd
             * srcEnd is greater than the length of this string
             * dstBegin is negative
             * dstBegin+(srcEnd-srcBegin) is larger than dst.length
             */
           // void getChars(int sourceBegin, int sourceEnd, Array<char> destination, int destinationBegin);

            /**
             * Get char to String
             * This function use for class UUID and Long
             *
             * @param index
             * @return String
             */
			String getStringFromIndex(int index);

            /**
             * Returns a hash code for this string.
             *
             * @return int
             */
            //long hashCode() const;
			int indexOf(int ch) const;
			int indexOf(int ch, int fromIndex) const;
			int indexOf(String str) const;
			int indexOf(String str, int fromIndex) const;
			boolean isEmpty() const;
			int lastIndexOf(int ch);
			int lastIndexOf(int ch, int fromIndex);
			int lastIndexOf(String str) const;
			int lastIndexOf(String str, int fromIndex) const;
			int length() const;
			boolean matches(String regex) const;
			String replace(char oldChar, char newChar) const;
			String replaceAll(String regex, String replacement) const;
			String replaceFirst(String regex, String replacement) const;
			Array<String> split(String regex) const;
			//Array<String> split(String regex, int limit) const;
			boolean startsWith(String prefix) const;
			boolean startsWith(String prefix, int toffset) const;
			Array<char> toCharArray() const;
			String toLowerCase() const;
			String toUpperCase();
			String trim();
			string toString() const;
			static String valueOf(boolean target);
			static String valueOf(char target);
			static String valueOf(string target);
			static String valueOf(short target);
			static String valueOf(int target);
			static String valueOf(long target);
			static String valueOf(float target);
			static String valueOf(double target);

			template<typename T, typename... Args>
			static String format(const String& format, T value, Args... args) {
				std::string result;
				std::string inputString(format.toString());
				std::smatch matchResult;
                std::regex reg("%(\\d+\\$)?([-#+0,(\\<]*)?(\\d+)?(\\.\\d+)?([tT])?([a-zA-Z%])");
                while (true) {
                    if (std::regex_search(inputString, matchResult, reg)) {
                        result += matchResult.prefix();
                        result += printObject(matchResult[0], value);
                        if ('%' == result.back()) {
                            inputString = matchResult.suffix().str();
                            continue;
                        }
                        return result + std::string(String::format(matchResult.suffix().str().c_str(), args...).toString());
                    } else {
                        result += inputString;
                        break;
                    }
                }
				return String(result.c_str());
			}

		private:
			static String format(const String& format);
            static std::string print(const std::string& format, short value);
			static std::string print(const std::string& format, int value);
            static std::string print(const std::string& format, long value);
            static std::string print(const std::string& format, unsigned short value);
            static std::string print(const std::string& format, unsigned int value);
            static std::string print(const std::string& format, unsigned long value);
            static std::string print(const std::string& format, double value);
            static std::string print(const std::string& format, float value);
            static std::string print(const std::string& format, char* value);

            template<typename T>
			static std::string printObject(const std::string& format, T value) {
				std::string result;
				char lastChar = format.back();
				switch (lastChar) {
					case 'd':
						if (instanceof<Number>(value))
							result = String::print(format, ((Number*)&value)->longValue());
						else if (typeid(short) == typeid(value))
							result = String::print(format, (short)value);
                        else if (typeid(int) == typeid(value))
                            result = String::print(format, (int)value);
                        else if (typeid(long) == typeid(value))
                            result = String::print(format, (long)value);
                        else if (typeid(unsigned short) == typeid(value))
                            result = String::print(format, (unsigned short)value);
                        else if (typeid(unsigned int) == typeid(value))
                            result = String::print(format, (unsigned int)value);
                        else if (typeid(unsigned long) == typeid(value))
                            result = String::print(format, (unsigned long)value);
						break;
					case 'f':
						if (instanceof<Number>(value))
							result = String::print(format, ((Number*)&value)->doubleValue());
						else if (typeid(float) == typeid(value))
                            result = String::print(format, (float)value);
                        else if (typeid(double) == typeid(value))
                            result = String::print(format, (double)value);
                        break;
					case 's':
						if (instanceof<String>(value))
							result = String::print(format, ((String*)&value)->toString());
						else if (typeid(char*) == typeid(value))
							result = String::print(format, (char*)value);
						break;
					case '%':
						result += lastChar;
						break;
				}
				return result;
			}

		public:
			boolean operator==(const String &target) const;
			boolean operator!=(const String &target) const;
			boolean operator<(const String &target) const;
			boolean operator>(const String &target) const;
			boolean operator<=(const String &target) const;
			boolean operator>=(const String &target) const;
			String operator+(const string &target);
			String operator+(const String &target);
			String operator=(const String &target);
			String operator+=(const String &target);
			String operator+=(const char &target);
			String operator+=(const_string target);
            String subString(int beginIndex);
			String subString(int from, int to);

		public:
			friend std::ostream &operator<<(std::ostream &os, const String &target) {
				os << target.original;
				return os;
			}

			friend String operator+(const_string target1, String const &target2) {
				String result;
				result = target1;
				result += target2;
				return result;
			}
		};
	}
}

#endif  // JAVA_LANG_STRING_STRING_HPP_