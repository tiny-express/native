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

#include "IllegalArgumentException.hpp"


using namespace Java::Lang;

TEST (JavaLang, IllegalArgumentExceptionConstructor) {
	// Constructs a new IllegalArgumentException with null as its detail message.
	IllegalArgumentException illegalArgumentExceptionWithNullMessage;
	ASSERT_STR("", illegalArgumentExceptionWithNullMessage.getMessage().toString());
	
	// Constructs a new IllegalArgumentException with the specified detail message.
	IllegalArgumentException illegalArgumentExceptionWithMessage = IllegalArgumentException("IllegalArgumentException with the specified message");
	ASSERT_STR("IllegalArgumentException with the specified message", illegalArgumentExceptionWithMessage.getMessage().toString());
	
	// Constructs a new IllegalArgumentException with the specified detail message and cause.
	IllegalArgumentException illegalArgumentExceptionWithMessageAndCause = IllegalArgumentException("IllegalArgumentException with the specified message and cause", &illegalArgumentExceptionWithMessage);
	ASSERT_STR("IllegalArgumentException with the specified message and cause", illegalArgumentExceptionWithMessageAndCause.getMessage().toString());
	ASSERT_STR("IllegalArgumentException with the specified message", illegalArgumentExceptionWithMessageAndCause.getCause()->getMessage().toString());
	
	// Constructs a new IllegalArgumentException with the specified cause.
	IllegalArgumentException illegalArgumentExceptionWithCause = IllegalArgumentException(&illegalArgumentExceptionWithMessageAndCause);
	ASSERT_STR("IllegalArgumentException with the specified message and cause", illegalArgumentExceptionWithCause.getCause()->getMessage().toString());
	ASSERT_STR("IllegalArgumentException with the specified message", illegalArgumentExceptionWithCause.getCause()->getCause()->getMessage().toString());
}

TEST (JavaLang, IllegalArgumentExceptionTryCatch) {
	try {
		throw IllegalArgumentException("Throw IllegalArgumentException");
	}
	catch (IllegalArgumentException e) {
		ASSERT_STR("Throw IllegalArgumentException", e.getMessage().toString());
	}
}