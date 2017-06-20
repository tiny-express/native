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

#include "../../Lang.hpp"
#include "HashMap.hpp"

using namespace Java::Lang;
using namespace Java::Util;

/**
 * All test cases use put(), so we don't need to test this function, if it wrong, will cause all test cases wrong
 */

TEST (JavaUtil, HashMapGet) {
	// Given valid hash map to test get()
	HashMap<String, String> hashMap;
	hashMap.put("key", "value");

	String *result = hashMap.get("key");
	String expectedValue = "value";
	ASSERT_NOT_NULL(result);
	ASSERT_STR(expectedValue.toString(), (*result).toString());
	ASSERT_STR(expectedValue.toString(), result->toString()); //another way to deal

	String *nullableResult = hashMap.get("wrong_key");
	ASSERT_NULL(nullableResult);
}

TEST (JavaUtil, HashMapContainsKey) {
	// Given valid hash map to test containsKey()
	HashMap<Integer, String> hashMap;
	hashMap.put(3, "three");
	hashMap.put(17, "seven teen");
	hashMap.put(-52, "negative fifty two");

	boolean exist = hashMap.containsKey(-52);
	ASSERT_TRUE(exist);

	boolean notFound = hashMap.containsKey(100);
	ASSERT_FALSE(notFound);
}

TEST (JavaUtil, HashMapContainsValue) {
	// Given valid hash map to test containsValue()
	HashMap<String, Double> hashMap;
	hashMap.put("15.3", 15.3);
	hashMap.put("30.111", 30.111);

	boolean exist = hashMap.containsValue(15.3);
	ASSERT_TRUE(exist);

	boolean notFound = hashMap.containsValue(30.22);
	ASSERT_FALSE(notFound);
}

TEST (JavaUtil, HashMapSize) {
	// Given valid hash map to test size()
	HashMap<Double, String> hashMap;
	hashMap.put(15.22222, "15.22222");
	hashMap.put(-50.2222, "50");

	int expectedSize = 2;
	ASSERT_EQUAL(expectedSize, hashMap.size());
}

TEST (JavaUtil, HashMapClear) {
	// Given valid hashMap to test clear()
	HashMap<Long, Integer> hashMap;
	hashMap.put(100, 25);
	hashMap.put(500, 123);

	hashMap.clear();
	int expectedSizeAfterClear = 0;
	ASSERT_EQUAL(expectedSizeAfterClear, hashMap.size());
}