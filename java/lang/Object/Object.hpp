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

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <type_traits>

// Define instanceof
template <typename Base, typename T>
bool instanceof(T) {
	return std::is_base_of<Base, T>::value;
}

// Define builtin types
typedef bool boolean;

template <typename E>
class Array;

template <typename E>
class ArrayIterator;

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
	~Array() {}
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
		string result = strdup("");
		if (std::is_same<E, byte>::value || std::is_same<E, char>::value) {
			for (char element : *this) {
				char *result_holder = result;
				result = string_append(result, element);
				free(result_holder);
			}
			return result;
		}
		return (string ) "This type is not available for serialize";
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
			/**
			 * Return a copy of this Object
			 * Not support this function yet
			 * @return
			 */
			Object &clone();
			
			/**
			 * Not support this function yet
			 */
			void finalize();
		
		public:
			/**
			 * A string representation of the object.
			 * @return string
			 */
			virtual string toString() const {
				return string_from_int(this->hashCode());
			}
			
			/**
			 * Support compare two Object through hashCode()
			 *
			 * @param obj
			 * @return boolean
			 */
			virtual boolean equals(const Object &o) const {
				if (this->hashCode() == o.hashCode()) {
					return true;
				}
				return false;
			}
			
			/**
			 * Not support this function yet
			 */
			Class<Object> getClass();
			
			/**
			 * A hash code value for this object.
			 *
			 * @return long
			 */
			virtual long hashCode() const {
				return  (intptr_t) std::addressof(*this);
			}
			
			/**
			 * Not support this function yet
			 */
			void notify();
			
			/**
			 * Not support this function yet
			 */
			void notifyAll();
			
			/**
			 * Not support this function yet
			 */
			void wait();
			
			/**
			 * Not support this function yet
			 */
			void wait(long timeout);
			
			/**
			 * Not support this function yet
			 */
			void wait(long timeout, int nanos);
			
			/**
			 * Compare two object is equal or not
			 * @param target
			 * @return boolean
			 */
			boolean operator==(const Object &target) const {
				return this->equals(target);
			}
			
			/**
			 * Compare two object is not equal or not
			 * @param target
			 * @return boolean
			 */
			boolean operator!=(const Object &target) const {
				return !this->equals(target);
			}
		};
	}
}

#endif//NATIVE_JAVA_LANG_OBJECT_H
