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

#include "../../../kernel/Test.hpp"
#include "ArithmeticException.hpp"

using namespace Java::Lang;

TEST (JavaLangArithmeticException, Constructor) {
    // Constructs a new ArithmeticException with null as its detail message.
    ArithmeticException arithmeticExceptionWithNullMessage;
    assertEquals("", arithmeticExceptionWithNullMessage.getMessage());

    // Constructs a new ArithmeticException with the specified detail message.
    ArithmeticException arithmeticExceptionWithMessage = ArithmeticException(
            "ArithmeticException with the specified message");
    assertEquals("ArithmeticException with the specified message",
                 arithmeticExceptionWithMessage.getMessage());

    // Constructs a new ArithmeticException with the specified detail message and cause.
    ArithmeticException arithmeticExceptionWithMessageAndCause = ArithmeticException(
            "ArithmeticException with the specified message and cause",
            &arithmeticExceptionWithMessage);
    assertEquals("ArithmeticException with the specified message and cause",
                 arithmeticExceptionWithMessageAndCause.getMessage());
    assertEquals("ArithmeticException with the specified message",
                 arithmeticExceptionWithMessageAndCause.getCause()->getMessage());

    // Constructs a new ArithmeticException with the specified cause.
    ArithmeticException arithmeticExceptionWithCause = ArithmeticException(
            &arithmeticExceptionWithMessageAndCause);
    assertEquals("ArithmeticException with the specified message and cause",
                 arithmeticExceptionWithCause.getCause()->getMessage());
    assertEquals("ArithmeticException with the specified message",
                 arithmeticExceptionWithCause.getCause()->getCause()->getMessage());
}

TEST (JavaLangArithmeticException, TryCatch) {
    try {
        throw ArithmeticException("Throw ArithmeticException");
    }
    catch (ArithmeticException e) {
        assertEquals("Throw ArithmeticException", e.getMessage());
    }
}