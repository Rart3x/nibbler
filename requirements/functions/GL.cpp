#include "../includes/GL.hpp"

extern "C" {
    GL *createGLInstance() {
        return new GL();
    }
}


GL::GL(void) {

    if (!glfwInit()) {
        std::cerr << "Error: Could not initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->running = false;
}

GL::~GL() {
    glfwDestroyWindow(this->win);
    glfwTerminate();
}


void GL::display() {

    this->win = glfwCreateWindow(1000, 1000, "Nibbler OpenGL", NULL, NULL);
    if (!this->win) {
        std::cerr << "Error: Could not create GLFW window" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(this->win);
    this->running = true;

    while (running) {
        input();
        glfwSwapBuffers(this->win);
        glfwPollEvents();
    }
}

void GL::input() {
    if (glfwGetKey(this->win, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        this->running = false;
    }
}