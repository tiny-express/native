//
// Created by coder on 05/04/2017.
//

#include "../../native/builtin.h"
#include "../unit_test.h"

TEST(Builtin_File, file_put_content){
	char *file_path = "storage/test.txt";
	char *content = "Hello FoodTiny";
	ASSERT_TRUE(file_put_content(file_path, content));
}

TEST(Builtin_File, file_get_content){
	char *target = "Hello FoodTiny";
	ASSERT_STR(file_get_content("storage/test.txt"), target);
}
