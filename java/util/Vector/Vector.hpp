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
             *
             */
            Vector() { }

            /**
             * Destructor.
             */
            virtual ~Vector() { }

        public:
            /**
             * Adds an element to the end of this Vector.
             *
             * @param e
             * @return boolean
             */
            boolean add(const E &e) {
                this->original.push_back(e);
                return true;
            }

            /**
             * Inserts a new element to specified index in this Vector.
             *
             * @param index
             * @param <E>
             */
            void add(int index, const E &element) {
                if (index < 0 || index >= this->original.size()) {
                    throw std::invalid_argument("index is out of range");
                }
                this->original.insert(this->original.begin() + index, element);
            }

            /**
             * Return capacity (current number of slots allocated for this Vector).
             *
             * @return int
             */
            int capacity() const {
                return this->original.capacity();
            }

            /**
             * Clears all element inside this Vector.
             *
             */
            void clear() {
                this->original.clear();
            }

            /**
             * Returns a clone of this Vector.
             *
             * @return Vector<E>
             */
            Vector<E> clone() const {
                Vector<E> clonedVector;
                E const *vectorData = this->original.data();
                for (int i = 0; i < this->original.size(); i++) {
                    clonedVector.add(vectorData[i]);
                }
                return clonedVector;
            }

            /**
             * Gets an element at specified index.
             *
             * @param index
             * @return <E>
             */
            E elementAt(int index) const {
                return this->get(index);
            }

            /**
             * Returns the first element (index = 0) of this Vector.
             *
             * @return <E>
             */
            E firstElement() {
                if (this->original.empty()) {
                    throw std::out_of_range("vector is empty");
                }
                return this->original.front();
            }

            /**
             * Gets an element at specified index.
             *
             * @param index
             * @return <E>
             */
            E get(int index) const {
                return this->original.at(index);
            }

            /**
             * Checks this Vector is empty or not.
             *
             * @return boolean
             */
            boolean isEmpty() const {
                return this->original.empty();
            }

            /**
             * Returns index of an element in this Vector.
             *
             * @param e             *
             * @return int
             */
            int indexOf(const E &e) const {
                int currentSize = this->original.size();
                for (int i = 0; i < currentSize; i++) {
                    if (this->original[i] == e) {
                        return i;
                    }
                }
                return -1;
            }

            /**
             * Returns the last element of this Vector.
             *
             * @return <E>
             */
            E lastElement() const {
                if (this->original.empty()) {
                    throw std::out_of_range("vector is empty");
                }
                return this->original.back();
            }

            /**
             * The last index of an element.
             * This function returns the index of the last occurrence of the specified element in this Vector.
             * If this Vector doesn't contain the element, returns -1.
             *
             * @param e
             * @return int
             */
            int lastIndexOf(const E &e) const {
                int index = -1;
                for (int i = 0; i < this->original.size(); i++) {
                    if (e == this->original[i]) {
                        index = i;
                    }
                }
                return index;
            }

            /**
             * Replaces the element at the specified index with the specified element.
             *
             * @param index
             * @param e
             * @return the element previously at the specified index.
             */
            E set(int index, const E &e) {
                if (index < 0 || index >= this->original.size()) {
                    throw std::invalid_argument("index is out of range");
                }
                E removedElement = this->get(index);
                this->original[index] = e;
                return removedElement;
            }

            /**
             * Returns size (number of elements) of this Vector.
             *
             * @return int
             */
            int size() const {
                return this->original.size();
            }

            /**
             * Removes an element at specified index in this Vector.
             *
             * @param index
             * @return <E>
             */
            E remove(int index) {
                if (index < 0 || index >= this->original.size()) {
                    throw std::invalid_argument("index is out of range");
                }
                E removedItem = this->original.at(index);
                this->original.erase(this->original.begin() + index);
                return removedItem;
            }

            /**
             * Removes all elements of this Vector.
             */
            void removeAllElements() {
                this->clear();
            }

        protected:
            /**
             * Removes all elements have index between fromIndex (inclusive) and toIndex (exclusive).
             *
             * @param fromIndex
             * @param toIndex
             */
            void removeRange(int fromIndex, int toIndex) {
                if (fromIndex >= toIndex) {
                    return;
                }

                int currentSize = this->original.size();
                if (fromIndex < 0 || fromIndex >= currentSize || toIndex < 0 || toIndex >= currentSize) {
                    return;
                }

                // startPosition is the index of the last element in removed range [fromIndex .. startPosition].
                // We need to reduce 1 because the element at toIndex will not be removed.
                int startPosition = fromIndex + (toIndex - fromIndex) - 1;
                register int position;
                for (position = startPosition; position >= fromIndex; position--) {
                    this->remove(position);
                }
            }
        };
    }
}

#endif // NATIVE_JAVA_UTIL_VECTOR_HPP
