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
        void displayMenu(void);
        void drawText(std::string text, float x, float y, sf::Color color, float fontSize);
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