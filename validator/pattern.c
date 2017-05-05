#include "../validator.h"
#include "../general.h"
#include "../string.h"
#include <stdio.h>
#include <regex.h>

#define IS(TYPE, PATTERN);\
inline int is_##TYPE(char* input) {\
    if (input == NULL || length_pointer_char(input) == 0) return FALSE;\
    regex_t exp;\
    int convert = regcomp(&exp, PATTERN, REG_EXTENDED);\
    if (convert != 0) return FALSE;\
    if (regexec(&exp, input, 0, NULL, 0) == 0) return TRUE;\
    regfree(&exp);\
    return FALSE;\
}

IS(url, URL_PATTERN);
IS(phone_number, PHONE_PATTERN);
IS(email, EMAIL_PATTERN);

