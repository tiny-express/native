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
 
#ifndef NATIVE_JAVA_LANG_BYTE_HPP
#define NATIVE_JAVA_LANG_BYTE_HPP

#include "../Number/Number.hpp"
#include "../Integer/Integer.hpp"
#include "../../../type.h"


namespace Java {
	namespace Lang {

        class Bytes;

		class Bytes : public virtual Number, public virtual Comparable<Bytes> {

        private:
			byte original;

			/**
			 * Min value of Byte
			 */
			static const byte MIN_VALUE = static_cast<const byte>(-128);

            /**
             * Max value of Byte
             */
			static const byte MAX_VALUE = 127;

            /**
             * The number of bits used to represent a byte value in two's complement binary form.
             */
			static const int SIZE = 8;

            /**
             * The number of bytes used to represent a byte value in two's complement binary form.
             */
            static constexpr int BYTES = SIZE / Bytes::SIZE;

        private:

        public:
            Bytes();

            /**
             * Byte initialization
             *
             * @param byteValue
             */
			Bytes(byte byteValue);

            /**
             * Construct a new Byte with the value of string
             *
             * @param inputString
             */
			Bytes(String inputString);

			~Bytes();

		public:

            /**
             *Return the value of this Byte as a char
             *
             * @return char
             */
			char charValue() const;

            /**
             * Returns the value of this Byte as an String.
             *
             * @return string
             */
			string stringValue() const;

            /**
             * Byte value
             *
             * @return byte
             */
            byte byteValue ();

            /**
             * Compares two byte values numerically.
             *
             * @param byteA
             * @param byteB
             * @return  the value 0 if byteA == byteB; a value less than 0 if byteA < byteB;
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
			int compareTo(const Bytes & other) const override;

            /**
             * Decodes a String into a Byte. Accepts decimal, hexadecimal, and octal numbers
             *
             * @param stringToDecode
             * @throw NumberFormatException - if the String does not contain a parsable byte.
             * @return a Byte object holding the byte value represented by stringToDecode
             */
            static Bytes decode(String stringToDecode);

            /**
             * Double value of Byte
             *
             * @return double
             */
			double doubleValue() const override;

			boolean equals(Object object);

			float floatValue() const override;

			int hashCode();

            static int hashCode(byte byteValue);

			int intValue() const override;

			long longValue() const override;

			static byte parseByte(String stringToParse);

            static byte parseByte(String stringToParse, int radix);
            
			short shortValue() const override;

			String toString();

			static String toString(byte byteValue);

			static int toUnsignedInt(byte byteValue);

			static long toUnsignedLong(byte byteValue);

			static Bytes valueOf(byte byteValue);

			static Bytes valueOf(String stringValue);

            static Bytes valueOf(String stringValue, int radix);
            
		public:
			Bytes operator+(const Bytes &target);

			Bytes operator-(const Bytes &target);

			Bytes operator/(const Bytes &target);

			Bytes operator%(const Bytes &target);

			Bytes operator*(const Bytes &target);

			boolean operator==(const Bytes &target);

			boolean operator!=(const Bytes &target);

			boolean operator<(const Bytes &target);

			boolean operator>(const Bytes &target);

			boolean operator<=(const Bytes &target);

			boolean operator>=(const Bytes &target);

			void operator-=(const Bytes &target);

			void operator+=(const Bytes &target);

			void operator*=(const Bytes &target);

			void operator/=(const Bytes &target);

			void operator%=(const Bytes &target);

            Bytes &operator=(const Bytes &target);

		};

        class ByteCache {
            static ByteCache *instance;

        public:
            ByteCache(){
                cache=cacheInit();
            };

            Array<Bytes> cache;

            Array<Bytes> cacheInit() {
                Array<Bytes> cache1;
                int index = 0;
                for (index; index < 256; index++)
                    cache1.push((Bytes((byte) (index - 128))));
                return cache1;
            }

            static ByteCache *getInstance()
            {
                if (instance == nullptr)
                    instance = new ByteCache();
                return instance;
            }
        };
	}
}
#endif