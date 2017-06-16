#ifndef NATIVE_EXAMPLE_PERSON_HPP
#define NATIVE_EXAMPLE_PERSON_HPP

#include <native/library.hpp>

class Person {
private:
	String firstName;
public:
	Person() {
	}
	~Person() {
	}
	Person &setFirstName(String firstName) {
		self.firstName = firstName;
		return self;
	}
	
//	String &getFirstName() {
//		return self.firstName;
//	}
//	Person &setLastName(String lastName) {
//		self.lastName = lastName;
//		return self;
//	}
//	String &getLastName() {
//		return self.lastName;
//	}
};

#endif //NATIVE_EXAMPLE_PERSON_HPP
