//
// Created by dquang on 4/22/17.
//

#include "../etcd.h"
#include "../network.h"
#include "../string.h"

#define LOCALHOST "http://127.0.0.1"
#define ETCD_PORT ":2379"
#define ETCD_DEVELOPMENT_PATH "v2/keys/elassandra/development/seeds"

char* etcd_get_all_keys() {
    char *headers[2] = {
            "\0"
    };

    char *body[2] = {
            "\0"
    };
    char* response = http_request(GET_METHOD, "http://127.0.0.1:2379/v2/keys", headers, body);
    int response_body_begin_index = string_index(response, "{", 1);
    int response_length =
    return result;
}