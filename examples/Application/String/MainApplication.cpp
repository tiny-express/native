#include "../../../library.hpp"

class MainApplication {
public:
		static void main(Array<String> arguments) {
			register int i;
			for (i=0; i<100000000; i++) {
				String str;
				str += "hello world";
			}
		}
};

int main(int argc, char **argv) {
	MainApplication::main(argv);
	return 0;
}
