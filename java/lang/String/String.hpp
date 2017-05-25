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

#include "../Object/Object.hpp"
#include "../Array/Array.hpp"
#include "../CharSequence/CharSequence.hpp"

namespace Java {
    namespace Lang {
        class String: public virtual Object {
        private:
            string original;
            int size = 0;
        public:
            String();
            String(const_string original);
            String(string original);
            String(Array<char> &chars);
            String(Array<byte> &bytes);
            String(const String &target);
            virtual ~String();
        public:
            char charAt(int index);
            int	compareTo(String anotherString);
            int	compareToIgnoreCase(String str);
            String concat(String str);
            boolean contains(CharSequence s);
            Array<byte> getBytes() const;
            boolean endsWith(String suffix);
            static String fromCharArray(Array<char> &chars);
            int indexOf(int ch) const;
            int indexOf(int ch, int fromIndex) const;
            int indexOf(String str) const;
            int indexOf(String str, int fromIndex) const;
            boolean isEmpty() const;
            int lastIndexOf(int ch);
            int lastIndexOf(int ch, int fromIndex);
            int lastIndexOf(String str) const;
            int lastIndexOf(String str, int fromIndex) const;
            int length();
            boolean matches(String regex) const;
            String replace(char oldChar, char newChar) const;
            String replaceAll(String regex, String replacement) const;
            String replaceFirst(String regex, String replacement) const;
            Array<String> split(String regex) const;
            String split(String regex, int limit) const;
            boolean startsWith(String prefix) const;
            boolean startsWith(String prefix, int toffset) const;
            Array<char> toCharArray() const;
            String toLowerCase() const;
            string toString() const;
            String toUpperCase();
            String trim();
            static String valueOf(boolean target);
            static String valueOf(char target);
            static String valueOf(string target);
            static String valueOf(short target);
            static String valueOf(int target);
            static String valueOf(long target);
            static String valueOf(float target);
            static String valueOf(double target);
        public:
            String operator+(const String& target);
            String operator=(const String &target);
            void operator+=(const String& target);
            boolean operator<(const String& target) const;
            boolean operator==(const String& target) const;
            boolean operator!=(const String& target);
            friend String operator+(const_string target1, String const &target2) {
                String result;
                result = target1;
                result += target2;
                return result;
            };
        };
    }
}

#endif//#ifndef NATIVE_JAVA_LANG_STRING_HPP
