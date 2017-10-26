/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
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

#include "../../java/Lang.hpp"

using namespace Java::Lang;

/**
 * Application starting point
 * This function handle any application exception to keep program safety
 *
 * @param program
 * @param argument
 * @return int
 */
int Application(void (*program)(Array <String>), int argc, char **argument) {
	try {
		Array <String> args;
		int argumentIndex;
		for (argumentIndex = 0; argumentIndex < argc; argumentIndex++) {
			args.push(argument[ argumentIndex ]);
		}
		program(argument);
		return 0;
	} catch (Exception &e) {
		System::out::println("Application Exception: " + e.getMessage());
		return 1;
	} catch (...) {
#ifdef LINUX
		std::exception_ptr p = std::current_exception();
				String exceptionName = p.__cxa_exception_type()->name();
				System::out::println("Unhandled Exception: " + exceptionName);
#else
		System::out::println("Unhandled Exception");
#endif
		return 1;
	}
}