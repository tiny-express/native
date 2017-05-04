// TODO - Twilio Service
#include <printf.h>
#include <stdio.h>
#include <stdlib.h>
#include "../vendor.h"
#include "../network.h"
#include "../string.h"
#include "../crypto.h"
#include "../general.h"
#include "../builtin.h"

#define STRING_NOT_FOUND -1
#define TRUE 1
#define FALSE 0

char* account_id = "AC85ddd85dbdd4f002c799676b7ad28914";
char* token = "QUM4NWRkZDg1ZGJkZDRmMDAyYzc5OTY3NmI3YWQyODkxNDo4N2M3NmZmZTAxNTA3OGMxN2U3MDgwZDE5YWY0NmNhZQ==";
char* url = "https://api.twilio.com/2010-04-01/Accounts/AC85ddd85dbdd4f002c799676b7ad28914/Messages.json";

/**
 * Send SMS by using Twilio's SMS Service
 * @param from
 * @param to
 * @param content
 * @return TRUE if success, else FALSE
 */
int send_sms(char* from, char* to, char* content) {

    if (content == NULL || length_pointer_char(content) == 0) {
        return FALSE;
    }

    if (!(match_phone_number(to)&&match_phone_number(from))) {
        return FALSE;
    }

    char* from_with_prefix = (string_index(from, "+", 1) == STRING_NOT_FOUND)? string_concat("+", from) : from;
    char* to_with_prefix = (string_index(to, "+", 1) == STRING_NOT_FOUND)? string_concat("+", to) : to;
    char* body_string;
    asprintf(
            &body_string,
             "From=%s&To=%s&Body=%s",
             url_encode(from_with_prefix),
             url_encode(to_with_prefix),
             url_encode(content)
    );

    char *body[1] = {
            body_string,
            '\0'
    };
    char *headers[3] = {
            "Content-Type: application/x-www-form-urlencoded",
            string_concat("Authorization: Basic ", token),
            '\0'
    };

    char *response = http_request("POST", url, headers, body);
    if (string_index(response, account_id, 1) != STRING_NOT_FOUND) {
        return TRUE;
    }
    return FALSE;
}