#include "axis.h"

void axis()
{
    // Lines to show the 3 axis on the screen for reference
	glBegin(GL_LINES);
	// X LINE IS RED
	glColor3f( 1.0, 0.0, 0.0 );
	glVertex3f( -(2.0*CUBE_SIZE), 0, 0);
	glVertex3f(  (2.0*CUBE_SIZE), 0, 0);
	// Y LINE IS GREEN
	glColor3f( 0.0, 1.0, 0.0 );
	glVertex3f( 0, -(2.0*CUBE_SIZE), 0);
	glVertex3f( 0,  (2.0*CUBE_SIZE), 0);
	// Z LINE IS BLUE
	glColor3f( 0.0, 0.0, 1.0 );
	glVertex3f( 0, 0, -(2.0*CUBE_SIZE));
	glVertex3f( 0, 0,  (2.0*CUBE_SIZE));
	glEnd();
}
