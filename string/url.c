#include "../string.h"
#include "../general.h"

char from_hex(char ch) {
    return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}

char to_hex(char code) {
    static char hex[] = "0123456789abcdef";
    return hex[code & 15];
}

char *url_encode(char *target) {
    char *target_index = target;
    char *result = malloc(length_pointer_char(target) * 3 + 1);
    char *result_index = result;
    while (*target_index) {
        if (isalnum(*target_index) || *target_index == '-' || *target_index == '_' || *target_index == '.' || *target_index == '~')
            *result_index++ = *target_index;
        else if (*target_index == ' ')
            *result_index++ = '+';
        else
            *result_index++ = '%', *result_index++ = to_hex(*target_index >> 4), *result_index++ = to_hex(*target_index & 15);
        target_index++;
    }
    *result_index = '\0';
    return result;
}

char *url_decode(char *target) {
    char *target_index = target;
    char *result = malloc(length_pointer_char(target) + 1);
    char *result_index = result;
    while (*target_index) {
        if (*target_index == '%') {
            if (target_index[1] && target_index[2]) {
                *result_index++ = from_hex(target_index[1]) << 4 | from_hex(target_index[2]);
                target_index += 2;
            }
        } else if (*target_index == '+') {
            *result_index++ = ' ';
        } else {
            *result_index++ = *target_index;
        }
        target_index++;
    }
    *result_index = '\0';
    return result;
}

char *find_param(char *name, char *params) {
    if (strcmp(params, "") == 0) {
        return "";
    }
    char **query_pairs = string_split(params, "&");
    int length_pairs = length_pointer_pointer_char(query_pairs);
    register int i;
    for (i=0; i < length_pairs; i++) {
        char **pair = string_split(query_pairs[i], "=");
        if (length_pointer_pointer_char(pair) == 2) {
            if (strcmp(pair[0], name) == 0) {
                char *result = malloc(sizeof(char));
                result = pair[1];
                free(pair);
                free(query_pairs);
                return result;
            }
        }
        free(pair);
    }
    free(query_pairs);
    return "";
}

char *find_param_from_url(char *name, char *url) {
    char **url_components = string_split(url, "?");
    if (length_pointer_pointer_char(url_components) < 2) {
        return "";
    }
    char *query_url = url_components[1];
    char **query_pairs = string_split(query_url, "&");
    int length_pairs = length_pointer_pointer_char(query_pairs);
    register int i;
    for (i=0; i < length_pairs; i++) {
        char **pair = string_split(query_pairs[i], "=");
        if (length_pointer_pointer_char(pair) == 2) {
            if (strcmp(pair[0], name) == 0) {
                char *result = malloc(sizeof(char));
                result = pair[1];
                free(pair);
                free(url_components);
                free(query_url);
                free(query_pairs);
                return result;
            }
        }
        free(pair);
    }
    free(query_url);
    free(url_components);
    free(query_pairs);
    return "";
}