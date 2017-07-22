#include "../../../library.hpp"

void HashMapAddGet() {
	std::cout << __func__ << ": ";
	HashMap<String, String> hashMap;
	hashMap.put("key", "value");
	System::out::println(hashMap.get("key").toString());
	System::out::println(hashMap.get("non-key").toString());
	std::cout << std::endl;
}

void HashMapToString() {
	std::cout << __func__ << ": ";
	HashMap<String, Integer> hashMapStringInteger;
	hashMapStringInteger.put("String1", 1);
	hashMapStringInteger.put("String2", 2);

	ArrayList<HashMap<String, Integer>> arrayListHashMap;
	arrayListHashMap.add(hashMapStringInteger);
	arrayListHashMap.add(hashMapStringInteger);

	ArrayList<HashMap<String, Integer>> emptyArrayListHashMap;

	HashMap<String, ArrayList<HashMap<String, Integer>>> hashMap;
	hashMap.put("ArrayList1", arrayListHashMap);
	hashMap.put("ArrayList2", arrayListHashMap);
	hashMap.put("EmptyArrayList", emptyArrayListHashMap);

	System::out::println(hashMap.toString());
	std::cout << std::endl;
}

int main() {
	HashMapAddGet();
	HashMapToString();
	return 0;
}
