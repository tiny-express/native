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

#include "StringIndexOutOfBoundsException.hpp"

using namespace Java::Lang;

TEST (JavaLang, StringIndexOutOfBoundsExceptionConstructor) {
	// Constructs a new StringIndexOutOfBoundsExceptionConstructor with null as its detail message.
	StringIndexOutOfBoundsException stringIndexOutOfBoundsExceptionWithNullMessage;
	ASSERT_STR("", stringIndexOutOfBoundsExceptionWithNullMessage.getMessage().toString());
	
	// Constructs a new StringIndexOutOfBoundsExceptionConstructor with the specified detail message.
	StringIndexOutOfBoundsException stringIndexOutOfBoundsExceptionWithMessage = StringIndexOutOfBoundsException("StringIndexOutOfBoundsException with the specified message");
	ASSERT_STR("StringIndexOutOfBoundsException with the specified message", stringIndexOutOfBoundsExceptionWithMessage.getMessage().toString());
	
	// Constructs a new StringIndexOutOfBoundsExceptionConstructor with the specified detail message and cause.
	StringIndexOutOfBoundsException stringIndexOutOfBoundsExceptionWithMessageAndCause = StringIndexOutOfBoundsException("StringIndexOutOfBoundsException with the specified message and cause", &stringIndexOutOfBoundsExceptionWithMessage);
	ASSERT_STR("StringIndexOutOfBoundsException with the specified message and cause", stringIndexOutOfBoundsExceptionWithMessageAndCause.getMessage().toString());
	ASSERT_STR("StringIndexOutOfBoundsException with the specified message", stringIndexOutOfBoundsExceptionWithMessageAndCause.getCause()->getMessage().toString());
	
	// Constructs a new StringIndexOutOfBoundsExceptionConstructor with the specified cause.
	StringIndexOutOfBoundsException stringIndexOutOfBoundsExceptionWithCause = StringIndexOutOfBoundsException(&stringIndexOutOfBoundsExceptionWithMessageAndCause);
	ASSERT_STR("StringIndexOutOfBoundsException with the specified message and cause", stringIndexOutOfBoundsExceptionWithCause.getCause()->getMessage().toString());
	ASSERT_STR("StringIndexOutOfBoundsException with the specified message", stringIndexOutOfBoundsExceptionWithCause.getCause()->getCause()->getMessage().toString());
	
	// Constructs a new StringIndexOutOfBoundsException class with an argument indicating the illegal index.
	StringIndexOutOfBoundsException stringIndexOutOfBoundsExceptionWithIllegalIndex = StringIndexOutOfBoundsException(999);
	ASSERT_STR("String index out of range: 999", stringIndexOutOfBoundsExceptionWithIllegalIndex.getMessage().toString());
}

TEST (JavaLang, StringIndexOutOfBoundsExceptionTryCatch) {
	try {
		throw StringIndexOutOfBoundsException("Throw StringIndexOutOfBoundsException");
	} catch (Exception e) {
		ASSERT_STR("Throw StringIndexOutOfBoundsException", e.getMessage().toString());
	}
}
