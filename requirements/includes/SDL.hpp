#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_timer.h>

#include "Library.hpp"

#define CYAN 0, 255, 255, 255
#define WHITE 255, 255, 255, 255
#define BLACK 0, 0, 0, 255

class SDL : public Library {

    public:
        SDL();
        ~SDL();

        void    closeWindow(void);

        void    display(void);
        void    displayGame(void);

        void    drawTitle(void);

        void    input(void);

        size_t  getLibCode(void) const;

        void    setAreaSize(int h, int w);
        void    setWinSize(int h, int w);

    private:
        bool    running;

        int     height;
        int     width;

        int     winH;
        int     winW;

        int     selectedButton;

        size_t  libCode;

        SDL_Renderer*   renderer;
        SDL_Window*     win;
        TTF_Font*       font;
};