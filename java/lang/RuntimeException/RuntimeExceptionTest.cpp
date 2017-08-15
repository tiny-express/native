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

#include "../RuntimeException/RuntimeException.hpp"

using namespace Java::Lang;


TEST (JavaLang, RuntimeExceptionConstructor) {
// Constructs a new RuntimeException with null as its detail message.
	RuntimeException runtimeExceptionWithNullMessage;
	ASSERT_STR("", runtimeExceptionWithNullMessage.getMessage().toString());

// Constructs a new RuntimeException with the specified detail message.
	RuntimeException runtimeExceptionWithMessage = RuntimeException("RuntimeException with the specified message");
	ASSERT_STR("RuntimeException with the specified message", runtimeExceptionWithMessage.getMessage().toString());

// Constructs a new RuntimeException with the specified detail message and cause.
	RuntimeException runtimeExceptionWithMessageAndCause = RuntimeException("RuntimeException with the specified message and cause", &runtimeExceptionWithMessage);
	ASSERT_STR("RuntimeException with the specified message and cause", runtimeExceptionWithMessageAndCause.getMessage().toString());
	ASSERT_STR("RuntimeException with the specified message", runtimeExceptionWithMessageAndCause.getCause()->getMessage().toString());

// Constructs a new RuntimeException with the specified cause.
	RuntimeException runtimeExceptionWithCause = RuntimeException(&runtimeExceptionWithMessageAndCause);
	ASSERT_STR("RuntimeException with the specified message and cause", runtimeExceptionWithCause.getCause()->getMessage().toString());
	ASSERT_STR("RuntimeException with the specified message", runtimeExceptionWithCause.getCause()->getCause()->getMessage().toString());
}

TEST (JavaLang, RuntimeExceptionTryCatch) {
	try {
		throw RuntimeException("Throw RuntimeException");
	} catch (Exception e) {
		ASSERT_STR("Throw RuntimeException", e.getMessage().toString());
	}
}
