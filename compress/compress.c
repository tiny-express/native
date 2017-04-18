//
// Created by coder on 06/04/2017.
//

#include <stdio.h>
#include "../string.h"
#include "../compress.h"
#include "../general.h"

#define MAXLEN 100000

// Compress
char* zlib_encode(char* compress_contents){
	char char_array_temp[MAXLEN];

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
	// End compressing

	// Convert to char pointer
	char *result = convert_to_pointer_char(char_array_temp);
	return result;
}

// Decompress
char *zlib_decode(char *encode_contents){
	char char_array_temp[MAXLEN];

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

	char *result = convert_to_pointer_char(char_array_temp);

	return result;
}