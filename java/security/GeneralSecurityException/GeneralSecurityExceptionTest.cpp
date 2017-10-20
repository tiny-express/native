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
#include "GeneralSecurityException.hpp"

using namespace Java::Security;

TEST(JavaLang, GeneralSecurityExceptionConstructor) {

    GeneralSecurityException generalSecurityExceptionWithNullMessage;
    assertEquals(
            "",
            generalSecurityExceptionWithNullMessage.getMessage().toString());

    GeneralSecurityException generalSecurityExceptionWithMessage =
            GeneralSecurityException(
                    "GeneralSecurityException with the specified message");

    assertEquals(
            "GeneralSecurityException with the specified message",
            generalSecurityExceptionWithMessage.getMessage().toString());

    GeneralSecurityException generalSecurityExceptionWithMessageAndCause =
            GeneralSecurityException(
                    "GeneralSecurityException with the specified message and cause",
                    &generalSecurityExceptionWithMessage);
    assertEquals(
            "GeneralSecurityException with the specified message and cause",
            generalSecurityExceptionWithMessageAndCause.getMessage().toString());
    assertEquals(
            "GeneralSecurityException with the specified message",
            generalSecurityExceptionWithMessageAndCause.getCause()
                    ->getMessage().toString());

    GeneralSecurityException generalSecurityExceptionWithCause =
            GeneralSecurityException(&generalSecurityExceptionWithMessageAndCause);
    assertEquals("GeneralSecurityException with the specified message and cause",
               generalSecurityExceptionWithCause.getCause()
                       ->getMessage().toString());
    assertEquals("GeneralSecurityException with the specified message",
               generalSecurityExceptionWithCause.getCause()
                       ->getCause()
                       ->getMessage().toString());
}

TEST(JavaLang, GeneralSecurityExceptionTryCatch) {
    try {
        throw GeneralSecurityException("Throw GeneralException");
    } catch (Exception e) {
        assertEquals("Throw GeneralException", e.getMessage().toString());
    }
}