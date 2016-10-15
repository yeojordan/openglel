#include "mast.h"

void mast(int segments)
{

    GLUquadric* quad = gluNewQuadric();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 2);

    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        gluQuadricTexture(quad, true);
        // Main Pole
        glPushMatrix();
            glRotatef(90.0, 1.0f, 0.0f, 0.0f);
            solidCylinder(4.0, segments, 150.0);
        glPopMatrix();

        // Basket
        glPushMatrix();
            glRotatef(90.0, 1.0f, 0.0f, 0.0f);


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
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
