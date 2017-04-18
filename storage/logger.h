//
// Created by Tu Cao on 30/10/2016.
//

#ifndef WORKER_LOGGER_H
#define WORKER_LOGGER_H
#include "../builtin.h"

#define LEVEL_INDEX 		0
#define MESSAGE_INDEX         1
#define FILE_INDEX 		2
#define FUNCTION_INDEX 	3
#define LINE_INDEX 		4
#define TIMESTAMP_INDEX       5
#define SCOPE_INDEX           6
#define REQUEST_ID_INDEX      7
#define PROCESS_ORDER_INDEX   8
#define MODE_INDEX            9
#define DATA_LOG_INDEX        10

#define LOG_NGINX       "NGINX"
#define LOG_HANDLER     "HANDLER"
#define LOG_REPOSITORY  "REPOSITORY"
#define LOG_SQL         "SQL"
#define LOG_APP_TEST    "0"

//#define NO_LOG 1 //uncomment this line to disable all log
#ifdef NO_LOG
#define log_debug(context, scope, message, fmt, ...) do {} while (0)
#define log_error(context, scope, message, fmt, ...)  do {} while (0)
#define log_warn(context, scope, message, fmt, ...)  do {} while (0)
#define log_info(context, scope, message, fmt, ...)  do {} while (0)
#define log_fatal(context, scope, message, fmt, ...) do {} while (0)
#else
#define log_debug(context, scope, message, fmt, ...)\
        do { logger_write("%d|%s|%s|%s()|%d|%ld|%s|%s|%s|%d|"\
                fmt, LOG_DEBUG, message, __FILE__, __func__, __LINE__, get_timestamp(), scope\
                , context->logger->request_id, context->logger->process_order, context->mode, ## __VA_ARGS__); } while (0)
#define log_error(context, scope, message, fmt, ...)\
        do { logger_write("%d|%s|%s|%s()|%d|%ld|%s|%s|%s|%d|"\
        	fmt, LOG_ERROR, message, __FILE__, __func__, __LINE__, get_timestamp(), scope\
        	, context->logger->request_id, context->logger->process_order, context->mode, ## __VA_ARGS__); } while (0)
#define log_warn(context, scope, message, fmt, ...)\
        do { logger_write("%d|%s|%s|%s()|%d|%ld|%s|%s|%s|%d|"\
        	fmt, LOG_WARN, message, __FILE__, __func__, __LINE__, get_timestamp(), scope\
        	, context->logger->request_id, context->logger->process_order, context->mode, ## __VA_ARGS__); } while (0)
#define log_info(context, scope, message, fmt, ...)\
        do { logger_write("%d|%s|%s|%s()|%d|%ld|%s|%s|%s|%d|"\
        	fmt, LOG_INFO, message, __FILE__, __func__, __LINE__, get_timestamp(), scope\
        	, context->logger->request_id, context->logger->process_order, context->mode, ## __VA_ARGS__); } while (0)
#define log_fatal(context, scope, message, fmt, ...)\
        do { logger_write("%d|%s|%s|%s()|%d|%ld|%s|%s|%s|%d|"\
                fmt, LOG_FATAL, message, __FILE__, __func__, __LINE__, get_timestamp(), scope\
                , context->logger->request_id, context->logger->process_order, context->mode, ## __VA_ARGS__); } while (0)

// #define log_trace(context, scope, message, fmt, ...)\
//         do { logger_write("%d|%s|%s|%s()|%d|%f|%ld|%s|%s|%s|%d|"\
//                 fmt, LOG_TRACE, message, __FILE__, __func__, __LINE__, getRamUsage(), get_timestamp(), scope\
//                 , context->logger->request_id, context->logger->log_file, context->mode, ## __VA_ARGS__); } while (0)

#endif

void logger_write(const char *fmt, ... );

#endif //WORKER