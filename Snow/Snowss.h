
    #ifdef __APPLE__
    #include <GLUT/glut.h>
    #else
    #include <GL/glut.h>
    #endif

#include "GEngine.h"
    #include <math.h>
    #include <stdlib.h>
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


//#endif // SNOW_H_INCLUDED
