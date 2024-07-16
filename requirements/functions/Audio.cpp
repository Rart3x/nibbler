#include "../includes/Audio.hpp"

extern "C" {
    Audio *createAudioInstance() {
        return new Audio();
    }
}


Audio::Audio() {
    this->music.setVolume(15);
    this->sound.setVolume(100);
}

Audio::~Audio() {
    if (this->music.getStatus() == sf::Music::Playing)
        this->music.stop();
}

Audio::Audio(const Audio& original) {
    if (this == &original)
        *this = original;
}

Audio& Audio::operator=(const Audio& original) {
    if (this == &original)
        return *this;
    return *this;
}

void Audio::pauseMusic(void) {
    this->music.pause();
}

void Audio::playMusic(const std::string& music) {
    if (this->music.getStatus() == sf::Music::Paused)
        this->music.play();
    else
    {
        if (this->music.getStatus() == sf::Music::Playing)
            this->music.stop();
        if (!this->music.openFromFile(music))
        {
            std::cerr << RED << "Error: Could not open file " << music << RESET << std::endl;
            return;
        }
        this->music.setLoop(true);
        this->music.play();

    }
}

void Audio::playSound(const std::string& sound) {
    if (!this->sound.openFromFile(sound))
    {
        std::cerr << RED << "Error: Could not open file " << sound << RESET << std::endl;
        return;
    }
    this->sound.play();
}

void Audio::stopMusic(void) {
    this->music.stop();
}


void Audio::setMusicVolume(size_t volume) {
    this->music.setVolume(volume);
}