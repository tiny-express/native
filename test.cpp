#include "library.hpp"

using namespace Java::Lang;
using namespace Java::IO;

int main() {
    String text = "Hello Native Library";
    FileWriter file = "text.txt";
    System::out::println(text);
    return 0;
}


