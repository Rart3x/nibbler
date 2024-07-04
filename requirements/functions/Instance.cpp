#include "../includes/Instance.hpp"

Instance::Instance() : actualLib(0) {
    this->libs[0] = loadGLInstance();
    this->libs[1] = loadSDLInstance();
    this->libs[2] = loadSFMLInstance();
}

Instance::~Instance() {}

size_t Instance::getActualLib() const {
    return this->actualLib;
}

void Instance::setActualLib(size_t i) {
    if (i > 2)
        throw std::runtime_error("Error: invalid index");

    this->actualLib = i;
}

Library* Instance::operator[](size_t i) {
    if (i > 2)
        throw std::runtime_error("Error: invalid index");

    return this->libs[i];
}