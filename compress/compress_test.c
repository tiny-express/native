//
// Created by coder on 08/04/2017.
//

#include "../compress.h"
#include "../unit_test.h"

TEST(Builtin_Compress, Zlib_Encode_Decode) {
	// English
	char *contents = "Hello Hello Hello Hello Hello Hello!";
	char *compressed = zlib_encode(contents);
	char *decompressed = zlib_decode(compressed);
	ASSERT_STR(decompressed, contents);

	// Japan
	char *contents_Japan = "わたし の名前はHelpdesk.tokyo です。学生です";
	char *compressed_Japan = zlib_encode(contents_Japan);
	char *decompressed_Japan = zlib_decode(compressed_Japan);

	ASSERT_STR(decompressed_Japan, contents_Japan);

	// Vietnam
	char *contents_Vietnam = "Xin chào FoodTiny! \n Tạm biệt FoodTiny";
	char *compressed_Vietnam = zlib_encode(contents_Vietnam);
	char *decompressed_Vietnam = zlib_decode(compressed_Vietnam);

	ASSERT_STR(decompressed_Vietnam, contents_Vietnam);
}
