#ifndef BUILTIN_CONTEXT_H
#define BUILTIN_CONTEXT_H

#include "../type/json.h"
#include "../string.h"

char *ERROR(int code, char *message) {
	JSON_Value *root_value = json_value_init_object();
	JSON_Object *root_object = json_value_get_object(root_value);
	json_object_dotset_number(root_object, "code", code);
	json_object_dotset_string(root_object, "message", message);
	char *serialized_string = json_serialize_to_string_pretty(root_value);
	json_value_free(root_value);
	return serialized_string;
}

char *ERROR_API(char *target, char *message) {
	JSON_Value *root_value = json_value_init_object();
	JSON_Object *root_object = json_value_get_object(root_value);
	char **buffer_split = string_split(message, "|");
	int error_code 		= StringToInt(buffer_split[0]);
	char *error_message;
	asprintf(&error_message, "%s%s\0", target, buffer_split[1]);
	json_object_dotset_number(root_object, "code", error_code);
	json_object_dotset_string(root_object, "message", error_message);
	char *serialized_string = json_serialize_to_string_pretty(root_value);
	json_value_free(root_value);
    free(buffer_split);
	free(error_message);
	return serialized_string;
}

#endif