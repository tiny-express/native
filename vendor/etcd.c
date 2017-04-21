#include "../network.h"
#include "../string.h"
#include "../general.h"
#include "../vendor.h"

/**
 * get node
 * @param host
 * @param key
 * @return json
 */
char *etcd_get(char* url, char *key) {
    char *url_components[3] = {
       url,
       "/v2/keys",
       key,
    };
    url = join_pointer_pointer_char(url_components);
    char *headers[2] = {"\0"};
    char *body[2] = {"\0"};
    char* response = http_request("GET", url, headers, body);
    int response_body_begin_index = string_index(response, "{", 1);
    int response_length = length_pointer_char(response);
    char* result = string_from_to(response, response_body_begin_index, response_length - 2);
    return result;
}

/**
 * set value of node
 * @param host
 * @param key
 * @param value
 * @return json
 */
char *etcd_set(char *url, char *key, char *value) {
    key = string_concat("/v2/keys", key);
    if (string_index(key, "/", 1) >= 0) {
        url = string_concat(url, key);
    } else {
        url = string_concat(url, "/");
        url = string_concat(url, key);
    }

    char *header[2] = {
            "Content-Type: application/x-www-form-urlencoded",
            '\0'
    };

    char *body_message = "value=";
    body_message = string_concat(body_message, value);
    char *body[2] = {
            body_message,
            '\0'
    };

    char* response = http_request("PUT", url, header, body);
    int response_body_begin_index = string_index(response, "{", 1);
    int response_length = length_pointer_char(response);
    char* result = string_from_to(
            response,
            response_body_begin_index,
            response_length - 2);
    return result;
}
