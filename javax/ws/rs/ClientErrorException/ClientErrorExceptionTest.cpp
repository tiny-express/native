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

#include "ClientErrorException.hpp"
#include "../../../../kernel/Test.hpp"

using namespace Javax::Ws::Rs;

TEST(ClientErrorException, Constructor) {
    // Default constructor, expected empty message
    ClientErrorException clientErrorException;
    assertEquals("", clientErrorException.getMessage().toString());

    // Constructs a new ClientErrorException with the specified detail message.
    ClientErrorException clientErrorExceptionWithMessage = ClientErrorException(
            "Illegal param");
    assertEquals("Illegal param",
               clientErrorExceptionWithMessage.getMessage().toString());

    // Constructs a new ClientErrorException with the specified detail message and cause.
    ClientErrorException clientErrorExceptionWithMessageAndCause =
            ClientErrorException("Illegal param", &clientErrorExceptionWithMessage);
    assertEquals("Illegal param",
               clientErrorExceptionWithMessageAndCause.getMessage().toString());
    assertEquals("Illegal param",
               clientErrorExceptionWithMessageAndCause.getCause()->getMessage().toString());

    // Constructs a new ClientErrorException with the specified cause.
    ClientErrorException clientErrorExceptionWithCause =
            ClientErrorException(&clientErrorExceptionWithMessageAndCause);
    assertEquals("Illegal param",
               clientErrorExceptionWithCause.getCause()->getMessage().toString());
    assertEquals("Illegal param",
               clientErrorExceptionWithCause.getCause()->getCause()->getMessage().toString());
}

TEST(ClientErrorException, TryCatch) {
    // Throw ClientErrorException with message "throw ClientErrorException"
    // expected message "throw ClientErrorException"
    ClientErrorException clientErrorException;
    try {
        throw ClientErrorException("throw ClientErrorException");
    } catch (ClientErrorException &exception) {
        clientErrorException = exception;
    }
    assertEquals("throw ClientErrorException", clientErrorException.getMessage().toString());
}
