#include "../includes/Instance.hpp"

Instance::Instance() {
    this->audio = NULL;
    this->lib = NULL;

    this->audio = this->loadAudioInstance();
    this->lib = this->loadNCInstance();

    ifNullLibraryDelete(*this);
}

Instance::Instance(const Instance &original) {
    *this = original;
}

Instance& Instance::operator=(const Instance &original) {
    if (this != &original)
    {
        this->audio = original.audio;
        this->lib = original.lib;
    }
    return *this;
}

Instance::~Instance() {}


void Instance::loadMap(std::vector<std::string> map) {
    this->lib->setMap(map);
}

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

    return instance;
}

NC* Instance::loadNCInstance() {
    const std::string funcName = "createNCInstance";

    void* dl_handle;
    void* func;

    NC* instance = NULL;

    std::cout << BLUE << "Loading NC instance..." << RESET << std::endl;

    dl_handle = dlopen(NC_PATH, RTLD_LAZY | RTLD_LOCAL);
    if (!error(dl_handle, "Error: Failed to load NC instance."))
        return NULL;

    std::cout << BLUE << "NC instance creation method imported" << RESET << std::endl;

    func = dlsym(dl_handle, funcName.c_str());
    if (!error(func, "Error: Failed to get method pointer.", dl_handle, dlclose))
        return NULL;

    std::cout << BLUE << "NC instance created" << RESET << std::endl;

    instance = reinterpret_cast<NC * (*)(void)>(func)();
    if (!error(instance, "Error: Failed to initialize NC instance.", dl_handle, dlclose))
        return NULL;

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

    return instance;
}


void Instance::unloadAndLoad(size_t code) {
    if (code > 2)
        return;

    if (this->lib)
    {
        delete this->lib;
        this->lib = NULL;
    }

    switch(code)
    {
        case SFMLCODE:
            this->lib = this->loadSFMLInstance();
            break;
        
        case NCCODE:
            this->lib = this->loadNCInstance();
            break;

        case GLCODE:
            this->lib = this->loadGLInstance();
            break;

        default:
            break;
    }
}


Audio* Instance::getAudio() const {
    return this->audio;
}

Library* Instance::getLib() const {
    return this->lib;
}


void Instance::setAreaSize(size_t w, size_t h) {
    this->lib->setAreaSize(w, h);
}

Audio* Instance::operator[](const std::string &str) {
    if (str == "AUDIO")
        return this->audio;

    return this->audio;
}

Library* Instance::operator[](size_t i) {
    if (i == 0)
        return this->lib;
    return this->lib;
}