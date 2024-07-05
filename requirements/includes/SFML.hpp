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

        size_t getLibCode(void) const;

        void setAreaSize(int h, int w);

    private:
        bool running;
        
        int height;
        int width;

        size_t libCode;

        sf::RenderWindow* win;
};