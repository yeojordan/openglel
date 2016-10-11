
#include "main.h"


const float BOX_SIZE = 7.0f; //The length of each side of the cube
float _angle = 0;            //The rotation of the box
GLuint _textureId;           //The OpenGL id of the texture

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27: //Escape key
			exit(0);
			break;
		// Increase Speed
		case 'F': case 'f':
			speed = (speed < 1) ? speed + 0.01: speed;
			// if (speed < 1.0)
			// {
			// 	speed + 0.01;
			// }
			break;
		// Decrease Speed
		case 'S': case 's':
			speed = (speed >= 0.01) ? speed - 0.01 : speed;
			// if (speed >= 0.01)
			// {
			// 	speed - 0.01;
			// }
			break;
		// Pause Animation
		case 'T': case 't':
			paused = 1;
			break;
		case 'C': case 'c':
			paused = 0;
			break;
		// Zoom In
		case 'Z':
		 	// 0.1 Increments
			if (zoom < 3.0f)
			{
				detail++;
				zoom = zoom + 0.1;
			}
			break;
		// Zoom Out
		case 'z':
			// 0.1 Increments
			if (zoom - 0.1 > 0.1f)
	        {
	        	detail = detail - 1;
				zoom = zoom - 0.1;
			}
			break;
		// Rotate clockwise around y-axis
		case 'Y': case 'y':
			if (rotYSpeed < 0.3f)
			{
				 rotYSpeed + 0.1f;
			}
			if (rotY > 360)
			{
				rotY - 360;
			}
			break;
		// Rotate clockwise around x-axis
		case 'X': case 'x':
			if (rotXSpeed > -0.3f)
			{
				rotXSpeed - 0.1f;
			}
			break;
		// Flat Shaded Polygonization
		case 'p':
			glShadeModel (GL_FLAT);
			break;
		// Smooth Shaded Polygonization
		case 'P':
			glShadeModel (GL_SMOOTH);
			break;
		// Start animation
		case 'A': case 'a':
			paused = 0;
			if (speed < 0.01)
			{
				 speed + 0.01;
			}
			break;
	}
}

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGB,
				 image->width, image->height,
				 0,
				 GL_RGB,
				 GL_UNSIGNED_BYTE,
				 image->pixels);
	return textureId;
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	Image* image = loadBMP("vtr.bmp");
	_textureId = loadTexture(image);
	delete image;
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, -10.0f, -80.0f);

	GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);


	glPushMatrix();
	glScalef(zoom,zoom,zoom);
	glRotatef(rotY,0.0f,1.0f,0.0f); //rotate about y
	glRotatef(rotX,1.0f,0.0f,0.0f); //rotate about x



		// Base (Floor) Plane
		glPushMatrix();
			glColor3f(255.0f/540.0f, 184.0f/540.0f, 77.0f/540.0f);
			glScalef(40.0f, 0.1f ,  40.0f);
			glTranslatef(0.0f, -60.0f,0.0f  );
			glutSolidCube(2.0f);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-_angle, 1.0f, 1.0f, 0.0f);
			anchor(detail);
		glPopMatrix();

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







	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	rotX+=rotXSpeed;
	rotY+=rotYSpeed;

	glutSwapBuffers();

	glutPostRedisplay();
}

//Called every 25 milliseconds
void update(int value) {
	_angle += 1.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);

	glutCreateWindow("CG Assignment 2 - 17727626");
	initRendering();

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);

	glutMainLoop();
	return 0;
}
