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

#ifndef NATIVE_JAVA_UTIL_VECTOR_HPP
#define NATIVE_JAVA_UTIL_VECTOR_HPP

#include "../../Lang.hpp"
#include "../AbstractSequentialList/AbstractSequentialList.hpp"
#include "../Collection/Collection.hpp"
#include "../RandomAccess/RandomAccess.hpp"

using namespace Java::Lang;

namespace Java {
    namespace Util {
        template <typename E>
        class Vector
//                :
//                public virtual List<E>,
//                public virtual RandomAccess,
//                public virtual Cloneable,
//                public virtual Serializable
        {
        private:
            std::vector<E> original;

        public:
            /**
             * Constructs an empty Vector.
             */
            Vector() { }

            /**
             * Destructor.
             */
            virtual ~Vector() { }

        public:
            /**
             * Add an element to the end of this Vector.
             * @param e
             * @return boolean
             */
            boolean add(const E &e) {
                this->original.push_back(e);
                return true;
            }

            /**
             * Insert a new element to specified index in this Vector.
             * @param index
             * @param element<E>
             */
            void add(int index, const E &element) {
                if (index < 0 || index >= this->original.size()) {
                    throw std::invalid_argument("index is out of range");
                }
                this->original.insert(this->original.begin() + index, element);
            }

            /**
             * Return capacity (current number of slots allocated for this Vector).
             * @return int
             */
            int capacity() const {
                return this->original.capacity();
            }

            /**
             * Clear all element inside this Vector.
             */
            void clear() {
                this->original.clear();
            }

            /**
             * Return the first element (index = 0) of this Vector.
             * @return element<E>
             */
            E firstElement() {
                if (this->original.empty()) {
                    throw std::out_of_range("vector is empty");
                }
                return this->original.front();
            }

            /**
             * Get an element at specified index.
             * @param index
             * @return element<E>
             */
            E get(int index) const {
                return this->original.at(index);
            }

            /**
             * Check this Vector is empty or not.
             * @return boolean
             */
            boolean isEmpty() const {
                return this->original.empty();
            }

            /**
             *
             * @param e
             * @return int
             */
            int indexOf(const E &e) const {
                int cur_size = this->original.size();
                for (int i = 0; i < cur_size; i++) {
                    if (this->original[i] == e) {
                        return i;
                    }
                }
                return -1;
            }

            /**
             * Return the last element of this Vector.
             * @return element<E>
             */
            E lastElement() const {
                if (this->original.empty()) {
                    throw std::out_of_range("vector is empty");
                }
                return this->original.back();
            }

            /**
             *
             * @return int
             */
            int size() const {
                return this->original.size();
            }

            /**
             * Remove an element at specified index in this Vector.
             * @param index
             * @return element<E>
             */
            E remove(int index) {
                if (index < 0 || index >= this->original.size()) {
                    throw std::invalid_argument("index is out of range");
                }
                E rm_item = this->original.at(index);
                this->original.erase(this->original.begin() + index);
                return rm_item;
            }
        };
    }
}

#endif // NATIVE_JAVA_UTIL_VECTOR_HPP
