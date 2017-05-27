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

#include "../../lang/Cloneable/Cloneable.hpp"
#include "../../io/Serializable/Serializable.hpp"
#include "../AbstractList/AbstractList.hpp"
#include "../Collection/Collection.hpp"
#include "../RandomAccess/RandomAccess.hpp"
#include "../ListIterator/ListIterator.hpp"
#include "../List/List.hpp"
#include "../Comparator/Comparator.hpp"
#include "../Spliterator/Spliterator.hpp"
#include "../function/Consumer/Consumer.hpp"
#include "../function/Predicate/Predicate.hpp"
#include "../function/UnaryOperator/UnaryOperator.hpp"
#include <initializer_list>

using namespace Java::Lang;
using namespace Java::IO;
using namespace Java::Util::Function;

namespace Java {
	namespace Util {
		template <typename E>
		class ArrayList;
		
		template <typename E>
		class ArrayListIterator {
		public:
			ArrayListIterator(const ArrayList<E> *p_vec, int pos) : _pos(pos), _p_vec(p_vec) {
			}
			
			boolean operator!=(const ArrayListIterator<E> &other) const {
				return _pos != other._pos;
			}
			
			int operator*() const {
				return _p_vec->get(_pos);
			}
			
			const ArrayListIterator<E> &operator++() {
				++_pos;
				return *this;
			}
		
		private:
			int _pos;
			const ArrayList<E> *_p_vec;
		};
		
		template <typename E>
		class ArrayList :
			public virtual AbstractList<E>,
			public virtual Serializable,
			public virtual Cloneable,
			public virtual List<E>,
			public virtual RandomAccess {
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
			ArrayListIterator<E> begin() const;
			ArrayListIterator<E> end() const;
		public:
			boolean add(E &e);
			void add(int index, E &element);
			boolean addAll(Collection<E> &c);
			boolean addAll(int index, Collection<E> &c);
			void clear();
			Object &clone();
			boolean contains(Object &o) const;
			void ensureCapacity(int minCapacity) const;
			void forEach(Consumer<E> &action) const;
			E &get(int index) const;
			int indexOf(Object &o) const;
			boolean isEmpty() const;
			Iterator<E> iterator() const;
			int lastIndexOf(Object &o) const;
			ListIterator<E> listIterator() const;
			ListIterator<E> listIterator(int index) const;
			E remove(int index);
			boolean remove(Object &o);
			boolean removeAll(Collection<Object> &c);
			boolean removeIf(Predicate<E> &filter);
			void replaceAll(UnaryOperator<E> &unaryOperator);
			boolean retainAll(Collection<Object> &c);
			E &set(int index, E &element);
			int	size() const override;
			void sort(Comparator &c);
			Spliterator<E>	&spliterator() const;
			List<E>	subList(int fromIndex, int toIndex);
			Array<Object>	&toArray();
			template <typename T>
			Array<T> toArray(Array<T> &a);
			void trimToSize();
		protected:
			void removeRange(int fromIndex, int toIndex);
		};
		
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
			register int index = 0;
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
		ArrayListIterator<E> ArrayList<E>::begin() const {
			return ArrayListIterator<E>(this, 0);
		}
		
		/**
		 * End of array
		 *
		 * @param E
		 * @return Iterator
		 */
		template <typename E>
		ArrayListIterator<E> ArrayList<E>::end() const {
			return ArrayListIterator<E>(this, this->realSize);
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
		 * Appends the specified element to the end of this list.
		 *
		 * @param E
		 * @param target
		 */
		/**
		 * Push new element to array
		 *
		 * @param E
		 * @param element
		 */
		template <typename E>
		boolean ArrayList<E>::add(E &element) {
			this->array[ this->realSize ] = element;
			this->realSize++;
			this->reallocate();
		}
		
		/**
		 * Inserts the specified element at the specified position in this list.
		 *
		 * @param E
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
		 * Appends all of the elements in the specified collection to the end of this array
		 *
		 * @param E
		 * @param target
		 * @return
		 */
		template <typename E>
		boolean ArrayList<E>::addAll(Collection<E> &target) {
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
		 * @param E
		 */
		template <typename E>
		void ArrayList<E>::clear() {
			delete[]this->array;
			this->realSize = 0;
			this->virtualSize = 4;
			this->array = new E[this->virtualSize];
		}
		
		/**
		 * Get value from index
		 *
		 * @param index
		 * @return
		 */
		template <typename E>
		E &ArrayList<E>::get(const int index) const {
			return this->array[ index ];
		}
		
		/**
		 * Return true if Array is empty, return false if Array not empty
		 *
		 * @param E
		 * @return
		 */
		template <typename E>
		boolean ArrayList<E>::isEmpty() const {
			return ( this->realSize == 0 );
		}
		
		/**
		 * Return real size of array
		 *
		 * @param E
		 * @return int
		 */
		template <typename E>
		int ArrayList<E>::size() const{
			return this->realSize;
		}
		
		/**
		 * Replaces the element at the specified position in this list with the specified element.
		 *
		 * @param E
		 * @param index
		 * @param element
		 * @return true or false
		 */
		template <typename E>
		E &ArrayList<E>::set(int index, E &element) {
			if (index < 0 || index > this->size() - 1) {
				return false;
			}
			this->array[ index ] = element;
			return this;
		}
	}
}

#endif//NATIVE_JAVA_UTIL_ARRAY_LIST_HPP
