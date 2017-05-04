#include "../builtin.h"
#include "../unit_test.h"

TEST(Network, GetIPAddress) {
	ASSERT_TRUE(length_pointer_char(getIPAddress()) > 0);
}