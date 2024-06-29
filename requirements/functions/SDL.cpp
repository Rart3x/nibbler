#include "../includes/SDL.hpp"

SDL::SDL(void) {
    
    if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) == -1)) {
        std::cerr << "Error: Could not initialize SDL" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->running = false;
}

SDL::~SDL() {
    SDL_Quit();
}

void SDL::display() {
    
    this->win = SDL_CreateWindow("Nibbler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    this->running = true;

    while (running) {
        input();
        SDL_Delay(16);
    }

    SDL_DestroyWindow(this->win);
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