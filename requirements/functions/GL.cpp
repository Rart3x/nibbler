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

    while (this->running) {
        this->input();
        glfwSwapBuffers(this->win);
        glfwPollEvents();
    }
}


void GL::input() {
    if (glfwGetKey(this->win, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        this->running = false;
    } else if (glfwGetKey(this->win, GLFW_KEY_1) == GLFW_PRESS) {
        return;
    } else if (glfwGetKey(this->win, GLFW_KEY_2) == GLFW_PRESS) {
        return;
    } else if (glfwGetKey(this->win, GLFW_KEY_3) == GLFW_PRESS) {
        return;
    } else if (glfwGetKey(this->win, GLFW_KEY_W) || glfwGetKey(this->win, GLFW_KEY_UP)) {
        return;
    } else if (glfwGetKey(this->win, GLFW_KEY_A) || glfwGetKey(this->win, GLFW_KEY_LEFT)) {
        return;
    } else if (glfwGetKey(this->win, GLFW_KEY_S) || glfwGetKey(this->win, GLFW_KEY_DOWN)) {
        return;
    } else if (glfwGetKey(this->win, GLFW_KEY_D) || glfwGetKey(this->win, GLFW_KEY_RIGHT)) {
        return;
    }
}