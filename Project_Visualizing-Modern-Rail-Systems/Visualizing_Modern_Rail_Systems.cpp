#include <windows.h> 
#include <GL/glut.h>
#include <cmath>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <bits/stdc++.h>
#include <GL/glu.h>
#include <math.h>
#include <stdlib.h>
#include <mmsystem.h> 
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int currentFrame = 1;

float trainX = 1400.0f;   
bool trainMoving = false;
bool trainStopping = false;
bool trainLeaving = false;
int stopCounter = 0;


float doorOffset = 0.0f;
bool doorOpening = false;
bool doorClosing = false;
const float DOOR_MAX = 75.0f;   
const float DOOR_SPEED = 1.2f;
const int DOOR_OPEN_TIME = 200;


bool isDay = true;
float cloud1X = 100.0f;
float cloud2X = 450.0f;
float cloud3X = 800.0f;

const float CLOUD1_SPEED = 0.5f;
const float CLOUD2_SPEED = 0.8f;
const float CLOUD3_SPEED = 0.3f;





GLfloat trainPos = -300.0f;
GLfloat boatPos  = 0.0f;

GLfloat trainSpeed = 2.8f;
GLfloat boatSpeed  = 0.3f;

#define PI 3.14159265358979323846

float trainPos1 = -800;
float carPos1  = -800;  // Start left
float carPos2  = 1200;  // Start right
float wheelAngle = 0;   // wheel rotation
float trainWheelAngle = 0; // Separate angle for train wheels




float trainX5 = -400;
float gateAngle = 0;
bool gateDown = true;
bool lightOn = true;
float smokeOffset = 0;





void drawTrain()
{
    //train
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2i(694, 199); //w2
    glVertex2i(479, 199); //z2
    glVertex2i(142, 199);//a3
    glVertex2i(145, 228);//b3
    glVertex2i(150, 248);//c3
    glVertex2i(168, 278);//d3
    glVertex2i(228, 354);//e3
    glVertex2i(250, 371);//f3
    glVertex2i(266, 378);//g3
    glVertex2i(465, 378);//h3=
    glVertex2i(694, 378);//i3
    glVertex2i(694, 205);//l3
    glVertex2i(694, 199); //w2
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2i(694, 354); //j3
    glVertex2i(713, 354);//k3
    glVertex2i(713, 205);//m3
    glVertex2i(694, 205);//l3
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2i(713,378); //N3
    glVertex2i(1195,378);//q3
    glVertex2i(1195,199);//r3
    glVertex2i(713,199);//o3
    glEnd();


    //train design first box

    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2i(243.53,365); //z4
    glVertex2i(694,365);//e5
    glVertex2i(694,357);
    glVertex2i(232.94,357);
    glEnd();

    //first bogi glass
    glBegin(GL_POLYGON);
    glColor3ub(25, 43, 66);
    glVertex2i(222.07, 346.08);//e5
    glVertex2i(268.73, 345.81);//f5
    glVertex2i(252.28, 290.68);//g5
    glVertex2i(249.58, 286.67);//i5
    glVertex2i(243.76,280.95);//k5
    glVertex2i(239.16,277.85);//p5
    glVertex2i(209.04, 277.74);//r5
    glVertex2i(168.45, 278.16);//d3
    glVertex2i(222.07, 346.08);//e5
    glEnd();

    //door just black
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2i(294.18,353.72);
    glVertex2i(369.57,353.72);
    glVertex2i(369.57,199);
    glVertex2i(294.18,199);
    glEnd();

    //actual door for first bogi

    glPushMatrix();
    glTranslatef(doorOffset, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(250,250,250);
    glVertex2i(294.18,353.72);
    glVertex2i(369.57,353.72);
    glVertex2i(369.57,199);
    glVertex2i(294.18,199);
    glEnd();

    //door glass
    glBegin(GL_POLYGON);
    glColor3ub(25, 43, 66);
    glVertex2i(299.83,345.79);//z6
    glVertex2i(361.97,345.79);
    glVertex2i(361.97,277.95);
    glVertex2i(299.83,277.95);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(33, 65, 105);
    glVertex2i(293.90,269.39);//D7
    glVertex2i(369.57,269.39);
    glVertex2i(369.57,262.74);
    glVertex2i(293.87,262.74);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(43, 43, 43);
    glVertex2i(293.72,214.44);//L7
    glVertex2i(369.57,214.44);
    glVertex2i(369.57,199);
    glVertex2i(293.72,199);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(184, 184, 184);
    glVertex2i(294.18,353.72);
    glVertex2i(369.57,353.72);
    glVertex2i(369.57,199);
    glVertex2i(294.18, 199);
    glVertex2i(294.18, 353.72);
    glVertex2i(294.18, 199);
    glVertex2i(369.57,353.72);
    glVertex2i(369.57,199);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(250,0,0);
    glVertex2i(293.81,243.40);//h7
    glVertex2i(369.57,243.40);
    glVertex2i(369.57,228.82);
    glVertex2i(293.76,228.82);
    glEnd();


    glPopMatrix();



    //first bogi 2nd door
    //door just black
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2i(577.57,353.72);
    glVertex2i(653.49,353.72);
    glVertex2i(653.49,199);
    glVertex2i(577.57,199);
    glEnd();


    glPushMatrix();
    glTranslatef(doorOffset, 0, 0);

    //actual door for first bogi
    glBegin(GL_POLYGON);
    glColor3ub(250,250,250);
    glVertex2i(577.57,353.72);//r7
    glVertex2i(653.49,353.72);//s7
    glVertex2i(653.49,199);//t7
    glVertex2i(577.57,199);//u7
    glEnd();

    //door glass
    glBegin(GL_POLYGON);
    glColor3ub(25, 43, 66);
    glVertex2i(584.57,345.79);
    glVertex2i(647.005,345.79);
    glVertex2i(647.005,277.95);
    glVertex2i(584.57,277.95);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(33, 65, 105);
    glVertex2i(577.57,269.39);//
    glVertex2i(653.49,269.39);
    glVertex2i(653.49,262.74);
    glVertex2i(577.57,262.74);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(43, 43, 43);
    glVertex2i(577.57,214.44);//
    glVertex2i(653.49,214.44);
    glVertex2i(653.49,199);
    glVertex2i(577.57,199);
    glEnd();

    


    glBegin(GL_POLYGON);
    glColor3ub(250,0,0);
    glVertex2i(577.57,243.40);
    glVertex2i(653.49,243.40);
    glVertex2i(653.49,228.82);
    glVertex2i(577.57,228.82);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(184, 184, 184);
    glVertex2i(577.57,353.72);//r7
    glVertex2i(653.49,353.72);//s7
    glVertex2i(653.49,199);//t7
    glVertex2i(577.57,199);//u7
    glVertex2i(577.57,353.72);//r7
    glVertex2i(577.57,199);//u7
    glVertex2i(653.49,353.72);//s7
    glVertex2i(653.49,199);//t7

    glEnd();

    glPopMatrix();




    //first bogi boro glass
    glBegin(GL_POLYGON);
    glColor3ub(25, 43, 66);
    glVertex2i(391.75,345.79);//r9
    glVertex2i(555.71,345.79);
    glVertex2i(555.71,277.95);
    glVertex2i(391.44,277.95);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(250,0,0);
    glVertex2i(149.16,243.40);//v9
    glVertex2i(292,243.40);
    glVertex2i(292,228.82);
    glVertex2i(145.39,228.82);//w9
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(33, 65, 105);
    glVertex2i(369.57,269.39);//e7
    glVertex2i(577,269.39);//
    glVertex2i(577,262.74);//
    glVertex2i(369.57,262.74);//f7
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(33, 65, 105);
    glVertex2i(655,269.39);//
    glVertex2i(693.89,269.39);//z9
    glVertex2i(693.89,262.74);//A10
    glVertex2i(655,262.74);//
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(250,0,0);
    glVertex2i(371,243.40);//i7
    glVertex2i(577,243.40);//j10
    glVertex2i(577,228.82);//k10
    glVertex2i(371.57,228.82);//
    glEnd();


     glBegin(GL_POLYGON);
    glColor3ub(250,0,0);
    glVertex2i(655,243.40);//f10
    glVertex2i(693.89,243.40);//
    glVertex2i(693.89,228.82);//
    glVertex2i(655,228.82);//
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(43, 43, 43);
    glVertex2i(371,214.44);//m7
    glVertex2i(576,214.44);//
    glVertex2i(576,199);//
    glVertex2i(371.57,199);//
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(43, 43, 43);
    glVertex2i(655,214.44);//
    glVertex2i(693.89,214.44);
    glVertex2i(693.89,199);
    glVertex2i(655.57,199);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(43, 43, 43);
    glVertex2i(143.49,214.44);//
    glVertex2i(292,214.44);
    glVertex2i(292,199);
    glVertex2i(141.51,199);
    glEnd();







    //start 2nd bogi design

    //door just black
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2i(781.18,353.72);
    glVertex2i(856.44,353.72);
    glVertex2i(856.44,199);
    glVertex2i(781.18,199);
    glEnd();


    glPushMatrix();
    glTranslatef(doorOffset, 0, 0);

    
    //actual door for first bogi
    glBegin(GL_POLYGON);
    glColor3ub(250,250,250);
    glVertex2i(781.18,353.72);
    glVertex2i(856.44,353.72);
    glVertex2i(856.44,199);
    glVertex2i(781.18,199);
    glEnd();

    //door glass
    glBegin(GL_POLYGON);
    glColor3ub(25, 43, 66);
    glVertex2i(787.62,345.79);
    glVertex2i(849.65,345.79);
    glVertex2i(849.65,277.95);
    glVertex2i(787.62,277.95);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(33, 65, 105);
    glVertex2i(781.18,269.39);//
    glVertex2i(856.44,269.39);
    glVertex2i(856.44,262.74);
    glVertex2i(781.18,262.74);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(43, 43, 43);
    glVertex2i(781.18,214.44);//
    glVertex2i(856.44,214.44);
    glVertex2i(856.44,199);
    glVertex2i(781.18,199);
    glEnd();

    


    glBegin(GL_POLYGON);
    glColor3ub(250,0,0);
    glVertex2i(781.18,243.40);
    glVertex2i(856.44,243.40);
    glVertex2i(856.44,228.82);
    glVertex2i(781.18,228.82);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(184, 184, 184);
    glVertex2i(781.18,353.72);
    glVertex2i(856.44,353.72);
    glVertex2i(856.44,199);
    glVertex2i(781.18,199);
    glVertex2i(781.18,353.72);
    glVertex2i(781.18,199);
    glVertex2i(856.44,353.72);
    glVertex2i(856.44,199);

    glEnd();

    glPopMatrix();


    glBegin(GL_POLYGON);
    glColor3ub(250,0,0);
    glVertex2i(713.24,366.51);
    glVertex2i(1194.59,366.51);
    glVertex2i(1194.56,358.46);
    glVertex2i(713.24,358.46);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(25, 43, 66);
    glVertex2i(731.41,345.79); 
    glVertex2i(762.99,345.79);
    glVertex2i(762.99,277.95);
    glVertex2i(731.41,277.95);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(33, 65, 105);
    glVertex2i(713,269.39);//p11
    glVertex2i(780.18,269.39);
    glVertex2i(780.18,262.74);
    glVertex2i(713,262.74);//q11
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250,0,0);
    glVertex2i(713,243.40);
    glVertex2i(780.18,243.40);
    glVertex2i(780.18,228.82);
    glVertex2i(713,228.82);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(43, 43, 43);
    glVertex2i(713,214.44);
    glVertex2i(780.18,214.44);
    glVertex2i(780.18,199);
    glVertex2i(713,199);
    glEnd();






    //2nd bogi 2nd door
    //door just black
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2i(1065.92,353.72);
    glVertex2i(1141.41,353.72);
    glVertex2i(1141.41,199);
    glVertex2i(1065.92,199);
    glEnd();


    glPushMatrix();
    glTranslatef(doorOffset, 0, 0);


    //actual door for first bogi
    glBegin(GL_POLYGON);
    glColor3ub(250,250,250);
    glVertex2i(1065.92,353.72);
    glVertex2i(1141.41,353.72);
    glVertex2i(1141.41,199);
    glVertex2i(1065.92,199);
    glEnd();

    //door glass
    glBegin(GL_POLYGON);
    glColor3ub(25, 43, 66);
    glVertex2i(1072.53,345.79);
    glVertex2i(1134.61,345.79);
    glVertex2i(1134.61,277.95);
    glVertex2i(1072.53,277.95);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(33, 65, 105);
    glVertex2i(1065.99,269.39);//
    glVertex2i(1141.41,269.39);
    glVertex2i(1141.41,262.74);
    glVertex2i(1065.99,262.74);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(43, 43, 43);
    glVertex2i(1065.99,214.44);//
    glVertex2i(1141.41,214.44);
    glVertex2i(1141.41,199);
    glVertex2i(1065.99,199);
    glEnd();

    


    glBegin(GL_POLYGON);
    glColor3ub(250,0,0);
    glVertex2i(1065.99,243.40);
    glVertex2i(1141.41,243.40);
    glVertex2i(1141.41,228.82);
    glVertex2i(1065.99,228.82);
    glEnd();


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(184, 184, 184);
    glVertex2i(1065.92,353.72);
    glVertex2i(1141.41,353.72);
    glVertex2i(1141.41,199);
    glVertex2i(1065.92,199);
    glVertex2i(1065.92,353.72);
    glVertex2i(1065.92,199);
    glVertex2i(1141.41,353.72);
    glVertex2i(1141.41,199);

    glEnd();

    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3ub(25, 43, 66);
    glVertex2i(1165.65,345.79);
    glVertex2i(1187.88,345.79);
    glVertex2i(1187.88,277.95);
    glVertex2i(1165.65,277.95);
    glEnd();


     glBegin(GL_POLYGON);
    glColor3ub(33, 65, 105);
    glVertex2i(1142,269.39);//
    glVertex2i(1194.59,269.39);
    glVertex2i(1194.59,262.74);
    glVertex2i(1142,262.74);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(43, 43, 43);
    glVertex2i(1142,214.44);//
    glVertex2i(1194.59,214.44);
    glVertex2i(1194.59,199);
    glVertex2i(1142,199);
    glEnd();

    


    glBegin(GL_POLYGON);
    glColor3ub(250,0,0);
    glVertex2i(1142,243.40);
    glVertex2i(1194.59,243.40);
    glVertex2i(1194.59,228.82);
    glVertex2i(1142,228.82);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(25, 43, 66);
    glVertex2i(879.01,345.79);
    glVertex2i(1043.02,345.79);
    glVertex2i(1043.02,277.95);
    glVertex2i(879.01,277.95);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(33, 65, 105);
    glVertex2i(857,269.39);//
    glVertex2i(1065,269.39);
    glVertex2i(1065.59,262.74);
    glVertex2i(857,262.74);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(43, 43, 43);
    glVertex2i(857,214.44);//
    glVertex2i(1065,214.44);
    glVertex2i(1065,199);
    glVertex2i(857,199);
    glEnd();

    


    glBegin(GL_POLYGON);
    glColor3ub(250,0,0);
    glVertex2i(857,243.40);
    glVertex2i(1065,243.40);
    glVertex2i(1065,228.82);
    glVertex2i(857,228.82);
    glEnd();

}











void drawCircle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float a = i * 3.1416f / 180;
        glVertex2f(cx + cos(a) * r, cy + sin(a) * r);
    }
    glEnd();
}

void drawSun() {
    glColor3ub(255, 215, 0);
    drawCircle(1050, 720, 35);
}

void drawMoon() {
    glColor3ub(230, 230, 230);
    drawCircle(1050, 720, 30);
}

void drawCloud(float x, float y) {
    if (isDay)
        glColor3ub(255, 255, 255);
    else
        glColor3ub(180, 180, 200);

    drawCircle(x, y, 25);
    drawCircle(x + 30, y + 10, 30);
    drawCircle(x + 60, y, 25);
}





void line(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}
// line Loop
void lineLoopQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}
// quad
void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}
// triangle
void triangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}
// circle
void circle(float x, float y, float radius, int segments = 100)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++)
    {
        float theta = 2.0f * M_PI * float(i) / float(segments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

float cloudX = 0;
bool cloudMove = false;
float trainX1 = 0;
bool trainMove = false;

void a_sky()
{
    glColor3ub(135, 206, 235);
    quad(0, 800, 1200, 800, 1200, 600, 0, 600);
}
void a_sun()
{
    glColor3ub(255, 223, 0);
    circle(800, 660, 40);
}
void a_cloud_1()
{
    glColor3ub(255, 255, 255);
    circle(330, 710, 25);
    circle(310, 720, 25);
    circle(320, 740, 25);
    circle(350, 750, 25);
    circle(380, 750, 25);
    circle(400, 730, 25);
    circle(380, 720, 25);
    circle(360, 710, 25);
}
void a_cloud_2()
{
    glColor3ub(255, 255, 255);
    quad(840, 760, 940, 760, 940, 720, 840, 720);
    circle(860, 745, 30);
    circle(895, 745, 30);
    circle(920, 745, 30);
}
void a_cloud_3()
{
    glColor3ub(255, 255, 255);
    circle(1060, 760, 25);
    circle(1090, 770, 25);
    circle(1120, 770, 25);
    circle(1140, 750, 25);
    circle(1110, 740, 25);
    circle(1080, 730, 25);
    circle(1050, 730, 25);
}
void a_clouds()
{
    glPushMatrix();
    glTranslatef(cloudX, 0, 0);

    a_cloud_1();
    a_cloud_2();
    a_cloud_3();

    glPopMatrix();
}
void a_mountain_1()
{
    glColor3ub(100, 115, 150);
    triangle(0, 600, 200, 700, 400, 600);
    glColor3ub(255, 255, 255);
    triangle(200, 700, 280, 660, 120, 660);
}
void a_mountain_2()
{
    glColor3ub(100, 115, 150);
    triangle(400, 600, 600, 750, 800, 600);
    glColor3ub(255, 255, 255);
    triangle(490, 670, 600, 750, 710, 670);
}
void a_mountain_3()
{
    glColor3ub(100, 115, 150);
    triangle(800, 600, 1000, 700, 1200, 600);
    glColor3ub(255, 255, 255);
    triangle(920, 660, 1000, 700, 1080, 660);
}
void a_mountains()
{
    a_mountain_1();
    a_mountain_2();
    a_mountain_3();
}
void a_river()
{
    glColor3ub(70, 130, 180);
    quad(0, 600, 1200, 600, 1200, 350, 0, 350);
}

void a_ground()
{
    glColor3ub(124, 252, 0);
    quad(0, 350, 1200, 350, 1200, 0, 0, 0);
}
void a_railLine()
{
    glColor3ub(141, 143, 143);
    quad(0, 280, 1200, 280, 1200, 240, 0, 240);
    glColor3ub(36, 38, 36);
    glLineWidth(4);
    // main
    line(0, 280, 1200, 280);
    line(0, 240, 1200, 240);
    // sections
    for (int i = 20; i <= 1200; i += 20)
    {
        line(i, 280, i, 240);
    }

}
void a_railBridge()
{
    glColor3ub(135, 161, 160);

    line(50, 240, 50, 150);
    quad(40, 155, 60, 155, 60, 140, 40, 140);

    line(150, 240, 150, 150);
    quad(140, 155, 160, 155, 160, 140, 140, 140);

    line(250, 240, 250, 150);
    quad(240, 155, 260, 155, 260, 140, 240, 140);

    line(350, 240, 350, 150);
    quad(340, 155, 360, 155, 360, 140, 340, 140);

    line(450, 240, 450, 150);
    quad(440, 155, 460, 155, 460, 140, 440, 140);

    line(550, 240, 550, 150);
    quad(540, 155, 560, 155, 560, 140, 540, 140);

    line(650, 240, 650, 150);
    quad(640, 155, 660, 155, 660, 140, 640, 140);

    line(750, 240, 750, 150);
    quad(740, 155, 760, 155, 760, 140, 740, 140);

    line(850, 240, 850, 150);
    quad(840, 155, 860, 155, 860, 140, 840, 140);

    line(950, 240, 950, 150);
    quad(940, 155, 960, 155, 960, 140, 940, 140);

    line(1050, 240, 1050, 150);
    quad(1040, 155, 1060, 155, 1060, 140, 1040, 140);

    line(1150, 240, 1150, 150);
    quad(1140, 155, 1160, 155, 1160, 140, 1140, 140);
}
void a_train()
{
    glPushMatrix();
    glTranslatef(trainX1, 0, 0);
    // bogie - 1
    // body
    glColor3ub(190, 30, 45);
    quad(720, 300, 840, 300, 840, 250, 720, 250);
    // wheel
    glColor3ub(120, 120, 120);
    circle(750, 250, 10);
    circle(810, 250, 10);
    // windows
    glColor3ub(167, 171, 167);
    quad(730, 285, 745, 285, 745, 275, 730, 275);
    quad(755, 285, 770, 285, 770, 275, 755, 275);
    quad(780, 285, 795, 285, 795, 275, 780, 275);
    quad(805, 285, 820, 285, 820, 275, 805, 275);
    // head
    quad(810, 320, 830, 320, 830, 300, 810, 300);
    // bogie - 2
    // body
    glColor3ub(190, 30, 45);
    quad(580, 300, 700, 300, 700, 250, 580, 250);
    // wheel
    glColor3ub(120, 120, 120);
    circle(610, 250, 10);
    circle(670, 250, 10);
    // windows
    glColor3ub(167, 171, 167);
    quad(595, 285, 610, 285, 610, 275, 595, 275);
    quad(620, 285, 635, 285, 635, 275, 620, 275);
    quad(645, 285, 660, 285, 660, 275, 645, 275);
    quad(670, 285, 685, 285, 685, 275, 670, 275);
    // bogie - 3
    // body
    glColor3ub(190, 30, 45);
    quad(440, 300, 560, 300, 560, 250, 440, 250);
    // wheel
    glColor3ub(120, 120, 120);
    circle(470, 250, 10);
    circle(530, 250, 10);
    // windows
    glColor3ub(167, 171, 167);
    quad(450, 285, 465, 285, 465, 275, 450, 275);
    quad(475, 285, 490, 285, 490, 275, 475, 275);
    quad(500, 285, 515, 285, 515, 275, 500, 275);
    quad(525, 285, 540, 285, 540, 275, 525, 275);

    // connection
    quad(560, 265, 580, 265, 580, 255, 560, 255);
    quad(700, 265, 720, 265, 720, 255, 700, 255);
    glPopMatrix();
}
void a_tree_1()
{
    // leaf
    glColor3ub(34, 139, 34);
    circle(40, 480, 60);
    circle(100, 400, 80);
    circle(180, 300, 80);
    circle(180, 180, 80);
    circle(50, 300, 150);
    // branch
    glColor3ub(210, 180, 140);
    quad(50, 300, 100, 300, 100, 50, 50, 50);
    circle(75, 290, 30);
    glLineWidth(10);
    line(50, 300, 20, 320);
    line(50, 300, 10, 250);
    line(60, 300, 20, 360);
    line(60, 300, 40, 380);
    line(80, 300, 80, 380);
    line(80, 300, 120, 380);
    line(100, 300, 180, 360);
    line(100, 300, 180, 320);
    line(100, 300, 150, 260);
}
void a_tree_2()
{
    // leaf
    glColor3ub(34, 139, 34);
    circle(1160, 480, 60);
    circle(1100, 400, 80);
    circle(1020, 300, 80);
    circle(1020, 180, 80);
    circle(1150, 300, 150);
    // branch
    glColor3ub(210, 180, 140);
    quad(1100, 300, 1150, 300, 1150, 50, 1100, 50);
    circle(1125, 290, 30);
    line(1100, 300, 1020, 220);
    line(1100, 300, 1000, 300);
    line(1100, 300, 1000, 360);
    line(1120, 300, 1060, 380);
    line(1120, 300, 1140, 380);
    line(1140, 300, 1100, 380);
    line(1140, 300, 1200, 400);
    line(1150, 300, 1220, 360);
    line(1150, 300, 1240, 300);
    line(1150, 300, 1220, 260);
}
void a_fence_1()
{
    glColor3ub(110, 84, 71);
    glLineWidth(5);
    // horizontal
    line(360, 80, 520, 80);
    line(360, 60, 520, 60);
    line(360, 40, 520, 40);
    // vertical
    line(380, 100, 380, 20);
    line(420, 100, 420, 20);
    line(460, 100, 460, 20);
    line(500, 100, 500, 20);
}
void a_fence_2()
{
    glColor3ub(110, 84, 71);
    glLineWidth(5);
    // horizontal
    line(680, 80, 840, 80);
    line(680, 60, 840, 60);
    line(680, 40, 840, 40);
    // vertical
    line(700, 100, 700, 20);
    line(740, 100, 740, 20);
    line(780, 100, 780, 20);
    line(820, 100, 820, 20);
}
void a_fences()
{
    a_fence_1();
    a_fence_2();
}

void cloudAnimation(int value)
{
    if (cloudMove)
    {
        cloudX += 5.0f;

        if (cloudX > 1250)
            cloudX = -1250;

        glutPostRedisplay();
    }

    glutTimerFunc(16, cloudAnimation, 0);
}

void trainAnimation(int value)
{
    if (trainMove)
    {
        trainX1 += 5.0;

        if (trainX1 > 1400)
        {
            trainX1 = -1400;
        }

        glutPostRedisplay();
    }

    glutTimerFunc(16, trainAnimation, 0);
}





GLvoid drawCircle1(GLfloat xc, GLfloat yc, GLfloat radius)
{
    glBegin(GL_POLYGON);
    for (float i = 0; i<= 2 * 3.1416f; i+= 0.01f)
    {
        glVertex2f((GLfloat)(xc + radius * cos(i)), (GLfloat)(yc + radius * sin(i)));
    }
    glEnd();
}

void drawWindowsAndDoor(int X,int z)
{
    //window
    glColor3f(0.6f, 0.75f, 0.55f);

    for (int i = 0; i < 3; i++)
    {
        float x = X + 45 + i * 50;
        glBegin(GL_QUADS);
        glVertex2f(x,     z+45);
        glVertex2f(x+40,  z+45);
        glVertex2f(x+40,  z+70);
        glVertex2f(x,     z+70);
        glEnd();
    }

    // Door
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(X , z);
    glVertex2f(X + 35, z);
    glVertex2f(X + 35, z+80);
    glVertex2f(X , z+80);
    glEnd();
}


void drawQuad(float x1, float y1, float x2, float y2)
{
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}




void drawWheel(float cx, float cy, float r, float rotation, bool isTrainWheel = false)
{
    // black tire
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);  // Center
        for (int i = 0; i <= 360; i++)
        {
            float a = i * 3.1416f / 180;
            glVertex2f(cx + cos(a) * r, cy + sin(a) * r);
        }
    glEnd();

    if (isTrainWheel)
    {
        // Train wheel - dark gray inner rim
        glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(cx, cy);
            for (int i = 0; i <= 360; i++)
            {
                float a = i * 3.1416f / 180;
                glVertex2f(cx + cos(a) * r * 0.8f, cy + sin(a) * r * 0.8f);
            }
        glEnd();

        // Train wheel - silver
        glColor3f(0.7f, 0.7f, 0.7f);
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(cx, cy);
            for (int i = 0; i <= 360; i++)
            {
                float a = i * 3.1416f / 180;
                glVertex2f(cx + cos(a) * r * 0.3f, cy + sin(a) * r * 0.3f);
            }
        glEnd();

        // Train wheel - 4 spokes
        glColor3f(0.5f, 0.5f, 0.5f);
        glLineWidth(3.0f);
        glBegin(GL_LINES);
            for (int i = 0; i < 4; i++)  // 4 spokes like car
            {
                float angle = (i * 90 + rotation) * 3.1416f / 180;
                glVertex2f(cx, cy);
                glVertex2f(cx + cos(angle) * r * 0.9f, cy + sin(angle) * r * 0.9f);
            }
        glEnd();
    }
    else
    {
        // Car wheel - silver
        glColor3f(0.8f, 0.8f, 0.8f);
        glBegin(GL_TRIANGLE_FAN);
            glVertex2f(cx, cy);
            for (int i = 0; i <= 360; i++)
            {
                float a = i * 3.1416f / 180;
                glVertex2f(cx + cos(a) * r * 0.4f, cy + sin(a) * r * 0.4f);
            }
        glEnd();

        // Car wheel spokes
        glColor3f(0.6f, 0.6f, 0.6f);
        glLineWidth(2.0f);
        glBegin(GL_LINES);
            for (int i = 0; i < 4; i++)  // 4 spokes
            {
                float angle = (i * 90 + rotation) * 3.1416f / 180;
                glVertex2f(cx, cy);
                glVertex2f(cx + cos(angle) * r * 0.9f, cy + sin(angle) * r * 0.9f);
            }
        glEnd();
    }
    glLineWidth(1.0f);
}

// ------------------ Sky ------------------
void sky()
{
    glColor3f(0.5529f, 0.8275f, 0.8588f);
    drawQuad(0, 400, 1200, 800);
}
// ------------------ Buildings (Skyline) ------------------
void buildings()
{
    glColor3f(0.20f, 0.45f, 0.50f);   // dark sky building color

    // Building 1
    drawQuad(0,   400, 120, 700);

    // Building 2
    drawQuad(120, 400, 260, 650);

    // Building 3
    drawQuad(260, 400, 380, 730);

    // Building 4
    drawQuad(380, 400, 520, 670);

    // Building 5
    drawQuad(520, 400, 680, 740);

    // Building 6
    drawQuad(680, 400, 830, 690);

    // Building 7
    drawQuad(830, 400, 980, 720);

    // Building 8
    drawQuad(980, 400, 1100, 660);

    // Building 9
    drawQuad(1100, 400, 1200, 750);
}


// ------------------ Grass ------------------
void grass()
{
    glColor3f(0.30f, 0.70f, 0.30f);
    drawQuad(0, 292.7, 1200, 400);
}

// ------------------ Road ------------------
void road()
{
    glColor3f(0.38f, 0.38f, 0.38f);
    drawQuad(0, 0, 1200, 164.8);
}
void road1()
{
    glColor3f(0.78f, 0.78f, 0.78f);
    drawQuad(0, 164.8, 1200, 214.31);
}
void road2()
{
    glColor3f(0.38f, 0.38f, 0.38f);
    drawQuad(0, 214.31, 1200, 276.19);
}
void road3()
{
    glColor3f(0.78f, 0.78f, 0.78f);
    drawQuad(0, 276.19, 1200, 292.7);
}

// ------------------ Train Track ------------------
void trainTrack()
{
    glColor3f(0.33f, 0.30f, 0.24);
    drawQuad(0, 400, 1200, 408);

    glColor3f(0.67f, 0.66f, 0.58f);
    for (int i = 0; i < 1200; i += 40)
        drawQuad(i, 393, i + 22, 402);
}

// ------------------ Train ------------------
void train()
{
    // ================= Main Train Body =================
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_POLYGON);
        glVertex2f(trainPos1 + 0.0f,    550.0f);    // N
        glVertex2f(trainPos1 + 517.68f, 548.52f);   // O
        glVertex2f(trainPos1 + 517.92f, 417.28f);   // P
        glVertex2f(trainPos1 + 0.0f,    417.9f);    // Q
    glEnd();

    // ================= Engine Front =================
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_POLYGON);
        glVertex2f(trainPos1 + 532.89f, 549.1f);    // R
        glVertex2f(trainPos1 + 1050.0f, 550.0f);    // S
        glVertex2f(trainPos1 + 1124.96f,488.28f);   // T
        glVertex2f(trainPos1 + 1125.29f,445.46f);   // U
        glVertex2f(trainPos1 + 1112.05f,417.28f);   // V
        glVertex2f(trainPos1 + 532.82f, 417.28f);   // W
    glEnd();

    // ================= Roof / Window Strip =================
    glColor3f(0.2f, 0.4f, 0.6f);
    glBegin(GL_POLYGON);
        glVertex2f(trainPos1 + 1034.69f, 524.82f);  // R6
        glVertex2f(trainPos1 + 1051.24f, 524.82f);  // V6
        glVertex2f(trainPos1 + 1084.89f, 502.69f);  // U6
        glVertex2f(trainPos1 + 1084.89f, 495.65f);  // T6
        glVertex2f(trainPos1 + 1034.57f, 495.65f);  // S6
    glEnd();

    // ================= Black outside the window =================
    // ================= Window Background (Coach) =================
    glColor3f(0.1f, 0.1f, 0.1f);   // black / dark gray
    glBegin(GL_POLYGON);
        glVertex2f(trainPos1 + 0.0f,    524.81f);   // F
        glVertex2f(trainPos1 + 519.39f, 524.81f);   // I
        glVertex2f(trainPos1 + 519.39f, 482.79f);   // J
        glVertex2f(trainPos1 + 0.0f,    482.79f);   // M
    glEnd();

    // ================= Window Background (Engine) =================
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
        glVertex2f(trainPos1 + 533.69f, 525.1f);    // J1
        glVertex2f(trainPos1 + 966.12f, 524.7f);    // K1
        glVertex2f(trainPos1 + 1000.0f, 500.0f);    // L1
        glVertex2f(trainPos1 + 1000.0f, 483.14f);   // M1
        glVertex2f(trainPos1 + 533.69f, 482.74f);   // F2
    glEnd();

    // ================= Red Strip (Main Body) =================
    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
        glVertex2f(trainPos1 + 0.0f,    458.98f);   // Z6
        glVertex2f(trainPos1 + 518.98f, 458.98f);   // G2
        glVertex2f(trainPos1 + 518.98f, 447.48f);   // H2
        glVertex2f(trainPos1 + 0.0f,    447.48f);   // E3
    glEnd();

    // ================= Red Strip (Engine Front) =================
    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
        glVertex2f(trainPos1 + 533.63f, 458.77f);   // F3
        glVertex2f(trainPos1 + 1065.53f,458.77f);   // G3
        glVertex2f(trainPos1 + 1057.38f,446.31f);   // H3
        glVertex2f(trainPos1 + 533.63f, 446.31f);   // D7
    glEnd();

    // ================= Coach Windows =================
    glColor3f(0.2f, 0.4f, 0.6f);
    float windowStartX = 10.5f;   // B4.x
    float windowWidth  = 43.3f;
    float windowGap    = 20.0f;  // spacing between windows

    for (int i = 0; i < 8; i++)   // number of windows
    {
        float x = trainPos1 + windowStartX + i * (windowWidth + windowGap);
        glBegin(GL_POLYGON);
            glVertex2f(x,              518.4f);  // top-left
            glVertex2f(x,              489.9f);  // bottom-left
            glVertex2f(x + windowWidth,489.9f);  // bottom-right
            glVertex2f(x + windowWidth,518.4f);  // top-right
        glEnd();
    }

    // ================= Engine Front Windows =================
    glColor3f(0.2f, 0.4f, 0.6f);   // same window color
    float engineWinStartX = 545.2f;   // N5.x
    float engineWinWidth  = 44.1f;
    float engineWinGap    = 22.0f;    // spacing between engine windows

    for (int i = 0; i < 6; i++)       // number of engine windows
    {
        float x = trainPos1 + engineWinStartX + i * (engineWinWidth + engineWinGap);
        glBegin(GL_POLYGON);
            glVertex2f(x,                  518.4f); // top-left
            glVertex2f(x,                  489.9f); // bottom-left
            glVertex2f(x + engineWinWidth, 489.9f); // bottom-right
            glVertex2f(x + engineWinWidth, 518.4f); // top-right
        glEnd();
    }

    // ================= TRAIN WHEELS =================
    // Coach wheels (all with 4 spokes now)
    drawWheel(trainPos1 + 53.76f, 424.7f, 18.0f, trainWheelAngle, true);     // Z
    drawWheel(trainPos1 + 405.88f, 424.19f, 18.0f, trainWheelAngle, true);   // B1
    drawWheel(trainPos1 + 465.38f, 424.19f, 18.0f, trainWheelAngle, true);   // C1
    drawWheel(trainPos1 + 588.27f, 424.19f, 18.0f, trainWheelAngle, true);   // D1
    drawWheel(trainPos1 + 646.31f, 424.75f, 18.0f, trainWheelAngle, true);   // E1

    // Engine wheels (slightly larger, also with 4 spokes)
    drawWheel(trainPos1 + 986.4f, 423.78f, 20.0f, trainWheelAngle, true);    // F1
    drawWheel(trainPos1 + 1045.25f, 424.7f, 20.0f, trainWheelAngle, true);   // G1
}

// ------------------ Cars ------------------
// ------------------ Blue Car (left to right) ------------------
void car1()
{
    // ================= Outer Body =================
    glColor3f(0.0f, 0.2f, 0.8f);   // blue car
    glBegin(GL_POLYGON);
        glVertex2f(carPos1 + 294.99f, 180.74f); // H1
        glVertex2f(carPos1 + 292.46f, 104.78f); // I1
        glVertex2f(carPos1 + 724.30f, 98.39f);  // N1
        glVertex2f(carPos1 + 724.30f, 137.57f); // O1
        glVertex2f(carPos1 + 713.70f, 152.85f); // P1
        glVertex2f(carPos1 + 609.44f, 178.74f); // Q1
        glVertex2f(carPos1 + 526.92f, 219.92f); // R1
        glVertex2f(carPos1 + 404.82f, 219.92f); // S1
    glEnd();

    // ================= Window =================
    glColor3f(0.2f, 0.4f, 0.6f);   // glass blue
    glBegin(GL_POLYGON);
        glVertex2f(carPos1 + 394.23f, 190.03f); // V1
        glVertex2f(carPos1 + 435.56f, 213.94f); // A2
        glVertex2f(carPos1 + 519.68f, 212.61f); // B2
        glVertex2f(carPos1 + 594.95f, 170.78f); // C2
        glVertex2f(carPos1 + 393.67f, 173.43f); // W1
    glEnd();

    // ================= Wheels for Car1 =================
    // Front wheel (right wheel - moving left to right)
    drawWheel(carPos1 + 650.0f, 100.0f, 22.0f, wheelAngle, false);  // U1 as center

    // Rear wheel (left wheel - moving left to right)
    drawWheel(carPos1 + 383.64f, 101.71f, 22.0f, wheelAngle, false); // T1 as center
}

// ------------------ Yellow Car (right to left) ------------------
void car2()
{
    // ================= Outer Body =================
    glColor3f(1.0f, 1.0f, 0.0f);   // yellow car
    glBegin(GL_POLYGON);
        // Start from front and go clockwise
        glVertex2f(carPos2 + 657.39f, 239.18f); // e2 - front bottom left
        glVertex2f(carPos2 + 657.39f, 258.44f); // d2 - front top left
        glVertex2f(carPos2 + 667.54f, 269.4f);  // p2
        glVertex2f(carPos2 + 720.95f, 280.35f); // 02
        glVertex2f(carPos2 + 759.42f, 302.26f); // N2
        glVertex2f(carPos2 + 830.79f, 304.26f); // m2
        glVertex2f(carPos2 + 866.47f, 288.98f); // l2
        glVertex2f(carPos2 + 891.00f, 283.01f); // k2
        glVertex2f(carPos2 + 892.67f, 283.01f); // j2
        glVertex2f(carPos2 + 892.67f, 239.18f); // rear bottom right
    glEnd();

    // ================= Window =================
    glColor3f(0.2f, 0.4f, 0.6f);   // glass blue
    glBegin(GL_POLYGON);
        glVertex2f(carPos2 + 773.05f, 299.46f); // V1
        glVertex2f(carPos2 + 816.36f, 298.9f);  // A2
        glVertex2f(carPos2 + 837.45f, 285.96f); // B2
        glVertex2f(carPos2 + 837.17f, 279.21f); // C2
        glVertex2f(carPos2 + 735.7f, 278.42f);  // W1
    glEnd();

    // ================= Wheels for Car2 =================
    // Front wheel (left side of car - moving right to left)
    drawWheel(carPos2 + 699.58f, 239.22f, 18.0f, -wheelAngle, false);  // Q2 as center

    // Rear wheel (right side of car - moving right to left)
    drawWheel(carPos2 + 844.05f, 239.56f, 18.0f, -wheelAngle, false);  // R2 as center
}




void update1(int)
{

    cloud1X -= CLOUD1_SPEED;
    cloud2X -= CLOUD2_SPEED;
    cloud3X -= CLOUD3_SPEED;

    if (cloud1X < -150) cloud1X = 1300;
    if (cloud2X < -150) cloud2X = 1300;
    if (cloud3X < -150) cloud3X = 1300;

    // 1. TRAIN ARRIVING
    if (trainMoving)
    {
        trainX -= 4.0f;
        if (trainX <= 0.0f)
        {
            trainX = 0.0f;
            trainMoving = false;
            trainStopping = true; // State: Arrived/Stopped
            doorOpening = true;   // Immediately start opening doors
        }
    }

    // 2. DOOR OPENING
    if (doorOpening)
    {
        doorOffset += DOOR_SPEED;
        if (doorOffset >= DOOR_MAX)
        {
            doorOffset = DOOR_MAX;
            doorOpening = false;
            stopCounter = 0; // Start the "Wait" timer only once door is fully open
        }
    }

    // 3. WAITING AT STATION (Doors Open)
    if (trainStopping && !doorOpening && !doorClosing && doorOffset >= DOOR_MAX)
    {
        stopCounter++;
        if (stopCounter > DOOR_OPEN_TIME)
        {
            doorClosing = true;
        }
    }

    // 4. DOOR CLOSING
    if (doorClosing)
    {
        doorOffset -= DOOR_SPEED;
        if (doorOffset <= 0.0f)
        {
            doorOffset = 0.0f;
            doorClosing = false;
            // Now that doors are shut, wait a tiny beat before moving
            stopCounter = 0; 
        }
    }

    // 5. TRAIN LEAVING (Only after doors are shut)
    if (trainStopping && !doorOpening && !doorClosing && doorOffset <= 0.0f)
    {
        stopCounter++;
        if (stopCounter > 60) { // Small delay (approx 1 sec) for realism
            trainStopping = false;
            trainLeaving = true;
        }
    }

    if (trainLeaving)
    {
        trainX -= 4.0f;
        if (trainX < -1400)
        {
            trainLeaving = false;
            trainX = 1400.0f; // Reset for next 'T' press
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update1, 0);
}

void update3(int value)
{
    trainPos += trainSpeed;
    if(trainPos>=1200)
    {
       trainPos = -1200;
    }
    boatPos += boatSpeed;
    if(boatPos>=1200)
    {
        boatPos = -600;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update3, 0);
}


void renderBitmapString(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y);
    while (*string) {
        glutBitmapCharacter(font, *string++);
    }
}

void renderBitmapString(float x, float y, float z, void* font, const char* string)
{
    glRasterPos3f(x, y, z);
    while (*string) {
        glutBitmapCharacter(font, *string++);
    }
}

void update4(int)
{
    trainPos1 += 2;           // Train moves right
    carPos1  += 3;           // Blue car moves right (left to right)
    carPos2  -= 2;           // Yellow car moves left (right to left)
    wheelAngle += 8;         // Rotate car wheels
    trainWheelAngle += 6;    // Rotate train wheels (slower for larger wheels)

    // Reset positions when off-screen
    if (trainPos1 > 1200) trainPos1 = -800;
    if (carPos1 > 1200)  carPos1 = -800;  // Reset to left when off right
    if (carPos2 < -800)  carPos2 = 1200;  // Reset to right when off left

    // wheel angles 0-360 range
    if (wheelAngle > 360) wheelAngle -= 360;
    if (trainWheelAngle > 360) trainWheelAngle -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, update4, 0);
}

void update5(int)
{
    trainX5 += 5;
    if (trainX5 > 1200) trainX5 = -400;

    lightOn = !lightOn;

    smokeOffset += 2;
    if (smokeOffset > 50) smokeOffset = 0;

    if (trainX5 > 200 && trainX5 < 900)
    {
        if (gateAngle < 0)
            gateAngle += 2;   // -90 → 0
    }
    else
    {
        if (gateAngle > -90)
            gateAngle -= 2;   // 0 → -90
    }

    glutPostRedisplay();
    glutTimerFunc(100, update5, 0);
}


void drawCircle5(int cx, int cy, int r)
{
    glBegin(GL_POLYGON);
    for (int i = 0;i < 360;i++)
    {
        float a = i * 3.1416 / 180;
        glVertex2f(cx + r * cos(a), cy + r * sin(a));
    }
    glEnd();
}

void clouds()
{
    // Cloud 1
    glColor3f(1.0, 1.0, 1.0);
    drawCircle5(200, 700, 40);
    drawCircle5(240, 720, 35);
    drawCircle5(280, 710, 40);
    drawCircle5(240, 690, 35);
    drawCircle5(270, 690, 30);

    // Cloud 2
    drawCircle5(600, 650, 45);
    drawCircle5(640, 670, 40);
    drawCircle5(680, 660, 45);
    drawCircle5(640, 640, 40);
    drawCircle5(670, 640, 35);

    // Cloud 3
    drawCircle5(1000, 720, 50);
    drawCircle5(1040, 740, 45);
    drawCircle5(1080, 730, 50);
    drawCircle5(1040, 710, 45);
    drawCircle5(1070, 710, 40);

    // Cloud 4
    drawCircle5(400, 750, 35);
    drawCircle5(440, 770, 30);
    drawCircle5(480, 760, 35);
    drawCircle5(440, 740, 30);

    // Cloud 5
    drawCircle5(850, 680, 40);
    drawCircle5(890, 700, 35);
    drawCircle5(930, 690, 40);
    drawCircle5(890, 670, 35);
}

void sky1()
{
    glColor3f(0.75f, 0.9f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0, 800);
    glVertex2f(1200, 800);
    glVertex2f(1200, 477);
    glVertex2f(0, 477);
    glEnd();

    clouds();
}

void ground()
{
    glColor3f(0.3f, 0.6f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(1200, 0);
    glVertex2f(1200, 474.03f);
    glVertex2f(0, 477);
    glEnd();

    glColor3f(0, 0, 0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(1087, 76);
    glVertex2f(1087, 341);
    glEnd();
}


void road5()
{
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(36.23, 0);
    glVertex2f(1117.73, 0);
    glVertex2f(570, 475);
    glVertex2f(560, 475);
    glEnd();

    glColor3f(1, 1, 0);
    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2f(548, 0);
    glVertex2f(565.71, 474.99);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(582, 0);
    glVertex2f(565.71, 474.99);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    glVertex2f(92.44, 0);
    glVertex2f(429.74, 342.6);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(1071, 0);
    glVertex2f(713, 343);
    glEnd();

    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(622, 196);
    glVertex2f(726, 282);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2f(609, 281);
    glVertex2f(808, 199);
    glEnd();
}

void railway()
{
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2i(0, 376);
    glVertex2i(1200, 376);
    glVertex2i(1200, 424);
    glVertex2i(0, 424);
    glEnd();

    // Railway tracks
    glColor3f(0.2, 0.2, 0.2);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(0, 380);
    glVertex2i(1200, 380);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(0, 420);
    glVertex2i(1200, 420);
    glEnd();

    // Railway sleepers
    glColor3f(0.4, 0.3, 0.2);
    glLineWidth(8);
    for (int i = 0; i < 30; i++) {
        glBegin(GL_LINES);
        glVertex2i(i * 40, 395);
        glVertex2i(i * 40 + 30, 395);
        glEnd();
    }
}

void train5()
{

    float trainY = 430;

    for (int part = 0; part < 4; part++) {
        float partX = trainX5 + part * 100;


        glColor3f(0.8f, 0.1f, 0.1f);
        glBegin(GL_POLYGON);
        glVertex2f(partX, trainY);
        glVertex2f(partX + 80, trainY);
        glVertex2f(partX + 80, trainY + 70);
        glVertex2f(partX, trainY + 70);
        glEnd();


        glColor3f(0.85f, 0.95f, 1.0f);
        glBegin(GL_POLYGON);
        glVertex2f(partX + 15, trainY + 30);
        glVertex2f(partX + 40, trainY + 30);
        glVertex2f(partX + 40, trainY + 50);
        glVertex2f(partX + 15, trainY + 50);
        glEnd();


        glColor3f(0.2f, 0.2f, 0.2f);
        for (int wheel = 0; wheel < 4; wheel++) {
            drawCircle5(partX + 15 + wheel * 20, trainY - 10, 10);
        }

        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(2);
        glBegin(GL_LINE_LOOP);
        glVertex2f(partX, trainY);
        glVertex2f(partX + 80, trainY);
        glVertex2f(partX + 80, trainY + 70);
        glVertex2f(partX, trainY + 70);
        glEnd();


        glBegin(GL_LINE_LOOP);
        glVertex2f(partX + 15, trainY + 30);
        glVertex2f(partX + 40, trainY + 30);
        glVertex2f(partX + 40, trainY + 50);
        glVertex2f(partX + 15, trainY + 50);
        glEnd();
    }


    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(trainX5, trainY);
    glVertex2f(trainX5 + 20, trainY);
    glVertex2f(trainX5 + 20, trainY + 70);
    glVertex2f(trainX5, trainY + 70);
    glEnd();


    glColor3f(0.8f, 0.1f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex2f(trainX5 + 400, trainY);
    glVertex2f(trainX5 + 420, trainY + 35);
    glVertex2f(trainX5 + 400, trainY + 70);
    glEnd();


    glColor3f(0.3f, 0.3f, 0.3f);
    glLineWidth(3);
    for (int part = 0; part < 3; part++) {
        float connectX = trainX5 + (part + 1) * 100;
        glBegin(GL_LINES);
        glVertex2f(connectX, trainY + 10);
        glVertex2f(connectX, trainY + 60);
        glEnd();
    }


    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2f(trainX5 + 40, trainY + 70);
    glVertex2f(trainX5 + 50, trainY + 70);
    glVertex2f(trainX5 + 50, trainY + 90);
    glVertex2f(trainX5 + 40, trainY + 90);
    glEnd();


    glColor3f(0.7f, 0.7f, 0.7f);
    float smokeY = trainY + 95 + smokeOffset;
    drawCircle5(trainX5 + 45, smokeY, 8);
    drawCircle5(trainX5 + 45 + 5, smokeY + 15, 10);
    drawCircle5(trainX5 + 45 - 5, smokeY + 30, 12);
    glEnd();
}

void signal()
{
    glColor3f(0, 0, 0);
    glLineWidth(20);
    glBegin(GL_LINES);
    glVertex2i(803, 638);
    glVertex2i(803, 356);
    glEnd();

    glColor3f(1, 0, 0);
    glLineWidth(15);
    glBegin(GL_LINES);
    glVertex2i(760, 567);
    glVertex2i(845, 653);
    glEnd();

    glColor3f(1, 0, 0);
    glLineWidth(15);
    glBegin(GL_LINES);
    glVertex2i(760, 653);
    glVertex2i(845, 569);
    glEnd();

    glColor3f(0, 0, 0);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2i(767, 557);
    glVertex2i(840, 557);
    glEnd();
}

void gate()
{
    glPushMatrix();
    glTranslatef(787, 441, 0);
    glRotatef(gateAngle, 0, 0, 1);

    glColor3f(1, 0, 0);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(-400, 0);
    glVertex2f(0, 0);
    glEnd();

    glPopMatrix();
}

void pole()
{
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(1087, 341);
    glVertex2f(1150, 400);
    glVertex2f(1087, 474);
    glVertex2f(1020, 400);
    glEnd();

    glColor3f(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(1087, 436);
    glVertex2f(1087, 367);
    glEnd();

    glColor3f(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(1045, 410);
    glVertex2f(1129, 410);
    glEnd();

    glColor3f(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(1046, 397);
    glVertex2f(1129, 397);
    glEnd();

    glColor3f(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(1053, 414);
    glVertex2f(1053, 391);
    glEnd();

    glColor3f(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(1067, 414);
    glVertex2f(1067, 391);
    glEnd();

    glColor3f(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(1108, 393);
    glVertex2f(1108, 413);
    glEnd();

    glColor3f(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(1121, 390);
    glVertex2f(1121, 412);
    glEnd();
}

void generator()
{
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(27.82, 348.79);
    glVertex2f(171, 347);
    glVertex2f(170, 490);
    glVertex2f(30, 492);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(100, 532);
    glVertex2f(30, 492);
    glVertex2f(170, 490);
    glEnd();

    glColor3f(0.33, 0.33, 0.34);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(50, 470);
    glVertex2f(88, 470);
    glEnd();

    glColor3f(0.33, 0.33, 0.34);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(50, 470);
    glVertex2f(50, 350);
    glEnd();

    glColor3f(0.33, 0.33, 0.34);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(88, 350);
    glVertex2f(88, 410);
    glEnd();

    glColor3f(0.33, 0.33, 0.34);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(100, 350);
    glVertex2f(100, 470);
    glEnd();

    glColor3f(0.33, 0.33, 0.34);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(100, 471);
    glVertex2f(148, 471);
    glEnd();

    glColor3f(0.33, 0.33, 0.34);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(148, 471);
    glVertex2f(148, 350);
    glEnd();

    glColor3f(0.33, 0.33, 0.34);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(30, 490);
    glVertex2f(170, 490);
    glEnd();
}

void mountain()
{
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(906, 475);
    glVertex2f(1000, 520);
    glVertex2f(1000, 476);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(1000, 476);
    glVertex2f(1117, 544);
    glVertex2f(1117, 475);
    glVertex2f(1000, 520);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(1117, 475);
    glVertex2f(1136, 529);
    glVertex2f(1136, 475);
    glVertex2f(1117, 544);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(1136, 475);
    glVertex2f(1180, 551);
    glVertex2f(1180, 475);
    glVertex2f(1136, 529);
    glEnd();

    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(1180, 475);
    glVertex2f(1200, 540);
    glVertex2f(1200, 475);
    glVertex2f(1180, 551);
    glEnd();
}




void display1() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(275 - 50, 400 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "         NAME");
    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(180 - 50, 360 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "MD. MINHAZ UL MOSTOFA PRANTO");
    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(130 - 50, 330 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "                           ABDUL RAHMAN");
    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(200 - 50, 300 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "                 ATKIYA ANISA");
    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(130 - 50, 270 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "                  MD. RAFIDUL ISLAM ");
    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(170 - 50, 240 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "                   MARIN RAHMAN  ");




    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(700 - 70, 400 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "ID");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(650 - 70, 360 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "23-50176-1 ");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(650 - 70, 330 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "22-49444-3");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(650 - 70, 300 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "23-52506-2");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(650 - 70, 270 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "23-50343-1 ");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(650 - 70, 240 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "23-52296-2 ");


    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(900 - 120, 400 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "SERIAL");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(930 - 120, 360 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "09");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(930 - 120, 330 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "05");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(930 - 120, 300 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "32");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(930 - 120, 270 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "10");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(930 - 120, 240 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "27");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(900 + 100, 400 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "CONTRIBUTION");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(930 + 120, 360 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "20%");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(930 + 120, 330 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "20%");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(930 + 120, 300 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "20%");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(930 + 120, 270 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "20%");

    glColor3ub(237, 52, 17); // Red text
    renderBitmapString(930 + 120, 240 - 230, GLUT_BITMAP_TIMES_ROMAN_24, "20%");


    glColor3ub(0, 0, 0);
    renderBitmapString(260, 540, GLUT_BITMAP_TIMES_ROMAN_24, "AMERICAN INTERNATIONAL UNIVERSITY-BANGLADESH");

    glColor3ub(0, 0, 0);
    renderBitmapString(460, 500, GLUT_BITMAP_TIMES_ROMAN_24, "COMPUTER GRAPHICS");

    glColor3ub(95, 109, 222);
    renderBitmapString(480, 460, GLUT_BITMAP_TIMES_ROMAN_24, "FALL: 2025-2026");

    glColor3ub(95, 109, 222);
    renderBitmapString(530, 420, GLUT_BITMAP_TIMES_ROMAN_24, "SECTION: A");

    glColor3ub(20, 97, 35);
    renderBitmapString(500, 380, GLUT_BITMAP_TIMES_ROMAN_24, "FINAL PROJECT");

    glColor3ub(87, 38, 21);
    renderBitmapString(500, 340, GLUT_BITMAP_TIMES_ROMAN_24, "SUPERVISED BY");

    glColor3ub(0, 0, 0);
    renderBitmapString(465, 300, GLUT_BITMAP_TIMES_ROMAN_24, "MAHFUJUR RAHMAN");

    glColor3ub(0, 0, 0);
    renderBitmapString(340, 260, GLUT_BITMAP_TIMES_ROMAN_24, "ASSISTANT PROFESSOR, COMPUTER SCIENCE");

    glColor3ub(0, 10, 99);
    renderBitmapString(500, 220, GLUT_BITMAP_TIMES_ROMAN_24, "SUBMITTED BY");

    glFlush();
}

void display2() {
    glClearColor(0.78f, 0.78f, 0.78f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    renderBitmapString(450, 750, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Visualizing Modern Rail Systems->Instruction Page");
    renderBitmapString(410, 720, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "=============================================");
    glColor3f(0.0, 0.0, 0.0);
    renderBitmapString(100, 680, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "1. Cover Page -press 1");
    renderBitmapString(100, 640, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Designed By MD.MINHAZ UL MOSTOFA PRANTO; ID : 23-50176-1 ; Serial: 09");
    renderBitmapString(100, 600, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "2. Instruction Page -press 2");
    renderBitmapString(100, 560, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Designed By MD.MINHAZ UL MOSTOFA PRANTO; ID : 23-50176-1 ; Serial: 09");
    renderBitmapString(100, 520, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "3. Scenario 1 (Train station) -press 3 ('b/B' for train )('d/D' for day) ('n/N' for night)");
    renderBitmapString(100, 480, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Designed By MD.MINHAZ UL MOSTOFA PRANTO; ID : 23-50176-1 ; Serial: 09");
    renderBitmapString(100, 440, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "4. Scenario 2 (Train on a bridge) -press 4 ('t/T' for train movement and stop)('c/C' for cloud movement and stop)");
    renderBitmapString(100, 400, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Designed By ABDUL RAHMAN ; ID : 22-49444-3 ; Serial: 05");
    renderBitmapString(100, 360, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "5. Scenario 3 (Train beside a canel) -press 5 ('upper arrow' speed up, 'down arrow' for speed down)");
    renderBitmapString(100, 320, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Designed By ATKIYA ANISA ; ID : 23-52506-2  ; Serial: 32");
    renderBitmapString(100, 280, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "6. Scenario 4 (Train Passing By Road) -press 6");
    renderBitmapString(100, 240, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Designed By MD. RAFIDUL ISLAM ; ID : 23-50343-1; Serial: 10");
    renderBitmapString(100, 200, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "7. Scenario 5 (Train Passing by Road Crossing) -press 7");
    renderBitmapString(100, 160, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Designed By MARIN RAHMAN ; ID : 23-52296-2 ; Serial: 27");

    glFlush();
}


void display3() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)



    glBegin(GL_POLYGON);
    if (isDay)
        glColor3ub(10, 144, 247);     // Day sky
    else
        glColor3ub(10, 20, 60);       // Night sky (dark blue)

    glVertex2i(0, 800);
    glVertex2i(1200, 800);
    glVertex2i(1200, 665);
    glVertex2i(0, 665);
    glEnd();

    if (isDay) drawSun();
    else drawMoon();

    drawCloud(cloud1X , 720);
    drawCloud(cloud2X , 700);
    drawCloud(cloud3X , 730);



    glBegin(GL_POLYGON);
    glColor3ub(174, 180, 181);
    glVertex2i(0, 665); //E
    glVertex2i(1200, 665); //F
    glVertex2i(1200, 0); //B
    glVertex2i(0, 0); //A
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(227, 228, 230);
    glVertex2i(0, 197); //G
    glVertex2i(1200, 197); //H
    glVertex2i(1200, 0); //B
    glVertex2i(0, 0); //A
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(255, 184, 61);
    glVertex2i(0, 187); //I
    glVertex2i(1200, 187); //M
    glVertex2i(1200, 165); //N
    glVertex2i(0, 165); //J
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(212, 123, 0);
    glVertex2i(0, 124); //K
    glVertex2i(1200, 124); //O
    glVertex2i(1200, 113); //P
    glVertex2i(0, 113); //L
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(117, 116, 116);
    glVertex2i(0, 638); //Q
    glVertex2i(1200, 638); //S
    glVertex2i(1200, 630); //T
    glVertex2i(0, 630); //R
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(207, 207, 207);
    glVertex2i(0, 597); //U
    glVertex2i(1200, 597); //F1
    glVertex2i(1200, 588); //G1
    glVertex2i(0, 588); //V
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(207, 207, 207);
    glVertex2i(0, 572); //W
    glVertex2i(1200, 572); //F1
    glVertex2i(1200, 540); //G1
    glVertex2i(0, 540); //P1
    glEnd();

    //light
    glBegin(GL_POLYGON);
    glColor3ub(92, 88, 88);
    glVertex2i(0, 563); //Z
    glVertex2i(49, 563); //A1
    glVertex2i(50, 560); //B1
    glVertex2i(0, 560); //C1
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(250, 247, 247);
    glVertex2i(0, 560); //C1
    glVertex2i(50, 560); //B1
    glVertex2i(50, 550); //D1
    glVertex2i(0, 550); //E1
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(92, 88, 88);
    glVertex2i(1150, 563); //L1
    glVertex2i(1200, 563); //I1
    glVertex2i(1200, 560); //J1
    glVertex2i(1150, 560); //M1
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(250, 247, 247);
    glVertex2i(1150, 560); //M1
    glVertex2i(1200, 560); //J1
    glVertex2i(1200, 550); //K1
    glVertex2i(1157, 550); //E1
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(92, 88, 88);
    glVertex2i(112, 563); //Q1
    glVertex2i(257, 563); //T1
    glVertex2i(257, 560); //U1
    glVertex2i(112, 560); //R1
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(250, 247, 247);
    glVertex2i(112, 560); //R1
    glVertex2i(257, 560); //U1
    glVertex2i(252,548); //V1
    glVertex2i(120,548); //S1
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(92, 88, 88);
    glVertex2i(320, 563); //W1
    glVertex2i(463, 563); //A2
    glVertex2i(463, 560); //B2
    glVertex2i(320, 560); //Z1
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(250, 247, 247);
    glVertex2i(320, 560); //Z1
    glVertex2i(463, 560); //B2
    glVertex2i(458,548); //C2
    glVertex2i(326,548); //D2
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(92, 88, 88);
    glVertex2i(528, 563); //E2
    glVertex2i(672, 563); //H2
    glVertex2i(672, 560); //I2
    glVertex2i(528, 560); //F2
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(250, 247, 247);
    glVertex2i(528, 560); //F2
    glVertex2i(672, 560); //I2
    glVertex2i(666,548); //J2
    glVertex2i(533,548); //G2
    glEnd();




    glBegin(GL_POLYGON);
    glColor3ub(92, 88, 88);
    glVertex2i(735, 563); //K2
    glVertex2i(880, 563); //N2
    glVertex2i(880, 560); //O2
    glVertex2i(735, 560); //L2
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(250, 247, 247);
    glVertex2i(735, 560); //L2
    glVertex2i(880, 560); //O2
    glVertex2i(873,548); //P2
    glVertex2i(741,548); //M2
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(92, 88, 88);
    glVertex2i(942, 563); //Q2
    glVertex2i(1086, 563); //T2
    glVertex2i(1086, 560); //U2
    glVertex2i(942, 560); //R2
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(250, 247, 247);
    glVertex2i(942, 560); //R2
    glVertex2i(1086, 560); //U2
    glVertex2i(1082,548); //V2
    glVertex2i(949,548); //S2
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(212, 212, 212);
    glVertex2i(271,450); //t3
    glVertex2i(528,450);//v3
    glVertex2i(528,199);//w3
    glVertex2i(271,199);//u3
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(124, 124, 124);
    glVertex2i(334,401); //z3
    glVertex2i(463,401);//a4
    glVertex2i(463,254);//d4
    glVertex2i(334,254);//b4
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(212, 212, 212);
    glVertex2i(656,450); //e4
    glVertex2i(888,450);//h4
    glVertex2i(888,199);//i4
    glVertex2i(656,199);//g4
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(124, 124, 124);
    glVertex2i(716,401); //j4
    glVertex2i(825,401);//k4
    glVertex2i(825,254);//m4
    glVertex2i(716,254);//l4
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(124, 124, 124);
    glVertex2i(0,520); //h4
    glVertex2i(1200,520);//u4
    glVertex2i(1200,497);//v4
    glVertex2i(0,497);//m4
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(124, 124, 124);
    glVertex2i(0,480); //o4
    glVertex2i(1200,480);//w4
    glVertex2i(1200,462);//z4
    glVertex2i(0,462);//q4
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(170, 170, 170);
    glVertex2i(0,540); //p1
    glVertex2i(1200,540);//o1
    glVertex2i(1200,520);//u4
    glVertex2i(0,520);//h4
    glEnd();



    glPushMatrix();
    glTranslatef(trainX, 0, 0);   
    drawTrain();
    glPopMatrix();






    //khamba
    glBegin(GL_POLYGON);
    glColor3ub(170, 170, 170);
    glVertex2i(80,520); //L4
    glVertex2i(110,520);//U4
    glVertex2i(110,144);//e5
    glVertex2i(80,144);//d5
    glEnd();




     glBegin(GL_POLYGON);
    glColor3ub(170, 170, 170);
    glVertex2i(585,520); 
    glVertex2i(615,520);
    glVertex2i(615,144);
    glVertex2i(585,144);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3ub(170, 170, 170);
    glVertex2i(1095,520); 
    glVertex2i(1126,520);
    glVertex2i(1126,144);
    glVertex2i(1095,144);
    glEnd();

    // khamba design
    glBegin(GL_POLYGON);
    glColor3ub(252, 143, 0);
    glVertex2i(80,218); 
    glVertex2i(110,218);
    glVertex2i(110,212);
    glVertex2i(80,212);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 143, 0);
    glVertex2i(80,205); 
    glVertex2i(110,205);
    glVertex2i(110,203);
    glVertex2i(80,203);
    glEnd();

    // khmba design
     glBegin(GL_POLYGON);
    glColor3ub(252, 143, 0);
    glVertex2i(585,218); 
    glVertex2i(615,218);
    glVertex2i(615,212);
    glVertex2i(585,212);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(252, 143, 0);
    glVertex2i(585,205); 
    glVertex2i(615,205);
    glVertex2i(615,203);
    glVertex2i(585,203);
    glEnd();


    //khamba design
    glBegin(GL_POLYGON);
    glColor3ub(252, 143, 0);
    glVertex2i(1095,218); 
    glVertex2i(1126,218);
    glVertex2i(1126,212);
    glVertex2i(1095,212);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(252, 143, 0);
    glVertex2i(1095,205); 
    glVertex2i(1126,205);
    glVertex2i(1126,203);
    glVertex2i(1095,203);
    glEnd();


    // --- manush
    glBegin(GL_POLYGON); 
        glColor3ub(200, 150, 110);
    for (int i = 0; i < 360; i++)
    {
        float rad = i * 3.14159 / 180;
        glVertex2f(315 + 10 * cos(rad), 200 + 10 * sin(rad)); 
    }
    glEnd();

    glBegin(GL_QUADS); 
        glColor3ub(0, 0, 255); 
        glVertex2i(305, 190); 
        glVertex2i(325, 190);
        glVertex2i(325, 140); 
        glVertex2i(305, 140);
    glEnd();

    glBegin(GL_LINES); 
        glColor3ub(0, 0, 0);
        glVertex2i(310, 140); glVertex2i(310, 99); 
        glVertex2i(320, 140); glVertex2i(320, 99); 
        glEnd();

    // 2nd manush
    glBegin(GL_POLYGON); 
    glColor3ub(200, 150, 110); 
    for(int i=0; i<360; i++) {
        float rad = i * 3.14159 / 180;
        glVertex2f(818 + 10 * cos(rad), 200 + 10 * sin(rad));
    }
    glEnd();

    glBegin(GL_QUADS); 
        glColor3ub(34, 139, 34); 
        glVertex2i(808, 190); 
        glVertex2i(828, 190);
        glVertex2i(828, 140); 
        glVertex2i(808, 140);
    glEnd();

    glBegin(GL_LINES); 
        glColor3ub(0, 0, 0);
        glVertex2i(813, 140); glVertex2i(813, 99); 
        glVertex2i(823, 140); glVertex2i(823, 99); 
        glEnd();


    // 3rd manush    
    glBegin(GL_POLYGON); 
    glColor3ub(200, 150, 110);
    for(int i=0; i<360; i++) {
        float rad = i * 3.14159 / 180;
        glVertex2f(500 + 10 * cos(rad), 150 + 10 * sin(rad));
    }
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(128, 0, 128); 
        glVertex2i(490, 140); 
        glVertex2i(510, 140);
        glVertex2i(510, 90); 
        glVertex2i(490, 90);
    glEnd();

    glBegin(GL_LINES); 
        glColor3ub(0, 0, 0);
        glVertex2i(495, 90); glVertex2i(495, 49); 
        glVertex2i(505, 90); glVertex2i(505, 49); 
    glEnd();

    

     glFlush();
}


void display4() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    a_sky();
    a_sun();
    a_clouds();
    a_mountains();
    a_river();

    a_ground();
    a_railLine();
    a_railBridge();
    a_train();
    a_tree_1();
    a_tree_2();
    a_fences();
    glFlush();

}


void display5()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    int triangleAmount = 1000;
    GLfloat twicePi = 2.0f * PI;


    //sky
    glColor3f(0.639f, 0.835f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 484.644f);
    glVertex2f(1200.0f, 488.5f);
    glVertex2f(1200.0f, 800.0f);
    glVertex2f(0.0f, 800.0f);
    glEnd();


    //cloud

    GLfloat x=0.0f;
    GLfloat y=700.0f;
    GLfloat radius = 54.0f ;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x + (radius * cos(i * twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat x1=50.0f;
    GLfloat y1=780.0f;
    GLfloat radius1 = 64.0f ;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x1 + (radius1 * cos(i * twicePi / triangleAmount)),
                    y1 + (radius1 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat x2=140.0f;
    GLfloat y2=790.0f;
    GLfloat radius2= 44.0f ;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x2 + (radius2 * cos(i * twicePi / triangleAmount)),
                    y2 + (radius2* sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x3=430.0f;
    GLfloat y3=760.0f;
    GLfloat radius3= 20.0f ;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x3 + (radius3 * cos(i * twicePi / triangleAmount)),
                    y3 + (radius3* sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x4=466.0f;
    GLfloat y4=760.0f;
    GLfloat radius4= 25.0f ;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x4 + (radius4* cos(i * twicePi / triangleAmount)),
                    y4 + (radius4* sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

      GLfloat x5=445.0f;
    GLfloat y5=730.0f;
    GLfloat radius5= 20.0f ;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x5 + (radius5* cos(i * twicePi / triangleAmount)),
                    y5+ (radius5* sin(i * twicePi / triangleAmount)) );
    }
    glEnd();




    GLfloat x6=420.0f;
    GLfloat y6=738.0f;
    GLfloat radius6= 20.0f ;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x6+ (radius6* cos(i * twicePi / triangleAmount)),
                    y6+ (radius6* sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat x7=475.0f;
    GLfloat y7=725.0f;
    GLfloat radius7= 20.0f ;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x7+ (radius7* cos(i * twicePi / triangleAmount)),
                    y7+ (radius7* sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    GLfloat x8=680.0f;
    GLfloat y8=620.0f;
    GLfloat radius8= 19.0f ;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x8+ (radius8* cos(i * twicePi / triangleAmount)),
                    y8+ (radius8* sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


    GLfloat x9=715.0f;
    GLfloat y9=640.0f;
    GLfloat radius9= 23.0f ;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x9, y9);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x9+ (radius9* cos(i * twicePi / triangleAmount)),
                    y9+ (radius9* sin(i * twicePi / triangleAmount)) );
    }
    glEnd();



    GLfloat x10=685.0f;
    GLfloat y10=650.0f;
    GLfloat radius10= 21.0f ;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x10,y10);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x10+ (radius10* cos(i * twicePi / triangleAmount)),
                    y10+ (radius10* sin(i * twicePi / triangleAmount)) );
    }
    glEnd();


        //Sun

    GLfloat x0=950.0f;
    GLfloat y0=660.0f;
    GLfloat radius0 = 44.0f ;
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x0, y0);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f( x0 + (radius0 * cos(i * twicePi / triangleAmount)),
                    y0 + (radius0 * sin(i * twicePi / triangleAmount)) );
    }
    glEnd();

    //Hills
    glColor3f(0.325f, 0.482f, 0.184f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 484.64f);
    glVertex2f(0.0f, 669.95f);
    glVertex2f(35.21f, 662.23f);
    glVertex2f(65.17f, 658.377f);
    glVertex2f(105.05f, 650.65f);
    glVertex2f(134.97f, 635.21f);
    glVertex2f(164.9f, 623.62f);
    glVertex2f(200.0f, 600.0f);
    glVertex2f(234.73f, 619.77f);
    glVertex2f(264.66f, 639.07f);
    glVertex2f(300.0f, 600.0f);
    glVertex2f(324.51f, 565.71f);
    glVertex2f(352.45f, 519.39f);
    glVertex2f(382.36f, 485.87f);
    glVertex2f(0.0f, 484.64f);
    //glEnd();
    //glColor3f(0.078f, 0.173f, 0.078f);
    glColor3f(0.176f, 0.318f, 0.157f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(324.51f, 565.71f);
    glVertex2f(358.43f, 631.35f);
    glVertex2f(400.33f, 650.65f);
    glVertex2f(440.23f, 635.21f);
    glVertex2f(472.15f, 619.77f);
    glVertex2f(504.08f, 631.35f);

    glVertex2f(324.51f, 565.71f);
    glVertex2f(551.96f, 650.65f);
    glVertex2f(593.86f, 658.37f);
    glVertex2f(633.76f, 639.07f);
    glVertex2f(667.68f, 615.91f);
    glVertex2f(700.0f, 600.0f);
    glVertex2f(731.53f, 604.32f);
    glVertex2f(771.43f, 635.21f);
    glVertex2f(803.35f, 642.93f);
    glVertex2f(835.27f, 627.49f);
    glVertex2f(867.2f, 577.3f);
    glVertex2f(889.14f, 534.83f);
    glVertex2f(907.08f, 487.59f);
    //small hill
    glVertex2f(382.36f, 485.87f);
    glVertex2f(324.51f, 565.71f);
    glEnd();


    glColor3f(0.325f, 0.482f, 0.184f);
    glBegin(GL_POLYGON);
    glVertex2f(713.14f, 486.93f);
    glVertex2f(729.15f, 509.75f);
    glVertex2f(736.51f, 522.74f);
    glVertex2f(743.00f, 530.26f);
    glVertex2f(752.95f, 545.3f);
    glVertex2f(762.47f, 558.9f);
    glVertex2f(774.59f, 574.33f);
    glVertex2f(785.85f, 586.33f);
    glVertex2f(800.0f, 600.0f);
    glVertex2f(835.27f, 627.49f);
    glVertex2f(909.39f, 644.76f);
    glVertex2f(948.08f, 647.18f);
    glVertex2f(978.17f, 630.25f);
    glVertex2f(1021.17f, 635.08f);
    glVertex2f(1062.01f, 600.0f);
    glVertex2f(1098.56f, 625.41f);
    glVertex2f(1128.65f, 606.06f);

    glVertex2f(1141.55f, 567.35f);
    glVertex2f(1167.34f, 591.54f);
    glVertex2f(1200.0f, 600.0f);
    glVertex2f(1200.0f, 488.5f);
    glVertex2f(1062.01f, 600.0f);
    glVertex2f(1098.56f, 625.41f);
    glVertex2f(1128.65f, 606.06f);
    glVertex2f(725.42f, 487.01f);
    glEnd();

    //Soil

    glColor3f(0.87f, 0.64f, 0.38f);
    //glColor3f(0.6f, 0.3f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 500.0f);
    glVertex2f(1200.0f, 500.0f);
    glVertex2f(1200.0f, 390.91f);
    glVertex2f(0.00f, 360.0f);
    glEnd();


    //RailLine
    glColor3f(0.9f, 0.9f, 0.88f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 420.0f);
    glVertex2f(1200.0f, 420.0f);
    glVertex2f(1200.0f, 460.0f);
    glVertex2f(0.00f, 460.0f);
    glEnd();

    glLineWidth(6);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 457.0f);
    glVertex2f(1200.0f, 457.0f);
    glEnd();

    glLineWidth(6);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 420.0f);
    glVertex2f(1200.0f, 420.0f);
    glEnd();

    glColor3f(0.5f, 0.35f, 0.2f);
    for(float x = 30.0f; x < 1200.0f; x += 60.0f)
    {
    glBegin(GL_POLYGON);
    glVertex2f(x, 464.0f);
    glVertex2f(x + 8.0f, 464.0f);
    glVertex2f(x + 8.0f, 412.0f);
    glVertex2f(x, 412.0f);
    glEnd();
    }


   //Train
    glPushMatrix();
    glTranslatef(trainPos, 0, 0);

    int z= 440;

    //Bogey1
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(100, z);
    glVertex2f(300, z);
    glVertex2f(300, z+40);
    glVertex2f(100, z+40);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(100, z+40);
    glVertex2f(300, z+40);
    glVertex2f(300, z+80);
    glVertex2f(100, z+80);
    glEnd();

    drawWindowsAndDoor(100, z);
    //wheels
    glColor3f(0,0,0);
    drawCircle1(140, z-10, 10);
    drawCircle1(260,z-10, 10);

    //Bogey2
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(310, z);
    glVertex2f(510, z);
    glVertex2f(510, z+40);
    glVertex2f(310, z+40);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(310, z+40);
    glVertex2f(510, z+40);
    glVertex2f(510, z+80);
    glVertex2f(310, z+80);
    glEnd();
    drawWindowsAndDoor(310, z);
    glColor3f(0,0,0);
    drawCircle1(350, z-10, 10);
    drawCircle1(470,z-10, 10);

    //Bogey3
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(520, z);
    glVertex2f(720, z);
    glVertex2f(720, z+40);
    glVertex2f(520, z+40);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(520, z+40);
    glVertex2f(720, z+40);
    glVertex2f(720, z+80);
    glVertex2f(520, z+80);
    glEnd();
    drawWindowsAndDoor(520, z);
    glColor3f(0,0,0);
    drawCircle1(560, z-10, 10);
    drawCircle1(680,z-10, 10);


    //Bogey4
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(730, z);
    glVertex2f(930, z);
    glVertex2f(930, z+40);
    glVertex2f(730, z+40);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(730, z+40);
    glVertex2f(930, z+40);
    glVertex2f(930, z+80);
    glVertex2f(730, z+80);
    glEnd();
    drawWindowsAndDoor(730, z);
    glColor3f(0,0,0);
    drawCircle1(770, z-10, 10);
    drawCircle1(890,z-10, 10);

     //Bogey5
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(940, z);
    glVertex2f(1150, z);
    glVertex2f(1150, z+40);
    glVertex2f(940, z+40);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(940, z+40);
    glVertex2f(1150, z+40);
    glVertex2f(1120, z+80);
    glVertex2f(940, z+80);
    glEnd();
    drawWindowsAndDoor(940, z);
    glColor3f(0,0,0);
    drawCircle1(980, z-10, 10);
    drawCircle1(1100,z-10, 10);

    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(5);

     glBegin(GL_QUADS);
    glVertex2f(140, z-7);
    glVertex2f(1100, z-7);
    glVertex2f(1100, z-14);
    glVertex2f(140, z-14);
    glEnd();


    glPopMatrix();


    //Sea
    glColor3f(0.0f, 0.702f, 0.863f);
    glBegin(GL_POLYGON);
    glVertex2f(0.00f, 360.0f);
    glVertex2f(1200.0f, 400.91f);
    glVertex2f(1200.0f, 0.0f);
    glVertex2f(0.00f, 0.0f);
    glEnd();


    //boat 1
    glPushMatrix();
    glTranslatef(boatPos, 0.0f, 0.0f);

    //hull
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(300.0f, 240.0f);
    glVertex2f(360.0f, 200.0f);
    glVertex2f(420.0f, 200.0f);
    glVertex2f(480.0f, 240.0f);
    glEnd();

    //2 Red sail
    glColor3f(01.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(372.0f, 248.0f);
    glVertex2f(384.0f, 280.0f);
    glVertex2f(384.0f, 248.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(420.0f, 248.0f);
    glVertex2f(390.0f, 320.0f);
    glVertex2f(390.0f, 248.0f);
    glEnd();
    glPopMatrix();

    //boat 2
    glPushMatrix();
    glTranslatef(boatPos, 0.0f, 0.0f);

    //green hull
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(940.0f, 300.0f);
    glVertex2f(1000.0f, 300.0f);
    glVertex2f(1055.0f, 340.0f);
    glVertex2f(885.0f, 340.0f);
    glEnd();

    //2 Red sail
    glColor3f(01.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(952.0f, 344.0f);
    glVertex2f(965.0f, 344.0f);
    glVertex2f(965.0f,  373.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(970.0f, 344.0f);
    glVertex2f(970.0f, 398.0f);
    glVertex2f(995.0f, 344.0f);
    glEnd();
    glPopMatrix();

    glFlush();
}

void display6()
{
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
      buildings();
    grass();
    trainTrack();
    train();    // Train
    road();
    road1();
    road2();
    road3();
    car1();  // Blue car moving left to right
    car2();  // Yellow car moving right to left

    glFlush();
}


void display7()
{
    glClear(GL_COLOR_BUFFER_BIT);

    sky1();
    ground();
    road5();
    railway();
    mountain();
    train5();
    signal();
    gate();
    pole();
    generator();


    glFlush();
}


void keyboard(unsigned char key, int x, int y) {
    PlaySound(NULL, 0, 0);
    if (key == 49)
    {
        currentFrame = 1;
    }
    if (key == 50) {
        currentFrame = 2;
    }
    if (key == 51)
    {
        currentFrame = 3;
        
    }
    if (key == 'b' || key == 'B')
    {
        trainX = 1400.0f;     // start off-screen
        trainMoving = true;
        trainStopping = false;
        trainLeaving = false;
        if(currentFrame == 3)
        {
            PlaySound("subway-station-456318.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        }
    }

    if (key == 'd' || key == 'D')
    {
        isDay = true;
         if(currentFrame == 3)
        {
            PlaySound("subway-station-456318.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        }
    }
    
    if (key == 'n' || key == 'N')
    {
        isDay = false;
         if(currentFrame == 3)
        {
            PlaySound("subway-station-456318.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
        }
    }
    if (key == 52)
    {
        currentFrame = 4;
        
    }
    
    if (key == 'c' || key == 'C')
    {
        cloudMove = !cloudMove;
    }

    if (key == 't' || key == 'T')
    {
        trainMove = !trainMove;

        if (trainMove)
        {
            // loop sound while train moves
            PlaySound(TEXT("train_horn.wav"), NULL,
                      SND_FILENAME | SND_ASYNC | SND_LOOP);
        }
        else
        {
            // stop sound
            PlaySound(NULL, 0, 0);
        }
    }

    if (key == 53)
    {
        currentFrame = 5;
        PlaySound(TEXT("train.wav"), NULL, SND_ASYNC | SND_LOOP);
    }

    if (key == 54)
    {
        currentFrame = 6;
    }

    if (key == 55)
    {
        currentFrame = 7;
    }


    glutPostRedisplay(); // refresh window
}

void SpecialInput(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)
        trainSpeed += 0.5f;

    if(key == GLUT_KEY_DOWN && trainSpeed - 0.5f > 0.0f)
        trainSpeed -= 0.5f;
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1200, 0, 800);

    glMatrixMode(GL_MODELVIEW);  //by anisa
    glLoadIdentity();
}




void display() {
    if (currentFrame == 1) display1();
    else if (currentFrame == 2) display2();
    else if (currentFrame == 3) display3();
    else if (currentFrame == 4) display4();
    else if (currentFrame == 5) display5();
    else if (currentFrame == 6) display6();
    else display7();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(120, 50);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //by alvi ,rafid,marin
    glutCreateWindow("Visualizing Modern Rail Systems");
    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, update1, 0);
    glutTimerFunc(0, cloudAnimation, 0);
    glutTimerFunc(0, trainAnimation, 0);
    glutTimerFunc(66, update3, 0);
    glutTimerFunc(0, update4, 0);
    glutTimerFunc(100, update5, 0);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(SpecialInput);
    glutMainLoop();
    return 0;
}