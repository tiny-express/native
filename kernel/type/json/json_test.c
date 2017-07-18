/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "../../type.h"
#include "../../test.h"

TEST(Type, JsonSerialize) {
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

//TEST(Type, JsonUnserialize) {
//	typedef struct jsonType {
//		char *name;
//		int age;
//		struct addressType {
//			char *city;
//		} *address;
//		struct contactType {
//			char **emails;
//		} *contact;
//	};
//	char *json_string = "{\n"
//					   "    \"name\": \"John Smith\",\n"
//					   "    \"age\": 25,\n"
//					   "    \"address\": {\n"
//					   "        \"city\": \"Cupertino\"\n"
//					   "    },\n"
//					   "    \"contact\": {\n"
//					   "        \"emails\": [\n"
//					   "            \"email@example.com\",\n"
//					   "            \"email2@example.com\"\n"
//					   "        ]\n"
//					   "    }\n"
//					   "}";
//	JSON_Value *root_value = json_parse_string(json_string);
//	JSON_Object *root_object = json_value_get_object(root_value);
//
//	struct addressType addressJSON = {
//		.city = json_object_dotget_string(root_object, (char*) "address.city")
//	};
//
//    JSON_Array *emails = json_object_dotget_array(root_object, (char*) "contact.emails");
//    int lengthEmails = json_array_get_count(emails);
//    ASSERT_EQUAL(2, lengthEmails);
//
//    char **emailJSONs = (char**) calloc(lengthEmails + 1, sizeof(char*));
//    register int i=0;
//    for (i=0; i<lengthEmails; i++) {
//        JSON_Value *obj = json_array_get_value(emails, i);
//        emailJSONs[i] = json_value_get_string(obj);
//    }
//
//    struct contactType contactJSONs = {
//		.emails = emailJSONs,
//	};
//
//	struct jsonType json = {
//		.name = json_object_get_string(root_object, "name"),
//		.address =	addressJSON,
//		.age = json_object_get_number(root_object, "age"),
//		.contact = contactJSONs,
//	};
//
//	ASSERT_EQUAL(25, json.age);
//	ASSERT_STR("John Smith", json.name);
//	ASSERT_STR("Cupertino", json.address.city);
//    ASSERT_EQUAL(2, length_pointer_pointer_char(json.contact.emails));
//    ASSERT_STR("email@example.com", json.contact.emails[0]);
//    ASSERT_STR("email2@example.com", json.contact.emails[1]);
//}