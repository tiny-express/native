#include "Lang.hpp"

/**
 * Application starting point
 * This function handle any application exception to keep program safety
 *
 * @param program
 * @param argument
 * @return int
 */
int Application(void (*program)(Array<Java::Lang::String>), char **argument) {
    try {
        program(argument);
        return 0;
    } catch (Exception &e) {
        System::out::println("Application Exception: " + e.getMessage());
        return 1;
    } catch (...) {
#ifdef LINUX
        std::exception_ptr p = std::current_exception();
        String exceptionName = p.__cxa_exception_type()->name();
        System::out::println("Unhandled Exception: " + exceptionName);
#else
        System::out::println("Unhandled Exception");
#endif
        return 1;
    }
}
