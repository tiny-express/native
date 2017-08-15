#include "../../../library.hpp"

class MainApplication {
public:
		static void main(Array<String> arguments) {
			HashMap<String, String> hashMap;
			int counter = 0;
			for (String argument : arguments) {
				hashMap.put("argument " + String::valueOf(counter), argument);
				counter++;
			}
			// Collect key value pairs
			String pairs = String("We have ") + String::valueOf(hashMap.size()) + String(" pairs: \n");
			for (Map<String, String>::Entry entry : hashMap.entrySet()) {
				pairs += entry.getKey() + String(" is ") + entry.getValue() + String("\n");
			}
			System::out::println(pairs);
			// Serialize to json data
			ArrayList<HashMap<String, String>> arrayList;
			arrayList.add(hashMap);
			System::out::println(arrayList.toString());
		}
};

int main(int argc, char **argv) {
	MainApplication::main(argv);
	return 0;
}
