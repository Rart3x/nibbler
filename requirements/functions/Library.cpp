#include "../includes/Library.hpp"

Library::Library() : running(false), keyCode(0), mode(0), height(0), width(0), winH(HEIGHT), winW(WIDTH) {}
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

void Library::setRunning() {
    this->running = true;
}

void Library::setWinSize(int h, int w) {
    this->winH = h;
    this->winW = w;
}