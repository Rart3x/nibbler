#pragma once 

#include <iostream>

#include "Audio.hpp"
#include "GL.hpp"
#include "NC.hpp"
#include "SFML.hpp"
#include "Utils.hpp"

class Utils;

class Instance {
    public:
        Instance();
        Instance(const Instance &original);
        Instance& operator=(const Instance &original);
        ~Instance();

        Audio*  loadAudioInstance();
        GL*     loadGLInstance();
        NC*    loadNCInstance();
        SFML*   loadSFMLInstance();

        void    unloadAndLoad(size_t code);

        Audio*      getAudio() const;
        Library*    getLib() const;

        void    setAreaSize(size_t h, size_t w);

        Audio*      operator[](const std::string &str);
        Library*    operator[](size_t i);
    private:
        Audio*      audio;
        Library*    lib;
};