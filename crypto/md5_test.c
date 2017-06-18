#include "../crypto.h"
#include "../unit_test.h"
#include <stdlib.h>

TEST (Crypto, Md5) {
	char *result = md5_encode((unsigned char *) "ahihi");
	char *expect = "24dca22fdab7a594baa005d55db4f7bf";
	ASSERT_STR(expect, result);
	free(result);
	
	char *result1 = md5_encode((unsigned char *) "");
	char *expect1 = "d41d8cd98f00b204e9800998ecf8427e";
	ASSERT_STR(expect1, result1);
	free(result1);
	
	char *result2 = md5_encode(NULL);
	char *expect2 = "";
	ASSERT_STR(expect2, result2);
}
