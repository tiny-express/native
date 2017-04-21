//
// Created by dquang on 4/22/17.
//

#include "../builtin.h"
#include "../unit_test.h"
#include "../etcd.h"

TEST(Builtin_ETCD, GetAllKeys) {
    char *all_key = etcd_get_all_keys();
    ASSERT_STR("{\"action\":\"get\",\"node\":{\"dir\":true,\"nodes\":[{\"key\":\"/xxx\",\"value\":\"123\",\"modifiedIndex\":4,\"createdIndex\":4}]}}", all_key);
}

