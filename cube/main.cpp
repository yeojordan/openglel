
#include "main.h"


const float BOX_SIZE = 7.0f; //The length of each side of the cube
float _angle = 0;            //The rotation of the box
GLuint tex_1;           //The OpenGL id of the texture

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27: //Escape key
			exit(0);
			break;
		// Increase Speed
		case 'F': case 'f':
			if (speed < 1.0)
			{
				speed += 0.1;
			}
			break;
		// Decrease Speed
		case 'S': case 's':
			if (speed >= 0.1)
			{
				speed -= 0.1;
			}
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
			if (zoom - 0.1 > 0.01f)
	        {
	        	detail = detail - 1;
				zoom = zoom - 0.1;
			}
			break;
		// Rotate clockwise around y-axis
		case 'Y': //case 'y':
			yRot = true;
			if (rotYSpeed < 0.3f)
			{
				rotYSpeed += 0.5f;
			}
			// if (rotY > 360)
			// {
			// 	rotY -= 360;
			// }
			break;
		case 'y':
			if (yRot == true)
			{
				yRot = false;
				rotYSpeed = 0.0f;
			}
			break;
		// Rotate clockwise around x-axis
		case 'X':// case 'x':
			xRot = true;
			if (rotXSpeed > -0.3f )
			{
				rotXSpeed -= 0.5f;
			}
			break;
		case 'x':
			if ( xRot == true)
			{
				xRot = false;
				rotXSpeed = 0.0f;
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
				 speed += 0.01;
			}
			break;


	}
}

//Makes the image into a texture, and returns the id of the texture
void loadTexture(Image* image) {
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
	//return textureId;
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	// Set background colour
	glClearColor(0.0f, 0.1f, 0.3f, 0.5f);
	// Image* image = loadBMP("vtr.bmp");
	Image* image1 = loadBMP("textures/rock.bmp");
	Image* image2 = loadBMP("textures/wood.bmp");

	loadTexture(image1);
	loadTexture(image2);
	delete image1;
	delete image2;
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

	// Initial camera position
	glTranslatef(0.0f, -1.0f, -20.0f);

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
			glScalef(400.0f, 0.1f , 400.0f);
			glTranslatef(0.0f, -60.0f,0.0f  );
			glutSolidCube(2.0f);
		glPopMatrix();

		// Anchor
		glPushMatrix();
			//glScalef(2.0,2.0,2.0);
			glTranslatef(50.0f, 0.0f, 0.0f);
			glRotatef(-45.0, 0.0f, 1.0f, 1.0f);
			anchor(detail);
		glPopMatrix();

		// Draw x,y,z axis
		axis();

		//Draw Wheel
		// glPushMatrix();
		// 	glTranslatef(50.0f, 0.0f, 0.0f);
		// 	wheel(detail);
		// glPopMatrix();

		glPushMatrix();
			glScalef(0.5, 0.5, 0.5);
			glTranslatef(-50.0f, 20.0f, 0.0f);
			glRotatef(-35.0, 0.0f, 0.0f, 1.0f);
			mast(detail);
		glPopMatrix();

		glPushMatrix();
			glScalef(0.5, 0.5, 0.5);
			glTranslatef(0.0f, 30.0f, -80.0f);
			cage(detail);
		glPopMatrix();

		// glPushMatrix();
		// 	rock(detail);
		// glPopMatrix();

		glPushMatrix();
			drawChain(10, 0.0,0.0,0.0);
		glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	rotX+=rotXSpeed;
	rotY+=rotYSpeed;

	glutSwapBuffers();

	glutPostRedisplay();
}

//Called every 25 milliseconds
void update(int value) {
	_angle += speed;
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
