
#include "../builtin.h"
#include "../unit_test.h"
#include "../vendor.h"

TEST(BUILTIN_ETCD, ETCDGet) {
    char *node = etcd_get(ETCD_LOCALHOST, "/elassandra/development/seeds/test_node");
    ASSERT_TRUE(length_pointer_char(node) > 0);

    node = etcd_get("", "/elassandra/development/seeds/test_node");
    ASSERT_FALSE(length_pointer_char(node) > 0);

    node = etcd_get(ETCD_LOCALHOST, "");
    ASSERT_FALSE(length_pointer_char(node) > 0);
}

TEST(BUILTIN_ETCD, ETCDSet) {
    char *result = etcd_set(ETCD_MASTER, "/elassandra/development/seeds/test_node", "1223");
    ASSERT_TRUE(length_pointer_char(result) > 0);

    result = etcd_set(ETCD_MASTER, "/elassandra/development/seeds/test_node", "Hello World");
    ASSERT_TRUE(length_pointer_char(result) > 0);
}

