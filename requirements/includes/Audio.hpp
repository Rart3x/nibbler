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

        void    pauseMusic(void);
        void    playMusic(const std::string& music);
        void    playSound(const std::string& sound);
        void    stopMusic(void);

        void    setMusicVolume(size_t volume);

    private:
        sf::Music   music;
        sf::Music   sound;
};