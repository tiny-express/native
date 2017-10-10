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

#include "../InterruptedException/InterruptedException.hpp"

using namespace Java::Lang;

TEST(JavaLang, InterruptedExceptionConstructor) {

    InterruptedException interruptedExceptionWithNullMessage;
    ASSERT_STR(
            "",
            interruptedExceptionWithNullMessage.getMessage().toString());

    InterruptedException interruptedExceptionWithMessage =
            InterruptedException(
                    "InterruptedException with the specified message");

    ASSERT_STR(
            "InterruptedException with the specified message",
            interruptedExceptionWithMessage.getMessage().toString());

    InterruptedException interruptedExceptionWithMessageAndCause =
            InterruptedException(
                    "InterruptedException with the specified message and cause",
                    &interruptedExceptionWithMessage);
    ASSERT_STR(
            "InterruptedException with the specified message and cause",
            interruptedExceptionWithMessageAndCause.getMessage().toString());
    ASSERT_STR(
            "InterruptedException with the specified message",
            interruptedExceptionWithMessageAndCause.getCause()
                    ->getMessage().toString());

    InterruptedException interruptedExceptionWithCause =
            InterruptedException(&interruptedExceptionWithMessageAndCause);
    ASSERT_STR("InterruptedException with the specified message and cause",
               interruptedExceptionWithCause.getCause()
                       ->getMessage().toString());
    ASSERT_STR("InterruptedException with the specified message",
               interruptedExceptionWithCause.getCause()
                       ->getCause()
                       ->getMessage().toString());
}

TEST(JavaLang, InterruptedExceptionTryCatch) {
    try {
        throw InterruptedException("Throw InterruptedException");
    } catch (Exception e) {
        ASSERT_STR("Throw InterruptedException", e.getMessage().toString());
    }
}
