
#include <iostream>
#include <GL/glut.h>
#include "glm.h"	// find in /tutors
// #include "glm.h"
void basicRoom ();
using namespace std;

#define ONE_BY_ROOT_THREE 0.57735
void mymenu (int);
int wireframe = 0;  // toggle for wire-frame
int depthbuff = 0;  // toggle for depth buffer
int fog       = 0;  // toggle fog
float xPos = 0.0;   // x position of camera
float yPos = 0.0;   // y position of camera
float zPos = 5.0;   // distance the center of projection from frustum
static float d = 0.0; // Length of normal.
unsigned char* image = NULL;   // store data of texture map
int texWidth;
int texHeight;
int isSmooth = 1;
int ptlt = 0;
GLdouble  modelview[1], inverse[1];
GLboolean world_draw = GL_TRUE;
GLMmodel* pmodel = NULL;
GLMmodel* pmodel1 = NULL;
int texture = 1;    // toggle for texture
static unsigned int textureArray[1];
void display ()
{
   // C  DEPTH is for hidden-surface removal
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity ();

   // Change position of camera in x, y, and z
   //
   // Note this is NOT the same as rotating an object in position!
   // The camera is moving to the current xPos, yPos, zPos position,
   // which means that, for example, if you move to the right in x,
   // you will move FARTHER away in z, so the object gets smaller
   // as the camera rotates (think about this).
   gluLookAt (0.0, 0.0, zPos, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   glRotatef(xPos, 1.0, 0.0, 0.0);
   glRotatef(yPos, 0.0, 1.0, 0.0);
   // draw solid object
   int texture = 1;    // toggle for texture
   basicRoom ();

   glFlush ();
}
// float normalize(float* v)
// {
//     float length;
    
//     length = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
//     v[0] /= length;
//     v[1] /= length;
//     v[2] /= length;
    
//     return length;
// }
void drawmodel(void)
{
	glDisable (GL_TEXTURE_2D);
	glColor3f (1.0, 1.0, 1.0);
    if (!pmodel) {
        pmodel = glmReadOBJ("chippchair.obj");
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 10.0);
    }
    glRotatef(90, 0,0,1);
    glScalef(0.4, 0.4, 0.4);
    glTranslatef(-0.87, -1.5, 0.0);
    if(isSmooth == 1){
    	glmDraw(pmodel, GLM_SMOOTH);
    }
    else{
    	glmDraw(pmodel, GLM_FLAT);
    }
    
    glRotatef(90, 1,0,0);
    glTranslatef(0.0, -1.5, -1.5);
    
    if(isSmooth == 1){
    	glmDraw(pmodel, GLM_SMOOTH);
    }
    else{
    	glmDraw(pmodel, GLM_FLAT);
    }
    glRotatef(90, 1,0,0);
    glTranslatef(0.0, -1.5, -1.5);
    
    if(isSmooth == 1){
    	glmDraw(pmodel, GLM_SMOOTH);
    }
    else{
    	glmDraw(pmodel, GLM_FLAT);
    }
    glRotatef(90, 1,0,0);
    glTranslatef(0.0, -1.5, -1.5);
    
    
    if(isSmooth == 1){
    	glmDraw(pmodel, GLM_SMOOTH);
    }
    else{
    	glmDraw(pmodel, GLM_FLAT);
    }
    
}
void drawmodel1(void)
{
	glDisable (GL_TEXTURE_2D);
	glColor3f (1.0, 0.0, 0.0);
    if (!pmodel1) {
        pmodel1 = glmReadOBJ("porsche.obj");
        if (!pmodel1) exit(0);
        glmUnitize(pmodel1);
        glmFacetNormals(pmodel1);
        glmVertexNormals(pmodel1, 10.0);      
    }
    glRotatef(270, 0,0,1)                                                                                                                              ;
    // glScalef(1.0, 1.0, 1.0);
    glTranslatef(1.3, -0.58, 1.0);
    
    if(isSmooth == 1){
    	glmDraw(pmodel1, GLM_SMOOTH);
    }
    else{
    	glmDraw(pmodel1, GLM_FLAT);
    }
}
// void screen_menu(int value)
// {
//     char* name = 0;
//     char* name1 = 0;
//     name = "chippchair.obj";    
//     if (name) {
//         pmodel = glmReadOBJ(name);
//         if (!pmodel) exit(0);
//         glmUnitize(pmodel);
//         glmFacetNormals(pmodel);
//         glmVertexNormals(pmodel, 90.0);
//     }
//     // glFlush ();
//     name1 = "porsche.obj";    
//     if (name1) {
//         pmodel1 = glmReadOBJ(name1);
//         if (!pmodel1) exit(0);
//         glmUnitize(pmodel1);
//         glmFacetNormals(pmodel1);
//         glmVertexNormals(pmodel1, 90.0);
//     }
//     // glFlush ();
// }
void basicRoom ()
{
	GLfloat light_pos[] = { 0.0, 0.0, 1.0, 0.0 };
	double length;
    length = 3;
    float radius = 0.3;
    float halfLength = 1.0;
	int slices = 360;
    // invert(modelview, inverse);
   float Xr = 1.5;	// right x
   float Xl = -1.5;	// left x
   float Yt = 1.0;	// top y
   float Yb = -1.0;	// bottom y
   float Zf = 1.5;	// front z
   float Zb = -1.5;	// back z
   float tableX1 = -0.5;
   float tableX2 = -0.05;
   float tableX3 = 0.05;
   float tableX4 = 0.5;
   float tableX5 = -0.7;
   float tableX6 = 0.7;
   float tableZ1 = -0.5;
   float tableZ2 = -0.05;
   float tableZ3 = 0.05;
   float tableZ4 = 0.5;
   float tableZ5 = -0.7;
   float tableZ6 = 0.7;
   float tableY1 = -1.0;
   float tableY2 = -0.9;
   float tableY3 = -0.5;
   float tableY4 = -0.4;
   float tableY5 = -0.1;

   glClear(GL_COLOR_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_COLOR_MATERIAL); 
  	
   glColor3f (0.34, 0.98, 1.0);
   glBegin (GL_POLYGON);			//left side

      glNormal3f(1.0, 0.0, 0.0);
      glVertex3f (Xl, Yt, Zf);
      glVertex3f (Xl, Yb, Zf);
      glVertex3f (Xl, Yb, Zb);
      glVertex3f (Xl, Yt, Zb);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xl-0.05, Yt, Zb);
      glVertex3f (Xl-0.05, Yb, Zb);
      glVertex3f (Xl-0.05, Yb, Zf);
      glVertex3f (Xl-0.05, Yt, Zf);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xl-0.05, Yb, Zf);
      glVertex3f (Xl, Yb, Zf);
      glVertex3f (Xl, Yt, Zf);
      glVertex3f (Xl-0.05, Yt, Zf);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xl-0.05, Yt, Zf);
      glVertex3f (Xl, Yt, Zf);
      glVertex3f (Xl, Yt, Zb);
      glVertex3f (Xl-0.05, Yt, Zb);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xl-0.05, Yt, Zb);
      glVertex3f (Xl, Yt, Zb);
      glVertex3f (Xl, Yb, Zb);
      glVertex3f (Xl-0.05, Yb, Zb);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xl-0.05, Yb, Zb);
      glVertex3f (Xl, Yb, Zb);
      glVertex3f (Xl, Yb, Zf);
      glVertex3f (Xl-0.05, Yb, Zf);
   glEnd();
   glBegin (GL_POLYGON);			//back
      glNormal3f(0.0, 0.0, 1.0);
      glVertex3f (Xr, Yt, Zb); 
      glVertex3f (Xl-0.05, Yt, Zb);
      glVertex3f (Xl-0.05, Yb, Zb); 
      glVertex3f (Xr, Yb, Zb); 
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xr, Yb, Zb-0.05); 
      glVertex3f (Xl-0.05, Yb, Zb-0.05);
      glVertex3f (Xl-0.05, Yt, Zb-0.05); 
      glVertex3f (Xr, Yt, Zb-0.05); 
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xl-0.05, Yt, Zb); 
      glVertex3f (Xr, Yt, Zb);
      glVertex3f (Xr, Yt, Zb-0.05); 
      glVertex3f (Xl-0.05, Yt, Zb-0.05); 
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xr, Yt, Zb); 
      glVertex3f (Xr, Yb, Zb);
      glVertex3f (Xr, Yb, Zb-0.05); 
      glVertex3f (Xr, Yt, Zb-0.05); 
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xr, Yb, Zb); 
      glVertex3f (Xl-0.05, Yb, Zb);
      glVertex3f (Xl-0.05, Yb, Zb-0.05); 
      glVertex3f (Xr, Yb, Zb-0.05); 
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xl-0.05, Yb, Zb); 
      glVertex3f (Xl-0.05, Yt, Zb);
      glVertex3f (Xl-0.05, Yt, Zb-0.05); 
      glVertex3f (Xl-0.05, Yb, Zb-0.05); 
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xr, Yb, Zb-0.05); 
      glVertex3f (Xl-0.05, Yb, Zb);
      glVertex3f (Xl-0.05, Yt, Zb); 
      glVertex3f (Xr, Yt, Zb-0.05); 
   glEnd();
   glColor3f (0.67, 0.30, 0.32);
   glBegin (GL_POLYGON);			//bottom
      glNormal3f(0.0, 1.0, 0.0);
      glVertex3f (Xr, Yb, Zf);
      glVertex3f (Xr, Yb, Zb-0.05);
      glVertex3f (Xl-0.05, Yb, Zb-0.05);
      glVertex3f (Xl-0.05, Yb, Zf);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xr, Yb-0.05, Zb-0.05);
      glVertex3f (Xr, Yb-0.05, Zf);
      glVertex3f (Xl-0.05, Yb-0.05, Zf);
      glVertex3f (Xl-0.05, Yb-0.05, Zb-0.05);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xl-0.05, Yb-0.05, Zf);
      glVertex3f (Xr, Yb-0.05, Zf);
      glVertex3f (Xr, Yb, Zf);
      glVertex3f (Xl-0.05, Yb, Zf);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xr, Yb-0.05, Zf);
      glVertex3f (Xr, Yb-0.05, Zb-0.05);
      glVertex3f (Xr, Yb, Zb-0.05);
      glVertex3f (Xr, Yb, Zf);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xr, Yb-0.05, Zb-0.05);
      glVertex3f (Xl-0.05, Yb-0.05, Zb-0.05);
      glVertex3f (Xl-0.05, Yb, Zb-0.05);
      glVertex3f (Xr, Yb, Zb-0.05);
   glEnd();
   glBegin (GL_POLYGON);
      glVertex3f (Xl-0.05, Yb-0.05, Zb-0.05);
      glVertex3f (Xl-0.05, Yb-0.05, Zf);
      glVertex3f (Xl-0.05, Yb, Zf);
      glVertex3f (Xl-0.05, Yb, Zb-0.05);
   glEnd();
   glColor3f (0.0, 0.0, 1.0);
   glBegin (GL_POLYGON);			//base 1
      glNormal3f(0.0, 0.0, -1.0);
      glVertex3f (tableX2, tableY1, tableZ2);
      glVertex3f (tableX1, tableY1, tableZ2);
      glVertex3f (tableX1, tableY2, tableZ2);
      glVertex3f (tableX2, tableY2, tableZ2);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 1.0, 0.0);
      glVertex3f (tableX1, tableY2, tableZ3);
      glVertex3f (tableX2, tableY2, tableZ3);
      glVertex3f (tableX2, tableY2, tableZ2);
      glVertex3f (tableX1, tableY2, tableZ2);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 0.0, 1.0);
      glVertex3f (tableX1, tableY1, tableZ3);
      glVertex3f (tableX2, tableY1, tableZ3);
      glVertex3f (tableX2, tableY2, tableZ3);
      glVertex3f (tableX1, tableY2, tableZ3);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, -1.0, 0.0);
      glVertex3f (tableX2, tableY1, tableZ2);
      glVertex3f (tableX1, tableY1, tableZ2);
      glVertex3f (tableX1, tableY1, tableZ3);
      glVertex3f (tableX2, tableY1, tableZ3);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(-1.0, 0.0, 0.0);
      glVertex3f (tableX1, tableY1, tableZ2); 
      glVertex3f (tableX1, tableY1, tableZ3);
      glVertex3f (tableX1, tableY2, tableZ3); 
      glVertex3f (tableX1, tableY2, tableZ2); 
   glEnd();
   glBegin (GL_POLYGON);			//base2
      glNormal3f(-1.0, 0.0, 0.0);
      glVertex3f (tableX2, tableY1, tableZ3);
      glVertex3f (tableX2, tableY1, tableZ4);
      glVertex3f (tableX2, tableY2, tableZ4);
      glVertex3f (tableX2, tableY2, tableZ3);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 1.0, 0.0);
      glVertex3f (tableX2, tableY2, tableZ3);
      glVertex3f (tableX2, tableY2, tableZ4);
      glVertex3f (tableX3, tableY2, tableZ4);
      glVertex3f (tableX3, tableY2, tableZ3);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(1.0, 0.0, 0.0);
      glVertex3f (tableX3, tableY1, tableZ4);
      glVertex3f (tableX3, tableY1, tableZ3);
      glVertex3f (tableX3, tableY2, tableZ3);
      glVertex3f (tableX3, tableY2, tableZ4);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, -1.0, 0.0);
      glVertex3f (tableX3, tableY1, tableZ4);
      glVertex3f (tableX3, tableY1, tableZ3);
      glVertex3f (tableX2, tableY1, tableZ3);
      glVertex3f (tableX2, tableY1, tableZ4);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 0.0, 1.0);
      glVertex3f (tableX2, tableY1, tableZ4);
      glVertex3f (tableX3, tableY1, tableZ4);
      glVertex3f (tableX3, tableY2, tableZ4);
      glVertex3f (tableX2, tableY2, tableZ4);
   glEnd();
   glBegin (GL_POLYGON);			//base3
      glNormal3f(0.0, 0.0, 1.0);
      glVertex3f (tableX3, tableY1, tableZ3);
      glVertex3f (tableX4, tableY1, tableZ3);
      glVertex3f (tableX4, tableY2, tableZ3);
      glVertex3f (tableX3, tableY2, tableZ3);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 1.0, 0.0);
      glVertex3f (tableX3, tableY2, tableZ2);
      glVertex3f (tableX4, tableY2, tableZ2);
      glVertex3f (tableX4, tableY2, tableZ3);
      glVertex3f (tableX3, tableY2, tableZ3);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 0.0, -1.0);
      glVertex3f (tableX4, tableY1, tableZ2);
      glVertex3f (tableX3, tableY1, tableZ2);
      glVertex3f (tableX3, tableY2, tableZ2);
      glVertex3f (tableX4, tableY2, tableZ2);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, -1.0, 0.0);
      glVertex3f (tableX4, tableY1, tableZ2);
      glVertex3f (tableX3, tableY1, tableZ2);
      glVertex3f (tableX3, tableY1, tableZ3);
      glVertex3f (tableX4, tableY1, tableZ3);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(1.0, 0.0, 0.0);
      glVertex3f (tableX4, tableY1, tableZ3);
      glVertex3f (tableX4, tableY1, tableZ2);
      glVertex3f (tableX4, tableY2, tableZ2);
      glVertex3f (tableX4, tableY2, tableZ3);
   glEnd();
   glBegin (GL_POLYGON);			//base4
      glNormal3f(1.0, 0.0, 0.0);
      glVertex3f (tableX3, tableY1, tableZ2);
      glVertex3f (tableX3, tableY1, tableZ1);
      glVertex3f (tableX3, tableY2, tableZ1);
      glVertex3f (tableX3, tableY2, tableZ2);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 1.0, 0.0);
      glVertex3f (tableX3, tableY2, tableZ2);
      glVertex3f (tableX3, tableY2, tableZ1);
      glVertex3f (tableX2, tableY2, tableZ1);
      glVertex3f (tableX2, tableY2, tableZ2);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(-1.0, 0.0, 0.0);
      glVertex3f (tableX2, tableY1, tableZ1);
      glVertex3f (tableX2, tableY1, tableZ2);
      glVertex3f (tableX2, tableY2, tableZ2);
      glVertex3f (tableX2, tableY2, tableZ1);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, -1.0, 0.0);
      glVertex3f (tableX2, tableY1, tableZ2);
      glVertex3f (tableX2, tableY1, tableZ1);
      glVertex3f (tableX3, tableY1, tableZ1);
      glVertex3f (tableX3, tableY1, tableZ2);
   glEnd();!sem
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 0.0, -1.0);
      glVertex3f (tableX3, tableY1, tableZ1);
      glVertex3f (tableX2, tableY1, tableZ1);
      glVertex3f (tableX2, tableY2, tableZ1);
      glVertex3f (tableX3, tableY2, tableZ1);
   glEnd();
   glColor3f (1.0, 0.0, 0.0);
   glBegin (GL_POLYGON);			//middle
      glNormal3f(0.0, 0.0, 1.0);
      glVertex3f (tableX2, tableY2, tableZ3);
      glVertex3f (tableX3, tableY2, tableZ3);
      glVertex3f (tableX3, tableY3, tableZ3);
      glVertex3f (tableX2, tableY3, tableZ3);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(1.0, 0.0, 0.0);
      glVertex3f (tableX3, tableY2, tableZ3);
      glVertex3f (tableX3, tableY2, tableZ2);
      glVertex3f (tableX3, tableY3, tableZ2);
      glVertex3f (tableX3, tableY3, tableZ3);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 0.0, -1.0);
      glVertex3f (tableX3, tableY2, tableZ2);
      glVertex3f (tableX2, tableY2, tableZ2);
      glVertex3f (tableX2, tableY3, tableZ2);
      glVertex3f (tableX3, tableY3, tableZ2);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(-1.0, 0.0, 0.0);
      glVertex3f (tableX2, tableY2, tableZ2);
      glVertex3f (tableX2, tableY2, tableZ3);
      glVertex3f (tableX2, tableY3, tableZ3);
      glVertex3f (tableX2, tableY3, tableZ2);
   glEnd();
   glColor3f (0.0, 1.0, 0.0);
   glBegin (GL_POLYGON);			//top
      glNormal3f(1.0, 0.0, 0.0);
      glVertex3f (tableX5, tableY3, tableZ6);
      glVertex3f (tableX6, tableY3, tableZ6);
      glVertex3f (tableX6, tableY4, tableZ6);
      glVertex3f (tableX5, tableY4, tableZ6);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 0.0, 1.0);
      glVertex3f (tableX6, tableY3, tableZ6);
      glVertex3f (tableX6, tableY3, tableZ5);
      glVertex3f (tableX6, tableY4, tableZ5);
      glVertex3f (tableX6, tableY4, tableZ6);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(-1.0, 0.0, 0.0);
      glVertex3f (tableX6, tableY3, tableZ5);
      glVertex3f (tableX5, tableY3, tableZ5);
      glVertex3f (tableX5, tableY4, tableZ5);
      glVertex3f (tableX6, tableY4, tableZ5);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 0.0, -1.0);
      glVertex3f (tableX5, tableY3, tableZ5);
      glVertex3f (tableX5, tableY3, tableZ6);
      glVertex3f (tableX5, tableY4, tableZ6);
      glVertex3f (tableX5, tableY4, tableZ5);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 1.0, 0.0);
      glVertex3f (tableX5, tableY4, tableZ6);
      glVertex3f (tableX6, tableY4, tableZ6);
      glVertex3f (tableX6, tableY4, tableZ5);
      glVertex3f (tableX5, tableY4, tableZ5);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, -1.0, 0.0);
      glVertex3f (tableX6, tableY3, tableZ5);
      glVertex3f (tableX5, tableY3, tableZ5);
      glVertex3f (tableX5, tableY3, tableZ6);
      glVertex3f (tableX6, tableY3, tableZ6);
   glEnd();
   glColor3f (0.8, 0.1, 0.0);
   glTranslatef (tableX3, tableY4+0.1, tableZ3);
   glutSolidTeapot (0.1);
   glColor3f (1.0, 1.0, 1.0);
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 0.0, 1.0);
      glVertex3f (tableX2-0.1, tableY5, tableZ2);
      glVertex3f (tableX2, tableY5, tableZ2);
      glVertex3f (tableX2, tableY5+0.1, tableZ2);
      glVertex3f (tableX2-0.1, tableY5+0.1, tableZ2);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(1.0, 0.0, 0.0);
      glVertex3f (tableX2, tableY5, tableZ2);
      glVertex3f (tableX2, tableY5, tableZ2-0.1);
      glVertex3f (tableX2, tableY5+0.1, tableZ2-0.1);
      glVertex3f (tableX2, tableY5+0.1, tableZ2);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 0.0, -1.0);
      glVertex3f (tableX2, tableY5, tableZ2-0.1);
      glVertex3f (tableX2-0.1, tableY5, tableZ2-0.1);
      glVertex3f (tableX2-0.1, tableY5+0.1, tableZ2-0.1);
      glVertex3f (tableX2, tableY5+0.1, tableZ2-0.1);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(-1.0, 0.0, 0.0);
      glVertex3f (tableX2-0.1, tableY5, tableZ2-0.1);
      glVertex3f (tableX2-0.1, tableY5, tableZ2);
      glVertex3f (tableX2-0.1, tableY5+0.1, tableZ2);
      glVertex3f (tableX2-0.1, tableY5+0.1, tableZ2-0.1);
   glEnd();
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 1.0, 0.0);
      glVertex3f (tableX2-0.1, tableY5+0.1, tableZ2);
      glVertex3f (tableX2, tableY5+0.1, tableZ2);
      glVertex3f (tableX2, tableY5+0.1, tableZ2-0.1);
      glVertex3f (tableX2-0.1, tableY5+0.1, tableZ2-0.1);
   glEnd();
   glColor3f (0.67, 0.30, 0.32);
   if (texture)
      glEnable (GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, textureArray[0]);
   glBegin (GL_POLYGON);
      glNormal3f(0.0, 1.0, 0.0);
	  glTexCoord2f (0, 0);
	  glVertex3f (Xl-0.05, tableY1+ 0.303, Zf-0.05);  // lower left
	  glTexCoord2f (1, 0);
	  glVertex3f (Xr-0.05, tableY1+ 0.303, Zf-0.05);  // lower right
	  glTexCoord2f (1, 1);
	  glVertex3f (Xr-0.05, tableY1+ 0.303, Zb-0.05);  // upper right
	  glTexCoord2f (0, 1);
      glVertex3f (Xl-0.05, tableY1+ 0.303, Zb-0.05);  // upper left
	   glEnd();
   if (texture)
      glDisable (GL_TEXTURE_2D);
  glColor3f (1.0, 1.0, 1.0);
   if (world_draw) {
        glEnable(GL_LIGHTING);
        glPushMatrix();
        // glMultMatrixd(inverse);
        glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
        glPopMatrix();
        glColor3f (0.34, 0.98, 1.0);
        drawmodel();
        drawmodel1();
        glDisable(GL_LIGHTING);
        // glPushMatrix();
    
	    // glMultMatrixd(inverse);
	    
	    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	    
	    }
	  
 } // rectSolid ()
 

void init ()
{

   // background color is grey
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST); // Enable depth testing.
   glEnable(GL_LIGHTING);

   // Light property vectors.
   float lightAmb[] = { 0.5, 0.5, 0.5, 1.0 };
   float lightDifAndSpec[] = { 1.0, 1.0, 1.0, 1.0 };

    float shininessmaterial[] = {100.0};  // 0 means entire object;
   if(ptlt == 1){
   	float lightPos1[] = {-0.1, -0.05,-0.1,1};  // From the lamp

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos1);
   }
   float lightPos[] = { 1.5, 1.5, 3.0, 1.0 };
   float globAmb[] = { 0.2, 0.2, 0.2, 1.0 };

   // Light properties.
   glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
   glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
   glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
  
   glEnable(GL_LIGHT0); // Enable particular light source.
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint.
    glMaterialfv (GL_FRONT, GL_AMBIENT, lightAmb);
    glMaterialfv (GL_FRONT, GL_DIFFUSE, lightDifAndSpec);
    glMaterialfv (GL_FRONT, GL_SPECULAR, lightDifAndSpec);
    glMaterialfv (GL_FRONT, GL_SHININESS, shininessmaterial);
   //glEnableClientState(GL_VERTEX_ARRAY);
   //glEnableClientState(GL_NORMAL_ARRAY);

   // Specify locations for the position and normal arrays.
   // glVertexPointer(3, GL_FLOAT, 0, vertices);
   // glNormalPointer(GL_FLOAT, 0, normals);

   // glColor3f(0.0, 0.0, 0.0);
   float matSpec[] = { 1.0, 1.0, 1.0, 1.0 };
   float matShine[] = { 50.0 };

   // Material properties.
   glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
   glMaterialfv(GL_FRONT, GL_SHININESS, matShine);
   glEnable(GL_COLOR_MATERIAL); 
   glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); 

   glGenTextures(3, textureArray);
   char ch[20] = "checker.ppm\0";
   image=glmReadPPM (ch, &texWidth, &texHeight);
   glBindTexture (GL_TEXTURE_2D, textureArray[0]);
   glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexEnvi (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
   glTexImage2D (GL_TEXTURE_2D, 	// target: 2D texture
		   0,			// level = 0 unless multiple resolutions
		   GL_RGB,		// internal image format 
		                        // (see OpenGL text for options)
		   texWidth,		// image width
		   texHeight,		// image height
		   0,			// border width (0 or 1;see OpenGL text)
		   GL_RGB,		// image format (see OpenGL text)
		   GL_UNSIGNED_BYTE,  	// format of data within image file
		   image);		// image file
   // unsigned char* image = NULL;
   // image = glmReadPPM("checker.ppm", &textWidth, &textHeight);
   // B  Start with NO depth test
   char* name = 0;
    char* name1 = 0;
    name = "chippchair.obj";    
    if (name) {
        pmodel = glmReadOBJ(name);
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }
    // glFlush ();
    name1 = "porsche.obj";    
    if (name1) {
        pmodel1 = glmReadOBJ(name1);
        if (!pmodel1) exit(0);
        glmUnitize(pmodel1);
        glmFacetNormals(pmodel1);
        glmVertexNormals(pmodel1, 90.0);
    }
    // glFlush ();
   glDisable (GL_DEPTH_TEST);
}
void reshape (int w, int h)
// Define the viewport and projection
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   // set up matrices for projection coordinate system 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   // Frustum defined as -1 to 1 in x, y and a larger spread in z
   glFrustum (-1, 1, -1, 1, 2.0, 25.0);
   // reset matrices to user's coordinate system
   glMatrixMode (GL_MODELVIEW);
}
void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case '-': zPos = zPos + 0.5;
      			// init();
                break;
      case '+': zPos = zPos - 0.5;
      			// init();
                break;
      case '4': yPos = yPos - 3;
      			// init();
                break;
      case '6': yPos = yPos + 3;
      			// init();
                break;
      case '8': xPos = xPos + 3;
      			// init();
                break;
      case '2': xPos = xPos - 3;
      			// init();
                break;
      case 'q': exit (1);
   }
   glutPostRedisplay ();
}
void initmenu ()
{
   glutCreateMenu (mymenu);
   glutAddMenuEntry ("Menu", 0);
   glutAddMenuEntry ("", 0);
   glutAddMenuEntry ("Toggle Wire-Frame", 1);
   glutAddMenuEntry ("Toggle Smooth/ Flat", 2);
   glutAddMenuEntry ("Toggle light", 3);
   glutAddMenuEntry ("Toggle Fog", 4);
   glutAddMenuEntry ("Toggle Textures", 5);

   glutAddMenuEntry ("Quit", 6);
   glutAttachMenu (GLUT_LEFT_BUTTON);
}
void mymenu (int value)
// Define actions for menu options
{
   switch (value) {
      // toggle wire-frame; do both front- and rear-facing polygons
      case 1 : if (wireframe) {
		  glPolygonMode (GL_FRONT, GL_FILL);
		  glPolygonMode (GL_BACK, GL_FILL);
		  wireframe--;
	       } else {
		  glPolygonMode (GL_FRONT, GL_LINE);
		  glPolygonMode (GL_BACK, GL_LINE);
		  wireframe++;
	       }
	       break;

      // D  Toggle hidden-surface removal (z-buffer test)
      case 2 : if (isSmooth) {
      		isSmooth = 0;
	       } else {
      		isSmooth = 1;
	       }
	       break;
	  case 3 : if (ptlt) {
      		ptlt = 0;
	       } else {
      		ptlt = 1;
	       }
	       break;
      // Toggle rudimentary fog effect
      case 4 : if (fog) {
		  glDisable (GL_FOG);
		  fog--;
	       } else {
		  glEnable (GL_FOG);
		  // define how "foggy" it is; the higher the
		  // density, the thicker the fog
		  glFogf (GL_FOG_DENSITY, 0.1);
		  fog++;
	       }
	       break;
      case 5 : if (texture) {
		  texture = 0;
	       } else {
		  texture = 1;
	       }
	       break;
      case 6 : exit (1);
   }

   glutPostRedisplay();
	
} // mymenu ()
int main (int argc, char** argv) {
   glutInit(&argc, argv);

   // A  set up for hidden surface checking; add DEPTH test
   // (change SINGLE to DOUBLE and add "glutSwapBuffers" to display() 
   // to do double-buffering, replacing call to "glFlush")
   // image = glmReadPPM("data/fishermen.ppm", &iwidth, &iheight);
   // //  if (!image)
   //      exit(0);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   // glutCreateMenu(world_menu);
   glutInitWindowSize (1000, 1000); 

   glutInitWindowPosition (100, 100);
   // glutCreateMenu(screen_menu);

   glutCreateWindow ("MyRoom");

   init ();
   // glutCreateMenu(world_menu);
   //  glutAddMenuEntry("Textures", 0);
   //  glutAddMenuEntry("", 0);
   //  glutAddMenuEntry("Fishermen", 'f');

   initmenu ();

    // screen = glutCreateSubWindow(window, GAP+256+GAP, GAP, 256, 256);
   glutDisplayFunc(display); 

   glutReshapeFunc (reshape);

   glutKeyboardFunc (keyboard);

   glutMainLoop();

   return 0; 
}
