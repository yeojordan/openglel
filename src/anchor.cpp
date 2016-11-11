#include "anchor.h"

void anchor(int segments)
{
		GLUquadric* quad = gluNewQuadric();

		// Texture
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	    glBindTexture(GL_TEXTURE_2D, 3);

		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			gluQuadricTexture(quad, true);
			glColor3f(0.5, 0.5, 0.5);

			// Top loop
			glPushMatrix();
				glTranslatef(0.0f,22.0f, 0.0f);
				glScalef(1.0f, 1.0f, 1.5f);
				glutSolidTorus(1.25f, 3.0f, 16, 2*segments);
			glPopMatrix();

			// Main Pole
			glPushMatrix();
				glRotatef(-90,1.0f,0.0f,0.0f);
				glTranslatef(0.0f,0.0f,-4.0f);
				gluCylinder(quad, 1.5f, 1.5f, 22.0, segments, segments);

				// Sideways Pole
				glPushMatrix();
					glTranslatef(10.0f,20.0f, 0.0f);
					glRotatef(-90.0, 0.0, 1.0, 0.0);
					glTranslatef(18.0f,-20.0f, 0.0f);
					gluCylinder(quad, 1.5f, 1.5f, 20.0, segments, segments);
				glPopMatrix();


				// Right sphere
				glPushMatrix();
					glTranslatef(10.0f, 0.0f, 18.0f);
					gluSphere(quad,  2.5f,  30,  segments);
				glPopMatrix();

				// Left sphere
				glPushMatrix();
					glTranslatef(-10.0f, 0.0f, 18.0f);
					gluSphere(quad,  2.5f,  30, segments);
				glPopMatrix();


				// Base Tip
				glPushMatrix();
					glTranslatef(0.0f,0.0f, 0.25f);
					glRotatef(180.0, 0.0, 1.0, 0.0);
					gluCylinder(quad, 1.6f, 0.1f, 1.5f, segments, segments);
				glPopMatrix();

				// Left anchor base
				glPushMatrix();
					glTranslatef(0.0f,0.0f, 1.0f);
					glRotatef(-70.0, 0.0, 1.0, 0.0);
					gluCylinder(quad, 1.5f, 1.5f, 11.0, segments, segments);
				glPopMatrix();

				// Right anchor base
				glPushMatrix();
					glTranslatef(0.0f,0.0f, 1.0f);
					glRotatef(70.0, 0.0, 1.0, 0.0);
					gluCylinder(quad, 1.5f, 1.5f, 11.0, segments, segments);
				glPopMatrix();

				// Right Anchor Tip
				glPushMatrix();
					glTranslatef(15.0f,0.0f, 0.0f);
					glRotatef(70.0, 0.0, 1.0, 0.0);
					glTranslatef(-6.25f,0.0f, -3.0f);
					gluCylinder(quad, 2.0f, 0.1f, 4.0, segments, segments);
				glPopMatrix();

				// Left Anchor Tip
				glPushMatrix();
					glTranslatef(15.0f,0.0f, 10.0f);
					glRotatef(-70.0, 0.0, 1.0, 0.0);
					glTranslatef(-13.5f,0.0f, 22.0f);
					gluCylinder(quad, 2.0f, 0.1f, 4.0, segments, segments);
				glPopMatrix();

				free(quad);


			glPopMatrix();

		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
}
