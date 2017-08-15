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

extern "C" {
#include "../../../kernel/test.h"
}

#include "Vector.hpp"

using namespace Java::Util;

TEST (JavaUtil, VectorDefaultConstructor) {
	Vector<int> vector;
	ASSERT_EQUAL(10, vector.capacity());
}

TEST (JavaUtil, VectorCustomConstructor) {
	// Checks initial capacity.
	Vector<int> vector1(30);
	ASSERT_EQUAL(30, vector1.capacity());
	
	// Checks initial capacity and capacity increment.
	Vector<int> vector2(3, 2);
	ASSERT_EQUAL(0, vector2.size());
	ASSERT_EQUAL(3, vector2.capacity());
	vector2.add(1);
	ASSERT_EQUAL(1, vector2.size());
	ASSERT_EQUAL(3, vector2.capacity());
	vector2.add(2);
	ASSERT_EQUAL(2, vector2.size());
	ASSERT_EQUAL(3, vector2.capacity());
	vector2.add(3);
	ASSERT_EQUAL(3, vector2.size());
	ASSERT_EQUAL(3, vector2.capacity());
	// new capacity = old capacity + capacity increment.
	vector2.add(4);
	ASSERT_EQUAL(4, vector2.size());
	ASSERT_EQUAL(5, vector2.capacity());
}

TEST (JavaUtil, VectorInitializerListConstructor) {
	// Given a vector construct from a std::initializer_list.
	Vector<int> vector { 1, 2, 3, 4, 5 };
	// Checks size.
	ASSERT_EQUAL(5, vector.size());
	// Check the first-last elements.
	ASSERT_EQUAL(1, vector.firstElement());
	ASSERT_EQUAL(5, vector.lastElement());
}

TEST (JavaUtil, VectorCopyConstructor) {
	// Given a valid vector.
	Vector<int> target;
	target.add(1);
	target.add(2);
	target.add(3);
	target.add(4);
	target.add(5);
	// Use copy-constructor.
	Vector<int> vector(target);
	ASSERT_EQUAL(target.size(), vector.size());
	ASSERT_EQUAL(target.firstElement(), vector.firstElement());
	ASSERT_EQUAL(target.lastElement(), vector.lastElement());
}

TEST (JavaUtil, VectorAdd) {
	// Given a valid vector - check size and check the first - last element.
	Vector<int> vector;
	vector.add(1);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	vector.add(5);
	ASSERT_EQUAL(5, vector.size());
	ASSERT_EQUAL(1, vector.firstElement());
	ASSERT_EQUAL(5, vector.lastElement());
	
	// Add an element at specified index in vector - return that element at that index.
	vector.add(3, 100);
	ASSERT_EQUAL(100, vector.get(3));
	ASSERT_EQUAL(4, vector.get(4));
}

TEST (JavaUtil, VectorAddAll) {
	// Given an empty vector.
	Vector<int> vector1;
	// Add all elements from initializer list.
	ASSERT_TRUE(vector1.addAll({ 1, 2, 3, 4, 5 }));
	// Checks size.
	ASSERT_EQUAL(5, vector1.size());
	// Check the first-last elements.
	ASSERT_EQUAL(1, vector1.firstElement());
	ASSERT_EQUAL(5, vector1.lastElement());
	
	// Given a valid vector.
	Vector<int> vector2;
	vector2.add(1);
	vector2.add(2);
	vector2.add(3);
	vector2.add(4);
	vector2.add(5);
	// Add initializer list at index 2.
	ASSERT_TRUE(vector2.addAll(2, { 7, 8, 9 }));
	// Check the first-last element.
	ASSERT_EQUAL(8, vector2.size());
	ASSERT_EQUAL(1, vector2.firstElement());
	ASSERT_EQUAL(5, vector2.lastElement());
	// Check element at index 2.
	ASSERT_EQUAL(7, vector2.get(2));
}

TEST (JavaUtil, VectorAddElement) {
	Vector<int> vector;
	vector.addElement(1);
	vector.addElement(2);
	vector.addElement(3);
	vector.addElement(4);
	vector.addElement(5);
	ASSERT_EQUAL(1, vector.firstElement());
	ASSERT_EQUAL(5, vector.lastElement());
}

TEST (JavaUtil, VectorClear) {
	// Given empty vector - return size of vector is 0.
	Vector<String> vector;
	ASSERT_EQUAL(0, vector.size());
	
	// Add three elements into vector - return size of vector is 3.
	vector.add("Hello");
	vector.add("World");
	vector.add("Vector");
	ASSERT_EQUAL(3, vector.size());
	
	// Clear all elements of vector - return size of vector is 0.
	vector.clear();
	ASSERT_EQUAL(0, vector.size());
}

TEST (JavaUtil, VectorClone) {
	// Given an empty vector, check size of cloned vector.
	Vector<int> vector;
	Vector<int> clonedVector1 = vector.clone();
	ASSERT_EQUAL(0, clonedVector1.size());
	
	// Given a valid vector, check size of cloned vector; check first-last element.7
	vector.add(1);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	vector.add(5);
	Vector<int> clonedVector2 = vector.clone();
	ASSERT_EQUAL(5, clonedVector2.size());
	ASSERT_EQUAL(1, clonedVector2.firstElement());
	ASSERT_EQUAL(5, clonedVector2.lastElement());
}

TEST (JavaUtil, VectorContains) {
	// Given a valid vector - checks element exists or not.
	Vector<int> vector;
	vector.add(1);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	vector.add(5);
	ASSERT_FALSE(vector.contains(0));
	ASSERT_TRUE(vector.contains(5));
}

TEST (JavaUtil, VectorContainsAll) {
	// Given a valid vector.
	Vector<int> vector { 1, 2, 3, 4, 5 };
	// Checks vector for having all elements in a list.
	ASSERT_FALSE(vector.containsAll({ 1, 2, 3, 4, 6 }));
	ASSERT_TRUE(vector.containsAll({ 1, 2, 3, 4, 5 }));
}

TEST (JavaUtil, VectorCopyInto) {
	Vector<int> vector { 1, 2, 3, 4, 5 };
	Array<int> anArray;
	vector.copyInto(anArray);
	ASSERT_EQUAL(vector.size(), anArray.length);
	register int index;
	for (index = 0; index < vector.size(); index++) {
		ASSERT_EQUAL(vector.get(index), anArray.get(index));
	}
}

TEST (JavaUtil, VectorElementAt) {
	// Given a valid vector.
	Vector<int> vector;
	vector.add(1);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	vector.add(5);
	// Get element at the first and the last position.
	ASSERT_EQUAL(vector.firstElement(), vector.elementAt(0));
	ASSERT_EQUAL(vector.lastElement(), vector.elementAt(4));
}

TEST (JavaUtil, VectorEnsureCapacity) {
	// Given an empty vector with initial capacity is 10 and capacity increment is 5.
	Vector<int> vector1(10, 5);
	ASSERT_EQUAL(10, vector1.capacity());
	// New capacity = old capacity + capacity increment.
	vector1.ensureCapacity(12);
	ASSERT_EQUAL(15, vector1.capacity());
	// New capacity = min capacity (because old capacity + capacity increment < min capacity).
	vector1.ensureCapacity(25);
	ASSERT_EQUAL(25, vector1.capacity());
	
	// Given an empty vector with initial capacity is 10 and capacity increment is 0.
	Vector<int> vector2(10, 0);
	// New capacity = old capacity * 2 (because capacity increment is zero).
	vector2.ensureCapacity(15);
	ASSERT_EQUAL(20, vector2.capacity());
	// New capacity = min capacity (because old capacity * 2 < min capacity).
	vector2.ensureCapacity(100);
	ASSERT_EQUAL(100, vector2.capacity());
}

TEST (JavaUtil, VectorEquals) {
	// Given two valid vectors, check they are equals or not.
	Vector<int> vector1 { 1, 2, 3, 4, 5 };
	Vector<int> target1 { 1, 2, 3, 5, 4 };
	ASSERT_FALSE(vector1.equals(target1));
	// Given two valid vector, check they are equals or not.
	Vector<int> vector2 { 1, 2, 3, 4, 5, 6, 7 };
	Vector<int> target2 { 1, 2, 3, 4, 5, 6, 7 };
	ASSERT_TRUE(vector2.equals(target2));
}

TEST (JavaUtil, VectorFirstElement) {
	// Given a valid vector, contains three elements are string - return the first element.
	Vector<String> vector;
	vector.add("Hello");
	vector.add("World");
	vector.add("Vector");
	ASSERT_STR("Hello", vector.firstElement().toString());
}

TEST (JavaUtil, VectorGet) {
	// Given an valid vector with elements are string.
	Vector<String> vector;
	vector.add("Hello");
	vector.add("World");
	vector.add("I'm");
	vector.add("a");
	vector.add("Vector");
	// Get element at index 0, then index 4.
	ASSERT_STR("Hello", vector.get(0).toString());
	ASSERT_STR("Vector", vector.get(4).toString());
}

TEST (JavaUtil, VectorIsEmpty) {
	// Given an empty vector, vector is empty.
	Vector<int> vector;
	ASSERT_TRUE(vector.isEmpty());
	// Add an element into vector, vector is not empty.
	vector.add(0);
	ASSERT_FALSE(vector.isEmpty());
}

TEST (JavaUtil, VectorIndexOf) {
	// Given a valid vector - return index of an element in vector.
	Vector<int> vector;
	vector.add(1);
	vector.add(2);
	vector.add(3);
	ASSERT_EQUAL(0, vector.indexOf(1));
	ASSERT_EQUAL(2, vector.indexOf(3));
	
	vector.clear();
	vector.add(1);
	vector.add(2);
	vector.add(4);
	vector.add(4);
	vector.add(5);
	ASSERT_EQUAL(-1, vector.indexOf(4, 4));
	ASSERT_EQUAL(2, vector.indexOf(4, 0));
}

TEST (JavaUtil, VectorInsertElementAt) {
	// Given a valid vector.
	Vector<int> vector;
	vector.add(1);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	vector.add(5);
	ASSERT_EQUAL(1, vector.firstElement());
	ASSERT_EQUAL(5, vector.lastElement());
	// Inserts an element.
	vector.insertElementAt(0, 0);
	// Checks that element after added.
	ASSERT_EQUAL(0, vector.get(0));
}

TEST (JavaUtil, VectorLastElement) {
	// Given a valid vector, contains three elements are string - return the last element.
	Vector<String> vector;
	vector.add("Hello");
	vector.add("World");
	vector.add("Vector");
	ASSERT_STR("Vector", vector.lastElement().toString());
}

TEST (JavaUtil, VectorLastIndexOf) {
	// Given an valid vector - check last index of some elements.
	Vector<int> vector;
	vector.add(1);
	vector.add(2);
	vector.add(2);
	vector.add(2);
	vector.add(5);
	ASSERT_EQUAL(0, vector.lastIndexOf(1));
	ASSERT_EQUAL(3, vector.lastIndexOf(2));
	
	ASSERT_EQUAL(3, vector.lastIndexOf(2, 4));
	ASSERT_EQUAL(1, vector.lastIndexOf(2, 1));
}

TEST (JavaUtil, VectorRemove) {
	// Given empty vector, add three elements, remove at index 1 twice times, then remove at index 0.
	// Result is element that removed from vector.
	Vector<int> vector1;
	vector1.add(1);
	vector1.add(2);
	vector1.add(3);
	ASSERT_EQUAL(2, vector1.remove(1));
	ASSERT_EQUAL(3, vector1.remove(1));
	ASSERT_EQUAL(1, vector1.remove(0));
	// Check size of vector.
	ASSERT_EQUAL(0, vector1.size());
	
	// Given a valid vector, removes specified elements.
	Vector<String> vector2;
	vector2.add(String("1"));
	vector2.add(String("2"));
	vector2.add(String("3"));
	vector2.add(String("4"));
	vector2.add(String("5"));
	ASSERT_FALSE(vector2.remove(String("10"))); // This element doesn't exists.
	ASSERT_TRUE(vector2.remove(String("5")));
	
	Vector<Integer> vector3;
	vector3.add(Integer(1));
	vector3.add(Integer(2));
	vector3.add(Integer(3));
	vector3.add(Integer(4));
	vector3.add(Integer(5));
	vector3.remove(Integer(3));
	ASSERT_FALSE(vector3.contains(Integer(3)));
}

TEST (JavaUtil, VectorRemoveAll) {
	// Given a valid vector.
	Vector<int> vector({ 1, 2, 3, 4, 5 });
	// Removes element appearing in the specified list.
	ASSERT_TRUE(vector.removeAll({ 1, 2, 3 }));
	// Checks size and the first-last element.
	ASSERT_EQUAL(2, vector.size());
	ASSERT_EQUAL(4, vector.firstElement());
	ASSERT_EQUAL(5, vector.lastElement());
}

TEST (JavaUtil, VectorRemoveAllElements) {
	// Given empty vector - return size of vector is 0.
	Vector<String> vector;
	ASSERT_EQUAL(0, vector.size());
	
	// Add three elements into vector - return size of vector is 3.
	vector.add("Hello");
	vector.add("World");
	vector.add("Vector");
	ASSERT_EQUAL(3, vector.size());
	
	// Remove all elements of vector - return size of vector is 0.
	vector.clear();
	ASSERT_EQUAL(0, vector.size());
}

TEST (JavaUtil, VectorRemoveElement) {
	Vector<Integer> vector;
	vector.add(Integer(1));
	vector.add(Integer(2));
	vector.add(Integer(3));
	vector.add(Integer(4));
	vector.add(Integer(5));
	
	vector.removeElement(Integer(3));
	ASSERT_EQUAL(4, vector.size());
	ASSERT_FALSE(vector.contains(Integer(3)));
}

TEST (JavaUtil, VectorRemoveElementAt) {
	// Given a valid vector.
	Vector<int> vector;
	vector.add(1);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	vector.add(5);
	// Removes element at index = 2.
	vector.removeElementAt(2);
	// Checks element value at index = 2.
	ASSERT_EQUAL(4, vector.get(2));
}

// This class use to call some protected methods in Vector class to run in test cases.
template <typename E>
class VectorFriend : public Vector<E> {
public:
		void removeRange(int fromIndex, int toIndex) {
			Vector<E>::removeRange(fromIndex, toIndex);
		}
};

TEST (JavaUtil, VectorRemoveRange) {
	// Given a valid vector.
	VectorFriend<int> vector;
	vector.add(1); // 0
	vector.add(2); // 1
	vector.add(3); // 2
	vector.add(4); // 3
	vector.add(5);
	vector.add(6);
	vector.add(7);
	vector.add(8);
	// index: 0 1 2 3 4 5 6 7
	// value: 1 2 3 4 5 6 7 8
	vector.removeRange(1, 3); // Removes elements at index: {1, 2}
	// index: 0 1 2 3 4 5
	// value: 1 4 5 6 7 8
	ASSERT_EQUAL(1, vector.get(0));
	ASSERT_EQUAL(4, vector.get(1));
}

TEST (JavaUtil, VectorRetainAll) {
	Vector<int> vector { 1, 2, 3, 4, 5 };
	ASSERT_TRUE(vector.retainAll({ 4, 5, 6 }));
	ASSERT_EQUAL(2, vector.size());
	ASSERT_EQUAL(4, vector.firstElement());
	ASSERT_EQUAL(5, vector.lastElement());
}

TEST (JavaUtil, VectorSet) {
	// Given a valid vector.
	Vector<int> vector;
	vector.add(1);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	vector.add(5);
	// Change element at index 0.
	ASSERT_EQUAL(1, vector.set(0, 10));
	// Check element at index 0.
	ASSERT_EQUAL(10, vector.get(0));
	// Change element at index 4.
	ASSERT_EQUAL(5, vector.set(4, 0));
	// Check element at index 4.
	ASSERT_EQUAL(0, vector.get(4));
}

TEST (JavaUtil, VectorSetElementAt) {
	// Given a valid vector.
	Vector<int> vector;
	vector.add(1);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	vector.add(5);
	// Change element at index 0.
	vector.setElementAt(10, 0);
	// Check element at index 0.
	ASSERT_EQUAL(10, vector.get(0));
	// Change element at index 4.
	vector.setElementAt(0, 4);
	// Check element at index 4.
	ASSERT_EQUAL(0, vector.get(4));
}

TEST (JavaUtil, VectorSetSize) {
	// Given a valid vector.
	Vector<int> vector;
	vector.add(1);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	vector.add(5);
	vector.add(6);
	vector.add(7);
	vector.add(8);
	vector.add(9);
	// Sets size and checks size.
	vector.setSize(5);
	ASSERT_EQUAL(5, vector.size());
}

TEST (JavaUtil, VectorSize) {
	// Given a empty vector, then add an element - return size.
	Vector<int> vector;
	vector.add(0);
	ASSERT_EQUAL(1, vector.size());
	
	// Remove the element at index 0 - return size.
	vector.remove(0);
	ASSERT_EQUAL(0, vector.size());
	
	// Add five elements into vector - return size.
	vector.add(1);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	vector.add(5);
	ASSERT_EQUAL(5, vector.size());
}

TEST (JavaUtil, VectorToArray) {
	// Given a valid vector.
	Vector<int> vector { 1, 2, 3, 4, 5 };
	// Copies vector to an array.
	Array<int> anArray = vector.toArray();
	// Check elements of vector and array at same order.
	register int index;
	for (index = 0; index < vector.size(); index++) {
		ASSERT_EQUAL(vector[ index ], anArray[ index ]);
	}
}

TEST (JavaUtil, VectorTrimToSize) {
	// Given a valid vector.
	Vector<int> vector;
	vector.add(1);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	vector.add(5);
	vector.add(6);
	vector.trimToSize(); // Trims the capacity to be the current size.
	ASSERT_EQUAL(vector.size(), vector.capacity());
	vector.remove(0); // After removing an element, capacity is not equal with size.
	ASSERT_NOT_EQUAL(vector.size(), vector.capacity());
	vector.trimToSize();
	ASSERT_EQUAL(vector.size(), vector.capacity());
}

TEST (JavaUtil, VectorRangeBasedForLoop) {
	// Given a valid vector.
	Vector<int> vector;
	vector.add(0);
	vector.add(1);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	// Using range-base-for-loop and checks element value.
	int index = 0;
	for (int element : vector) {
		ASSERT_EQUAL(index, element);
		index++;
	}
}

TEST (JavaUtil, VectorArrayOperator) {
	// Given a valid vector.
	Vector<int> vector;
	vector.add(0);
	vector.add(1);
	vector.add(2);
	vector.add(3);
	vector.add(4);
	// Accesses element value using array operator.
	int index;
	for (index = 0; index < vector.size(); index++) {
		ASSERT_EQUAL(index, vector[ index ]);
	}
	vector[ 0 ] = -1;
	ASSERT_EQUAL(-1, vector.get(0));
}

TEST (JavaUtil, VectorAssignmentOperator) {
	// Given an empty vector and add an element to it.
	Vector<int> vector;
	vector.add(-1);
	// Assigns with an initializer list.
	vector = { 1, 2, 3, 4, 5 };
	// Checks size and the first-last element.
	ASSERT_EQUAL(5, vector.size());
	ASSERT_EQUAL(1, vector.firstElement());
	ASSERT_EQUAL(5, vector.lastElement());
	
	// Given an target vector with some elements inside.
	Vector<int> target { 10, 11, 12 };
	// Assigns target to vector.
	vector = target;
	// Checks size and the first-last element.
	ASSERT_EQUAL(3, vector.size());
	ASSERT_EQUAL(10, vector.firstElement());
	ASSERT_EQUAL(12, vector.lastElement());
}
