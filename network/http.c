
#include <stdlib.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include "../general.h"
#include "../string.h"
#include "../network.h"

/**
 *
 * @param url
 * @return 1 if url is HTTPS, 2 if HTTP, else 0
 */
int is_url(char *url) {

    if (url == NULL || length_pointer_char(url) == 0) {
        return NOT_URL;
    }

    if (string_startswith(url, "https://") == 1) {
        return IS_HTTPS;
    }

    if (string_startswith(url, "http://") == 1) {
        return IS_HTTP;
    }

    return NOT_URL;
}

/**
 * Retrieve url schema
 *
 * @param url
 * @return string (https or http)
 */

char *http_schema(char *url) {
    int is_url_result = is_url(url);

    if (is_url_result == 0) {
        return NULL;
    }

    if (is_url_result == 1) {
        return HTTPS;
    }

    return HTTP;
}

/**
 * Retrieve url schema
 *
 * @param url
 * @return string (hostname)
 */

char *http_hostname(char *url) {
    int is_url_result = is_url(url);

    if (is_url_result == 0) {
        return NULL;
    }

	if (string_index(url, "127.0.0.1", 1) != -1) {
		return LOCALHOST;
	}


    int length_url = length_pointer_char(url);
    int begin_position = string_index(url, "://", 1) + 3;
    int end_position = length_url;

    // Find end position to cut, if meet ':', '?' or '/'
    int index = begin_position;
    for (; index < length_url; index++) {
        if (url[index] == ':' || url[index] == '/' || url[index] == '?') {
            end_position = index;
            break;
        }
    }

    char *result = string_from_to(url, begin_position, end_position - 1);
    return result;
}

/**
 * Retrieve url schema
 *
 * @param url
 * @return int
 */
int http_port(char *url) {
    int is_url_result = is_url(url);

    if (is_url_result == 0) {
        return -1;
    }

    int url_length = length_pointer_char(url);
    int prefix_position = string_index(url, "://", 1);
    char* url_without_prefix = string_from_to(url, prefix_position + 3, url_length);
    int url_without_prefix_length = length_pointer_char(url_without_prefix);
    int port_index_begin = string_index(url_without_prefix, ":", 1) + 1;
    int port_index_end = string_index(url_without_prefix, "/", 1) - 1;
    if (port_index_end < 0) {
        port_index_end = url_without_prefix_length - 1;
    }
    char* port_string = string_from_to(url_without_prefix, port_index_begin, port_index_end);
    int port = string_to_int(port_string);
    printf("port string - port_int: %s - %d\n", port_string, port);
    if (port == 0) {
        if (is_url_result == IS_HTTPS)
            return HTTPS_PORT;
        return HTTP_PORT;
    }
    return port;
}

/**
 * Get query from url
 * Example: http://localhost/index?key1=value1&key2=value2
 * Query will be 'key1=value1&key2=value2'
 * @param url
 * @return string
 */
char *http_query(char *url) {
    int is_url_result = is_url(url);

    if (is_url_result == 0) {
        return NULL;
    }

	int length_url = length_pointer_char(url);
	int begin_position = string_index(url, "?", 1) + 1;

    if (begin_position == 0) {
        return "";
    }

	int end_position = begin_position;

	for (end_position; end_position < length_url; end_position++) {
		if (url[end_position] == '/' || url[end_position] == ':') {
			break;
		}
	}

    char *result = string_from_to(url, begin_position, end_position - 1);
    return result;
}

/**
 * return paht of URL if paht doesn't exit return "/"
 * @param url
 * @return string path
 */
char *http_path(char *url) {
    int is_url_result = is_url(url);

    if (is_url_result == 0) {
        return NULL;
    }

    int len_url = length_pointer_char(url);
    int begin_pos = string_index(url, "/", 3);
    if (begin_pos == -1) {
        return "/";
    }

    int end_pos = len_url;
    int index;
    for (index = begin_pos; index < len_url; index++) {
        if (url[index] == ':' || url[index] == '?') {
            end_pos = index;
            break;
        }
    }

    char *result = string_from_to(url, begin_pos, end_pos - 1);
    return result;
}

/**
 * Send request to server with data in request body
 * This function can be used in general case with all requests
 *
 * @method GET POST PUT PATCH DELETE HEAD OPTIONS
 * @return string
 */
char *http_request(char *method, char *url, char **headers, char **body) {
    // Parse URL
    int port = http_port(url);
    char *host = http_hostname(url);
    asprintf(&host, "%s:%d", host, port);
    char *path = http_path(url);
    char *schema = http_schema(url);
    int is_https = strcmp(schema, HTTPS) ? 0 : 1;
    int is_get_method = strcmp(method, "GET") ? 0 : 1;

    // Prepare request message
    char *template = 	"%s %s%s%s HTTP/1.1\r\n"
                        "Connection: close\r\n"
                        "Host: %s\r\n"
                        "%s\r\n\r\n"
                        "%s";
    char *header_content = string_join(headers, "\r\n");
    char *body_string = string_join(body, "&");

    if (!is_get_method) {
        int bodySize = length_pointer_char(body_string);
        asprintf(&header_content, "%s%sContent-Length: %d", header_content, length_pointer_char(header_content) > 0?"\r\n":"", bodySize);
    }

    char *request;
    if (is_get_method) {
        asprintf(&request, template,
                 method,
                 path,
                 length_pointer_char(body_string) > 0 ? "?" : "",
                 body_string,
                 host,
                 header_content,
                 "");
    } else {
        asprintf(&request, template,
                 method,
                 path,
                 "",
                 "",
                 host,
                 header_content,
                 body_string);
    }

    BIO * bio;
    SSL * ssl;
    SSL_CTX * ctx;
    char *response = malloc(100000 * sizeof(char));
    int received = 0;

    if (is_https) {
        SSL_library_init();
    }

    ERR_load_BIO_strings();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    if (is_https) {
        const SSL_METHOD *method = TLSv1_2_client_method();	/* SSLv3 but can rollback to v2 */
        if (! method) {
            fprintf(stderr, "SSL client method failed\n");
            return "";
        }

        ctx = SSL_CTX_new(method);
        if (! ctx) {
            fprintf(stderr, "SSL context is NULL\n");
            ERR_print_errors_fp(stderr);
            return "";
        }

        /* Setup the connection */
        bio = BIO_new_ssl_connect(ctx);

        /* Set the SSL_MODE_AUTO_RETRY flag */
        BIO_get_ssl(bio, &ssl);
        SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);

        /* Create and setup the connection */
        BIO_set_conn_hostname(bio, host);

        if(BIO_do_connect(bio) <= 0) {
            fprintf(stderr, "Error attempting to connect\n");
            ERR_print_errors_fp(stderr);
            printf("%s\n", ERR_error_string(ERR_get_error(), NULL));
            BIO_free_all(bio);
            SSL_CTX_free(ctx);
            return "";
        }
    } else {
        bio = BIO_new_connect(host);
        if(bio == NULL) {
            fprintf(stderr, "BIO is null\n");
            return "";
        }

        if(BIO_do_connect(bio) <= 0) {
            ERR_print_errors_fp(stderr);
            BIO_free_all(bio);
            return "";
        }
    }

    /* Send the request */
    BIO_write(bio, request, length_pointer_char(request));

    /* Read in the response */
    int bytes;
    for(;;) {
        bytes = BIO_read(bio, response + received, 1023);
        if(bytes < 0) {
            printf("ERROR received");
            return "";
        }
        if (bytes == 0) {
            break;
        }
        received += bytes;
    }
    /* Close the connection and free the context */
    BIO_free_all(bio);
    if (is_https) {
        SSL_CTX_free(ctx);
    }
    free(request);
    return response;
}
