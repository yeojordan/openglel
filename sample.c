#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

/*
 *	Define macros for commonly used numerical values
 *
 *	CUBE_SIZE:		Half the length of the cubes sides
 *	WINDOW_WIDTH:	The width of the window in pixels
 *	WINDOW_HEIGHT:	The height of the window in pixels
 */
#define	CUBE_SIZE     1.0
#define WINDOW_WIDTH  400
#define WINDOW_HEIGHT 400

/*
 *	Define global variables to be used by the program
 *
 *	scale:	a factor to scale the viewed cube by
 *	alpha:	number of degrees by which the cube is rotated
 *	beta:	number of degrees by which the cube is tilted
 *	inc:	amount to increase alpha for every frame of animation
 */
float scale, alpha, beta;
int   inc;


/*--------------------------------------------------*
 * void init()                                      *
 * This function is called once at the beginning of *
 * program execution allowing initialisation of     *
 * variables etc.                                   *
 *--------------------------------------------------*/
void init()
{
	/* set the background colour and enable depth
	 * testing  */
	glClearColor((float) 0.3, (float) 0.0, (float) 0.5, (float) 0.0);
	glEnable(GL_DEPTH_TEST);

	/* set initial rotation and scale values  */
	alpha = -(float) 20.0;
	beta  =  (float) 20.0;
	scale =  (float) 1.0;

	inc = 1;
}

/*--------------------------------------------------*
 * void draw()                                      *
 * This function defines the objects to be drawn.   *
 * For wireframe drawing only polylines and lines   *
 * are used. If you decided to draw shaded polygons *
 * do not forget to define materials and lights in  *
 * init()                                           *
 *--------------------------------------------------*/
void draw()
{
	/* set the colour to red and draw the coordinate
	 * axes. GL_LINES defines segments of straight
	 * lines connecting vertices v1 with v2, v3 with
	 * v4, v5 with v6, etc.  */
    glColor3f((float) 1.0, (float) 0.0, (float) 0.0);
	glBegin(GL_LINES);
		glVertex3f(-(float)(2.0*CUBE_SIZE), (float) 0, (float) 0);
		glVertex3f( (float)(2.0*CUBE_SIZE), (float) 0, (float) 0);
		glVertex3f( (float) 0,-(float)(2.0*CUBE_SIZE), (float) 0);
		glVertex3f( (float) 0, (float)(2.0*CUBE_SIZE), (float) 0);
		glVertex3f( (float) 0, (float) 0,-(float)(2.0*CUBE_SIZE));
		glVertex3f( (float) 0, (float) 0, (float)(2.0*CUBE_SIZE));
	glEnd();

	/* set the colour to green and draw a cube - one
	 * polyline and three segments. GL_LINE_STRIP
	 * defines a polyline connecting vertices v1, v2,
	 * v3,...,vn. It can be done in for {...} as
	 * well.  */
    glColor3f((float) 0.0, (float) 1.0, (float) 0.0);
	glBegin(GL_LINE_STRIP);
		glVertex3f(-(float)CUBE_SIZE, -(float)CUBE_SIZE, -(float)CUBE_SIZE);
		glVertex3f( (float)CUBE_SIZE, -(float)CUBE_SIZE, -(float)CUBE_SIZE);
		glVertex3f( (float)CUBE_SIZE, -(float)CUBE_SIZE,  (float)CUBE_SIZE);
		glVertex3f(-(float)CUBE_SIZE, -(float)CUBE_SIZE,  (float)CUBE_SIZE);
		glVertex3f(-(float)CUBE_SIZE, -(float)CUBE_SIZE, -(float)CUBE_SIZE);
		glVertex3f(-(float)CUBE_SIZE,  (float)CUBE_SIZE, -(float)CUBE_SIZE);
		glVertex3f( (float)CUBE_SIZE,  (float)CUBE_SIZE, -(float)CUBE_SIZE);
		glVertex3f( (float)CUBE_SIZE,  (float)CUBE_SIZE,  (float)CUBE_SIZE);
		glVertex3f(-(float)CUBE_SIZE,  (float)CUBE_SIZE,  (float)CUBE_SIZE);
		glVertex3f(-(float)CUBE_SIZE,  (float)CUBE_SIZE, -(float)CUBE_SIZE);
    glEnd();

	/* GL_LINES defines segments of straight lines
	 * connecting vertices v1 with v2, v3 with v4,
	 * v5 with v6, etc.  */
	glBegin(GL_LINES);
		glVertex3f( (float)CUBE_SIZE, -(float)CUBE_SIZE, -(float)CUBE_SIZE);
		glVertex3f( (float)CUBE_SIZE,  (float)CUBE_SIZE, -(float)CUBE_SIZE);
		glVertex3f( (float)CUBE_SIZE, -(float)CUBE_SIZE,  (float)CUBE_SIZE);
		glVertex3f( (float)CUBE_SIZE,  (float)CUBE_SIZE,  (float)CUBE_SIZE);
		glVertex3f(-(float)CUBE_SIZE, -(float)CUBE_SIZE,  (float)CUBE_SIZE);
		glVertex3f(-(float)CUBE_SIZE,  (float)CUBE_SIZE,  (float)CUBE_SIZE);
	glEnd();
}

/*--------------------------------------------------*
 * void display(void)                               *
 * This function is called by the system to draw    *
 * every next buffer.                               *
 *--------------------------------------------------*/
void display(void)
{
	/* clear the buffer of all data  */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
		/* increase the amount of rotation for the
	     * visualisation transformation  */
		alpha = alpha + (float) inc;

		/* reset the rotation angle when it reaches
		 * 360 degrees  */
		if(alpha  >  (float) 360.0)
			alpha -= (float) 360.0;

		/* translation and rotation transformations
		 * that specify the overall visualisation
		 * transformation. Changing the value of
		 * scale would introduce a scaling
		 * transformation  */
		glTranslatef((float) 0.0, (float) 0.0, -(float) (5.0 * CUBE_SIZE));
		glRotatef(beta , (float) 1.0, (float) 0.0, (float) 0.0);
		glRotatef(alpha, (float) 0.0, (float) 1.0, (float) 0.0);
		glScalef(scale, scale, scale);

		draw();
	glPopMatrix();

	/* force the scene to draw and swap the
	 * buffers for smooth animation  */
	glFlush();
	glutSwapBuffers();
}

/*--------------------------------------------------*
 * void reshape(int width, int height)              *
 * In this function the projection transformation   *
 * is defined. Currently it is a perspective        *
 * projection, but it could be an orthographic      *
 * projection should you use the commented glOrtho  *
 * instead of glFrustum.                            *
 *--------------------------------------------------*/
void reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	/*glOrtho(-(float) 2.0*CUBE_SIZE, (float) 2.0*CUBE_SIZE, -(float) 2.0*CUBE_SIZE,
	           (float) 2.0*CUBE_SIZE, (float) 0.0*CUBE_SIZE,  (float)10.0*CUBE_SIZE);*/
	glFrustum(-(float) 2.0*CUBE_SIZE, (float) 2.0*CUBE_SIZE, -(float) 2.0*CUBE_SIZE,
			   (float) 2.0*CUBE_SIZE, (float) 3.0*CUBE_SIZE,  (float)40.0*CUBE_SIZE);

	glMatrixMode(GL_MODELVIEW);
}

/*--------------------------------------------------*
 * void input(unsigned char key, int x, int y)      *
 * A callback function for when the user presses a  *
 * key. Pressing the 'r' key will either stop or    *
 * start the rotation of the drawn object.          *
 *--------------------------------------------------*/
void input(unsigned char key, int x, int y)
{
	/* do nothing unless the user has pressed the
	 * 's' key  */
	if(key == 's')
	{
		/* if the rotation has stopped then restart
		 * it otherwise stop the rotation  */
		if(inc == 1)
			inc = 0;
		else
			inc = 1;
	}
}

/*--------------------------------------------------*
 * void idle(void)                                  *
 * A callback function run whenever the system has  *
 * spare resources. Request that the screen be      *
 * redrawn so that the application has the highest  *
 * fps as possible.                                 *
 *--------------------------------------------------*/
void idle(void)
{
	glutPostRedisplay();
}

/*--------------------------------------------------*
 * int main(int argc, char **argv)                  *
 * The main function initialises a window and gives *
 * it the specified properties. The program is      *
 * initialised and callback functions attached      *
 * before entering the glutMainLoop.                *
 *--------------------------------------------------*/
int main(int argc, char **argv)
{
	/* initialise glut and a window  */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(100, 100);

	/* create a window and initialise the program  */
	glutCreateWindow("CG252 Sample Program");
	init();

	/* set callback functions  */
	glutDisplayFunc (display);
	glutReshapeFunc (reshape);
	glutKeyboardFunc(input);
	glutIdleFunc    (idle);

	glutMainLoop();
	return 0;
}
