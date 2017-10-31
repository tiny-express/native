#include "../../../library.hpp"

void ArrayListSetGet() {
	std::cout << __func__ << ": ";
	ArrayList<String> arrayList;
	arrayList.add("hello");
	arrayList.add("world");
	System::out::println(arrayList.get(0).toString());
}

void ArrayListException() {
	std::cout << __func__ << ": ";
	ArrayList<String> arrayList;
	arrayList.add("hello");
	try {
		arrayList.get(10);
	} catch (Exception e) {
		System::out::println(e.getMessage());
	}
}

void ArrayListForeach() {
	std::cout << __func__ << ": ";
	ArrayList<String> arrayList;
	arrayList.add("hello");
	arrayList.add("world");
	for (String item : arrayList) {
		System::out::println(item.toString());
	}
}

void ArrayListSerialize() {
	std::cout << __func__ << ": ";
	ArrayList<String> arrayList;
	arrayList.add("hello");
	arrayList.add("world");
	System::out::println(arrayList.toString());
}

long int main() {
	ArrayListSetGet();
	ArrayListException();
	ArrayListForeach();
	ArrayListSerialize();
	return 0;
}
