#pragma once 

#include <iostream>

#include "Audio.hpp"
#include "GL.hpp"
#include "SDL.hpp"
#include "SFML.hpp"
#include "Utils.hpp"

class Utils;

class Instance {
    public:
        Instance();
        ~Instance();

        Audio*  loadAudioInstance();
        GL*     loadGLInstance();
        SDL*    loadSDLInstance();
        SFML*   loadSFMLInstance();

        size_t  getActualLib() const;
        Audio * getAudio() const;

        void    setActualLib(size_t i);
        void    setAreaSize(size_t h, size_t w);

        Library* operator[](size_t i);
    private:
        size_t      actualLib;

        Audio*      audio;
        Library*    libs[3];
};