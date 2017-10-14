/**
 * Copyright (c) 2017 Food Tiny Project. All rights reserved.
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

#include "BadRequestException.hpp"
#include "../../../../kernel/Test.hpp"

using namespace Javax::Ws::Rs;

TEST(BadRequestException, Constructor) {
    // Default constructor, expected empty message
    BadRequestException badRequestException;
    assertEquals("", badRequestException.getMessage().toString());

    // Constructs a new BadRequestException with the specified detail message.
    BadRequestException badRequestExceptionWithMessage = BadRequestException(
            "Illegal param");
    assertEquals("Illegal param",
               badRequestExceptionWithMessage.getMessage().toString());

    // Constructs a new BadRequestException with the specified detail message and cause.
    BadRequestException badRequestExceptionWithMessageAndCause =
            BadRequestException("Illegal param", &badRequestExceptionWithMessage);
    assertEquals("Illegal param",
               badRequestExceptionWithMessageAndCause.getMessage().toString());
    assertEquals("Illegal param",
               badRequestExceptionWithMessageAndCause.getCause()->getMessage().toString());

    // Constructs a new BadRequestException with the specified cause.
    BadRequestException badRequestExceptionWithCause =
            BadRequestException(&badRequestExceptionWithMessageAndCause);
    assertEquals("Illegal param",
               badRequestExceptionWithCause.getCause()->getMessage().toString());
    assertEquals("Illegal param",
               badRequestExceptionWithCause.getCause()->getCause()->getMessage().toString());
}

TEST(BadRequestException, TryCatch) {
    // Throw BadRequestException with message "throw BadRequestException"
    // expected message "throw BadRequestException"
    BadRequestException badRequestException;
    try {
        throw BadRequestException("throw BadRequestException");
    } catch (BadRequestException &exception) {
        badRequestException = exception;
    }
    assertEquals("throw BadRequestException", badRequestException.getMessage().toString());
}
