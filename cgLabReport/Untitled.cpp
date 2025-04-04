#include <GL/glut.h>

void init() {
    glEnable(GL_DEPTH_TEST);  // Enable depth testing for 3D rendering
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Black background
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear buffers
    glLoadIdentity();
    
    glTranslatef(0.0, 0.0, -5.0);  // Move sphere back into scene
    
    GLUquadric* quad;
    quad = gluNewQuadric();
    gluSphere(quad, 1.0, 50, 50);  // Draw sphere with radius 1.0

    glutSwapBuffers();  // Swap buffers for smooth rendering
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Sphere");

    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    
    return 0;
}

