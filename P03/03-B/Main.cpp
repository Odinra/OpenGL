#include <Windows.h>
#include <gl/glut.h>
#include <iostream>

using namespace std;

static int view = 7;
static int ViewX = 600;
static int ViewY = 600;

void setViewPort(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1.0 * view, 1.0 * view, -1.0 * view, 1.0 * view, 1.5, 2000.0);
	gluPerspective(60,(GLfloat)w/(GLfloat)h, 1, 1000000.0);
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 7, 0.0, 0.0, 0.0, 0, 1.0, 0.0);
}
//window
void SetWindow(float left, float right, float bottom, float top)
{


	gluOrtho2D(left, right, bottom, top);
}
//init
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);

}
//display with the different pictures
void display(void)
{
	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	glClear(GL_COLOR_BUFFER_BIT);	
	glColor3f(01.0, 0.0, 01.0);
	glPushMatrix();
	glTranslatef(-1, 2, 0);
	glRotatef(45, 0, 0, -1);
	glutSolidTeapot(1);
	glPopMatrix();

	glColor3f(0, 0, 1);

	glPushMatrix();
	glTranslatef(.5, .15, 0);
	glScalef(.1, 2, 1);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(1,1,1);

	glPushMatrix();
	glTranslatef(.5,-1.45,.1);
	glScalef(1,1,1);
	glRotatef(10, 1, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(0,0,1);

	glPushMatrix();
	glRotatef(10, 1, 0, 0);
	glTranslatef(.5, -.92, .2);
	glScalef(.95, .1, 1);
	glutSolidCube(1);
	glPopMatrix();

	glColor3f(1, 0, 0);

	glPushMatrix();
	glTranslatef(.55, -2.1, 0);
	glScalef(1, .1, 0);
	glutWireSphere(1, 360, 360);
	glPopMatrix();

	glColor3f(1,1,1);	

	glPushMatrix();
	glTranslatef(1.33, -1.55, 0);
	glScalef(.1,.15, 0);
	glutSolidTorus(.5, 2, 360, 360);
	glPopMatrix();
	
	glColor3f(.75, .75, .75);

	glPushMatrix();
	glTranslatef(-1,-0,0);
	glRotatef(10, 0,0,0);
	glScalef(.25,.4,0);
	glutSolidSphere(1, 360, 360);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1,-1,0);
	glScalef(1,1,1);
	gluCylinder(qobj, 1, 1, 1, 16, 16);
	glPopMatrix();

	glutSwapBuffers();
}//keyboard functions to change views
void keyboard(unsigned char key, int x, int y)
{switch(key)
{
case 'i':
	view += .0025;
	glTranslatef(0.0, 0.0, view);
	glutPostRedisplay();
	break;
case 'o':
	view += .0025;
	glTranslatef(0.0, 0.0, -view);
	glutPostRedisplay();
	break;
case 'v':
	ViewX *= 2;
	ViewY *= 2;
	setViewPort(ViewX, ViewY);
		glutPostRedisplay();
	break;
case 'V':
	ViewX /= 2;
	ViewY /= 2;
	setViewPort(ViewX, ViewY);
		glutPostRedisplay();
	break;
default:
	break;
}
}//main
void main (int argc, char** argv)
{
	glutInit(&argc, argv);	

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,600);
	glutCreateWindow(" . ");
	glutKeyboardFunc(keyboard);

	init();

	glutDisplayFunc(display);

	setViewPort(ViewX, ViewY);
	//SetWindow(0, 600, 0, 600);
	glutMainLoop();
}