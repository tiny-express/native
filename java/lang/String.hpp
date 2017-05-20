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

#ifndef NATIVE_JAVA_LANG_STRING_HPP
#define NATIVE_JAVA_LANG_STRING_HPP

#include "Object.hpp"

namespace Java {
    namespace Lang {
        class String: public virtual Object {
        public:
            static String* parseChar(char target);
            static String* parseCString(char *target);
            static String* parseString(std::string target);
            static String* parseShort(short target);
            static String* parseInt(int target);
            static String* parseLong(long target);
            static String* parseFloat(float target);
            static String* parseDouble(double target);

            char charValue();
            char *cstringValue();
            std::string stringValue();
            short shortValue();
            int intValue();
            long longValue();
            float floatValue();
            double doubleValue();

            String(const char* original);
            String(char *original);
            ~String();
            int length();
            String* toString();

        private:
            char *original;
        };
    }
}

#endif//#ifndef NATIVE_JAVA_LANG_STRING_HPP