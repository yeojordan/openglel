#include "cage.h"

void cage(int segments)
{
    int i;

    glColor3f(0.3,0.3,0.3);
    glPushMatrix();


        glPushMatrix();
        glTranslatef(0.0f, 0.0f, -30.0f);
        glPushMatrix();

            glRotatef(90.0, 1.0f, 0.0f, 0.0f);

            glPushMatrix();
                glTranslatef(30.0f, 0.0f, 0.f);

                // Right row
                for(i = 0; i < 4; i++)
                {
                    glPushMatrix();
                        solidCylinder(3.0f, segments, 80.0f);
                    glPopMatrix();
                    glTranslatef(0.0f, 20.0f, 0.0f);
                }
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-30.0f, 0.0f, 0.f);

                // Left row
                for(i = 0; i < 4; i++)
                {
                    glPushMatrix();
                        solidCylinder(3.0f, segments, 80.0f);
                    glPopMatrix();
                    glTranslatef(0.0f, 20.0f, 0.0f);
                }
            glPopMatrix();

            // Back Row
            glPushMatrix();
                glTranslatef(10.0f, 9.5f, 0.0f);
                glRotatef(90.0, 0.0f, 0.0f, 1.0f);
                glTranslatef(-10.0f, 0.0f, 0.f);

                // Left row
                for(i = 0; i < 2; i++)
                {
                    glPushMatrix();
                        solidCylinder(3.0f, segments, 80.0f);
                    glPopMatrix();
                    glTranslatef(0.0f, 20.0f, 0.0f);
                }
            glPopMatrix();

            // Back Row
            glPushMatrix();
                glTranslatef(10.0f, 69.5f, 0.0f);
                glRotatef(90.0, 0.0f, 0.0f, 1.0f);
                glTranslatef(-10.0f, 0.0f, 0.f);

                // Left row
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

        //glRotatef(90.0, 1.0f, 0.0f, 0.0f);
        glPushMatrix();

			//glColor3f(255.0f/540.0f, 184.0f/540.0f, 77.0f/540.0f);
			glScalef(40.0f, 1.0f ,  40.0f);
			glTranslatef(0.0f, 40.0f,0.0f  );
			glutSolidCube(2.0f);
		glPopMatrix();

        glPushMatrix();

			//glColor3f(255.0f/540.0f, 184.0f/540.0f, 77.0f/540.0f);
			glScalef(40.0f, 1.0f ,  40.0f);
			glTranslatef(0.0f, -40.0f,0.0f  );
			glutSolidCube(2.0f);
		glPopMatrix();
    glPopMatrix();
}
