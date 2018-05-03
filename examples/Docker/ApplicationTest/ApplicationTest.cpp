#include <native/library.hpp>

TEST (JavaLangBytexxxx, Constructor) {
	// Given empty value for Bytes constructor and assign value - Return Byte
	Bytes defaultConstructorBytes;
	int expectResult = 0;
	int actualByteValue = defaultConstructorBytes.intValue();
	assertEquals(expectResult, actualByteValue);
	assertEquals("0", defaultConstructorBytes.toString());

	Bytes byteConstructorBytes = Bytes(3);
	expectResult = 3;
	actualByteValue = byteConstructorBytes.intValue();
	assertEquals(expectResult, actualByteValue);
	assertEquals("3", byteConstructorBytes.toString());

	// Constructor with String
	Bytes stringConstructorBytes = Bytes("3");
	actualByteValue = stringConstructorBytes.intValue();
	assertEquals(expectResult, actualByteValue);
	assertEquals("3", stringConstructorBytes.toString());

	// Copy constructor
	Bytes copyConstructorBytes = Bytes(stringConstructorBytes);
	actualByteValue = copyConstructorBytes.intValue();
	assertEquals(expectResult, actualByteValue);
	assertEquals("3", copyConstructorBytes.toString());

	try {
		Bytes exceptionBytes = Bytes("");
	} catch (NumberFormatException &e) {
		assertEquals(String("input string is null"), e.getMessage());
	}

	try {
		Bytes exceptionBytes = Bytes("abcd");
	}
	catch (NumberFormatException &e) {
		assertEquals("Not a number", e.getMessage());
	}

	try {
		Bytes exceptionBytes = Bytes("999999999999");
	}
	catch (NumberFormatException &e) {
		assertEquals("Integer out of range", e.getMessage());
	}

	try {
		Bytes exceptionBytes = Bytes("256");
	}
	catch (NumberFormatException &e) {
		assertEquals("out of byte range", e.getMessage());
	}
}

int main(int argc, const char *argv[]) {
    return ApplicationTest(argc, argv);
}