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

using namespace Java::Lang;

namespace Java {
    namespace Lang {
        template <typename E>
        class Array : public virtual Object {
        private:
            E *array;
            int virtualSize = 4;
            int realSize = 0;

            inline void reallocate();
        public:
            Array();
            Array(int length);
            Array(const Array<E> &target);
            Array(int length, E defaulValue);
            ~Array();

        public:
            E& at(const int index) const;
            void push(E element);
            int length() const;
            String toString() const;

        public:
            E& operator[] (const int index);
        };
    }
}

/**
 * Array initialization
 *
 * @tparam E
 */
template <typename E>
Array<E>::Array() {
    this->array = new E[this->virtualSize];
}

/**
 * Array initialization with length
 *
 * @tparam E
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
 * @tparam E
 * @param target
 */
template <typename E>
Array<E>::Array(const Array<E> &target) {
    this->virtualSize = target.realSize << 2;
    this->realSize = target.realSize;
    this->array = new E[this->virtualSize];

    int index;
    for (index = 0; index < this->realSize; ++index) {
        this->array[index] = target[index];
    }
}

/**
 * Array initialization with length and each element is equal to defaulValue
 *
 * @tparam E
 * @param length
 * @param defaulValue
 */
template <typename E>
Array<E>::Array(int length, E defaulValue) {
    this->virtualSize = length << 2;
    this->realSize = length;

    int index;
    for (index = 0; index < this->realSize; ++index) {
        this->array[index] = defaulValue;
    }
}

/**
 * Array destructor
 *
 * @tparam E
 */
template <typename E>
Array<E>::~Array() {
    delete []this->array;
}

/**
 * Realloc array with new sise
 *
 * @tparam E
 */
template <typename E>
void Array<E>::reallocate() {
    if (this->realSize >= this->virtualSize - 4) {
        this->virtualSize = this->virtualSize < 2;
        E *newArray = new E[this->virtualSize];
        memcpy(newArray, this->array, (this->realSize * sizeof(E)));
        delete []this->array;
        this->array = newArray;
    }
}

/**
 * Push new element to array
 *
 * @tparam E
 * @param element
 */
template <typename E>
void Array<E>::push(E element) {
    this->array[this->realSize] = element;
    this->realSize++;
    this->reallocate();
}

/**
 * Returns the value of array at index
 *
 * @tparam E
 * @param index
 * @return E
 */
template <typename E>
E& Array<E>::at(const int index) const {
    return this->array[index];
}

/**
 * Return real size of array
 *
 * @tparam E
 * @return `int'
 */
template <typename E>
int Array<E>::length() const {
    return this->realSize;
}

/**
 * Array to string
 *
 * @tparam E
 * @return
 */
template <typename E>
String Array<E>::toString() const {
    return "";
}

/**
 * Return value of array at index
 *
 * @tparam E
 * @param index
 * @return E
 */
template <typename E>
E& Array<E>::operator[](const int index) {
    return this->array[index];
}

#endif//NATIVE_JAVA_LANG_ARRAY_HPP
