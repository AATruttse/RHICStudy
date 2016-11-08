
    #ifdef __APPLE__
    #include <GLUT/glut.h>
    #else
    #include <GL/glut.h>
    #endif

    #include <math.h>
    #include <stdlib.h>

    #include "GEngine.h"
    #include "Snowss.h"


    int main(int argc, char **argv) {

    // инициализация GLUT и создание окна
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("Урок - 7");

    // регистрация
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);

    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);

    // регистрируем две новые функции
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);

    // OpenGL - инициализация функции теста
    glEnable(GL_DEPTH_TEST);

    //CGraphics graph;

    //graph.drawLine(1.0,2.0,3.0,3.0,4.0,5.0);

    // главный цикл
    glutMainLoop();

    return 1;
    }



