#pragma once

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Library.hpp"

class SFML : public Library {
    public:
        SFML();
        SFML(const SFML &other);
        SFML& operator=(const SFML &other);
        ~SFML();

        void    closeWindow(void);    

        void    display(void);
        void    displayGame(void);
        void    displayMenu(void);
        void    displayPause(void);

        void    drawButton(std::string text, sf::Vector2f position, sf::Vector2f size, sf::Color color);
        void    drawArea(void);
        void    drawTitle(std::string text, sf::Color color);
    
        void    input(void);
        void    update(void);

    private:
        int     selectedButton;

        sf::Music           music;
        sf::RenderWindow*   win;
};