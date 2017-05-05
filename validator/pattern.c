/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <regex.h>
#include "../validator.h"
#include "../general.h"
#include "../string.h"
#include "../type.h"


int is_url(char *url) {

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

int is_email(char *email) {
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

int is_phone_number(char *phone_number) {
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
