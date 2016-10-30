#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#ifdef __linux__
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdlib.h>

#include "colours.h"

#define TAU (6.283185308)
#define ZOOM (0.1)

#define TEX_ROCK	1
#define TEX_WOOD	2


//#define detail 13
#define CUBE_SIZE 100

#define ALPHA 0.95

#define TEX_ROCK 1
