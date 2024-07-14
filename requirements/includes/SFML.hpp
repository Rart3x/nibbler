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
        virtual ~SFML();

        void    display(void);
        void    input(void);
        void    update(void);

        void    drawArea(void);

    private:
        sf::Music           music;
        sf::RenderWindow*   win;
};