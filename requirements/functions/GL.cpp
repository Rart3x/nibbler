#include "../includes/GL.hpp"

extern "C" {
    GL *createGLInstance() {
        return new GL();
    }
}


GL::GL(void) : Library() {
    if (!errorQuitLibWithBool(glfwInit(), "Error: Could not initialize GLFW", this))
        return;
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    this->win = glfwCreateWindow(WIDTH, HEIGHT, "Nibbler OpenGL", NULL, NULL);
    if (!errorQuitLibWithObj(this->win, "Error: Could not create GLFW window", this))
        return;
    this->isWindowOpen = false;
}

GL::GL(const GL &original) {
    *this = original;
}

GL& GL::operator=(const GL &original) {
    if (this != &original)
    {
        this->height = original.height;
        this->width = original.width;
        this->keyCode = original.keyCode;
        this->mode = original.mode;
        this->prevMode = original.prevMode;
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
        std::cout << "Closing window" << std::endl;
        glfwHideWindow(this->win);   
        this->isWindowOpen = false;
    }
}

void GL::openWindow() {
    if (this->win)
    {
        std::cout << "Opening window" << std::endl;
        glfwShowWindow(this->win);
        this->isWindowOpen = true;
    }
}

void GL::display() {
    if (this->win && !this->isWindowOpen)
        this->openWindow();

    glfwMakeContextCurrent(this->win);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(this->win);
    glfwPollEvents();
}

void GL::input() {
    if (glfwGetKey(this->win, GLFW_KEY_ESCAPE))
    {
        this->keyCode = QUIT;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_1))
    {
        this->keyCode = SFMLCODE;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_2))
    {
        this->keyCode = SDLCODE;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_SPACE))
    {
        return;
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

void GL::update() {
    this->input();
    this->display();
}