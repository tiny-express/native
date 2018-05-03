#include <native/library.hpp>

class MainApplication {
public:
    static void main(Array<String> arguments) {
        String helloWorld = "Hello World";
        helloWorld = "Food Tiny " + helloWorld;
        System::out::println(helloWorld);
        HashMap<String, String> hashMap;
        for (int i=0; i<100; i++) {
            hashMap.put(String("Key ") + String::valueOf(i), String("Value ") + String::valueOf(i));
        }
        System::out::println(String("Hash map size is ") + String::valueOf(hashMap.size()));
        throw Exception("Your program has been protected by native exception");
    }
};

int main(int argc, char **argv) {
    return Application(MainApplication::main, argc, argv);
}