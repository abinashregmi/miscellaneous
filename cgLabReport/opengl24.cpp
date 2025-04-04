#include <GL/glut.h>

void initOpenGL() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_QUADS);
    glVertex2f(100.0, 100.0);
    glVertex2f(400.0, 100.0);
    glVertex2f(400.0, 400.0);
    glVertex2f(100.0, 400.0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("SQUARE");

    initOpenGL();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
