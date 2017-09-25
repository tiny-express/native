#include <native/library.hpp>

class MainApplication {
public:
    static void main(Array<String> arguments) {
        String helloWorld = "Hello World";
        helloWorld = "Food Tiny " + helloWorld;
        System::out::println(helloWorld);
        throw Exception("Your program has been protected by native exception");
    }
};

int main(int argc, char **argv) {
    return Application(MainApplication::main, argv);
}