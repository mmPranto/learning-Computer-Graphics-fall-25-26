#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */


void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.0f, -1.0f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.3f, 0.3f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(-0.5f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.4f, -0.2f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);

    glVertex2f(0.26f, 0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.24f, -0.04f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.3f, -0.1f);

    glVertex2f(0.4f, -0.2f);
    glVertex2f(0.38f,-0.04f);
    glVertex2f(0.5f,0.1f);
    glVertex2f(0.34f,0.1f);
    glVertex2f(0.3f,0.3f);

    glEnd();




    




     glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480); // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
