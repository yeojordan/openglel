#include "rock.h"

void rock(int segments)
{
    GLUquadric* quad = gluNewQuadric();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 1);

    glPushMatrix();
        // glTranslatef(-10.0f, 0.0f, 18.0f);
        gluSphere(quad,  2.5f,  30, segments);
    glPopMatrix();

}
