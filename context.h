#ifndef BUILTIN_API_H
#define BUILTIN_API_H

#include <stdarg.h>

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
	int process_order;
} LOGGER;

typedef struct BUILD {
	char *version;
	char *branch;
	char *message;
	char *time;
} BUILD;

typedef struct Context {
	BUILD *build;
	APP_MODE mode;
	LOGGER *logger;
	CACHE *cache;
} Context;

Context *createRequestContext(Context *context);
Context* mockContext();
void freeContext(Context *context);
char *findParam(char *name, char *params);
char *findParamFromUrl(char *name, char *url);
#endif