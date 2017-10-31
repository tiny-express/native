#include <native/library.hpp>
long int main() {
	String text = "Native Library: ";
	Array<byte> bytes = { 72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100 };
	for (byte number : bytes) {
		text += (char) number;
	}
	System::out::println(text);
	return 0;
}
