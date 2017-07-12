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


namespace Java {
	namespace Lang {

        class Bytes;

		class Bytes : public virtual Number,
            public virtual Comparable<Bytes>{

        private:
			byte original;
			//Min value of a byte
			static const byte MIN_VALUE = -128;
			//Max value of a byte
			static const byte MAX_VALUE = 127;
			static const int SIZE = 8;

        private:

        public:
            Bytes();
			Bytes(byte original);
			Bytes(String string);
			~Bytes();

		public:
			char charValue() const;

			string stringValue() const;

            byte byteValue ();

			static int compare(byte, byte);

			int compareTo(const Bytes & ) const;

			static Bytes decode(String);

			double doubleValue() const;

			boolean equals(Object );

			float floatValue() const;

			int hashCode();

            static int hashCode(byte );

			int intValue() const;

			long longValue() const ;

			static byte parseByte(String);

            static byte parseByte(String, int);
            
			short shortValue() const;

			String toString();

			static String toString(byte);

			static int toUnsignedInt(byte);

			static long toUnsignedLong(byte);

			static Bytes valueOf(byte);

			static Bytes valueOf(String);

            static Bytes valueOf(String,int);
            
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

            void operator=(const Bytes &target);

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
                if (!instance)
                    instance = new ByteCache();
                return instance;
            }
        };
	}
}
#endif