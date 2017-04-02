#ifndef BUILTIN_STORAGE_H
#define BUILTIN_STORAGE_H

#include "context.h"

typedef enum {
    LOG_OFF = 0,    // The highest possible rank and is intended to turn off logging.
    LOG_TRACE,  // Designates finer-grained informational events than the DEBUG.
    LOG_DEBUG,  // Designates fine-grained informational events that are most useful to debug.
    LOG_INFO,   // Designates informational messages that highlight the progress of the application
    LOG_WARN,    // Designates potentially harmful situations
    LOG_ERROR,  // Designates error events that might still allow the application to continue running.
    LOG_FATAL,  // Designates very severe error events that will presumably lead the application to abort.
    LOG_ALL = 7    // All levels including custom levels.
} LOG_MODE;

/****** MYSQL TYPES **********/
typedef struct Rows {
	int status;
    int header_length;
    int length;
	char *message;
	char **headers;
	char ***records;
} Rows;

#define findStringField findField

#define findShortField find_field_short
#define findIntField find_field_int
#define findLongField find_field_long
#define findFloatField find_field_float
#define findDoubleField find_field_double

short find_field_short(char *fieldName, Rows *rows, int position);
int find_field_int(char *fieldName, Rows *rows, int position);
long find_field_long(char *fieldName, Rows *rows, int position);
float find_field_float(char *fieldName, Rows *rows, int position);
double find_field_double(char *fieldName, Rows *rows, int position);

char *findField(char *fieldName, Rows *rows, int position);

Rows* CQL(Context *context, char* rawCQLQuery);
void freeRows(Rows *rows);

void LOG(Context *context, LOG_MODE logMode, char* message);
void LOG_D(Context *context, char* message);
void LOG_S(Context *context, char *format, char* message);

/* SQL result at Repository */
#define HAD_RECORD(rows)    (rows->status == 1 && rows->length > 0)
#define EMPTY(rows)			(rows->status == 1 && rows->length == 0)
#define SUCCESS(rows)       (rows->status == 1)
#define FAIL(rows)          (rows->status == 0)
#define QUERY_SUCCESS       1 // for handler
#define QUERY_FAIL          0 // for handler
#define MOCK_SUCCESS		1 // for testing
#define MOCK_NOT_FOUND		0 // for testing
#define MOCK_FAIL			-1//for testing
#endif