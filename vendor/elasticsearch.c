#include "../network.h"
#include "../vendor.h"

char *es_query(char *host, char *index, char *query) {
    char *headers[2] = {
            "Content-Type: application/json",
            '\0'
    };

    char *body[2] = {
            query,
            '\0'
    };
    char *url;
    asprintf(&url, "http://%s:9200/%s/_search?pretty", host, index);
    return http_request("POST", url, headers, body);
}