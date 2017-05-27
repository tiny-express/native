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

// Define builtin types
typedef bool boolean;

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
class Array  {
public:
	Array();
	Array(std::initializer_list<E> list);
	Array(int length);
	Array(const Array<E> &target);
	~Array();
	int length;

public:
	ArrayIterator<E> begin() const;
	ArrayIterator<E> end() const;
	void push(E e);
	E get(const int index) const;
	string toString() const;

public:
	E &operator[](const int index);
};

namespace Java {
	namespace Lang {
		class Object {
		protected:
			virtual string toString() const = 0;
		};
	}
}

#endif//NATIVE_JAVA_LANG_OBJECT_H