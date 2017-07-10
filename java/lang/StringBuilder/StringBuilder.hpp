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

#ifndef NATIVE_JAVA_LANG_STRINGBUILDER_HPP
#define NATIVE_JAVA_LANG_STRINGBUILDER_HPP

#include "../../Lang.hpp"

using namespace Java::IO;

namespace Java {
    namespace Lang {
        class StringBuilder :
                public Object,
                public virtual Serializable,
                public virtual CharSequence
        {
        private:
            string original;
            int size = 0;

        public:
            StringBuilder();
            virtual ~StringBuilder();

        public:
            StringBuilder append(const Boolean &target);
            StringBuilder append(boolean target);
            StringBuilder append(const Character &target);
            StringBuilder append(char target);
            StringBuilder append(const Array<Character> &target);
            StringBuilder append(const Array<char> &target);
            StringBuilder append(const Array<Character> &target, int offset, int length);
            StringBuilder append(const Array<char> &target, int offset, int length);
            StringBuilder append(const CharSequence &target);
            StringBuilder append(const string target);
            StringBuilder append(const Double &target);
            StringBuilder append(double target);
            StringBuilder append(const Float &target);
            StringBuilder append(float target);
            StringBuilder append(const Integer &target);
            StringBuilder append(int target);
            StringBuilder append(const Long &target);
            StringBuilder append(long target);
            StringBuilder append(const Object &target);
            StringBuilder append(const String &target);
            StringBuilder append(const StringBuffer &target);
            StringBuilder appendCodePoint(int codePoint);

            int Capacity() const;
            char charAt(int index) const;
            int codePointAt(int index) const;
            int codePointBefore(int index) const;
            int codePointCount(int beginIndex, int endIndex);

            StringBuilder deleteRange(int start, int end);
            StringBuilder deleteCharAt(int index);

            void ensureCapacity(int minimumCapacity);

            void getChars(int sourceBegin, int sourceEnd, Array<char> &target, int targetBegin);

            int indexOf(const String &target);
            int indexOf(const String &target, int fromIndex);

            StringBuilder insert(int offset, boolean target);
            StringBuilder insert(int offset, const Boolean &target);
            StringBuilder insert(int offset, char target);
            StringBuilder insert(int offset, const Character &character);
            StringBuilder insert(int offset, const Array<char> &target);
            StringBuilder insert(int offset, const Array<Character> &target);
            StringBuilder insert(int index, const Array<char> &target, int offset, int length);
            StringBuilder insert(int index, const Array<Character> &target, int offset, int length);
            StringBuilder insert(int destinationOffset, const CharSequence &target);
            StringBuilder insert(int destinationOffset, const CharSequence &target, int start, int end);
            StringBuilder insert(int offset, const Double &target);
            StringBuilder insert(int offset, double target);
            StringBuilder insert(int offset, const Float &target);
            StringBuilder insert(int offset, float target);
            StringBuilder insert(int offset, const Integer &target);
            StringBuilder insert(int offset, int target);
            StringBuilder insert(int offset, const Long &target);
            StringBuilder insert(int offset, long target);
            StringBuilder insert(int offset, const Object &target);
            StringBuilder insert(int offset, const String &target);

            StringBuilder lastIndexOf(const String &target);
            StringBuilder lastIndexOf(const String &target, int fromIndex);

            int length() const;

            int offsetByCodePoints(int index, int codePointOffset) const;

            StringBuilder replace(int start, int end, const String &str);
            StringBuilder reverse();

            void setCharAt(int index, char target);
            void setCharAt(int index, const Character &target);

            void setLength(int newLength);

            CharSequence subSequence(int start, int end) const;
            String substring(int start) const;
            String substring(int start, int end) const;

            string toString() const;

            void trimToSize();
        };
    }
}

#endif //NATIVE_JAVA_LANG_STRINGBUILDER_HPP
