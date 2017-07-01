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

#ifndef JAVA_LANG_LONG_HPP_
#define JAVA_LANG_LONG_HPP_

#include "../Number/Number.hpp"

namespace Java {
	namespace Lang {
		
		class Long;
		
		class Long : public virtual Number {
		private:
			long original;
		public:
			Long();
			Long(long original);
			Long(const Long &longnumber);
			~Long();

		public:
			char charValue() const;
			string stringValue() const;
			short shortValue() const;
			int intValue() const;
			long longValue() const;
			float floatValue() const;
			double doubleValue() const;
			string toString() const;
			
			static Long parseLong(String target);
			static Long parseLong(String target, int radix);
            static Long decode(String nm);

		public:
			Long operator+(const Long &target) const;
			Long operator-(const Long &target) const;
			Long operator/(const Long &target) const;
			Long operator%(const Long &target) const;
			Long operator*(const Long &target) const;
			boolean operator==(const Long &target) const;
			boolean operator!=(const Long &target) const;
			boolean operator<(const Long &target) const;
			boolean operator>(const Long &target) const;
			boolean operator<=(const Long &target) const;
			boolean operator>=(const Long &target) const;
			
			void operator-=(const Long &target);
			void operator+=(const Long &target);
			void operator*=(const Long &target);
			void operator/=(const Long &target);
			void operator%=(const Long &target);
		};
	}
}

#endif  // JAVA_LANG__HPP_
