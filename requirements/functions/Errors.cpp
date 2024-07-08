#include "../includes/Errors.hpp"

bool    error(void* obj, std::string text) {
    if (!obj) {
        std::cerr << text << std::endl;
        return false;
    }
    return true;
}

bool    errorQuitLib(void *obj, std::string text, Library *lib) {
    if (!obj) {
        printError(text);
        lib->setLibCode(404);
        lib->setRunning();
        return false;
    }
    return true;
}

void    printError(std::string text) {
    std::cerr << RED << text << RESET << std::endl;
}