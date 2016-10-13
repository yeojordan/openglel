#include "solidCylinder.h"

void solidCylinder(double radius, int segments, double length)
{
    GLUquadric* quad = gluNewQuadric();
    GLUquadric* quad2 = gluNewQuadric();
    GLUquadric* quad3 = gluNewQuadric();

    // Rear Disk
    glPushMatrix();
        glTranslatef(0.0f,0.0f,-0.5*length);
        gluDisk(quad2,  0.1f, radius, segments, segments);
    glPopMatrix();

    // Front Disk
    glPushMatrix();
        glTranslatef(0.0f,0.0f,0.5*length);
        gluDisk(quad3,  0.1f, radius, segments, segments);
    glPopMatrix();


    // Center
    gluQuadricTexture(quad, true);
    glTranslatef(0.0f,0.0f,-0.5*length);
    gluCylinder(quad, radius, radius, length, segments, segments);
}
