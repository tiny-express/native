#ifndef BUILTIN_NETWORK_H
#define BUILTIN_NETWORK_H

char *getIPAddress();
char *http_schema(char *url);
char *http_hostname(char *url);
int   http_port(char *url);
char *http_query(char *url);
char *http_request(char *url, char *data, char *headers);

#endif
