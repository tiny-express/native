#include "../crypto.h"
#include <openssl/sha.h>
#include "../common.h"
#include "../string.h"

/**
 * SHA1 Encode
 *
 * @param target
 * @return sha1 string
 */
char *sha1_encode(unsigned char *target) {
	
	int length_target = length_pointer_char((char *) target);
	unsigned char digest[SHA_DIGEST_LENGTH];
	
	SHA_CTX ctx;
	SHA1_Init(&ctx);
	SHA1_Update(&ctx, target, (size_t) length_target);
	SHA1_Final(digest, &ctx);
	
	char mdString[SHA_DIGEST_LENGTH * 2 + 1];
	int index;
	for (index = 0; index < SHA_DIGEST_LENGTH; ++index) {
		sprintf(&mdString[ index * 2 ], "%02x", (unsigned int) digest[ index ]);
	}
	
	char *result = strdup(mdString);
	return result;
}
