#include "../../../library.hpp"
#include "Person.hpp"

class MainApplication {
public:
	static void main(Array<String> arguments) {
		Person person;
		person
			.setFirstName("Nguyen")
			.setLastName("Loi");
		System::out::println(person.getFullName());
	}
};

int main(int argc, string *argv) {
	return Application(MainApplication::main, argc, argv);
}
