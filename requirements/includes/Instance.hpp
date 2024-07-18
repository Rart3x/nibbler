#pragma once 

#include <iostream>

#include "Audio.hpp"
#include "SDL.hpp"
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
        SDL*     loadSDLInstance();
        NC*     loadNCInstance();
        SFML*   loadSFMLInstance();

        void    loadMap(std::vector<std::string> map);
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