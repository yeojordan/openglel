#include "bubbles.h"

void bubbles(double animSpd, int segments)
{
    GLUquadric* quad = gluNewQuadric();

    glTranslatef(0.0,animSpd*10,0.0);
    glPushMatrix();
        glTranslatef(-60.0f, 0.0f, 120.0f);
        glColor4f(1.0f, 1.0f, 1.0f, 0.05);
        gluSphere(quad,  4.5f,  30,  segments);

        glPushMatrix();
        glTranslatef(20.0, 15.0, -3.0);
        gluSphere(quad,  6.5f,  20,  segments);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(5.0, 20.0, -6.0);
        gluSphere(quad,  7.0f,  30,  segments);
        glPopMatrix();

        //glutSolidCube();
    glPopMatrix();
}
