#pragma once

#include <iostream>

#include <GLFW/glfw3.h>

#include "Library.hpp"

class GL {
    public:
        GL();
        ~GL();

        void display(void);
        void input(void);

    private:
        bool running;

        GLFWwindow* win;
};
