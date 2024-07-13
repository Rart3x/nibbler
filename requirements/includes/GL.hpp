#pragma once

#include <iostream>

#include <GLFW/glfw3.h>

#include "Library.hpp"

class GL : public Library {
    public:
        GL();
        GL(const GL &original);
        GL& operator=(const GL &original);
        ~GL();

        void    closeWindow(void);

        void    display(void);
        void    displayGame(void);
        void    displayPause(void);

        void    input(void);
        void    update(void);

    private:
        GLFWwindow* win;
};
