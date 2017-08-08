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

#include "../builtin.h"
#include "../test.h"

TEST (KernelCommon, AppendPointerChar) {
	char *target[] = {
		(char *) "The",
		(char *) "quick",
		(char *) "brown",
		(char *) "fox",
		(char *) "jumps",
		(char *) "over",
		(char *) "the",
		(char *) "lazy",
		'\0'
	};
	char *append = "dog";
	ASSERT_EQUAL(8, length_pointer_pointer_char(target));
	char **result = append_pointer_char(target, append);
	ASSERT_EQUAL(9, length_pointer_pointer_char(result));
	ASSERT_STR("The", result[ 0 ]);
	ASSERT_STR("quick", result[ 1 ]);
	ASSERT_STR("brown", result[ 2 ]);
	ASSERT_STR("fox", result[ 3 ]);
	ASSERT_STR("jumps", result[ 4 ]);
	ASSERT_STR("over", result[ 5 ]);
	ASSERT_STR("the", result[ 6 ]);
	ASSERT_STR("lazy", result[ 7 ]);
	ASSERT_STR("dog", result[ 8 ]);
	append = "";
	free(result);
	result = append_pointer_char(target, append);
	ASSERT_EQUAL(9, length_pointer_pointer_char(result));
	free(result);
}


