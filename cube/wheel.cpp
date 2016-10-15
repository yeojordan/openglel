#include "wheel.h"

void wheel(int segments)
{
    
    //Side View
    //glRotatef(90.0, 0.0f, 1.0f, 0.0f);


    // Outer Torus
    glPushMatrix();
        // GLUquadric* quad = gluNewQuadric();
        // gluQuadricTexture(quad, true);
        //glTranslatef(0.0f,0.0f,-4.0f);
        //gluCylinder(quad, 1.5f, 1.5f, 22.0, segments, segments);
        //glTranslatef(0.0f,0.0f, 0.0f);
        //glScalef(1.0f, 1.0f, 1.5f);
        glutSolidTorus(1.5f, 10.0f, 16, 2*segments);
    glPopMatrix();


    // Inner Disk
    glPushMatrix();
        solidCylinder(4.0, segments, 2.0);
    glPopMatrix();

    // // Handles
    // glPushMatrix();
    //     glRotatef(90.0, 1.0f, 0.0f, 0.0f);
    //     for(int i = 0; i < 6; i++)
    //     {
    //         //glRotatef(angle, 1.0f, 0.0f, 0.0f);
    //         solidCylinder(1.0, segments, 6.0);
    //         angle +=60.0;
    //
    //
    //         solidCylinder(1.0, segments, 6.0);
    //
    //     }
    // glPopMatrix();


    //Creating arms
    glPushMatrix();
        glRotatef(90.0, 1.0f, 0.0f, 0.0f);
        //glTranslatef(0.0f, -3.0f, 0.0f);
        glColor3f( 0.4, 0.0, 0.0 );
        //glScalef(2,0.7,2);
        for (int i = 0; i <= 180; i=i+45)
        {
            glPushMatrix();
                //glRotatef(-35-(6* sin(6.2*animTime)) ,1.0f,0.0f,0.0f);
                solidCylinder(1.0, segments, 30.0);
            glPopMatrix();
            glRotatef(-i,0.0f,1.0f,0.0f);
        }
    glPopMatrix();

}
