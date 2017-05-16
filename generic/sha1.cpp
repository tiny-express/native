extern "C" {
#include "../crypto.h"
#include "../string.h"
#include "../general.h"
}

#include <iostream>
/**
 * Un-supported type
 * @tparam T
 * @return
 */
template <typename T> char *sha1Encode(T) {
    return (char*) "\0";
}

/**
 *
 * @param Pointer char
 * @return Pointer char sha1 encoded string
 */
template <> char *sha1Encode(char *target) {
    char *result = sha1_encode((unsigned char*)target);
    return result;
}
template char *sha1Encode<char *>(char *target);

/**
 *
 * @param String
 * @return Pointer char sha1 encoded string
 */
template <> char *sha1Encode(std::string target) {
    char *result = sha1_encode((unsigned char*)target.c_str());
    return result;
}
template char *sha1Encode<std::string>(std::string target);

/**
 *
 * @param Int number
 * @return Pointer char sha1 encoded int number
 */
template <> char *sha1Encode(int target) {
    char *result = sha1_encode((unsigned char*)string_from_int(target));
    return result;
}
template char *sha1Encode<int>(int target);

/**
 *
 * @param Long number
 * @return Pointer char sha1 encoded long number
 */
template <> char *sha1Encode(long target) {
    char *result = sha1_encode((unsigned char*)string_from_long(target));
    return result;
}
template char *sha1Encode<long>(long target);

/**
 *
 * @param Double number
 * @return Pointer char sha1 encoded double number
 */
template <> char *sha1Encode(double target) {
    char *result = sha1_encode((unsigned char*)string_from_double(target));
    return result;
}
template char *sha1Encode<double>(double target);






