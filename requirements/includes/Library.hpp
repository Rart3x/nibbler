#pragma once

#include <iostream>
#include <vector>

#include "Defines.hpp"
#include "Errors.hpp"


class Library {

    public:
        Library();
        virtual ~Library();

        virtual void    closeWindow() = 0;
        virtual void    display() = 0;
        virtual void    input() = 0;
        virtual void    update() = 0;

        virtual int     getKeyCode() const;

        virtual void    setAreaSize(int h, int w);
        virtual void    setKeyCode(int code);
        virtual void    setMode(int code);
        virtual void    setRunning();
        virtual void    setWinSize(int h, int w);
    
    protected:
        bool    running;

        int     keyCode;
        int     libCode;
        
        int     mode;
        int     prevMode;

        int     height;
        int     width;

        int     winH;
        int     winW;

        std::string key;
        std::vector<std::string> map;
};