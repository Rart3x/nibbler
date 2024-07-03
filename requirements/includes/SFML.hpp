#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Library.hpp"

class SFML {
    public:
        SFML();
        ~SFML();

        void display(void);
        void input(void);

    private:
        bool running;

        sf::RenderWindow* win;
};