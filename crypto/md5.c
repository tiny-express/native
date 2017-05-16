#include "../crypto.h"
#include <openssl/md5.h>
#include "../general.h"
#include "../string.h"

/**
 *
 * @param target
 * @return
 */
char *md5_encode(unsigned char *target) {
    unsigned char digest[16];

    int length_target = length_pointer_char(target);
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, target, strlen(target));
    MD5_Final(digest, &ctx);

    char mdString[33];
    int index;
    for (index = 0; index < 16; index++) {
        sprintf(&mdString[index * 2], "%02x", (unsigned int) digest[index]);
    }

    char *result = string_copy(mdString);
    return result;
}


unsigned char *md5_decode(const char *target) {
    return NULL;
}
