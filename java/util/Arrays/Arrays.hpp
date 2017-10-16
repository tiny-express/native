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
static int binarySearch(TYPE a[], int fromIndex, int toIndex, TYPE key) {\
    return binarySearch0(a, fromIndex, toIndex, key);\
}

#define BINARY_SEARCH_BY_KEY(TYPE); \
static int binarySearch(TYPE a[], TYPE key, int arraySize) {\
    return binarySearch0(a, 0, arraySize - 1, key);\
}

#define COPY_OF(TYPE); \
static Array<TYPE> copyOf(Array<TYPE> original, int newLength) {\
    return copyOf0(original, newLength, NULL);\
}

#define COPY_OF_RANGE(TYPE); \
static Array<TYPE> copyOfRange(Array<TYPE> original, int from, int to) {\
    return copyOfRange0(original, from, to);\
}

#define EQUALS(TYPE); \
static boolean equals(Array<TYPE> a, Array<TYPE> a2) {\
    return equals0(a, a2);\
}

#define FILL(TYPE); \
static void fill(Array<TYPE> *a, TYPE val) {\
    return fill0(a, 0, (*a).length - 1, val);\
}

#define FILL_BY_INDEX(TYPE); \
static void fill(Array<TYPE> *a, int fromIndex, int toIndex, TYPE val) {\
    return fill0(a, fromIndex, toIndex, val);\
}

#define HASH_CODE(TYPE); \
static int hashCode(Array<TYPE> a) {\
    if (a.length == 0) {\
        return 0;\
    }\
\
    int result = 1;\
    for (TYPE element : a) {\
        result = 31 * result + element;\
    }\
\
    return result;\
}

#define SORT(TYPE); \
static void sort(TYPE a[], int arraySize) {\
    return sort0(a, 0, arraySize - 1);\
}

#define SORT_BY_INDEX(TYPE); \
static void sort(TYPE a[], int fromIndex, int toIndex) {\
    return sort0(a, fromIndex, toIndex);\
}

#define SORT_BY_ARRAY_SIZE(TYPE); \
static void sort(TYPE a[], int arraySize) {\
    return sort0(a, 0, arraySize - 1);\
}

#define SORT_BY_INDEX_ARRAY_SIZE(TYPE); \
static void sort(TYPE a[], int fromIndex, int toIndex, TYPE arraySize) {\
    return sort0(a, fromIndex, toIndex);\
}

using namespace Java::Lang;

namespace Java {
    namespace Util {
        class Arrays : public Object {
        private:
            Arrays();

            ~Arrays();

        public:
            template<typename U, typename... T>
            static List<U> asList(T... a) {
                //FIXME: Please implement ArrayList<T>(a);
            }

            BINARY_SEARCH_BY_INDEX(char);
            BINARY_SEARCH_BY_INDEX(byte);
            BINARY_SEARCH_BY_INDEX(short);
            BINARY_SEARCH_BY_INDEX(int);
            BINARY_SEARCH_BY_INDEX(long);
            BINARY_SEARCH_BY_INDEX(float);
            BINARY_SEARCH_BY_INDEX(double);

            static int binarySearch(Object a[], int fromIndex, int toIndex, Object key) {
                return -1;
            }

            BINARY_SEARCH_BY_KEY(char);
            BINARY_SEARCH_BY_KEY(byte);
            BINARY_SEARCH_BY_KEY(short);
            BINARY_SEARCH_BY_KEY(int);
            BINARY_SEARCH_BY_KEY(long);
            BINARY_SEARCH_BY_KEY(float);
            BINARY_SEARCH_BY_KEY(double);

            static int binarySearch1(Object a[], Object key, int arraySize) {
                return -1;
            }

            template<typename T>
            static int binarySearch(T a[], T key, int arraySize) {
                return binarySearch0(a, 0, arraySize - 1, key);
            }

            template<typename T>
            static int binarySearch(T a[], int fromIndex, int toIndex, T key) {
                return binarySearch0(a, 0, toIndex, key);
            }

            template<typename T>
            static int binarySearch(Array<T> a, T key, int arraySize) {
                return binarySearch0(a, 0, arraySize - 1, key);
            }

            template<typename T>
            static int binarySearch(Array<T> a, int fromIndex, int toIndex, T key) {
                return binarySearch0(a, 0, toIndex, key);
            }

            COPY_OF(boolean);
            COPY_OF(char);
            COPY_OF(short);
            COPY_OF(int);
            COPY_OF(long);
            COPY_OF(float);
            COPY_OF(double);

            template<typename T>
            static Array<T> copyOf(Array<T> original, int newLength) {
                return copyOf0(original, newLength, NULL);
            }

            template<typename T, typename U>
            static Array<T> copyOf(Array<U> u, int newLength, T newType) {
                Array<T> result;
                for (U element: u) {
                    T newElement = (T) u; ///T must have a constructor of U
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

            template<typename T>
            static Array<T> copyOfRange(Array<T> original, int from, int to) {
                return copyOfRange0(original, from, to);
            }

            template<typename T, typename U>
            static Array<T> copyOfRange(Array<U> original, int from, int to, T newType) {
                Array<T> result;

                if (from < 0 || to <= 0 || to <= from || to > original.length) {
                    return result;
                }

                for (int index = from; index < to; ++index) {
                    T element = (T) original[index]; ///T must have a constructor of U
                    result.push(element);
                }

                return result;
            }

            static boolean deepEquals(Object a1[], Object a2[]) {
                return false; /// Don't support this method
            }

            static int deepHashCode(Object a[]) {
                return -1; /// Don't support this method
            }

            static String deepToString(Object a[]) {
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
            //static void fill(Array<boolean> *a, boolean val) {}

            /**
             *  Don't support this in C++ runtime, because <bool> will be optimised to bit and can't modify in vector of Array
             *  Use fill(Array<int>, int) instead
             */
            //static void fill(Array<boolean> *a, int fromIndex, int toIndex, boolean val) {}

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

            static int hashCode(Array<boolean> a) {
                if (a.length == 0) {
                    return 0;
                }

                int result = 1;
                for (boolean element : a) {
                    result = 31 * result + (element ? 1231 : 1237);
                }

                return result;
            }

            static int hashCode(Array<double> a) {
                if (a.length == 0) {
                    return 0;
                }

                int result = 1;
                for (double element : a) {
                    long bits = long(element);
                    result = 31 * result + (int) (bits ^ (bits >> 32));
                }
                return result;
            }

            static int hashCode(Array<long> a) {
                if (a.length == 0) {
                    return 0;
                }

                int result = 1;
                for (long element : a) {
                    int elementHash = (int) (element ^ (element >> 32));
                    result = 31 * result + elementHash;
                }

                return result;
            }

            static int hashCode(Array<Object> a) {
                if (a.length == 0) {
                    return 0;
                }

                int result = 1;
                for (Object element : a) {
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

            template<typename T>
            static void sort(T a[], int arraySize) {
                return sort0(a, 0, arraySize - 1);
            }

            template<typename T>
            static void sort(T a[], int fromIndex, int toIndex) {
                return sort0(a, fromIndex, toIndex);
            }

            template<typename T>
            static void sort(Array<T> *a, int arraySize) {
                return sort0(a, 0, arraySize - 1);
            }

            template<typename T>
            static void sort(Array<T> *a, int fromIndex, int toIndex) {
                return sort0(a, fromIndex, toIndex);
            }

        private:
            template<typename T>
            static int binarySearch0(T a[], int fromIndex, int toIndex, T key) {
                if (fromIndex < 0 || toIndex < 0 || toIndex < fromIndex) {
                    return -1;
                }

                int left = fromIndex;
                int right = toIndex;

                while (left < right) {
                    int mid = (left + right) / 2;

                    if (a[mid] >= key) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }

                    if (left == right - 1) { /// Get very first left postition in array
                        if (a[left] == key) {
                            return left;
                        }
                        if (a[right] == key) {
                            return right;
                        }

                        break;
                    }
                }

                return -1;
            }

            /// Support Array<E>
            template<typename T>
            static int binarySearch0(Array<T> a, int fromIndex, int toIndex, T key) {
                if (fromIndex < 0 || toIndex < 0 || toIndex < fromIndex) {
                    return -1;
                }

                int left = fromIndex;
                int right = toIndex;

                while (left < right) {
                    int mid = (left + right) / 2;

                    if (a[mid] >= key) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }

                    if (left == right - 1) { /// Get very first left postition in array
                        if (a[left] == key) {
                            return left;
                        }
                        if (a[right] == key) {
                            return right;
                        }

                        break;
                    }
                }

                return -1;
            }

            /// Quick sort
            template<typename T>
            static void sort0(T a[], int fromIndex, int toIndex) {
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
                        T key = a[(i + j) / 2];

                        while (i <= j) {
                            while (a[i] < key && i <= j)
                                i++;
                            while (a[j] > key && j >= i)
                                j--;

                            if (i <= j) {
                                T temp = a[i];
                                a[i] = a[j];
                                a[j] = temp;

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

            /// Support Array<T>
            template<typename T>
            static void sort0(Array<T> *a, int fromIndex, int toIndex) {
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
                        T key = a->get((i + j) / 2);

                        while (i <= j) {
                            while (a->get(i) < key && i <= j)
                                i++;
                            while (a->get(j) > key && j >= i)
                                j--;

                            if (i <= j) {
                                T temp = a->get(i);
                                a->operator[](i) = a->get(j);
                                a->operator[](j) = temp;

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

            template<typename T, typename U>
            static Array<T> copyOf0(Array<T> original, int newLength, U padding) {
                Array<T> result;

                int copyLength = Math::min(original.length, newLength);

                for (int index = 0; index < copyLength; ++index) {
                    result.push(original.get(index));
                }

                for (int index = copyLength; index < newLength; ++index) {
                    result.push(padding);
                }

                return result;
            }

            template<typename T>
            static Array<T> copyOfRange0(Array<T> original, int fromIndex, int toIndex) {
                Array<T> result;

                if (fromIndex < 0 || toIndex < 0 || toIndex < fromIndex || toIndex > original.length - 1) {
                    return result;
                }

                for (int index = fromIndex; index < toIndex; ++index) {
                    result.push(original.get(index));
                }

                return result;
            }

            template<typename T>
            static boolean equals0(Array<T> original, Array<T> target) {
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

            template<typename T>
            static void fill0(Array<T> *a, int fromIndex, int toIndex, T val) {
                if (fromIndex < 0 || toIndex < 0 || toIndex < fromIndex || toIndex > (*a).length - 1) {
                    return;
                }
                for (int index = fromIndex; index <= toIndex; ++index) {
                    (*a)[index] = val;
                }
                return;
            }
        };
    }
}

#endif //JAVA_UTIL_ARRAYS_ARRAYS_HPP