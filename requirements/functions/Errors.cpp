#include "../includes/Errors.hpp"

bool    error(void* obj, std::string text, void* toDelete, int (*deleteFunc)(void *)) {
    if (!obj)
    {
        printError(text);
        if (toDelete && deleteFunc)
            deleteFunc(toDelete);
        return false;
    }
    return true;
}

bool    errorQuitLibWithBool(bool boolean, std::string text, Library *lib) {
    if (!boolean)
    {
        printError(text);
        lib->setKeyCode(QUIT);
        
        return false;
    }
    return true;
}

bool    errorQuitLibWithint(int i, std::string text, Library *lib) {
    if (i == -1)
    {
        printError(text);
        lib->setKeyCode(QUIT);
        
        return false;
    }
    return true;
}

bool    errorQuitLibWithObj(void *obj, std::string text, Library *lib) {
    if (!obj)
    {
        printError(text);
        lib->setKeyCode(QUIT);
        
        return false;
    }
    return true;
}

void    printError(std::string text) {
    std::cerr << RED << text << RESET << std::endl;
}