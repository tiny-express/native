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
#ifndef NATIVE_STRINGBUFFER_H
#define NATIVE_STRINGBUFFER_H

#include "../StringBuilder/StringBuilder.hpp"

namespace Java {
    namespace Lang {
        class StringBuffer { //: public CharSequence {
        private:
            string original = NULL;
            string toStringCache = NULL;
            int currentlength = 0;
            int currentcapacity = 0;

        private:
            //void readObject(ObjectInputStream);

            //void writeObject(ObjectOutputStream);

        public:
            StringBuffer();

            StringBuffer(CharSequence *seq);

            explicit StringBuffer(int capacity);

            explicit StringBuffer(String str);

            StringBuffer(const StringBuffer &other);

            StringBuffer append(Object obj);

            StringBuffer append(float floatValue);

            //StringBuffer append(AbstractStringBuilder abs);

            StringBuffer append(string str);

            StringBuffer append(boolean boolValue);

            StringBuffer append(CharSequence *seq);

            StringBuffer append(double doubleValue);

            StringBuffer append(char charValue);

            StringBuffer append(String str);

            StringBuffer append(int intValue);

            StringBuffer append(long longValue);

            StringBuffer append(StringBuffer stringBuffer);

            StringBuffer append(string str, int offset, int len);

            StringBuffer append(CharSequence *seq, int start, int end);

            StringBuffer appendCodePoint(int codePoint);

            int capacity();

            char charAt(int index);

            //IntStream codePoint();

            int codePointAt(int index);

            int codePointBefore(int index);

            int codePointCount(int beginIndex);

            //IntStream codePoint();

            StringBuffer deletes(int start, int end);

            StringBuffer deleteCharAt(int index);

            void ensureCapacity(int minimumCapacity);

            void expandCapacity(int minimumCapacity);

            void getChars(int srcBegin, int srcEnd, string dts, int dstBgin);

            string getValue();

            int indexOf(String str);

            int indexOf(String str, int fromIndex);

            StringBuffer insert(int offset, float floatValue);

            StringBuffer insert(int offset, boolean boolValue);

            StringBuffer insert(int offset, string str);

            StringBuffer insert(int offset, char charValue);

            StringBuffer insert(int offset, String str);

            StringBuffer insert(int offset, long longValue);

            StringBuffer insert(int offset, Object obj);

            StringBuffer insert(int offset, int intValue);

            StringBuffer insert(int offset, double doubleValue);

            StringBuffer insert(int dstOffset, CharSequence *seq, int start, int end);

            StringBuffer insert(int index, string str, int offset, int len);

            int lastIndexOf(String str);

            int lastIndexOf(String str, int fromIndex);

            int length();

            int offsetByCodePoints(int index, int codePointOffset);

            StringBuffer replace(int start, int end, String str);

            StringBuffer reverse();

            void setCharAt(int index, char charValue);

            void setLength(int newLength);

            CharSequence *subSequence(int start, int end);

            String subString(int start);

            String subString(int start, int end);

            String toString();

            void trimToSize();

            ~StringBuffer();

        };
    }
}



#endif //NATIVE_STRINGBUFFER_H
