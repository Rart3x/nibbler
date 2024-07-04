#include "../includes/Instance.hpp"

Instance::Instance() : actualLib(0) {
    this->libs[0] = this->loadGLInstance();
    this->libs[1] = this->loadSDLInstance();
    this->libs[2] = this->loadSFMLInstance();
}

Instance::~Instance() {}


GL * Instance::loadGLInstance() {
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


SDL* Instance::loadSDLInstance() {
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


SFML* Instance::loadSFMLInstance() {
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


size_t Instance::getActualLib() const {
    return this->actualLib;
}


void Instance::setActualLib(size_t i) {
    if (i > 2)
        throw std::runtime_error("Error: invalid index");

    this->actualLib = i;
}


void Instance::setWindowSize(size_t w, size_t h) {
    for (size_t i = 0; i < 3; i++)
        this->libs[i]->setWindowSize(w, h);
}


Library* Instance::operator[](size_t i) {
    if (i > 2)
        throw std::runtime_error("Error: invalid index");

    return this->libs[i];
}