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

        void    display(void);
        void    displayPause(void);
        void    input(void);
        void    pause(void);
        void    update(void);

        void    drawMap(void);

    private:
        sf::Music           music;
        sf::RenderWindow*   win;
};