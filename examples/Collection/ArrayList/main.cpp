#include "../../../library.hpp"

void ArrayListSetGet()
{
	ArrayList<String> arrayList;
	arrayList.add("hello");
	arrayList.add("world");
	System::out::println(arrayList.get(0).toString());
}

void ArrayListException() {
	ArrayList<String> arrayList;
	arrayList.add("hello");
	try {
		arrayList.get(10);
	} catch (Exception e) {
		// ERROR -  Should throw exception
		System::out::println(e.getMessage());
	}
}

void ArrayListForeach()
{
	ArrayList<String> arrayList;
	arrayList.add("hello");
	arrayList.add("world");
	for (String item: arrayList) {
		System::out::println(item.toString());
	}
}

void ArrayListSerialize()
{
	ArrayList<String> arrayList;
	arrayList.add("hello");
	arrayList.add("world");
	// ERROR - Should return ["hello", "world"]
	System::out::println(arrayList.toString());
}

int main()
{
	ArrayListSetGet();
	ArrayListException();
	ArrayListForeach();
	ArrayListSerialize();
	return 0;
}
