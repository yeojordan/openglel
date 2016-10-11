#include "main.h"

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27: //Escape key
			exit(0);
			break;
		// Increase Speed
		case 'F': case 'f':
			break;
		// Decrease Speed
		case 'S': case 's':
			break;
		// Pause Animation
		case 'T': case 't':
			break;
		// Zoom In
		case 'Z':
		 	// 0.1 Increments
			break;
		// Zoom Out
		case 'z':
			// 0.1 Increments
			break;
		// Rotate clockwise around y-axis
		case 'Y': case 'y':
			break;
		// Rotate clockwise around x-axis
		case 'X': case 'x':
			break;
		// Flat Shaded Polygonization
		case 'p':
			break;
		// Smooth Shaded Polygonization
		case 'P':
			break;
		// Start animation
		case 'A': case 'a':
			break;
	}
}


//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

GLuint _textureId; //The id of the texture

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

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glTranslatef(0.0f, 1.0f, -6.0f);

	GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	GLfloat directedLight[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat directedLightPos[] = {-10.0f, 15.0f, 20.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, directedLight);
	glLightfv(GL_LIGHT0, GL_POSITION, directedLightPos);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	//Bottom
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 0.2f, 0.2f);








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


	glutSwapBuffers();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("CG Assignment 2 - 17727626");
	initRendering();

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop();
	return 0;
}
