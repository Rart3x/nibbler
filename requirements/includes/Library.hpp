#pragma once

#include <iostream>
#include <vector>

#include "Defines.hpp"
#include "Errors.hpp"


class Library {

    public:
        Library();
        virtual ~Library();

        virtual void    display() = 0;
        virtual void    input() = 0;
        virtual void    pause() = 0;
        virtual void    update() = 0;

        virtual int     getKeyCode() const;
        virtual std::vector<std::string> getMap() const;

        virtual void    setAreaSize(int h, int w);
        virtual void    setKeyCode(int code);
        virtual void    setMap(std::vector<std::string> map);
        virtual void    setMode(int code);
    
    protected:
        int     keyCode;
        int     libCode;
        
        int     mode;

        int     height;
        int     width;

        std::vector<std::string> map;
};