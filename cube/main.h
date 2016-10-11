#include <iostream>
#include <stdlib.h>

#include "imageloader.h"
#include "anchor.h"

#include "gl.h"


using namespace std;

#define CUBE_SIZE 100
//#define detail 13


GLfloat speed = 0.0;
GLfloat hour;
// GLfloat minute;
// GLfloat discoRot;


//CAMERA ROTATIONS
GLfloat rotY;
GLfloat rotYSpeed;
GLfloat rotX;
GLfloat rotXSpeed;
GLfloat zoom = 0.1;


int paused = 1;
GLfloat detail = 13.0;
