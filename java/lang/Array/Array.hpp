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

#ifndef NATIVE_JAVA_LANG_ARRAY_HPP
#define NATIVE_JAVA_LANG_ARRAY_HPP

#include "../Object/Object.hpp"
#include <initializer_list>

using namespace Java::Lang;

namespace Java {
	namespace Lang {
		template <typename E>
		class Array;
		
		template <typename E>
		class ArrayIterator {
		public:
			ArrayIterator(const Array<E> *p_vec, int pos) : _pos(pos), _p_vec(p_vec) {
			}
			bool operator!=(const ArrayIterator<E> &other) const {
				return _pos != other._pos;
			}
			
			int operator*() const {
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
		class Array : public Object {
		private:
			E *array;
			int virtualSize = 4;
			int realSize = 0;
			inline void reallocate();
		
		public:
			Array();
			Array(std::initializer_list<E> list);
			Array(int length);
			//Array(E target);
			Array(const Array<E> &target);
			Array(int length, E defaultValue);
			~Array();
		
		public:
			void append(std::initializer_list<E> list);
			void append(const Array<E> &target);
			void append(const E &target);
			E at(const int index) const;
			void push(E element);
			boolean isEmpty() const;
			int length() const;
			int get(int index) const;
			void set(int index, int value);
			ArrayIterator<E> begin() const;
			ArrayIterator<E> end() const;
			string toString() const;
		
		public:
			E &operator[](const int index);
			Array<E> operator+(const Array<E> &target);
			Array<E> operator+=(const Array<E> &target);
			Array<E> operator=(const Array<E> &target);
		};
		
		/**
		 * Array initialization
		 *
		 * @param E
		 */
		template <typename E>
		Array<E>::Array() {
			this->array = new E[this->virtualSize];
		}
		
		/**
		 * Array initialization with pointer
		 *
		 * @param E
		 * @param byte*
		 */
		template <typename E>
		Array<E>::Array(std::initializer_list<E> list) {
			this->array = new E[this->virtualSize];
			this->realSize = 0;
			typename std::initializer_list<E>::iterator it;
			for (it = list.begin(); it != list.end(); ++it) {
				this->push(*it);
			}
		}
		
		/**
		 * Array initialization with length
		 *
		 * @param E
		 * @param length
		 */
		template <typename E>
		Array<E>::Array(int length) {
			this->virtualSize = length << 2;
			this->realSize = length;
			this->array = new E[this->virtualSize];
		}
		
		/**
		 * Array initialization with Array
		 *
		 * @param E
		 * @param target
		 */
		template <typename E>
		Array<E>::Array(const Array<E> &target) {
			this->virtualSize = target.realSize << 2;
			this->realSize = target.realSize;
			this->array = new E[this->virtualSize];
			
			register int index;
			for (index = 0; index < this->realSize; index++) {
				this->array[ index ] = target.at(index);
			}
		}
		
		/**
		 * Array initialization with length and each element is equal to defaultValue
		 *
		 * @param E
		 * @param length
		 * @param defaultValue
		 */
		template <typename E>
		Array<E>::Array(int length, E defaultValue) {
			this->virtualSize = length << 2;
			this->realSize = length;
			
			int index;
			for (index = 0; index < this->realSize; ++index) {
				this->array[ index ] = defaultValue;
			}
		}
		
		/**
		 * Array destructor
		 *
		 * @param E
		 */
		template <typename E>
		Array<E>::~Array() {
			delete[]this->array;
		}
		
		/**
		 * Begin array
		 *
		 * @return Iterator<E>
		 */
		template <typename E>
		ArrayIterator<E> Array<E>::begin() const {
			return ArrayIterator<E>(this, 0);
		}
		
		/**
		 * End of array
		 *
		 * @param E
		 * @return Iterator
		 */
		template <typename E>
		ArrayIterator<E> Array<E>::end() const {
			return ArrayIterator<E>(this, this->realSize);
		}
		
		/**
		 * Realloc array with new size
		 *
		 * @param E
		 */
		template <typename E>
		void Array<E>::reallocate() {
			if (this->realSize >= this->virtualSize - 4) {
				this->virtualSize = this->virtualSize < 2;
				E *newArray = new E[this->virtualSize];
				memcpy(newArray, this->array, ( this->realSize * sizeof(E)));
				delete[]this->array;
				this->array = newArray;
			}
		}
		
		/**
		 * Check if array is empty or not
		 *
		 * @param E
		 * @return boolean
		 */
		template <typename E>
		boolean Array<E>::isEmpty() const {
			return ( this->realSize == 0 );
		}
		
		/**
		 * Get value from index
		 *
		 * @param index
		 * @return
		 */
		template <typename E>
		int Array<E>::get(int index) const {
			return this->at(index);
		}
		
		/**
		 * Set value for index
		 *
		 * @param index
		 * @param value
		 */
		template <typename E>
		void Array<E>::set(int index, int value) {
			this->array[ index ] = value;
		}
		
		/**
		 * Push new element to array
		 *
		 * @param E
		 * @param element
		 */
		template <typename E>
		void Array<E>::push(E element) {
			this->array[ this->realSize ] = element;
			this->realSize++;
			this->reallocate();
		}
		
		/**
		 * Array from list initialization
		 *
		 * @param E
		 * @param Array<E>
		 */
		template <typename E>
		void Array<E>::append(std::initializer_list<E> list) {
			typename std::initializer_list<E>::iterator it;
			for (it = list.begin(); it != list.end(); ++it) {
				this->push(*it);
			}
		}
		
		/**
		 * Returns the value of array at index
		 *
		 * @param E
		 * @param index
		 * @return E
		 */
		template <typename E>
		E Array<E>::at(const int index) const {
			return this->array[ index ];
		}
		
		/**
		 * Return real size of array
		 *
		 * @param E
		 * @return int
		 */
		template <typename E>
		int Array<E>::length() const {
			return this->realSize;
		}
		
		/**
		 * Serialize array to string
		 *
		 * @return string
		 */
		template <typename E>
		string Array<E>::toString() const {
			return (string) "";
		}
		
		/**
		 * Return value of array at index
		 *
		 * @param E
		 * @param index
		 * @return E
		 */
		template <typename E>
		E &Array<E>::operator[](const int index) {
			return this->array[ index ];
		}
		
		/**
		 * Make the current Array equal to target Array
		 *
		 * @tparam E
		 * @param target
		 * @return
		 */
		template <typename E>
		Array<E> Array<E>::operator=(const Array<E> &target) {
			if (!this->isEmpty()) {
				delete[]this->array;
			}
			this->realSize = target.realSize;
			this->virtualSize = target.virtualSize;
			this->array = new E[this->virtualSize];
			
			register int index = 0;
			for (index = 0; index < this->realSize; ++index) {
				this->push(target[ index ]);
			}
		}
		
		/**
		 * Add Array to Array and return new Object
		 *
		 * @tparam E
		 * @param target
		 * @return Array<E>
		 */
		template <typename E>
		Array<E> Array<E>::operator+(const Array<E> &target) {
			Array<E> result = *this;
			
			register int index;
			for (index = 0; index < target.length(); ++index) {
				result.push(target.at(index));
			}
			
			return result;
		}
		
		/**
		 * Add a new Array to current Array
		 *
		 * @tparam E
		 * @param target
		 * @return Array<E>
		 */
		template <typename E>
		Array<E> Array<E>::operator+=(const Array<E> &target) {
			register int index;
			for (index = 0; index < target.length(); ++index) {
				this->push(target.at(index));
			}
			return *this;
		}
		
		
	}
}

#endif//NATIVE_JAVA_LANG_ARRAY_HPP
