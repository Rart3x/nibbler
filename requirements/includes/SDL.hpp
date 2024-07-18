#pragma once

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include "Library.hpp"

class SDL : public Library {
    public:
        SDL();
        SDL(const SDL &original);
        SDL& operator=(const SDL &original);
        ~SDL();
        
        void    display(void);
        void    displayPause(void);
        void    input(void);
        void    pause(void);
        void    update(void);

    private:
        SDL_Renderer*   renderer;
        SDL_Window*     win;
        TTF_Font*       font;
};
