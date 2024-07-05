#pragma once

#include <iostream>

#define SQUARE 5

class Library {

    public:
        Library();
        virtual ~Library();

        virtual void closeWindow() = 0;
        virtual void display() = 0;
        virtual void input() = 0;

        virtual size_t getLibCode() const = 0;

        virtual void setAreaSize(int h, int w) = 0;
    
    private:
        bool running;
        
        int height;
        int width;
    
        size_t libCode;
};