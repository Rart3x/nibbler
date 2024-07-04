#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Library.hpp"

class SFML : public Library {
    public:
        SFML();
        ~SFML();

        void closeWindow(void);    
        void display(void);
        void input(void);

        unsigned int getLibCode(void) const;

    private:
        bool running;
        unsigned int libCode;

        sf::RenderWindow* win;
};