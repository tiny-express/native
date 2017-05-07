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
#include "../general.h"
#include "../builtin.h"
#include "../type.h"

#define STRING_NOT_FOUND -1

/**
 * Send SMS using Twillio Service
 *
 * @param account_id
 * @param account_token
 * @param url
 * @param from
 * @param to
 * @param content
 * @return TRUE if success, else FALSE
 */
int send_sms(
    char* account_id,
    char* account_token,
    char* service_url,
    char* phone_number_from,
    char* phone_number_to,
    char* content) {

    // Check empty string
    if (is_empty(account_id)
        || is_empty(account_token)
            || is_empty(service_url)
                || is_empty(phone_number_from)
                    || is_empty(phone_number_to)
                        || is_empty(content)) {
        return FALSE;
    }

    // Check service url format
    if (!is_url(service_url)) {
        return FALSE;
    }

    // Check phone number
    if (!is_phone_number(phone_number_from) || !is_phone_number(phone_number_to)) {
        return FALSE;
    }

    // TODO: remove hard code and uncomment 3 commands below when base64_encode completed
    char* token = "QUM4NWRkZDg1ZGJkZDRmMDAyYzc5OTY3NmI3YWQyODkxNDo4N2M3NmZmZTAxNTA3OGMxN2U3MDgwZDE5YWY0NmNhZQ==";

    /*
    char* token;
    asprintf(&token, "%s:%s", account_id, account_token);
    token =  base64_encode(token);
    */

    char *phone_number_from_with_prefix = phone_number_from;
    if (string_index(phone_number_from, "+", 1) == STRING_NOT_FOUND) {
        phone_number_from_with_prefix = string_concat("+", phone_number_from);
    }
    // Remove all space from phone number
    phone_number_from_with_prefix = string_replace(phone_number_from_with_prefix, " ", "");

    char *phone_number_to_with_prefix = phone_number_to;
    if (string_index(phone_number_to, "+", 1) == STRING_NOT_FOUND) {
        phone_number_to_with_prefix = string_concat("+", phone_number_to);
    }
    // Remove all space from phone number
    phone_number_to_with_prefix = string_replace(phone_number_to_with_prefix, " ", "");

    char* body_string;
    asprintf(
        &body_string,
        "From=%s&To=%s&Body=%s",
        url_encode(phone_number_from_with_prefix),
        url_encode(phone_number_to_with_prefix),
        url_encode(content)
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
    if (string_index(response, account_id, 1) != STRING_NOT_FOUND) {
        return TRUE;
    }

    return FALSE;
}