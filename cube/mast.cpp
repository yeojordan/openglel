#include "mast.h"

void mast(int segments)
{
    glPushMatrix();

        // Main Pole
        glPushMatrix();
            glRotatef(90.0, 1.0f, 0.0f, 0.0f);
            solidCylinder(4.0, segments, 150.0);
        glPopMatrix();

        // Basket
        glPushMatrix();
            glRotatef(90.0, 1.0f, 0.0f, 0.0f);
            GLUquadric* quad = gluNewQuadric();
            GLUquadric* quad2 = gluNewQuadric();
            glTranslatef(0.0f, 0.0f, -40.0f);
            gluCylinder(quad, 20.0f, 6.0f, 15.0f, segments, segments);
            // glPushMatrix();
            //     gluDisk(quad2,  6.0f, 6.0f, segments, segments);
            // glPopMatrix();
        glPopMatrix();

        // Sideways post
        glPushMatrix();
            glRotatef(90.0, 0.0f, 1.0f, 0.0f);
            glTranslatef(0.0f, 20.0f, 0.0f);
            solidCylinder(4.0, segments, 100.0 );
        glPopMatrix();
    glPopMatrix();
}
