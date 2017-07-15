#include "../crypto.h"
#include "../unit_test.h"
#include <stdlib.h>

TEST (Crypto, Sha1) {
	char *result = sha1_encode((unsigned char *) "hello world");
	char *expect = "2aae6c35c94fcfb415dbe95f408b9ce91ee846ed";
	ASSERT_STR(expect, result);
	free(result);
	
	char *result1 = sha1_encode((unsigned char *) "");
	char *expect1 = "da39a3ee5e6b4b0d3255bfef95601890afd80709";
	ASSERT_STR(expect1, result1);
	free(result1);
	
	char *result2 = sha1_encode((unsigned char *) NULL);
	char *expect2 = "da39a3ee5e6b4b0d3255bfef95601890afd80709";
	ASSERT_STR(expect2, result2);
	free(result2);
}
