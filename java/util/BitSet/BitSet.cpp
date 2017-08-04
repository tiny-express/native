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
                                                String(" > ") +
                                                String("toIndex: ") + String::valueOf(toIndex));
    }
}

void BitSet::initializeWords(int numberOfBits) {
    // Determine index of word contains the most significant bit,
    // then increase by 1 to change index to size.
    int sizeOfWordsArray = wordIndex(numberOfBits - 1) + 1;
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
    if (this->words.length < wordsRequired) {
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

BitSet::BitSet() {
    this->initializeWords(BITS_PER_WORD);
    this->sizeIsSticky = false;
}

BitSet::BitSet(int numberOfBits) {
    if (numberOfBits < 0) {
        throw NegativeArraySizeException(String("numberOfBits < 0: ") +
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
    this->words = Arrays::copyOf(bitSet.words,bitSet.words.length);
    this->wordsInUse = bitSet.wordsInUse;
    this->sizeIsSticky = bitSet.sizeIsSticky;
}

BitSet::~BitSet() { }

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

    int indexOfWord = wordIndex(bitIndex);
    if (indexOfWord >= this->wordsInUse) {
        return;
    }

    this->words[indexOfWord] &= ~(1L << bitIndex);
    this->recalculateWordsInUse();
}

void BitSet::clear(int fromIndex, int toIndex) {
    checkRange(fromIndex, toIndex);

    if (fromIndex == toIndex) {
        return;
    }

    int startWordIndex = wordIndex(fromIndex);
    if (startWordIndex >= this->wordsInUse) {
        return;
    }

    // toIndex decrease by 1 because toIndex is out of specified range.
    int endWordIndex = wordIndex(toIndex - 1);
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
    // TODO(truongchauhien): Implement this method later.
    return false;
}

void BitSet::flip(int bitIndex) {
    if (bitIndex < 0) {
        throw IndexOutOfBoundsException(String("bitIndex < 0: ") +
                                                String::valueOf(bitIndex));
    }
    int indexOfWord = wordIndex(bitIndex);
    this->expandTo(indexOfWord);
    this->words[indexOfWord] ^= (1L << bitIndex);
    this->recalculateWordsInUse();
}

void BitSet::flip(int fromIndex, int toIndex) {
    this->checkRange(fromIndex, toIndex);

    if (fromIndex == toIndex) {
        return;
    }

    int startWordIndex = wordIndex(fromIndex);
    int endWordIndex = wordIndex(toIndex);
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
        throw IndexOutOfBoundsException(String("bitIndex < 0: ") +
                                                String::valueOf(bitIndex));
    }

    int indexOfWord = wordIndex(bitIndex);

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
    // If no set bits in range return empty bitset.
    if (logicalLength <= fromIndex || fromIndex == toIndex) {
        return BitSet(0);
    }

    if (toIndex > logicalLength) {
        toIndex = logicalLength;
    }

    int logicalLengthOfResult = toIndex - fromIndex;
    BitSet result = BitSet(logicalLengthOfResult);
    int targetWords = wordIndex(logicalLengthOfResult - 1) + 1;
    int sourceIndex = wordIndex(fromIndex);
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
        throw IndexOutOfBoundsException(String("fromIndex < 0: ") +
                                                String::valueOf(fromIndex));
    }

    int indexOfWord = wordIndex(fromIndex);
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
        throw IndexOutOfBoundsException(String("fromIndex < 0: ") +
                                                String::valueOf(fromIndex));
    }

    int indexOfWord = wordIndex(fromIndex);
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
        throw IndexOutOfBoundsException(String("fromIndex < -1: ") +
                                                String::valueOf(fromIndex));
    }

    int indexOfWord = wordIndex(fromIndex);
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
        throw IndexOutOfBoundsException(String("fromIndex < -1: ") +
                                                String::valueOf(fromIndex));
    }

    int indexOfWord = wordIndex(fromIndex);
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

    int indexOfWord = wordIndex(bitIndex);
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

    int startWordIndex = wordIndex(fromIndex);
    int endWordIndex = wordIndex(toIndex - 1);
    this->expandTo(endWordIndex);

    long firstWordMask = WORD_MASK << fromIndex;
    long lastWordMask = static_cast<unsigned long>(WORD_MASK) >> (-toIndex & 0b111111);

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

string BitSet::toString() const {
    // TODO(truongchauhien): Implement this method later.
    return nullptr;
}
