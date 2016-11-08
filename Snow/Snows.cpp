#include "Snowss.h"
    #ifdef __APPLE__
    #include <GLUT/glut.h>
    #else
    #include <GL/glut.h>
    #endif
    #include <math.h>
    #include <stdlib.h>
    #include <iostream>
    #include <cstdlib>
#include "GEngine.h"
void changeSize(int w, int h);
    void drawSnowMan();
    void computePos(float deltaMove);
    void renderScene(void);
    void processNormalKeys(unsigned char key, int xx, int yy);
    void change_camera_angles(float deltaAngleXY,float deltaAngleXZ);
    void pressKey(int key, int xx, int yy);
    void releaseKey(int key, int x, int y);
    void mouseMove(int x, int y);
    void mouseButton(int button, int state, int x, int y);
    // угол поворота камеры
    float angleXZ=0.0;
    float angleXY=0.0;
    // координаты вектора направления движения камеры
    float lx=0.0f, ly = 0.0f, lz=-1.0f;
    // XZ позиция камеры
    float x=0.0f, y = 0.0f, z=5.0f;
    //Ключи статуса камеры. Переменные инициализируются нулевыми значениями
    //когда клавиши не нажаты
    float stepAngle = 0.001f;
    float stepAngleXY = 0;
    float stepAngleXZ = 0;
    float deltaAngleXZ = 0.0f;
    float deltaAngleXY = 0.0f;
    float deltaMove = 0;
    int xOrigin = -1;
    int yOrigin = -1;

    void changeSize(int w, int h) {
    // предотвращение деления на ноль
    if (h == 0)
    h = 1;
    float ratio = w * 1.0 / h;
    // используем матрицу проекции
    glMatrixMode(GL_PROJECTION);
    // обнуляем матрицу
    glLoadIdentity();
    // установить параметры вьюпорта
    glViewport(0, 0, w, h);
    // установить корректную перспективу
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
    // вернуться к матрице проекции
    glMatrixMode(GL_MODELVIEW);
    }

    void drawSnowMan() {
    glColor3f(1.0f, 1.0f, 1.0f);
    // тело снеговика
    glTranslatef(0.0f ,0.75f, 0.0f);
    glutSolidSphere(0.75f,20,20);
    // голова снеговика
    glTranslatef(0.0f, 1.0f, 0.0f);
    glutSolidSphere(0.25f,20,20);
    // глаза снеговика
    glPushMatrix();
    glColor3f(0.0f,0.0f,0.0f);
    glTranslatef(0.05f, 0.10f, 0.18f);
    glutSolidSphere(0.05f,10,10);
    glTranslatef(-0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.05f,10,10);
    glPopMatrix();
    // нос снеговика
    glColor3f(1.0f, 0.5f , 0.5f);
    glRotatef(0.0f,1.0f, 0.0f, 0.0f);
    glutSolidCone(0.08f,0.5f,10,2);

    }

    void computePos(float deltaMove)
    {
    x += deltaMove * lx * 0.1f;
    y += deltaMove * ly * 0.1f;
    z += deltaMove * lz * 0.1f;
    }
    void change_camera_angles(float deltaAngleXY,float deltaAngleXZ)
    {
    lx = sin(angleXZ + deltaAngleXZ);
    lz = -cos(angleXZ + deltaAngleXZ);
    ly = sin(angleXY + deltaAngleXY);
    lx = lx*cos(angleXY + deltaAngleXY);
    lz = lz*cos(angleXY + deltaAngleXY);
    }

    void renderScene(void) {
    if (deltaMove)
    computePos(deltaMove);

    angleXY += stepAngleXY;
    angleXZ += stepAngleXZ;

    change_camera_angles( deltaAngleXY,deltaAngleXZ);

    //очистить буфер цвета и глубины
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // обнулить трансформацию
    glLoadIdentity();
    // установить камеру
    gluLookAt( x, y, z,
    x+lx, y+ly, z+lz,
    0.0f, 1.0f, 0.0f );

    /*
    // нарисуем "землю"
    glColor3f(0.9f, 0.9f, 0.9f);
    // полигон (plaine)
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glVertex3f(-100.0f, 0.0f, 100.0f);
    glVertex3f( 100.0f, 0.0f, 100.0f);
    glVertex3f( 100.0f, 0.0f, -100.0f);
    glEnd();
    // Нарисуем 64 снеговика
    for (int i = -4; i < 4; i++)
    for (int j=-4; j < 4; j++)
    {
    glPushMatrix();
    glTranslatef(i*5.0, 0, j * 5.0);
    drawSnowMan();
    glPopMatrix();
    }*/

    CGraphics graph;

    for (int i = 0; i < 100; i++)
    {
        graph.drawBox(1,2,4,-rand() % 100,-rand() % 100,-rand() % 100);
    }

    glutSwapBuffers();
    }

    void processNormalKeys(unsigned char key, int xx, int yy) {

    if (key == 27)
    exit(0);
    }

    void pressKey(int key, int xx, int yy) {
    int mod;
    mod = glutGetModifiers();
    switch (key) {
    case GLUT_KEY_UP :
    if (mod == GLUT_ACTIVE_CTRL){

    stepAngleXY = stepAngle;

    }
    else deltaMove = 0.5f;
    break;
    case GLUT_KEY_DOWN :
    if (mod == GLUT_ACTIVE_CTRL) {
    stepAngleXY = -stepAngle;}
    else deltaMove = -0.5f;
    break;
    case GLUT_KEY_RIGHT : stepAngleXZ = stepAngle;
    break;
    case GLUT_KEY_LEFT : stepAngleXZ = -stepAngle; break;
    }
    }

    void releaseKey(int key, int x, int y) {
    int mod;
    mod = glutGetModifiers();

    switch (key) {
    case GLUT_KEY_UP :
    stepAngleXY = 0.f;
    deltaMove = 0;
    break;
    case GLUT_KEY_DOWN :
    stepAngleXY = 0.f;
    deltaMove = 0;
    break;
    case GLUT_KEY_RIGHT :
    case GLUT_KEY_LEFT : stepAngleXZ = 0.f; break;

    }

    }

    void mouseMove(int x, int y) {

    // this will only be true when the left button is down
    if (xOrigin >= 0) {

    // update deltaAngle
    deltaAngleXZ = (x - xOrigin) * 0.001f;

    }

    if (yOrigin >= 0) {

    // update deltaAngle
    deltaAngleXY = (y - yOrigin) * 0.001f;

    }
    change_camera_angles(deltaAngleXY,deltaAngleXZ);
    }

    void mouseButton(int button, int state, int x, int y) {

    // only start motion if the left button is pressed
    if (button == GLUT_LEFT_BUTTON) {

    // when the button is released
    if (state == GLUT_UP) {

    angleXZ += deltaAngleXZ;
    angleXY += deltaAngleXY;
    deltaAngleXZ = 0.f;
    deltaAngleXY = 0.f;
    xOrigin = -1;
    yOrigin = -1;
    }
    else {// state = GLUT_DOWN
    xOrigin = x;
    yOrigin = y;
    }
    }
    }
