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
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.0f, -1.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.75f, 0.25f);
    glVertex2f(-0.25f, 0.25f);
    glVertex2f(-0.5f, 0.625f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 194, 3);
    glVertex2f(0.375f, 0.25f);
    glVertex2f(0.625f, 0.25f);
    glVertex2f(0.75f, 0.5f);
    glVertex2f(0.625f, 0.75f);
    glVertex2f(0.375f, 0.75f);
    glVertex2f(0.25f, 0.5f);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 0);
    glVertex2f(-0.75f, -0.75f);
    glVertex2f(-0.25f, -0.75f);
    glVertex2f(-0.25f, -0.25f);
    glVertex2f(-0.75f, -0.25f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 132, 3);
    glVertex2f(0.375f, -0.75f);
    glVertex2f(0.625f, -0.75f);
    glVertex2f(0.5f, -0.25f);
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
