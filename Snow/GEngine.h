#ifndef GENGINE_H_INCLUDED
#define GENGINE_H_INCLUDED
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
class CGraphics
{

public:
    void drawSphere(double radius,GLfloat red, GLfloat green, GLfloat blue,GLfloat x, GLfloat y, GLfloat z);
    void drawBox(GLfloat _sizex, GLfloat _sizey, GLfloat _sizez, GLfloat _center_x, GLfloat _center_y, GLfloat _center_z);
    void drawPoint(GLfloat x, GLfloat y, GLfloat z);
    void drawLine(GLfloat _point1x, GLfloat _point1y, GLfloat _point1z, GLfloat _point2x, GLfloat _point2y, GLfloat _point2z);
    void drawRectangle(GLfloat x, GLfloat y, GLfloat z);


};




#endif // GENGINE_H_INCLUDED
