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
        void displayGame(void);
        void displayMenu(void);

        void drawButton(std::string text, sf::Vector2f position, sf::Vector2f size, sf::Color color);
        
        void input(void);

        size_t getLibCode(void) const;

        void setAreaSize(int h, int w);
        void setWinSize(int h, int w);

    private:
        bool running;

        int height;
        int width;

        int winH;
        int winW;

        int selectedButton;

        int mode;

        size_t libCode;

        sf::RenderWindow* win;
};