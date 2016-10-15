#include <iostream>
#include <stdlib.h>

#include "imageloader.h"
#include "anchor.h"
#include "axis.h"
#include "wheel.h"
#include "gl.h"
#include "solidCylinder.h"
#include "mast.h"
#include "cage.h"
#include "rock.h"


using namespace std;


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

// bool paused = true;
int paused = 1;
GLfloat detail = 13.0;

bool xRot = false;
bool yRot = false;
/*
    Objects to Create:
        - [x] Anchor
        - [x] Mast
        - [ ] Tombstone
        - [x] Pirate Ship Wheel
        - [x] Shark Cage
        - [ ]
*/
