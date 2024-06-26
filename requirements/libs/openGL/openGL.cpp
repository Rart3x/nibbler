#include "openGL.hpp"

void printA() {
    printf("test");
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.0, 0.5);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Ma Fenêtre OpenGL");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}