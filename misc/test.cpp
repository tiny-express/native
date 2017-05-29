#include <native/library.hpp>
int main() {
	String text = "Sample program: ";
	Array<byte> bytes = { 64, 65, 66, 67 };
	for (byte number : bytes) {
		text += (char) number;
	}
	System::out::println(text);
	return 0;
}

