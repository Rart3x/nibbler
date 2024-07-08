#pragma once

#include <iostream>

#include <GLFW/glfw3.h>

#include "Library.hpp"

class GL : public Library {
    public:
        GL();
        ~GL();

        void    closeWindow(void);

        void    display(void);
        void    displayGame(void);
        void    displayPause(void);

        void    input(void);

        size_t  getLibCode(void) const;

        void    setAreaSize(int h, int w);
        void    setWinSize(int h, int w);

    private:
        bool    running;

        int     height;
        int     width;

        int     mode;

        int     winH;
        int     winW;

        size_t  libCode;

        GLFWwindow* win;
};
