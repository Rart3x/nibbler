#include "../includes/GL.hpp"

extern "C" {
    GL *createGLInstance() {
        return new GL();
    }
}


GL::GL(void) : Library() {
    if (!errorQuitLibWithBool(glfwInit(), "Error: Could not initialize GLFW", this))
        return;
    this->win = glfwCreateWindow(WIDTH, HEIGHT, "Nibbler OpenGL", NULL, NULL);
    if (!errorQuitLibWithObj(this->win, "Error: Could not create GLFW window", this))
        return;
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


void GL::display() {
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
        this->keyCode = NCCODE;
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