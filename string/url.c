#include "../string.h"
#include "../general.h"

char from_hex(char ch) {
    return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}

char to_hex(char code) {
    static char hex[] = "0123456789abcdef";
    return hex[code & 15];
}

char *url_encode(char *target) {
    char *targetIndex = target;
    char *result = malloc(length_pointer_char(target) * 3 + 1);
    char *resultIndex = result;
    while (*targetIndex) {
        if (isalnum(*targetIndex) || *targetIndex == '-' || *targetIndex == '_' || *targetIndex == '.' || *targetIndex == '~')
            *resultIndex++ = *targetIndex;
        else if (*targetIndex == ' ')
            *resultIndex++ = '+';
        else
            *resultIndex++ = '%', *resultIndex++ = to_hex(*targetIndex >> 4), *resultIndex++ = to_hex(*targetIndex & 15);
        targetIndex++;
    }
    *resultIndex = '\0';
    return result;
}

char *url_decode(char *target) {
    char *targetIndex = target;
    char *result = malloc(length_pointer_char(target) + 1);
    char *resultIndex = result;
    while (*targetIndex) {
        if (*targetIndex == '%') {
            if (targetIndex[1] && targetIndex[2]) {
                *resultIndex++ = from_hex(targetIndex[1]) << 4 | from_hex(targetIndex[2]);
                targetIndex += 2;
            }
        } else if (*targetIndex == '+') {
            *resultIndex++ = ' ';
        } else {
            *resultIndex++ = *targetIndex;
        }
        targetIndex++;
    }
    *resultIndex = '\0';
    return result;
}
