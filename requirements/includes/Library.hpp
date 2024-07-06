#pragma once

#include <iostream>

#define SQUARE  5

#define WIDTH   500
#define HEIGHT  500

#define ARIAL   "./requirements/ressources/fonts/arial.ttf"
#define SCIENCE "./requirements/ressources/fonts/science.ttf"

class Library {

    public:
        Library();
        virtual ~Library();

        virtual void closeWindow() = 0;
        virtual void display() = 0;
        virtual void input() = 0;

        virtual size_t getLibCode() const = 0;

        virtual void setAreaSize(int h, int w) = 0;
        virtual void setWinSize(int h, int w) = 0;
    
    private:
        bool running;
        
        int height;
        int width;

        int winH;
        int winW;
    
        size_t libCode;
};