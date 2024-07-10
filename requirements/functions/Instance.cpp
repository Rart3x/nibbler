#include "../includes/Instance.hpp"

Instance::Instance() : actualLib(0) {
    this->audio = NULL;
    this->libs[SFMLCODE] = NULL;
    this->libs[SDLCODE] = NULL;
    this->libs[GLCODE] = NULL;

    this->audio = this->loadAudioInstance();
    this->libs[SFMLCODE] = this->loadSFMLInstance();
    this->libs[SDLCODE] = this->loadSDLInstance();
    this->libs[GLCODE] = this->loadGLInstance();
}

Instance::~Instance() {}


Audio* Instance::loadAudioInstance() {
    const std::string funcName = "createAudioInstance";

    void* dl_handle;
    void* func;

    Audio* instance = NULL;

    std::cout << BLUE << "Loading Audio instance..." << RESET << std::endl;

    dl_handle = dlopen(AUDIO_PATH, RTLD_LAZY | RTLD_LOCAL);
    if (!error(dl_handle, "Error: Failed to load Audio instance."))
        return NULL;

    std::cout << BLUE << "Audio instance creation method imported" << RESET << std::endl;

    func = dlsym(dl_handle, funcName.c_str());
    if (!error(func, "Error: Failed to get method pointer.", dl_handle, dlclose))
        return NULL;

    std::cout << BLUE << "Audio instance created" << RESET << std::endl;

    instance = reinterpret_cast<Audio * (*)(void)>(func)();
    if (!error(instance, "Error: Failed to initialize Audio instance.", dl_handle, dlclose))
        return NULL;

    std::cout << BLUE << "Audio instance initialized" << RESET << std::endl << std::endl;

    return instance;
}


GL* Instance::loadGLInstance() {
    const std::string funcName = "createGLInstance";

    void* dl_handle;
    void* func;

    GL* instance = NULL;

    std::cout << BLUE << "Loading GL instance..." << RESET << std::endl;

    dl_handle = dlopen(GL_PATH, RTLD_LAZY | RTLD_LOCAL);
    if (!error(dl_handle, "Error: Failed to load GL instance."))
        return NULL;

    std::cout << BLUE << "GL instance creation method imported" << RESET << std::endl;

    func = dlsym(dl_handle, funcName.c_str());
    if (!error(func, "Error: Failed to get method pointer.", dl_handle, dlclose))
        return NULL;

    std::cout << BLUE << "GL instance created" << RESET << std::endl;

    instance = reinterpret_cast<GL * (*)(void)>(func)();
    if (!error(instance, "Error: Failed to initialize GL instance.", dl_handle, dlclose))
        return NULL;

    std::cout << BLUE << "GL instance initialized" << RESET << std::endl << std::endl;

    return instance;
}


SDL* Instance::loadSDLInstance() {
    const std::string funcName = "createSDLInstance";

    void* dl_handle;
    void* func;

    SDL* instance = NULL;

    std::cout << BLUE << "Loading SDL instance..." << RESET << std::endl;

    dl_handle = dlopen(SDL_PATH, RTLD_LAZY | RTLD_LOCAL);
    if (!error(dl_handle, "Error: Failed to load SDL instance."))
        return NULL;

    std::cout << BLUE << "SDL instance creation method imported" << RESET << std::endl;

    func = dlsym(dl_handle, funcName.c_str());
    if (!error(func, "Error: Failed to get method pointer.", dl_handle, dlclose))
        return NULL;

    std::cout << BLUE << "SDL instance created" << RESET << std::endl;

    instance = reinterpret_cast<SDL * (*)(void)>(func)();
    if (!error(instance, "Error: Failed to initialize SDL instance.", dl_handle, dlclose))
        return NULL;

    std::cout << BLUE << "SDL instance initialized" << RESET << std::endl << std::endl;

    return instance;
}


SFML* Instance::loadSFMLInstance() {
    const std::string funcName = "createSFMLInstance";

    void* dl_handle;
    void* func;

    SFML* instance = NULL;

    std::cout << BLUE << "Loading SFML instance..." << RESET << std::endl;

    dl_handle = dlopen(SFML_PATH, RTLD_LAZY | RTLD_LOCAL);
    if (!error(dl_handle, "Error: Failed to load SFML instance."))
        return NULL;

    std::cout << BLUE << "SFML instance creation method imported" << RESET << std::endl;

    func = dlsym(dl_handle, funcName.c_str());
    if (!error(func, "Error: Failed to get method pointer.", dl_handle, dlclose))
        return NULL;

    std::cout << BLUE << "SFML instance created" << RESET << std::endl;

    instance = reinterpret_cast<SFML * (*)(void)>(func)();
    if (!error(instance, "Error: Failed to initialize SFML instance.", dl_handle, dlclose))
        return NULL;

    std::cout << BLUE << "SFML instance initialized" << RESET << std::endl << std::endl;

    return instance;
}


size_t Instance::getActualLib() const {
    return this->actualLib;
}


Audio* Instance::getAudio() const {
    return this->audio;
}


void Instance::setActualLib(size_t i) {
    if (i > 2)
        throw std::runtime_error("Error: invalid index");

    this->actualLib = i;
}


void Instance::setAreaSize(size_t w, size_t h) {
    for (size_t i = 0; i < 3; i++)
        this->libs[i]->setAreaSize(w, h);
}

Audio* Instance::operator[](const std::string &str) {
    if (str == "AUDIO")
        return this->audio;
    return this->audio;
}

Library* Instance::operator[](size_t i) {
    if (i > 2)
        throw std::runtime_error("Error: invalid index");
    return this->libs[i];
}