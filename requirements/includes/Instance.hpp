#pragma once 

#include <iostream>

#include "GL.hpp"
#include "SDL.hpp"
#include "SFML.hpp"
#include "Utils.hpp"

class Utils;

class Instance {
    public:
        Instance();
        ~Instance();

        GL*     loadGLInstance();
        SDL*    loadSDLInstance();
        SFML*   loadSFMLInstance();

        size_t  getActualLib() const;

        void    setActualLib(size_t i);
        void    setWindowSize(size_t h, size_t w);

        Library* operator[](size_t i);
    private:
        size_t actualLib;

        Library* libs[3];
};