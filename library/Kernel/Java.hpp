/**
 * Copyright 2017 Tiny Express Project. All rights reserved.
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

#ifndef NATIVE_KERNEL_JAVA_HPP
#define NATIVE_KERNEL_JAVA_HPP

#include "Common.hpp"

namespace Java {
		namespace Lang {
				class String;
		}
}

template <typename E>
class Array;

template <typename E>
class ArrayIterator {
public:
		ArrayIterator(const Array<E> *p_vec, int pos) : _pos(pos), _p_vec(p_vec) {
		}
		
		boolean operator!=(const ArrayIterator<E> &other) const {
			return _pos != other._pos;
		}
		
		E operator*() const {
			return _p_vec->get(_pos);
		}
		
		const ArrayIterator<E> &operator++() {
			++_pos;
			return *this;
		}

private:
		int _pos;
		const Array<E> *_p_vec;
};

template <typename E>
class Array {
private:
		std::vector<E> original;
public:
		
		/**
		 * Array default constructor
		 */
		Array() {
			this->length = 0;
		}
		
		/**
		 * Array constructor with std::initializer_list
		 *
		 * @param list
		 */
		Array(const std::initializer_list<E> &list) {
			typename std::initializer_list<E>::iterator it;
			for (it = list.begin(); it != list.end(); ++it) {
				original.push_back(*it);
			}
			this->length = original.size();
		}
		
		Array(char **charPointerArray) {
			int index = 0;
			while (charPointerArray[index] != nullptr) {
				original.push_back(charPointerArray[ index ]);
				index += 1;
			}
			this->length = original.size();
		}
		
		/**
		 *  Array constructor with contain size
		 *
		 * @param containerSize
		 */
		Array(long containerSize) {
			this->original.resize(containerSize);
			this->length = containerSize;
		}
		
		/**
		 * Array destructor
		 */
		~Array() = default;
		
		/**
		 * Property length of Array
		 *
		 * Don't set this property when you coding
		 */
		int length;
		
		/**
		 * Get the first element in Array
		 *
		 * @return ArrayIterator<E>
		 */
		ArrayIterator<E> begin() const {
			return ArrayIterator<E>(this, 0);
		}
		
		/**
		 * Get the final element in Array
		 *
		 * @return ArrayIterator<E>
		 */
		ArrayIterator<E> end() const {
			return ArrayIterator<E>(this, this->length);
		}

public:
		
		/**
		 * Push new element to end of Array
		 *
		 * @param e
		 */
		void push(E e) {
			original.push_back(e);
			this->length = original.size();
		}
		
		/**
		 * Returns the element at the specified position in this Array
		 *
		 * @param index
		 * @return E
		 */
		E get(const int index) const {
			return (E) original.at(index);
		}

public:
		
		/**
		* Set and get value of element at the specified position in this Array
		*
		* @param index
		* @return E
		*/
		E &operator[](const int index) {
			return this->original.at(index);
		}
		
		/**
		 * Get value of element at the specified position in this Array
		 *
		 * @param index
		 * @return E
		 */
		const E &operator[](const int index) const {
			return this->original.at(index);
		}

		/**
		 * Append a std::initializer_list<E> to this array
		 *
		 * @param list
		 * @return Array<E>
		 */
		Array<E> operator+=(const std::initializer_list<E> &list) {
			typename std::initializer_list<E>::iterator it;
			for (it = list.begin(); it != list.end(); ++it) {
				original.push_back(*it);
			}
			this->length = original.size();
			return *this;
		}
};

/**
 * Convert integer to hex string
 *
 * @param inputInt
 * @return String
 */
Java::Lang::String IntegerToHexString(int inputInt);

/**
 * Application testing
 * This function handle any application exception to keep program safety
 *
 * @param program
 * @param argument
 * @return int
 */
int ApplicationTest(int argc, const char **argv);

/**
 * Application starting point
 * This function handle any application exception to keep program safety
 *
 * @param program
 * @param argument
 * @return int
 */
int Application(void (*program)(Array <Java::Lang::String>), int argc, char **argv);

#endif// NATIVE_KERNEL_JAVA_HPP