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

#ifndef JAVA_UTIL_BITSET_HPP_
#define JAVA_UTIL_BITSET_HPP_

#include "../../Lang.hpp"

namespace Java {
    namespace Util {
        class BitSet : public Object, public Cloneable, public Serializable {
        private:
            // Number of bits need to address every bit in a word with default size.
            static const int addressBitsPerWord = 6;
            // Number of bits of a word (default size of a word).
            static const int bitsPerWord = 1 << addressBitsPerWord;
            // Maximum index of a bit in a single word.
            static const int bitIndexMask = bitsPerWord - 1;
            // Used to shift left or right for a partial word mask.
            static const long wordMask = 0xffffffffffffffffL;

        private:
            Array<long> words;
            // The number of words in the logical size of this BitSet.
            int wordsInUse = 0;
            // The size of "words" array (array<long> words) is user-specified or by default.
            boolean sizeIsSticky = false;

        public:
            /**
             * BitSet Constructor
             * Creates a new bit set. All bits are initially false.
             */
            BitSet();

            /**
             * BitSet Constructor
             * Creates a bit set whose initial size is large enough to explicitly represent bits
             * with indices in the range 0 through numberOfBits-1.
             * All bits are initially false.
             *
             * @param numberOfBits
             * @throw NegativeArraySizeException - if the specified initial size is negative.
             */
            BitSet(int numberOfBits);

            /**
             * BitSet Destructor
             */
            virtual ~BitSet();

        private:
            BitSet(const Array<long> &words);

        private:
            /**
             * This method return word index containing a bit has specified index.
             *
             * @param bitIndex
             * @return int
             */
            static int wordIndex(int bitIndex);

        private:
            /**
             * This method use to create a array of word (long) with size based on number of bits.
             *
             * @param numberOfBits
             */
            void initializeWords(int numberOfBits);

        public:
            void bitAnd(const BitSet &set);
            void bitOr(const BitSet &set);
            void bitXor(const BitSet &set);
            void andNot(const BitSet &set);

            /**
             * Returns the number of bits set to true in this BitSet.
             *
             * @return int
             */
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

            /**
             * Returns the "logical size" of this BitSet: the index of the highest set bit in the BitSet plus one.
             * Returns zero if the BitSet contains no set bits.
             *
             * @return int
             */
            int length() const;
            int nextClearBit(int fromIndex) const;
            int nextSetBit(int fromIndex) const;
            int previousClearBit(int fromIndex) const;
            int previousSetBit(int fromIndex) const;
            void set(int bitIndex);
            void set(int bitIndex, boolean value);
            void set(int fromIndex, int toIndex);
            void set(int fromIndex, int toIndex, boolean value);

            /**
             * Returns the number of bits of space actually in use by this BitSet to represent bit values.
             * The maximum element in the set is the size - 1st element.
             *
             * @return int
             */
            int size() const;
//          IntStream stream() const;
            Array<byte> toByteArray() const;
            Array<long> toLongArray() const;

            /**
             * Returns a string representation of this bit set.
             * For every index for which this BitSet contains a bit in the set state,
             * the decimal representation of that index is included in the result.
             * Such indices are listed in order from lowest to highest,
             * separated by ", " (a comma and a space) and surrounded by braces,
             * resulting in the usual mathematical notation for a set of integers.
             *
             * @return string
             */
            string toString() const;

        public:
            static BitSet valueOf(const Array<byte> &bytes);
//          static BitSet valueOf(const ByteBuffer &byteBuffer);
            static BitSet valueOf(const Array<long> &longs);
//          static BitSet valueOf(const LongBuffer &longBuffer);
        };  // class BitSet
    }  // namespace Util
}  // namespace Java

#endif  // JAVA_UTIL_BITSET_HPP_
