#include "rock.h"

void rock(int segments)
{
    GLUquadric* quad = gluNewQuadric();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 1);

    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        gluQuadricTexture(quad, true);
        // glTranslatef(-10.0f, 0.0f, 18.0f);
        glColor3f(1.0,1.0,1.0);
        gluSphere(quad,  2.5f,  30, segments);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}
