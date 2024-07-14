#include "../includes/Library.hpp"

Library::Library() : keyCode(NONE), mode(0), height(0), width(0) {}
Library::~Library() {}


int Library::getKeyCode(void) const {
    return this->keyCode;
}

void Library::setAreaSize(int h, int w) {
    this->height = h;
    this->width = w;
}

void Library::setKeyCode(int code) {
    this->keyCode = code;
}

void Library::setMode(int code) {
    this->mode = code;
}