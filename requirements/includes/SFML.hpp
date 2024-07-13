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
        void    openWindow(void);

        void    display(void);
        void    input(void);
        void    update(void);

        void    drawArea(void);

    private:
        bool                isWindowOpen;

        sf::Music           music;
        sf::RenderWindow*   win;
};