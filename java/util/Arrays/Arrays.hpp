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

#ifndef JAVA_UTIL_ARRAYS_HPP_
#define JAVA_UTIL_ARRAYS_HPP_

#include <stack>
#include "../../Lang.hpp"
#include "../List/List.hpp"
#include "../ArrayList/ArrayList.hpp"

using namespace Java::Lang;

namespace Java {
		namespace Util {
				class Arrays : public Object {
				private:
						Arrays();
						~Arrays();
				public:
						template <typename U, typename... T>
						static List<U> asList(T... a) {
							//FIXME: Please implement ArrayList<T>(a);
						}
						
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
							return binarySearch0(a, 0, arraySize - 1, key);
						}
						
						template <typename T>
						static int binarySearch(T a[], int fromIndex, int toIndex, T key) {
							return binarySearch0(a, 0, toIndex, key);
						}
						
						template <typename T>
						static int binarySearch(Array<T> a, T key, int arraySize) {
							return binarySearch0(a, 0, arraySize - 1, key);
						}
						
						template <typename T>
						static int binarySearch(Array<T> a, int fromIndex, int toIndex, T key) {
							return binarySearch0(a, 0, toIndex, key);
						}
						
						static Array<boolean> copyOf(Array<boolean> original, int newLength) {
							return copyOf0(original, newLength, false);
						}
						
						static Array<char> copyOf(Array<char> original, int newLength) {
							return copyOf0(original, newLength, NULL);
						}
						
						static Array<short> copyOf(Array<short> original, int newLength) {
							return copyOf0(original, newLength, 0);
						}
						
						static Array<int> copyOf(Array<int> original, int newLength) {
							return copyOf0(original, newLength, 0);
						}
						
						static Array<long> copyOf(Array<long> original, int newLength) {
							return copyOf0(original, newLength, 0);
						}
						
						static Array<float> copyOf(Array<float> original, int newLength) {
							return copyOf0(original, newLength, 0.0);
						}
						
						static Array<double> copyOf(Array<double> original, int newLength) {
							return copyOf0(original, newLength, 0.0);
						}
						
						template <typename T>
						static Array<T> copyOf(Array<T> original, int newLength) {
							return copyOf0(original, newLength, NULL);
						}
						
						template <typename T, typename U>
						static Array<T> copyOf(Array<U> u, int newLength, T newType) {
							Array<T> result;
							for (U element: u) {
								T newElement = (T) u; ///T must have a constructor of U
								result.push(newElement);
							}
							
							return result;
						}
						
						static Array<boolean> copyOfRange(Array<boolean> original, int from, int to) {
							return copyOfRange0(original, from, to);
						}
						
						static Array<byte> copyOfRange(Array<byte> original, int from, int to) {
							return copyOfRange0(original, from, to);
						}
						
						static Array<char> copyOfRange(Array<char> original, int from, int to) {
							return copyOfRange0(original, from, to);
						}
						
						static Array<short> copyOfRange(Array<short> original, int from, int to) {
							return copyOfRange0(original, from, to);
						}
						
						static Array<int> copyOfRange(Array<int> original, int from, int to) {
							return copyOfRange0(original, from, to);
						}
						
						static Array<long> copyOfRange(Array<long> original, int from, int to) {
							return copyOfRange0(original, from, to);
						}
						
						static Array<float> copyOfRange(Array<float> original, int from, int to) {
							return copyOfRange0(original, from, to);
						}
						
						static Array<double> copyOfRange(Array<double> original, int from, int to) {
							return copyOfRange0(original, from, to);
						}
						
						template <typename T>
						static Array<T> copyOfRange(Array<T> original, int from, int to) {
							return copyOfRange0(original, from, to);
						}
						
						template <typename T, typename U>
						static Array<T> copyOfRange(Array<U> original, int from, int to, T newType) {
							Array<T> result;
							
							if (from < 0 || to <= 0 || to <= from || to > original.length) {
								return result;
							}
							
							for (int index = from; index < to; ++index) {
								T element = (T) original[ index ]; ///T must have a constructor of U
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
						
						static boolean equals(Array<boolean> a, Array<boolean> a2) {
							return equals0(a, a2);
						}
						
						static boolean equals(Array<byte> a, Array<byte> a2) {
							return equals0(a, a2);
						}
						
						static boolean equals(Array<char> a, Array<char> a2) {
							return equals0(a, a2);
						}
						
						static boolean equals(Array<double> a, Array<double> a2) {
							return equals0(a, a2);
						}
						
						static boolean equals(Array<float> a, Array<float> a2) {
							return equals0(a, a2);
						}
						
						static boolean equals(Array<int> a, Array<int> a2) {
							return equals0(a, a2);
						}
						
						static boolean equals(Array<long> a, Array<long> a2) {
							return equals0(a, a2);
						}
						
						static boolean equals(Array<short> a, Array<short> a2) {
							return equals0(a, a2);
						}
						
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
						
						static void fill(Array<byte> *a, byte val) {
							return fill0(a, 0, ( *a ).length - 1, val);
						}
						
						static void fill(Array<byte> *a, int fromIndex, int toIndex, byte val) {
							return fill0(a, fromIndex, toIndex, val);
						}
						
						static void fill(Array<char> *a, char val) {
							return fill0(a, 0, ( *a ).length - 1, val);
						}
						
						static void fill(Array<char> *a, int fromIndex, int toIndex, char val) {
							return fill0(a, fromIndex, toIndex, val);
						}
						
						static void fill(Array<double> *a, double val) {
							return fill0(a, 0, ( *a ).length - 1, val);
						}
						
						static void fill(Array<double> *a, int fromIndex, int toIndex, double val) {
							return fill0(a, fromIndex, toIndex, val);
						}
						
						static void fill(Array<float> *a, float val) {
							return fill0(a, 0, ( *a ).length - 1, val);
						}
						
						static void fill(Array<float> *a, int fromIndex, int toIndex, float val) {
							return fill0(a, fromIndex, toIndex, val);
						}
						
						static void fill(Array<int> *a, int val) {
							return fill0(a, 0, ( *a ).length - 1, val);
						}
						
						static void fill(Array<int> *a, int fromIndex, int toIndex, int val) {
							return fill0(a, fromIndex, toIndex, val);
						}
						
						static void fill(Array<long> *a, long val) {
							return fill0(a, 0, ( *a ).length - 1, val);
						}
						
						static void fill(Array<long> *a, int fromIndex, int toIndex, long val) {
							return fill0(a, fromIndex, toIndex, val);
						}
						
						static void fill(Array<short> *a, short val) {
							return fill0(a, 0, ( *a ).length - 1, val);
						}
						
						static void fill(Array<short> *a, int fromIndex, int toIndex, short val) {
							return fill0(a, fromIndex, toIndex, val);
						}
						
						static int hashCode(Array<boolean> a) {
							if (a.length == 0) {
								return 0;
							}
							
							int result = 1;
							for (boolean element : a) {
								result = 31 * result + ( element ? 1231 : 1237 );
							}
							
							return result;
						}
						
						static int hashCode(Array<byte> a) {
							if (a.length == 0) {
								return 0;
							}
							
							int result = 1;
							for (byte element : a) {
								result = 31 * result + element;
							}
							
							return result;
						}
						
						static int hashCode(Array<char> a) {
							if (a.length == 0) {
								return 0;
							}
							
							int result = 1;
							for (char element : a) {
								result = 31 * result + element;
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
								result = 31 * result + (int) ( bits ^ ( bits >> 32 ));
							}
							return result;
						}
						
						static int hashCode(Array<float> a) {
							if (a.length == 0) {
								return 0;
							}
							
							int result = 1;
							for (float element : a) {
								result = 31 * result + int(element);
							}
							
							return result;
						}
						
						static int hashCode(Array<int> a) {
							if (a.length == 0) {
								return 0;
							}
							
							int result = 1;
							for (int element : a) {
								result = 31 * result + element;
							}
							
							return result;
						}
						
						static int hashCode(Array<long> a) {
							if (a.length == 0) {
								return 0;
							}
							
							int result = 1;
							for (long element : a) {
								int elementHash = (int) ( element ^ ( element >> 32 ));
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
						
						static int hashCode(Array<short> a) {
							if (a.length == 0) {
								return 0;
							}
							
							int result = 1;
							for (short element : a) {
								result = 31 * result + element;
							}
							
							return result;
						}
						
						static void sort(byte a[], int arraySize) {
							return sort0(a, 0, arraySize - 1);
						}
						
						static void sort(byte a[], int fromIndex, int toIndex) {
							return sort0(a, fromIndex, toIndex);
						}
						
						static void sort(char a[], int arraySize) {
							return sort0(a, 0, arraySize - 1);
						}
						
						static void sort(char a[], int fromIndex, int toIndex) {
							return sort0(a, fromIndex, toIndex);
						}
						
						static void sort(double a[], int arraySize) {
							return sort0(a, 0, arraySize - 1);
						}
						
						static void sort(double a[], int fromIndex, int toIndex) {
							return sort0(a, fromIndex, toIndex);
						}
						
						static void sort(float a[], int arraySize) {
							return sort0(a, 0, arraySize - 1);
						}
						
						static void sort(float a[], int fromIndex, int toIndex) {
							return sort0(a, fromIndex, toIndex);
						}
						
						static void sort(int a[], int arraySize) {
							return sort0(a, 0, arraySize - 1);
						}
						
						static void sort(int a[], int fromIndex, int toIndex, int arraySize) {
							return sort0(a, fromIndex, toIndex);
						}
						
						static void sort(long a[], int arraySize) {
							return sort0(a, 0, arraySize - 1);
						}
						
						static void sort(long a[], int fromIndex, int toIndex) {
							return sort0(a, fromIndex, toIndex);
						}
						
						static void sort(short a[], int arraySize) {
							return sort0(a, 0, arraySize - 1);
						}
						
						static void sort(short a[], int fromIndex, int toIndex, int arraySize) {
							return sort0(a, fromIndex, toIndex);
						}
						
						template <typename T>
						static void sort(T a[], int arraySize) {
							return sort0(a, 0, arraySize - 1);
						}
						
						template <typename T>
						static void sort(T a[], int fromIndex, int toIndex) {
							return sort0(a, fromIndex, toIndex);
						}
						
						template <typename T>
						static void sort(Array<T> *a, int arraySize) {
							return sort0(a, 0, arraySize - 1);
						}
						
						template <typename T>
						static void sort(Array<T> *a, int fromIndex, int toIndex) {
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
								int mid = ( left + right ) / 2;
								
								if (a[ mid ] >= key) {
									right = mid;
								} else {
									left = mid + 1;
								}
								
								if (left == right - 1) { /// Get very first left postition in array
									if (a[ left ] == key) {
										return left;
									}
									if (a[ right ] == key) {
										return right;
									}
									
									break;
								}
							}
							
							return -1;
						}
						
						/// Support Array<E>
						template <typename T>
						static int binarySearch0(Array<T> a, int fromIndex, int toIndex, T key) {
							if (fromIndex < 0 || toIndex < 0 || toIndex < fromIndex) {
								return -1;
							}
							
							int left = fromIndex;
							int right = toIndex;
							
							while (left < right) {
								int mid = ( left + right ) / 2;
								
								if (a[ mid ] >= key) {
									right = mid;
								} else {
									left = mid + 1;
								}
								
								if (left == right - 1) { /// Get very first left postition in array
									if (a[ left ] == key) {
										return left;
									}
									if (a[ right ] == key) {
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
									int i = left;
									int j = right;
									T key = a[ ( i + j ) / 2 ];
									
									while (i <= j) {
										while (a[ i ] < key && i <= j)
											i++;
										while (a[ j ] > key && j >= i)
											j--;
										
										if (i <= j) {
											T temp = a[ i ];
											a[ i ] = a[ j ];
											a[ j ] = temp;
											
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
						template <typename T>
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
									T key = a->get(( i + j ) / 2);
									
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
						
						template <typename T, typename U>
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
						
						template <typename T>
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
						
						template <typename T>
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
						
						template <typename T>
						static void fill0(Array<T> *a, int fromIndex, int toIndex, T val) {
							if (fromIndex < 0 || toIndex < 0 || toIndex < fromIndex || toIndex > ( *a ).length - 1) {
								return;
							}
							for (int index = fromIndex; index <= toIndex; ++index) {
								( *a )[ index ] = val;
							}
							return;
						}
				};
		}
}

#endif //JAVA_UTIL_ARRAYS_HPP_