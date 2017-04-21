//
// Created by dquang on 4/22/17.
//

#ifndef BUILTIN_ETCD_H
#define BUILTIN_ETCD_H

#define POST_METHOD "POST"
#define GET_METHOD "GET"
#define ETCD_LOCALHOST "http://127.0.0.1:2379"
#define ETCD_MASTER "http://etcd.foodtiny.net:80"
#define ETCD_DEVELOPMENT_PATH "/v2/keys/elassandra/development/seeds"

/**
 * get all nodes from etcd
 * @param host
 * @return json
 */
char* etcd_get_all_node(char *host);

/**
 * get node
 * @param host
 * @param key
 * @return json
 */
char* etcd_get(char* host, char *key);

/**
 * set value of node
 * @param host
 * @param key
 * @param value
 * @return json
 */
char* etcd_set(char* host, char *key, char *value);

#endif
