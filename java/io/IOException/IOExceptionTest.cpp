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
#include "IOException.hpp"

using namespace Java::Lang;

TEST (JavaIO, IOExceptionConstructor) {
    // Constructs a new IOException with null as its detail message.
    IOException ioExceptionWithNullMessage;
    assertEquals("", ioExceptionWithNullMessage.getMessage().toString());

    // Constructs a new IOException with the specified detail message.
    IOException ioExceptionWithMessage = IOException("IOException with the specified message");
    assertEquals("IOException with the specified message", ioExceptionWithMessage.getMessage().toString());

    // Constructs a new IOException with the specified detail message and cause.
    IOException ioExceptionWithMessageAndCause = IOException("IOException with the specified message and cause", &ioExceptionWithMessage);
    assertEquals("IOException with the specified message and cause", ioExceptionWithMessageAndCause.getMessage().toString());
    assertEquals("IOException with the specified message", ioExceptionWithMessageAndCause.getCause()->getMessage().toString());

    // Constructs a new IOException with the specified cause.
    IOException ioExceptionWithCause = IOException(&ioExceptionWithMessageAndCause);
    assertEquals("IOException with the specified message and cause", ioExceptionWithCause.getCause()->getMessage().toString());
    assertEquals("IOException with the specified message", ioExceptionWithCause.getCause()->getCause()->getMessage().toString());
}

TEST (JavaIO, IOExceptionTryCatch) {
    try {
        throw IOException("Throw IOException");
    } catch (IOException &ex) {
        assertEquals("Throw IOException", ex.getMessage().toString());
    }
}
