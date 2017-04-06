#ifdef CASSANDRA
#include "../builtin.h"

#define FIND_FIELD(TYPE); \
TYPE find_field_##TYPE(char *fieldName, Rows *rows, int position) { \
    return string_to_##TYPE(findField(fieldName, rows, position)); \
}

Rows *ERROR_ROWS(Rows *rows, char *errMsg) {
    rows->status = 0;
    rows->message = errMsg;
    rows->header_length = 0;
    rows->headers = NULL;
    rows->length = 0;
    rows->records = NULL;
    return rows;
}

int initCassandraConnection(Context *context) {
    context->database = malloc(sizeof(DATABASE));
    context->database->cluster = cass_cluster_new();
    context->database->session = cass_session_new();
    cass_cluster_set_contact_points(context->database->cluster, context->config->databaseConfig->host);
    cass_cluster_set_credentials(context->database->cluster,
                                 context->config->databaseConfig->username,
                                 context->config->databaseConfig->password
    );

    CassFuture* future = cass_session_connect_keyspace(context->database->session,
                                                       context->database->cluster,
                                                       context->config->databaseConfig->database
    );
    cass_future_wait(future);
    if (cass_future_error_code(future) != CASS_OK) {
        char *message;
        size_t len;
        cass_future_error_message(future, &message, &len);
        log_fatal(context, LOG_SQL, "cass_session_connect failed", "{error:%s}", message);
        return 0;
    }
    cass_future_free(future);
    log_debug(context, LOG_SQL, "Cassandra connected", "");
    return 1;
}

void getHeaders(Rows *rows, const CassResult* result) {
    rows->header_length = cass_result_column_count(result);
    char **headers = calloc(rows->header_length + 1, sizeof(char *));
    size_t header_length;
    char *header;
    int i;
    for (i = 0; i < rows->header_length; i++) {
        cass_result_column_name(result, i, &header, &header_length);
        headers[i] = calloc((header_length + 1), sizeof(char));
        memcpy(headers[i], header, header_length);
    }
    rows->headers = headers;
}

void getRecords(Rows *rows, const CassResult* result) {
    rows->length = cass_result_row_count(result);
    char ***records = calloc(rows->length + 1, sizeof(char **));

    int count = 0;
    int i;
    CassIterator* resultRows = cass_iterator_from_result(result);
    while (cass_iterator_next(resultRows)) {
        records[count] = calloc(rows->header_length + 1, sizeof(char *));
        const CassRow* resultRow = cass_iterator_get_row(resultRows);
        for (i = 0; i < rows->header_length; i++) {
            const CassValue* value = cass_row_get_column_by_name(resultRow, rows->headers[i]);
            switch (cass_value_type(value)) {
                case CASS_VALUE_TYPE_TIMEUUID: {
                    CassUuid cassUuid;
                    if (cass_value_get_uuid(value, &cassUuid) == CASS_ERROR_LIB_NULL_VALUE) {
                        records[count][i] = "\0";
                    } else {
                        records[count][i] = malloc(CASS_UUID_STRING_LENGTH);
                        cass_uuid_string(cassUuid, records[count][i]);
                    }
                    break;
                }

                case CASS_VALUE_TYPE_VARCHAR: {
                    size_t data_len;
                    char *data;
                    if (cass_value_get_string(value, &data, &data_len) == CASS_ERROR_LIB_NULL_VALUE) {
                        records[count][i] = "\0";
                    } else {
                        records[count][i] = malloc(((int)data_len + 1) * sizeof(char));
                        memcpy(records[count][i], data, (int)data_len);
                        records[count][i][data_len] = '\0';
                    }
                    break;
                }

                case CASS_VALUE_TYPE_TIMESTAMP: {
                    long long int data;
                    if (cass_value_get_int64(value, &data) == CASS_ERROR_LIB_NULL_VALUE) {
                        records[count][i] = "\0";
                    } else {
                        records[count][i] = string_from_long(data);
                    }
                    break;
                }

                case CASS_VALUE_TYPE_DOUBLE: {
                    double data;
                    if (cass_value_get_double(value, &data) == CASS_ERROR_LIB_NULL_VALUE) {
                        records[count][i] = "\0";
                    } else {
                        records[count][i] = string_from_double(data);
                    }
                    break;
                }

                case CASS_VALUE_TYPE_BOOLEAN: {
                    break;
                }

                case CASS_VALUE_TYPE_INT: {
                    int data;
                    if (cass_value_get_int32(value, &data) == CASS_ERROR_LIB_NULL_VALUE) {
                        records[count][i] = "\0";
                    } else {
                        records[count][i] = string_from_int(data);
                    }
                    break;
                }
            }
        }
        count++;
    }

    cass_iterator_free(resultRows);
    rows->records = records;
}

Rows *CQL(Context *context, char *rawCQLQuery) {
    Rows *rows = malloc(sizeof(Rows));
    rows->status = 1;
    rows->message = "Success";
    rows->header_length = 0;
    rows->headers = NULL;
    rows->length = 0;
    rows->records = NULL;

    if (context->database == NULL) {
        int success = initCassandraConnection(context);
        if (!success) {
            return ERROR_ROWS(rows, "Cannot connect to Cassandra");
        }
    }

    log_debug(context, LOG_SQL, "Cassandra execute query", "%s", rawCQLQuery);
    CassStatement *statement = cass_statement_new(rawCQLQuery, 0);
    CassFuture *resultFuture = cass_session_execute(context->database->session, statement);
    cass_future_wait(resultFuture);

    if (cass_future_error_code(resultFuture) != CASS_OK) {
        char *message;
        size_t len;
        cass_future_error_message(resultFuture, &message, &len);
        log_error(context, LOG_SQL, "cass_session_execute failed", "{error:%s}", message);
        return ERROR_ROWS(rows, "cass_session_execute failed");
    } else {
        const CassResult* result = cass_future_get_result(resultFuture);
        getHeaders(rows, result);
        getRecords(rows, result);
        cass_result_free(result);
        log_debug(context, LOG_SQL, "cass_session_execute success", "");
    }

    cass_statement_free(statement);
    cass_future_free(resultFuture);
    return rows;
}

char *findField(char *fieldName, Rows *rows, int position) {
    if (rows->records == NULL) {
        return "\0";
    }
    char ***records = rows->records;
    char **record = records[position];
    int lengthValue;
    for (int i = 0; i < rows->header_length; i++) {
        if (strcmp(fieldName, rows->headers[i]) == 0) {
            lengthValue = length_pointer_char(record[i]);
            char *fieldValue;
            if (record[i]) {
                fieldValue = malloc((lengthValue + 1) * sizeof(char));
                memcpy(fieldValue, record[i], lengthValue);
                fieldValue[lengthValue] = '\0';
            } else {
                fieldValue = "\0";
            }
            return fieldValue;
        }
    }
    return "\0";
}

void freeRows(Rows *rows) {
    if (rows != NULL) {
        if (rows->headers != NULL) {
            int headerOrder;
            for (headerOrder = 0; headerOrder < rows->header_length; ++headerOrder) {
                free(rows->headers[headerOrder]);
            }
            free(rows->headers);
        }
        if (rows->records != NULL) {
            int recordOrder;
            for (recordOrder = 0; recordOrder < rows->length; ++recordOrder) {
                if (rows->records[recordOrder] != NULL) {
                    int recordColumn;

                    for (recordColumn = 0; recordColumn < rows->header_length; ++recordColumn) {
                        free(rows->records[recordOrder][recordColumn]);
                    }
                    free(rows->records[recordOrder]);
                }
            }
            free(rows->records);
        }
        free(rows);
    }
}

FIND_FIELD(short);
FIND_FIELD(int);
FIND_FIELD(long);
FIND_FIELD(float);
FIND_FIELD(double);

#endif