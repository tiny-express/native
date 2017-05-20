#include <native/library.hpp>

using namespace Java::Lang;
using namespace Java::IO;

int main() {
    String text = "Hello Native Library";
    File file = "text.txt";

    System::out::println(text);
    return 0;
}


