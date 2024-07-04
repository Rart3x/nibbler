#include "../includes/Utils.hpp"

bool isNumeric(const std::string& str) {
    for (char c : str)
        if (!isdigit(c))
            return false;
    return true;
}


void check_args_validity(int ac, char **av) {

    if (ac != 3)
        throw std::runtime_error("Error: invalid number of arguments");

    std::string width = av[1];
    std::string height = av[2];

    if (!isNumeric(width) || !isNumeric(height))
        throw std::runtime_error("Error: numeric arguments required");
}


GL * loadGLInstance() {
    const std::string funcName = "createGLInstance";

    void* dl_handle;
    void* func;

    GL* instance;

    std::cout << BLUE << "Loading GL instance..." << RESET << std::endl;

    dl_handle = dlopen(GL_PATH, RTLD_LAZY | RTLD_LOCAL);
    if (!dl_handle) {
        std::cerr << RED << "Error: Failed to load GL instance." << RESET << std::endl;
        return NULL;
    }

    std::cout << BLUE << "GL instance creation method imported" << RESET << std::endl;

    func = dlsym(dl_handle, funcName.c_str());
    if (!func) {
        std::cerr << RED << "Error: Failed to get method pointer." << RESET << std::endl;
        dlclose(dl_handle);
        return NULL;
    }

    std::cout << BLUE << "GL instance created" << RESET << std::endl;

    instance = reinterpret_cast<GL * (*)(void)>(func)();
    if (!instance) {
        std::cerr << RED << "Error: Failed to initialize GL instance." << RESET << std::endl;
        dlclose(dl_handle);
        return NULL;
    }

    std::cout << BLUE << "GL instance initialized" << RESET << std::endl << std::endl;

    return instance;
}


SDL* loadSDLInstance() {
    const std::string funcName = "createSDLInstance";

    void* dl_handle;
    void* func;

    SDL* instance;

    std::cout << BLUE << "Loading SDL instance..." << RESET << std::endl;

    dl_handle = dlopen(SDL_PATH, RTLD_LAZY | RTLD_LOCAL);
    if (!dl_handle) {
        std::cerr << RED << "Error: Failed to load SDL instance." << RESET << std::endl;
        return NULL;
    }

    std::cout << BLUE << "SDL instance creation method imported" << RESET << std::endl;

    func = dlsym(dl_handle, funcName.c_str());
    if (!func) {
        std::cerr << RED << "Error: Failed to get method pointer." << RESET << std::endl;
        dlclose(dl_handle);
        return NULL;
    }

    std::cout << BLUE << "SDL instance created" << RESET << std::endl;

    instance = reinterpret_cast<SDL * (*)(void)>(func)();
    if (!instance) {
        std::cerr << RED << "Error: Failed to initialize SDL instance." << RESET << std::endl;
        dlclose(dl_handle);
        return NULL;
    }

    std::cout << BLUE << "SDL instance initialized" << RESET << std::endl << std::endl;

    return instance;
}


SFML* loadSFMLInstance() {
    const std::string funcName = "createSFMLInstance";

    void* dl_handle;
    void* func;

    SFML* instance;

    std::cout << BLUE << "Loading SFML instance..." << RESET << std::endl;

    dl_handle = dlopen(SFML_PATH, RTLD_LAZY | RTLD_LOCAL);
    if (!dl_handle) {
        std::cerr << RED << "Error: Failed to load SFML instance." << RESET << std::endl;
        return NULL;
    }

    std::cout << BLUE << "SFML instance creation method imported" << RESET << std::endl;

    func = dlsym(dl_handle, funcName.c_str());
    if (!func) {
        std::cerr << RED << "Error: Failed to get method pointer." << RESET << std::endl;
        dlclose(dl_handle);
        return NULL;
    }

    std::cout << BLUE << "SFML instance created" << RESET << std::endl;

    instance = reinterpret_cast<SFML * (*)(void)>(func)();
    if (!instance) {
        std::cerr << RED << "Error: Failed to initialize SFML instance." << RESET << std::endl;
        dlclose(dl_handle);
        return NULL;
    }

    std::cout << BLUE << "SFML instance initialized" << RESET << std::endl << std::endl;

    return instance;
}