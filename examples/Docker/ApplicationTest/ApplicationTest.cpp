#include <native/library.hpp>

TEST(ApplicationTestSuite, Case1) {
    assertEquals("Hello", "Hello");
}

int main(int argc, char **argv) {
    return ApplicationTest(argc, argv);
}