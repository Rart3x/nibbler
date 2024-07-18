#pragma once

#include <iostream>

#include <curses.h>

#include "Library.hpp"


class NC : public Library {

    public:
        NC();
        NC(const NC &other);
        NC& operator=(const NC &other);
        ~NC();

        void    display(void);
        void    input(void);
        void    pause(void);
        void    update(void);

        void    drawMap(void);

    private:
        int         cols;
        int         lines;

        WINDOW*     win;
};