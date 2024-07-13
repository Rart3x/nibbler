#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_timer.h>

#include "Library.hpp"


class SDL : public Library {

    public:
        SDL();
        SDL(const SDL &other);
        SDL& operator=(const SDL &other);
        ~SDL();

        void    closeWindow(void);

        void    display(void);
        void    displayGame(void);
        void    displayPause(void);

        void    drawTitle(void);

        void    input(void);
        void    update(void);

    private:
        SDL_Renderer*   renderer;
        SDL_Window*     win;
        TTF_Font*       font;
};