#include "../includes/GL.hpp"

extern "C" {
    GL *createGLInstance() {
        return new GL();
    }
}


GL::GL(void) : Library() {

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


void GL::closeWindow() {
    if (this->win) {
        glfwDestroyWindow(this->win);
        this->win = NULL;
    }
}


void GL::display() {

    this->win = glfwCreateWindow(this->height, this->width, "Nibbler OpenGL", NULL, NULL);
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
        this->libCode = 404;
        this->running = false;
    } else if (glfwGetKey(this->win, GLFW_KEY_2) == GLFW_PRESS) {
        this->libCode = 1;
        this->running = false;
    } else if (glfwGetKey(this->win, GLFW_KEY_3) == GLFW_PRESS) {
        this->libCode = 2;
        this->running = false;
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


size_t GL::getLibCode(void) const {
    return this->libCode;
}

void GL::setAreaSize(int h, int w) {
    this->height = h;
    this->width = w;
}