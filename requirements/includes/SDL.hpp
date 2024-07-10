#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_timer.h>

#include "Library.hpp"


class SDL : public Library {

    public:
        SDL();
        ~SDL();

        void    closeWindow(void);

        void    display(void);
        void    displayGame(void);
        void    displayPause(void);

        void    drawTitle(void);

        void    input(void);

        size_t  getLibCode(void) const;

        void    setAreaSize(int h, int w);
        void    setLibCode(int code);
        void    setMode(int code);
        void    setRunning();
        void    setWinSize(int h, int w);

    private:
        SDL_Renderer*   renderer;
        SDL_Window*     win;
        TTF_Font*       font;
};