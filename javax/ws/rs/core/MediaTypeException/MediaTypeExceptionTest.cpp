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

#include "MediaTypeException.hpp"
#include "../../../../../kernel/Test.hpp"

using namespace Javax::Ws;

TEST(MediaTypeException, Constructor) {
    // Default constructor, expected empty message
    MediaTypeException mediaTypeException;
    assertEquals("", mediaTypeException.getMessage().toString());

    // Constructs a new MediaTypeException with the specified detail message.
    MediaTypeException mediaTypeExceptionWithMessage = MediaTypeException("Wildcard type is legal only in '*/*' (all types)");
    assertEquals("Wildcard type is legal only in '*/*' (all types)", mediaTypeExceptionWithMessage.getMessage().toString());

    // Constructs a new MediaTypeException with the specified detail message and cause.
    MediaTypeException mediaTypeExceptionWithMessageAndCause = MediaTypeException("does not contain subtype after '/'", &mediaTypeExceptionWithMessage);
    assertEquals("does not contain subtype after '/'", mediaTypeExceptionWithMessageAndCause.getMessage().toString());
    assertEquals("Wildcard type is legal only in '*/*' (all types)", mediaTypeExceptionWithMessageAndCause.getCause()->getMessage().toString());

    // Constructs a new MediaTypeException with the specified cause.
    MediaTypeException mediaTypeExceptionWithCause = MediaTypeException(&mediaTypeExceptionWithMessageAndCause);
    assertEquals("does not contain subtype after '/'", mediaTypeExceptionWithCause.getCause()->getMessage().toString());
    assertEquals("Wildcard type is legal only in '*/*' (all types)", mediaTypeExceptionWithCause.getCause()->getCause()->getMessage().toString());
}

TEST(MediaTypeException, TryCatch) {

    // Throw MediaType Exception with message "throw MediaType Exception", expected message "throw MediaType Exception"
    MediaTypeException mediaTypeException;
    try {
        throw MediaTypeException("throw MediaType Exception");
    } catch(MediaTypeException &exception) {
        mediaTypeException = exception;
    }
    assertEquals("throw MediaType Exception", mediaTypeException.getMessage().toString());
}
