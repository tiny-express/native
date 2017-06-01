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

#include "../../Lang.hpp"

using namespace Java::Lang;

namespace Java {
    namespace Util {
        class Arrays: public Object {
        private:
            Arrays();
            ~Arrays();
        public:
            //static <T>List asList(T...a)

            static int binarySearch(byte a[], byte key) {
                return -1;
            }

            static int binarySearch(byte a[], int fromIndex, int toIndex, byte key) {
                return -1;
            }

            static int binarySearch(char a[], char key);
            static int binarySearch(char a[], int fromIndex, int toIndex, char key);
            static int binarySearch(double a[], double key);
            static int binarySearch(double a[], int fromIndex, int toIndex, double key);
            static int binarySearch(float a[], float key);
            static int binarySearch(float a[], int fromIndex, int toIndex, float key);
            static int binarySearch(int a[], int key);
            static int binarySearch(int a[], int fromIndex, int toIndex, int key);
            static int binarySearch(long a[], long key);
            static int binarySearch(long a[], int fromIndex, int toIndex, long key);
            static int binarySearch(short a[], short key);
            static int binarySearch(short a[], int fromIndex, int toIndex, short key);
            static int binarySearch(Object a[], Object key);
            static int binarySearch(Object a[], int fromIndex, int toIndex, Object key);

//            template <typename T>
//            static int binarySearch(T a[], Object key);
//            template <typename T>
//            static int binarySearch(T a[], int fromIndex, int toIndex, T key, Comparator<? super T> c);

            static void sort(byte a[]);
            static void sort(byte a[], int fromIndex, int toIndex);
            static void sort(char a[]);
            static void sort(char a[], int fromIndex, int toIndex);
            static void sort(double a[]);
            static void sort(double a[], int fromIndex, int toIndex);
            static void sort(float a[]);
            static void sort(float a[], int fromIndex, int toIndex);
            static void sort(int a[]);
            static void sort(int a[], int fromIndex, int toIndex);
            static void sort(long a[]);
            static void sort(long a[], int fromIndex, int toIndex);
            static void sort(short a[]);
            static void sort(short a[], int fromIndex, int toIndex);
            static void sort(Object a[]);
            static void sort(Object a[], int fromIndex, int toIndex);

//            template <typename T>
//            static void sort(T a[], T key, Comparator<? super T> c);
//            template <typename T>
//            static void sort(Object a[], int fromIndex, int toIndex, T key, Comparator<? super T> c);


        };
    }
}

#endif //NATIVE_JAVA_UTIL_ARRAYS_HPP