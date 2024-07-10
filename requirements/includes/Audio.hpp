#pragma once

#include <iostream>

#include "Defines.hpp"
#include "Errors.hpp"

#include <SFML/Audio.hpp>

class Audio {
    public:
        Audio();
        ~Audio();

        Audio(const Audio& other);
        Audio& operator=(const Audio& other);

        void    playSong(const std::string& song);
        void    stopSong(void);

    private:
        sf::Music   music;
};