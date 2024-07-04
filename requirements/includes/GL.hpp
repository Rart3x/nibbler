#pragma once

#include <iostream>

#include <GLFW/glfw3.h>

#include "Library.hpp"

class GL : public Library {
    public:
        GL();
        ~GL();

        void closeWindow(void);
        void display(void);
        void input(void);

        unsigned int getLibCode(void) const;

    private:
        bool running;
        unsigned int libCode;

        GLFWwindow* win;
};
