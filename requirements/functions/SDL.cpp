#include "../includes/SDL.hpp"

extern "C" {
    SDL *createSDLInstance() {
        return new SDL();
    }
}


SDL::SDL(void) : Library() {
    
    if((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)) {
        std::cerr << "Error: Could not initialize SDL" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->running = false;
    this->libCode = 0;
}


SDL::~SDL() {
    SDL_DestroyWindow(this->win);
    SDL_Quit();
}


void SDL::closeWindow() {
    if (this->win) {
        SDL_DestroyWindow(this->win);
        this->win = NULL;
    }
}


void SDL::display() {

    this->win = SDL_CreateWindow("Nibbler SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    if (!this->win) {
        std::cerr << "Error: Could not create SDL window" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->running = true;

    while (this->running) {
        this->input();
        SDL_Delay(16);
    }
}


void SDL::input() {
    SDL_Event event;
 
    while (SDL_PollEvent(&event)) {
        switch (event.type) {

        case SDL_QUIT:
            this->running = false;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode) {

            case SDL_SCANCODE_ESCAPE:
                this->libCode = 404;
                this->running = false;
                break;

            case SDL_SCANCODE_1:
                this->libCode = 0;
                this->running = false;
                break;

            case SDL_SCANCODE_3:
                this->libCode = 2;
                this->running = false;
                break;

            case SDL_SCANCODE_W:
            case SDL_SCANCODE_UP:
                break;

            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
                break;

            case SDL_SCANCODE_S:
            case SDL_SCANCODE_DOWN:
                break;

            case SDL_SCANCODE_D:
            case SDL_SCANCODE_RIGHT:
                break;

            default:
                break;
            }
        }
    }
}

size_t SDL::getLibCode() const {
    return this->libCode;
}

void SDL::setAreaSize(int h, int w) {
    this->height = h;
    this->width = w;
}