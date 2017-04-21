#include "../unit_test.h"
#include "../general.h"
#include "../vendor.h"

TEST(Builtin_Vendor, ElasticSearch) {
    char *result = es_query("35.189.187.98", "db_foodtiny_test", "{'query': {'bool' : {'must' : [{'nested':{'path':'shop_type','query':{ 'match': {'shop_type.vi_VN':'Quán ăn' }}}},{'filtered': {'filter': {'geo_distance': {'distance': '1km','distance_type': 'plane', 'location': {'lat':  10.799433,'lon': 106.710999}}}}}]}}}");
    ASSERT_TRUE(length_pointer_char(result) > 0);
}