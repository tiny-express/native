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

#ifndef NATIVE_JAVA_LANG_DOUBLE_HPP
#define NATIVE_JAVA_LANG_DOUBLE_HPP

#include "../Number/Number.hpp"

namespace Java {
    namespace Lang {
        class Double : public virtual Number {
        private:
            double original;
        public:
            Double();
            Double(double original);
            Double(const Double &target);
            ~Double();

        public:
            char charValue() const;
            string stringValue() const;
            short shortValue() const;
            int intValue() const;
            long longValue() const;
            float floatValue() const;
            double doubleValue() const;
            string toString() const;

            static Double *parseDouble(String target);

        public:
            Double operator+(const Double& target);
            Double operator-(const Double& target);
            Double operator/(const Double& target);
            Double operator*(const Double& target);

            boolean operator==(const Double& target) const;
            boolean operator!=(const Double& target) const;
            boolean operator<(const Double& target) const;
            boolean operator>(const Double& target) const;
            boolean operator<=(const Double& target) const;
            boolean operator>=(const Double& target) const;

            void operator-=(const Double& target);
            void operator+=(const Double& target);
            void operator*=(const Double& target);
            void operator/=(const Double& target);
        };
    }
}
#endif//NATIVE_JAVA_LANG_DOUBLE_HPP