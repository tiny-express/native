#include "../validator.h"
#include "../general.h"
#include <stdlib.h>
#include <stdio.h>
#include <regex.h>


int match_url(char *url) {

    if (url == NULL || length_pointer_char(url) == 0) {
        return 0;
    }

    regex_t exp;
    int convert = regcomp(&exp, URL_PATTERN, REG_EXTENDED);

    if (convert != 0) {
        printf("CAN'T CONVERT\n");
        return 0;
    }

    if (regexec(&exp, url, 0, NULL, 0) == 0) {

        return 1;
    }

    regfree(&exp);
    return 0;
}

int match_email(char *email) {
    if (email == NULL || length_pointer_char(email) == 0) {
        return 0;
    }
    regex_t exp;
    int convert = regcomp(&exp, EMAIL_PATTERN, REG_EXTENDED);

    if (convert != 0) {
        printf("CAN'T CONVERT\n");
        return 0;
    }

    if (regexec(&exp, email, 0, NULL, 0) == 0) {

        return 1;
    }

    regfree(&exp);
    return 0;
}

int match_phone_number(char *phone_number) {
    if (phone_number == NULL || length_pointer_char(phone_number) < 10 || length_pointer_char(phone_number) > 11) {
        return 0;
    }
    regex_t exp;
    int convert = regcomp(&exp, PHONE_PATTERN, REG_EXTENDED);

    if (convert != 0) {
        printf("CAN'T CONVERT\n");
        return 0;
    }

    if (regexec(&exp, phone_number, 0, NULL, 0) == 0) {

        return 1;
    }

    regfree(&exp);
    return 0;
}
