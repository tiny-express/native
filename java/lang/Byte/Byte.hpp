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

#ifndef NATIVE_JAVA_LANG_BYTE_HPP
#define NATIVE_JAVA_LANG_BYTE_HPP

#include "../../../kernel/String.hpp"
#include "../Number/Number.hpp"
#include "../Integer/Integer.hpp"
#include "../../../kernel/Type.hpp"

namespace Java {
		namespace Lang {
				
				class Byte;
				
				class Byte :
					public virtual Number,
					public virtual Comparable<Byte> {
				private:
						byte original;
						string originalString;
				
				public:
						/**
						 * Min value of Byte
						 */
						static const byte MIN_VALUE = 0;
						
						/**
						 * Max value of Byte
						 */
						static const byte MAX_VALUE = 255;
						
						/**
						 * The number of bits used to represent a byte value in two's complement binary form.
						 */
						static const int SIZE = 8;
						
						/**
						 * The number of bytes used to represent a byte value in two's complement binary form.
						 */
						static constexpr int BYTES = 1;
				
				public:
						/**
						 * Default constructor
						 */
						Byte();
						
						/**
						 * Construct a new Byte with the value of byte
						 *
						 * @param byteValue
						 */
						Byte(byte byteValue);
						
						/**
						 * Construct a new Byte with the value of String
						 *
						 * @param inputString
						 * @throw NumberFormatException If inputString does not contain a parsable byte.
						 */
						Byte(String inputString);
						
						/**
						 * Copy constructor
						 *
						 * @param anotherByte
						 */
						Byte(const Byte &anotherByte);
						
						/**
						 * Destructor, free memory allocated for originalString.
						 */
						~Byte();
				
				public:
						
						/**
						 *Return the value of this Byte as a char
						 *
						 * @return char
						 */
						char charValue() const;
						
						/**
						 * Byte value
						 *
						 * @return byte
						 */
						byte byteValue() const;
						
						/**
						 * Compares two byte values numerically.
						 *
						 * @param byteA
						 * @param byteB
						 * @return the value 0 if byteA == byteB; a value less than 0 if byteA < byteB;
						 * and a value greater than 0 if byteA > byteB
						 */
						static int compare(byte byteA, byte byteB);
						
						/**
						 * Compares two Byte objects numerically
						 *
						 * @param other
						 * @return the value 0 if this Byte is equal to other;
						 * a value less than 0 if this Byte is numerically less than other;
						 * and a value greater than 0 if this Byte is numerically greater than other
						 */
						int compareTo(const Byte &other) const override;
						
						/**
						 * Decodes a String into a Byte. Accepts decimal, hexadecimal, and octal numbers
						 *
						 * @param stringToDecode
						 * @throw NumberFormatException - if the String does not contain a parsable byte.
						 * @return a Byte object holding the byte value represented by stringToDecode
						 */
						static Byte decode(String stringToDecode);
						
						/**
						 * Double value of Byte
						 *
						 * @return double
						 */
						double doubleValue() const override;
						
						/**
						 * Compare this Byte to another Byte object
						 *
						 * @param object
						 * @return true if object is a Byte and has the same value as this Byte; false otherwise
						 */
						// TODO need instanceof temporary use Byte instead of Object
						boolean equals(Byte object);
						
						/**
						 * Returns the value of this Byte as an float.
						 *
						 * @return float
						 */
						float floatValue() const override;
						
						/**
						 * Returns a hash code for this Byte
						 *
						 * @return long
						 */
						long hashCode() const override;
						
						/**
						 * Returns a hash code for this Byte
						 *
						 * @param byteValue
						 * @return int
						 */
						static int hashCode(byte byteValue);
						
						/**
						 * Returns the value of this Byte as an int.
						 *
						 * @return int
						 */
						int intValue() const override;
						
						/**
						 * Returns the value of this Byte as an long.
						 *
						 * @return long
						 */
						long longValue() const override;
						
						/**
						 * Parse the parameter string as a byte with radix =10
						 *
						 * @param stringToParse
						 * @throw NumberFormatException If the string does not contain a parsable byte.
						 * @return the byte value represented by the string argument with radix =10
						 */
						static byte parseByte(String stringToParse);
						
						/**
						 * Parse the parameter string as a byte
						 *
						 * @param stringToParse
						 * @param radix
						 * @throw NumberFormatException If the string does not contain a parsable byte.
						 * @return the byte value represented by the string argument in the specified radix
						 */
						static byte parseByte(String stringToParse, int radix);
						
						/**
						 * Returns the value of this Byte as an short.
						 *
						 * @return short
						 */
						short shortValue() const override;
						
						/**
						 * Returns a string representing this Byte's value
						 *
						 * @return string
						 */
						string toString() const override;
						
						/**
						 * Returns a new String object representing the specified byte with radix = 10
						 *
						 * @param byteValue
						 * @return String
						 */
						static String toString(byte byteValue);
						
						/**
						 * Converts the argument to an int by an unsigned conversion.
						 *
						 * @param byteValue
						 * @return int
						 */
						static int toUnsignedInt(byte byteValue);
						
						/**
						 * Converts the argument to an int by an unsigned conversion.
						 *
						 * @param byteValue
						 * @return long
						 */
						static long toUnsignedLong(byte byteValue);
						
						/**
						 * Returns a Byte instance representing the specified byte value.
						 *
						 * @param byteValue
						 * @return Byte
						 */
						static Byte valueOf(byte byteValue);
						
						/**
						 * Returns a Byte instance representing the specified String value.
						 *
						 * @param stringValue
						 * @return Byte
						 */
						static Byte valueOf(String stringValue);
						
						/**
						 * Returns a Byte instance representing the specified String value with radix
						 *
						 * @param stringValue
						 * @param radix
						 * @return Byte
						 */
						static Byte valueOf(String stringValue, int radix);
				
				public:
						/**
						 * Make a summation with target Byte
						 *
						 * @param target
						 * @return Byte
						 */
						Byte operator+(const Byte &target);
						
						/**
						 * Make a subtraction with target Byte
						 *
						 * @param target
						 * @return Byte
						 */
						Byte operator-(const Byte &target);
						
						/**
						 *  Make a division from this Byte with target
						 *
						 * @param target
						 * @throw ArithmeticException if target equal to zero
						 * @return Byte
						 */
						Byte operator/(const Byte &target);
						
						/**
						 * Make a modulo from this Byte with target
						 *
						 * @param target
						 * @throw ArithmeticException if target equal to zero
						 * @return Byte
						 */
						Byte operator%(const Byte &target);
						
						/**
						 * Make a multiplication from this Byte with target
						 *
						 * @param target
						 * @return Byte
						 */
						Byte operator*(const Byte &target);
						
						/**
						 * Compare 2 Byte
						 *
						 * @param target
						 * @return true if target Byte is equal to this Byte; false otherwise
						 */
						boolean operator==(const Byte &target);
						
						/**
						 * Compare 2 Byte
						 *
						 * @param target
						 * @return true if target Byte is not equal to this Byte; false otherwise
						 */
						boolean operator!=(const Byte &target);
						
						/**
						 * Determine if this Byte is smaller than target
						 *
						 * @param target
						 * @return true if this Byte is smaller than target; false otherwise
						 */
						boolean operator<(const Byte &target);
						
						/**
						 * Determine if this Byte is bigger than target
						 *
						 * @param target
						 * @return true if this Byte is bigger than target; false otherwise
						 */
						boolean operator>(const Byte &target);
						
						/**
						 * Determine if this Byte is equal or less than target
						 *
						 * @param target
						 * @return true if this Byte is equal or less than target; false otherwise
						 */
						boolean operator<=(const Byte &target);
						
						/**
						 * Determine if this Byte is equal or bigger than target
						 *
						 * @param target
						 * @return true if this Byte is equal or bigger than target; false otherwise
						 */
						boolean operator>=(const Byte &target);
						
						/**
						 * Make a subtraction from this Byte with target and assign the result value to this Byte
						 *
						 * @param target
						 * @return Byte
						 */
						Byte &operator-=(const Byte &target);
						
						/**
						 * Make an summation from this Byte with target and assign the result value to this Byte
						 *
						 * @param target
						 * @return Byte
						 */
						Byte &operator+=(const Byte &target);
						
						/**
						 * Make a multiplication from this Byte with target and assign the result value to this Byte
						 *
						 * @param target
						 * @return Byte
						 */
						Byte &operator*=(const Byte &target);
						
						/**
						 * Make a division from this Byte with target and assign the result value to this Byte
						 *
						 * @param target
						 * @return Byte
						 */
						Byte &operator/=(const Byte &target);
						
						/**
						 * Make a modulo from this Byte with target and assign the result value to this Byte
						 *
						 * @param target
						 * @throw ArithmeticException if target equal to zero
						 * @return Byte
						 */
						Byte &operator%=(const Byte &target);
						
						/**
						 *  Assign the value of target to this Byte
						 *
						 * @param target
						 * @throw ArithmeticException if target equal to zero
						 * @return Byte
						 */
						Byte &operator=(const Byte &target);
						
						inline size_t operator()(const Byte &target) const {
							String targetString = target.toString();
							return std::hash<std::string>{}(targetString.toString());
						}
				};
				
				/**
				 * Byte cache for instance byte
				 */
				class ByteCache {
				private:
						static ByteCache *instance;
						
						ByteCache() {
							cache = this->cacheInit();
						};
						
						Array<Byte> cache;
						
						Array<Byte> cacheInit() {
							Array<Byte> cacheArray;
							int index;
							for (index = 0; index < 256; index++) {
								cacheArray.push(Byte(static_cast<byte>(index)));
							}
							return cacheArray;
						}
				
				public:
						static ByteCache *getInstance() {
							if (instance == nullptr) {
								instance = new ByteCache();
							}
							return instance;
						}
						
						Byte getByteAtIndex(int index) {
							return cache[ index ];
						}
				};
		}
}

namespace std {
		template <>
		struct hash<Byte> {
				std::size_t operator()(const Byte &k) const {
					return Byte()(k);
				}
		};
}
#endif