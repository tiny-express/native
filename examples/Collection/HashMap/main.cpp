#include "../../../library.hpp"

void HashMapAddGet()
{
	HashMap<String, String> hashMap;
	hashMap.put("key", "value");
	System::out::println(hashMap.get("key").toString());
	System::out::println(hashMap.get("non-key").toString());
}

int main()
{
	HashMapAddGet();
	return 0;
}
