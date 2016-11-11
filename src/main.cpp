/********************************************************************
Modeling of environment:
	3 simple objects				: base plane (disk),
									,bubbles
	3 composite objects 			: cage, chain, mast, wheel
Lighting
	2 light sources					: ambient, positioned x2
Textures
	3 different surface finishes	: GL_COLOR_MATERIAL  on base, wheel, cage
									  GL_TEXTURE_2D on all bmp textured objects
Zoom
	Level-of-details implementation	:changes based on scale
Animation
	Reasonable and smooth animation : export can dis/apearing,
									clock hands,
									disco ball
	Complexity of animation 		: clock hands render actual
									position when passed hr and min
Key Input
	Correct Zoom in/out <Z/z>		 : handleKeypress()
	Correct rotation of scene X/Y 	 : handleKeypress()
	Correct function of of remaining : handleKeypress()
Misc
	Display key func in window 		: printText()
	Quality and reasonable setting 	: sure
		of objects
	Texture on objects				 : wood.bmp, metal.bmp, rock.bmp,
	Other effects - transparency, fog: bubbles are transluscent


****************************************************************************/
#include "main.h"


const float BOX_SIZE = 7.0f; //The length of each side of the cube
float _angle = 0;            //The rotation of the box


void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27: //Escape key
			exit(0);
			break;
		// Increase Speed
		case 'F': case 'f':
			if (speed < 1.0 && !paused)
			{
				speed += 0.1;
			}
			break;
		// Decrease Speed
		case 'S': case 's':
			if (speed >= 0.1 && !paused)
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
		case 'Y':
			yRot = true;
			if (rotYSpeed < 0.3f)
			{
				rotYSpeed += 0.5f;
			}
			break;
		case 'y':
			if (yRot == true)
			{
				yRot = false;
				rotYSpeed = 0.0f;
			}
			break;
		// Rotate clockwise around x-axis
		case 'X':
			xRot = true;
			if (rotXSpeed > -0.3f )
			{
				rotXSpeed += 0.5f;
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

void GLPrint(const char* text, float x, float y)
{

	int i;
	int length = strlen(text);

	glColor3f(1.0,1.0,1.0);
	glRasterPos3f(x,y,-10.0f);
	glPushMatrix();

	//one char at a time
	for(i=0; i < length; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}
	glPopMatrix();
}

void printText()
{
    glDisable(GL_LIGHTING);

//	glTranslatef(-10.0,0.0,0.0);
	glPushMatrix();

	    glRotatef(0.5f,1.0f,0.0f,0.0f);

		glTranslatef(0.0,5.0,0.0);
		GLPrint("Input:",-22.0,12.0);
		GLPrint("<Z>/<z> : Zooms in/out",-22.0,11.0);
		GLPrint("<X>/<x> : X-axis rotation clockwise/Pause Rotation",-22.0,10.0);
		GLPrint("<Y>/<y> : Y-axis rotation clockwise/Pause Rotation",-22.25,9.0);
		GLPrint("<p>/<P> : Turn on Flat/Smooth Shading",-22.25,8.0);
		GLPrint("<a>/<A> : Start animation",-22.25,7.0);
		GLPrint("<t>/<T> : Pause animation",-22.25,6.0);
		GLPrint("<c>/<C> : Resume Animation",-22.25,5.0);
		GLPrint("<s>/<S> : Slow down Animation",-22.25,4.0);
		GLPrint("<f>/<F> : Speed up Animation",-22.25,3.0);
		GLPrint("<Esc> : Quit the program",-22.5,2.0);

    glPopMatrix();
    glEnable(GL_LIGHTING);
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

}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_FOG);


	glEnable(GL_BLEND); //Enable alpha blending
 	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set the blend function

	// Set background colour
	glClearColor(53.0f/410.0f, 129.0f/410.0f, 228.0f/410.0f, 0.15f);
	// Image* image = loadBMP("vtr.bmp");
	Image* image1 = loadBMP("textures/rock.bmp");
	Image* image2 = loadBMP("textures/wood.bmp");
	Image* image3 = loadBMP("textures/metal.bmp");

	loadTexture(image1);
	loadTexture(image2);
	loadTexture(image3);
	delete image1;
	delete image2;
	delete image3;
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}




void drawScene()
{
	// Fog
	GLfloat fogColor[4] = {53.0f/410.0f, 129.0f/410.0f, 228.0f/410.0f, 0.5f};
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_START, 25.0f);
	glFogf(GL_FOG_END, 40.0f);
	glFogf(GL_FOG_DENSITY, 0.8f);


	//Add green directed light
    GLfloat lightColor1[] = {0.0f, 1.0f, 0.0f, 1.0f};
    GLfloat lightPos1[] = {0.0f, 150.0f, 50.0f, 1.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);



	//Add red directed light
	GLfloat lightColor2[] = {1.0f, 0.0f, 0.0f, 0.50f};
	GLfloat lightPos2[] = {100.0f, 0.0f, 50.0f, 1.0f};
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, lightColor2);
	glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);

	glPushMatrix();



	glScalef(zoom,zoom,zoom);
	glRotatef(rotY,0.0f,1.0f,0.0f); //rotate about y
	glRotatef(rotX,1.0f,0.0f,0.0f); //rotate about x


		// Base (Floor) Plane
		glPushMatrix();
			glColor3f(246.0f/503.0f, 187.0f/503.0f, 70.0f/503.0f);
			glTranslatef(0.0f, -10.0f,0.0f  );


			// Surface Finish for Base Plane
		glDisable(GL_COLOR_MATERIAL);
			float mat_ambient[]  ={ 0.24725f, 0.1995f, 0.0745f, 1.0f };
			float mat_diffuse[]  ={0.75164f, 0.60648f, 0.22648f, 1.0f };
			float mat_specular[] ={0.628281f, 0.555802f, 0.366065f, 1.0f };
			float shine =11.2f ;


		    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		    glMaterialf(GL_FRONT, GL_SHININESS, shine);


			glRotatef(90.0,1.0,0.0,0.0);
			GLUquadric* quad = gluNewQuadric();
			gluDisk(quad,0.01,  4000.0, detail, detail);

		glEnable(GL_COLOR_MATERIAL);

		glPopMatrix();

	// Anchor setup
	glPushMatrix();
		glScalef(2.0,2.0,2.0);
		// Rock for Anchor
		glPushMatrix();
			glScalef(5.0,7.0,4.0);
			glRotatef(90.0,0.0,1.0,0.0);
			glTranslatef(7.5,5.0,12.0);
			rock(detail);
		glPopMatrix();


		// Anchor
		glPushMatrix();
			//glScalef(2.0,2.0,2.0);
			glTranslatef(50.0f, 0.0f, 0.0f);
			glRotatef(-45.0, 1.0f, 0.0f, 0.0f);
			anchor(detail);
		glPopMatrix();
	glPopMatrix();

		// Draw x,y,z axis
		//axis();


		//Draw Wheel
		glPushMatrix();
			glScalef(1.5,1.5,1.5);
			wheel(wheelSpd, detail);
		glPopMatrix();

		// Rocks
		glPushMatrix();
			glTranslatef(-100.0f, 20.0f, 0.0f);
			glPushMatrix();
				glScalef(10.0,10.0,10.0);
				glTranslatef(0.0f, 3.0f, 0.0f);
				rock(detail);
			glPopMatrix();

			glRotatef(-35.0, 0.0f, 1.0f, 1.0f);
			mast(detail);

		glPopMatrix();

		// Draw Cage
		glPushMatrix();
			glTranslatef(0.0f, 40.0f, -120.0f);
			cage(cageSpd, detail);
		glPopMatrix();

		// Draw Bubbles
		glPushMatrix();
			bubbles(cageSpd, detail);
		glPopMatrix();

	glDisable(GL_TEXTURE_2D);

		glPopMatrix();

	// Alter rotation speed
	rotX+=rotXSpeed;
	rotY+=rotYSpeed;

	// Change rotation speed
	if(!paused)
	{
		wheelSpd += 0.5*speed;
		cageSpd+=speed;
	}


}


void display()
{
	// Initialise scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Initial camera position
	glTranslatef(0.0f, -1.0f, -20.0f);

	// Ambient Lighting for scene
	GLfloat ambientLight[] = {0.3f, 0.3f, 0.3f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glTranslatef(0.0f, 0.0f, -10.0f);

	gluLookAt (0.0, 1.0, 7.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//camera

	// Draw objects
	drawScene();

	// Display text
	printText();

	// Reset
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
	glutInitWindowSize(1000, 800);

	glutCreateWindow("CG Assignment 2 - 17727626");
	initRendering();

	glutDisplayFunc(display);

	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);

	glutMainLoop();
	return 0;
}
