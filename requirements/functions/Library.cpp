#include "../includes/Library.hpp"

Library::Library() : keyCode(NONE), mode(NONE), height(0), width(0) {}
Library::~Library() {}


int Library::getKeyCode(void) const {
    return this->keyCode;
}

std::vector<std::string> Library::getMap(void) const {
    return this->map;
}

int Library::getMode(void) const {
    return this->mode;
}


void Library::setAreaSize(int h, int w) {
    this->height = h;
    this->width = w;
}

void Library::setKeyCode(int code) {
    this->keyCode = code;
}

void Library::setMap(std::vector<std::string> map) {
    this->map = map;
}

void Library::setMode(int code) {
    this->mode = code;
}