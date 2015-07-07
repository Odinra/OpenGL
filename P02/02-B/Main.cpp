#include <Windows.h>
#include <gl/glut.h>
#include <iostream>

using namespace std;

#define PI 3.1415926535898

GLdouble angle = 0;
GLint circle_points = 1000000;
GLfloat colorR = 0, colorG = 0, colorB = 0;

void setViewPort(int left, int right, int bottom, int top)
{
	glViewport(left, bottom, right - left, top - bottom);
}

void SetWindow(float left, float right, float bottom, float top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

void init(void)
{
	glClearColor(1., 01.,1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10);
	glLineWidth(1);

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
	glColor3f(1, 1, 0);
	glVertex2i(64, 465);
	glVertex2i(127, 465);
	glVertex2i(127, 395);
	glVertex2i(127, 465);
	glVertex2i(127, 395);
	glVertex2i(176, 395);
	glVertex2i(176, 343);
	glVertex2i(176, 395);
	glVertex2i(176, 343);
	glVertex2i(127, 343);
	glVertex2i(127, 192);
	glVertex2i(127, 343);
	glVertex2i(127, 192);
	glVertex2i(64, 192);
	glVertex2i(64, 343);
	glVertex2i(64, 192);
	glVertex2i(64, 343);
	glVertex2i(10, 343);
	glVertex2i(9, 395);
	glVertex2i(10, 343);
	glVertex2i(9, 395);
	glVertex2i(65, 395);
	glVertex2i(65, 395);
	glVertex2i(64, 465);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 1);
	glVertex2i(523, 591);
	glVertex2i(549, 545);
	glVertex2i(	589, 544);
	glVertex2i(	559, 529);
	glVertex2i(578, 483);
	glVertex2i(525, 510);
	glVertex2i(	469, 482);
	glVertex2i(	491, 529);
	glVertex2i(459, 543);
	glVertex2i(489, 542);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 0);
	for (int i = 0; i < circle_points; i++) {
	angle = 2*PI*i/circle_points;
	glVertex2f(cos(angle) * 50  + 100, sin(angle) * 50 + 100);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5, 0, 1);
	glVertex2i(265, 154);
	glVertex2i(286, 111);
	glVertex2i(243, 70);
	glVertex2i(184, 102);
	glVertex2i(202, 154);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0,1,0);
	glVertex2i(370, 546);
	glVertex2i(270, 446);
	glVertex2i(270, 546);

	glColor3f(1, .5, 0);
	glVertex2i(281, 529);
	glVertex2i(314, 520);
	glVertex2i(300, 497);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1, 0, 1);
	glVertex2i(435, 160);
	glVertex2i(438, 150);
	glVertex2i(438, 102);
	glVertex2i(486, 147);
	glVertex2i(502, 96);
	glVertex2i(438, 102);
	glVertex2i(486, 59);
	glVertex2i(438, 50);
	glVertex2i(438, 102);
	glVertex2i(398, 65);
	glVertex2i(375, 105);
	glVertex2i(438, 102);
	glVertex2i(398, 150);
	glVertex2i(435, 160);
	glVertex2i(438, 102);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0,1,1);
	glVertex2i(337, 277);
	glVertex2i(439, 229);
	glVertex2i(426, 313);
	glVertex2i(358, 357);
	glVertex2i(286, 343);
	glVertex2i(268, 249);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	glVertex2i(0,0);
	glColor3f(1,0,0);
	glVertex2i(10,10);
	glColor3f(0,1,0);
	glVertex2i(20,20);
	glColor3f(0,0,1);
	glVertex2i(30,30);
	glColor3f(1,1,0);
	glVertex2i(40,40);
	glColor3f(1,0,1);
	glVertex2i(50,50);
	glColor3f(0,1,1);
	glVertex2i(60,60);
	glColor3f(1,1,1);
	glVertex2i(70,70);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0,0,0);
	glVertex2i(43, 553);
	glVertex2i(155, 549);
	glVertex2i(131, 500);
	glVertex2i(84, 503);
	glEnd();

	glBegin(GL_QUAD_STRIP);
	glColor3f(.545098,.270588,.0745);
	glVertex2i(388, 376);
	glVertex2i(379, 450);
	glVertex2i(448, 423);
	glVertex2i(442, 492);
	glVertex2i(523, 352);
	glVertex2i(524, 442);
	glEnd();

	glFlush();
}

void main (int argc, char** argv)
{
	glutInit(&argc, argv);	

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,600);
	glutCreateWindow("OpenGL Shapes");	

	init();

	glutDisplayFunc(display);

	setViewPort(0, 600, 0, 600);
	SetWindow(0, 600, 0, 600);
	glutMainLoop();
}