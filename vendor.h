#ifndef BUILTIN_VENDOR_H
#define BUILTIN_VENDOR_H

#define POST_METHOD "POST"
#define GET_METHOD "GET"
#define ETCD_LOCALHOST "http://127.0.0.1:2379"
#define ETCD_MASTER "http://etcd.foodtiny.net:80"
#define ETCD_DEVELOPMENT_PATH "/v2/keys/elassandra/development/seeds"

char* etcd_get_all_node(char *host);

char* etcd_get(char* host, char *key);

char* etcd_set(char* host, char *key, char *value);

char *search(char *host, char *index, char *query);

char *es_query(char *host, char *index, char *query);

int send_sms(char* from, char* to, char* content);

#endif
