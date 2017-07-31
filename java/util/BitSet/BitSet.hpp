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

#include "../../Lang.hpp"

namespace Java {
    namespace Util {
        class BitSet : public Object {
        private:
            Array<long> words;
            int wordsInUse = 0;

        public:
            BitSet();
            BitSet(int numberOfBits);
            ~BitSet();

        public:
            void AND(const BitSet &set);
            void OR(const BitSet &set);
            void XOR(const BitSet &set);
            void andNot(const BitSet &set);
            int cardinality() const;
            void clear();
            void clear(int bitIndex);
            void clear(int fromIndex, int toIndex);
            BitSet clone();
            boolean equals(const Object &target) const;
            void flip(int bitIndex);
            void flip(int fromIndex, int toIndex);
            boolean get(int bitIndex) const;
            BitSet get(int fromIndex, int toIndex) const;
            long hashCode() const;
            boolean intersects(const BitSet &set);
            boolean isEmpty() const;
            int length() const;
            int nextClearBit(int fromIndex) const;
            int nextSetBit(int fromIndex) const;
            int previousClearBit(int fromIndex) const;
            int previousSetBit(int fromIndex) const;
            void set(int bitIndex);
            void set(int bitIndex, boolean value);
            void set(int fromIndex, int toIndex);
            void set(int fromIndex, int toIndex, boolean value);
            int size() const;
//          IntStream stream() const;
            Array<byte> toByteArray() const;
            Array<long> toLongArray() const;
            string toString() const;

        public:
            static BitSet valueOf(const Array<byte> &bytes);
//          static BitSet valueOf(const ByteBuffer &byteBuffer);
            static BitSet valueOf(const Array<long> &longs);
//          static BitSet valueOf(const LongBuffer &longBuffer);
        };
    }  // namespace Util
}  // namespace Java
