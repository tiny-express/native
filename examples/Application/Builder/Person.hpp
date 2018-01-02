#ifndef NATIVE_PERSON_HPP
#define NATIVE_PERSON_HPP


class Person {
private:
	String firstName;
	String lastName;
public:
	Person &setFirstName(String firstName) {
		this->firstName = firstName;
		return *this;
	}
	
	String getFirstName() {
		return this->firstName;
	}
	
	Person &setLastName(String lastName) {
		this->lastName = lastName;
		return *this;
	}
	
	String getLastName() {
		return this->lastName;
	}
	
	String getFullName() {
		return firstName + String(" ") + lastName;
	}
};


#endif //NATIVE_PERSON_HPP
