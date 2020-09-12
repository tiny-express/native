#include "../../../library.hpp"

#include <native/library.hpp>

class MainApplication {
public:
    static void main(Array<String> arguments) {
        HashMap<String, String> hashMap = {};
        var index = 0;
        for (var argument : arguments) {
            hashMap.put(String::valueOf(index++), argument);
        }
        hashMap.forEach([](String key, String value) {
            System::out::println(String::format("Key is %s - Value is %s", key, value));
            return true;
        });
    }
};

int main(int argc, string *argv) {
    return Application(MainApplication::main, argc, argv);
}