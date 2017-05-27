#include "../unit_test.h"
#include "../generic.hpp"


TEST (Generic, Print) {
	const char *constPointerChar = "\nConst Pointer Char";
	print(constPointerChar);
	
	const char *pointerChar = "Pointer Char";
	print((char *) pointerChar);
	
	std::string stdString = "String";
	print(stdString);
	
	std::cout << "Print short number: ";
	short shortNumber = 11111;
	print(shortNumber);
	
	std::cout << "Print int number: ";
	int intNumber = 999999999;
	print(intNumber);
	
	std::cout << "Print long number: ";
	long longNumber = 999999999999999999;
	print(longNumber);
	
	std::cout << "Print double number: ";
	double doubleNumber = 99.111;
	print(doubleNumber);
	
	std::cout << "Print vector int: ";
	std::vector<int> vectorInt(4, 100);
	print(vectorInt);
	
	std::cout << "Print vector double: ";
	std::vector<double> vectorDouble(4, 99.99999);
	print(vectorDouble);
}

