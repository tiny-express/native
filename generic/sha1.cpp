extern "C" {
#include "../crypto.h"
#include "../string.h"
#include "../general.h"
}
#include <iostream>

/**
 * Un-supported type
 *
 * @param T
 * @return
 */
template <typename T> char *sha1(T) {
    return (char*) "\0";
}

/**
 * SHA1 Encode from char pointer
 *
 * @param target
 * @return SHA1 encoded string
 */
template <> char *sha1(char *target) {
    char *result = sha1_encode((unsigned char*)target);
    return result;
}
template char *sha1<char *>(char *target);

/**
 * SHA1 Encode from std::string
 *
 * @param target
 * @return SHA1 encoded string
 */
template <> char *sha1(std::string target) {
    char *result = sha1_encode((unsigned char*)target.c_str());
    return result;
}
template char *sha1<std::string>(std::string target);

/**
 * SHA1 Encode from short
 *
 * @param target
 * @return SHA1 encoded string
 */
template <> char *sha1(short target) {
    char *result = sha1_encode((unsigned char*)string_from_short(target));
    return result;
}
template char *sha1<short>(short target);

/**
 * SHA1 Encode from int
 *
 * @param target
 * @return SHA1 encoded string
 */
template <> char *sha1(int target) {
    char *result = sha1_encode((unsigned char*) string_from_int(target));
    return result;
}
template char *sha1<int>(int target);

/**
 * SHA1 Encode from long
 *
 * @param target
 * @return SHA1 encoded string
 */
template <> char *sha1(long target) {
    char *result = sha1_encode((unsigned char*) string_from_long(target));
    return result;
}
template char *sha1<long>(long target);

/**
 * SHA1 Encode from double
 *
 * @param target
 * @return SHA1 encoded string
 */
template <> char *sha1(double target) {
    char *result = sha1_encode((unsigned char*) string_from_double(target));
    return result;
}
template char *sha1<double>(double target);






