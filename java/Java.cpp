#include "Lang.hpp"

/**
 * Application starting point
 *
 * @param program
 * @param argument
 * @return int
 */
int Application(void (*program)(Array<Java::Lang::String>), char **argument) {
    try {
        program(argument);
    } catch (Exception &exception) {
        System::out::println(exception.getMessage());
    }
    return 0;
}
