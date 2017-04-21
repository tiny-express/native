#include <stdio.h>
#include <stdlib.h>
#include "../general.h"
#include "../string.h"
#include "../network.h"
#include "openssl/ssl.h"
#include "openssl/bio.h"
#include "openssl/err.h"

/**
 * Retrieve url schema
 *
 * @param url
 * @return string (https or http)
 */
char *http_schema(char *url) {
	if (length_pointer_char(url) == 0) {
		return NULL;
	}
	if (string_startswith(url, "https://") == 1) {
		return HTTPS;
	} else if (string_startswith(url, "http://") == 1) {
		return HTTP;
	}
	return NULL;
}

/**
 * Retrieve url schema
 *
 * @param url
 * @return string (hostname)
 */
char *http_hostname(char *url) {
	if (length_pointer_char(url) == 0) {
		return NULL;
	}

	if (string_index(url, "127.0.0.1", FIRST_TIMES) != -1) {
		return LOCALHOST;
	} else {
		int firstPos = string_index(url, "://", FIRST_TIMES);
        char *indexUrl = url + sizeof(char) * (firstPos + 3);
        char *result = string_get_substr(indexUrl, 0, ":/?");
        return result;
	}

	return NULL;
}

/**
 * Retrieve url schema
 *
 * @param url
 * @return int
 */
int http_port(char *url) {
    int https_port = string_startswith(url, HTTPS);
    int http_port = string_startswith(url, HTTP);

	if (length_pointer_char(url) == 0 || (http_port == 0 && https_port == 0)) {
		return -1;
	}

    char **element = string_split(url, "/");
    char *result = element[1];

    int indexColon = string_index(result, ":", FIRST_TIMES) + 1;
    char *index = result + sizeof(char) * indexColon;

    int port = atoi(index);
    if (port == 0) {
        return https_port ? HTTPS_PORT : HTTP_PORT;
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
	int length_url = length_pointer_char(url);

	if (length_url == 0) {
		return NULL;
	}

	int first_position = string_index(url, "?", FIRST_TIMES);
	int end_position = first_position;
	int length_target = length_pointer_char(url);
	for (end_position; end_position < length_target; end_position++) {
		if (url[end_position] == '/' || url[end_position] == ':') {
			break;
		}
	}

	if (first_position != -1) {
		return string_from_to(url, first_position + 1, end_position - 1);
	}

	return NULL;
}

/**
 * return paht of URL if paht doesn't exit return "/"
 * @param url
 * @return string path
 */
char *http_path(char *url) {
    int exitHttp = string_startswith(url, HTTP);
    int exitHttps = string_startswith(url, HTTPS);

    if (exitHttp == 0 && exitHttps == 0) {
        return NULL;
    }

    char *index = url + sizeof(char) * (exitHttp ? LENGHT_OF_HTTP : LENGHT_OF_HTTPS);
    int indexOfFirstSlash = string_index(index, "/", FIRST_TIMES);
    char *result = string_get_substr(index, indexOfFirstSlash, ":?");
    if (result == NULL) {
        return "/";
    }
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
    int isHTTPS = strcmp(schema, HTTPS)?0:1;
    int isGetMethod = strcmp(method, "GET")?0:1;

    // Prepare request message
    char *template = 	"%s %s%s%s HTTP/1.1\r\n"
                        "Connection: close\r\n"
                        "Host: %s\r\n"
                        "%s\r\n\r\n"
                        "%s";
    char *headerString = string_join(headers, "\r\n");
    char *bodyString = string_join(body, "&");

    if (!isGetMethod) {
        int bodySize = length_pointer_char(bodyString);
        asprintf(&headerString, "%s%sContent-Length: %d", headerString, length_pointer_char(headerString) > 0?"\r\n":"", bodySize);

    }

    char *request;
    if (isGetMethod) {
        asprintf(&request, template,
                 method,
                 path,
                 length_pointer_char(bodyString) > 0 ? "?" : "",
                 bodyString,
                 host,
                 headerString,
                 "");
    } else {
        asprintf(&request, template,
                 method,
                 path,
                 "",
                 "",
                 host,
                 headerString,
                 bodyString);
    }

    BIO * bio;
    SSL * ssl;
    SSL_CTX * ctx;
    char *response = malloc(100000 * sizeof(char));
    int received = 0;

    if (isHTTPS) {
        SSL_library_init();
    }

    ERR_load_BIO_strings();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    if (isHTTPS) {
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
    if (isHTTPS) {
        SSL_CTX_free(ctx);
    }
    free(request);

    return response;
}
