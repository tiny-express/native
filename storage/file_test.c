#include "../file.h"
#include "../unit_test.h"

TEST(Builtin_File, FilePutContents) {
    const char* file_path = "test.txt";
    // Make sure file does not exist before testing
    // No need to care about delete success or not
    remove(file_path);
	char *content = "Sample content";
	// Verify write operation
	ASSERT_TRUE(file_put_contents(file_path, content));
}

TEST(Builtin_File, FileGetContents) {
    const char* file_path = "test.txt";
    // Make sure file does not exist before testing
    // No need to care about delete success or not
    remove(file_path);
    char *content = "Sample content";
    file_put_contents(file_path, content);
    char *expect = file_get_contents(file_path);
    // Verify read operation
    ASSERT_STR(expect, content);

//    content = file_get_contents("http://etcd.foodtiny.net/v2/keys/elassandra/development/seeds/test_node");
//    expect = "{\"action\":\"get\",\"node\":{\"key\":\"/elassandra/development/seeds/test_node\",\"value\":\"Hello World\",\"modifiedIndex\":45,\"createdIndex\":45}}\n";
//    ASSERT_STR(expect, content);
}
