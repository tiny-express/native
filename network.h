#ifndef BUILTIN_NETWORK_H
#define BUILTIN_NETWORK_H

#define HTTPS "https://"
#define HTTP "http://"
#define LOCALHOST "localhost"
#define HTTP_PORT 80
#define HTTPS_PORT 443
#define IS_HTTPS 1
#define IS_HTTP 2
#define NOT_URL 0

char *get_ip_address();
char *http_schema(char *url);
char *http_hostname(char *url);
int   http_port(char *url);
char *http_query(char *url);
char *http_request(char *method, char* url, char **headers, char **body);
char *http_path(char *url);

#endif
