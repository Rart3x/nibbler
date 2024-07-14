#pragma once

#include <iostream>

#include <curses.h>

#include "Library.hpp"


class NC : public Library {

    public:
        NC();
        NC(const NC &other);
        NC& operator=(const NC &other);
        virtual ~NC();

        void    display(void);
        void    input(void);
        void    update(void);

    private:
        WINDOW*     win;
};