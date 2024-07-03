#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

class SDL {

    public:
        SDL();
        ~SDL();

        void display(void);
        void input(void);
        void print(void) const;

    private:
        bool running;

        SDL_Window* win;
};