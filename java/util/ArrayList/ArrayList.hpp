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
			//public virtual AbstractList<E>,
			//public virtual Serializable,
			//public virtual Cloneable,
			//public virtual List<E>,
			public virtual RandomAccess {
		private:
			E *array;
			int virtualSize = 4;
			int realSize;
			void reallocate() {
				if (this->realSize >= this->virtualSize - 4) {
					this->virtualSize = this->virtualSize < 2;
					E *newArray = new E[this->virtualSize];
					memcpy(newArray, this->array, ( this->realSize * sizeof(E)));
					delete[]this->array;
					this->array = newArray;
				}
			}
		public:
			ArrayList() {
				this->array = new E[this->virtualSize];
			}
			ArrayList(Collection<E> &c) {
				this->virtualSize = c.size() << 2;
				this->realSize = c.size();
				this->array = new E[this->virtualSize];
				register int index;
				Iterator<E> it = c.iterator();
				while (it.hasNext()) {
					this->array[index] = it;
					it.next();
				}
			}
			ArrayList(int initialCapacity) {
				this->virtualSize = initialCapacity << 2;
				this->realSize = initialCapacity;
				this->array = new E[this->virtualSize];
			}
			~ArrayList() {
				delete[]this->array;
				this->realSize = this->virtualSize;
			}
			string toString() {
				return AbstractCollection<E>::toString();
			}
		public:
			ArrayListIterator<E> begin() const {
				return ArrayListIterator<E>(this, 0);
			}
			ArrayListIterator<E> end() const {
				return ArrayListIterator<E>(this, this->realSize);
			}
		public:
			boolean add(E &e) {
				this->array[ this->realSize ] = e;
				this->realSize++;
				this->reallocate();
			}
			void add(int index, E &element)  {
				register int loopIndex;
				for (loopIndex = this->realSize - 1; loopIndex >= index; --loopIndex) {
					this->array[ loopIndex + 1 ] = this->array[ loopIndex ];
				}
				this->realSize++;
				this->reallocate();
			}
			boolean addAll(Collection<E> &c) {
				// TODO
				return true;
			}
			boolean addAll(int index, Collection<E> &c) {
				// TODO
				return true;
			}
			void clear() {
				delete[]this->array;
				this->realSize = 0;
				this->virtualSize = 4;
				this->array = new E[this->virtualSize];
			}
			Object &clone() {
				// TODO
				Object c;
				return c;
			}
			boolean contains(Object &o) const {
				// TODO
				return true;
			}
			void ensureCapacity(int minCapacity) const {
				// TODO
			}
			void forEach(Consumer<E> &action) const {
			}
			E &get(int index) const {
				// TODO
				E *e = new E();
				return *e;
			}
			int indexOf(Object &o) const {
				// TODO
				return 0;
			}
			boolean isEmpty() const {
				return this->realSize == 0;
			}
			Iterator<E> &iterator() const {
				// TODO
				Iterator<E> *it = new Iterator<E>();
				return *it;
			}
			int lastIndexOf(Object &o) const {
				// TODO
				return 0;
			}
			ListIterator<E> &listIterator() const {
				// TODO
				ListIterator<E> *listIterator = new ListIterator<E>();
				return *listIterator;
			}
			ListIterator<E> &listIterator(int index) const {
				// TODO
				ListIterator<E> *listIterator = new ListIterator<E>();
				return *listIterator;
			}
			E &remove(int index) {
				// TODO
				E *e = new E();
				return *e;
			}
			boolean remove(Object &o) {
				// TODO
				return true;
			}
			boolean removeAll(Collection<Object> &c) {
				// TODO
				return true;
			}
			boolean removeIf(Predicate<E> &filter) {
				// TODO
				return true;
			}
			void replaceAll(UnaryOperator<E> &unaryOperator) {
				// TODO
			}
			boolean retainAll(Collection<Object> &c) {
				// TODO
				return true;
			}
			E &set(int index, E &element) {
				// TODO
				E *e = new E();
				return *e;
			}
			int	size() const {
				// TODO
				return this->realSize;
			}
			void sort(Comparator<E> &c) {
				// TODO
			}
			Spliterator<E>	&spliterator() const {
				// TODO
				Spliterator<E> *spliterator = new Spliterator<E>();
				return *spliterator;
			}
			List<E> &subList(int fromIndex, int toIndex) const {
				// TODO
				List<E> *list = new ArrayList<E>();
				return *list;
			}
			Array<Object>	&toArray() {
				// TODO
				Array<Object> objects;
				return objects;
			}
			template <typename T>
			Array<T> &toArray(Array<T> &a) const {
				// TODO
				return a;
			}
			void trimToSize() {
				// TODO
			}
			string toString() const {
				return (string) "" ;
			}
		protected:
			void removeRange(int fromIndex, int toIndex) {
				// TODO
			}
		};
	
		template <typename E>
		class SubList : public virtual AbstractList<E> {
		private:
			AbstractList<E> l;
		};
	}
}

#endif//NATIVE_JAVA_UTIL_ARRAY_LIST_HPP
