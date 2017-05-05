//
// Created by coder on 08/04/2017.
//

#include "../compress.h"
#include "../unit_test.h"

TEST(Compress, ZlibCompressor) {
	// English
	char *contents = "Hello Hello Hello Hello Hello Hello!";
	char *compressed = zlib_encode(contents);
	char *decompressed = zlib_decode(compressed);
	ASSERT_STR(contents, decompressed);

	// Japan
	contents = "わたし の名前はHelpdesk.tokyo です。学生です";
	compressed = zlib_encode(contents);
	decompressed = zlib_decode(compressed);
	ASSERT_STR(contents, decompressed);

	// Vietnam
	contents = "Xin chào. Tôi là ai đó \n\n";
	compressed = zlib_encode(contents);
	decompressed = zlib_decode(compressed);
	ASSERT_STR(contents, decompressed);
}
