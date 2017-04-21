//
// Created by dquang on 4/22/17.
//

#ifndef BUILTIN_ETCD_H
#define BUILTIN_ETCD_H


#define TRUE "true"
#define FALSE "false"
#define POST_METHOD "POST"
#define GET_METHOD "GET"

/**
 * get all key from etcd
 * @return all key
 */
char* etcd_get_all_keys();

/**
 * get value of key
 * @param key
 * @return value
 */
char* etcd_get(char *key);

/**
 *
 * @param key
 * @param value
 * @return "true" if success, else "false"
 */
char* etcd_set(char *key, char* value);

#endif
