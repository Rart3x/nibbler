#include "../includes/Errors.hpp"

bool    error(void* obj, std::string text) {
    if (!obj)
    {
        printError(text);
        return false;
    }
    return true;
}

bool    errorQuitLibWithBool(bool boolean, std::string text, Library *lib) {
    if (!boolean)
    {
        printError(text);
        lib->setLibCode(404);
        lib->setRunning();
        return false;
    }
    return true;
}

bool    errorQuitLibWithint(int i, std::string text, Library *lib) {
    if (i == -1)
    {
        printError(text);
        lib->setLibCode(404);
        lib->setRunning();
        return false;
    }
    return true;
}

bool    errorQuitLibWithObj(void *obj, std::string text, Library *lib) {
    if (!obj)
    {
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