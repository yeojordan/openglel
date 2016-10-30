#include "chain.h"

void drawChain( int links, int segments, double x, double y, double z )
{
    glPushMatrix();
        // Number of links in the chain
        for ( int i = 0; i < links; i++ )
        {
            glPushMatrix();
                // Move the link up
                glTranslatef( x, ( y + 5.0f * (double)i ), z );
                glScalef( 0.35f, 1.0f, 0.35f );
                // Rotate every second link
                if ( i % 2 == 0 )
                {
                    glRotatef( 80.0f, 0.0f, 1.0f, 0.0f );
                }
                glutSolidTorus( 1.2f, 3.0f, segments, segments);

            glPopMatrix();
        }

    glPopMatrix();
}
