#include "rock.h"

void rock(int segments)
{
    GLUquadric* quad = gluNewQuadric();

    // Enabling rock texture 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, TEX_ROCK);

    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        gluQuadricTexture(quad, true);
        glTranslatef(0.0f, -6.0f, -0.0f);
        glColor3f(1.0,1.0,1.0);

        // "Random" placement of rocks
        for (int i = 0; i <= 13; i++)
        {
            glPushMatrix();
                glScalef(1.0,0.75,1.0);
                gluSphere(quad,  2.5f,  6, segments);
            glPopMatrix();
            // "Randomising" placement
            if( i % 2 == 0)
            {
                glTranslatef((double)(i%4), 0.0, (double)(i%2));
            }
            else
            {
                glTranslatef((double)(i%2), 0.0, -(double)(i%4));
            }
            glRotatef(35,0.0,1.0,0.0);

        }

        glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}
