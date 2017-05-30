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
};

#include "Thread.hpp"

using namespace Java::Lang;

class RunnableTarget: public virtual Runnable {
public:
    void run() const {
        printf("Hello world");
    }
};

TEST(JavaLang, ThreadConstructor) {
    // Given validThread with default constructor
    Thread thread;

    // Test empty threadName
    ASSERT_STR("", thread.getName());

    // Test true after set new name for threadName
    thread.setName("Some valid name");
    ASSERT_STR("Some valid name", thread.getName());
}

TEST(JavaLang, ThreadStart) {
    // Given validTarget and validThread to test start(), join(), join(millis) functions
    RunnableTarget validTarget;
    Thread thread = Thread(validTarget);

    thread.start();
    thread.join(); /// Make sure that thread has join() because if not, there will be crashed

    //FIXME: please help to check this output <"Hello world"> is appeard at test case 73 or not
}

TEST(JavaLang, ThreadStop) {
    //TODO
}