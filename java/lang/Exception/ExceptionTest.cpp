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

#include "Exception.hpp"

using namespace Java::Lang;

TEST (JavaLang, ExceptionConstructor) {
	// Constructs a new Exception with null as its detail message.
	Exception exceptionWithNullMessage;
	ASSERT_STR("", exceptionWithNullMessage.getMessage().toString());
	
	// Constructs a new Exception with the specified detail message.
	Exception exceptionWithMessage = Exception("Exception with the specified message");
	ASSERT_STR("Exception with the specified message", exceptionWithMessage.getMessage().toString());
	
	// Constructs a new Exception with the specified detail message and cause.
	Exception exceptionWithMessageAndCause = Exception("Exception with the specified message and cause", &exceptionWithMessage);
	ASSERT_STR("Exception with the specified message and cause", exceptionWithMessageAndCause.getMessage().toString());
	ASSERT_STR("Exception with the specified message", exceptionWithMessageAndCause.getCause()->getMessage().toString());
	
	// Constructs a new Exception with the specified cause.
	Exception exceptionWithCause = Exception(&exceptionWithMessageAndCause);
	ASSERT_STR("Exception with the specified message and cause", exceptionWithCause.getCause()->getMessage().toString());
	ASSERT_STR("Exception with the specified message", exceptionWithCause.getCause()->getCause()->getMessage().toString());
}