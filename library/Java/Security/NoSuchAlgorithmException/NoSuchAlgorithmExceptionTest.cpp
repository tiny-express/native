/**
 * Copyright (c) 2016 Tiny Express Project. All rights reserved.
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
#include "NoSuchAlgorithmException.hpp"

using namespace Java::Security;

TEST(JavaLangNoSuchAlgorithmException, Constructor) {

    NoSuchAlgorithmException noSuchAlgorithmExceptionWithNullMessage;
    assertEquals(
            "",
            noSuchAlgorithmExceptionWithNullMessage.getMessage());

    NoSuchAlgorithmException noSuchAlgorithmExceptionWithMessage =
            NoSuchAlgorithmException(
                    "NoSuchAlgorithmException with the specified message");

    assertEquals(
            "NoSuchAlgorithmException with the specified message",
            noSuchAlgorithmExceptionWithMessage.getMessage());

    auto noSuchAlgorithmExceptionWithMessageAndCause = NoSuchAlgorithmException(
                    "NoSuchAlgorithmException with the specified message and cause",
                    &noSuchAlgorithmExceptionWithMessage);
    assertEquals(
            "NoSuchAlgorithmException with the specified message and cause",
            noSuchAlgorithmExceptionWithMessageAndCause.getMessage());
    assertEquals(
            "NoSuchAlgorithmException with the specified message",
            noSuchAlgorithmExceptionWithMessageAndCause.getCause()
                    ->getMessage());

    auto noSuchAlgorithmExceptionWithCause = NoSuchAlgorithmException(&noSuchAlgorithmExceptionWithMessageAndCause);
    assertEquals("NoSuchAlgorithmException with the specified message and cause",
               noSuchAlgorithmExceptionWithCause.getCause()
                       ->getMessage());
    assertEquals("NoSuchAlgorithmException with the specified message",
               noSuchAlgorithmExceptionWithCause.getCause()
                       ->getCause()
                       ->getMessage());
}

TEST(JavaLangNoSuchAlgorithmException,TryCatch) {
    try {
        throw NoSuchAlgorithmException("Throw NoSuchAlgorithmException");
    } catch (Exception e) {
        assertEquals("Throw NoSuchAlgorithmException", e.getMessage());
    }
}