#include "../../library.hpp"

void doArrayList()
{
	ArrayList<Integer> arrayList;
	arrayList.add(1);
	arrayList.add(2);
	// TODO - Test exception
}

void doHashMap()
{
	HashMap<String, String> hashMap;
	hashMap.put("string", "hello world");
	System::out::println(hashMap.get("string").toString());
	// Friendly with null pointer exception without any verify
	System::out::println(hashMap.get("another_string").toString());
}

int main()
{
	doArrayList();
	doHashMap();
	return 0;
}
