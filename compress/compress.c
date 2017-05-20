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

#include <stdio.h>
#include "../string.h"
#include "../compress.h"
#include "../common.h"

#define MAXLEN_STRING_COMPRESS 100000

// Compress
char* zlib_encode(char* compress_contents){
	char char_array_temp[MAXLEN_STRING_COMPRESS];

	// Compressing
	z_stream defstream;
	defstream.zalloc = Z_NULL;
	defstream.zfree = Z_NULL;
	defstream.opaque = Z_NULL;

	defstream.avail_in = (uInt)length_pointer_char(compress_contents) + 1;
	defstream.next_in = (Bytef *)compress_contents;
	defstream.avail_out = (uInt)sizeof(char_array_temp);
	defstream.next_out = (Bytef *)char_array_temp;

	deflateInit(&defstream, Z_BEST_COMPRESSION);
	deflate(&defstream, Z_FINISH);
	deflateEnd(&defstream);

	// Convert to char pointer
	return string_copy(char_array_temp);
}

// Decompress
char *zlib_decode(char *encode_contents){
	char char_array_temp[MAXLEN_STRING_COMPRESS];

	z_stream infstream;
	infstream.zalloc = Z_NULL;
	infstream.zfree = Z_NULL;
	infstream.opaque = Z_NULL;

	infstream.avail_in = (uInt)length_pointer_char(encode_contents) + 1;
	infstream.next_in = (Bytef *)encode_contents;
	infstream.avail_out = (uInt)sizeof(char_array_temp);
	infstream.next_out = (Bytef *)char_array_temp;

	inflateInit(&infstream);
	inflate(&infstream, Z_NO_FLUSH);
	inflateEnd(&infstream);

	char *result = string_copy(char_array_temp);

	return result;
}