#include "GEngine.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <iostream>

void CGraphics::drawSphere(double radius,GLfloat red, GLfloat green, GLfloat blue,GLfloat x, GLfloat y, GLfloat z)
{
    glColor3f(red,  green,  blue);
    glTranslatef(x,  y, z);
    glutSolidSphere(radius,100,20);
}

// glVertex3f - координаты центра
// glVertex3f - размеры

// 2 варианта
// 1. glVertex3f - направление большой оси
// float - поворот относительно оси

void CGraphics::drawBox(GLfloat _sizex, GLfloat _sizey, GLfloat _sizez, GLfloat _center_x, GLfloat _center_y, GLfloat _center_z){

    //glBegin(GL_QUADS);
    GLfloat px[8];
    GLfloat py[8];
    GLfloat pz[8];

    for (unsigned int i = 0; i < 8; i++)
    {
        px[i] = _sizex * 0.5f * ((i % 2) ? 1 : -1);
        py[i] = _sizey * 0.5f * (((i % 4) > 1) ? 1 : -1);
        pz[i] = _sizez * 0.5f * ((i >3) ? 1 : -1);
        px[i] += _center_x;
        py[i] += _center_y;
        pz[i] += _center_z;
    }

    unsigned int indexes[4] = {0,1,3,2};
    unsigned int index, nextIndex;
    for (unsigned int i = 0; i < 4; i++)
    {
        index = indexes[i];
        nextIndex = indexes[(i + 1) % 4];
        drawLine(px[index], py[index], pz[index], px[nextIndex],py[nextIndex],pz[nextIndex]);
        drawLine(px[index+4], py[index+4], pz[index+4], px[nextIndex+4],py[nextIndex+4],pz[nextIndex+4]);
         drawLine(px[index], py[index], pz[index], px[index+4],py[index+4],pz[index+4]);

    }


//glVertex3f(0.5f, 0.5f, 1.0f);
//glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
//glColor3f(0.7f, 0.25f, 0.55f);
//glutWireCube(1.0f);
//glEnd();
//glutSwapBuffers();

};

void CGraphics::drawPoint(GLfloat x, GLfloat y, GLfloat z ){
    glVertex3f(x,y,z);
};

void CGraphics::drawLine(GLfloat _point1x, GLfloat _point1y, GLfloat _point1z, GLfloat _point2x, GLfloat _point2y, GLfloat _point2z){

    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(1);
    glBegin(GL_LINES);

    glVertex3f(_point1x, _point1y,_point1z);
    glVertex3f(_point2x, _point2y,_point2z);
    glEnd();
    glFlush();
};

void CGraphics::drawRectangle(GLfloat x, GLfloat y, GLfloat z)
{
glBegin(GL_POLYGON);
glColor3f(1.0f,0.0f,0.0f);
glVertex3f(0.25f, 0.25f,0.0f);
glVertex3f(0.75f, 0.25f, 0.0f);
glVertex3f(0.75f, 0.75f, 0.0f);
glVertex3f(0.25f, 0.75f, 0.0f);
glLineWidth(2);
//glutWireCube(0.5f);
glEnd();
glFlush ();
//glutSwapBuffers();
};
