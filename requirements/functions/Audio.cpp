#include "../includes/Audio.hpp"

extern "C" {
    Audio *createAudioInstance() {
        return new Audio();
    }
}


Audio::Audio() {
    this->music.setVolume(50);
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


void Audio::playSong(const std::string& song) {
    if (this->music.getStatus() == sf::Music::Playing)
        this->music.stop();
    if (!this->music.openFromFile(song))
    {
        std::cerr << RED << "Error: Could not open file " << song << RESET << std::endl;
        return;
    }
    this->music.play();
}


void Audio::stopSong(void) {
    if (this->music.getStatus() == sf::Music::Playing)
        this->music.stop();
}