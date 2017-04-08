#include "../file.h"
#include "../unit_test.h"

TEST(Builtin_File, filePutContents) {
    const char* file_path = "test.txt";
    // Make sure file does not exist before testing
    // No need to care about delete success or not
    remove(file_path);
	char *content = "Sample content";
	// Verify write operation
	ASSERT_TRUE(file_put_contents(file_path, content));
}

TEST(Builtin_File, fileGetContents) {
    const char* file_path = "test.txt";
    // Make sure file does not exist before testing
    // No need to care about delete success or not
    remove(file_path);
    char *content = "Sample content";
    file_put_contents(file_path, content);
    // Verify read operation
    ASSERT_STR(file_get_contents(file_path), content);
}
