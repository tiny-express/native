#ifndef VENDOR_ELASTICSEARCH_H
#define VENDOR_ELASTICSEARCH_H

char *etcd_get(char* host, char *key);
char *etcd_set(char* host, char *key, char* value);

char *es_query(char *host, char *index, char *query);

#endif
