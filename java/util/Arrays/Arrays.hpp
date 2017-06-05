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

#ifndef NATIVE_JAVA_UTIL_ARRAYS_HPP
#define NATIVE_JAVA_UTIL_ARRAYS_HPP

#include <stack>
#include "../../Lang.hpp"
#include "../List/List.hpp"

using namespace Java::Lang;

namespace Java {
    namespace Util {
        class Arrays: public Object {
        private:
            Arrays();
            ~Arrays();
        public:
//            template<typename T, typename... T>
//            static List<T> asList(T... a) {
//                //TODO
//            }

            static int binarySearch(byte a[], byte key, int arraySize) {
                return binarySearch0(a, 0, arraySize - 1, key);
            }

            static int binarySearch(byte a[], int fromIndex, int toIndex, byte key) {
                return binarySearch0(a, fromIndex, toIndex, key);
            }

            static int binarySearch(char a[], char key, int arraySize) {
                return binarySearch0(a, 0, arraySize - 1, key);
            }

            static int binarySearch(char a[], int fromIndex, int toIndex, char key) {
                return binarySearch0(a, fromIndex, toIndex, key);
            }

            static int binarySearch(double a[], double key, int arraySize) {
                return binarySearch0(a, 0, arraySize - 1, key);
            }

            static int binarySearch(double a[], int fromIndex, int toIndex, double key) {
                return binarySearch0(a, fromIndex, toIndex, key);
            }

            static int binarySearch(float a[], float key, int arraySize) {
                return binarySearch0(a, 0, arraySize - 1, key);
            }

            static int binarySearch(float a[], int fromIndex, int toIndex, float key) {
                return binarySearch0(a, fromIndex, toIndex, key);
            }

            static int binarySearch(int a[], int key, int arraySize) {
                return binarySearch0(a, 0, arraySize - 1, key);
            }

            static int binarySearch(int a[], int fromIndex, int toIndex, int key) {
                return binarySearch0(a, fromIndex, toIndex, key);
            }

            static int binarySearch(long a[], long key, int arraySize) {
                return binarySearch0(a, 0, arraySize - 1, key);
            }

            static int binarySearch(long a[], int fromIndex, int toIndex, long key) {
                return binarySearch0(a, fromIndex, toIndex, key);
            }

            static int binarySearch(short a[], short key, int arraySize) {
                return binarySearch0(a, 0, arraySize - 1, key);
            }

            static int binarySearch(short a[], int fromIndex, int toIndex, short key) {
                return binarySearch0(a, fromIndex, toIndex, key);
            }

            static int binarySearch1(Object a[], Object key, int arraySize) {
                return -1;
            }
            static int binarySearch(Object a[], int fromIndex, int toIndex, Object key) {
                return -1;
            }

            template <typename T>
            static int binarySearch(T a[], T key, int arraySize) {
                return binarySearch0(a, 0, arraySize-1, key);
            }

            template <typename T>
            static int binarySearch(T a[], int fromIndex, int toIndex, T key) {
                return binarySearch0(a, 0, toIndex, key);
            }

            static Array<boolean> copyOf(Array<boolean> original) {
                return copyOf0(original);
            }

            static Array<byte> copyOf(byte original[], int arrayLength, int newLength) {
                return Array<byte>();
            }

            static char* copyOf(char original[], int arrayLength, int newLength) {
            }

            static double* copyOf(double original[], int arrayLength, int newLength) {
                //TODO
                return NULL;
            }

            static float* copyOf(float original[], int arrayLength, int newLength) {
                //TODO
                return NULL;
            }

            static int* copyOf(int original[], int arrayLength, int newLength) {
                //TODO
                return NULL;
            }

            static long* copyOf(long original[], int arrayLength, int newLength) {
                //TODO
                return NULL;
            }

            static short* copyOf(short original[], int arrayLength, int newLength) {
                //TODO
                return NULL;
            }

            template<typename T>
            static T* copyOf(T original[], int arrayLength, int newLength) {
                //TODO
                return NULL;
            }

            template<typename T, typename U>
            static T* copyOf(U original[], int arrayLength, int newLength, T newType) {
                //TODO
                return NULL;
            }

            static boolean* copyOfRange(boolean original[], int from, int to) {
                //TODO
                return NULL;
            }

            static byte* copyOfRange(byte original[], int from, int to) {
                //TODO
                return NULL;
            }

            static char* copyOfRange(char original[], int from, int to) {
                //TODO
                return NULL;
            }

            static double* copyOfRange(double original[], int from, int to) {
                //TODO
                return NULL;
            }

            static float* copyOfRange(float original[], int from, int to) {
                //TODO
                return NULL;
            }

            static int* copyOfRange(int original[], int from, int to) {
                //TODO
                return NULL;
            }

            static long* copyOfRange(long original[], int from, int to) {
                //TODO
                return NULL;
            }

            static short* copyOfRange(short original[], int from, int to) {
                //TODO
                return NULL;
            }

            template<typename T>
            static T* copyOfRange(T original[], int from, int to) {
                //TODO
                return NULL;
            }

            template<typename T, typename U>
            static T* copyOfRange(U original[], int from, int to, T newType) {
                //TODO
                return NULL;
            }

            static boolean deepEquals(Object a1[], Object a2[]) {
                //TODO
                return false;
            }

            static int deepHashCode(Object a[]) {
                //TODO
                return -1;
            }

            static String deepToString(Object a[]) {
                //TODO
                return "";
            }

            static boolean equals(boolean a[], boolean a2[], int aSize, int a2Size) {
                return equals0(a, aSize, a2, a2Size);
            }

            static boolean equals(byte a[], byte a2[], int aSize, int a2Size) {
                return equals0(a, aSize, a2, a2Size);
            }

            static boolean equals(char a[], char a2[]) {
                //TODO
                return false;
            }

            static boolean equals(double a[], double a2[]) {
                //TODO
                return false;
            }

            static boolean equals(float a[], float a2[]) {
                //TODO
                return false;
            }

            static boolean equals(int a[], int a2[]) {
                //TODO
                return false;
            }

            static boolean equals(long a[], long a2[]) {
                //TODO
                return false;
            }

            static boolean equals(Object a[], Object a2[]) {
                //TODO
                return false;
            }

            static boolean equals(short a[], short a2[]) {
                //TODO
                return false;
            }

            static void	fill(boolean a[], boolean val) {
                //TODO
            }

            static void	fill(boolean a[], int fromIndex, int toIndex, boolean val) {
                //TODO
            }

            static void	fill(byte a[], byte val) {
                //TODO
            }

            static void	fill(byte a[], int fromIndex, int toIndex, byte val) {
                //TODO
            }

            static void	fill(char a[], char val) {
                //TODO
            }

            static void	fill(char a[], int fromIndex, int toIndex, char val) {
                //TODO
            }

            static void	fill(double a[], double val) {
                //TODO
            }

            static void	fill(double a[], int fromIndex, int toIndex, double val) {
                //TODO
            }

            static void	fill(float a[], float val) {
                //TODO
            }

            static void	fill(float a[], int fromIndex, int toIndex, float val) {
                //TODO
            }

            static void	fill(int a[], int val) {
                //TODO
            }

            static void	fill(int a[], int fromIndex, int toIndex, int val) {
                //TODO
            }

            static void	fill(long a[], long val) {
                //TODO
            }

            static void	fill(long a[], int fromIndex, int toIndex, long val) {
                //TODO
            }

            static void	fill(Object a[], Object val) {
                //TODO
            }

            static void	fill(Object a[], int fromIndex, int toIndex, Object val) {
                //TODO
            }

            static void	fill(short a[], short val) {
                //TODO
            }

            static void	fill(short a[], int fromIndex, int toIndex, short val) {
                //TODO
            }

            static int hashCode(boolean a[]) {
                //TODO
                return -1;
            }

            static int hashCode(byte a[]) {
                //TODO
                return -1;
            }

            static int hashCode(char a[]) {
                //TODO
                return -1;
            }

            static int hashCode(double a[]) {
                //TODO
                return -1;
            }

            static int hashCode(float a[]) {
                //TODO
                return -1;
            }

            static int hashCode(int a[]) {
                //TODO
                return -1;
            }

            static int hashCode(long a[]) {
                //TODO
                return -1;
            }

            static int hashCode(Object a[]) {
                //TODO
                return -1;
            }

            static int hashCode(short a[]) {
                //TODO
                return -1;
            }

            static void sort(byte a[], int arraySize) {
                return sort0(a, 0, arraySize-1);
            }

            static void sort(byte a[], int fromIndex, int toIndex) {
                return sort0(a, fromIndex, toIndex);
            }

            static void sort(char a[], int arraySize) {
                return sort0(a, 0, arraySize-1);
            }

            static void sort(char a[], int fromIndex, int toIndex) {
                return sort0(a, fromIndex, toIndex);
            }

            static void sort(double a[], int arraySize) {
                return sort0(a, 0, arraySize-1);
            }

            static void sort(double a[], int fromIndex, int toIndex) {
                return sort0(a, fromIndex, toIndex);
            }

            static void sort(float a[], int arraySize) {
                return sort0(a, 0, arraySize-1);
            }

            static void sort(float a[], int fromIndex, int toIndex) {
                return sort0(a, fromIndex, toIndex);
            }

            static void sort(int a[], int arraySize) {
                return sort0(a, 0, arraySize-1);
            }

            static void sort(int a[], int fromIndex, int toIndex, int arraySize) {
                return sort0(a, fromIndex, toIndex);
            }

            static void sort(long a[], int arraySize) {
                return sort0(a, 0, arraySize-1);
            }

            static void sort(long a[], int fromIndex, int toIndex) {
                return sort0(a, fromIndex, toIndex);
            }

            static void sort(short a[], int arraySize) {
                return sort0(a, 0, arraySize-1);
            }

            static void sort(short a[], int fromIndex, int toIndex, int arraySize) {
                return sort0(a, fromIndex, toIndex);
            }

            static void sort(Object a[], int arraySize) {
//                return sort0(a, 0, arraySize-1); //FIXME: discuss about > & < of Object's operator
            }

            static void sort(Object a[], int fromIndex, int toIndex) {
//                return sort0(a, fromIndex, toIndex); //FIXME: discuss about > & < of Object's operator
            }

            template <typename T>
            static void sort(T a[], int arraySize) {
                return sort0(a, 0, arraySize-1);
            }

            template <typename T>
            static void sort(T a[], int fromIndex, int toIndex) {
                return sort0(a, fromIndex, toIndex);
            }

        private:
            template <typename T>
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

            /// Quick sort
            template <typename T>
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
                        int i   = left;
                        int j   = right;
                        T   key = a[(i + j) / 2];

                        while (i <= j) {
                            while (a[i] < key && i <= j) i++;
                            while (a[j] > key && j >= i) j--;

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

            template<typename T>
            static Array<T> copyOf0(Array<T> original) {
                Array<T> result;
                for (T t: original) {
                    result.push(t);
                }
                return result;
            }

            template<typename T>
            static boolean equals0(T origin[], int originalSize, T target[], int targetSize) {
                if (originalSize != targetSize) {
                    return false;
                }

                for (int index = 0; index < originalSize; ++index) {
                    if (origin[index] != target[index]) {
                        return false;
                    }
                }
                return true;
            }
        };
    }
}

#endif //NATIVE_JAVA_UTIL_ARRAYS_HPP