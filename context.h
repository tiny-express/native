#ifndef BUILTIN_API_H
#define BUILTIN_API_H

#include <stdarg.h>
#ifdef CASSANDRA
#include "cassandra.h"
#endif

/***** APP_MODE ******/
typedef enum {
    APP_TESTING,
    APP_DEVELOPMENT,
	APP_STAGING,
    APP_PRODUCTION
} APP_MODE;

/****** CACHE MODE ********/
typedef struct CACHE {
    char *cache_key;
} CACHE;

/****** LOG MODE **********/
typedef struct LOGGER {
    char *request_id;
	char *process_order;
} LOGGER;

typedef struct BUILD {
	char *version;
	char *branch;
	char *message;
	char *time;
} BUILD;

typedef struct DatabaseConfig {
	char *username;
	char *host;
	char *password;
	int port;
	char *database;
} DatabaseConfig;

typedef struct CONFIG {
	DatabaseConfig *databaseConfig;
} CONFIG;

#ifdef CASSANDRA
typedef struct DATABASE {
	CassCluster* cluster;
	CassSession* session;
} DATABASE;
#endif

typedef struct Context {
	BUILD *build;
	APP_MODE mode;
	LOGGER *logger;
	CACHE *cache;
	CONFIG *config;
#ifdef CASSANDRA
    DATABASE *database;
#endif
} Context;

Context *createRequestContext(Context *context);
Context* mockContext();
CONFIG *getRemoteConfig();
void freeContext(Context *context);
char *findParam(char *name, char *params);
char *findParamFromUrl(char *name, char *url);
#endif