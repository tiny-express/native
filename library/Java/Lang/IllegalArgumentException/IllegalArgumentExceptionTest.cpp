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

#include "../../../Test.hpp"
#include "IllegalArgumentException.hpp"

using namespace Java::Lang;

TEST (JavaLangIllegalArgumentException, Constructor) {
	// Constructs a new IllegalArgumentException with null as its detail message.
	InterruptedException illegalArgumentExceptionWithNullMessage;
	assertEquals("", illegalArgumentExceptionWithNullMessage.getMessage());
	
	// Constructs a new IllegalArgumentException with the specified detail message.
	InterruptedException illegalArgumentExceptionWithMessage = InterruptedException("IllegalArgumentException with the specified message");
	assertEquals("IllegalArgumentException with the specified message", illegalArgumentExceptionWithMessage.getMessage());
	
	// Constructs a new IllegalArgumentException with the specified detail message and cause.
	InterruptedException illegalArgumentExceptionWithMessageAndCause = InterruptedException("IllegalArgumentException with the specified message and cause", &illegalArgumentExceptionWithMessage);
	assertEquals("IllegalArgumentException with the specified message and cause", illegalArgumentExceptionWithMessageAndCause.getMessage());
	assertEquals("IllegalArgumentException with the specified message", illegalArgumentExceptionWithMessageAndCause.getCause()->getMessage());
	
	// Constructs a new IllegalArgumentException with the specified cause.
	InterruptedException illegalArgumentExceptionWithCause = InterruptedException(&illegalArgumentExceptionWithMessageAndCause);
	assertEquals("IllegalArgumentException with the specified message and cause", illegalArgumentExceptionWithCause.getCause()->getMessage());
	assertEquals("IllegalArgumentException with the specified message", illegalArgumentExceptionWithCause.getCause()->getCause()->getMessage());
}

TEST (JavaLangIllegalArgumentException, TryCatch) {
	try {
		throw InterruptedException("Throw IllegalArgumentException");
	}
	catch (InterruptedException e) {
		assertEquals("Throw IllegalArgumentException", e.getMessage());
	}
}