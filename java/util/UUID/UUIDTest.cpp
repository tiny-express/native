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

#include "UUID.hpp"


TEST (JavaUtil, UUIDConstructor) {
    // Given valid construct to test
    UUID uuid = UUID(123, 456);

    long result = uuid.getMostSignificantBits();
    long expectedValue = 123;
    ASSERT_EQUAL(expectedValue, result);

    result = uuid.getLeastSignificantBits();
    expectedValue = 456;
    ASSERT_EQUAL(expectedValue, result);

    /**
     * All test cases with static constructor are very hard to test,
     * just give sample to call instead
     */

    // Given valid static constructor with randomUUID
    uuid = UUID::randomUUID();

    // Given valid static constructor fromString format with sample below
    uuid = UUID::fromString("38400000-8cf0-11bd-b23e-10b96e4ef00d");
}

TEST (JavaUtil, UUIDCompare) {
    // Given valid 2 UUIDs, both of them will never be equal if different instance

    UUID uuid = UUID::randomUUID();
    UUID target = UUID::randomUUID();

    String uuidString = uuid.toString();
    String targetString = target.toString();

    ASSERT_TRUE(uuidString != targetString);
}

TEST (JavaUtil, UUIDEquals) {
    // Given valid an instance of UUID, test equals with ifself
    UUID uuid = UUID::randomUUID();

    ASSERT_TRUE(uuid.toString() == uuid.toString());
}

TEST (JavaUtil, UUIDGetSignificantBits) {
    // Given valid UUID to test getLeast and getMost of significant bits inside this class
    long expectedMost = 100000000;
    long expectedLeast = 5000000;
    UUID uuid = UUID(expectedMost, expectedLeast);

    ASSERT_EQUAL(expectedMost, uuid.getMostSignificantBits());

    ASSERT_EQUAL(expectedLeast, uuid.getLeastSignificantBits());
}

TEST (JavaUtil, UUIDNode) {
    // Given valid UUID to test node value
    UUID uuid = UUID::fromString("38400000-8cf0-11bd-b23e-10b96e4ef00d");

    long result = uuid.node();
    long expectedValue = 18388605661197;
    ASSERT_EQUAL(expectedValue, result);
}

TEST (JavaUtil, UUIDTimeStamps) {
    // Given valid UUID to test time stamps value
    UUID uuid = UUID::fromString("38400000-8cf0-11bd-b23e-10b96e4ef00d");

    long result = uuid.timestamp();
    long expectedValue = 125411328000000000;
    ASSERT_EQUAL(expectedValue, result);
}

TEST (JavaUtil, UUIDToString) {
    // Given valid UUID to test toString()
    UUID uuid = UUID::fromString("38400000-8cf0-11bd-b23e-10b96e4ef00d");
    UUID target = UUID(4053239666997989821, 5603022497796657139);

    String uuidString = uuid.toString();
    String targetString = target.toString();

    ASSERT_STR(uuidString.toString(), targetString.toString());
}

TEST (JavaUtil, UUIDVariant) {
    // Given valid UUID to test variant value
    UUID uuid = UUID::fromString("38400000-8cf0-11bd-b23e-10b96e4ef00d");

    long result = uuid.variant();
    long expectedValue = 2;
    ASSERT_EQUAL(expectedValue, result);
}

TEST (JavaUtil, UUIDVersion) {
    // Given valid UUID to test version value
    UUID uuid = UUID::fromString("38400000-8cf0-11bd-b23e-10b96e4ef00d");

    long result = uuid.version();
    long expectedValue = uuid.version();
    ASSERT_EQUAL(expectedValue, result);
}
