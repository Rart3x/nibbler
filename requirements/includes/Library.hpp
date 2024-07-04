#pragma once

#include <iostream>

class Library {

    public:
        Library();
        virtual ~Library();

        virtual void closeWindow() = 0;
        virtual void display() = 0;
        virtual void input() = 0;

        virtual size_t getLibCode() const = 0;

        virtual void setWindowSize(int h, int w) = 0;
    
    private:
        bool running;
        
        int height;
        int width;
    
        size_t libCode;
};