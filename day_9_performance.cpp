#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */


void display() {
    glClearColor(0.75f, 0.75f, 0.75f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

 
    //palestine 
    glBegin(GL_POLYGON);
    glColor3ub(16, 99, 30);
    glVertex2f(0.25f, -0.25f); // (10,-10)
    glVertex2f(0.5f, -0.5f); //(20,-20)
    glVertex2f(0.25f, -0.75f); //(10,-30)
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(199, 26, 26);
    glVertex2f(0.25f, -0.25f);//(10,-10)
    glVertex2f(0.875f, -0.25f);//(35,-10)
    glVertex2f(0.875f, -0.425f);//(35,-17)
    glVertex2f(0.425f, -0.425);//(17,-17)
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(0.875f, -0.425f);//(35,-17)
    glVertex2f(0.875f, -0.575f);//(35,-23)
    glVertex2f(0.425f, -0.575f);//(17,-23)
    glVertex2f(0.5f, -0.5f);//(20,-20)
    glVertex2f(0.425f, -0.425f);//(17,-17)
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.425f, -0.575f);//(17,-23)
    glVertex2f(0.875f, -0.575f);//(35,-23)
    glVertex2f(0.875f, -0.75f);//(35,-30)
    glVertex2f(0.25f, -0.75f);//(10,-30)
    glEnd();

    //Vietnam
    glBegin(GL_POLYGON);
    glColor3ub(255, 25, 25);
    glVertex2f(-0.875f, -0.25f); //(-35,-10)
    glVertex2f(-0.25f, -0.25f);//(-10,-10)
    glVertex2f(-0.25f, -0.75f);//(-10,-30)
    glVertex2f(-0.875f, -0.75f);//(-35,-30)
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(242, 224, 22);
    glVertex2f(-0.525f, -0.5f); //1   (-21,-20)
    glVertex2f(-0.425f,-0.5f);  //2   (-17,-20)
    glVertex2f(-0.5f,-0.55f);  //3    (-20,-22)
    glVertex2f(-0.5f,-0.625f);  //4   (-20,-25)
    glVertex2f(-0.55f,-0.575f);  //5  (-22,-23)
    glVertex2f(-0.625f,-0.625f);  //6 (-25,-25)
    glVertex2f(-0.6f,-0.55f);  //7     (-24,-22)
    glVertex2f(-0.675f,-0.5f);  //8   (-27,-20)
    glVertex2f(-0.6f,-0.5f);  //9      (-24,-20)
    glVertex2f(-0.55f,-0.375f);  //10 (-22,-15)
    glEnd();


    //Syria flag
    glBegin(GL_POLYGON);
    glColor3ub(186, 6, 6);
    glVertex2f(-0.875f,0.75f);//(-35,30)
    glVertex2f(-0.25f,0.75f);//(-10,30)
    glVertex2f(-0.25f,0.6f);//(-10,24)
    glVertex2f(-0.875f, 0.6f);//(-35,24)
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(-0.875f,0.6f);//(-35,24)
    glVertex2f(-0.25f,0.6f);//(-10,24)
    glVertex2f(-0.25f,0.4f);//(-10,16)
    glVertex2f(-0.875f,0.4f);//(-35,16)
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2f(-0.875f,0.4f);//(-35,16)
    glVertex2f(-0.25f,0.4f);//(-10,16)
    glVertex2f(-0.25f,0.25f);//(-10,10)
    glVertex2f(-0.875f,0.25f);//(-35,10)
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(7,130,13);
    glVertex2f(-0.425f, 0.5f);//1
    glVertex2f(-0.375f, 0.5f);//2
    glVertex2f(-0.4125f, 0.475f);//3
    glVertex2f(-0.4f, 0.425f);//4
    glVertex2f(-0.4375f, 0.45f);//5
    glVertex2f(-0.475f, 0.425f);//6
    glVertex2f(-0.4625f, 0.4625f);//7
    glVertex2f(-0.525f, 0.5f);//8
    glVertex2f(-0.4625f, 0.5f);//9
    glVertex2f(-0.45f, 0.55f);//10
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(7, 130, 13);
    glVertex2f(-0.6625f, 0.5f);//1
    glVertex2f(-0.6f, 0.5f);//2
    glVertex2f(-0.65f, 0.4625f);//3
    glVertex2f(-0.625f, 0.425f);//4
    glVertex2f(-0.6625f, 0.45f);//5
    glVertex2f(-0.7f, 0.425f);//6
    glVertex2f(-0.7f, 0.4625f);//7
    glVertex2f(-0.75f, 0.5f);//8
    glVertex2f(-0.6875f, 0.5f);//9
    glVertex2f(-0.675f, 0.55f);//10
    glEnd();



    //Israel flag
    glBegin(GL_POLYGON);
    glColor3ub(19,26,120);
    glVertex2f(0.25f,0.75f);//(10,30)
    glVertex2f(0.875f,0.75f);//(35,30)
    glVertex2f(0.875f,0.625f);//(35,25)
    glVertex2f(0.25f,0.625f);//(10,25)
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
    glVertex2f(0.25f,0.625f);//(10,25)
    glVertex2f(0.875f,0.625f);//(35,25)
    glVertex2f(0.875f,0.375f);//(35,15)
    glVertex2f(0.25f,0.375f);//(10,15)
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(19,26,120);
    glVertex2f(0.25f,0.375f);//(10,15)
    glVertex2f(0.875f,0.375f);//(35,15)
    glVertex2f(0.875f,0.25f);//(35,10)
    glVertex2f(0.25f,0.25f);//(10,10)
    glEnd();


    glLineWidth(12);
    glBegin(GL_LINE_LOOP);
    glColor3ub(19,26,120);
    glVertex2f(0.55f, 0.6f);//(22,24)
    glVertex2f(0.65f,0.45f);//(26,18)
    glVertex2f(0.45f, 0.45f);//(18,18)
    glEnd();

    glLineWidth(12);
    glBegin(GL_LINE_LOOP);
    glColor3ub(19, 26, 120);
    glVertex2f(0.45f,0.55f);//(18,22)
    glVertex2f(0.65f,0.55f);//(26,22)
    glVertex2f(0.55f, 0.4f);//(22,16)

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
