#include <windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

// Arrays to store points
float px[200000];
float py[200000];
int pc = 0;  // point count

// Reset arrays
void resetPoints() {
    pc = 0;
}

// Add point to array
void addPoint(float x, float y) {
    px[pc] = x;
    py[pc] = y;
    pc++;
}

// ---------------------- DDA LINE -------------------------
void DDA_Line(float x1, float y1, float x2, float y2)
{
    resetPoints();

    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    float Xinc = dx / steps;
    float Yinc = dy / steps;

    float X = x1;
    float Y = y1;

    for (int i = 0; i <= steps; i++) {
        addPoint(X, Y);
        X += Xinc;
        Y += Yinc;
    }
}

// ------------------ MIDPOINT LINE -------------------------
void Midpoint_Line(float x1, float y1, float x2, float y2)
{
    resetPoints();

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int x, y;

    // Always left to right
    if (x1 > x2) {
        x = x2;
        y = y2;
        x2 = x1;
        y2 = y1;
    } else {
        x = x1;
        y = y1;
    }

    int p = 2 * dy - dx;

    addPoint(x, y);

    while (x < x2)
    {
        x++;

        if (p < 0)
            p += 2 * dy;
        else {
            p += 2 * (dy - dx);
            y++;
        }

        addPoint(x, y);
    }
}

// ------------------ MIDPOINT CIRCLE ----------------------
void Midpoint_Circle(int xc, int yc, int R)
{
    resetPoints();

    int x = 0;
    int y = R;
    int p = 1 - R;

    while (x <= y)
    {
        addPoint(xc + x, yc + y);
        addPoint(xc - x, yc + y);
        addPoint(xc + x, yc - y);
        addPoint(xc - x, yc - y);
        addPoint(xc + y, yc + x);
        addPoint(xc - y, yc + x);
        addPoint(xc + y, yc - x);
        addPoint(xc - y, yc - x);

        if (p < 0)
            p += 2 * x + 3;
        else {
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

// ---------------------- DISPLAY ---------------------------
void display()
{
    glClearColor(0.75f, 0.75f, 0.75f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(1, 0, 0);

    for (int i = 0; i < pc; i++)
        glVertex2f(px[i], py[i]);

    glEnd();
    glFlush();
}

// ---------------------- MAIN ------------------------------
int main(int argc, char** argv)
{
    int choice;
    cout << "Choose Algorithm:\n";
    cout << "1 = DDA Line\n";
    cout << "2 = Midpoint Line\n";
    cout << "3 = Midpoint Circle\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        float x1, y1, x2, y2;
        cout << "Enter x1 y1: ";
        cin >> x1 >> y1;
        cout << "Enter x2 y2: ";
        cin >> x2 >> y2;
        DDA_Line(x1, y1, x2, y2);
    }
    else if (choice == 2)
    {
        float x1, y1, x2, y2;
        cout << "Enter x1 y1: ";
        cin >> x1 >> y1;
        cout << "Enter x2 y2: ";
        cin >> x2 >> y2;
        Midpoint_Line(x1, y1, x2, y2);
    }
    else if (choice == 3)
    {
        int xc, yc, R;
        cout << "Enter center xc yc: ";
        cin >> xc >> yc;
        cout << "Enter radius R: ";
        cin >> R;
        Midpoint_Circle(xc, yc, R);
    }

    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG Algorithms (DDA, Midpoint Line, Circle)");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
