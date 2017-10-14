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

#ifndef JAVA_UTIL_BITSET_HPP
#define JAVA_UTIL_BITSET_HPP

#include "../../Lang.hpp"

namespace Java {
    namespace Util {
        class BitSet : public Object, public Cloneable, public Serializable {
        private:
            // Number of bits need to address every bit in a word with default size.
            static const int ADDRESS_BITS_PER_WORD = 6;
            // Number of bits of a word (default size of a word).
            static const int BITS_PER_WORD = 1 << ADDRESS_BITS_PER_WORD;
            // Maximum index of a bit in a single word.
            static const int BIT_INDEX_MASK = BITS_PER_WORD - 1;
            // Used to shift left or right for a partial word mask.
            static const long WORD_MASK = 0xffffffffffffffffL;

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
             * Creates a bit set whose initial size is large enough to explicitly
             * represent bits with indices in the range 0 through numberOfBits-1.
             * All bits are initially false.
             *
             * @param numberOfBits
             * @throw NegativeArraySizeException - if the specified initial size is negative.
             */
            BitSet(int numberOfBits);

            /**
             * BitSet Constructor
             * Creates a bit set from another bit set instance.
             *
             * @param bitSet
             */
            BitSet(const BitSet &bitSet);

            /**
             * BitSet Destructor
             */
            virtual ~BitSet();

        private:
            /**
             * Creates a bit set using words as the internal representation.
             * The last word (if there is one) must be non-zero.
             *
             * @param words
             */
            BitSet(const Array<long> &words);

        private:
            /**
             * This method return word index containing a bit has specified index.
             *
             * @param bitIndex
             * @return int
             */
            static int wordIndex(int bitIndex);

            /**
             * Checks that fromIndex ... toIndex is a valid range of bit indices.
             *
             * @param fromIndex
             * @param toIndex
             */
            static void checkRange(int fromIndex, int toIndex);

        private:
            /**
             * This method use to create a array of word (long) with size
             * based on number of bits.
             *
             * @param numberOfBits
             */
            void initializeWords(int numberOfBits);

            /**
             * Ensures that the BitSet can accommodate a given wordIndex.
             *
             * @param wordIndex
             */
            void expandTo(int wordIndex);

            /**
             * Ensures that the BitSet can hold enough words.
             *
             * @param wordsRequired
             */
            void ensureCapacity(int wordsRequired);

            /**
             * Sets the field wordsInUse to the logical size in words of the bit set.
             */
            void recalculateWordsInUse();

            /**
             * Attempts to reduce internal storage used for the bits in this bit set.
             */
            void trimToSize();

            /**
             * Free resources.
             */
            void cleanUp();

        private:
            mutable string backupForToString = nullptr;

        public:

            /**
             * @see bitAnd
             */
//          void and(const BitSet &set);

            /**
             * Performs a logical AND of this target bit set with the argument bit set.
             * This bit set is modified so that each bit in it has the value true if and
             * only if it both initially had the value true and the corresponding bit in
             * the bit set argument also had the value true.
             *
             * @param set
             */
            void bitAnd(const BitSet &set);

            /**
             * @see bitOr
             */
//          void or(const BitSet &set);

            /**
             * Performs a logical OR of this bit set with the bit set argument.
             * This bit set is modified so that a bit in it has the value true if and
             * only if it either already had the value true or the corresponding bit in
             * the bit set argument has the value true.
             *
             * @param set
             */
            void bitOr(const BitSet &set);

            /**
             * @see bitXor
             */
//          void xor(const BitSet &set);

            /**
             * Performs a logical XOR of this bit set with the bit set argument.
             * This bit set is modified so that a bit in it has the value true if and
             * only if one of the following statements holds:
             * The bit initially has the value true, and the corresponding bit in
             * the argument has the value false; The bit initially has the value false,
             * and the corresponding bit in the argument has the value true.
             *
             * @param set
             */
            void bitXor(const BitSet &set);

            /**
             * Clears all of the bits in this BitSet whose corresponding bit
             * is set in the specified BitSet.
             *
             * @param set
             */
            void andNot(const BitSet &set);

            /**
             * Returns the number of bits set to true in this BitSet.
             *
             * @return int
             */
            int cardinality() const;

            /**
             * Sets all of the bits in this BitSet to false.
             */
            void clear();

            /**
             * Sets the bit specified by the index to false.
             *
             * @param bitIndex
             * @throw IndexOutOfBoundsException - if the specified index is negative.
             */
            void clear(int bitIndex);

            /**
             * Sets the bits from the specified fromIndex (inclusive) to the specified
             * toIndex (exclusive) to false.
             *
             * @param fromIndex
             * @param toIndex
             * @throw IndexOutOfBoundsException - if fromIndex is negative,
             * or toIndex is negative, or fromIndex is larger than toIndex.
             */
            void clear(int fromIndex, int toIndex);

            /**
             * Cloning this BitSet produces a new BitSet that is equal to it.
             * The clone of the bit set is another bit set that has exactly
             * the same bits set to true as this bit set.
             *
             * @return BitSet
             */
            BitSet clone();

            /**
             * Compares this BitSet against the specified BitSet.
             * The result is true if and only if the target is a Bitset object that has
             * exactly the same set of bits set to true as this bit set.
             * The current sizes of the two bit sets are not compared.
             *
             * @param target
             * @return boolean
             */
            boolean equals(const Object &target) const;

            /**
             * Sets the bit at the specified index to the complement of its current value.
             *
             * @param bitIndex
             */
            void flip(int bitIndex);

            /**
             * Sets each bit from the specified fromIndex (inclusive) to the specified
             * toIndex (exclusive) to the complement of its current value.
             * @param fromIndex
             * @param toIndex
             */
            void flip(int fromIndex, int toIndex);

            /**
             * Returns the value of the bit with the specified index.
             * The value is true if the bit with the index bitIndex is currently
             * set in this BitSet; otherwise, the result is false.
             *
             * @param bitIndex
             * @return boolean
             * @throw IndexOutOfBoundsException - if the specified index is negative.
             */
            boolean get(int bitIndex) const;

            /**
             * Returns a new BitSet composed of bits from this BitSet from
             * fromIndex (inclusive) to toIndex (exclusive).
             *
             * @param fromIndex
             * @param toIndex
             * @return BitSet
             * @throw IndexOutOfBoundsException - if fromIndex is negative,
             * or toIndex is negative, or fromIndex is larger than toIndex.
             */
            BitSet get(int fromIndex, int toIndex) const;

            /**
             * Returns the hash code value for this bit set.
             * The hash code depends only on which bits are set within this BitSet.
             *
             * @return long
             */
            long hashCode() const;

            /**
             * Returns true if the specified BitSet has any bits set to true that
             * are also set to true in this BitSet.
             *
             * @param set
             * @return boolean
             */
            boolean intersects(const BitSet &set);

            /**
             * Returns true if this BitSet contains no bits that are set to true.
             *
             * @return boolean
             */
            boolean isEmpty() const;

            /**
             * Returns the "logical size" of this BitSet: the index of the highest set bit
             * in the BitSet plus one.
             * Returns zero if the BitSet contains no set bits.
             *
             * @return int
             */
            int length() const;

            /**
             * Returns the index of the first bit that is set to false that occurs on or after
             * the specified starting index.
             *
             * @param fromIndex
             * @return int
             * @throw IndexOutOfBoundsException - if the specified index is negative.
             */
            int nextClearBit(int fromIndex) const;

            /**
             * Returns the index of the first bit that is set to true that occurs on or after
             * the specified starting index.
             * If no such bit exists then -1 is returned.
             *
             * @param fromIndex
             * @return int
             * @throw IndexOutOfBoundsException - if the specified index is negative.
             */
            int nextSetBit(int fromIndex) const;

            /**
             * Returns the index of the nearest bit that is set to false that occurs on or
             * before the specified starting index.
             * If no such bit exists, or if -1 is given as the starting index,
             * then -1 is returned.
             *
             * @param fromIndex
             * @return int
             * @throw IndexOutOfBoundsException - if the specified index is less than -1.
             */
            int previousClearBit(int fromIndex) const;

            /**
             * Returns the index of the nearest bit that is set to true that occurs on or
             * before the specified starting index.
             * If no such bit exists, or if -1 is given as the starting index, then -1 is returned.
             *
             * @param fromIndex
             * @return int
             * @throw IndexOutOfBoundsException - if the specified index is less than -1.
             */
            int previousSetBit(int fromIndex) const;

            /**
             * Sets the bit at the specified index to true.
             *
             * @param bitIndex
             * @throw IndexOutOfBoundsException - if the specified index is negative.
             */
            void set(int bitIndex);

            /**
             * Sets the bit at the specified index to the specified value.
             *
             * @param bitIndex
             * @param value
             * @throw IndexOutOfBoundsException - if the specified index is negative.
             */
            void set(int bitIndex, boolean value);

            /**
             * Sets the bits from the specified fromIndex (inclusive) to the specified toIndex (exclusive) to true.
             *
             * @param fromIndex
             * @param toIndex
             * @throw IndexOutOfBoundsException - if fromIndex is negative, or toIndex is negative,
             * or fromIndex is larger than toIndex.
             */
            void set(int fromIndex, int toIndex);

            /**
             * Sets the bits from the specified fromIndex (inclusive) to the specified toIndex (exclusive)
             * to the specified value.
             *
             * @param fromIndex
             * @param toIndex
             * @param value
             * @throw IndexOutOfBoundsException - if fromIndex is negative, or toIndex is negative,
             * or fromIndex is larger than toIndex.
             */
            void set(int fromIndex, int toIndex, boolean value);

            /**
             * Returns the number of bits of space actually in use by this BitSet to represent bit values.
             * The maximum element in the set is the size - 1st element.
             *
             * @return int
             */
            int size() const;

            /**
             * Returns a stream of indices for which this BitSet contains a bit in the set state.
             * The indices are returned in order, from lowest to highest.
             * The size of the stream is the number of bits in the set state,
             * equal to the value returned by the cardinality() method.
             *
             * The bit set must remain constant during the execution of the terminal stream operation.
             * Otherwise, the result of the terminal stream operation is undefined.
             *
             * @return IntStream
             */
//          IntStream stream() const;
            // TODO(truongchauhien): Waiting for IntStream class.

            /**
             * Returns a new byte array containing all the bits in this bit set.
             *
             * @return Array<byte>
             */
            Array<byte> toByteArray() const;

            /**
             * Returns a new long array containing all the bits in this bit set.
             *
             * @return Array<long>
             */
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
            /**
             * Returns a new bit set containing all the bits in the given byte array.
             *
             * @param bytes
             * @return BitSet
             */
            static BitSet valueOf(const Array<byte> &bytes);

            /**
             * Returns a new bit set containing all the bits in the given byte buffer
             * between its position and limit.
             *
             * @param byteBuffer
             * @return BitSet
             */
//          static BitSet valueOf(const ByteBuffer &byteBuffer);
            // TODO(truongchauhien): Waiting for ByteBuffer class.

            /**
             * Returns a new bit set containing all the bits in the given long array.
             *
             * @param longs
             * @return BitSet
             */
            static BitSet valueOf(const Array<long> &longs);

            /**
             * Returns a new bit set containing all the bits in the given long buffer
             * between its position and limit.
             *
             * @param longBuffer
             * @return BitSet
             */
//          static BitSet valueOf(const LongBuffer &longBuffer);
            // TODO(truongchauhien): Waiting for LongBuffer class.

        public:
            /**
             * Checks if the values this bit set and target are equal or not,
             * if yes then condition becomes true.
             *
             * @param target
             * @return boolean
             */
            boolean operator==(const BitSet &target) const;

            /**
             * Assignment operator.
             *
             * @param target
             * @return BitSet &
             */
            BitSet &operator=(const BitSet &target);
        };  // class BitSet
    }  // namespace Util
}  // namespace Java

#endif  // JAVA_UTIL_BITSET_HPP
