extern "C" {
#include "../crypto.h"
#include "../string.h"
#include "../general.h"
}
#include <iostream>


/**
 * Un-supported type
 * @param T
 * @return
 */
template <typename T> char *sha1(T) {
    return (char*) "\0";
}

/**
 *
 * @param Pointer char
 * @return Pointer char sha1 encoded string
 */
template <> char *sha1(char *target) {
    char *result = sha1_encode((unsigned char*)target);
    return result;
}
template char *sha1<char *>(char *target);

/**
 *
 * @param String (C++)
 * @return Pointer char sha1 encoded string
 */
template <> char *sha1(std::string target) {
    char *result = sha1_encode((unsigned char*)target.c_str());
    return result;
}
template char *sha1<std::string>(std::string target);

/**
 *
 * @param Int number
 * @return Pointer char sha1 encoded string
 */
template <> char *sha1(int target) {
    char *result = sha1_encode((unsigned char*)string_from_int(target));
    return result;
}
template char *sha1<int>(int target);

/**
 *
 * @param Long number
 * @return Pointer char sha1 encoded string
 */
template <> char *sha1(long target) {
    char *result = sha1_encode((unsigned char*)string_from_long(target));
    return result;
}
template char *sha1<long>(long target);

/**
 *
 * @param Double number
 * @return Pointer char sha1 encoded string
 */
template <> char *sha1(double target) {
    char *result = sha1_encode((unsigned char*)string_from_double(target));
    return result;
}
template char *sha1<double>(double target);

/**
 *
 * @param Short number
 * @return Pointer char sha1 encoded string
 */
template <> char *sha1(short target) {
    char *result = sha1_encode((unsigned char*)string_from_short(target));
    return result;
}
template char *sha1<short>(short target);






