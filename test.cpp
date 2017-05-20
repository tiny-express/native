#include <native/java.hpp>
using namespace java::lang;
int main() {
    String *output = new String("Hello C++");
    System::out::println(output);
    delete output;
    return 0;
}


