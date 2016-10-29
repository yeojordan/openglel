#include "wheel.h"

void wheel(double animSpd, int segments)
{
    glDisable(GL_COLOR_MATERIAL);
    float mat_ambient[] ={0.25f, 0.148f, 0.06475f, 1.0f  };
    float mat_diffuse[] ={0.4f, 0.2368f, 0.1036f, 1.0f };
    float mat_specular[] ={0.774597f, 0.458561f, 0.200621f, 1.0f };
    float shine =76.8f ;

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);

    //Side View
    glRotatef(45.0, 0.0f, 1.0f, 0.0f);
glTranslatef(-animSpd*15, 7.0,0.0);

glPushMatrix();

    glRotatef(60*animSpd, 0.0,0.0,1.0);


    // Outer Torus
    glPushMatrix();
        glutSolidTorus(1.5f, 10.0f, 16, 2*segments);
    glPopMatrix();


    // Inner Disk
    glPushMatrix();
        solidCylinder(4.0, segments, 2.0);
    glPopMatrix();

    //Creating arms
    glPushMatrix();
        glRotatef(90.0, 1.0f, 0.0f, 0.0f);
        //glTranslatef(0.0f, -3.0f, 0.0f);
        // glColor3f( 0.4, 0.0, 0.0 );
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
glPopMatrix();
glEnable(GL_COLOR_MATERIAL);
}
