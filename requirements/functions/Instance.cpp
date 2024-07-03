#include "../includes/Instance.hpp"

SDL* loadSDLInstance() {
    const std::string funcName = "createSDLInstance";

    void* dl_handle;
    void* func_ptr;

    SDL* instance;

    dl_handle = dlopen(SDL_PATH, RTLD_LAZY | RTLD_LOCAL);
    if (!dl_handle)
        return NULL;

    func_ptr = dlsym(dl_handle, funcName.c_str());
    if (!func_ptr)
        return NULL;

    instance = reinterpret_cast<SDL * (*)(void)>(func_ptr)();
    if (!instance)
        return NULL;

    dlclose(dl_handle);
    return instance;
}