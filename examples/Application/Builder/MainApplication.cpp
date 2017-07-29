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

int main(int argc, char **argv) {
	MainApplication::main(argv);
	return 0;
}
