#include "../../../library.hpp"

void ArrayAssignment() {
	string stringSequence[3] = {
		(string) "string1",
		(string) "string2",
	        '\0'
	};
	Array<String> array = (string*) stringSequence;
	System::out::println(array.length);
}

void ArrayException() {
	std::cout << __func__ << ": ";
	ArrayList<String> arrayList;
	arrayList.add("hello");
	try {
		arrayList.get(10);
	} catch (Exception e) {
		System::out::println(e.getMessage());
	}
}

void ArrayForeach() {
	std::cout << __func__ << ": ";
	Array<String> arrayString;
	arrayString.push("hello");
	arrayString.push("world");
	for (String item : arrayString) {
		System::out::println(item.toString());
	}
}

void ArraySerialize() {
	std::cout << __func__ << ": ";
	Array<String> arrayString;
	arrayString.push("hello");
	arrayString.push("world");
	//System::out::println(arrayString.toCharPointer());
}

int main() {
	ArrayAssignment();
	ArrayException();
	ArrayForeach();
	ArraySerialize();
	return 0;
}
