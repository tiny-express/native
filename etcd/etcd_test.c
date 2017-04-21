//
// Created by dquang on 4/22/17.
//

#include "../builtin.h"
#include "../unit_test.h"
#include "../etcd.h"

TEST(Builtin_ETCD, ETCDGetAllNode) {
    char *all_key = etcd_get_all_node(ETCD_LOCALHOST);
    ASSERT_TRUE(length_pointer_char(all_key) > 1);
}

TEST(BUILTIN_ETCD, ETCDGet) {
    char *node = etcd_get(ETCD_LOCALHOST, "test_node");
    ASSERT_TRUE(length_pointer_char(node) > 0);
}

TEST(BUILTIN_ETCD, ETCDSet) {
    char *result = etcd_set(ETCD_MASTER, "/test_node", "1223");
    ASSERT_TRUE(length_pointer_char(result) > 0);

    result = etcd_set(ETCD_MASTER, "/test_node", "Hello World");
    ASSERT_TRUE(length_pointer_char(result) > 0);
}

