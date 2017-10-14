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

#include "WebApplicationException.hpp"
#include "../../../../kernel/Test.hpp"

using namespace Javax::Ws::Rs;

TEST(WebApplicationException, Constructor) {
    // Default constructor, expected empty message
    WebApplicationException webApplicationException;
    assertEquals("", webApplicationException.getMessage().toString());

    // Constructs a new WebApplicationException with the specified detail message.
    WebApplicationException webApplicationExceptionWithMessage = WebApplicationException(
            "Illegal param");
    assertEquals("Illegal param",
               webApplicationExceptionWithMessage.getMessage().toString());

    // Constructs a new WebApplicationException with the specified detail message and cause.
    WebApplicationException webApplicationExceptionWithMessageAndCause =
            WebApplicationException("Illegal param", &webApplicationExceptionWithMessage);
    assertEquals("Illegal param",
               webApplicationExceptionWithMessageAndCause.getMessage().toString());
    assertEquals("Illegal param",
               webApplicationExceptionWithMessageAndCause.getCause()->getMessage().toString());

    // Constructs a new WebApplicationException with the specified cause.
    WebApplicationException webApplicationExceptionWithCause =
            WebApplicationException(&webApplicationExceptionWithMessageAndCause);
    assertEquals("Illegal param",
               webApplicationExceptionWithCause.getCause()->getMessage().toString());
    assertEquals("Illegal param",
               webApplicationExceptionWithCause.getCause()->getCause()->getMessage().toString());
}

TEST(WebApplicationException, TryCatch) {
    // Throw WebApplicationException with message "throw WebApplicationException"
    // expected message "throw WebApplicationException"
    WebApplicationException webApplicationException;
    try {
        throw WebApplicationException("throw WebApplicationException");
    } catch (WebApplicationException &exception) {
        webApplicationException = exception;
    }
    assertEquals("throw WebApplicationException", webApplicationException.getMessage().toString());
}
