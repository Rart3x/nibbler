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
        void displayMenu(void);
        void input(void);

        size_t getLibCode(void) const;

        void setAreaSize(int h, int w);

    private:
        bool running;

        int height;
        int width;

        size_t libCode;

        GLFWwindow* win;
};
