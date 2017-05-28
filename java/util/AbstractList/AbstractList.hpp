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

#ifndef  NATIVE_JAVA_UTIL_ABSTRACT_LIST_HPP
#define NATIVE_JAVA_UTIL_ABSTRACT_LIST_HPP

#include "../AbstractCollection/AbstractCollection.hpp"
#include "../ListIterator/ListIterator.hpp"
#include "../Collection/Collection.hpp"
#include "../List/List.hpp"

namespace Java {
	namespace Util {
		template <class E>
		class AbstractList : public virtual AbstractCollection<E> {
		protected:
			AbstractList() {
			}
		public:
			boolean add(E e) {
				// TODO
				return true;
			}
			void add(int index, E element) {
				// TODO
			}
			boolean addAll(int index, Collection<E> &c) {
				// TODO
				return true;
			}
			void clear() {
				// TODO
			}
			boolean equals(Object &o) const {
				return true;
			}
			virtual E &get(int index) const = 0;
			int	hashCode()  const {
				// TODO
				return 0;
			}
			int	indexOf(Object &o) const {
				return 0;
			}
			Iterator<E> iterator() {
				Iterator<E> *it = new Iterator<E>();
			}
			int	lastIndexOf(Object &o) {
				// TODO
				return 0;
			}
			ListIterator<E> listIterator() {
				// TODO
				ListIterator<E> *listIterator = new ListIterator<E>();
				return *listIterator;
			}
			ListIterator<E> listIterator(int index) {
				// TODO
				ListIterator<E> *listIterator = new ListIterator<E>();
				return *listIterator;
			}
			E remove(int index);
			E set(int index, E element) const {
				// TODO
				E *e = new E();
				return e;
			}
			List<E>	&subList(int fromIndex, int toIndex) const {
			}
		};
	}
}

#endif //NATIVE_ABSTRACT_LIST_HPP
