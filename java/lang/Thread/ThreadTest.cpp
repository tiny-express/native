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
};

#include "Thread.hpp"

using namespace Java::Lang;

class RunnableTarget : public virtual Runnable {
public:
	void run() const {
	}
};

class RunnableTarget2 : public virtual Runnable {
public:
	void run() const {
		int index = 0;
		int limit = 51;
		for (; index <= limit; index++) {
			// printf("Index [%d] must not equal to %d to test Thread.stop()\n", index, limit);
			usleep(1);
		}
	}
};

// TODO(thoangminh): Need to improve it
TEST(JavaLang, ThreadConstructor) {
    Thread thread;
}

TEST(JavaLang, ThreadRun) {
    Thread thread;

    thread.run();
}

TEST(JavaLang, ThreadSetDaemon) {
    Thread thread;

    thread.setDaemon(true);
    ASSERT_TRUE(thread.isDaemon());

    thread.setDaemon(false);
    ASSERT_FALSE(thread.isDaemon());
}

TEST(JavaLang, ThreadIsDaemon) {
    Thread thread;

    thread.setDaemon(true);
    ASSERT_TRUE(thread.isDaemon());

    thread.setDaemon(false);
    ASSERT_FALSE(thread.isDaemon());
}

TEST(JavaLang, ThreadSetPriority) {
    Thread thread;

    thread.setPriority(-1);
    ASSERT_EQUAL(1, thread.getPriority());

    thread.setPriority(0);
    ASSERT_EQUAL(1, thread.getPriority());

    thread.setPriority(3);
    ASSERT_EQUAL(3, thread.getPriority());

    thread.setPriority(Thread::MIN_PRIORITY);
    ASSERT_EQUAL(1, thread.getPriority());

    thread.setPriority(Thread::NORM_PRIORITY);
    ASSERT_EQUAL(5, thread.getPriority());

    thread.setPriority(Thread::MAX_PRIORITY);
    ASSERT_EQUAL(10, thread.getPriority());
}

TEST(JavaLang, ThreadGetPriority) {
    Thread thread;

    thread.setPriority(-1);
    ASSERT_EQUAL(1, thread.getPriority());

    thread.setPriority(0);
    ASSERT_EQUAL(1, thread.getPriority());

    thread.setPriority(3);
    ASSERT_EQUAL(3, thread.getPriority());

    thread.setPriority(Thread::MIN_PRIORITY);
    ASSERT_EQUAL(1, thread.getPriority());

    thread.setPriority(Thread::NORM_PRIORITY);
    ASSERT_EQUAL(5, thread.getPriority());

    thread.setPriority(Thread::MAX_PRIORITY);
    ASSERT_EQUAL(10, thread.getPriority());
}

TEST(JavaLang, ThreadSetName) {
    Thread thread;

    String name = "Thread 1";
    thread.setName(name);
    ASSERT_STR((string) "Thread 1", thread.getName().toString());

    thread.setName((string) "Thread 2");
    ASSERT_STR((string) "Thread 2", thread.getName().toString());

    thread.setName((string) "Thread 5");
    ASSERT_NOT_STR((string) "Thread 1", thread.getName().toString());
}

TEST(JavaLang, ThreadGetName) {
    Thread thread;

    String name = "Thread 1";
    thread.setName(name);
    ASSERT_STR((string) "Thread 1", thread.getName().toString());

    thread.setName((string) "Thread 2");
    ASSERT_STR((string) "Thread 2", thread.getName().toString());

    thread.setName((string) "Thread 5");
    ASSERT_NOT_STR((string) "Thread 1", thread.getName().toString());
}

