#pragma once

#include <iostream>

#include <GLFW/glfw3.h>

#include "Library.hpp"

class GL : public Library {
    public:
        GL();
        GL(const GL &original);
        GL& operator=(const GL &original);
        virtual ~GL();
        
        void    display(void);
        void    input(void);
        void    update(void);

    private:
        GLFWwindow* win;
};
