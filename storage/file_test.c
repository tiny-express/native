//
// Created by coder on 05/04/2017.
//

#include "../../native/builtin.h"
#include "../unit_test.h"

TEST(Builtin_File, FilePutContent){
	char *file_path = "storage/test.txt";
	char *content = "Hello FoodTiny";

	int isSuccess = file_put_content(file_path, content);
	ASSERT_TRUE(isSuccess);
}

TEST(Builtin_File, FileGetContets){
	char *target = "Hello FoodTiny";
	char *content = file_get_contents("storage/test.txt");
	ASSERT_STR(content, target);

	char *content_false = file_get_contents("storage/test_false.txt");
	ASSERT_NOT_EQUAL(content_false, target);
}
