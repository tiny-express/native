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

#include "../vendor.h"
#include "../network.h"
#include "../string.h"
#include "../builtin.h"

#define BODY_FORMAT \
             "{\"personalizations\":"\
                     "[{\"to\": [{\"email\": \"%s\"}],"\
                     "\"subject\": \"%s\"}],"\
                     "\"from\":"\
                     "{\"email\": \"%s\"},"\
                     "\"content\":"\
                     "[{\"type\": \"text/plain\",\"value\": \"%s\"}]}"

#define GRID_URL            "https://api.sendgrid.com/v3/mail/send"
#define GRID_STAGING_TOKEN  "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"

int send_mail(char *from_email, char *to_email, char *subject, char *content ) {
    if (NULL == from_email              || NULL == to_email
        || NULL == subject              || NULL == content
        || strcmp(from_email, "") == 0  || strcmp(to_email, "") == 0
        || strcmp(subject, "")    == 0  || strcmp(content, "")  == 0 ) {
        return 0;
    }

    char *body[2];
    asprintf(&body[0], BODY_FORMAT, to_email, subject, from_email, content);
    body[1] = '\0';

    char *header[3] = {
            string_concat("Authorization: Bearer ", GRID_STAGING_TOKEN),
            "Content-Type: application/json",
            '\0'
    };

    http_request("POST", GRID_URL, header, body);
    return 1;
}