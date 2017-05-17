extern "C" {
#include "../crypto.h"
#include "../string.h"
}
#include <iostream>


/**
 * Un-supported type
 * @param T
 * @return Pointer char '\0'
 */
template <typename T> char *md5(T) {
    return (char*) '\0';
}

/**
 *
 * @param Pointer char
 * @return Pointer char md5 encoded string
 */
template <> char *md5(char *target) {
    char *result = md5_encode((unsigned char*)target);
    return result;
}
template char *md5<char *>(char *target);

/**
 *
 * @param String (C++)
 * @return Pointer char md5 encoded string
 */
template <> char *md5(std::string target) {
    char *result = md5_encode((unsigned char*)target.c_str());
    return result;
}
template char *md5<std::string>(std::string target);

/**
 *
 * @param Int number
 * @return Pointer char md5 encoded string
 */
template <> char *md5(int target) {
    char *result = md5_encode((unsigned char*)string_from_int(target));
    return result;
}
template char *md5<int>(int target);

/**
 *
 * @param Long number
 * @return Pointer char md5 encoded string
 */
template <> char *md5(long target) {
    char *result = md5_encode((unsigned char*)string_from_long(target));
    return result;
}
template char *md5<long>(long target);

/**
 *
 * @param Double number
 * @return Pointer char md5 encoded string
 */
template <> char *md5(double target) {
    char *result = md5_encode((unsigned char*)string_from_double(target));
    return result;
}
template char *md5<double>(double target);

/**
 *
 * @param Short number
 * @return Pointer char md5 encoded string
 */
template <> char *md5(short target) {
    char *result = md5_encode((unsigned char*)string_from_short(target));
    return result;
}
template char *md5<short>(short target);







