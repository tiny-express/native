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

using namespace Java::Util;

int BitSet::wordIndex(int bitIndex) {
    // indexOfWord = bitIndex / (2 ^ addressBitsPerWord)
    // (2 ^ addressBitsPerWord) is size of word.
    int indexOfWord = bitIndex >> addressBitsPerWord;
    return indexOfWord;
}

void BitSet::initializeWords(int numberOfBits) {
    // Determine index of word contains the most significant bit,
    // then increase by 1 to change index to size.
    int sizeOfWordArray = wordIndex(numberOfBits - 1) + 1;
    this->words = Array<long>(sizeOfWordArray);
}

BitSet::BitSet() {
    this->initializeWords(bitsPerWord);
    this->sizeIsSticky = false;
}

BitSet::BitSet(int numberOfBits) {
    if (numberOfBits < 0) {
        throw NegativeArraySizeException("numberOfBits < 0" + numberOfBits);
    }
    this->initializeWords(numberOfBits);
    this->sizeIsSticky = true;
}

BitSet::~BitSet() { }

int BitSet::length() const {
    if (this->wordsInUse == 0) {
        return 0;
    }
    int indexOfWordContainHighestBit = wordsInUse - 1;
    // Number of bits in use.
    int logicalSize = (bitsPerWord * (this->wordsInUse - 1)) +
            (bitsPerWord - Long::numberOfLeadingZeros(words[indexOfWordContainHighestBit]));
    return logicalSize;
}

int BitSet::size() const {
    return this->words.length * bitsPerWord;
}
