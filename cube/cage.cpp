#include "cage.h"
#include "chain.h"
#include <stdio.h>

void cage(double animSpd, int segments)
{
    int i;
    double height = 4  * animSpd;

    // Surface Material
    glDisable(GL_COLOR_MATERIAL);
    float mat_ambient[] ={ 0.19125f, 0.0735f, 0.0225f, 1.0f };
    float mat_diffuse[] ={0.7038f, 0.27048f, 0.0828f, 1.0f };
    float mat_specular[] ={0.256777f, 0.137622f, 0.086014f, 1.0f };
    float shine = 12.8f;

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, shine);


    glColor3f(0.3,0.3,0.3);


    glPushMatrix();

        // Animation for cage
        glTranslatef(0.0,height,0.0);

        glPushMatrix();
            glPushMatrix();
                glScalef(2.0, 1.0, 2.0);
                drawChain(50, segments, 0.0,43.0,0.0);
            glPopMatrix();

            glTranslatef(0.0f, 0.0f, -30.0f);


            glPushMatrix();

                glRotatef(90.0, 1.0f, 0.0f, 0.0f);

                // Right row of cage
                glPushMatrix();
                    glTranslatef(30.0f, 0.0f, 0.f);

                    // Bars
                    for(i = 0; i < 4; i++)
                    {
                        glPushMatrix();
                            solidCylinder(3.0f, segments, 80.0f);
                        glPopMatrix();
                        glTranslatef(0.0f, 20.0f, 0.0f);
                    }
                glPopMatrix();

                // Left Row of Cage
                glPushMatrix();
                    glTranslatef(-30.0f, 0.0f, 0.f);
                    // Bars
                    for(i = 0; i < 4; i++)
                    {
                        glPushMatrix();
                            solidCylinder(3.0f, segments, 80.0f);
                        glPopMatrix();
                        glTranslatef(0.0f, 20.0f, 0.0f);
                    }
                glPopMatrix();

                // Back Row of cage
                glPushMatrix();
                    glTranslatef(10.0f, 9.5f, 0.0f);
                    glRotatef(90.0, 0.0f, 0.0f, 1.0f);
                    glTranslatef(-10.0f, 0.0f, 0.f);

                    // Bars
                    for(i = 0; i < 2; i++)
                    {
                        glPushMatrix();
                            solidCylinder(3.0f, segments, 80.0f);
                        glPopMatrix();
                        glTranslatef(0.0f, 20.0f, 0.0f);
                    }
                glPopMatrix();

                // Front Row of cage
                glPushMatrix();
                    glTranslatef(10.0f, 69.5f, 0.0f);
                    glRotatef(90.0, 0.0f, 0.0f, 1.0f);
                    glTranslatef(-10.0f, 0.0f, 0.f);

                    // Bars
                    for(i = 0; i < 2; i++)
                    {
                        glPushMatrix();
                            solidCylinder(3.0f, segments, 80.0f);
                        glPopMatrix();
                        glTranslatef(0.0f, 20.0f, 0.0f);
                    }
                glPopMatrix();
            glPopMatrix();


        glPopMatrix();
        //Top Panel
        glPushMatrix();
			glScalef(40.0f, 1.0f ,  40.0f);
			glTranslatef(0.0f, 40.0f,0.0f  );
			glutSolidCube(2.0f);
		glPopMatrix();

        //Bottom Panel
        glPushMatrix();
			glScalef(40.0f, 1.0f ,  40.0f);
			glTranslatef(0.0f, -40.0f,0.0f  );
			glutSolidCube(2.0f);
		glPopMatrix();


    glPopMatrix();

    glEnable(GL_COLOR_MATERIAL);
}
