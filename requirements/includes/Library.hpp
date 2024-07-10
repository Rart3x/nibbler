#pragma once

#include <iostream>

#include "Defines.hpp"
#include "Errors.hpp"

class Library {

    public:
        Library();
        virtual ~Library();

        virtual void    closeWindow() = 0;
        virtual void    display() = 0;
        virtual void    input() = 0;

        virtual size_t  getLibCode() const = 0;

        virtual void    setAreaSize(int h, int w) = 0;
        virtual void    setLibCode(int code) = 0;
        virtual void    setRunning() = 0;
        virtual void    setWinSize(int h, int w) = 0;
    
    protected:
        bool    running;
        
        int     libCode;
        
        int     height;
        int     width;

        int     winH;
        int     winW;
};