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

#include "../BitSet/BitSet.hpp"
#include "../../lang/NegativeArraySizeException/NegativeArraySizeException.hpp"
#include "../Arrays/Arrays.hpp"
#include "../../lang/StringBuilder/StringBuilder.hpp"

using namespace Java::Util;

int BitSet::wordIndex(int bitIndex) {
    // indexOfWord = bitIndex / (2 ^ addressBitsPerWord)
    // (2 ^ addressBitsPerWord) is size of word.
    int indexOfWord = bitIndex >> ADDRESS_BITS_PER_WORD;
    return indexOfWord;
}

void BitSet::checkRange(int fromIndex, int toIndex) {
    if (fromIndex < 0) {
        throw IndexOutOfBoundsException(String("fromIndex < 0: ") +
                                                String::valueOf(fromIndex));
    }
    if (toIndex < 0) {
        throw IndexOutOfBoundsException(String("toIndex < 0: ") +
                                                String::valueOf(toIndex));
    }
    if (fromIndex > toIndex) {
        throw IndexOutOfBoundsException(String("fromIndex: ") + String::valueOf(fromIndex) +
                                                String(" > toIndex: ") +
                                                String::valueOf(toIndex));
    }
}

void BitSet::initializeWords(int numberOfBits) {
    // Determine index of word contains the most significant bit,
    // then increase by 1 to change index to size.
    int sizeOfWordsArray = this->wordIndex(numberOfBits - 1) + 1;
    this->words = Array<long>(sizeOfWordsArray);
    // Set value of new word to 0.
    int indexOfWordsArray;
    for (indexOfWordsArray = 0;
         indexOfWordsArray < this->words.length; ++indexOfWordsArray) {
        this->words[indexOfWordsArray] = 0L;
    }
}

void BitSet::expandTo(int wordIndex) {
    int wordsRequired = wordIndex + 1;
    if (this->wordsInUse < wordsRequired) {
        this->ensureCapacity(wordsRequired);
        this->wordsInUse = wordsRequired;
    }
}

void BitSet::ensureCapacity(int wordsRequired) {
    if (this->words.length >= wordsRequired) {
        return;
    }
    // Allocate larger of doubled size or required size.
    int wordsRequested = Math::max(2 * this->words.length, wordsRequired);
    int oldWordsArrayLength = this->words.length;
    this->words = Arrays::copyOf(this->words, wordsRequested);
    this->sizeIsSticky = false;
    // Set value of new word to 0.
    int indexOfWordsArray;
    for (indexOfWordsArray = oldWordsArrayLength;
         indexOfWordsArray < this->words.length; ++indexOfWordsArray) {
        this->words[indexOfWordsArray] = 0L;
    }
}

void BitSet::recalculateWordsInUse() {
    // Traverse the bitset until a used word is found.
    int indexOfWordsArray = this->wordsInUse - 1;
    while (indexOfWordsArray >= 0) {
        if (this->words[indexOfWordsArray] != 0) {
            break;
        }
        indexOfWordsArray = indexOfWordsArray - 1;
    }
    // Change index to logical size.
    this->wordsInUse = indexOfWordsArray + 1;
}

void BitSet::trimToSize() {
    if (this->wordsInUse != this->words.length) {
        this->words = Arrays::copyOf(this->words, this->wordsInUse);
    }
}

void BitSet::cleanUp() {
    if (this->backupForToString != nullptr) {
        free(this->backupForToString);
    }
}

BitSet::BitSet() {
    this->initializeWords(BITS_PER_WORD);
    this->sizeIsSticky = false;
}

BitSet::BitSet(int numberOfBits) {
    if (numberOfBits < 0) {
        throw NegativeArraySizeException("numberOfBits < 0: " +
                                                 String::valueOf(numberOfBits));
    }
    this->initializeWords(numberOfBits);
    this->sizeIsSticky = true;
}

BitSet::BitSet(const Array<long> &words) {
    this->words = words;
    this->wordsInUse = words.length;
}

BitSet::BitSet(const BitSet &bitSet){
    this->words = Arrays::copyOf(bitSet.words, bitSet.words.length);
    this->wordsInUse = bitSet.wordsInUse;
    this->sizeIsSticky = bitSet.sizeIsSticky;
}

BitSet::~BitSet() {
    this->cleanUp();
}

void BitSet::bitAnd(const BitSet &set) {
    if (*this == set) {
        // Nothing will be changed.
        return;
    }

    while (this->wordsInUse > set.wordsInUse) {
        // Decrease by 1 to change logical size to index.
        this->wordsInUse = this->wordsInUse - 1;
        this->words[this->wordsInUse] = 0L;
    }

    // Perform logical AND on words in common.
    int index;
    for (index = 0; index < this->wordsInUse; ++index) {
        words[index] &= set.words[index];
    }

    this->recalculateWordsInUse();
}

void BitSet::bitOr(const BitSet &set) {
    if (*this == set) {
        return;
    }

    int wordsInCommon = Math::min(this->wordsInUse, set.wordsInUse);

    if (this->wordsInUse < set.wordsInUse) {
        this->ensureCapacity(set.wordsInUse);
        this->wordsInUse = set.wordsInUse;
    }

    // Perform logical OR on words in common.
    int index;
    for (index = 0; index < wordsInCommon; ++index) {
        this->words[index] |= set.words[index];
    }

    // Copy any remaining words.
    if (wordsInCommon < set.wordsInUse) {
        for (index = wordsInCommon;
             index < set.wordsInUse; ++index) {
            this->words[index] = set.words[index];
        }
    }
}

void BitSet::bitXor(const BitSet &set) {
    int wordsInCommon = Math::min(this->wordsInUse, set.wordsInUse);

    if (this->wordsInUse < set.wordsInUse) {
        this->ensureCapacity(set.wordsInUse);
        this->wordsInUse = set.wordsInUse;
    }

    // Perform logical XOR on words in common.
    int index;
    for (index = 0; index < wordsInCommon; ++index) {
        this->words[index] ^= set.words[index];
    }

    // Copy any remaining words.
    if (wordsInCommon < set.wordsInUse) {
        for (index = wordsInCommon;
             index < set.wordsInUse; ++index) {
            this->words[index] = set.words[index];
        }
    }

    this->recalculateWordsInUse();
}

void BitSet::andNot(const BitSet &set) {
    // Perform logical (a & !b) on words in common.
    int wordsInCommon = Math::min(this->wordsInUse, set.wordsInUse);

    int index;
    for (index = 0; index < wordsInCommon; ++index) {
        this->words[index] &= ~set.words[index];
    }

    this->recalculateWordsInUse();
}

int BitSet::cardinality() const {
    int numberOfBitsSetToTrue = 0;
    int indexOfWords;
    for (indexOfWords = 0; indexOfWords < this->wordsInUse; indexOfWords++) {
        numberOfBitsSetToTrue = numberOfBitsSetToTrue +
                Long::bitCount(this->words[indexOfWords]);
    }
    return numberOfBitsSetToTrue;
}

void BitSet::clear() {
    while (this->wordsInUse > 0) {
        // Must decrease by 1 first, because we want change logical size to index.
        this->wordsInUse = this->wordsInUse - 1;
        this->words[this->wordsInUse] = 0L;
    }
}

void BitSet::clear(int bitIndex) {
    if (bitIndex < 0) {
        throw IndexOutOfBoundsException("bitIndex < 0: " +
                                                String::valueOf(bitIndex));
    }

    int indexOfWord = this->wordIndex(bitIndex);
    if (indexOfWord >= this->wordsInUse) {
        return;
    }

    this->words[indexOfWord] &= ~(1L << bitIndex);
    this->recalculateWordsInUse();
}

void BitSet::clear(int fromIndex, int toIndex) {
    this->checkRange(fromIndex, toIndex);

    if (fromIndex == toIndex) {
        return;
    }

    int startWordIndex = this->wordIndex(fromIndex);
    if (startWordIndex >= this->wordsInUse) {
        return;
    }

    // toIndex decrease by 1 because toIndex is out of specified range.
    int endWordIndex = this->wordIndex(toIndex - 1);
    if (endWordIndex >= this->wordsInUse) {
        toIndex = this->length();
        endWordIndex = this->wordsInUse - 1;
    }

    long firstWordMask = WORD_MASK << fromIndex;
    // In Java, the line below is equivalent to: long lastWordMask = wordMask >>> -toIndex;
    long lastWordMask = static_cast<unsigned long>(WORD_MASK) >> (-toIndex & 0b111111);

    if (startWordIndex == endWordIndex) {
        // Case 1: fromIndex and toIndex are in one word.
        this->words[startWordIndex] &= ~(firstWordMask & lastWordMask);
    } else {
        // Case 2: Multiple words.
        // Handle first word.
        this->words[startWordIndex] &= ~firstWordMask;
        // Handle intermediate words, if any.
        int indexOfIntermediateWords;
        for (indexOfIntermediateWords = startWordIndex + 1;
             indexOfIntermediateWords < endWordIndex; indexOfIntermediateWords++) {
            this->words[indexOfIntermediateWords] = 0L;
        }
        // Handle last word.
        this->words[endWordIndex] &= ~lastWordMask;
    }

    this->recalculateWordsInUse();
}

BitSet BitSet::clone() {
    if (!sizeIsSticky) {
        this->trimToSize();
    }

    return *this;
}

boolean BitSet::equals(const Object &target) const {
    const BitSet* pointerToTarget = dynamic_cast<const BitSet *>(&target);
    if (pointerToTarget == nullptr) {
        return false;
    }

    if (this->wordsInUse != pointerToTarget->wordsInUse) {
        return false;
    }

    int indexOfWord;
    for (indexOfWord = 0; indexOfWord < this->wordsInUse; ++indexOfWord) {
        if (this->words[indexOfWord] != pointerToTarget->words[indexOfWord]) {
            return false;
        }
    }

    return true;
}

void BitSet::flip(int bitIndex) {
    if (bitIndex < 0) {
        throw IndexOutOfBoundsException("bitIndex < 0: " +
                                                String::valueOf(bitIndex));
    }
    int indexOfWord = this->wordIndex(bitIndex);
    this->expandTo(indexOfWord);
    this->words[indexOfWord] ^= (1L << bitIndex);
    this->recalculateWordsInUse();
}

void BitSet::flip(int fromIndex, int toIndex) {
    this->checkRange(fromIndex, toIndex);

    if (fromIndex == toIndex) {
        return;
    }

    int startWordIndex = this->wordIndex(fromIndex);
    int endWordIndex = this->wordIndex(toIndex);
    this->expandTo(endWordIndex);

    long firstWordMask = WORD_MASK << fromIndex;
    long lastWordMask = static_cast<unsigned long>(WORD_MASK) >> (-toIndex & 0b111111);

    if (startWordIndex == endWordIndex) {
        // Case 1: One word.
        this->words[startWordIndex] ^= (firstWordMask & lastWordMask);
    } else {
        // Case 2:: Multiple words.
        // Handle the first word.
        this->words[startWordIndex] ^= firstWordMask;
        // Handle intermediate words, if any.
        int indexOfIntermediateWord;
        for (indexOfIntermediateWord = startWordIndex + 1;
             indexOfIntermediateWord < endWordIndex; ++indexOfIntermediateWord) {
            this->words[indexOfIntermediateWord] ^= WORD_MASK;
        }
        // Handle the last words.
        this->words[endWordIndex] ^= lastWordMask;
    }

    this->recalculateWordsInUse();
}

boolean BitSet::get(int bitIndex) const {
    if (bitIndex < 0) {
        throw IndexOutOfBoundsException("bitIndex < 0: " +
                                                String::valueOf(bitIndex));
    }

    int indexOfWord = this->wordIndex(bitIndex);

    // bitIndex is out of range, default value is false.
    if (indexOfWord >= this->wordsInUse) {
        return false;
    }

    // Checking current bit at bitIndex in word at wordIndex.
    return ((this->words[indexOfWord] & (1L << bitIndex)) != 0);
}

BitSet BitSet::get(int fromIndex, int toIndex) const {
    this->checkRange(fromIndex, toIndex);

    int logicalLength = this->length();
    // If no set bits in range return empty BitSet.
    if (logicalLength <= fromIndex || fromIndex == toIndex) {
        return BitSet(0);
    }

    if (toIndex > logicalLength) {
        toIndex = logicalLength;
    }

    int logicalLengthOfResult = toIndex - fromIndex;
    BitSet result = BitSet(logicalLengthOfResult);
    int targetWords = this->wordIndex(logicalLengthOfResult - 1) + 1;
    int sourceIndex = this->wordIndex(fromIndex);
    boolean wordAligned = ((fromIndex & BIT_INDEX_MASK) == 0);

    // Process all words but the last word.
    int index;
    for (index = 0; index < targetWords - 1; ++index, ++sourceIndex) {
        if (wordAligned) {
            result.words[index] = this->words[sourceIndex];
        } else {
            result.words[index] =
                    (static_cast<unsigned long>(this->words[sourceIndex]) >> fromIndex) |
                    (this->words[sourceIndex + 1] << (-fromIndex & 0b111111));
        }
    }

    // Process the last word.
    long lastWordMask =
            static_cast<unsigned long>(WORD_MASK) >> (-toIndex & 0b111111);
    if (((toIndex - 1) & BIT_INDEX_MASK) < (fromIndex & BIT_INDEX_MASK)) {
        result.words[targetWords - 1] =
                (static_cast<unsigned long>(this->words[sourceIndex]) >> fromIndex) |
                        (words[sourceIndex+1] & lastWordMask) << (-fromIndex & 0b111111);
    } else {
        result.words[targetWords - 1] =
                static_cast<unsigned long>(this->words[sourceIndex] & lastWordMask) >> fromIndex;
    }

    // Set wordsInUse correctly.
    result.wordsInUse = targetWords;
    result.recalculateWordsInUse();

    return result;
}

long BitSet::hashCode() const {
    // BitSet hash code algorithm.
    long hash = 1234;
    for (int i = words.length; --i >= 0; )
        hash ^= this->words[i] * (i + 1);
    return (hash >> 32) ^ hash;
}

boolean BitSet::intersects(const BitSet &set) {
    int endWordIndex = Math::min(this->wordsInUse, set.wordsInUse);
    int index;
    for (index = 0; index <= endWordIndex; ++index) {
        if ((this->words[index] & set.words[index]) != 0) {
            return true;
        }
    }
    return false;
}

boolean BitSet::isEmpty() const {
    return (this->wordsInUse == 0);
}

int BitSet::length() const {
    if (this->wordsInUse == 0) {
        return 0;
    }
    int indexOfWordContainHighestBit = this->wordsInUse - 1;
    // Number of bits in use.
    int logicalSize = (BITS_PER_WORD * indexOfWordContainHighestBit) +
            (BITS_PER_WORD - Long::numberOfLeadingZeros(words[indexOfWordContainHighestBit]));
    return logicalSize;
}

int BitSet::nextClearBit(int fromIndex) const {
    if (fromIndex < 0) {
        throw IndexOutOfBoundsException("fromIndex < 0: " +
                                                String::valueOf(fromIndex));
    }

    int indexOfWord = this->wordIndex(fromIndex);
    if (indexOfWord >= this->wordsInUse) {
        return fromIndex;
    }

    long word = ~this->words[indexOfWord] & (WORD_MASK << fromIndex);

    while (indexOfWord <= this->wordsInUse) {
        if (word != 0) {
            return (indexOfWord * BITS_PER_WORD) + Long::numberOfTrailingZeros(word);
        }

        indexOfWord = indexOfWord + 1;
        if (indexOfWord == this->wordsInUse) {
            return this->wordsInUse * BITS_PER_WORD;
        }

        word = ~this->words[indexOfWord];
    }

    // while loop must return a value, so don't need to return anything after while loop.
}

int BitSet::nextSetBit(int fromIndex) const {
    if (fromIndex < 0) {
        throw IndexOutOfBoundsException("fromIndex < 0: " +
                                                String::valueOf(fromIndex));
    }

    int indexOfWord = this->wordIndex(fromIndex);
    if (indexOfWord >= this->wordsInUse) {
        return -1;
    }

    long word = this->words[indexOfWord] & (WORD_MASK << fromIndex);

    while (indexOfWord <= this->wordsInUse) {
        if (word != 0) {
            return (indexOfWord * BITS_PER_WORD) + Long::numberOfTrailingZeros(word);
        }

        indexOfWord = indexOfWord + 1;
        if (indexOfWord == this->wordsInUse) {
            return -1;
        }

        word = this->words[indexOfWord];
    }

    // while loop must return a value, so don't need to return anything after while loop.
}

int BitSet::previousClearBit(int fromIndex) const {
    if (fromIndex < 0) {
        if (fromIndex == -1) {
            return -1;
        }
        throw IndexOutOfBoundsException("fromIndex < -1: " +
                                                String::valueOf(fromIndex));
    }

    int indexOfWord = this->wordIndex(fromIndex);
    if (indexOfWord >= this->wordsInUse) {
        return fromIndex;
    }

    long word = ~this->words[indexOfWord] &
            (static_cast<unsigned long>(WORD_MASK) >> (-(fromIndex + 1) & 0b111111));

    while (indexOfWord >= 0) {
        if (word != 0) {
            return (indexOfWord + 1) * BITS_PER_WORD - 1 - Long::numberOfLeadingZeros(word);
        }

        if (indexOfWord == 0) {
            return -1;
        }

        indexOfWord = indexOfWord - 1;
        word = ~this->words[indexOfWord];
    }

    // while loop must return a value, so don't need to return anything after while loop.
}

int BitSet::previousSetBit(int fromIndex) const {
    if (fromIndex < 0) {
        if (fromIndex == -1) {
            return -1;
        }
        throw IndexOutOfBoundsException("fromIndex < -1: " +
                                                String::valueOf(fromIndex));
    }

    int indexOfWord = this->wordIndex(fromIndex);
    if (indexOfWord >= this->wordsInUse) {
        return this->length() - 1;
    }

    long word = this->words[indexOfWord] &
            (static_cast<unsigned long>(WORD_MASK) >> (-(fromIndex + 1) & 0b111111));

    while (indexOfWord >= 0) {
        if (word != 0) {
            return (indexOfWord + 1) * BITS_PER_WORD - 1 - Long::numberOfLeadingZeros(word);
        }

        if (indexOfWord == 0) {
            return -1;
        }

        indexOfWord = indexOfWord - 1;
        word = this->words[indexOfWord];
    }
}

void BitSet::set(int bitIndex) {
    if (bitIndex < 0) {
        throw IndexOutOfBoundsException(String("bitIndex < 0: ") +
                                                String::valueOf(bitIndex));
    }

    int indexOfWord = this->wordIndex(bitIndex);
    this->expandTo(indexOfWord);
    this->words[indexOfWord] |= (1L << bitIndex);
}

void BitSet::set(int bitIndex, boolean value) {
    if (value) {
        this->set(bitIndex);
    } else {
        this->clear(bitIndex);
    }
}

void BitSet::set(int fromIndex, int toIndex) {
    this->checkRange(fromIndex, toIndex);

    if (fromIndex == toIndex) {
        return;
    }

    int startWordIndex = this->wordIndex(fromIndex);
    int endWordIndex = this->wordIndex(toIndex - 1);
    this->expandTo(endWordIndex);

    long firstWordMask = WORD_MASK << fromIndex;
    long lastWordMask =
            static_cast<unsigned long>(WORD_MASK) >> (-toIndex & 0b111111);

    if (startWordIndex == endWordIndex) {
        // Case 1: One word.
        this->words[startWordIndex] |= (firstWordMask & lastWordMask);
    } else {
        // Case 2: Multiple words.
        // Handle first word.
        this->words[startWordIndex] |= firstWordMask;
        // handle intermediate words, if any.
        int indexOfIntermediateWords;
        for (indexOfIntermediateWords = startWordIndex + 1;
             indexOfIntermediateWords < endWordIndex; ++indexOfIntermediateWords) {
            this->words[indexOfIntermediateWords] = WORD_MASK;
        }
        // Handle last word.
        this->words[endWordIndex] |= lastWordMask;
    }
}

void BitSet::set(int fromIndex, int toIndex, boolean value) {
    if (value) {
        this->set(fromIndex, toIndex);
    } else {
        this->clear(fromIndex, toIndex);
    }
}

int BitSet::size() const {
    return this->words.length * BITS_PER_WORD;
}

Array<byte> BitSet::toByteArray() const {
    // This is an alternative version, without supports from ByteBuffer data type.

    if (this->wordsInUse == 0) {
        return Array<byte>(0);
    }

    const int numberOfBytesPerWord = 8;

    Array<byte> result;
    int indexOfWord;
    long word;
    byte *bytePointerToWord;
    int indexOfEightPartsOfWord;
    unsigned long unsignedWord;
    // Handle all words before the last word.
    for (indexOfWord = 0; indexOfWord < this->wordsInUse - 1; ++indexOfWord) {
        word = this->words[indexOfWord];
        unsignedWord = static_cast<unsigned long>(word);
        bytePointerToWord = (byte *)&unsignedWord;
        for (indexOfEightPartsOfWord = 0;
             indexOfEightPartsOfWord < numberOfBytesPerWord;
             ++indexOfEightPartsOfWord) {
            result.push(bytePointerToWord[indexOfEightPartsOfWord]);
        }
    }

    // Handle the last word.
    word = this->words[this->wordsInUse - 1];
    unsignedWord = static_cast<unsigned long>(word);
    bytePointerToWord = (byte *)&unsignedWord;
    int numberOfTrailingZeroBytes = 0;
    indexOfEightPartsOfWord = numberOfBytesPerWord - 1;
    while (indexOfEightPartsOfWord >= 0) {
        if (bytePointerToWord[indexOfEightPartsOfWord] == 0) {
            numberOfTrailingZeroBytes = numberOfTrailingZeroBytes + 1;
            indexOfEightPartsOfWord = indexOfEightPartsOfWord - 1;
        } else {
            break;
        }
    }

    int numberOfHeadingNonZeroByte = numberOfBytesPerWord - numberOfTrailingZeroBytes;
    for (indexOfEightPartsOfWord = 0;
         indexOfEightPartsOfWord < numberOfHeadingNonZeroByte;
         ++indexOfEightPartsOfWord) {
        result.push(bytePointerToWord[indexOfEightPartsOfWord]);
    }

    return result;
}

Array<long> BitSet::toLongArray() const {
    return Arrays::copyOf(this->words, this->wordsInUse);
}

string BitSet::toString() const {
    // Optimizing String Builder initial size.
    int numberOfBits;
    if (this->wordsInUse > 128) {
        numberOfBits = this->cardinality();
    } else {
        numberOfBits = this->wordsInUse * BITS_PER_WORD;
    }

    StringBuilder stringBuilder(6 * numberOfBits + 2);
    stringBuilder.append('{');

    int indexOfNextSetBit = this->nextSetBit(0);
    while (indexOfNextSetBit != -1) {
        stringBuilder.append(indexOfNextSetBit);
        indexOfNextSetBit = this->nextSetBit(indexOfNextSetBit + 1);
        if (indexOfNextSetBit == -1) {
            break;
        } else {
            stringBuilder.append(',').append(' ');
        }
    }
    stringBuilder.append('}');

    free(this->backupForToString);
    this->backupForToString = stringCopy(stringBuilder.toString());

    return this->backupForToString;
}

BitSet BitSet::valueOf(const Array<byte> &bytes) {
    // This is an alternative version, without supports from ByteBuffer data type.

    const int bytesPerWord = 8;

    int numberOfHeadingNoneZeroBytes = bytes.length;
    while (numberOfHeadingNoneZeroBytes > 0 &&
            bytes[numberOfHeadingNoneZeroBytes - 1] == 0) {
        numberOfHeadingNoneZeroBytes = numberOfHeadingNoneZeroBytes - 1;
    }
    // Length of words is always >= 1 if numberOfHeadingNoneZeroBytes > 0
    Array<long> words((numberOfHeadingNoneZeroBytes + 7) / 8);

    int indexOfByte;
    byte *pointerToWord;
    for (indexOfByte = 0;
         indexOfByte < numberOfHeadingNoneZeroBytes; ++indexOfByte) {
        pointerToWord = (byte *)&words[indexOfByte / bytesPerWord];
        pointerToWord[indexOfByte % bytesPerWord] = bytes[indexOfByte];
    }

    return BitSet(words);
}

BitSet BitSet::valueOf(const Array<long> &longs) {
    int numberOfHeadingNoneZeroWords = longs.length;
    while (numberOfHeadingNoneZeroWords > 0 &&
            longs[numberOfHeadingNoneZeroWords - 1] == 0) {
        numberOfHeadingNoneZeroWords = numberOfHeadingNoneZeroWords - 1;
    }
    return BitSet(Arrays::copyOf(longs, numberOfHeadingNoneZeroWords));
}

boolean BitSet::operator==(const BitSet &target) const {
    return (this->equals(target));
}

BitSet& BitSet::operator=(const BitSet &target) {
    this->cleanUp();
    this->words = Arrays::copyOf(target.words, target.words.length);
    this->wordsInUse = target.wordsInUse;
    this->sizeIsSticky = target.sizeIsSticky;
}
