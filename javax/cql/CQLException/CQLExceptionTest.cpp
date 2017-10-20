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
#include "CQLException.hpp"

using namespace Javax::Cql;

TEST (JavaxCql, CQLExceptionConstructor) {
    // Constructs a new CQLException with null as its detail message.
    CQLException cqlExceptionWithNullMessage;
    assertEquals("", cqlExceptionWithNullMessage.getMessage().toString());

    // Constructs a new CQLException with the specified detail message.
    CQLException cqlExceptionWithMessage = CQLException("CQLException with the specified message");
    assertEquals("CQLException with the specified message", cqlExceptionWithMessage.getMessage().toString());

    // Constructs a new CQLException with the specified detail message and cause.
    CQLException cqlExceptionWithMessageAndCause = CQLException("CQLException with the specified message and cause", &cqlExceptionWithMessage);
    assertEquals("CQLException with the specified message and cause", cqlExceptionWithMessageAndCause.getMessage().toString());
    assertEquals("CQLException with the specified message", cqlExceptionWithMessageAndCause.getCause()->getMessage().toString());

    // Constructs a new CQLException with the specified cause.
    CQLException cqlExceptionWithCause = CQLException(&cqlExceptionWithMessageAndCause);
    assertEquals("CQLException with the specified message and cause", cqlExceptionWithCause.getCause()->getMessage().toString());
    assertEquals("CQLException with the specified message", cqlExceptionWithCause.getCause()->getCause()->getMessage().toString());
}

TEST (JavaxCql, CQLExceptionTryCatch) {
    try {
        throw CQLException("Throw CQLException");
    } catch (CQLException &e) {
        assertEquals("Throw CQLException", e.getMessage().toString());
    }
}