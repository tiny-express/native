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

#ifndef NATIVE_JAVA_UTIL_ARRAY_LIST_HPP
#define NATIVE_JAVA_UTIL_ARRAY_LIST_HPP

#include "../AbstractList/AbstractList.hpp"
#include "../Collection/Collection.hpp"
#include <initializer_list>

using namespace Java::Lang;

namespace Java {
	namespace Util {
		template <typename E>
		class ArrayList;
		
		template <typename E>
		class ArrayIterator {
		public:
			ArrayIterator(const ArrayList<E> *p_vec, int pos) : _pos(pos), _p_vec(p_vec) {
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
			const ArrayList<E> *_p_vec;
		};
		
		template <typename E>
		class ArrayList : public virtual AbstractList<E> {
		private:
			E *array;
			int virtualSize = 4;
			int realSize;
			inline void reallocate();
		
		public:
			ArrayList();
			ArrayList(std::initializer_list<E> list);
			ArrayList(int length);
			ArrayList(ArrayList<E> &target);
			ArrayList(int length, E defaultValue);
			~ArrayList();
		
		public:
			ArrayIterator<E> begin() const;
			ArrayIterator<E> end() const;
			string toString() const;
		
		public:
			void add(E &e);
			void add(int index, E &element);
			bool addAll(Collection<E> &c);
			void addAll(std::initializer_list<E> list);
			void clear();
			bool contains(E &element) const;
			bool containsAll(Collection<E> &c) const;
			bool equals(E &e) const;
			E get(const int index) const;
			int hashCode() const;
			bool isEmpty() const;
			bool remove(E &e);
			bool removeAll(Collection<E> &c);
			bool set(int index, E &value);
			int size() const;
		};
		
		/*
		 * CONSTRUCTOR
		 */
		/**
		 * Array initialization
		 *
		 * @param E
		 */
		template <typename E>
		ArrayList<E>::ArrayList() {
			this->array = new E[this->virtualSize];
		}
		
		/**
		 * Array initialization with pointer
		 *
		 * @param E
		 * @param byte*
		 */
		template <typename E>
		ArrayList<E>::ArrayList(std::initializer_list<E> list) {
			this->virtualSize = (int) list.size() << 2;
			this->array = new E[this->virtualSize];
			this->realSize = (int) list.size();
			typename std::initializer_list<E>::iterator it;

			#ifdef __APPLE__
						int index = 0;
			#elif __linux_
						register int index = 0;
			#endif
			for (it = list.begin(); it != list.end(); ++it, ++index) {
				this->array[ index ] = *it;
				this->reallocate();
			}
		}
		
		/**
		 * Array initialization with length
		 *
		 * @param E
		 * @param length
		 */
		template <typename E>
		ArrayList<E>::ArrayList(int length) {
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
		ArrayList<E>::ArrayList(ArrayList<E> &target) {
			this->virtualSize = target.realSize << 2;
			this->realSize = target.realSize;
			this->array = new E[this->virtualSize];
			
			register int index;
			for (index = 0; index < this->realSize; index++) {
				this->array[ index ] = target.get(index);
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
		ArrayList<E>::ArrayList(int length, E defaultValue) {
			this->virtualSize = length << 2;
			this->realSize = length;
			this->array = new E[this->virtualSize];
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
		ArrayList<E>::~ArrayList() {
			delete[]this->array;
			this->realSize = this->virtualSize;
		}
		
		/**
		 * Begin array
		 *
		 * @return Iterator<E>
		 */
		template <typename E>
		ArrayIterator<E> ArrayList<E>::begin() const {
			return ArrayIterator<E>(this, 0);
		}
		
		/**
		 * End of array
		 *
		 * @param E
		 * @return Iterator
		 */
		template <typename E>
		ArrayIterator<E> ArrayList<E>::end() const {
			return ArrayIterator<E>(this, this->realSize);
		}
		
		/**
		 * Realloc array with new size
		 *
		 * @param E
		 */
		template <typename E>
		void ArrayList<E>::reallocate() {
			if (this->realSize >= this->virtualSize - 4) {
				this->virtualSize = this->virtualSize < 2;
				E *newArray = new E[this->virtualSize];
				memcpy(newArray, this->array, ( this->realSize * sizeof(E)));
				delete[]this->array;
				this->array = newArray;
			}
		}
		
		/**
		 * Serialize array to string
		 *
		 * @return string
		 */
		template <typename E>
		string ArrayList<E>::toString() const {
			return (string) "";
		}
		
		/*
		 * Java standard method for ArrayList
		 */
		
		/**
		 * Appends the specified element to the end of this list.
		 *
		 * @tparam E
		 * @param target
		 */
		/**
		 * Push new element to array
		 *
		 * @param E
		 * @param element
		 */
		template <typename E>
		void ArrayList<E>::add(E &element) {
			this->array[ this->realSize ] = element;
			this->realSize++;
			this->reallocate();
		}
		
		/**
		 * Inserts the specified element at the specified position in this list.
		 *
		 * @tparam E
		 * @param index
		 * @param element
		 */
		template <typename E>
		void ArrayList<E>::add(int position, E &element) {
			register int index;
			for (index = this->realSize - 1; index >= position; --index) {
				this->array[ index + 1 ] = this->array[ index ];
			}
			
			this->realSize++;
			this->reallocate();
		}
		
		/**
		 * Append list initialization to Array
		 *
		 * @param E
		 * @param Array<E>
		 */
		template <typename E>
		void ArrayList<E>::addAll(std::initializer_list<E> list) {
			typename std::initializer_list<E>::iterator it;
			register int index = this->size();
			for (it = list.begin(); it != list.end(); ++it, ++index) {
				this->array[ index ] = *it;
				this->realSize++;
				this->reallocate();
			}
		}
		
		/**
		 * Appends all of the elements in the specified collection to the end of this array
		 *
		 * @tparam E
		 * @param target
		 * @return
		 */
		template <typename E>
		bool ArrayList<E>::addAll(Collection<E> &target) {
			register int index;
			int length = target.size();
			this->virtualSize = length << 2;
			this->array = new E[this->virtualSize];
			this->realSize = length;
			for (index = 0; index < length; ++index) {
				this->array[ index ] = target.get(index);
			}
		}
		
		/**
		 * Delete all elements of Array
		 *
		 * @tparam E
		 */
		template <typename E>
		void ArrayList<E>::clear() {
			delete[]this->array;
			this->realSize = 0;
			this->virtualSize = 4;
			this->array = new E[this->virtualSize];
		}
		
		/**
		 * Returns true if this list contains the specified element
		 *
		 * @tparam E
		 * @param element
		 * @return true or false
		 */
		template <typename E>
		bool ArrayList<E>::contains(E &element) const {
			register int index;
			int size = this->size();
			for (index = 0; index < size; ++index) {
				if (this->get(index) == element) {
					return true;
				}
			}
			
			return false;
		}
		
		/**
		 * Returns true if this collection contains all of the elements in the specified collection.
		 *
		 * @tparam E
		 * @param target
		 * @return
		 */
		template <typename E>
		bool ArrayList<E>::containsAll(Collection<E> &target) const {
			int thisSize = this->size();
			int targetSize = target.size();
			
			register int indexTarget;
			register int indexThis;
			for (indexTarget = 0; indexTarget < targetSize; ++indexTarget) {
				bool isExist = false;
				for (indexThis = 0; indexThis < thisSize; ++indexThis) {
					if (this->get(indexThis) == target.get(indexTarget)) {
						isExist = true;
						break;
					}
				}
				
				if (!isExist) {
					return false;
				}
			}
			
			return true;
		}
		
		/**
		 * Get value from index
		 *
		 * @param index
		 * @return
		 */
		template <typename E>
		E ArrayList<E>::get(const int index) const {
			return this->array[ index ];
		}
		
		/**
		 * Return true if Array is empty, return false if Array not empty
		 *
		 * @tparam E
		 * @return
		 */
		template <typename E>
		bool ArrayList<E>::isEmpty() const {
			return ( this->realSize == 0 );
		}
		
		/**
		 * Return real size of array
		 *
		 * @param E
		 * @return int
		 */
		template <typename E>
		int ArrayList<E>::size() const {
			return this->realSize;
		}
		
		/**
		 * Replaces the element at the specified position in this list with the specified element.
		 *
		 * @tparam E
		 * @param index
		 * @param element
		 * @return true or false
		 */
		template <typename E>
		bool ArrayList<E>::set(int index, E &element) {
			if (index < 0 || index > this->size() - 1) {
				return false;
			}
			
			this->array[ index ] = element;
			return true;
		}
	}
}

#endif//NATIVE_JAVA_UTIL_ARRAY_LIST_HPP
