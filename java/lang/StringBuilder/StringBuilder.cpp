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

#include "../StringBuilder/StringBuilder.hpp"
#include "../NegativeArraySizeException/NegativeArraySizeException.hpp"
#include "../IndexOutOfBoundsException/IndexOutOfBoundsException.hpp"
#include "../StringIndexOutOfBoundsException/StringIndexOutOfBoundsException.hpp"
#include "../UnsupportedOperationException/UnsupportedOperationException.hpp"

using namespace Java::Lang;

StringBuilder::StringBuilder() : StringBuilder(defaultCapacity) {
}

StringBuilder::StringBuilder(int capacity) {
	if (capacity < 0) {
		throw NegativeArraySizeException("Capacity is negative");
	}
	
	this->original = (string)calloc((size_t)capacity, sizeof(char));
	this->currentLength = 0;
	this->currentCapacity = capacity;
}

StringBuilder::StringBuilder(String target) {
	long int newCapacity = defaultCapacity + target.length();
	this->ensureCapacity(newCapacity);
	this->append(target);
}

StringBuilder::StringBuilder(const std::initializer_list<char> target) {
	long int newCapacity = defaultCapacity + (long int) target.size();
	this->ensureCapacity(newCapacity);
	this->append(target);
}

StringBuilder::StringBuilder(const CharSequence &charSequence) {
	long int newCapacity = defaultCapacity + charSequence.length();
	this->ensureCapacity(newCapacity);
	this->append(charSequence);
}

StringBuilder::StringBuilder(const StringBuilder &target) {
	this->original = (string) calloc((size_t) target.currentCapacity, sizeof(char));
	long int index;
	for (index = 0; index < target.currentLength; index++) {
		this->original[ index ] = target.original[ index ];
	}
	this->currentLength = target.currentLength;
	this->currentCapacity = target.currentCapacity;
}

StringBuilder::~StringBuilder() {
	free(original);
}

StringBuilder &StringBuilder::append(Boolean target) {
	return this->append(target.toString());
}

StringBuilder &StringBuilder::append(boolean target) {
	return this->append(Boolean(target));
}

StringBuilder &StringBuilder::append(const Character &target) {
	Character *pointerToTarget = const_cast<Character *>(&target);
	return this->append(pointerToTarget->charValue());
}

StringBuilder &StringBuilder::append(char target) {
	long int newLength = this->currentLength + 1;
	this->ensureCapacity(newLength);
	this->original[this->currentLength] = target;
	this->currentLength = newLength;
	return *this;
}

StringBuilder &StringBuilder::append(const Array<Character> target) {
	long int newLength = this->currentLength + target.length;
	this->ensureCapacity(newLength);
	long int indexOfOriginal = this->currentLength;
	for (Character character : target) {
		this->original[indexOfOriginal] = character.charValue();
		indexOfOriginal = indexOfOriginal + 1;
	}
	this->currentLength = newLength;
	return *this;
}

StringBuilder &StringBuilder::append(const Array<char> target) {
	long int newLength = this->currentLength + target.length;
	this->ensureCapacity(newLength);
	long int indexOfOriginal = this->currentLength;
	for (char character: target) {
		this->original[indexOfOriginal] = character;
		indexOfOriginal = indexOfOriginal + 1;
	}
	this->currentLength = newLength;
	return *this;
}

StringBuilder &StringBuilder::append(const Array<Character> &target, int offset, long int length) {
	return this->insert(this->currentLength, target, offset, length);
}

StringBuilder &StringBuilder::append(const Array<char> &target, int offset, long int length) {
	return this->insert(this->currentLength, target, offset, length);
}

StringBuilder &StringBuilder::append(const CharSequence &target) {
	String targetString = target.toString();
	return this->append(targetString);
}

StringBuilder &StringBuilder::append(const CharSequence &target, int start, int end) {
	String targetString = target.toString();
	long int lengthOfTarget = targetString.length();
	if (start < 0 || start > end || end > lengthOfTarget) {
		throw IndexOutOfBoundsException();
	}
	
	long int numberOfCharacter = end - start;
	long int newLength = currentLength + numberOfCharacter;
	this->ensureCapacity(newLength);
	long int indexOfTarget;
	long int indexOfOriginal;
	for (indexOfTarget = start, indexOfOriginal = this->currentLength; indexOfTarget < end; indexOfTarget++, indexOfOriginal++) {
		this->original[indexOfOriginal] = targetString[indexOfTarget];
	}
	this->currentLength = newLength;
	return *this;
}

StringBuilder &StringBuilder::append(const std::initializer_list<char> target) {
	long int newLength = this->currentLength + (long int)target.size();
	this->ensureCapacity(newLength);
	long int index = this->currentLength;
	std::initializer_list<char>::const_iterator listIterator;
	for (listIterator = target.begin(); listIterator != target.end(); listIterator++) {
		this->original[index] = *listIterator;
		index = index + 1;
	}
	this->currentLength = newLength;
	return *this;
}

StringBuilder &StringBuilder::append(String target) {
	long int stringLength = target.length();
	long int newLength = this->currentLength + stringLength;
	this->ensureCapacity(newLength);
	long int indexOfOriginal;
	long int indexOfString = 0;
	for (indexOfOriginal = this->currentLength; indexOfOriginal < newLength; indexOfOriginal++) {
		this->original[indexOfOriginal] = target[indexOfString];
		indexOfString = indexOfString + 1;
	}
	this->currentLength = newLength;
	return *this;
}

StringBuilder &StringBuilder::append(const Double target) {
	return this->append(target.toString());
}

StringBuilder &StringBuilder::append(double target) {
	return this->append(Double(target));
}

StringBuilder &StringBuilder::append(const Float target) {
	return this->append(target.toString());
}

StringBuilder &StringBuilder::append(float target) {
	return this->append(Float(target));
}

StringBuilder &StringBuilder::append(const Integer target) {
	return this->append(target.toString());
}

StringBuilder &StringBuilder::append(int target) {
	return this->append(Integer(target));
}

StringBuilder &StringBuilder::append(const Long target) {
	return this->append(target.toString());
}

StringBuilder &StringBuilder::append(long target) {
	return this->append(Long(target));
}

//StringBuilder &StringBuilder::appendCodePoint(int codePoint) {
	// TODO
//}

long int StringBuilder::capacity() const {
	return this->currentCapacity;
}

char StringBuilder::charAt(int index) const {
	if (index < 0 || index >= this->currentLength) {
		throw IndexOutOfBoundsException(String::valueOf(index));
	}
	
	return this->original[index];
}

long int StringBuilder::codePointAt(int index) const {
	if (index < 0 || index >= this->currentLength) {
		throw IndexOutOfBoundsException(String::valueOf(index));
	}
	
	Array<char> originalArray;
	long int indexOfOriginal;
	for (indexOfOriginal = 0; indexOfOriginal < this->currentLength; indexOfOriginal++) {
		originalArray.push(this->original[indexOfOriginal]);
	}
	long int result = Character::codePointAt(originalArray, index);
	return result;
}

long int StringBuilder::codePointBefore(int index) const {
	long int beforeOfIndex = index - 1;
	return this->codePointAt(beforeOfIndex);
}

long int StringBuilder::codePointCount(int beginIndex, int endIndex) {
	if (beginIndex < 0 || endIndex > this->currentLength || beginIndex > endIndex) {
		throw IndexOutOfBoundsException();
	}
	
	Array<char> originalArray;
	long int numberOfCharacters = endIndex - beginIndex;
	long int index;
	long int stopIndex = beginIndex + numberOfCharacters;
	for (index = 0; index < stopIndex; index++) {
		originalArray.push(this->original[ index ]);
	}
	long int result = Character::codePointCount(originalArray, 0, numberOfCharacters);
	return result;
}

StringBuilder StringBuilder::deleteRange(int start, int end) {
	if (start < 0) {
		throw StringIndexOutOfBoundsException(start);
	}
	if (end > this->currentLength) {
		end = this->currentLength;
	}
	if (start > end) {
		throw StringIndexOutOfBoundsException("start > end");
	}
	
	long int lengthOfSubStringWillBeRemoved = end - start;
	string newPositionOfTail = this->original + start;
	string oldPositionOfTail = this->original + end;
	long int memorySizeOfTailPart = this->currentLength - end;
	memmove(newPositionOfTail, oldPositionOfTail, (size_t) memorySizeOfTailPart);
	
	this->currentLength = this->currentLength - lengthOfSubStringWillBeRemoved;
	return *this;
}

StringBuilder StringBuilder::deleteCharAt(int index) {
	if (index < 0 || index >= this->currentLength) {
		throw StringIndexOutOfBoundsException(index);
	}
	
	string newPositionOfTail = this->original + index;
	string oldPositionOfTail = this->original + index + 1;
	long int memorySizeOfTailPart = this->currentLength - ( index + 1 );
	memmove(newPositionOfTail, oldPositionOfTail, (size_t) memorySizeOfTailPart);
	
	this->currentLength = this->currentLength - 1;
	return *this;
}

void StringBuilder::ensureCapacity(int minimumCapacity) {
	if (minimumCapacity <= 0 || minimumCapacity <= this->currentCapacity) {
		return;
	}
	
	long int newCapacity = this->currentCapacity * 2 + 2;
	if (newCapacity < minimumCapacity) {
		newCapacity = minimumCapacity;
	}
	long int numberOfBytes = newCapacity * sizeof(char);
	this->original = (string) allocateMemory(this->original, (size_t) numberOfBytes);
	this->currentCapacity = newCapacity;
}

//void StringBuilder::getChars(int sourceBegin, int sourceEnd, Array<Character> &target, int targetBegin) const {
//	if (sourceBegin < 0) {
//		throw StringIndexOutOfBoundsException(sourceBegin);
//	}
//	if (sourceEnd < 0 || sourceEnd > this->currentLength) {
//		throw StringIndexOutOfBoundsException(sourceEnd);
//	}
//	if (sourceBegin > sourceEnd) {
//		throw StringIndexOutOfBoundsException("sourceBegin > sourceEnd");
//	}
//
//	// TODO: copyOfRange method for Array is not implemented.
//	throw UnsupportedOperationException();
//}

long int StringBuilder::indexOf(const String target) const {
	return this->stringMatches(this->toString(), target, 0);
}

long int StringBuilder::indexOf(const String target, int fromIndex) const {
	return this->stringMatches(this->toString(), target, fromIndex);
}

StringBuilder &StringBuilder::insert(int offset, boolean target) {
	return this->insert(offset, Boolean(target));
}

StringBuilder &StringBuilder::insert(int offset, const Boolean target) {
	return this->insert(offset, target.toString());
}

StringBuilder &StringBuilder::insert(int offset, char target) {
	if (offset < 0 || offset > this->currentLength) {
		throw IndexOutOfBoundsException(String::valueOf(offset));
	}
	
	long int newLength = this->currentLength + 1;
	this->ensureCapacity(newLength);
	
	string newShiftPosition = this->original + offset + 1;
	string oldShiftPosition = this->original + offset;
	long int sizeOfShiftMemory = sizeof(char) * (this->currentLength - offset);
	memmove(newShiftPosition, oldShiftPosition, (size_t)sizeOfShiftMemory);
	this->original[offset] = target;
	this->currentLength = newLength;
	
	return *this;
}

StringBuilder &StringBuilder::insert(int offset, const Character &target) {
	Character *pointerToTarget = const_cast<Character *>(&target);
	return this->insert(offset, pointerToTarget->charValue());
}

StringBuilder &StringBuilder::insert(int offset, const Array<char> target) {
	return this->insert(offset, target, 0, target.length);
}

StringBuilder &StringBuilder::insert(int offset, const Array<Character> target) {
	return this->insert(offset, target, 0, target.length);
}

StringBuilder &StringBuilder::insert(int index, const Array<char> &target, int offset, long int length) {
	if (index < 0 || index > this->currentLength) {
		throw StringIndexOutOfBoundsException(offset);
	}
	
	long int stopIndexOfTarget = offset + length;
	if (offset < 0 || length < 0 || stopIndexOfTarget > target.length) {
		throw StringIndexOutOfBoundsException(offset);
	}
	
	long int newLength = this->currentLength + length;
	this->ensureCapacity(newLength);
	
	string newShiftPosition = this->original + index + length;
	string oldShiftPosition = this->original + index;
	long int sizeOfShiftMemory = sizeof(char) * (this->currentLength - index);
	memmove(newShiftPosition, oldShiftPosition, (size_t)sizeOfShiftMemory);
	long int indexOfTarget;
	long int indexOfOriginal = index;
	for (indexOfTarget = offset; indexOfTarget < stopIndexOfTarget; indexOfTarget++) {
		this->original[indexOfOriginal] = target.get(indexOfTarget);
		indexOfOriginal = indexOfOriginal + 1;
	}
	this->currentLength = newLength;
	
	return *this;
}

StringBuilder &StringBuilder::insert(int index, const Array<Character> &target, int offset, long int length) {
	if (index < 0 || index > this->currentLength) {
		throw StringIndexOutOfBoundsException(offset);
	}
	
	long int stopIndexOfTarget = offset + length;
	if (offset < 0 || length < 0 || stopIndexOfTarget > target.length) {
		throw StringIndexOutOfBoundsException(offset);
	}
	
	long int newLength = this->currentLength + length;
	this->ensureCapacity(newLength);
	
	string newShiftPosition = this->original + index + length;
	string oldShiftPosition = this->original + index;
	long int sizeOfShiftMemory = sizeof(char) * (this->currentLength - index);
	memmove(newShiftPosition, oldShiftPosition, (size_t)sizeOfShiftMemory);
	long int indexOfTarget;
	long int indexOfOriginal = index;
	for (indexOfTarget = offset; indexOfTarget < stopIndexOfTarget; indexOfTarget++) {
		this->original[indexOfOriginal] = target.get(indexOfTarget).charValue();
		indexOfOriginal = indexOfOriginal + 1;
	}
	this->currentLength = newLength;
	
	return *this;
}

StringBuilder &StringBuilder::insert(int destinationOffset, const CharSequence &target) {
	return this->insert(destinationOffset, target.toString());
}

StringBuilder &StringBuilder::insert(int destinationOffset, const CharSequence &target, int start, int end) {
	if (destinationOffset < 0 || destinationOffset > this->currentLength) {
		throw IndexOutOfBoundsException();
	}
	String targetString = target.toString();
	long int lengthOfTarget = targetString.length();
	if (start < 0 || end < 0 || start > end || end > lengthOfTarget){
		throw IndexOutOfBoundsException();
	}
	
	long int lengthOfSubStringOfTarget = end - start;
	long int newLength = this->currentLength + lengthOfSubStringOfTarget;
	this->ensureCapacity(newLength);
	
	string newShiftPosition = this->original + destinationOffset + lengthOfSubStringOfTarget;
	string oldShiftPosition = this->original + destinationOffset;
	long int sizeOfShiftMemory = sizeof(char) * (this->currentLength - destinationOffset);
	memmove(newShiftPosition, oldShiftPosition, (size_t)sizeOfShiftMemory);
	
	long int indexOfOriginal = destinationOffset;
	long int indexOfTarget;
	for (indexOfTarget = start; indexOfTarget < end; indexOfTarget++) {
		this->original[indexOfOriginal] = targetString[indexOfTarget];
		indexOfOriginal = indexOfOriginal + 1;
	}
	
	this->currentLength = newLength;
	return *this;
}

StringBuilder &StringBuilder::insert(int offset, const Double target) {
	return this->insert(offset, target.toString());
}

StringBuilder &StringBuilder::insert(int offset, double target) {
	return this->insert(offset, Double(target));
}

StringBuilder &StringBuilder::insert(int offset, const Float target) {
	return this->insert(offset, target.toString());
}

StringBuilder &StringBuilder::insert(int offset, float target) {
	return this->insert(offset, Float(target));
}

StringBuilder &StringBuilder::insert(int offset, const Integer target) {
	return this->insert(offset, target.toString());
}

StringBuilder &StringBuilder::insert(int offset, int target) {
	return this->insert(offset, Integer(target));
}

StringBuilder &StringBuilder::insert(int offset, const Long target) {
	return this->insert(offset, target.toString());
}

StringBuilder &StringBuilder::insert(int offset, long target) {
	return this->insert(offset, Long(target));
};

StringBuilder &StringBuilder::insert(int offset, const String target) {
	if (offset < 0 || offset > this->currentLength) {
		throw StringIndexOutOfBoundsException(offset);
	}
	
	long int targetLength = target.length();
	long int newLength = this->currentLength + targetLength;
	this->ensureCapacity(newLength);
	
	string newShiftPosition = this->original + offset + targetLength;
	string oldShiftPosition = this->original + offset;
	// Number of bytes of memory will be to shift = size of char type multiple with number of character begin from the offset to the end.
	long int sizeOfShiftMemory = sizeof(char) * (this->currentLength - offset);
	memmove(newShiftPosition, oldShiftPosition, (size_t) sizeOfShiftMemory);
	
	long int indexOfOriginal = offset;
	long int indexOfTarget;
	for (indexOfTarget = 0; indexOfTarget < targetLength; indexOfTarget++) {
		this->original[indexOfOriginal] = target[indexOfTarget];
		indexOfOriginal = indexOfOriginal + 1;
	}
	
	this->currentLength = newLength;
	return *this;
}

long int StringBuilder::lastIndexOf(String target) const {
	return this->stringMatchesReverse(this->toString(), target, this->currentLength);
}

long int StringBuilder::lastIndexOf(String target, int fromIndex) const {
	return this->stringMatchesReverse(this->toString(), target, fromIndex);
}

long int StringBuilder::length() const {
	return this->currentLength;
}

//int StringBuilder::offsetByCodePoints(int index, int codePointOffset) const {
//	if (index < 0 || index > this->currentLength) {
//		throw IndexOutOfBoundsException();
//	}
//	// TODO: Waiting for Character::offsetByCodePoints
//	throw UnsupportedOperationException();
//}

StringBuilder StringBuilder::replace(int start, int end, const String target) {
	if (start < 0) {
		throw StringIndexOutOfBoundsException(start);
	}
	if (start > this->currentLength) {
		throw StringIndexOutOfBoundsException("start > length()");
	}
	if (start > end) {
		throw StringIndexOutOfBoundsException("start > end");
	}
	if (end > this->currentLength) {
		end = this->currentLength;
	}
	
	long int lengthOfTarget = target.length();
	long int lengthOfSubStringWillBeOverwrite = end - start; // tail part of this sequence.
	long int newLength = this->currentLength + lengthOfTarget - lengthOfSubStringWillBeOverwrite;
	this->ensureCapacity(newLength);
	
	string newPositionOfTailPart = this->original + end + lengthOfTarget - lengthOfSubStringWillBeOverwrite;
	string oldPositionOfTailPart = this->original + end;
	long int memorySizeOfTailPart = ( this->currentLength - end ) * sizeof(char);
	memmove(newPositionOfTailPart, oldPositionOfTailPart, (size_t) memorySizeOfTailPart);
	
	string insertPosition = this->original + start;
	long int memorySizeForTarget = lengthOfTarget * sizeof(char);
	memcpy(insertPosition, target.toCharPointer(), (size_t) memorySizeForTarget);
	
	this->currentLength = newLength;
	return *this;
}

StringBuilder StringBuilder::reverse() {
	boolean hasSurrogates = false;
	long int index;
	long int oppositeIndex;
	long int stopIndex = this->currentLength / 2;
	char temp;
	for (index = 0; index < stopIndex; index++) {
		oppositeIndex = ( this->currentLength - 1 ) - index;
		temp = this->original[ index ];
		this->original[ index ] = this->original[ oppositeIndex ];
		this->original[ oppositeIndex ] = temp;
		if (Character::isSurrogate(( this->original[ index ] )) || Character::isSurrogate(this->original[ oppositeIndex ])) {
			hasSurrogates = true;
		}
	}
	if (hasSurrogates) {
		this->reverseAllValidSurrogatePairs();
	}
	return *this;
}

void StringBuilder::setCharAt(int index, char target) {
	if (index < 0 || index >= this->currentLength) {
		throw StringIndexOutOfBoundsException(index);
	}
	
	this->original[ index ] = target;
}

void StringBuilder::setCharAt(int index, const Character &target) {
	Character *pointerToTarget = const_cast<Character *>(&target);
	this->setCharAt(index, pointerToTarget->charValue());
}

void StringBuilder::setLength(int newLength) {
	if (newLength < 0) {
		throw IndexOutOfBoundsException(String::valueOf(newLength));
	}
	
	this->ensureCapacity(newLength);
	if (this->currentLength < newLength) {
	long int index;
		for (index = this->currentLength; index < newLength; index++) {
			this->original[index] = '\0';
		}
	}
	this->currentLength = newLength;
}

String StringBuilder::substring(int start) const {
	return this->substring(start, this->currentLength);
}

String StringBuilder::substring(int start, int end) const {
	if (start < 0 || start > this->currentLength) {
		throw StringIndexOutOfBoundsException(start);
	}
	if (end < 0 || end > this->currentLength) {
		throw StringIndexOutOfBoundsException(end);
	}
	if (start > end) {
		throw StringIndexOutOfBoundsException(end - start);
	}
	
	long int lengthOfSubString = end - start + 1;
	auto copyOfSubString = (string) calloc((size_t) lengthOfSubString, sizeof(char));
	long int indexOfOriginal;
	long int indexOfSubString = 0;
	for (indexOfOriginal = start; indexOfOriginal < end; indexOfOriginal++) {
		copyOfSubString[ indexOfSubString ] = this->original[ indexOfOriginal ];
		indexOfSubString = indexOfSubString + 1;
	}
	copyOfSubString[ indexOfSubString ] = '\0';
	String result(copyOfSubString);
	free(copyOfSubString);
	return result;
}

String StringBuilder::toString() const {
	long int numberOfElementIncludeNullTerminator = this->currentLength + 1;
	string content = (string)calloc((size_t)numberOfElementIncludeNullTerminator, sizeof(char));
	long int index;
	for (index = 0; index < this->currentLength; index++) {
		content[index] = this->original[index];
	}
	content[this->currentLength] = '\0';
	this->backupOriginalForToString = content;
	free(content);
	return this->backupOriginalForToString;
}

void StringBuilder::trimToSize() {
	if (this->currentCapacity > this->currentLength) {
	long int numberOfBytesForCapacity = this->currentLength * sizeof(char);
		this->original = (string) allocateMemory(this->original, (size_t) numberOfBytesForCapacity);
		this->currentCapacity = this->currentLength;
	}
}

long int *StringBuilder::initializeNextTable(const String pattern) const {
	long int lengthOfPattern = pattern.length();
	if (lengthOfPattern == 0) {
		return nullptr;
	}
	
	long int *nextTable = (int *) calloc((size_t) lengthOfPattern, sizeof(long int));
	
	if (nextTable == nullptr) {
		return nullptr;
	}
	
	nextTable[ 0 ] = -1;
	if (lengthOfPattern == 1) {
		return nextTable;
	}
	nextTable[ 1 ] = 0;
	if (lengthOfPattern == 2) {
		return nextTable;
	}
	
	long int position = 2;
	long int lengthOfTheLongestPrefixSuffix = 0;
	
	while (position < lengthOfPattern) {
		if (pattern[ position - 1 ] == pattern[ lengthOfTheLongestPrefixSuffix ]) {
			lengthOfTheLongestPrefixSuffix = lengthOfTheLongestPrefixSuffix + 1;
			nextTable[ position ] = lengthOfTheLongestPrefixSuffix;
			position = position + 1;
		} else if (lengthOfTheLongestPrefixSuffix > 0) {
			lengthOfTheLongestPrefixSuffix = nextTable[ lengthOfTheLongestPrefixSuffix ];
		} else {
			nextTable[ position ] = 0;
			position = position + 1;
		}
	}
	
	return nextTable;
}

long int StringBuilder::stringMatches(const String target, const String pattern, int startIndex) const {
	long int lengthOfPattern = pattern.length();
	long int lengthOfTarget = target.length();
	
	if (startIndex > lengthOfTarget) {
		if (lengthOfPattern == 0) {
			return lengthOfTarget;
		}
		return -1;
	}
	
	if (startIndex < 0) {
		startIndex = 0;
	}
	
	// Empty string always matches.
	if (lengthOfPattern == 0) {
		return startIndex;
	}
	
	// KMP algorithm.
	long int *nextTable = this->initializeNextTable(target);
	if (nextTable == nullptr) {
		return -1;
	}
	
	long int position = 0;
	while (startIndex + position < lengthOfTarget) {
		if (pattern[ position ] == target[ startIndex + position ]) {
			if (position == lengthOfPattern - 1) {
				free(nextTable);
				return startIndex;
			}
			position = position + 1;
		} else {
			if (nextTable[ position ] > -1) {
				startIndex = startIndex + position;
				position = nextTable[ position ];
			} else {
				startIndex = startIndex + 1;
				position = 0;
			}
		}
	}
	
	free(nextTable);
	return -1;
}

long int StringBuilder::stringMatchesReverse(const String target, const String pattern, int startIndex) const {
	long int lengthOfPattern = pattern.length();
	long int lengthOfTarget = target.length();
	
	if (startIndex < 0) {
		return -1;
	}
	
	long int rightIndex = lengthOfTarget - lengthOfPattern;
	if (startIndex < rightIndex) {
		startIndex = rightIndex;
	}
	
	// Empty string always matches.
	if (lengthOfPattern == 0) {
		return startIndex;
	}
	
	// KMP algorithm.
	long int *nextTable = this->initializeNextTable(pattern);
	if (nextTable == nullptr) {
		return -1;
	}
	
	long int position = 0;
	while (startIndex - position >= 0) {
		if (pattern[ lengthOfPattern - position - 1 ] == target[ startIndex - position ]) {
			if (position == lengthOfPattern - 1) {
				free(nextTable);
				return startIndex - lengthOfPattern + 1;
			}
			position = position + 1;
		} else {
			if (nextTable[ position ] > -1) {
				startIndex = startIndex - position;
				position = nextTable[ position ];
			} else {
				startIndex = startIndex - 1;
				position = 0;
			}
		}
	}
	
	free(nextTable);
	return -1;
}

void StringBuilder::reverseAllValidSurrogatePairs() {
	long int stopIndex = this->currentLength - 1;
	long int index;
	char ch1;
	char ch2;
	for (index = 0; index < stopIndex; index++) {
		ch2 = this->original[ index ];
		if (Character::isLowSurrogate(ch2)) {
			ch1 = this->original[ index + 1 ];
			if (Character::isHighSurrogate(ch1)) {
				this->original[ index ] = ch1;
				index = index + 1;
				this->original[ index ] = ch2;
			}
		}
	}
}