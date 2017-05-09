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
#include "../type.h"

#define STRING_NOT_FOUND        -1
#define TWILIO_RESPONSE_SUCCESS "201 CREATED"
/**
 * Send mail via Twillio service
 *
 * @param account_id
 * @param account_token
 * @param url
 * @param from
 * @param to
 * @param content
 * @return TRUE | FALSE
 */
int send_sms(
    char* service_url,
    char* account_id,
    char* account_token,
    char* from_phone_number,
    char* to_phone_number,
    char* sms_content) {

    // NULL value or empty string can not be accepted
    if (is_empty(service_url)
            ||is_empty(account_id)
                || is_empty(account_token)
                    || is_empty(from_phone_number)
                        || is_empty(to_phone_number)
                            || is_empty(sms_content)) {
        return FALSE;
    }

    // Check service url format
    if (!is_url(service_url)) {
        return FALSE;
    }

    // Check phone number
    if (!is_phone_number(from_phone_number) || !is_phone_number(to_phone_number)) {
        return FALSE;
    }

    // TODO: remove hard code and uncomment 3 commands below when base64_encode completed
    char* token = "QUM4NWRkZDg1ZGJkZDRmMDAyYzc5OTY3NmI3YWQyODkxNDo4N2M3NmZmZTAxNTA3OGMxN2U3MDgwZDE5YWY0NmNhZQ==";

    /*
    char* token;
    asprintf(&token, "%s:%s", account_id, account_token);
    token =  base64_encode(token);
    */

    char *from_phone_number_with_prefix = from_phone_number;
    if (string_index(from_phone_number, "+", 1) == STRING_NOT_FOUND) {
        from_phone_number_with_prefix = string_concat("+", from_phone_number);
    }
    // Remove all space from 'from phone number'
    from_phone_number_with_prefix = string_replace(from_phone_number_with_prefix, " ", "");

    char *to_phone_number_with_prefix = to_phone_number;
    if (string_index(to_phone_number, "+", 1) == STRING_NOT_FOUND) {
        to_phone_number_with_prefix = string_concat("+", to_phone_number);
    }

    // Remove all spaces from 'to phone number'
    to_phone_number_with_prefix = string_replace(to_phone_number_with_prefix, " ", "");

    char* body_string;
    asprintf(
        &body_string,
        "From=%s&To=%s&Body=%s",
        url_encode(from_phone_number_with_prefix),
        url_encode(to_phone_number_with_prefix),
        url_encode(sms_content)
    );

    char *body[3] = {
        body_string,
        '\0'
    };

    char *headers[3] = {
        "Content-Type: application/x-www-form-urlencoded",
        string_concat("Authorization: Basic ", token),
        '\0'
    };

    char *response = http_request("POST", service_url, headers, body);
    if (string_index(response, TWILIO_RESPONSE_SUCCESS, 1) != STRING_NOT_FOUND) {
        return TRUE;
    }
    return FALSE;
}