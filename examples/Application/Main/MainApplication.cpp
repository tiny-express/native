#include "../../../library.hpp"

#include <native/library.hpp>

class MainApplication {
public:
    static void main(Array<String> arguments) {
        HashMap<String, String> hashMap = {};
        int index = 0;
        for (var argument : arguments) {
            hashMap.put(String::valueOf(index++), argument);
        }
        hashMap.forEach([](const String &key, const String &value) {
            System::out::println(String::format("Key is %s - Value is %s", key, value));
        });
    }
};

int main(int argc, char **argv) {
    return Application(MainApplication::main, argc, argv);
}