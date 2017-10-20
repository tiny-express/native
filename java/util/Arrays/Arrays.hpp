/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
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

#ifndef JAVA_UTIL_ARRAYS_ARRAYS_HPP
#define JAVA_UTIL_ARRAYS_ARRAYS_HPP

#include <stack>
#include "../../Lang.hpp"
#include "../List/List.hpp"
#include "../ArrayList/ArrayList.hpp"

#define BINARY_SEARCH_BY_INDEX(TYPE); \
static int binarySearchByIndex(TYPE array[],\
                                int fromIndex,\
                                int toIndex,\
                                TYPE key) {\
    return BinarySearch(array, fromIndex, toIndex, key);\
}

#define BINARY_SEARCH_BY_KEY(TYPE); \
static int binarySearchByKey(TYPE array[],\
                            TYPE key,\
                            int arraySize) {\
    return BinarySearch(array, 0, arraySize - 1, key);\
}

#define COPY_OF(TYPE); \
static Array<TYPE> copyOf(Array<TYPE> original,\
                            int newLength) {\
    return copyOfOrigin(original, newLength, NULL);\
}

#define COPY_OF_RANGE(TYPE); \
static Array<TYPE> copyOfRange(Array<TYPE> original,\
                                int from,\
                                int to) {\
    return copyOfRangeOrigin(original, from, to);\
}

#define EQUALS(TYPE); \
static boolean equals(Array<TYPE> array,\
                        Array<TYPE> a2) {\
    return equalsOrigin(array, a2);\
}

#define FILL(TYPE); \
static void fill(Array<TYPE> *array,\
                    TYPE value) {\
    return fileOrigin(array, 0, (*array).length - 1, value);\
}

#define FILL_BY_INDEX(TYPE); \
static void fillByIndex(Array<TYPE> *array,\
                        int fromIndex,\
                        int toIndex,\
                        TYPE value) {\
    return fileOrigin(array, fromIndex, toIndex, value);\
}

#define HASH_CODE(TYPE); \
static int hashCode(Array<TYPE> array) {\
    if (array.length == 0) {\
        return 0;\
    }\
\
    int result = 1;\
    for (TYPE element : array) {\
        result = 31 * result + element;\
    }\
\
    return result;\
}

#define SORT(TYPE); \
static void sort(TYPE array[],\
                int arraySize) {\
    return sortOrigin(array, 0, arraySize - 1);\
}

#define SORT_BY_INDEX(TYPE); \
static void sortByIndex(TYPE array[],\
                        int fromIndex,\
                        int toIndex) {\
    return sortOrigin(array, fromIndex, toIndex);\
}

#define SORT_BY_ARRAY_SIZE(TYPE); \
static void sortByArraySize(TYPE array[],\
                            int arraySize) {\
    return sortOrigin(array, 0, arraySize - 1);\
}

#define SORT_BY_INDEX_ARRAY_SIZE(TYPE); \
static void sortByIndexArraySize(TYPE array[],\
                                int fromIndex,\
                                int toIndex,\
                                TYPE arraySize) {\
    return sortOrigin(array, fromIndex, toIndex);\
}

using namespace Java::Lang;

namespace Java {
    namespace Util {
        class Arrays : public Object {
        private:
            Arrays();

            ~Arrays();

        public:
            template<typename AnotherType, typename... Type>
            static List<AnotherType> asList(Type... array) {
                //FIXME: Please implement ArrayList<Type>(array);
            }

            BINARY_SEARCH_BY_INDEX(char);
            BINARY_SEARCH_BY_INDEX(byte);
            BINARY_SEARCH_BY_INDEX(short);
            BINARY_SEARCH_BY_INDEX(int);
            BINARY_SEARCH_BY_INDEX(long);
            BINARY_SEARCH_BY_INDEX(float);
            BINARY_SEARCH_BY_INDEX(double);

            static int binarySearchByIndex(Object *array,
                                           int fromIndex,
                                           int toIndex,
                                           Object key) {
                return -1;
            }

            BINARY_SEARCH_BY_KEY(char);
            BINARY_SEARCH_BY_KEY(byte);
            BINARY_SEARCH_BY_KEY(short);
            BINARY_SEARCH_BY_KEY(int);
            BINARY_SEARCH_BY_KEY(long);
            BINARY_SEARCH_BY_KEY(float);
            BINARY_SEARCH_BY_KEY(double);

            static int binarySearchByKey(Object *array,
                                         Object key,
                                         int arraySize) {
                return -1;
            }

            template<typename Type>
            static int binarySearchByKey(Type *array,
                                         Type key,
                                         int arraySize) {
                return BinarySearch(array, 0, arraySize - 1, key);
            }

            template<typename Type>
            static int binarySearch(Type array[],
                                    int fromIndex,
                                    int toIndex,
                                    Type key) {
                return BinarySearch(array, 0, toIndex, key);
            }

            template<typename Type>
            static int binarySearch(Array<Type> array,
                                    Type key,
                                    int arraySize) {
                return BinarySearch(array, 0, arraySize - 1, key);
            }

            template<typename Type>
            static int binarySearch(Array<Type> array,
                                    int fromIndex,
                                    int toIndex,
                                    Type key) {
                return BinarySearch(array, 0, toIndex, key);
            }

            COPY_OF(boolean);
            COPY_OF(char);
            COPY_OF(short);
            COPY_OF(int);
            COPY_OF(long);
            COPY_OF(float);
            COPY_OF(double);

            template<typename Type>
            static Array<Type> copyOf(Array<Type> original,
                                      int newLength) {
                return copyOfOrigin(original, newLength, NULL);
            }

            template<typename Type, typename AnotherType>
            static Array<Type> copyOf(Array<AnotherType> anotherType, 
                                      int newLength, 
                                      Type newType) {
                Array<Type> result;
                for (AnotherType element: anotherType) {
                    Type newElement = (Type) anotherType;  // Type must have array constructor of AnotherType
                    result.push(newElement);
                }

                return result;
            }

            COPY_OF_RANGE(boolean);
            COPY_OF_RANGE(byte);
            COPY_OF_RANGE(char);
            COPY_OF_RANGE(short);
            COPY_OF_RANGE(int);
            COPY_OF_RANGE(long);
            COPY_OF_RANGE(float);
            COPY_OF_RANGE(double);

            template<typename Type>
            static Array<Type> copyOfRange(Array<Type> original, 
                                           int from, 
                                           int to) {
                return copyOfRangeOrigin(original, from, to);
            }

            template<typename Type, typename AnotherType>
            static Array<Type> copyOfRange(Array<AnotherType> original, 
                                           int from, int to, 
                                           Type newType) {
                Array<Type> result;

                if (from < 0 
                    || to <= 0 
                    || to <= from 
                    || to > original.length) {
                    return result;
                }

                for (int index = from; index < to; ++index) {
                    Type element = (Type) original[index];  // Type must have array constructor of AnotherType
                    result.push(element);
                }

                return result;
            }

            static boolean deepEquals(Object fisrtArray[],
                                      Object secondArray[]) {
                return false; /// Don't support this method
            }

            static int deepHashCode(Object array[]) {
                return -1; /// Don't support this method
            }

            static String deepToString(Object array[]) {
                return ""; /// Don't support this method
            }

            EQUALS(boolean);
            EQUALS(byte);
            EQUALS(char);
            EQUALS(double);
            EQUALS(float);
            EQUALS(int);
            EQUALS(long);
            EQUALS(short);

            /**
             *  Don't support this in C++ runtime, because <bool> will be optimised to bit and can't modify in vector of Array
             *  Use fill(Array<int>, int) instead
             */
            //static void fill(Array<boolean> *array, boolean value) {}

            /**
             *  Don't support this in C++ runtime, because <bool> will be optimised to bit and can't modify in vector of Array
             *  Use fill(Array<int>, int) instead
             */
            //static void fill(Array<boolean> *array, int fromIndex, int toIndex, boolean value) {}

            FILL(byte);
            FILL(char);
            FILL(double);
            FILL(float);
            FILL(int);
            FILL(long);
            FILL(short);

            FILL_BY_INDEX(byte);
            FILL_BY_INDEX(char);
            FILL_BY_INDEX(double);
            FILL_BY_INDEX(float);
            FILL_BY_INDEX(int);
            FILL_BY_INDEX(long);
            FILL_BY_INDEX(short);

            HASH_CODE(byte);
            HASH_CODE(char);
            HASH_CODE(float);
            HASH_CODE(int);
            HASH_CODE(short);

            static int hashCode(Array<boolean> array) {
                if (array.length == 0) {
                    return 0;
                }

                int result = 1;
                for (boolean element : array) {
                    result = 31 * result + (element ? 1231 : 1237);
                }

                return result;
            }

            static int hashCode(Array<double> array) {
                if (array.length == 0) {
                    return 0;
                }

                int result = 1;
                for (double element : array) {
                    long bits = long(element);
                    result = 31 * result + (int) (bits ^ (bits >> 32));
                }
                return result;
            }

            static int hashCode(Array<long> array) {
                if (array.length == 0) {
                    return 0;
                }

                int result = 1;
                for (long element : array) {
                    int elementHash = (int) (element ^ (element >> 32));
                    result = 31 * result + elementHash;
                }

                return result;
            }

            static int hashCode(Array<Object> array) {
                if (array.length == 0) {
                    return 0;
                }

                int result = 1;
                for (Object element : array) {
                    result = 31 * result + element.hashCode();
                }

                return result;
            }

            SORT(byte);
            SORT(char);
            SORT(double);
            SORT(float);
            SORT(int);

            SORT_BY_INDEX(byte);
            SORT_BY_INDEX(char);
            SORT_BY_INDEX(double);
            SORT_BY_INDEX(float);
            SORT_BY_INDEX(long);

            SORT_BY_ARRAY_SIZE(long);
            SORT_BY_ARRAY_SIZE(short);

            SORT_BY_INDEX_ARRAY_SIZE(int);
            SORT_BY_INDEX_ARRAY_SIZE(short);

            template<typename Type>
            static void sort(Type array[], int arraySize) {
                return sortOrigin(array, 0, arraySize - 1);
            }

            template<typename Type>
            static void sort(Type array[], 
                             int fromIndex, 
                             int toIndex) {
                return sortOrigin(array, fromIndex, toIndex);
            }

            template<typename Type>
            static void sort(Array<Type> *array, int arraySize) {
                return sortOrigin(array, 0, arraySize - 1);
            }

            template<typename Type>
            static void sort(Array<Type> *array, 
                             int fromIndex, 
                             int toIndex) {
                return sortOrigin(array, fromIndex, toIndex);
            }

        private:
            template<typename Type>
            static int BinarySearch(Type array[],
                                    int fromIndex,
                                    int toIndex,
                                    Type key) {
                if (fromIndex < 0
                    || toIndex < 0
                    || toIndex < fromIndex) {
                    return -1;
                }

                int left = fromIndex;
                int right = toIndex;

                while (left < right) {
                    int mid = (left + right) / 2;

                    if (array[mid] >= key) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }

                    if (left == right - 1) { /// Get very first left postition in array
                        if (array[left] == key) {
                            return left;
                        }
                        if (array[right] == key) {
                            return right;
                        }

                        break;
                    }
                }

                return -1;
            }

            // Support Array<E>
            template<typename Type>
            static int BinarySearch(Array<Type> array,
                                    int fromIndex,
                                    int toIndex,
                                    Type key) {
                if (fromIndex < 0
                    || toIndex < 0
                    || toIndex < fromIndex) {
                    return -1;
                }

                int left = fromIndex;
                int right = toIndex;

                while (left < right) {
                    int mid = (left + right) / 2;

                    if (array[mid] >= key) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }

                    if (left == right - 1) { /// Get very first left postition in array
                        if (array[left] == key) {
                            return left;
                        }
                        if (array[right] == key) {
                            return right;
                        }

                        break;
                    }
                }

                return -1;
            }

            /// Quick sort
            template<typename Type>
            static void sortOrigin(Type array[],
                                   int fromIndex,
                                   int toIndex) {
                std::stack<int> positionKeeper;

                positionKeeper.push(fromIndex);
                positionKeeper.push(toIndex);

                while (!positionKeeper.empty()) {
                    int right = positionKeeper.top();
                    positionKeeper.pop();
                    int left = positionKeeper.top();
                    positionKeeper.pop();

                    while (left < right) {
                        int i = left;
                        int j = right;
                        Type key = array[(i + j) / 2];

                        while (i <= j) {
                            while (array[i] < key && i <= j)
                                i++;
                            while (array[j] > key && j >= i)
                                j--;

                            if (i <= j) {
                                Type temp = array[i];
                                array[i] = array[j];
                                array[j] = temp;

                                i++;
                                j--;
                            }
                        }
                        if (i < right) {
                            positionKeeper.push(i);
                            positionKeeper.push(right);
                        }
                        right = j;
                    }
                }
            }

            /// Support Array<Type>
            template<typename Type>
            static void sortOrigin(Array<Type> *array,
                                   int fromIndex,
                                   int toIndex) {
                std::stack<int> positionKeeper;

                positionKeeper.push(fromIndex);
                positionKeeper.push(toIndex);

                while (!positionKeeper.empty()) {
                    int right = positionKeeper.top();
                    positionKeeper.pop();
                    int left = positionKeeper.top();
                    positionKeeper.pop();

                    while (left < right) {
                        int i = left;
                        int j = right;
                        Type key = array->get((i + j) / 2);

                        while (i <= j) {
                            while (array->get(i) < key && i <= j)
                                i++;
                            while (array->get(j) > key && j >= i)
                                j--;

                            if (i <= j) {
                                Type temp = array->get(i);
                                array->operator[](i) = array->get(j);
                                array->operator[](j) = temp;

                                i++;
                                j--;
                            }
                        }
                        if (i < right) {
                            positionKeeper.push(i);
                            positionKeeper.push(right);
                        }
                        right = j;
                    }
                }
            }

            template<typename Type, typename AnotherType>
            static Array<Type> copyOfOrigin(Array<Type> original,
                                            int newLength,
                                            AnotherType padding) {
                Array<Type> result;

                int copyLength = Math::min(original.length, newLength);

                for (int index = 0; index < copyLength; ++index) {
                    result.push(original.get(index));
                }

                for (int index = copyLength; index < newLength; ++index) {
                    result.push(padding);
                }

                return result;
            }

            template<typename Type>
            static Array<Type> copyOfRangeOrigin(Array<Type> original,
                                                 int fromIndex,
                                                 int toIndex) {
                Array<Type> result;

                if (fromIndex < 0
                    || toIndex < 0
                    || toIndex < fromIndex
                    || toIndex > original.length - 1) {
                    return result;
                }

                for (int index = fromIndex; index < toIndex; ++index) {
                    result.push(original.get(index));
                }

                return result;
            }

            template<typename Type>
            static boolean equalsOrigin(Array<Type> original,
                                        Array<Type> target) {
                if (original.length != target.length) {
                    return false;
                }

                for (int index = 0; index < original.length; ++index) {
                    if (original.get(index) != target.get(index)) {
                        return false;
                    }
                }

                return true;
            }

            template<typename Type>
            static void fileOrigin(Array<Type> *array,
                              int fromIndex,
                              int toIndex,
                              Type value) {
                if (fromIndex < 0
                    || toIndex < 0
                    || toIndex < fromIndex
                    || toIndex > (*array).length - 1) {
                    return;
                }
                for (int index = fromIndex; index <= toIndex; ++index) {
                    (*array)[index] = value;
                }
                return;
            }
        };
    }
}

#endif //JAVA_UTIL_ARRAYS_ARRAYS_HPP