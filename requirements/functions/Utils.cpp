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


SDL* loadSDLInstance() {
    const std::string funcName = "createSDLInstance";

    void* dl_handle;
    void* func;

    SDL* instance;

    std::cout << BLUE << "Loading SDL instance..." << RESET << std::endl;

    dl_handle = dlopen(SDL_PATH, RTLD_LAZY | RTLD_LOCAL);
    if (!dl_handle) {
        std::cerr << RED << "Failed to load SDL instance." << RESET << std::endl;
        return NULL;
    }

    std::cout << BLUE << "SDL instance loaded" << RESET << std::endl;

    func = dlsym(dl_handle, funcName.c_str());
    if (!func) {
        std::cerr << RED << "Failed to get function pointer." << RESET << std::endl;
        dlclose(dl_handle);
        return NULL;
    }

    std::cout << BLUE << "SDL instance created" << RESET << std::endl;

    instance = reinterpret_cast<SDL * (*)(void)>(func)();
    if (!instance) {
        std::cerr << RED << "Failed to initialize SDL instance." << RESET << std::endl;
        dlclose(dl_handle);
        return NULL;
    }

    std::cout << BLUE << "SDL instance initialized" << RESET << std::endl;

    dlclose(dl_handle);
    return instance;
}
