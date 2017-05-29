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
			//public virtual List<E>,
			public virtual RandomAccess {
		private:
			std::vector<E> original;
		public:
			ArrayList() {
			}
			ArrayList(Collection<E> &c) {
			}
			ArrayList(int initialCapacity) {
			}
			~ArrayList() {
			}
		public:
			ArrayListIterator<E> begin() const {
				return ArrayListIterator<E>(this, 0);
			}
			ArrayListIterator<E> end() const {
				return original.end();
			}
		public:
			void push_back(const E &target) {
				this->original.push_back(target);
			}
			boolean add(E &e) {
				original.push_back(e);
				return true;
			}
			void add(int index, E &element)  {
				// TODO
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
				// TODO
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
				return (E&) original.at(index);
			}
			int indexOf(Object &o) const {
				// TODO
				return 0;
			}
			boolean isEmpty() const {
				return original.empty();
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
				return original.size();
			}
			void sort(Comparator<E> &c) {
				// TODO
			}
			Spliterator<E>	&spliterator() const {
				// TODO
				Spliterator<E> *spliterator = new Spliterator<E>();
				return *spliterator;
			}
//			List<E> &subList(int fromIndex, int toIndex) const {
//				// TODO
//				List<E> *list = new ArrayList<E>();
//				return *list;
//			}
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
