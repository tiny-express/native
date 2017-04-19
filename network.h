#ifndef BUILTIN_NETWORK_H
#define BUILTIN_NETWORK_H

#define HTTPS "https"
#define HTTP "http"
#define LOCALHOST "localhost"
#define LENGHT_OF_HTTP 7
#define LENGHT_OF_HTTPS 8
#define HTTP_PORT 80
#define HTTPS_PORT 443


char *getIPAddress();
char *http_schema(char *url);
char *http_hostname(char *url);
int   http_port(char *url);
char *http_query(char *url);
char *http_request(char *method, char* url, char **headers, char **body);

#endif
