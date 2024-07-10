#pragma once

#include <iostream>

#include "Errors.hpp"

#define SQUARE  5

#define WIDTH   500
#define HEIGHT  500

#define ARIAL   "./requirements/assets/fonts/arial.ttf"
#define SCIENCE "./requirements/assets/fonts/science.ttf"

#define GL_PATH "./requirements/libs/GL.so"
#define SDL_PATH "./requirements/libs/SDL.so"
#define SFML_PATH "./requirements/libs/SFML.so"

#define SFMLCODE    0
#define SDLCODE     1
#define GLCODE      2

#define MENU        0
#define GAME        1
#define PAUSE       2
#define QUIT        404

#define BUTTONSONG      "./requirements/assets/audios/button.ogg"
#define POKESONG        "./requirements/assets/audios/pokemon.ogg"
#define POKEROADSONG    "./requirements/assets/audios/pokemon_road.ogg"

class Library {

    public:
        Library();
        virtual ~Library();

        virtual void    closeWindow() = 0;
        virtual void    display() = 0;
        virtual void    input() = 0;

        virtual size_t  getLibCode() const = 0;

        virtual void    setAreaSize(int h, int w) = 0;
        virtual void    setLibCode(int code) = 0;
        virtual void    setRunning() = 0;
        virtual void    setWinSize(int h, int w) = 0;
    
    protected:
        bool    running;
        
        int     libCode;
        
        int     height;
        int     width;

        int     winH;
        int     winW;
};