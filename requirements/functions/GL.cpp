#include "../includes/GL.hpp"

extern "C" {
    GL *createGLInstance() {
        return new GL();
    }
}


GL::GL(void) : Library() {
    if (!glfwInit()) {
        std::cerr << "Error: Could not initialize GLFW" << std::endl;
        this->libCode = 404;
        return;    
    }
    this->mode = 0;
    this->win = NULL;
    this->running = false;
}


GL::~GL() {
    if (this->win)
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
    this->win = glfwCreateWindow(WIDTH, HEIGHT, "Nibbler OpenGL", NULL, NULL);
    if (!this->win) {
        std::cerr << "Error: Could not create GLFW window" << std::endl;
        this->libCode = 404;
        return;
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
    if (glfwGetKey(this->win, GLFW_KEY_ESCAPE)) {
        this->libCode = 404;
        this->running = false;
    } else if (glfwGetKey(this->win, GLFW_KEY_1)) {
        this->libCode = 0;
        this->running = false;
    } else if (glfwGetKey(this->win, GLFW_KEY_2)) {
        this->libCode = 1;
        this->running = false;
    } else if (glfwGetKey(this->win, GLFW_KEY_SPACE)) {
        if (this->mode == 0)
            this->mode = 1;
        else if (this->mode == 1)
            this->mode = 2;
    } else if (glfwGetKey(this->win, GLFW_KEY_W)) {
        return;
    } else if (glfwGetKey(this->win, GLFW_KEY_A)) {
        return;
    } else if (glfwGetKey(this->win, GLFW_KEY_S)) {
        return;
    } else if (glfwGetKey(this->win, GLFW_KEY_D)) {
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

void GL::setLibCode(int code) {
    this->libCode = code;
}

void GL::setRunning() {
    this->running = true;
}

void GL::setWinSize(int h, int w) {
    this->winH = h;
    this->winW = w;
}