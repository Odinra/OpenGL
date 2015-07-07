/*Christopher King
Section 1031
Tower O' Rings*/
#include <Windows.h>
#include <gl/glut.h>
#include <iostream>

using namespace std;

int iZoom = 0;
int ViewX = 600;
int ViewY = 600;
int iX = 0, iY = 0, iZ = 15;

void setViewPort(int w, int h)
{
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w/(GLfloat)h, 1, 100000000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(iX,iY,iZ,0,0,0,0,.001,1000);
}
void init(void)
{
	glClearColor(0,0,0,0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//tower
	glColor3f(.75, 0, .25);
	glPushMatrix();
	glRotatef(0, 0, 0, 0);
	glScalef(1, 10, 1);
	glTranslatef(0,0,0);
	glutSolidCube(1);
	glColor3f(.75, .25, 0);
	//Base
	glPushMatrix();
	glRotatef(1,0,0,0);
	glScalef(10,.1,1);
	glTranslatef(0,-5,0);
	glutSolidCube(1);
	glPopMatrix();
	//Top
	glPushMatrix();
	glRotatef(1,0,0,0);
	glScalef(1,.1,1);
	glTranslatef(0,6,0);
	glutSolidSphere(1,360,360);
	glPopMatrix();
	/**************************************************************************
									RINGS
	**************************************************************************/
	glColor3f(1,1,0);
	glPushMatrix();
	glScalef(1,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,0,9);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(1,0,1);
	glPushMatrix();
	glScalef(.9,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,-0,7);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(1,0,0);
	glPushMatrix();
	glScalef(.8,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,0,5);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(0,0,1);
	glPushMatrix();
	glScalef(.7,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,-0,3);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(0,1,0);
	glPushMatrix();
	glScalef(.6,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,0,1);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(0,1,1);
	glPushMatrix();
	glScalef(.5,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,-0,-1);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(1,0.6470588235294118,0);
	glPushMatrix();
	glScalef(.4,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,0,-3);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(1,0.8431372549019608,0);
	glPushMatrix();
	glScalef(.3,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,-0,-5);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(0.0980392156862745,0.0980392156862745,0.4392156862745098);
	glPushMatrix();
	glScalef(.25,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,0,-7);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(0.6901960784313725,0.1882352941176471,0.3764705882352941);
	glPushMatrix();
	glScalef(.25,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,-0,-9);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();


	glPopMatrix();



	glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'w'://zoom on y
		iZoom = 1;
		glTranslatef(0,iZoom, 0);
		glutPostRedisplay();
		break;
	case 'q'://zoom on y
		iZoom = 1;
		glTranslatef(0,-iZoom, 0);
		glutPostRedisplay();
		break;
	case 's'://zoom on x
		iZoom = 1;
		glTranslatef(iZoom, 0, 0);
		glutPostRedisplay();
		break;
	case 'a'://zoom on x
		iZoom = 1;
		glTranslatef(-iZoom,0, 0);
		glutPostRedisplay();
		break;
	case 'x'://zoom on z
		iZoom = 1;
		glTranslatef(0, 0,-iZoom);
		glutPostRedisplay();
		break;
	case 'z'://zoom on z
		iZoom = 1;
		glTranslatef(0, 0, iZoom);
		glutPostRedisplay();
		break;
	case 'e':
		iX += 1;
		setViewPort(ViewX, ViewY);
		glutPostRedisplay();
	case 'E':
		iX -= 1;
		setViewPort(ViewX, ViewY);
		glutPostRedisplay();
	case 'd':
		iY += 1;
		setViewPort(ViewX, ViewY);
		glutPostRedisplay();
	case 'D':
		iY -= 1;
		setViewPort(ViewX, ViewY);
		glutPostRedisplay();
	case 'c':
		iZ += 1;
		setViewPort(ViewX, ViewY);
		glutPostRedisplay();
	case 'C':
		iZ -= 1;
		setViewPort(ViewX, ViewY);
		glutPostRedisplay();
	default:
		break;
	}
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600, 600);
	glutCreateWindow(" ");
	glutKeyboardFunc(keyboard);

	init();

	glutDisplayFunc(display);

	setViewPort(ViewX, ViewY);
	glutMainLoop();
}