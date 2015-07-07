#include <Windows.h>
#include <gl/glut.h>
#include <iostream>

using namespace std;

static int view = 7;
//viewport
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
//setwindow
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
//display with main pictures stuffs
void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT);	
	glColor3f(01.0, 0.0, 01.0);
	glPushMatrix();
	glutWireSphere(1.5,360,360);
	glColor3f(01.0,01.0,0.0);
	glTranslatef(9.0, 0.0, 0.0);
	glutWireSphere(1.5,360,360);
	glPopMatrix();
	glutSwapBuffers();
}//view changing options
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

	setViewPort(600, 600);
	//SetWindow(0, 600, 0, 600);
	glutMainLoop();
}