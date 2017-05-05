// TODO - Twilio Service
#include "../vendor.h"
#include "../network.h"
#include "../string.h"
#include "../general.h"
#include "../builtin.h"

#define STRING_NOT_FOUND -1
#define TRUE 1
#define FALSE 0

/**
 * Send SMS by using Twilio's SMS Service
 * @param account_id
 * @param account_token
 * @param url
 * @param from
 * @param to
 * @param content
 * @return TRUE if success, else FALSE
 */
int send_sms(char* account_id, char* account_token, char* url, char* from, char* to, char* content) {

    if (content == NULL || length_pointer_char(content) == 0) {
        return FALSE;
    }

    if (!(is_phone_number(to)&& is_phone_number(from))) {
        return FALSE;
    }

    // TODO: remove hard code and uncomment 3 commands below when base64_encode completed
    char* token = "QUM4NWRkZDg1ZGJkZDRmMDAyYzc5OTY3NmI3YWQyODkxNDo4N2M3NmZmZTAxNTA3OGMxN2U3MDgwZDE5YWY0NmNhZQ==";
//    char* token;
//    asprintf(&token, "%s:%s", account_id, account_token);
//    token =  base64_encode(token);

    char* from_with_prefix = (string_index(from, "+", 1) == STRING_NOT_FOUND)? string_concat("+", from) : from;
    char* to_with_prefix = (string_index(to, "+", 1) == STRING_NOT_FOUND)? string_concat("+", to) : to;
    from_with_prefix = string_replace(from_with_prefix, " ", "");
    to_with_prefix = string_replace(to_with_prefix, " ", "");
    char* body_string;
    asprintf(
            &body_string,
             "From=%s&To=%s&Body=%s",
             url_encode(from_with_prefix),
             url_encode(to_with_prefix),
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

    char *response = http_request("POST", url, headers, body);
    if (string_index(response, account_id, 1) != STRING_NOT_FOUND) {
        return TRUE;
    }
    return FALSE;
}