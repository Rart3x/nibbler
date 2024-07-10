#include "../includes/GL.hpp"

extern "C" {
    GL *createGLInstance() {
        return new GL();
    }
}


GL::GL(void) : Library() {
    if (!errorQuitLibWithBool(glfwInit(), "Error: Could not initialize GLFW", this))
        return;

    this->win = NULL;
}


GL::GL(const GL &original) {
    *this = original;
}


GL& GL::operator=(const GL &original) {
    if (this != &original)
    {
        this->height = original.height;
        this->width = original.width;
        this->libCode = original.libCode;
        this->mode = original.mode;
        this->prevMode = original.prevMode;
        this->running = original.running;
        this->winH = original.winH;
        this->winW = original.winW;
        this->win = original.win;
    }
    return *this;
}


GL::~GL() {
    if (this->win)
        glfwDestroyWindow(this->win);
    glfwTerminate();
}


void GL::closeWindow() {
    if (this->win)
    {
        glfwDestroyWindow(this->win);
        this->win = NULL;
    }
}


void GL::display() {
    if (this->win)
        this->closeWindow();
    this->win = glfwCreateWindow(WIDTH, HEIGHT, "Nibbler OpenGL", NULL, NULL);
    if (!errorQuitLibWithObj(this->win, "Error: Could not create GLFW window", this))
        return;

    glfwMakeContextCurrent(this->win);
    
    this->running = true;

    while (this->running)
    {
        this->input();
        glfwSwapBuffers(this->win);
        glfwPollEvents();
    }
}


void GL::input() {
    if (glfwGetKey(this->win, GLFW_KEY_ESCAPE))
    {
        this->libCode = QUIT;
        this->running = false;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_1))
    {
        this->libCode = 0;
        this->running = false;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_2))
    {
        this->libCode = 1;
        this->running = false;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_SPACE))
    {
        if (this->mode == 0)
            this->mode = 1;
        else if (this->mode == 1)
            this->mode = 2;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_W))
    {
        return;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_A))
    {
        return;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_S))
    {
        return;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_D))
    {
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

void GL::setMode(int code) {
    this->mode = code;
}

void GL::setRunning() {
    this->running = true;
}

void GL::setWinSize(int h, int w) {
    this->winH = h;
    this->winW = w;
}