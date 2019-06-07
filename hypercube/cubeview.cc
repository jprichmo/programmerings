///////////////////////////////////////////////////////////////////////////////                
//  CUBE VIEW PROGRAM
//    
//  File:           cubeview.cc 
//  Author:         Dana Vrajitoru
//  Adapted from:   E. Angel
//                  Interactive Computer Graphics
//                  A Top-Down Approach with OpenGL, Third Edition
//                  Addison-Wesley Longman, 2003
//                  Rotating cube with viewer movement from Chapter 5
//  Editor:         Jason Richmond
//  Project:        Rotating Hypercube
//  Last updated:   February 27, 2017.
// 
//  Creates a translucent rotating hypercube
//
///////////////////////////////////////////////////////////////////////////////                

#include <cstdlib>
#include "glheader.h"

///////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
///////////////////////////////////////////////////////////////////////////////

static bool lineMode = false;
//outer vertices
float po = 1.0;     //positive outside
float no = -po;     //negative outside
//inner vertices
float pi = 0.6;     //positive inside
float ni = -pi;     //negative inside
//2D arrays to hold vertex and normal values
GLfloat vertices[][3] = {{no,no,no},{no,no,po},{no,po,no},{no,po,po},
                         {po,no,no},{po,no,po},{po,po,no},{po,po,po},
                         {ni,ni,ni},{ni,ni,pi},{ni,pi,ni},{ni,pi,pi},
                         {pi,ni,ni},{pi,ni,pi},{pi,pi,ni},{pi,pi,pi}};
GLfloat normals[][3]  = {{no,no,no},{no,no,po},{no,po,no},{no,po,po},
                         {po,no,no},{po,no,po},{po,po,no},{po,po,po},
                         {ni,ni,ni},{ni,ni,pi},{ni,pi,ni},{ni,pi,pi},
                         {pi,ni,ni},{pi,ni,pi},{pi,pi,ni},{pi,pi,pi}};
//alpha for colors
float outerAlpha = 0.7;
float innerAlpha = 0.8;
//colors 000 to 111 for outer cube                        
GLfloat blkO[4] = {0.0,0.0,0.0,outerAlpha};
GLfloat bluO[4] = {0.0,0.0,1.0,outerAlpha};
GLfloat grnO[4] = {0.0,1.0,0.0,outerAlpha};
GLfloat cynO[4] = {0.0,1.0,1.0,outerAlpha};
GLfloat redO[4] = {1.0,0.0,0.0,outerAlpha};
GLfloat magO[4] = {1.0,0.0,1.0,outerAlpha};
GLfloat yelO[4] = {1.0,1.0,0.0,outerAlpha};
GLfloat whtO[4] = {1.0,1.0,1.0,outerAlpha};
//colors 000 to 111 for inner cube                        
GLfloat blkI[4] = {0.0,0.0,0.0,innerAlpha};
GLfloat bluI[4] = {0.0,0.0,1.0,innerAlpha};
GLfloat grnI[4] = {0.0,1.0,0.0,innerAlpha};
GLfloat cynI[4] = {0.0,1.0,1.0,innerAlpha};
GLfloat redI[4] = {1.0,0.0,0.0,innerAlpha};
GLfloat magI[4] = {1.0,0.0,1.0,innerAlpha};
GLfloat yelI[4] = {1.0,1.0,0.0,innerAlpha};
GLfloat whtI[4] = {1.0,1.0,1.0,innerAlpha};
//color array
GLfloat *colors[16] = {blkO, bluO, grnO, cynO,
                       redO, magO, yelO, whtO,
                       blkI, bluI, grnI, cynI,
                       redI, magI, yelI, whtI};
//location and rotation values
static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 1;                          //rotates about Y axis
static const GLdouble viewer[]= {0.0,0.0,2.4};  //set to look inside hypercube
//translation variables
static GLfloat trX = 0.0;
static GLfloat trY = 0.0;
static GLfloat trZ = 0.0;

///////////////////////////////////////////////////////////////////////////////
// FUNCTION PROTOTYPES
///////////////////////////////////////////////////////////////////////////////

void drawPoly(int a, int b, int c, int d);
void drawCube(int e, int f, int g, int h, int i, int j, int k, int l);
void drawHypercube();
void display();
void spinCube(int value);
void mouse(int btn, int state, int x, int y);
void key(unsigned char key, int x, int y);
void myReshape(int w, int h);

///////////////////////////////////////////////////////////////////////////////
// MAIN —> int                
// Initializes window and GUI and starts main loop
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("drawCube");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutTimerFunc(50, spinCube, 1);
    glutMouseFunc(mouse);
    glutKeyboardFunc(key);
    glLineWidth(4);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
 //   glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_CULL_FACE);
    glutMainLoop();
}

///////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// DRAW POLYGON —> void                
// Draws a quadrilateral using four points with corresponding colors 
void drawPoly(int a, int b, int c, int d) {
    glBegin(GL_POLYGON);
    glColor4fv(colors[a]);
    glNormal3fv(normals[a]);
    glVertex3fv(vertices[a]);
    glColor4fv(colors[b]);
    glNormal3fv(normals[b]);
    glVertex3fv(vertices[b]);
    glColor4fv(colors[c]);
    glNormal3fv(normals[c]);
    glVertex3fv(vertices[c]);
    glColor4fv(colors[d]);
    glNormal3fv(normals[d]);
    glVertex3fv(vertices[d]);
    glEnd();
}

///////////////////////////////////////////////////////////////////////////////
// DRAW CUBE —> void                
// Draws the cube
void drawCube(int e, int f, int g, int h, int i, int j, int k, int l) {
    drawPoly(e,i,j,f);
    drawPoly(l,k,g,h);
    drawPoly(i,k,l,j);
    drawPoly(h,g,e,f);
    drawPoly(j,l,h,f);
    drawPoly(g,k,i,e);
}

///////////////////////////////////////////////////////////////////////////////
// DRAW HYPERCUBE —> void                
// Draws the hypercube 
void drawHypercube() {
    //draw outer cube
    drawCube(0,1,2,3,4,5,6,7);
    //draw inner cube
    drawCube(8,9,10,11,12,13,14,15);
    //draw connections
    drawPoly(0,4,12,8);
    drawPoly(2,6,14,10);
    drawPoly(1,5,13,9);
    drawPoly(3,7,15,11);
    drawPoly(4,6,14,12);
    drawPoly(0,2,10,8);
    drawPoly(1,3,11,9);
    drawPoly(5,7,15,13);
}

///////////////////////////////////////////////////////////////////////////////
// DISPLAY —> void                
// Callback function for redrawing the window 
void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2,0.2,0.2,1.0);

    //update viewer position in modelview matrix
    glLoadIdentity();
    gluLookAt(viewer[0],viewer[1],viewer[2], 0.0,0.0,0.0, 0.0,1.0,0.0);
    glTranslatef(trX, trY, trZ); 

    //rotate cube
    glRotatef(theta[0], 1.0,0.0,0.0);
    glRotatef(theta[1], 0.0,1.0,0.0);
    glRotatef(theta[2], 0.0,0.0,1.0);

    //draw cube
    drawHypercube();

    glFlush();
    glutSwapBuffers();
}

///////////////////////////////////////////////////////////////////////////////
// SPIN CUBE —> void                
// Spins the cube two degrees in given direction
void spinCube(int value) {

    theta[axis] += 2.0;
    if( theta[axis] > 360.0 ) 
        theta[axis] -= 360.0;
    
    glutPostRedisplay();
    glutTimerFunc(50, spinCube, 1);
}

///////////////////////////////////////////////////////////////////////////////
// MOUSE —> void                
// Callback function for mouse
void mouse(int btn, int state, int x, int y) {
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
        axis = 0;
    if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) 
        axis = 1;
    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) 
        axis = 2;
    theta[axis] += 2.0;
    if ( theta[axis] > 360.0 ) 
        theta[axis] -= 360.0;
    display();
}

///////////////////////////////////////////////////////////////////////////////
// KEY —> void                
// Callback function for Ascii key
void key(unsigned char key, int x, int y) {
    //lineMode toggle
    if (key == ' ') {
        if (lineMode)
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        lineMode = !lineMode;
    }  
    //translation keys 
    if (key == 'x') 
        trX -= 0.1;
    if (key == 'X') 
        trX += 0.1;
    if (key == 'y') 
        trY -= 0.1;
    if (key == 'Y') 
        trY += 0.1;
    if (key == 'z') 
        trZ -= 0.1;
    if (key == 'Z') 
        trZ += 0.1;
    display();
}

///////////////////////////////////////////////////////////////////////////////
// MY INIT —> void                
// Reshapes the window
void myReshape(int w, int h) {
    glViewport(0, 0, w, h);
    //Use a perspective view
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();
    if(w<=h) 
        glFrustum(-2.0, 2.0, -2.0 * (GLfloat) h/ (GLfloat) w, 
                  2.0* (GLfloat) h / (GLfloat) w, 2.0, 20.0);
    else 
        glFrustum(-2.0, 2.0, -2.0 * (GLfloat) w/ (GLfloat) h, 
                  2.0* (GLfloat) w / (GLfloat) h, 2.0, 20.0);    
    glMatrixMode(GL_MODELVIEW);
}
