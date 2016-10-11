#include "anchor.h"

void anchor(int segments)
{

		// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	  //   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	  //   glBindTexture(GL_TEXTURE_2D, TEX_CAN);

		//Side View
		// glRotatef(90.0, 0.0f, 1.0f, 0.0f);



		glPushMatrix();
			//glEnable(GL_TEXTURE_2D);
			glColor3f(1.0, 0.0, 0.0);
			// Top loop
			glPushMatrix();
				glTranslatef(0.0f,22.0f, 0.0f);
				glScalef(1.0f, 1.0f, 1.5f);
				glutSolidTorus(1.25f, 3.0f, 16, 2*segments);
			glPopMatrix();

			// Main Pole
			glPushMatrix();
				glRotatef(-90,1.0f,0.0f,0.0f);
				//glColor3f(1.0f,1.0f,1.0f);
				GLUquadric* quad = gluNewQuadric();
				gluQuadricTexture(quad, true);
				glTranslatef(0.0f,0.0f,-4.0f);
				gluCylinder(quad, 1.5f, 1.5f, 22.0, segments, segments);

				// Sideways Pole
				glPushMatrix();
					GLUquadric* quad2 = gluNewQuadric();
					glTranslatef(10.0f,20.0f, 0.0f);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					glTranslatef(18.0f,-20.0f, 0.0f);
					gluCylinder(quad2, 1.5f, 1.5f, 20.0, segments, segments);
				glPopMatrix();


				// Right sphere
				// (Left-Right, In-Out, Up-Down)
				glPushMatrix();
					GLUquadric* quad7 = gluNewQuadric();
					glTranslatef(10.0f, 0.0f, 18.0f);
					gluSphere(quad7,  2.5f,  30,  segments);
				glPopMatrix();

				// Left sphere
				// (Left-Right, In-Out, Up-Down)
				glPushMatrix();
					GLUquadric* quad8 = gluNewQuadric();
					glTranslatef(-10.0f, 0.0f, 18.0f);
					gluSphere(quad8,  2.5f,  30, segments);
				glPopMatrix();


				// Base Tip
				glPushMatrix();
					GLUquadric* quad9 = gluNewQuadric();
					glTranslatef(0.0f,0.0f, 0.25f);
					glRotatef(180.0, 0.0, 1.0, 0.0);
					//glTranslatef(-6.25f,0.0f, -3.0f);
					gluCylinder(quad9, 1.6f, 0.1f, 1.5f, segments, segments);
				glPopMatrix();




				// Left anchor base
				glPushMatrix();
					GLUquadric* quad3 = gluNewQuadric();
					glTranslatef(0.0f,0.0f, 1.0f);
					glRotatef(-70.0, 0.0, 1.0, 0.0);
					// glTranslatef(14.0f,-20.0f, 0.0f);
					gluCylinder(quad3, 1.5f, 1.5f, 11.0, segments, segments);
				glPopMatrix();

				// Right anchor base
				glPushMatrix();
					GLUquadric* quad4 = gluNewQuadric();
					glTranslatef(0.0f,0.0f, 1.0f);
					glRotatef(70.0, 0.0, 1.0, 0.0);
					// glTranslatef(14.0f,-20.0f, 0.0f);
					gluCylinder(quad4, 1.5f, 1.5f, 11.0, segments, segments);
				glPopMatrix();

				// Right Anchor Tip
				glPushMatrix();
					GLUquadric* quad5 = gluNewQuadric();
					glTranslatef(15.0f,0.0f, 0.0f);
					glRotatef(70.0, 0.0, 1.0, 0.0);
					glTranslatef(-6.25f,0.0f, -3.0f);
					gluCylinder(quad5, 2.0f, 0.1f, 4.0, segments, segments);
				glPopMatrix();

				// Left Anchor Tip
				glPushMatrix();
					GLUquadric* quad6 = gluNewQuadric();
					glTranslatef(15.0f,0.0f, 10.0f);
					glRotatef(-70.0, 0.0, 1.0, 0.0);
					glTranslatef(-13.5f,0.0f, 22.0f);
					gluCylinder(quad6, 2.0f, 0.1f, 4.0, segments, segments);
				glPopMatrix();






				free(quad);

				//glDisable(GL_TEXTURE_2D);
			glPopMatrix();

		glPopMatrix();
}
