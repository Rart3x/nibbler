#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

#include "Library.hpp"

class SDL : public Library {

    public:
        SDL();
        ~SDL();

        void display(void);
        void input(void);

    private:
        bool running;

        SDL_Window* win;
};