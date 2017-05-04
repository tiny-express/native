#include "../validator.h"
#include "../general.h"
#include "../string.h"
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>


int match_url(char *url) {

    if (url == NULL || length_pointer_char(url) == 0) {
        return FALSE;
    }

    regex_t exp;
    int convert = regcomp(&exp, URL_PATTERN, REG_EXTENDED);

    if (convert != 0) {
        return FALSE;
    }

    if (regexec(&exp, url, 0, NULL, 0) == 0) {

        return TRUE;
    }

    regfree(&exp);
    return FALSE;
}

int match_email(char *email) {
    if (email == NULL || length_pointer_char(email) == 0) {
        return FALSE;
    }

    regex_t exp;
    int convert = regcomp(&exp, EMAIL_PATTERN, REG_EXTENDED);

    if (convert != 0) {
        return FALSE;
    }


    if (regexec(&exp, email, 0, NULL, 0) == 0) {

        return TRUE;
    }

    regfree(&exp);
    return FALSE;
}

int match_phone_number(char *phone_number) {
    if (phone_number == NULL || length_pointer_char(phone_number) < 7 || length_pointer_char(phone_number) > 15) {
        return FALSE;
    }

    if (string_to_int(string_replace(phone_number, "+", "")) == 0) {
        return FALSE;
    }

    regex_t exp;
    int convert = regcomp(&exp, PHONE_PATTERN, REG_EXTENDED);

    if (convert != 0) {
        return FALSE;
    }

    if (regexec(&exp, phone_number, 0, NULL, 0) == 0) {
        return TRUE;
    }

    regfree(&exp);
    return FALSE;
}
