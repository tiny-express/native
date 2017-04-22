//
// Created by dquang on 4/22/17.
//

#include "../etcd.h"
#include "../network.h"
#include "../string.h"
#include "../general.h"

char *get_etcd_url(char *host);

/**
 * get all nodes from etcd
 * @param host
 * @return json
 */
char* etcd_get_all_node(char *host) {

    if (length_pointer_char(host) == 0) {
        return "";
    }

    char *headers[2] = {
            "\0"
    };

    char *body[2] = {
            "\0"
    };
    char *url = get_etcd_url(host);
    char* response = http_request(GET_METHOD, url, headers, body);
    int response_body_begin_index = string_index(response, "{", 1);
    int response_length = length_pointer_char(response);
    char* result = string_from_to(response, response_body_begin_index, response_length - 2);
    return result;
}

/**
 * get node
 * @param host
 * @param key
 * @return json
 */
char *etcd_get(char* host, char *key) {
    char *headers[2] = {
            "\0"
    };

    char *body[2] = {
            "\0"
    };
    char *url = get_etcd_url(host);
    if (string_char_in_string(key, '/')) {
        url = string_concat(url, key);
    } else {
        url = string_concat(url, "/");
        url = string_concat(url, key);
    }
    char* response = http_request(GET_METHOD, url, headers, body);
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
char *etcd_set(char *host, char *key, char *value) {

    if (length_pointer_char(host) == 0 ||
            length_pointer_char(key) == 0 ||
            length_pointer_char(value) == 0) {
        return "";
    }

    char *url = get_etcd_url(host);
    if (string_char_in_string(key, '/')) {
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
            response_length - 2
    );
    return result;
}

/**
 * get url of request
 * @param host (consist of port, example: http://localhost:80/etcd/)
 * @return host + path
 */
char *get_etcd_url(char *host) {
    char* url = "";
    url = string_concat(url, host);
    url = string_concat(url, ETCD_DEVELOPMENT_PATH);
    return url;
}