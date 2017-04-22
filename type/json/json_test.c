#include "../../builtin.h"
#include "../../unit_test.h"

TEST(Builtin_Json, JSONEncoding) {
	JSON_Value *root_value = json_value_init_object();
	JSON_Object *root_object = json_value_get_object(root_value);
	char *serialized_string = NULL;
	json_object_set_string(root_object, "name", "John Smith");
	json_object_set_number(root_object, "age", 25);
	json_object_dotset_string(root_object, "address.city", "Cupertino");
	json_object_dotset_value(root_object, "contact.emails", json_parse_string("[\"email@example.com\",\"email2@example.com\"]"));
	serialized_string = json_serialize_to_string_pretty(root_value);
	/*
	 {
	    "name": "John Smith",
	    "age": 25,
	    "address": {
	        "city": "Cupertino"
	    },
	    "contact": {
	        "emails": [
	            "email@example.com",
	            "email2@example.com"
	        ]
	    }
	}
	*/
	ASSERT_STR("{\n"
	   "    \"name\": \"John Smith\",\n"
	   "    \"age\": 25,\n"
	   "    \"address\": {\n"
	   "        \"city\": \"Cupertino\"\n"
	   "    },\n"
	   "    \"contact\": {\n"
	   "        \"emails\": [\n"
	   "            \"email@example.com\",\n"
	   "            \"email2@example.com\"\n"
	   "        ]\n"
	   "    }\n"
	   "}", serialized_string);
	json_free_serialized_string(serialized_string);
	json_value_free(root_value);
}

TEST(Builtin_Json, JSONDecoding) {
	/*
	typedef struct addressType {
		char *city;
	};
	typedef struct contactType {
		char **emails;
	};
	typedef struct jsonType {
		char *name;
		int age;
		struct addressType address;
		struct contactType contact;
	};
	char *json_string = "{\n"
					   "    \"name\": \"John Smith\",\n"
					   "    \"age\": 25,\n"
					   "    \"address\": {\n"
					   "        \"city\": \"Cupertino\"\n"
					   "    },\n"
					   "    \"contact\": {\n"
					   "        \"emails\": [\n"
					   "            \"email@example.com\",\n"
					   "            \"email2@example.com\"\n"
					   "        ]\n"
					   "    }\n"
					   "}";
	JSON_Value *root_value = json_parse_string(json_string);
	JSON_Object *root_object = json_value_get_object(root_value);

	struct addressType addressJSON = {
		.city = json_object_dotget_string(root_object, "address.city")
	};

	JSON_Array *emailArray = json_object_dotget_array(root_object, "contact.emails");
	char **emailJSONs = (char**) calloc(json_array_get_count(emailArray), sizeof(char*));

	struct contactType contactJSON = {
		.emails = emailJSONs
	};
	struct jsonType json = {
		.name = json_object_get_string(root_object, "name"),
		.address =	addressJSON,
		.age = json_object_get_number(root_object, "age"),
		.contact = contactJSON,
	};*/
}