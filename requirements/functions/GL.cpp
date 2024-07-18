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

void GL::drawMap() {
}

void GL::input() {
    static bool pause = false;

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
        if (!pause)
            this->keyCode = PAUSE;
        else
            this->keyCode = GAME;
        pause = !pause;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_W))
    {
        this->keyCode = UP;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_S))
    {
        this->keyCode = DOWN;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_A))
    {
        this->keyCode = LEFT;
    }
    else if (glfwGetKey(this->win, GLFW_KEY_D))
    {
        this->keyCode = RIGHT;
    }
}

void GL::pause() {
    if (this->mode == PAUSE)
        this->mode = GAME;
    else
        this->mode = PAUSE;
}

void GL::update() {
    this->display();
    this->input();
}