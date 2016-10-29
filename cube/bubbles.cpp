#include "bubbles.h"

void bubbles(double animSpd, int segments)
{
    GLUquadric* quad = gluNewQuadric();

    glPushMatrix();
        // glTranslatef(10.0f, 0.0f, 18.0f);
         gluSphere(quad,  2.5f,  30,  segments);

        //glutSolidCube();
    glPopMatrix();
}
