#pragma once

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Library.hpp"

class SFML : public Library {
    public:
        SFML();
        ~SFML();

        void    closeWindow(void);    

        void    display(void);
        void    displayGame(void);
        void    displayMenu(void);
        void    displayPause(void);

        void    drawButton(std::string text, sf::Vector2f position, sf::Vector2f size, sf::Color color);
        void    drawTitle(std::string text, sf::Color color);
    
        void    input(void);

        void    playSong(const std::string& song, bool loop = false);

        size_t  getLibCode(void) const;

        void    setAreaSize(int h, int w);
        void    setLibCode(int code);
        void    setRunning();
        void    setWinSize(int h, int w);

    private:
        bool    running;

        int     height;
        int     width;

        int     winH;
        int     winW;

        int     selectedButton;

        int     mode;
        int     prevMode;

        int     libCode;

        sf::Music           music;
        sf::RenderWindow*   win;
};