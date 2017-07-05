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
        protected:
            std::vector<E> original;
            int capacityIncrement;

        public:
            /**
             * Construct an empty Vector with initial capacity is 10.
             *
             */
            Vector() : Vector(10) { }

            /**
             * Construct an empty Vector with custom initial capacity.
             *
             * @param initialCapacity
             */
            Vector(int initialCapacity) : Vector(initialCapacity, 0) { }

            /**
             * Construct an empty Vector with custom initial capacity and capacity increment.
             *
             * @param initialCapacity
             * @param capacityIncrement
             */
            Vector(int initialCapacity, int capacityIncrement) {
                if (initialCapacity < 0) {
                    throw std::invalid_argument("initial capacity is negative");
                }
                this->original.reserve(initialCapacity);
                this->capacityIncrement = capacityIncrement;
            }

            /**
             * Constructs a Vector from a Vector.
             *
             * @param target
             */
            Vector(const Vector<E> &target) {
                const E *targetData = target.original.data();
                register int index;
                for (index = 0; index < target.original.size(); index++) {
                    this->original.push_back(targetData[index]);
                }
            }

            /**
             * Destructor.
             */
            virtual ~Vector() { }

        public:
            /**
             * Adds an element to the end of this Vector.
             *
             * @param element
             * @return boolean
             */
            boolean add(const E &element) {
                this->ensureCapacity(this->original.size() + 1);
                this->original.push_back(element);
                return true;
            }

            /**
             * Inserts a new element to specified index in this Vector.
             *
             * @param index
             * @param <E>
             */
            void add(int index, const E &element) {
                int size = this->original.size();
                if (index < 0 || index >= size) {
                    throw std::invalid_argument("index is out of range");
                }
                this->ensureCapacity(size + 1);
                this->original.insert(this->original.begin() + index, element);
            }

            /**
             * Adds an element to the end of this Vector.
             *
             * @param element
             */
            void addElement(const E &element) {
                this->add(element);
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
                const E *vectorData = this->original.data();
                register int index;
                for (index = 0; index < this->original.size(); index++) {
                    clonedVector.add(vectorData[index]);
                }
                return clonedVector;
            }

            /**
             * Returns true if this Vector contains the specified element.
             *
             * @param element
             * @return boolean
             */
            boolean contains(const E &element) const {
                if (this->indexOf(element) == -1) {
                    return false;
                }
                return true;
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
             * Increases the capacity of this vector,
             * if necessary, to ensure that it can hold at least the number of elements specified by
             * the minimum capacity argument.
             *
             * @param minCapacity
             */
            void ensureCapacity(int minCapacity) {
                int oldCapacity = this->capacity();
                if ((minCapacity > 0) && (minCapacity > oldCapacity)) {
                    // The new capacity will be the old capacity plus capacityIncrement,
                    // unless the value of capacityIncrement is less than or equal to zero,
                    // in which case the new capacity will be twice the old capacity.
                    int newCapacity = (this->capacityIncrement > 0) ?
                                      (oldCapacity + this->capacityIncrement) : (oldCapacity * 2);
                    // If this new capacity is still smaller than minCapacity, then the new capacity will be minCapacity.
                    if (newCapacity < minCapacity) {
                        newCapacity = minCapacity;
                    }

                    this->original.reserve(newCapacity);
                }
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
             * @param element
             * @return int
             */
            int indexOf(const E &element) const {
                int currentSize = this->original.size();
                register int index;
                for (index = 0; index < currentSize; index++) {
                    if (element == this->original[index]) {
                        return index;
                    }
                }
                return -1;
            }

            /**
             * Returns the index of the first occurrence of the specified element in this Vector,
             * searching forwards from index, or returns -1 if the element is not found.
             *
             * @param element
             * @param index
             * @return int
             */
            int indexOf(const E &element, int index) {
                if (index < 0) {
                    throw std::invalid_argument("index is negative");
                }

                register int position;
                for (position = index; position < this->original.size(); position++) {
                    if (element == this->original[position]) {
                        return position;
                    }
                }

                return -1;
            }

            /**
             * Inserts the specified element at the specified index in this Vector.
             *
             * @param element
             * @param index
             */
            void insertElementAt(const E &element, int index) {
                this->add(index, element);
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
             * @param element
             * @return int
             */
            int lastIndexOf(const E &element) const {
                int maxIndex = this->original.size() - 1;
                return this->lastIndexOf(element, maxIndex);
            }

            /**
             * Returns the index of the last occurrence of the specified element in this vector,
             * searching backwards from index, or returns -1 if the element is not found.
             *
             * @param element
             * @param index
             * @return
             */
            int lastIndexOf(const E &element, int index) const {
                if (index >= this->original.size()) {
                    throw std::invalid_argument("index is greater than or equal to the current size of this vector");
                }

                register int position;
                for (position = index; position >= 0; position--) {
                    if (element == this->original[position]) {
                        return position;
                    }
                }

                return -1;
            }

            /**
             * Replaces the element at the specified index with the specified element.
             *
             * @param index
             * @param element
             * @return the element previously at the specified index.
             */
            E set(int index, const E &element) {
                if (index < 0 || index >= this->original.size()) {
                    throw std::invalid_argument("index is out of range");
                }
                E removedElement = this->get(index);
                this->original[index] = element;
                return removedElement;
            }

            /**
             * Sets the element at the specified index of this Vector to be the specified element.
             *
             * @param element
             * @param index
             */
            void setElementAt(const E &element, int index) {
                this->set(index, element);
            }

            /**
             * Sets the size of this Vector.
             *
             * @param newSize
             */
            void setSize(int newSize) {
                if (newSize < 0) {
                    throw std::invalid_argument("new size is negative");
                }
                // If new size is greater than current capacity, run ensureCapacity to increase capacity.
                if (newSize > this->original.size()) {
                    this->ensureCapacity(newSize);
                }
                this->original.resize(newSize);
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
             * Removes the first occurrence of the specified element in this Vector.
             *
             * @param element
             * @return boolean
             */
            boolean remove(const Object &element) {
                const E *referenceToElement = dynamic_cast<const E *>(&element);
                register int index;
                for (index = 0; index < this->original.size(); index++) {
                    if ((*referenceToElement) == this->original[index]) {
                        this->remove(index);
                        return true;
                    }
                }
                return false;
            }

            /**
             * Removes all elements of this Vector.
             *
             */
            void removeAllElements() {
                this->clear();
            }

            /**
             * Removes the first (lowest-indexed) occurrence of the argument from this vector.
             *
             * @param element
             * @return boolean
             */
            boolean removeElement(const Object &element) {
                return this->remove(element);
            }

            /**
             * Deletes the element at the specified index.
             *
             * @param index
             */
            void removeElementAt(int index) {
                this->remove(index);
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

        public:
            /**
             * Trims the capacity of this Vector to be the Vector's current size.
             *
             */
            void trimToSize() {
                this->original.shrink_to_fit();
            }
        };
    }
}

#endif // NATIVE_JAVA_UTIL_VECTOR_HPP
