#include "../../../library.hpp"

class MainApplication {
public:
	static void main(Array<string> args) {
		ArrayList<String> stringList;
		stringList.add("hello");
		stringList.add("word");
		try {
			System::out::println(stringList.get(5));
		} catch (IndexOutOfBoundsException e) {
			System::out::println(e.getMessage());
		}
	}
};

int main(int argc, char **argv) {
	MainApplication::main(argv);
	return 0;
}
