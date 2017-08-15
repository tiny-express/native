/**
 Copyright 2017 Food Tiny Project. All rights reserved.
 *
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 *
 Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 Redistributions in binary form must reproduce the above
 copyright notice, this list of conditions and the following disclaimer
 in the documentation and/or other materials provided with the
 distribution.
 *
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "NumberFormatException.hpp"

extern "C" {
#include "../../../kernel/test.h"
}

TEST (JavaLang, NumberFormatExceptionConstructor) {
	// Constructs a new NumberFormatException with null as its detail message.
	NumberFormatException NumberFormatExceptionWithNullMessage;
	ASSERT_STR("", NumberFormatExceptionWithNullMessage.getMessage().toString());
	
	// Constructs a new NumberFormatException with the specified detail message.
	NumberFormatException NumberFormatExceptionWithMessage = NumberFormatException("NumberFormatException with the specified message");
	ASSERT_STR("NumberFormatException with the specified message", NumberFormatExceptionWithMessage.getMessage().toString());
}

TEST (JavaLang, NumberFormatExceptionTryCatch) {
	try {
		throw NumberFormatException("Throw NumberFormatException");
	} catch (NumberFormatException &e) {
		ASSERT_STR("Throw NumberFormatException", e.getMessage().toString());
	}
}