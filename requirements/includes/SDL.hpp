#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

#include "Library.hpp"

class SDL : public Library {

    public:
        SDL();
        ~SDL();

        void closeWindow(void);
        void display(void);
        void input(void);

        size_t getLibCode(void) const;

        void setAreaSize(int h, int w);
        void setWinSize(int h, int w);

    private:
        bool running;

        int height;
        int width;

        int winH;
        int winW;

        size_t libCode;

        SDL_Window* win;
};