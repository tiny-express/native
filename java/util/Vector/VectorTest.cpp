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
#include "../../../unit_test.h"
}

#include "Vector.hpp"

using namespace Java::Util;

TEST(JavaUtil, VectorAdd) {
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

TEST(JavaUtil, VectorClear) {
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

TEST(JavaUtil, VectorClone) {
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
    ASSERT_EQUAL(5,clonedVector2.size());
    ASSERT_EQUAL(1, clonedVector2.firstElement());
    ASSERT_EQUAL(5, clonedVector2.lastElement());
}

TEST(JavaUtil, VectorFirstElement) {
    // Given a valid vector, contains three elements are string - return the first element.
    Vector<String> vector;
    vector.add("Hello");
    vector.add("World");
    vector.add("Vector");
    ASSERT_STR("Hello", vector.firstElement().toString());
}

TEST(JavaUtil, VectorGet) {
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

TEST(JavaUtil, VectorIsEmpty) {
    // Given an empty vector, vector is empty.
    Vector<int> vector;
    ASSERT_TRUE(vector.isEmpty());
    // Add an element into vector, vector is not empty.
    vector.add(0);
    ASSERT_FALSE(vector.isEmpty());
}


TEST(JavaUtil, VectorIndexOf) {
    // Given a valid vector - return index of an element in vector.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(3);
    ASSERT_EQUAL(0, vector.indexOf(1));
    ASSERT_EQUAL(2, vector.indexOf(3));
}

TEST(JavaUtil, VectorLastElement) {
    // Given a valid vector, contains three elements are string - return the last element.
    Vector<String> vector;
    vector.add("Hello");
    vector.add("World");
    vector.add("Vector");
    ASSERT_STR("Vector", vector.lastElement().toString());
}

TEST(JavaUtil, VectorLastIndexOf) {
    // Given an valid vector - check last index of some elements.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(2);
    vector.add(2);
    vector.add(5);
    ASSERT_EQUAL(0, vector.lastIndexOf(1));
    ASSERT_EQUAL(3, vector.lastIndexOf(2));
}

TEST(JavaUtil, VectorSize) {
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


TEST(JavaUtil, VectorRemove) {
    // Given empty vector, add three elements, remove at index 1 twice times, then remove at index 0.
    // Result is element that removed from vector.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(3);
    ASSERT_EQUAL(2, vector.remove(1));
    ASSERT_EQUAL(3, vector.remove(1));
    ASSERT_EQUAL(1, vector.remove(0));
    // Check size of vector.
    ASSERT_EQUAL(0, vector.size());
}

TEST(JavaUtil, VectorRemoveAllElements) {
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

TEST(JavaUtil, VectorRemoveRange) {
    // Given a valid vector.
    Vector<int> vector;
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
