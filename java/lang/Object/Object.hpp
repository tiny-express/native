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

#ifndef NATIVE_JAVA_LANG_OBJECT_H
#define NATIVE_JAVA_LANG_OBJECT_H

extern "C" {
#include "../../../builtin.h"
};

#include <memory>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

// Define instanceof
template<typename Base, typename T>
bool instanceof(T) {
	return std::is_base_of<Base, T>::value;
}

// Define builtin types
typedef bool boolean;

template <typename E> class Array;
template <typename E> class ArrayIterator;

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
class Array  {
private:
	std::vector<E> original;
public:
	Array() {
	}
	Array(std::initializer_list<E> list) {
		typename std::initializer_list<E>::iterator it;
		for (it = list.begin(); it != list.end(); ++it) {
			original.push_back(*it);
		}
		this->length = original.size();
	}
	~Array() {};
	int length;
	ArrayIterator<E> begin() const {
		return ArrayIterator<E>(this, 0);
	}
	ArrayIterator<E> end() const {
		return ArrayIterator<E>(this, this->length);
	}
public:
	void push(E e) {
		original.push_back(e);
		this->length = original.size();
	}
	E get(const int index) const {
		return (E) original.at(index);
	}
	string toString() {
		return (string ) "";
	}
public:
	E &operator[](const int index) {
		return this->original.at(index);
	}
	Array<E> operator+=(const std::initializer_list<E> &list) {
		typename std::initializer_list<E>::iterator it;
		for (it = list.begin(); it != list.end(); ++it) {
			original.push_back(*it);
		}
		this->length = original.size();
		return *this;
	}
};

namespace Java {
	namespace Lang {
		template <typename E>
		class Class;
		class String;
		class Object;
		
		template <typename E>
		class Class {
		public:
			Class();
			~Class();
		};
		
		class Object {
		protected:
			Object	&clone();
			void	finalize();
		public:
			string toString();
			int hashCode();
			boolean equals(const Object &obj) const {
				if (this->hashCode() == obj.hashCode()) {
					return true;
				}
				return false;
			}
			Class<Object> getClass() {
				// This method is only available in Java
				// should not be supported in this library
			}
			long hashCode() const {
				return (intptr_t) std::addressof(*this);
			}
			void notify() {
				// TODO
			}
			void notifyAll() {
				// TODO
			}
			string toString() const {
				return (string) "";
			}
			void wait() {
				// TODO
			}
			void wait(long timeout) {
				// TODO
			}
			void wait(long timeout, int nanos) {
				// TODO
			}
			boolean operator==(const Object &target) const {
				return this->equals( target);
			}
			boolean operator!=(const Object &target) const {
				return !this->equals( target);
			}
		};
	}
}

#endif//NATIVE_JAVA_LANG_OBJECT_H